
void ActivateUnicastRegistration(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
[32m  sVar1 = *(short *)(param_2 + 6);[0m
  if (sVar1 != 0x21) {
    if (sVar1 == 0xc) {
      iVar6 = *(int *)(param_2 + 0x30);
    }
    else {
      if (sVar1 != 0x10) goto LAB_0042c93c;
      iVar6 = *(int *)(param_2 + 0x38);
    }
    if (iVar6 != 0) {
      if (*(short *)(iVar6 + 6) == 0x21) {
        if (mDNS_LoggingEnabled != 0) {
          uVar2 = GetRRDisplayString_rdb(iVar6 + 4,*(int *)(iVar6 + 0x24) + 4,param_1 + 0x2f);
          uVar5 = *(undefined4 *)(iVar6 + 0xe4);
          uVar7 = *(undefined4 *)(param_2 + 0x20);
          uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 6));
          LogMsgWithLevel(3,
                          "ActivateUnicastRegistration: Found Service Record %s in state %d for %##s (%s)"
                          ,uVar2,uVar5,uVar7,uVar3);
        }
        *(undefined4 *)(param_2 + 0xe4) = *(undefined4 *)(iVar6 + 0xe4);
      }
      else {
        uVar2 = GetRRDisplayString_rdb(iVar6 + 4,*(int *)(iVar6 + 0x24) + 4,param_1 + 0x2f);
        LogMsgWithLevel(0,
                        "ActivateUnicastRegistration: ERROR!! Resource record %s wrong, expecting SRV type"
                        ,uVar2);
      }
    }
  }
LAB_0042c93c:
  if (*(int *)(param_2 + 0xe4) == 8) {
    if (mDNS_LoggingEnabled != 0) {
      uVar2 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
                    /* WARNING: Treating indirect jump as call */
      LogMsgWithLevel(3,"ActivateUnicastRegistration record %s in regState_NoTarget, not activating"
                      ,uVar2);
      return;
    }
  }
  else {
    if (*(char *)(param_2 + 4) == '\x01') {
      if (mDNS_LoggingEnabled != 0) {
        uVar2 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
        LogMsgWithLevel(3,
                        "ActivateUnicastRegistration: Resource record %s, current state %d, moving to DeregPending"
                        ,uVar2,*(undefined4 *)(param_2 + 0xe4));
      }
      uVar2 = 3;
    }
    else {
      uVar2 = 1;
      if (mDNS_LoggingEnabled != 0) {
        uVar2 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
        LogMsgWithLevel(3,
                        "ActivateUnicastRegistration: Resource record %s, current state %d, moving to Pending"
                        ,uVar2,*(undefined4 *)(param_2 + 0xe4));
        uVar2 = 1;
      }
    }
    *(undefined4 *)(param_2 + 0xe4) = uVar2;
    *(undefined *)(param_2 + 0x86) = 0;
    *(undefined *)(param_2 + 0x85) = 0;
    *(undefined *)(param_2 + 0x87) = 0;
    iVar6 = mDNSPlatformOneSecond;
    *(int *)(param_2 + 0xbc) = mDNSPlatformOneSecond;
    iVar4 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(param_2 + 0xec) = 0;
    *(int *)(param_2 + 0xc0) = iVar4 - iVar6;
    *(undefined *)(param_2 + 0xe8) = 1;
    *(undefined *)(param_2 + 0x150) = 0;
    *(undefined4 *)(param_2 + 0x15c) = 0;
    *(undefined2 *)(param_2 + 0xf2) = 0;
    if (*(int *)(param_2 + 0x14c) != 0) {
      mDNS_StopNATOperation_internal(param_1,param_2 + 0x108);
      *(undefined4 *)(param_2 + 0x14c) = 0;
    }
    if (*(int *)(param_2 + 0x100) != 0) {
      CancelGetZoneData(param_1);
      *(undefined4 *)(param_2 + 0x100) = 0;
    }
    if (*(int *)(param_2 + 0x104) != 0) {
      DisposeTCPConn();
      *(undefined4 *)(param_2 + 0x104) = 0;
    }
    iVar6 = *(int *)(param_2 + 0xbc) + *(int *)(param_2 + 0xc0);
    if (-1 < *(int *)(param_1 + 0x2188) - iVar6) {
      *(int *)(param_1 + 0x2188) = iVar6;
    }
  }
  return;
}

[ASK_GPT] 72d4a3e2231b08c6
