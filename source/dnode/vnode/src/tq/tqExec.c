/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "tq.h"

static int32_t tqAddBlockDataToRsp(const SSDataBlock* pBlock, SMqDataRsp* pRsp, int32_t numOfCols) {
  int32_t dataStrLen = sizeof(SRetrieveTableRsp) + blockGetEncodeSize(pBlock);
  void*   buf = taosMemoryCalloc(1, dataStrLen);
  if (buf == NULL) return -1;

  SRetrieveTableRsp* pRetrieve = (SRetrieveTableRsp*)buf;
  pRetrieve->useconds = 0;
  pRetrieve->precision = TSDB_DEFAULT_PRECISION;
  pRetrieve->compressed = 0;
  pRetrieve->completed = 1;
  pRetrieve->numOfRows = htonl(pBlock->info.rows);

  // TODO enable compress
  int32_t actualLen = 0;
  blockEncode(pBlock, pRetrieve->data, &actualLen, numOfCols, false);
  actualLen += sizeof(SRetrieveTableRsp);
  ASSERT(actualLen <= dataStrLen);
  taosArrayPush(pRsp->blockDataLen, &actualLen);
  taosArrayPush(pRsp->blockData, &buf);
  return 0;
}

static int32_t tqAddBlockSchemaToRsp(const STqExecHandle* pExec, SMqDataRsp* pRsp) {
  SSchemaWrapper* pSW = tCloneSSchemaWrapper(pExec->pExecReader->pSchemaWrapper);
  if (pSW == NULL) {
    return -1;
  }
  taosArrayPush(pRsp->blockSchema, &pSW);
  return 0;
}

static int32_t tqAddTbNameToRsp(const STQ* pTq, int64_t uid, SMqDataRsp* pRsp) {
  SMetaReader mr = {0};
  metaReaderInit(&mr, pTq->pVnode->pMeta, 0);
  // TODO add reference to gurantee success
  if (metaGetTableEntryByUid(&mr, uid) < 0) {
    metaReaderClear(&mr);
    return -1;
  }
  char* tbName = strdup(mr.me.name);
  taosArrayPush(pRsp->blockTbName, &tbName);
  metaReaderClear(&mr);
  return 0;
}

int64_t tqScanData(STQ* pTq, const STqHandle* pHandle, SMqDataRsp* pRsp, STqOffsetVal* pOffset) {
  const STqExecHandle* pExec = &pHandle->execHandle;
  ASSERT(pExec->subType == TOPIC_SUB_TYPE__COLUMN);

  qTaskInfo_t task = pExec->task;

  if (qStreamPrepareScan(task, pOffset, pHandle->execHandle.subType) < 0) {
    tqDebug("prepare scan failed, return");
    if (pOffset->type == TMQ_OFFSET__LOG) {
      pRsp->rspOffset = *pOffset;
      return 0;
    } else {
      tqOffsetResetToLog(pOffset, pHandle->snapshotVer);
      if (qStreamPrepareScan(task, pOffset, pHandle->execHandle.subType) < 0) {
        tqDebug("prepare scan failed, return");
        pRsp->rspOffset = *pOffset;
        return 0;
      }
    }
  }

  int32_t rowCnt = 0;
  while (1) {
    SSDataBlock* pDataBlock = NULL;
    uint64_t     ts = 0;
    tqDebug("tmqsnap task start to execute");
    if (qExecTask(task, &pDataBlock, &ts) < 0) {
      ASSERT(0);
    }
    tqDebug("tmqsnap task execute end, get %p", pDataBlock);

    if (pDataBlock) {
      tqAddBlockDataToRsp(pDataBlock, pRsp, pExec->numOfCols);
      pRsp->blockNum++;
    }
  }

  return 0;
}

int64_t tqScan(STQ* pTq, const STqHandle* pHandle, SMqDataRsp* pRsp, SMqMetaRsp* pMetaRsp, STqOffsetVal* pOffset) {
  const STqExecHandle* pExec = &pHandle->execHandle;
  qTaskInfo_t          task = pExec->task;

  if (qStreamPrepareScan(task, pOffset, pHandle->execHandle.subType) < 0) {
    tqDebug("prepare scan failed, return");
    if (pOffset->type == TMQ_OFFSET__LOG) {
      pRsp->rspOffset = *pOffset;
      return 0;
    } else {
      tqOffsetResetToLog(pOffset, pHandle->snapshotVer);
      if (qStreamPrepareScan(task, pOffset, pHandle->execHandle.subType) < 0) {
        tqDebug("prepare scan failed, return");
        pRsp->rspOffset = *pOffset;
        return 0;
      }
    }
  }

  int32_t rowCnt = 0;
  while (1) {
    SSDataBlock* pDataBlock = NULL;
    uint64_t     ts = 0;
    tqDebug("tmqsnap task start to execute");
    if (qExecTask(task, &pDataBlock, &ts) < 0) {
      ASSERT(0);
    }
    tqDebug("tmqsnap task execute end, get %p", pDataBlock);

    if (pDataBlock != NULL) {
      if (pRsp->withTbName) {
        int64_t uid = 0;
        if (pOffset->type == TMQ_OFFSET__LOG) {
          uid = pExec->pExecReader->msgIter.uid;
          if (tqAddTbNameToRsp(pTq, uid, pRsp) < 0) {
            continue;
          }
        }
      }
      if (pRsp->withSchema) {
        if (pOffset->type == TMQ_OFFSET__LOG) {
          tqAddBlockSchemaToRsp(pExec, pRsp);
        } else {
          SSchemaWrapper* pSW = tCloneSSchemaWrapper(qExtractSchemaFromTask(task));
          taosArrayPush(pRsp->blockSchema, &pSW);
        }
      }

      if (pHandle->execHandle.subType == TOPIC_SUB_TYPE__COLUMN) {
        tqAddBlockDataToRsp(pDataBlock, pRsp, pExec->numOfCols);
      } else {
        tqAddBlockDataToRsp(pDataBlock, pRsp, taosArrayGetSize(pDataBlock->pDataBlock));
      }
      pRsp->blockNum++;
      if (pOffset->type == TMQ_OFFSET__LOG) {
        continue;
      } else {
        rowCnt += pDataBlock->info.rows;
        if (rowCnt <= 4096) continue;
      }
    }

    if (pHandle->execHandle.subType != TOPIC_SUB_TYPE__COLUMN) {
      if (pDataBlock == NULL && pOffset->type == TMQ_OFFSET__SNAPSHOT_DATA) {
        if (qStreamExtractPrepareUid(task) != 0) {
          continue;
        }
        tqDebug("tmqsnap vgId: %d, tsdb consume over, switch to wal, ver %" PRId64, TD_VID(pTq->pVnode),
                pHandle->snapshotVer + 1);
        break;
      }

      if (pRsp->blockNum > 0) {
        tqDebug("tmqsnap task exec exited, get data");
        break;
      }

      SMqMetaRsp* tmp = qStreamExtractMetaMsg(task);
      if (tmp->rspOffset.type == TMQ_OFFSET__SNAPSHOT_DATA) {
        tqOffsetResetToData(pOffset, tmp->rspOffset.uid, tmp->rspOffset.ts);
        qStreamPrepareScan(task, pOffset, pHandle->execHandle.subType);
        tmp->rspOffset.type = TMQ_OFFSET__SNAPSHOT_META;
        tqDebug("tmqsnap task exec change to get data");
        continue;
      }

      *pMetaRsp = *tmp;
      tqDebug("tmqsnap task exec exited, get meta");
    }

    tqDebug("task exec exited");
    break;
  }

  if (qStreamExtractOffset(task, &pRsp->rspOffset) < 0) {
    ASSERT(0);
  }

  ASSERT(pRsp->rspOffset.type != 0);
  return 0;
}

int32_t tqLogScanExec(STQ* pTq, STqHandle* pHandle, SSubmitReq* pReq, SMqDataRsp* pRsp) {
  STqExecHandle* pExec = &pHandle->execHandle;
  ASSERT(pExec->subType != TOPIC_SUB_TYPE__COLUMN);

  if (pExec->subType == TOPIC_SUB_TYPE__TABLE) {
    pRsp->withSchema = 1;
    STqReader* pReader = pExec->pExecReader;
    tqReaderSetDataMsg(pReader, pReq, 0);
    while (tqNextDataBlock(pReader)) {
      SSDataBlock block = {0};
      if (tqRetrieveDataBlock(&block, pReader) < 0) {
        if (terrno == TSDB_CODE_TQ_TABLE_SCHEMA_NOT_FOUND) continue;
      }
      if (pRsp->withTbName) {
        int64_t uid = pExec->pExecReader->msgIter.uid;
        if (tqAddTbNameToRsp(pTq, uid, pRsp) < 0) {
          blockDataFreeRes(&block);
          continue;
        }
      }
      tqAddBlockDataToRsp(&block, pRsp, taosArrayGetSize(block.pDataBlock));
      blockDataFreeRes(&block);
      tqAddBlockSchemaToRsp(pExec, pRsp);
      pRsp->blockNum++;
    }
  } else if (pExec->subType == TOPIC_SUB_TYPE__DB) {
    pRsp->withSchema = 1;
    STqReader* pReader = pExec->pExecReader;
    tqReaderSetDataMsg(pReader, pReq, 0);
    while (tqNextDataBlockFilterOut(pReader, pExec->execDb.pFilterOutTbUid)) {
      SSDataBlock block = {0};
      if (tqRetrieveDataBlock(&block, pReader) < 0) {
        if (terrno == TSDB_CODE_TQ_TABLE_SCHEMA_NOT_FOUND) continue;
      }
      if (pRsp->withTbName) {
        int64_t uid = pExec->pExecReader->msgIter.uid;
        if (tqAddTbNameToRsp(pTq, uid, pRsp) < 0) {
          blockDataFreeRes(&block);
          continue;
        }
      }
      tqAddBlockDataToRsp(&block, pRsp, taosArrayGetSize(block.pDataBlock));
      blockDataFreeRes(&block);
      tqAddBlockSchemaToRsp(pExec, pRsp);
      pRsp->blockNum++;
    }
#if 0
    if (pHandle->fetchMeta && pRsp->blockNum) {
      SSubmitMsgIter iter = {0};
      tInitSubmitMsgIter(pReq, &iter);
      STaosxRsp* pXrsp = (STaosxRsp*)pRsp;
      while (1) {
        SSubmitBlk* pBlk = NULL;
        if (tGetSubmitMsgNext(&iter, &pBlk) < 0) return -1;
        if (pBlk->schemaLen > 0) {
          if (pXrsp->createTableNum == 0) {
            pXrsp->createTableLen = taosArrayInit(0, sizeof(int32_t));
            pXrsp->createTableReq = taosArrayInit(0, sizeof(void*));
          }
          void* createReq = taosMemoryCalloc(1, pBlk->schemaLen);
          memcpy(createReq, pBlk->data, pBlk->schemaLen);
          taosArrayPush(pXrsp->createTableLen, &pBlk->schemaLen);
          taosArrayPush(pXrsp->createTableReq, &createReq);
          pXrsp->createTableNum++;
        }
      }
    }
#endif
  }

  if (pRsp->blockNum == 0) {
    return -1;
  }

  return 0;
}
