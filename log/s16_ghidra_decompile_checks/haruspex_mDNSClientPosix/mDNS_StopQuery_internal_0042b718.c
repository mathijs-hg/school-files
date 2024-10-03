
/* WARNING: Removing unreachable block (ram,0x0042b780) */

undefined4 mDNS_StopQuery_internal(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  uVar1 = DomainNameHashValue(param_2 + 0x55);
  iVar2 = CacheGroupForName(param_1,uVar1 % 499,param_2[1],param_2 + 0x55);
  puVar5 = (undefined4 *)(param_1 + 0x2b8);
  if ((param_2[0x4d] != -2) && (puVar5 = (undefined4 *)(param_1 + 0x2ac), param_2[0x4d] == -4)) {
    puVar5 = (undefined4 *)(param_1 + 0x2b8);
  }
  do {
    puVar7 = puVar5;
    puVar5 = (undefined4 *)*puVar7;
    if (puVar5 == (undefined4 *)0x0) {
      if (-1 < (int)param_2[4]) {
        uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
        LogMsgWithLevel(0,"mDNS_StopQuery_internal: Question %##s (%s) not found in active list",
                        param_2 + 0x55,uVar3);
      }
      return 0xfffefffb;
    }
  } while (puVar5 != param_2);
  *puVar7 = *param_2;
  if (param_2[0xf] == 0) {
    puVar5 = (undefined4 *)0x0;
    for (puVar7 = *(undefined4 **)(param_1 + 0x2ac); puVar7 != (undefined4 *)0x0;
        puVar7 = (undefined4 *)*puVar7) {
      if (((undefined4 *)puVar7[0xf] == param_2) &&
         (puVar7[0xf] = puVar5, puVar5 == (undefined4 *)0x0)) {
        puVar7[3] = param_2[3];
        puVar7[4] = param_2[4];
        puVar7[5] = param_2[5];
        puVar7[6] = param_2[6];
        puVar7[7] = param_2[7];
        puVar7[0x2c] = param_2[0x2c];
        puVar7[0x2d] = param_2[0x2d];
        puVar7[0x2e] = param_2[0x2e];
        puVar7[0x3c] = param_2[0x3c];
[32m[32m        memcpy(puVar7 + 0x3d,param_2 + 0x3d,0x14);[0m[0m
        *(undefined2 *)(puVar7 + 0x42) = *(undefined2 *)(param_2 + 0x42);
        puVar7[0x37] = param_2[0x37];
        puVar7[0x38] = param_2[0x38];
        puVar7[0x39] = param_2[0x39];
        *(undefined *)(puVar7 + 0x3b) = *(undefined *)(param_2 + 0x3b);
        *(undefined2 *)(puVar7 + 0x3a) = *(undefined2 *)(param_2 + 0x3a);
        *(undefined2 *)((int)puVar7 + 0xea) = *(undefined2 *)((int)param_2 + 0xea);
        *(undefined2 *)((int)puVar7 + 0x152) = *(undefined2 *)((int)param_2 + 0x152);
        if (puVar7[0x36] != 0) {
          mDNSPlatformUDPClose();
        }
        puVar7[0x36] = param_2[0x36];
        puVar7[0x45] = param_2[0x45];
        puVar7[0x46] = param_2[0x46];
        puVar7[0x47] = param_2[0x47];
        *(undefined2 *)(puVar7 + 0x48) = *(undefined2 *)(param_2 + 0x48);
        puVar7[0x49] = param_2[0x49];
        puVar7[0x4a] = param_2[0x4a];
        param_2[0x36] = 0;
        param_2[0x3c] = 0;
        if (puVar7[0x3c] != 0) {
          if (mDNS_LoggingEnabled != 0) {
            uVar3 = DNSTypeName(*(undefined2 *)(puVar7 + 0x95));
            LogMsgWithLevel(3,"UpdateQuestionDuplicates transferred nta pointer for %##s (%s)",
                            puVar7 + 0x55,uVar3);
          }
          *(undefined4 **)(puVar7[0x3c] + 0x328) = puVar7;
        }
        if ((param_2[0x43] != 0) && (mDNS_LoggingEnabled != 0)) {
          LogMsgWithLevel(3,"UpdateQuestionDuplicates did not transfer tcp pointer");
        }
        if (param_2[0x45] == 3) {
          if (mDNS_LoggingEnabled != 0) {
            uVar3 = DNSTypeName(*(undefined2 *)(puVar7 + 0x95));
            LogMsgWithLevel(3,"UpdateQuestionDuplicates transferred LLQ state for %##s (%s)",
                            puVar7 + 0x55,uVar3);
          }
          param_2[0x45] = 0;
        }
        SetNextQueryTime(param_1,puVar7);
        puVar5 = puVar7;
      }
    }
  }
  else if (mDNS_LoggingEnabled != 0) {
    uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
    iVar6 = param_2[0xf];
    uVar4 = DNSTypeName(*(undefined2 *)(iVar6 + 0x254));
    LogMsgWithLevel(3,"UpdateQuestionDuplicates: question %p %##s (%s) duplicate of %p %##s (%s)",
                    param_2,param_2 + 0x55,uVar3,iVar6,iVar6 + 0x154,uVar4);
  }
  puVar5 = (undefined4 *)0x0;
  param_2[4] = 0xffffffff;
  if (iVar2 != 0) {
    puVar5 = *(undefined4 **)(iVar2 + 8);
  }
  for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
    if ((undefined4 *)puVar5[0x11] == param_2) {
      puVar7 = *(undefined4 **)(param_1 + 0x2ac);
      while ((puVar7 != (undefined4 *)0x0 &&
             ((((int)puVar7[4] < 1 || (puVar7[0xf] != 0)) ||
              (iVar2 = ResourceRecordAnswersQuestion(puVar5 + 1,puVar7), iVar2 == 0))))) {
        puVar7 = (undefined4 *)*puVar7;
      }
      puVar5[0x11] = puVar7;
      if (puVar7 == (undefined4 *)0x0) {
        *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x2d4) + -1;
      }
    }
  }
  if (*(undefined4 **)(param_1 + 0x2b4) == param_2) {
    *(undefined4 *)(param_1 + 0x2b4) = *param_2;
  }
  if (*(undefined4 **)(param_1 + 0x2b0) == param_2) {
    *(undefined4 *)(param_1 + 0x2b0) = *param_2;
  }
  if (*(undefined4 **)(param_1 + 700) == param_2) {
    *(undefined4 *)(param_1 + 700) = *param_2;
  }
  if (*(undefined4 **)(param_1 + 0x2c0) == param_2) {
    uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
    LogMsgWithLevel(0,
                    "mDNS_StopQuery_internal: Just deleted the current restart question: %##s (%s)",
                    param_2 + 0x55,uVar3);
    *(undefined4 *)(param_1 + 0x2c0) = *param_2;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x2c4);
  if (puVar5 == param_2) {
    if (mDNS_LoggingEnabled != 0) {
      uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
      LogMsgWithLevel(3,
                      "mDNS_StopQuery_internal: Just deleted the current Validation question: %##s (%s)"
                      ,param_2 + 0x55,uVar3);
    }
    *(undefined4 *)(param_1 + 0x2c4) = *puVar5;
  }
  *param_2 = 0;
  if (param_2[0x43] != 0) {
    DisposeTCPConn();
    param_2[0x43] = 0;
  }
  if (param_2[0x36] != 0) {
    mDNSPlatformUDPClose();
    param_2[0x36] = 0;
  }
  if ((*(short *)((int)param_2 + 0x152) != 0) && (*(char *)(param_2 + 0x96) != '\0')) {
    for (puVar5 = *(undefined4 **)(param_1 + 0x2ac); puVar5 != (undefined4 *)0x0;
        puVar5 = (undefined4 *)*puVar5) {
      if ((*(short *)((int)puVar5 + 0x152) != 0) && (*(char *)(puVar5 + 0x96) != '\0'))
      goto LAB_0042bd20;
    }
    if (*(int *)(param_1 + 0x29b0) == 0) {
      LogMsgWithLevel(0,"mDNS_StopQuery ERROR LLQNAT.clientCallback NULL");
    }
    else {
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(3,"Stopping LLQNAT");
      }
      mDNS_StopNATOperation_internal(param_1,param_1 + 0x2970);
      *(undefined4 *)(param_1 + 0x29b0) = 0;
    }
LAB_0042bd20:
    if (param_2[0x45] == 3) {
      param_2[0x46] = 0;
      sendLLQRefresh(param_1,param_2);
      if (param_2[0x43] != 0) {
        *(undefined4 *)(param_2[0x43] + 0x2304) = 0;
        param_2[0x43] = 0;
      }
    }
  }
  if (param_2[0x3c] != 0) {
    CancelGetZoneData(param_1);
    param_2[0x3c] = 0;
  }
  if ((*(char *)((int)param_2 + 0x266) != '\0') && (param_2[0x34] != 0)) {
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"mDNS_StopQuery_internal: freeing DNSSECAuthInfo %##s",param_2 + 0x55);
    }
    (*(code *)param_2[0x35])(param_1,param_2[0x34]);
    param_2[0x34] = 0;
  }
  if (param_2[0x11] != 0) {
    FreeAnonInfo();
    param_2[0x11] = 0;
  }
  return 0;
}

[ASK_GPT] c640c877227fcfc8
