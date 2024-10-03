
undefined4 FUN_004326d4(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  
[32m  sVar1 = *(short *)(param_2 + 0x254);[0m
  if ((sVar1 == 1) || (sVar1 == 0x1c)) {
    if ((*(int *)(param_2 + 0x134) == -3) ||
       (iVar3 = IsLocalDomain(param_2 + 0x154,param_2), iVar3 == 0)) {
      uVar2 = FUN_00427d54(param_1,param_2,*(undefined4 *)(param_2 + 0xdc));
      return uVar2;
    }
    for (puVar6 = *(undefined4 **)(param_1 + 0x2174); puVar6 != (undefined4 *)0x0;
        puVar6 = (undefined4 *)*puVar6) {
      if ((*(char *)(puVar6 + 1) != '\0') && (*(char *)((int)puVar6 + 0x1595) == '\0')) {
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,"ShouldSuppressDotLocalQuery: Found interface %s, not suppressing",
                          (int)puVar6 + 0x1552);
        }
        goto LAB_004328dc;
      }
    }
    *(int *)(param_1 + 0x2b4) = param_2;
    iVar3 = FUN_00432360(param_1,param_2,1);
    *(undefined4 *)(param_1 + 0x2b4) = 0;
    if (iVar3 == 0) {
      puVar6 = *(undefined4 **)(param_1 + 0x2160);
      while( true ) {
        if (puVar6 == (undefined4 *)0x0) {
          if (mDNS_LoggingEnabled != 0) {
            uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
            LogMsgWithLevel(3,
                            "ShouldSuppressQuery: Query suppressed for %##s, qtype %s, Local question"
                            ,param_2 + 0x154,uVar2);
            return 1;
          }
          return 1;
        }
        iVar3 = ResourceRecordAnswersQuestion(puVar6 + 1,param_2);
        if (iVar3 != 0) break;
        puVar6 = (undefined4 *)*puVar6;
      }
      if (mDNS_LoggingEnabled != 0) {
        uVar2 = GetRRDisplayString_rdb(puVar6 + 1,puVar6[9] + 4,param_1 + 0x2f);
        uVar4 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
        LogMsgWithLevel(3,
                        "ShouldSuppressDotLocalQuery: Found resource record %s for %##s (%s) not suppressing"
                        ,uVar2,param_2 + 0x154,uVar4);
      }
    }
    else if (mDNS_LoggingEnabled != 0) {
      uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
      LogMsgWithLevel(3,
                      "ShouldSuppressDotLocalQuery: Found LocalOnly record for %##s (%s), not suppressing"
                      ,param_2 + 0x154,uVar2);
    }
LAB_004328dc:
    if (mDNS_LoggingEnabled == 0) {
      return 0;
    }
    uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
    pcVar5 = "ShouldSuppressQuery: Query not suppressed for %##s, qtype %s, Local question";
  }
  else {
    if (mDNS_LoggingEnabled == 0) {
      return 0;
    }
    uVar2 = DNSTypeName(sVar1);
    pcVar5 = "ShouldSuppressQuery: Query not suppressed for %##s, qtype %s, not A/AAAA type";
  }
  LogMsgWithLevel(3,pcVar5,param_2 + 0x154,uVar2);
  return 0;
}

[ASK_GPT] 123e932cae947058
