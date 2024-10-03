
/* WARNING: Removing unreachable block (ram,0x0042e220) */

void ReleaseCacheRecord(int param_1,undefined4 *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *__ptr;
  void *__ptr_00;
  undefined4 uVar5;
  
  uVar2 = DomainNameHashValue(param_2[8]);
  __ptr = (undefined4 *)param_2[9];
  if ((__ptr != (undefined4 *)0x0) && (__ptr != param_2 + 0x1c)) {
    mDNSPlatformMemFree(__ptr);
  }
  param_2[9] = 0;
  iVar3 = CacheGroupForName(param_1,uVar2 % 499,param_2[5],param_2[8]);
  if ((iVar3 == 0) && (mDNS_LoggingEnabled != 0)) {
    uVar5 = param_2[8];
    uVar4 = DNSTypeName(*(undefined2 *)((int)param_2 + 6));
    LogMsgWithLevel(3,"ReleaseCacheRecord: ERROR!! cg NULL for %##s (%s)",uVar5,uVar4);
  }
  __ptr_00 = (void *)param_2[8];
  if (((__ptr_00 != (void *)0x0) && (iVar3 != 0)) && (__ptr_00 != *(void **)(iVar3 + 0x10))) {
    mDNSPlatformMemFree(__ptr_00);
  }
  param_2[8] = 0;
  if (param_2[0xb] != 0) {
    FreeAnonInfo();
  }
  param_2[0xb] = 0;
  if (param_2[7] == 0) {
    *(uint *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) - (uint)*(ushort *)(param_2 + 4);
[32m    sVar1 = *(short *)((int)param_2 + 6);[0m
    if ((((ushort)(sVar1 - 0x2eU) < 3) || (sVar1 == 0x2b)) || (sVar1 == 0x32)) {
      BumpDNSSECStats(param_1,1,0,*(undefined2 *)(param_2 + 4));
    }
  }
  FUN_0042e080(param_1,param_2 + 0x15);
  FUN_0042e080(param_1,param_2 + 0x16);
  *param_2 = *(undefined4 *)(param_1 + 0x2dc);
  *(undefined4 **)(param_1 + 0x2dc) = param_2;
  *(int *)(param_1 + 0x2cc) = *(int *)(param_1 + 0x2cc) + -1;
  return;
}

[ASK_GPT] 9f23f93734ceb88a
