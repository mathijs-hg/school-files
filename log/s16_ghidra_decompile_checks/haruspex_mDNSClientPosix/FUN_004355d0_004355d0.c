
void FUN_004355d0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  undefined *puVar6;
  int iVar7;
  code *pcVar8;
  undefined auStack_d8 [4];
  undefined auStack_d4 [184];
  
  iVar7 = *(int *)(param_1 + 0x2b4);
  if (((param_3 == 0) || (*(short *)(iVar7 + 0x254) == 5)) || (*(char *)(param_2 + 4) == -0x10)) {
    bVar1 = false;
  }
  else {
    bVar1 = *(short *)(param_2 + 6) == 5;
  }
  if ((*(char *)(iVar7 + 0x266) != '\0') &&
     ((param_3 == 0 || ((*(char *)(param_2 + 4) == -0x10 && (param_3 == 1)))))) {
    *(undefined4 *)(iVar7 + 0xc4) = 1;
    *(undefined4 *)(iVar7 + 200) = 0;
  }
  if (*(char *)(iVar7 + 0xbd) != '\0') {
    if (mDNS_LoggingEnabled == 0) {
      return;
    }
    uVar2 = DNSTypeName(*(undefined2 *)(iVar7 + 0x254));
    uVar3 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(3,
                    "AnswerCurrentQuestionWithResourceRecord: Question %p %##s (%s) not answering with record %s due to LOAddressAnswers %d"
                    ,iVar7,iVar7 + 0x154,uVar2,uVar3,*(undefined *)(iVar7 + 0xbd));
    return;
  }
  if (((*(char *)(iVar7 + 0x25c) != '\0') && (*(char *)(iVar7 + 0xbc) != '\0')) ||
     (*(char *)(iVar7 + 0x12e) != '\0')) {
    if (*(char *)(iVar7 + 0x260) == '\0') {
      return;
    }
    if (*(char *)(param_2 + 4) != -0x10) {
      return;
    }
    if (*(int *)(param_1 + 0x234) - *(int *)(iVar7 + 0xc0) < 0) {
      return;
    }
  }
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x234);
  if (param_3 == 1) {
    if ((*(int *)(iVar7 + 0x3c) == 0) && (*(int *)(param_2 + 0x44) != iVar7)) {
      if (*(int *)(param_2 + 0x44) == 0) {
        *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x2d4) + 1;
      }
      *(int *)(param_2 + 0x44) = iVar7;
      FUN_00428c90(param_1,param_2);
    }
    if ((*(char *)(iVar7 + 0x259) != '\0') || ((*(byte *)(param_2 + 4) & 0x10) != 0)) {
LAB_004357d0:
      if (((0 < *(int *)(iVar7 + 0x10)) && (*(int *)(iVar7 + 0x3c) == 0)) &&
         ((*(short *)(iVar7 + 0x152) == 0 || (*(char *)(iVar7 + 600) == '\0')))) {
        *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(param_1 + 0x234);
        uVar2 = *(undefined4 *)(param_1 + 0x234);
        *(undefined4 *)(iVar7 + 0x1c) = 0;
        *(undefined4 *)(iVar7 + 0xb4) = uVar2;
        iVar4 = mDNSPlatformOneSecond;
        *(undefined4 *)(iVar7 + 0xb0) = 0;
        *(undefined *)(iVar7 + 0xec) = 0;
        *(int *)(iVar7 + 0x10) = iVar4 * 0xe10;
      }
    }
  }
  else if ((param_3 == 2) && (*(int *)(iVar7 + 0xb0) == 0)) goto LAB_004357d0;
  if (*(int *)(param_2 + 0x38) != 0) {
    return;
  }
  if ((*(char *)(param_2 + 4) == -0x10) ||
     ((*(short *)(iVar7 + 0x254) != 0x2f && (iVar4 = RRAssertsNonexistence(param_2 + 4), iVar4 != 0)
      ))) {
    if (param_3 == 0) {
      return;
    }
    if (((param_3 != 6) && (param_3 != 3)) && (*(char *)(iVar7 + 0x25b) == '\0')) {
      return;
    }
  }
  if (((*(int *)(iVar7 + 0x288) != 0) && (*(char *)(iVar7 + 0x112) == '\0')) &&
     ((!bVar1 || (*(char *)(iVar7 + 0x25b) != '\0')))) {
    iVar4 = *(int *)(param_1 + 0x28) + 1;
    *(int *)(param_1 + 0x28) = iVar4;
    if (*(int *)(param_1 + 0x24) != iVar4) {
      LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                      "AnswerCurrentQuestionWithResourceRecord",*(int *)(param_1 + 0x24),iVar4);
    }
    if ((*(short *)(iVar7 + 0x254) == 0x2f) ||
       (iVar4 = RRAssertsNonexistence(param_2 + 4), iVar4 == 0)) {
      pcVar8 = *(code **)(iVar7 + 0x288);
      puVar6 = (undefined *)(param_2 + 4);
    }
    else {
      MakeNegativeCacheRecord
                (param_1,auStack_d8,iVar7 + 0x154,*(undefined4 *)(iVar7 + 4),
                 *(undefined2 *)(iVar7 + 0x254),*(undefined2 *)(iVar7 + 0x256),1,
                 *(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(iVar7 + 0xdc));
      pcVar8 = *(code **)(iVar7 + 0x288);
      puVar6 = auStack_d4;
    }
    (*pcVar8)(param_1,iVar7,puVar6,param_3);
    iVar4 = *(int *)(param_1 + 0x28);
    if (*(int *)(param_1 + 0x24) != iVar4) {
      LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                      "AnswerCurrentQuestionWithResourceRecord",*(int *)(param_1 + 0x24),iVar4);
      iVar4 = *(int *)(param_1 + 0x28);
    }
    *(int *)(param_1 + 0x28) = iVar4 + -1;
  }
  iVar4 = *(int *)(param_1 + 0x2b4);
  if (((iVar4 == iVar7) && (param_3 == 1)) && (*(char *)(iVar7 + 0xcc) == '\0')) {
[32m    cVar5 = *(char *)(iVar7 + 0x266);[0m
    if (cVar5 == '\0') goto LAB_00435a94;
    if ((*(int *)(iVar7 + 0xc4) == 1) && (*(int *)(iVar7 + 0xdc) != 0)) {
      *(undefined4 *)(iVar7 + 0xc4) = 2;
      iVar7 = *(int *)(param_1 + 0x28) + 1;
      *(int *)(param_1 + 0x28) = iVar7;
      if (*(int *)(param_1 + 0x24) != iVar7) {
        LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                        "AnswerCurrentQuestionWithResourceRecord",*(int *)(param_1 + 0x24),iVar7);
      }
      VerifySignature(param_1,0,iVar4);
      iVar7 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x24) != iVar7) {
        LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                        "AnswerCurrentQuestionWithResourceRecord",*(int *)(param_1 + 0x24),iVar7);
        iVar7 = *(int *)(param_1 + 0x28);
      }
      *(int *)(param_1 + 0x28) = iVar7 + -1;
      return;
    }
  }
[32m  cVar5 = *(char *)(iVar7 + 0x266);[0m
LAB_00435a94:
  if (((cVar5 == '\0') && (*(char *)(iVar7 + 0xcc) == '\0')) && ((bVar1 && (iVar4 == iVar7)))) {
    FUN_00431a38(param_1,iVar4,param_2 + 4);
  }
  return;
}

[ASK_GPT] d7cd5e1a001f8125
