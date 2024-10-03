
bool AnyTypeRecordAnswersQuestion(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x18);
  if ((iVar5 == -2) || (iVar5 == -4)) {
    LogMsgWithLevel(0,
                    "AnyTypeRecordAnswersQuestion: ERROR!! called with LocalOnly ResourceRecord %p, Question %p"
                    ,iVar5,*(undefined4 *)(param_2 + 0x134));
    bVar2 = false;
  }
  else {
    if (iVar5 == 0) {
[32m      sVar4 = 0;[0m
      if (*(int *)(param_1 + 0x24) != 0) {
[32m        sVar4 = *(short *)(*(int *)(param_1 + 0x24) + 0x13e);[0m
      }
[32m      sVar1 = 0;[0m
      if (*(int *)(param_2 + 0xdc) != 0) {
[32m        sVar1 = *(short *)(*(int *)(param_2 + 0xdc) + 0x13e);[0m
      }
      if (sVar4 != sVar1) {
        return false;
      }
    }
    else {
      iVar3 = *(int *)(param_2 + 0x134);
      if (((iVar3 != 0) && (iVar3 != -2)) && (iVar5 != iVar3)) {
        return false;
      }
      if (*(short *)(param_2 + 0x152) != 0) {
        return false;
      }
    }
    if ((*(short *)(param_1 + 4) == *(short *)(param_2 + 0x256)) ||
       (bVar2 = false, *(short *)(param_2 + 0x256) == 0xff)) {
      iVar5 = AnonInfoAnswersQuestion(param_1,param_2,iVar5,param_4,&_gp);
      if (iVar5 == 0) {
        bVar2 = false;
      }
      else {
        bVar2 = false;
        if (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 4)) {
          iVar5 = SameDomainName(*(undefined4 *)(param_1 + 0x1c),param_2 + 0x154);
          bVar2 = iVar5 != 0;
        }
      }
    }
  }
  return bVar2;
}

[ASK_GPT] e0247966a5ddf221
