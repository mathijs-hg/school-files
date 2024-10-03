
/* WARNING: Removing unreachable block (ram,0x00432338) */

undefined4 FUN_004320a0(int param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar4 = *(int *)(param_1 + 0x2b4);
  if (iVar4 != 0) {
    uVar2 = DNSTypeName(*(undefined2 *)(iVar4 + 0x254));
    LogMsgWithLevel(0,
                    "LocalRecordRmvEventsForQuestion: ERROR m->CurrentQuestion already set: %##s (%s)"
                    ,iVar4 + 0x154,uVar2);
  }
  for (puVar5 = *(undefined4 **)(param_1 + 0x2b0); puVar6 = param_2 + 0x55,
      puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
    if (puVar5 == param_2) {
      if (mDNS_LoggingEnabled == 0) {
        return 1;
      }
      uVar2 = DNSTypeName(*(undefined2 *)(puVar5 + 0x95));
      LogMsgWithLevel(3,"LocalRecordRmvEventsForQuestion: New Question %##s (%s)",puVar5 + 0x55,
                      uVar2);
      return 1;
    }
  }
  *(undefined4 **)(param_1 + 0x2b4) = param_2;
  uVar3 = DomainNameHashValue(puVar6);
  iVar4 = FUN_00427bd8(param_1 + 0x1278,uVar3 % 499,param_2[1],puVar6);
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x2b4) = 0;
  }
  else {
    for (puVar5 = *(undefined4 **)(iVar4 + 8); puVar5 != (undefined4 *)0x0;
        puVar5 = (undefined4 *)*puVar5) {
      if ((((puVar5[0x1f] == 4) && ((*(byte *)(puVar5 + 1) & 0x32) != 0)) &&
[32m          ((sVar1 = *(short *)((int)puVar5 + 6), sVar1 == 1 ||[0m
           (((sVar1 == 0x1c || (sVar1 == 5)) || (sVar1 == 0xc)))))) &&
         (iVar4 = LocalOnlyRecordAnswersQuestion(puVar5,param_2), iVar4 != 0)) {
        if (mDNS_LoggingEnabled != 0) {
          uVar2 = GetRRDisplayString_rdb(puVar5 + 1,puVar5[9] + 4,param_1 + 0x2f);
          LogMsgWithLevel(3,
                          "LocalRecordRmvEventsForQuestion: Delivering possible Rmv events with record %s"
                          ,uVar2);
        }
        if ((param_2[8] == 0) || (*(char *)((int)param_2 + 0xbd) == '\0')) {
          uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
          LogMsgWithLevel(0,
                          "LocalRecordRmvEventsForQuestion: ERROR!! CurrentAnswers or LOAddressAnswers is zero %p %##s (%s) CurrentAnswers %d, LOAddressAnswers %d"
                          ,param_2,puVar6,uVar2,param_2[8],*(undefined *)((int)param_2 + 0xbd));
        }
        else {
          FUN_00431d88(param_1,puVar5,0);
          if (*(undefined4 **)(param_1 + 0x2b4) != param_2) {
            *(undefined4 *)(param_1 + 0x2b4) = 0;
            return 0;
          }
        }
      }
    }
    *(undefined4 *)(param_1 + 0x2b4) = 0;
  }
  return 1;
}

[ASK_GPT] 0c68e917cea2b197
