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

#define _GNU_SOURCE
#include "shellInt.h"

static void shellWorkAsClient() {
  SShellArgs *pArgs = &shell.args;
  SRpcInit    rpcInit = {0};
  SEpSet      epSet = {.inUse = 0, .numOfEps = 1};
  SRpcMsg     rpcRsp = {0};
  void       *clientRpc = NULL;
  char        pass[TSDB_PASSWORD_LEN + 1] = {0};

  taosEncryptPass_c((uint8_t *)("_pwd"), strlen("_pwd"), pass);
  rpcInit.label = "CHK";
  rpcInit.numOfThreads = 1;
  rpcInit.sessions = 16;
  rpcInit.connType = TAOS_CONN_CLIENT;
  rpcInit.idleTime = tsShellActivityTimer * 1000;
  rpcInit.user = "_dnd";
  rpcInit.ckey = "_key";
  rpcInit.spi = 1;
  rpcInit.secret = pass;

  clientRpc = rpcOpen(&rpcInit);
  if (clientRpc == NULL) {
    printf("failed to init net test client since %s\n", terrstr());
    goto _OVER;
  }

  if (pArgs->host == NULL) {
    pArgs->host = tsFirst;
  }
  char fqdn[TSDB_FQDN_LEN] = {0};
  tstrncpy(fqdn, pArgs->host, TSDB_FQDN_LEN);
  strtok(fqdn, ":");

  if (pArgs->port == 0) {
    pArgs->port = tsServerPort;
  }

  printf("network test client is initialized, the server is %s:%u\n", fqdn, pArgs->port);

  tstrncpy(epSet.eps[0].fqdn, fqdn, TSDB_FQDN_LEN);
  epSet.eps[0].port = (uint16_t)pArgs->port;

  int32_t  totalSucc = 0;
  uint64_t startTime = taosGetTimestampUs();

  for (int32_t i = 0; i < pArgs->pktNum; ++i) {
    SRpcMsg rpcMsg = {.ahandle = (void *)0x9525, .msgType = TDMT_DND_NET_TEST};
    rpcMsg.pCont = rpcMallocCont(pArgs->pktLen);
    rpcMsg.contLen = pArgs->pktLen;

    printf("request is sent, size:%d\n", rpcMsg.contLen);
    rpcSendRecv(clientRpc, &epSet, &rpcMsg, &rpcRsp);
    if (rpcRsp.code == 0 &&rpcRsp.contLen == rpcMsg.contLen) {
      printf("response is received, size:%d\n", rpcMsg.contLen);
      if (rpcRsp.code == 0) totalSucc++;
    } else {
      printf("response not received since %s\n", tstrerror(rpcRsp.code));
    }

    rpcFreeCont(rpcRsp.pCont);
    rpcRsp.pCont = NULL;
  }

  uint64_t endTime = taosGetTimestampUs();
  uint64_t elT = endTime - startTime;

  printf("\ntotal succ:%5d/%d\tcost:%8.2lf ms\tspeed:%8.2lf MB/s\n", totalSucc, pArgs->pktNum, elT / 1000.0,
         pArgs->pktLen / (elT / 1000000.0) / 1024.0 / 1024.0 * totalSucc);

_OVER:
  if (clientRpc != NULL) {
    rpcClose(clientRpc);
  }
  if (rpcRsp.pCont != NULL) {
    rpcFreeCont(rpcRsp.pCont);
  }
}

static void shellProcessMsg(void *p, SRpcMsg *pRpc, SEpSet *pEpSet) {
  printf("request is received, size:%d\n", pRpc->contLen);
  fflush(stdout);
  SRpcMsg rsp = {.handle = pRpc->handle, .refId = pRpc->refId, .ahandle = pRpc->ahandle, .code = 0};
  rsp.pCont = rpcMallocCont(shell.args.pktLen);
  rsp.contLen = shell.args.pktLen;
  rpcSendResponse(&rsp);
}

void shellNettestHandler(int32_t signum, void *sigInfo, void *context) { shellExit(); }

static void shellWorkAsServer() {
  SShellArgs *pArgs = &shell.args;

  if (pArgs->port == 0) {
    pArgs->port = tsServerPort;
  }

  SRpcInit rpcInit = {0};
  rpcInit.localPort = pArgs->port;
  rpcInit.label = "CHK";
  rpcInit.numOfThreads = tsNumOfRpcThreads;
  rpcInit.cfp = (RpcCfp)shellProcessMsg;
  rpcInit.sessions = 10;
  rpcInit.connType = TAOS_CONN_SERVER;
  rpcInit.idleTime = tsShellActivityTimer * 1000;

  void *serverRpc = rpcOpen(&rpcInit);
  if (serverRpc == NULL) {
    printf("failed to init net test server since %s", terrstr());
  } else {
    printf("network test server is initialized, port:%u\n", pArgs->port);
    taosSetSignal(SIGTERM, shellNettestHandler);
    while (1) taosMsleep(10);
  }
}

void shellTestNetWork() {
  if (strcmp(shell.args.netrole, "client") == 0) {
    shellWorkAsClient();
  }

  if (strcmp(shell.args.netrole, "server") == 0) {
    shellWorkAsServer();
  }
}