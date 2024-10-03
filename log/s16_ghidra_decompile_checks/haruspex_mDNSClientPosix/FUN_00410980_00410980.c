
void FUN_00410980(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x21b0) != 0) && (*(char *)(param_2 + 0x150) == '\0')) {
    iVar3 = param_2 + 0x14c;
    mDNS_SetupResourceRecord(iVar3,0,0,1,0x78,0,0,FUN_00410c7c,param_2);
    uVar1 = DomainNameLengthLimit((void *)(param_2 + 0x4c),iVar3);
    if (uVar1 < 0x101) {
      mDNSPlatformMemCopy((void *)(param_2 + 0x2c4),(void *)(param_2 + 0x4c),uVar1);
    }
    else {
      *(undefined *)(param_2 + 0x2c4) = 0;
    }
    *(undefined4 *)(*(int *)(param_2 + 0x170) + 4) = *(undefined4 *)(param_1 + 0x21b0);
    *(undefined4 *)(param_2 + 0x230) = 4;
    iVar2 = mDNSv4AddrIsRFC1918(param_1 + 0x21b0);
    if (iVar2 == 0) {
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(3,"Advertising hostname %##s IPv4 %.4a",*(undefined4 *)(param_2 + 0x16c),
                        param_1 + 0x21b0);
      }
      *(undefined *)(param_2 + 0x150) = 0x20;
      mDNS_Register_internal(param_1,iVar3);
    }
    else {
      if (*(int *)(param_2 + 0x48) != 0) {
        mDNS_StopNATOperation_internal(param_1,param_2 + 4);
      }
      *(code **)(param_2 + 0x44) = FUN_0040e818;
      *(undefined2 *)(param_2 + 0x3c) = 0;
      *(undefined *)(param_2 + 0x38) = 0;
      *(undefined2 *)(param_2 + 0x3a) = 0;
      *(undefined4 *)(param_2 + 0x40) = 0;
      *(int *)(param_2 + 0x48) = param_2;
      mDNS_StartNATOperation_internal(param_1,param_2 + 4);
    }
  }
  if (((((*(int *)(param_1 + 0x21c8) != 0) || (*(int *)(param_1 + 0x21c4) != 0)) ||
       (*(int *)(param_1 + 0x21cc) != 0)) || (*(int *)(param_1 + 0x21d0) != 0)) &&
     (*(char *)(param_2 + 0x4d4) == '\0')) {
    mDNS_SetupResourceRecord(param_2 + 0x4d0,0,0,0x1c,0x78,0x20,0,FUN_00410c7c,param_2);
    uVar1 = DomainNameLengthLimit((void *)(param_2 + 0x4c),param_2 + 0x14c);
    if (uVar1 < 0x101) {
      mDNSPlatformMemCopy((void *)(param_2 + 0x648),(void *)(param_2 + 0x4c),uVar1);
    }
    else {
      *(undefined *)(param_2 + 0x648) = 0;
    }
[32m[32m    memcpy((void *)(*(int *)(param_2 + 0x4f4) + 4),(void *)(param_1 + 0x21c4),0x10);[0m[0m
    *(undefined4 *)(param_2 + 0x5b4) = 4;
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"Advertising hostname %##s IPv6 %.16a",*(undefined4 *)(param_2 + 0x4f0),
                      (void *)(param_1 + 0x21c4));
    }
                    /* WARNING: Treating indirect jump as call */
    mDNS_Register_internal(param_1,param_2 + 0x4d0);
    return;
  }
  return;
}

[ASK_GPT] d5c6367219232cb2
