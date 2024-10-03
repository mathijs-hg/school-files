
/* WARNING: Removing unreachable block (ram,0x00432404) */

undefined4 FUN_00432360(int param_1,int param_2,char param_3)

{
  undefined uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar6 = *(int *)(param_1 + 0x216c);
  if (iVar6 != 0) {
    uVar3 = GetRRDisplayString_rdb(iVar6 + 4,*(int *)(iVar6 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,"AnswerQuestionWithLORecord ERROR m->CurrentRecord already set %s",uVar3);
  }
  uVar4 = DomainNameHashValue(param_2 + 0x154);
  iVar6 = FUN_00427bd8(param_1 + 0x1278,uVar4 % 499,*(undefined4 *)(param_2 + 4),param_2 + 0x154);
  if (iVar6 != 0) {
    *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(iVar6 + 8);
    do {
      do {
        puVar9 = *(undefined4 **)(param_1 + 0x216c);
        if ((puVar9 == (undefined4 *)0x0) || (puVar9 == *(undefined4 **)(iVar6 + 0x14)))
        goto LAB_00432534;
        *(undefined4 *)(param_1 + 0x216c) = *puVar9;
      } while (((puVar9[0x1f] != 4) && ((puVar9[0x1f] != 5 || (*(int *)(param_2 + 0x134) != 0)))) ||
              (iVar8 = LocalOnlyRecordAnswersQuestion(puVar9,param_2), iVar8 == 0));
      if (param_3 != '\0') {
        if (mDNS_LoggingEnabled != 0) {
          uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
          uVar5 = GetRRDisplayString_rdb(puVar9 + 1,puVar9[9] + 4,param_1 + 0x2f);
          LogMsgWithLevel(3,"AnswerQuestionWithLORecord: question %##s (%s) answered by %s",
                          param_2 + 0x154,uVar3,uVar5);
        }
        *(undefined4 *)(param_1 + 0x216c) = 0;
        return 1;
      }
      FUN_00431d88(param_1,puVar9,1);
    } while (*(int *)(param_1 + 0x2b4) == param_2);
  }
LAB_00432534:
  iVar8 = *(int *)(param_1 + 0x2b4);
  *(undefined4 *)(param_1 + 0x216c) = 0;
  if (iVar8 == param_2) {
    if (*(char *)(param_2 + 0xbd) == '\0') {
      if (iVar6 != 0) {
        for (puVar9 = *(undefined4 **)(iVar6 + 0x14); puVar9 != (undefined4 *)0x0;
            puVar9 = (undefined4 *)*puVar9) {
          if ((((puVar9[0x1f] == 4) && ((*(byte *)(puVar9 + 1) & 0x32) != 0)) &&
[32m              ((sVar2 = *(short *)((int)puVar9 + 6), sVar2 == 1 ||[0m
               (((sVar2 == 0x1c || (sVar2 == 5)) || (sVar2 == 0xc)))))) &&
             (iVar6 = LocalOnlyRecordAnswersQuestion(puVar9,iVar8), iVar6 != 0)) {
            if (mDNS_LoggingEnabled == 0) {
              return 1;
            }
            uVar3 = DNSTypeName(*(undefined2 *)(iVar8 + 0x254));
            pcVar7 = 
            "AnswerQuestionWithLORecord: Question %p %##s (%s) will be answered using new local auth records  LOAddressAnswers %d"
            ;
            uVar1 = *(undefined *)(iVar8 + 0xbd);
            iVar6 = iVar8 + 0x154;
            goto LAB_00432680;
          }
        }
      }
      return 0;
    }
    if (mDNS_LoggingEnabled == 0) {
      return 1;
    }
    uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
    uVar1 = *(undefined *)(param_2 + 0xbd);
    pcVar7 = 
    "AnswerQuestionWithLORecord: Question %p %##s (%s) answered using local auth records LOAddressAnswers %d"
    ;
    iVar6 = param_2 + 0x154;
    iVar8 = param_2;
LAB_00432680:
    LogMsgWithLevel(3,pcVar7,iVar8,iVar6,uVar3,uVar1);
  }
  else {
    if (mDNS_LoggingEnabled == 0) {
      return 1;
    }
    LogMsgWithLevel(3,
                    "AnswerQuestionWithLORecord: Question deleted while while answering LocalOnly record answers"
                   );
  }
  return 1;
}

[ASK_GPT] 8acec23fc726a669
