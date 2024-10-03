
undefined4 mDNS_StopNATOperation_internal(int param_1,undefined4 *param_2)

{
  char cVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar7 = *(undefined4 **)(param_1 + 0x29b8);
  puVar6 = (undefined4 *)(param_1 + 0x29b8);
  while( true ) {
    puVar5 = puVar7;
    if (puVar5 == (undefined4 *)0x0) {
      LogMsgWithLevel(0,"mDNS_StopNATOperation_internal: NATTraversalInfo %p not found in list",
                      param_2);
      return 0xfffefffb;
    }
    if (puVar5 == param_2) break;
    puVar7 = (undefined4 *)*puVar5;
    puVar6 = puVar5;
  }
  *puVar6 = *param_2;
  if (mDNS_LoggingEnabled != 0) {
    LogMsgWithLevel(3,"mDNS_StopNATOperation_internal %p %d %d %d %d",param_2,
                    *(undefined *)(param_2 + 0xd),*(undefined2 *)((int)param_2 + 0x36),
                    *(undefined2 *)(param_2 + 0xe),param_2[0xf]);
  }
  if (*(undefined4 **)(param_1 + 0x29bc) == param_2) {
    *(undefined4 *)(param_1 + 0x29bc) = *param_2;
  }
  bVar4 = true;
  puVar7 = *(undefined4 **)(param_1 + 0x29b8);
  do {
    if (puVar7 == (undefined4 *)0x0) {
      if (param_2[1] != 0) {
        if (!bVar4) {
          return 0;
        }
        param_2[0xf] = 0;
        *(undefined2 *)(param_2 + 0xe) = 0;
        param_2[2] = 0;
        *(undefined *)(param_2 + 6) = 0;
        param_2[9] = 0;
        FUN_0040efd0(param_1,param_2,param_2[5] != 1);
      }
      return 0;
    }
[32m    cVar1 = *(char *)(param_2 + 0xd);[0m
    if (cVar1 == '\0') {
      bVar3 = true;
      if ((*(char *)(puVar7 + 0xd) != '\0') && (bVar3 = false, *(char *)(puVar7 + 0xd) == '\x02')) {
[32m        sVar2 = *(short *)((int)puVar7 + 0x36);[0m
        goto LAB_0040fa48;
      }
    }
    else {
      bVar3 = true;
      if ((((param_2[0xd] & 0xff00ffff) != (puVar7[0xd] & 0xff00ffff)) &&
          (bVar3 = false, *(char *)(puVar7 + 0xd) == '\0')) && (bVar3 = false, cVar1 == '\x02')) {
[32m        sVar2 = *(short *)((int)param_2 + 0x36);[0m
LAB_0040fa48:
        bVar3 = sVar2 == 9;
      }
    }
    if ((bVar3) && (bVar4 = false, mDNS_LoggingEnabled != 0)) {
      LogMsgWithLevel(3,
                      "Warning: Removed port mapping request %p Prot %d Int %d TTL %d duplicates existing port mapping request %p Prot %d Int %d TTL %d"
                      ,param_2,cVar1,*(undefined2 *)((int)param_2 + 0x36),param_2[0xf],puVar7,
                      *(undefined *)(puVar7 + 0xd),*(undefined2 *)((int)puVar7 + 0x36),puVar7[0xf]);
      bVar4 = false;
    }
    puVar7 = (undefined4 *)*puVar7;
  } while( true );
}

[ASK_GPT] 4b08c21e1e1d0090
