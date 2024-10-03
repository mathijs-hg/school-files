
/* WARNING: Removing unreachable block (ram,0x0043539c) */

void FUN_004350d4(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  undefined4 uVar2;
  uint __n;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_2 + 0x28c);
  iVar5 = param_2 - (iVar4 + 0x298) >> 4;
  iVar6 = iVar5 * -0x3e7063e7;
  if (mDNS_LoggingEnabled != 0) {
    uVar2 = GetRRDisplayString_rdb(param_3,*(int *)(param_3 + 0x20) + 4,param_1 + 0x2f);
    LogMsgWithLevel(2,"NetWakeResolve: SPS: %d Add: %d %s",iVar6,param_4,uVar2);
  }
[32m  if ((param_4 == 0) || (sVar1 = *(short *)(param_2 + 0x254), sVar1 != *(short *)(param_3 + 2))) {[0m
    return;
  }
  if (sVar1 == 0x21) {
    mDNS_StopQuery(param_1,param_2);
    *(undefined2 *)(iVar4 + (iVar6 + 0x540) * 2 + 4) = *(undefined2 *)(*(int *)(param_3 + 0x20) + 8)
    ;
    __n = DomainNameLengthLimit(*(int *)(param_3 + 0x20) + 10,*(int *)(param_3 + 0x20) + 0x10a);
    if (__n < 0x101) {
      mDNSPlatformMemCopy((void *)(param_2 + 0x154),(void *)(*(int *)(param_3 + 0x20) + 10),__n);
    }
    else {
      *(undefined *)(param_2 + 0x154) = 0;
    }
    uVar3 = 1;
LAB_004352c0:
    *(undefined2 *)(param_2 + 0x254) = uVar3;
    mDNS_StartQuery(param_1,param_2);
    return;
  }
  if (sVar1 == 1) {
    if (*(short *)(param_3 + 0xc) != 4) {
      if (*(short *)(param_3 + 0xc) != 0) {
        return;
      }
      mDNS_StopQuery(param_1,param_2);
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(2,"NetWakeResolve: SPS %d %##s has no IPv4 address, will try IPv6 instead",
                        iVar6,param_2 + 0x154);
      }
      uVar3 = 0x1c;
      goto LAB_004352c0;
    }
    mDNS_StopQuery(param_1,param_2);
    *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
    iVar5 = iVar4 + iVar5 * 0x1f3831f4;
    *(undefined4 *)(iVar5 + 0xa48) = 4;
    *(undefined4 *)(iVar5 + 0xa4c) = *(undefined4 *)(*(int *)(param_3 + 0x20) + 4);
  }
  else {
    if (sVar1 != 0x1c) {
      return;
    }
    if (*(short *)(param_3 + 0xc) != 0x10) {
      return;
    }
    if (*(char *)(*(int *)(param_3 + 0x20) + 4) != -2) {
      return;
    }
    if ((*(byte *)(*(int *)(param_3 + 0x20) + 5) & 0xc0) != 0x80) {
      return;
    }
    mDNS_StopQuery(param_1,param_2);
    *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
    iVar5 = iVar4 + iVar5 * 0x1f3831f4;
    *(undefined4 *)(iVar5 + 0xa48) = 6;
[32m[32m    memcpy((void *)(iVar5 + 0xa4c),(void *)(*(int *)(param_3 + 0x20) + 4),0x10);[0m[0m
  }
  mDNS_Lock_(param_1,"NetWakeResolve");
  if (iVar6 == *(int *)(iVar4 + 0xa8c) / 3) {
    FUN_00434f7c(param_1,iVar4,0);
  }
                    /* WARNING: Treating indirect jump as call */
  mDNS_Unlock_(param_1,"NetWakeResolve");
  return;
}

[ASK_GPT] 0b7a97bf82a7a0ce
