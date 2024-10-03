
void FUN_00404d40(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = &_gp;
  if (((param_1 != (char *)0x0) && (param_2 != 0)) && (iVar1 = (int)*param_1, iVar1 != 0)) {
    iVar2 = 0;
    do {
      if (iVar1 < 0x41) {
        if (0x39 < iVar1) goto LAB_00404e08;
        if (iVar1 == 0x20) {
          iVar1 = 0x2b;
        }
        else if ((0x1f < iVar1) && (iVar1 < 0x30)) goto LAB_00404e08;
LAB_00404e28:
        *(char *)(param_2 + iVar2) = (char)iVar1;
        iVar2 = iVar2 + 1;
        *(undefined *)(param_2 + iVar2) = 0;
      }
      else {
        if ((iVar1 < 0x5b) || ((0x60 < iVar1 && (3 < iVar1 - 0x7bU)))) goto LAB_00404e28;
LAB_00404e08:
[32m        iVar1 = sprintf((char *)(param_2 + iVar2),"%c%02X",0x25,iVar1,puVar3);[0m
        iVar2 = iVar2 + iVar1;
      }
      iVar1 = (int)param_1[1];
      param_1 = param_1 + 1;
    } while (iVar1 != 0);
  }
  return;
}

[ASK_GPT] a744f351d38634b7
