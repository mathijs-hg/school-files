
void FUN_00429428(int param_1,undefined4 param_2,int param_3,int param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = param_1;
  do {
    for (puVar6 = *(undefined4 **)(iVar5 + 0x2e0); puVar6 != (undefined4 *)0x0;
        puVar6 = (undefined4 *)*puVar6) {
      for (puVar4 = (undefined4 *)puVar6[2]; puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
[32m        sVar1 = *(short *)((int)puVar4 + 6);[0m
        if ((((sVar1 == 2) || (sVar1 == 5)) || (sVar1 == 0xc)) || (sVar1 == 0x27)) {
          iVar3 = puVar4[9] + 4;
LAB_00429524:
          if ((iVar3 != 0) && (puVar4[6] == param_3)) {
            iVar3 = SameDomainName(iVar3,param_2);
            if (iVar3 != 0) {
              if (mDNS_LoggingEnabled != 0) {
                uVar2 = GetRRDisplayString_rdb(puVar4 + 1,puVar4[9] + 4,param_1 + 0x2f);
                LogMsgWithLevel(3,"ReconfirmAntecedents: Reconfirming (depth=%d) %s",param_4,uVar2);
              }
              FUN_00429190(param_1,puVar4,mDNSPlatformOneSecond * 5);
              if (param_4 < 5) {
                FUN_00429428(param_1,puVar4[8],puVar4[5],param_4 + 1);
              }
            }
          }
        }
        else {
          if (((sVar1 == 0xf) || (sVar1 == 0x12)) || ((sVar1 == 0x15 || (sVar1 == 0x24)))) {
            iVar3 = puVar4[9] + 6;
            goto LAB_00429524;
          }
          if (sVar1 == 0x21) {
            iVar3 = puVar4[9] + 10;
            goto LAB_00429524;
          }
        }
      }
    }
    iVar5 = iVar5 + 4;
    if (iVar5 == param_1 + 0x7cc) {
      return;
    }
  } while( true );
}

[ASK_GPT] ee4e56b1b995ca00
