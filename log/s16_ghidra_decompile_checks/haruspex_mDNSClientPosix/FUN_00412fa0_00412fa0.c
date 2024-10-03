
void FUN_00412fa0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  uint __n;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined *__dest;
  undefined4 uStackX_8;
  undefined4 uStackX_c;
  
  iVar5 = *(int *)(param_2 + 0x44);
  if (iVar5 == 0) {
    uVar3 = 0;
    pcVar4 = "CompleteRecordNatMap called with unknown AuthRecord object";
  }
  else {
    if (*(int *)(param_2 + 0x3c) == 0) {
      param_3 = GetRRDisplayString_rdb(iVar5 + 4,*(int *)(iVar5 + 0x24) + 4);
      pcVar4 = "CompleteRecordNatMap No NATLease for %s";
    }
    else {
      if (*(short *)(iVar5 + 6) == 0x21) {
        if (*(char *)(iVar5 + 4) == '\x01') {
          if (mDNS_LoggingEnabled == 0) {
            return;
          }
          param_3 = GetRRDisplayString_rdb(iVar5 + 4,*(int *)(iVar5 + 0x24) + 4,param_1 + 0x2f);
          pcVar4 = "CompleteRecordNatMap called for %s, Service deregistering";
        }
        else {
          if (*(int *)(iVar5 + 0xe4) != 3) {
            if ((*(int *)(iVar5 + 0x100) == 0) || (*(int *)(*(int *)(iVar5 + 0x100) + 0x310) == 0))
            {
              if (mDNS_LoggingEnabled != 0) {
                uVar3 = GetRRDisplayString_rdb(iVar5 + 4,*(int *)(iVar5 + 0x24) + 4,param_1 + 0x2f);
                LogMsgWithLevel(3,"CompleteRecordNatMap called for %s but no zone information!",
                                uVar3);
              }
              if (*(int *)(iVar5 + 0x14c) != 0) {
                mDNS_StopNATOperation_internal(param_1,iVar5 + 0x108);
                *(undefined4 *)(iVar5 + 0x14c) = 0;
              }
              *(undefined4 *)(iVar5 + 0xe4) = 1;
              *(int *)(iVar5 + 0xbc) = mDNSPlatformOneSecond;
              *(int *)(iVar5 + 0xc0) = *(int *)(param_1 + 0x234) - mDNSPlatformOneSecond;
              return;
            }
            mDNS_Lock_(param_1,"CompleteRecordNatMap",param_1 + 0x2f);
            pcVar4 = (char *)GetServiceTarget(param_1,iVar5);
[32m            sVar1 = *(short *)(iVar5 + 6);[0m
            if ((((sVar1 == 2) || (sVar1 == 5)) || (sVar1 == 0xc)) || (sVar1 == 0x27)) {
              __dest = (undefined *)(*(int *)(iVar5 + 0x24) + 4);
            }
            else if (((sVar1 == 0xf) || (sVar1 == 0x12)) || ((sVar1 == 0x15 || (sVar1 == 0x24)))) {
              __dest = (undefined *)(*(int *)(iVar5 + 0x24) + 6);
            }
            else {
              __dest = (undefined *)0x0;
              if (sVar1 == 0x21) {
                __dest = (undefined *)(*(int *)(iVar5 + 0x24) + 10);
              }
            }
            if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
              if (mDNS_LoggingEnabled != 0) {
                LogMsgWithLevel(3,"CompleteRecordNatMap - no target for %##s, ExternalPort %d",
                                *(undefined4 *)(iVar5 + 0x20),*(undefined2 *)(param_2 + 0x28));
              }
            }
            else {
              if (*(short *)(param_2 + 0x28) != 0) {
                if (mDNS_LoggingEnabled != 0) {
                  LogMsgWithLevel(3,
                                  "CompleteRecordNatMap - Target %##s for ResourceRecord %##s, ExternalPort %d"
                                  ,pcVar4,*(undefined4 *)(iVar5 + 0x20),*(short *)(param_2 + 0x28));
                }
                if ((__dest != (undefined *)0x0) &&
                   (iVar2 = SameDomainName(__dest,pcVar4), iVar2 == 0)) {
                  __n = DomainNameLengthLimit(pcVar4,pcVar4 + 0x100);
                  if (__n < 0x101) {
                    mDNSPlatformMemCopy(__dest,pcVar4,__n);
                  }
                  else {
                    *__dest = 0;
                  }
                  SetNewRData(iVar5 + 4,0,0);
                }
                *(undefined4 *)(iVar5 + 0xe4) = 1;
                *(undefined *)(iVar5 + 0x150) = 0;
                *(int *)(iVar5 + 0xbc) = mDNSPlatformOneSecond;
                *(int *)(iVar5 + 0xc0) = *(int *)(param_1 + 0x234) - mDNSPlatformOneSecond;
                iVar2 = FUN_0040da24(param_1,iVar5,mDNSPlatformOneSecond + *(int *)(param_1 + 0x234)
                                    );
                if (iVar2 != 0) {
                  *(int *)(iVar5 + 0xc0) = *(int *)(iVar5 + 0xc0) + mDNSPlatformOneSecond;
                }
                mDNS_Unlock_(param_1,"CompleteRecordNatMap");
                uVar3 = 1;
                goto LAB_00413438;
              }
              if (mDNS_LoggingEnabled != 0) {
                LogMsgWithLevel(3,
                                "CompleteRecordNatMap - Target %##s for ResourceRecord %##s, ExternalPort %d"
                                ,pcVar4,*(undefined4 *)(iVar5 + 0x20),0);
              }
            }
            if (__dest != (undefined *)0x0) {
              *__dest = 0;
            }
            *(undefined4 *)(iVar5 + 0xe4) = 8;
            *(undefined2 *)(iVar5 + 0x12) = 0;
            *(undefined2 *)(iVar5 + 0x10) = 0;
            mDNS_Unlock_(param_1,"CompleteRecordNatMap");
            uVar3 = 0;
LAB_00413438:
            FUN_0040e070(param_1,iVar5,uVar3);
            return;
          }
          if (mDNS_LoggingEnabled == 0) {
            return;
          }
          param_3 = GetRRDisplayString_rdb(iVar5 + 4,*(int *)(iVar5 + 0x24) + 4,param_1 + 0x2f);
          pcVar4 = "CompleteRecordNatMap called for %s, record in DeregPending";
        }
        uVar3 = 3;
        goto code_r0x00407ce4;
      }
      param_3 = GetRRDisplayString_rdb(iVar5 + 4,*(int *)(iVar5 + 0x24) + 4,param_1 + 0x2f);
      pcVar4 = "CompleteRecordNatMap: Not a service record %s";
    }
    uVar3 = 0;
  }
code_r0x00407ce4:
  uStackX_8 = param_3;
  uStackX_c = param_4;
  FUN_00407c70(uVar3,pcVar4,&uStackX_8);
  return;
}

[ASK_GPT] 5ba5f195642aa6bc
