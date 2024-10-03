
void mDNSCoreRestartAddressQueries
               (int param_1,char param_2,code *param_3,code *param_4,undefined4 param_5)

{
  short sVar1;
  undefined4 uVar2;
  uint __n;
  undefined uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28) + 1) {
    LogMsgWithLevel(0,"%s: Lock not held! mDNS_busy (%ld) mDNS_reentrancy (%ld)",
                    "mDNSCoreRestartAddressQueries",*(int *)(param_1 + 0x24),
                    *(int *)(param_1 + 0x28));
  }
  if (param_3 != (code *)0x0) {
    (*param_3)(param_1);
  }
  iVar5 = *(int *)(param_1 + 0x2c0);
  if (iVar5 != 0) {
    uVar2 = DNSTypeName(*(undefined2 *)(iVar5 + 0x254));
    LogMsgWithLevel(0,
                    "mDNSCoreRestartAddressQueries: ERROR!! m->RestartQuestion already set: %##s (%s)"
                    ,iVar5 + 0x154,uVar2);
  }
  *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(param_1 + 0x2ac);
  puVar7 = (undefined4 *)0x0;
LAB_00437738:
  do {
    while( true ) {
      do {
        while( true ) {
          puVar6 = *(undefined4 **)(param_1 + 0x2c0);
          if (puVar6 == (undefined4 *)0x0) {
            if (param_4 != (code *)0x0) {
              (*param_4)(param_1,param_5);
            }
            while (puVar7 != (undefined4 *)0x0) {
              puVar6 = (undefined4 *)*puVar7;
              *puVar7 = 0;
              if (mDNS_LoggingEnabled != 0) {
                uVar2 = DNSTypeName(*(undefined2 *)(puVar7 + 0x95),puVar7);
                LogMsgWithLevel(3,"mDNSCoreRestartAddressQueries: Start question %p %##s (%s)",
                                puVar7,puVar7 + 0x55,uVar2);
              }
              mDNS_StartQuery_internal(param_1,puVar7);
              puVar7 = puVar6;
            }
            return;
          }
          *(undefined4 *)(param_1 + 0x2c0) = *puVar6;
          iVar5 = IsGetZoneDataQuestion(puVar6);
          if (iVar5 == 0) break;
          puVar8 = (undefined4 *)*puVar6;
          if (mDNS_LoggingEnabled != 0) {
            uVar2 = DNSTypeName(*(undefined2 *)(puVar6 + 0x95));
            LogMsgWithLevel(3,
                            "mDNSCoreRestartAddressQueries: Skipping GetZoneDataQuestion %p %##s (%s)"
                            ,puVar6,puVar6 + 0x55,uVar2);
          }
          for (; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
            if ((puVar6 == (undefined4 *)(puVar8[0x3c] + 0x32c)) && (mDNS_LoggingEnabled != 0)) {
              uVar2 = DNSTypeName(*(undefined2 *)(puVar8 + 0x95));
              LogMsgWithLevel(3,
                              "mDNSCoreRestartAddressQueries: Question %p %##s (%s) referring to GetZoneDataQuestion %p, not stopping"
                              ,puVar8,puVar8 + 0x55,uVar2,puVar6);
            }
          }
        }
[32m        sVar1 = *(short *)(puVar6 + 0x95);[0m
      } while ((((sVar1 != 1) && (sVar1 != 0x1c)) && (sVar1 != 5)) ||
              ((param_2 != '\0' && (*(char *)(puVar6 + 0x99) == '\0'))));
      iVar5 = FUN_00435b04(param_1,puVar6);
      if (iVar5 == 0) break;
      iVar5 = FUN_004320a0(param_1,puVar6);
      if (iVar5 == 0) goto code_r0x004375ec;
      if (mDNS_LoggingEnabled != 0) {
        uVar2 = DNSTypeName(*(undefined2 *)(puVar6 + 0x95));
        LogMsgWithLevel(3,
                        "mDNSCoreRestartAddressQueries: Stop question %p %##s (%s), AppendSearchDomains %d, qnameOrig %p"
                        ,puVar6,puVar6 + 0x55,uVar2,(int)*(char *)(puVar6 + 0x99),puVar6[0xa1]);
      }
      mDNS_StopQuery_internal(param_1,puVar6);
      if (puVar6[0xa1] != 0) {
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,"mDNSCoreRestartAddressQueries: qnameOrig %##s");
        }
        __n = DomainNameLengthLimit(puVar6[0xa1],puVar6[0xa1] + 0x100);
        if (__n < 0x101) {
          mDNSPlatformMemCopy(puVar6 + 0x55,(void *)puVar6[0xa1],__n);
        }
        else {
          *(undefined *)(puVar6 + 0x55) = 0;
        }
        mDNSPlatformMemFree((void *)puVar6[0xa1]);
        puVar6[0xa1] = 0;
        if (*(char *)(puVar6 + 0x99) == '\0') {
LAB_0043771c:
          uVar3 = 0;
        }
        else {
          iVar5 = CountLabels(puVar6 + 0x55);
          uVar3 = 1;
          if (iVar5 != 1) goto LAB_0043771c;
        }
        *(undefined *)((int)puVar6 + 0x25f) = uVar3;
      }
      *puVar6 = puVar7;
      *(undefined *)((int)puVar6 + 0x263) = 0;
      puVar7 = puVar6;
    }
    pcVar4 = 
    "mDNSCoreRestartAddressQueries: Question deleted while delivering Cache Record RMV events";
  } while (mDNS_LoggingEnabled == 0);
  goto LAB_00437604;
code_r0x004375ec:
  if (mDNS_LoggingEnabled != 0) {
    pcVar4 = 
    "mDNSCoreRestartAddressQueries: Question deleted while delivering Local Record RMV events";
LAB_00437604:
    LogMsgWithLevel(3,pcVar4);
  }
  goto LAB_00437738;
}

[ASK_GPT] fc9ddc6d46180939
