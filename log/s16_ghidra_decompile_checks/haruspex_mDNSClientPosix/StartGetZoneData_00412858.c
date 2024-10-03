
undefined *
StartGetZoneData(int param_1,void *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *__dest;
  uint uVar4;
  bool bVar5;
  undefined4 uVar6;
  
  iVar1 = GetAuthInfoForName_internal();
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
    iVar2 = 0;
  }
  else {
    iVar2 = DomainNameLengthLimit(param_2,(int)param_2 + 0x100);
    iVar3 = DomainNameLengthLimit(iVar1 + 0x11b4,iVar1 + 0x12b4);
    iVar2 = iVar2 - iVar3;
  }
  __dest = (undefined *)mDNSPlatformMemAllocate(0x5bc);
  if (__dest == (undefined *)0x0) {
    LogMsgWithLevel(0,"ERROR: StartGetZoneData - mDNSPlatformMemAllocate failed");
    return (undefined *)0x0;
  }
  mDNSPlatformMemZero(__dest,0x5bc);
  uVar4 = DomainNameLengthLimit(param_2,(int)param_2 + 0x100);
  if (uVar4 < 0x101) {
    mDNSPlatformMemCopy(__dest,param_2,uVar4);
  }
  else {
    *__dest = 0;
  }
  *(undefined4 *)(__dest + 0x100) = param_3;
  *(undefined **)(__dest + 0x104) = __dest + iVar2;
  *(undefined2 *)(__dest + 0x30a) = 0;
  __dest[0x108] = 0;
  *(undefined2 *)(__dest + 0x208) = 0;
  __dest[0x20a] = 0;
[32m[32m  memcpy(__dest + 0x30c,zeroAddr,0x14);[0m[0m
  bVar5 = false;
  if (iVar1 != 0) {
    bVar5 = *(char *)(iVar1 + 8) != '\0';
  }
  __dest[800] = bVar5;
  *(undefined4 *)(__dest + 0x324) = param_4;
  *(undefined **)(__dest + 0x5b8) = __dest;
  *(undefined4 *)(__dest + 0x328) = param_5;
  iVar2 = *(int *)(param_1 + 0x28) + 1;
  *(int *)(param_1 + 0x28) = iVar2;
  if (*(int *)(param_1 + 0x24) != iVar2) {
    LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                    "StartGetZoneData",*(int *)(param_1 + 0x24),iVar2);
  }
  if ((iVar1 != 0) && (*(char *)(iVar1 + 8) != '\0')) {
    if (*(short *)(iVar1 + 0x14b4) != 0) {
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(3,"StartGetZoneData: Bypassing SOA, SRV query for %##s",iVar1 + 0x11b4);
      }
      uVar4 = DomainNameLengthLimit((void *)(iVar1 + 0x11b4),iVar1 + 0x12b4);
      if (uVar4 < 0x101) {
        mDNSPlatformMemCopy(__dest + 0x108,(void *)(iVar1 + 0x11b4),uVar4);
      }
      else {
        __dest[0x108] = 0;
      }
      *(undefined2 *)(__dest + 0x208) = 1;
      uVar4 = DomainNameLengthLimit((void *)(iVar1 + 0x13b4),iVar1 + 0x14b4);
      if (uVar4 < 0x101) {
        mDNSPlatformMemCopy(__dest + 0x20a,(void *)(iVar1 + 0x13b4),uVar4);
      }
      else {
        __dest[0x20a] = 0;
      }
      *(undefined2 *)(__dest + 0x30a) = *(undefined2 *)(iVar1 + 0x14b4);
      uVar4 = DomainNameLengthLimit(__dest + 0x20a,__dest + 0x30a);
      if (uVar4 < 0x101) {
        mDNSPlatformMemCopy(__dest + 0x480,__dest + 0x20a,uVar4);
      }
      else {
        __dest[0x480] = 0;
      }
      uVar6 = 1;
      goto LAB_00412b9c;
    }
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"StartGetZoneData: Not Bypassing SOA, SRV query for %##s",iVar1 + 0x11b4);
    }
  }
  uVar4 = DomainNameLengthLimit(*(int *)(__dest + 0x104),*(int *)(__dest + 0x104) + 0x100);
  if (uVar4 < 0x101) {
    mDNSPlatformMemCopy(__dest + 0x480,*(void **)(__dest + 0x104),uVar4);
  }
  else {
    __dest[0x480] = 0;
  }
  uVar6 = 6;
LAB_00412b9c:
  FUN_0041213c(param_1,__dest,uVar6);
  iVar1 = *(int *)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x24) != iVar1) {
    LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                    "StartGetZoneData",*(int *)(param_1 + 0x24),iVar1);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  *(int *)(param_1 + 0x28) = iVar1 + -1;
  return __dest;
}

[ASK_GPT] c919c01fabe57bab
