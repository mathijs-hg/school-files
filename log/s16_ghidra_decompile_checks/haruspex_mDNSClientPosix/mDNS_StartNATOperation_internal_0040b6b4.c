
undefined4 mDNS_StartNATOperation_internal(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (mDNS_LoggingEnabled != 0) {
    LogMsgWithLevel(3,
                    "mDNS_StartNATOperation_internal %p Protocol %d IntPort %d RequestedPort %d NATLease %d"
                    ,param_2,*(undefined *)(param_2 + 0xd),*(undefined2 *)((int)param_2 + 0x36),
                    *(undefined2 *)(param_2 + 0xe),param_2[0xf]);
  }
  puVar4 = (undefined4 *)(param_1 + 0x29b8);
  while( true ) {
    puVar2 = (undefined4 *)*puVar4;
    if (puVar2 == (undefined4 *)0x0) {
      *param_2 = 0;
      param_2[1] = 0;
      iVar3 = mDNSPlatformOneSecond;
      if (mDNSPlatformOneSecond < 0) {
        iVar3 = mDNSPlatformOneSecond + 3;
      }
      param_2[2] = iVar3 >> 2;
      param_2[3] = *(undefined4 *)(param_1 + 0x234);
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[8] = 0xffffffff;
      *(undefined *)(param_2 + 6) = 0;
      param_2[0xb] = 0;
      param_2[9] = 0;
      param_2[0xc] = 0;
      *(undefined2 *)(param_2 + 10) = 0;
      if (param_2[0xf] == 0) {
        param_2[0xf] = 0x1c20;
      }
      if (*(int *)(param_1 + 0x29b8) == 0) {
        *(undefined4 *)(param_1 + 0x29c4) = *(undefined4 *)(param_1 + 0x234);
        iVar3 = mDNSPlatformOneSecond;
        if (mDNSPlatformOneSecond < 0) {
          iVar3 = mDNSPlatformOneSecond + 3;
        }
        *(int *)(param_1 + 0x29c0) = iVar3 >> 2;
      }
      if (*(char *)(param_2 + 0xd) == '\0') {
        param_2[9] = *(undefined4 *)(param_1 + 0x29c8);
      }
      *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x234);
      *puVar4 = param_2;
      return 0;
    }
[32m    cVar1 = *(char *)(param_2 + 0xd);[0m
    if (param_2 == puVar2) break;
    if (((cVar1 != '\0') && ((param_2[0xd] & 0xff00ffff) == (puVar2[0xd] & 0xff00ffff))) &&
       (*(short *)((int)param_2 + 0x36) != 0x16)) {
      LogMsgWithLevel(0,
                      "Warning: Created port mapping request %p Prot %d Int %d TTL %d duplicates existing port mapping request %p Prot %d Int %d TTL %d"
                      ,param_2,cVar1,*(short *)((int)param_2 + 0x36),param_2[0xf],puVar2,
                      *(undefined *)(puVar2 + 0xd),*(undefined2 *)((int)puVar2 + 0x36),puVar2[0xf]);
    }
    puVar4 = (undefined4 *)*puVar4;
  }
  LogMsgWithLevel(0,
                  "Error! Tried to add a NAT traversal that\'s already in the active list: request %p Prot %d Int %d TTL %d"
                  ,param_2,cVar1,*(undefined2 *)((int)param_2 + 0x36),param_2[0xf]);
  return 0xfffefff5;
}

[ASK_GPT] ac0fa22f7bfaadd7
