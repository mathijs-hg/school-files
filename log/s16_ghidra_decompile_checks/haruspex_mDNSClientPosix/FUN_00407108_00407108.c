
void FUN_00407108(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = &_gp;
  iVar2 = 0;
  do {
    iVar1 = 0x10;
    if (param_1 < 0x11) {
      iVar1 = param_1;
    }
    if (iVar2 == 0) {
[32m      sprintf(param_2,"%x");[0m
    }
    else {
[32m[32m[32m      sprintf(param_2,"%s:%x",param_2,0xffff << (0x10U - iVar1 & 0x1f) & 0xffff,puVar3);[0m[0m[0m
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 - iVar1;
  } while (iVar2 != 8);
  return;
}

[ASK_GPT] c8fabc8e9f173220
