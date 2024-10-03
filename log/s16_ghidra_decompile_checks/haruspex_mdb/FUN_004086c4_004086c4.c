
int FUN_004086c4(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = &_gp;
  iVar1 = (int)*param_1;
  if (iVar1 != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      if (iVar2 < param_2) {
LAB_004087b8:
        *(char *)(param_3 + iVar3) = (char)iVar1;
        iVar3 = iVar3 + 1;
        *(undefined *)(param_3 + iVar3) = 0;
      }
      else {
        if (0x40 < iVar1) {
          if ((0x5a < iVar1) && ((iVar1 < 0x61 || (iVar1 - 0x7bU < 4)))) goto LAB_00408798;
          goto LAB_004087b8;
        }
        if (iVar1 < 0x3a) {
          if (iVar1 == 0x20) {
            iVar1 = 0x2b;
          }
          else if ((0x1f < iVar1) && (iVar1 < 0x30)) goto LAB_00408798;
          goto LAB_004087b8;
        }
LAB_00408798:
[32m        iVar1 = sprintf((char *)(param_3 + iVar3),"%c%02X",0x25,iVar1,puVar4);[0m
        iVar3 = iVar3 + iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = (int)param_1[iVar2];
    } while (iVar1 != 0);
  }
  return param_3;
}

[ASK_GPT] 06f23f1ba34a57a5
