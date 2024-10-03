
void FUN_00431d88(int param_1,int param_2,int param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  undefined *puVar8;
  
  iVar7 = *(int *)(param_1 + 0x2b4);
  if (iVar7 == 0) {
    uVar4 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
                    /* WARNING: Treating indirect jump as call */
    LogMsgWithLevel(0,
                    "AnswerLocalQuestionWithLocalAuthRecord: ERROR!! CurrentQuestion NULL while answering with %s"
                    ,uVar4);
    return;
  }
  bVar3 = false;
  if (((param_3 != 0) && (*(short *)(iVar7 + 0x254) != 5)) && (*(char *)(param_2 + 4) != -0x10)) {
    bVar3 = *(short *)(param_2 + 6) == 5;
  }
  bVar1 = *(byte *)(param_2 + 4);
  if ((bVar1 & 0x3c) == 0) {
    if (param_3 == 0) {
      puVar8 = &DAT_0044de44;
    }
    else {
      puVar8 = &DAT_0044d190;
    }
    uVar4 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,
                    "AnswerLocalQuestionWithLocalAuthRecord: *NOT* delivering %s event for local record type %X %s"
                    ,puVar8,bVar1,uVar4);
  }
  else {
    if (param_3 != 0) {
      *(undefined *)(param_2 + 0x89) = 1;
    }
    iVar5 = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x28) = iVar5;
    if (*(int *)(param_1 + 0x24) != iVar5) {
      LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                      "AnswerLocalQuestionWithLocalAuthRecord",*(int *)(param_1 + 0x24),iVar5);
    }
    if ((*(int *)(iVar7 + 0x288) != 0) && (*(char *)(iVar7 + 0x112) == '\0')) {
      iVar5 = -1;
      if (param_3 != 0) {
        iVar5 = 1;
      }
      *(int *)(iVar7 + 0x20) = iVar5 + *(int *)(iVar7 + 0x20);
      if (((*(int *)(param_2 + 0x7c) == 4) && ((*(byte *)(param_2 + 4) & 0x32) != 0)) &&
[32m         ((sVar2 = *(short *)(param_2 + 6), sVar2 == 1 ||[0m
          (((sVar2 == 0x1c || (sVar2 == 5)) || (sVar2 == 0xc)))))) {
        if ((!bVar3) || (*(char *)(iVar7 + 0x25b) != '\0')) {
[32m          cVar6 = -1;[0m
          if (param_3 != 0) {
            cVar6 = '\x01';
          }
          *(char *)(iVar7 + 0xbd) = cVar6 + *(char *)(iVar7 + 0xbd);
          *(undefined4 *)(iVar7 + 0x10) = 0;
          (**(code **)(iVar7 + 0x288))(param_1,iVar7,param_2 + 4,param_3);
        }
        iVar5 = *(int *)(param_1 + 0x28);
        if (*(int *)(param_1 + 0x24) != iVar5) {
          LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                          "AnswerLocalQuestionWithLocalAuthRecord",*(int *)(param_1 + 0x24),iVar5);
          iVar5 = *(int *)(param_1 + 0x28);
        }
        *(int *)(param_1 + 0x28) = iVar5 + -1;
        if (!bVar3) {
          return;
        }
        if (*(int *)(param_1 + 0x2b4) != iVar7) {
          return;
        }
        FUN_00431a38(param_1,iVar7,param_2 + 4);
        return;
      }
      (**(code **)(iVar7 + 0x288))(param_1,iVar7,param_2 + 4,param_3);
    }
    iVar7 = *(int *)(param_1 + 0x28);
    if (*(int *)(param_1 + 0x24) != iVar7) {
      LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                      "AnswerLocalQuestionWithLocalAuthRecord",*(int *)(param_1 + 0x24),iVar7);
      iVar7 = *(int *)(param_1 + 0x28);
    }
    *(int *)(param_1 + 0x28) = iVar7 + -1;
  }
  return;
}

[ASK_GPT] 79868da2effb9119
