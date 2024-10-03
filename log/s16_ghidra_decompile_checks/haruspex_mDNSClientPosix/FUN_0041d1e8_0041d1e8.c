
bool FUN_0041d1e8(int param_1,int param_2,undefined *param_3)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  
  *param_3 = 1;
[32m  sVar1 = *(short *)(param_1 + 2);[0m
[32m  sVar2 = *(short *)(param_2 + 0x254);[0m
  if (sVar2 != sVar1) {
    if ((sVar2 == 0x2b) || (sVar2 == 0x30)) {
      return false;
    }
    if (sVar1 == 0x2e) {
      if (*(char *)(param_2 + 0xcc) != '\0') {
[32m        sVar1 = *(short *)(*(int *)(param_1 + 0x20) + 4);[0m
        if ((sVar1 != 5) && (sVar2 != sVar1)) {
          return false;
        }
        if (mDNS_LoggingEnabled != 0) {
          uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
          LogMsgWithLevel(3,"DNSSECRecordAnswersQuestion: RRSIG matched question %##s (%s)",
                          param_2 + 0x154,uVar3);
        }
        *param_3 = 0;
      }
    }
    else {
      if (sVar1 != 0x2f) {
        return true;
      }
      if (*(char *)(param_2 + 0x266) != '\0') {
        return false;
      }
      if (*(char *)(param_2 + 0xcc) != '\0') {
        return false;
      }
      if (*(char *)(param_2 + 0x267) != '\0') {
        return *(char *)(param_2 + 0x268) == '\0';
      }
    }
  }
  return true;
}

[ASK_GPT] fb29e9eaee61e104
