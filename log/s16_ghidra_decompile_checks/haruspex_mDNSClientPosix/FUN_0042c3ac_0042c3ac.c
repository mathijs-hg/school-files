
/* WARNING: Removing unreachable block (ram,0x0042c484) */
/* WARNING: Removing unreachable block (ram,0x0042c5b8) */

void FUN_0042c3ac(int param_1,int param_2,char param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  if (*(int *)(param_2 + 0x3c) == 0) {
    *(undefined4 *)(param_2 + 0xb8) = 0;
    if (*(int *)(param_2 + 0xf0) != 0) {
      CancelGetZoneData();
      *(undefined4 *)(param_2 + 0xf0) = 0;
    }
    if (*(char *)(param_2 + 600) != '\0') {
      *(undefined4 *)(param_2 + 0x114) = 1;
      *(undefined4 *)(param_2 + 0x124) = 0;
      *(undefined4 *)(param_2 + 0x128) = 0;
      *(undefined2 *)(param_2 + 0x108) = 0;
      if (*(int *)(param_2 + 0x10c) != 0) {
        DisposeTCPConn();
        *(undefined4 *)(param_2 + 0x10c) = 0;
      }
    }
    if (param_3 != '\0') {
      uVar2 = DomainNameHashValue(param_2 + 0x154);
      iVar3 = FUN_00427bd8(param_1 + 0x1278,uVar2 % 499,*(undefined4 *)(param_2 + 4),param_2 + 0x154
                          );
      if (iVar3 != 0) {
        for (puVar6 = *(undefined4 **)(iVar3 + 8); puVar6 != (undefined4 *)0x0;
            puVar6 = (undefined4 *)*puVar6) {
          if ((((puVar6[0x1f] == 4) && ((*(byte *)(puVar6 + 1) & 0x32) != 0)) &&
[32m              ((sVar1 = *(short *)((int)puVar6 + 6), sVar1 == 1 ||[0m
               (((sVar1 == 0x1c || (sVar1 == 5)) || (sVar1 == 0xc)))))) &&
             (iVar3 = LocalOnlyRecordAnswersQuestion(puVar6,param_2), iVar3 != 0)) {
            if (mDNS_LoggingEnabled == 0) {
              return;
            }
            uVar4 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
            uVar5 = GetRRDisplayString_rdb(puVar6 + 1,puVar6[9] + 4,param_1 + 0x2f);
            LogMsgWithLevel(3,"QuestionHasLocalAnswers: Question %p %##s (%s) has local answer %s",
                            param_2,param_2 + 0x154,uVar4,uVar5);
            return;
          }
        }
      }
      iVar3 = (mDNSPlatformOneSecond + 2) / 3;
      *(int *)(param_2 + 0x10) = iVar3;
      *(int *)(param_2 + 0xc) = *(int *)(param_1 + 0x234) - iVar3;
      SetNextQueryTime(param_1,param_2);
      return;
    }
  }
  return;
}

[ASK_GPT] 174cfdfb5f7a0d10
