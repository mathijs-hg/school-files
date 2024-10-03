
void FUN_004292f4(int param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  undefined4 uVar3;
  
[32m  if (((*(char *)(param_2 + 4) == -0x10) || (sVar1 = *(short *)(param_2 + 6), sVar1 == 1)) ||[0m
     (sVar1 == 0x1c)) {
    bVar2 = true;
  }
  else {
    bVar2 = sVar1 == 0x21;
  }
  if (bVar2) {
    if (mDNS_LoggingEnabled != 0) {
      uVar3 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
      LogMsgWithLevel(3,"PurgeorReconfirmCacheRecord: Purging Resourcerecord %s, RecordType %x",
                      uVar3,*(undefined *)(param_2 + 4));
    }
    mDNS_PurgeCacheResourceRecord(param_1,param_2);
    return;
  }
  if (mDNS_LoggingEnabled != 0) {
    uVar3 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(3,"PurgeorReconfirmCacheRecord: Reconfirming Resourcerecord %s, RecordType %x",
                    uVar3,*(undefined *)(param_2 + 4));
  }
  FUN_00429190(param_1,param_2,mDNSPlatformOneSecond * 5);
  return;
}

[ASK_GPT] 550e546f59c67e0a
