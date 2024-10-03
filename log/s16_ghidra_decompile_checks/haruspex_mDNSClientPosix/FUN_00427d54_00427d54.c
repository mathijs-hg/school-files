
undefined4 FUN_00427d54(undefined4 param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
[32m  sVar1 = *(short *)(param_2 + 0x254);[0m
  if ((sVar1 == 1) || (sVar1 == 0x1c)) {
    iVar4 = GetAuthInfoForName_internal(param_1,param_2 + 0x154);
    if ((iVar4 == 0) || ((*(int *)(iVar4 + 4) != 0 || (*(char *)(iVar4 + 8) == '\0')))) {
      if (param_3 == 0) {
        if (mDNS_LoggingEnabled != 0) {
          uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
          LogMsgWithLevel(3,
                          "ShouldSuppressUnicastQuery: Query suppressed for %##s, qtype %s, as the DNS server is NULL"
                          ,param_2 + 0x154,uVar3);
          return 1;
        }
        return 1;
      }
      if (*(short *)(param_2 + 0x254) == 1) {
        if (*(char *)(param_3 + 0x140) == '\0') {
LAB_00427f64:
          if (mDNS_LoggingEnabled != 0) {
            uVar3 = DNSTypeName();
            if (*(char *)(param_3 + 0x140) == '\0') {
              pcVar6 = "false";
            }
            else {
              pcVar6 = "true";
            }
            if (*(char *)(param_3 + 0x141) == '\0') {
              pcVar5 = "false";
            }
            else {
              pcVar5 = "true";
            }
            LogMsgWithLevel(3,
                            "ShouldSuppressUnicastQuery: Query suppressed for %##s, qtype %s, since DNS Configuration does not allow (req_A is %s and req_AAAA is %s)"
                            ,param_2 + 0x154,uVar3,pcVar6,pcVar5);
            return 1;
          }
          return 1;
        }
        if (mDNS_LoggingEnabled == 0) {
          return 0;
        }
        uVar3 = DNSTypeName(1);
        uVar2 = *(undefined2 *)(param_3 + 0x20);
        pcVar6 = 
        "ShouldSuppressUnicastQuery: Query not suppressed for %##s, qtype %s, DNSServer %##s %#a:%d allows A queries"
        ;
      }
      else {
        if ((*(short *)(param_2 + 0x254) != 0x1c) || (*(char *)(param_3 + 0x141) == '\0'))
        goto LAB_00427f64;
        if (mDNS_LoggingEnabled == 0) {
          return 0;
        }
        uVar3 = DNSTypeName(0x1c);
        uVar2 = *(undefined2 *)(param_3 + 0x20);
        pcVar6 = 
        "ShouldSuppressUnicastQuery: Query not suppressed for %##s, qtype %s, DNSServer %##s %#a:%d allows AAAA queries"
        ;
      }
      LogMsgWithLevel(3,pcVar6,param_2 + 0x154,uVar3,param_3 + 0x30,param_3 + 0xc,uVar2);
      return 0;
    }
    if (mDNS_LoggingEnabled == 0) {
      return 0;
    }
    uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
    pcVar6 = "ShouldSuppressUnicastQuery: Query not suppressed for %##s, qtype %s, Private Domain";
  }
  else {
    if (mDNS_LoggingEnabled == 0) {
      return 0;
    }
    uVar3 = DNSTypeName(sVar1);
    pcVar6 = "ShouldSuppressUnicastQuery: Query not suppressed for %##s, qtype %s, not A/AAAA type";
  }
  LogMsgWithLevel(3,pcVar6,param_2 + 0x154,uVar3);
  return 0;
}

[ASK_GPT] 6380696907b1f28a
