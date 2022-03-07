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

#include "syncElection.h"
#include "syncMessage.h"

// TLA+ Spec
// RequestVote(i, j) ==
//    /\ state[i] = Candidate
//    /\ j \notin votesResponded[i]
//    /\ Send([mtype         |-> RequestVoteRequest,
//             mterm         |-> currentTerm[i],
//             mlastLogTerm  |-> LastTerm(log[i]),
//             mlastLogIndex |-> Len(log[i]),
//             msource       |-> i,
//             mdest         |-> j])
//    /\ UNCHANGED <<serverVars, candidateVars, leaderVars, logVars>>
//
int32_t syncNodeRequestVotePeers(SSyncNode* pSyncNode) {}

int32_t syncNodeElect(SSyncNode* pSyncNode) {
  // start election
  syncNodeRequestVotePeers(pSyncNode);
}

int32_t syncNodeRequestVote(SSyncNode* pSyncNode, const SRaftId* destRaftId, const SyncRequestVote* pMsg) {
  sTrace("syncNodeRequestVote pSyncNode:%p ", pSyncNode);
  int32_t ret = 0;

  SRpcMsg rpcMsg;
  syncRequestVote2RpcMsg(pMsg, &rpcMsg);
  syncNodeSendMsgById(destRaftId, pSyncNode, &rpcMsg);
  return ret;
}