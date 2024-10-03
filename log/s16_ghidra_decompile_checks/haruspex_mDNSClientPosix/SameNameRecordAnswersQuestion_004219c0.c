
bool SameNameRecordAnswersQuestion(uint *param_1,int param_2)

{
  uint uVar1;
  short sVar3;
  int iVar2;
  bool bVar4;
  short sVar5;
  uint uVar6;
  char local_18 [12];
  
  uVar6 = param_1[6];
  local_18[0] = '\x01';
  if ((uVar6 == 0xfffffffe) || (uVar6 == 0xfffffffc)) {
    LogMsgWithLevel(0,
                    "SameNameRecordAnswersQuestion: ERROR!! called with LocalOnly ResourceRecord %p, Question %p"
                    ,uVar6,*(undefined4 *)(param_2 + 0x134));
    bVar4 = false;
  }
  else if (((*(char *)(param_2 + 0x25c) == '\0') ||
           (bVar4 = false, *(char *)(param_2 + 0xbc) == '\0')) &&
          (bVar4 = false, *(char *)(param_2 + 0x12e) == '\0')) {
    if (uVar6 == 0) {
[32m      sVar5 = 0;[0m
      if (param_1[9] != 0) {
[32m        sVar5 = *(short *)(param_1[9] + 0x13e);[0m
      }
[32m      sVar3 = 0;[0m
      if (*(int *)(param_2 + 0xdc) != 0) {
[32m        sVar3 = *(short *)(*(int *)(param_2 + 0xdc) + 0x13e);[0m
      }
      if (sVar5 != sVar3) {
        return false;
      }
      iVar2 = FUN_0041d1e8(param_1,param_2,local_18);
      if (iVar2 == 0) {
        return false;
      }
    }
    else {
      uVar1 = *(uint *)(param_2 + 0x134);
      if (((uVar1 != 0) && (uVar1 != 0xfffffffe)) && (uVar6 != uVar1)) {
        return false;
      }
    }
    if (((param_1[6] == 0) || (bVar4 = false, *(short *)(param_2 + 0x152) == 0)) &&
       (((*param_1 & 0xff00ffff) != 0xf0000005 ||
        (bVar4 = false, *(short *)((int)param_1 + 2) == *(short *)(param_2 + 0x254))))) {
      if ((((local_18[0] != '\0') && (*(short *)((int)param_1 + 2) != 5)) &&
          (*(short *)((int)param_1 + 2) != *(short *)(param_2 + 0x254))) &&
         ((*(short *)(param_2 + 0x254) != 0xff &&
          (iVar2 = RRAssertsNonexistence(param_1), iVar2 == 0)))) {
        return false;
      }
      if ((*(short *)(param_1 + 1) == *(short *)(param_2 + 0x256)) ||
         (*(short *)(param_2 + 0x256) == 0xff)) {
        iVar2 = AnonInfoAnswersQuestion(param_1,param_2);
        bVar4 = iVar2 != 0;
      }
      else {
        bVar4 = false;
      }
    }
  }
  return bVar4;
}

[ASK_GPT] 503180ababbbc308
