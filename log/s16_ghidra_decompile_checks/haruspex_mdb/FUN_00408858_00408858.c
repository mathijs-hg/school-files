
void FUN_00408858(int *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  void *pvVar3;
  int iVar4;
  
  sVar1 = strlen(param_2);
  sVar2 = strlen(param_3);
  iVar4 = *param_1;
[32m[32m[32m  pvVar3 = malloc(sVar1 * 3 + 1);[0m[0m[0m
  param_1[iVar4 + 1] = (int)pvVar3;
  iVar4 = *param_1;
[32m[32m[32m  pvVar3 = malloc(sVar2 * 3 + 1);[0m[0m[0m
  param_1[iVar4 + 0x81] = (int)pvVar3;
  FUN_004086c4(param_2,0,param_1[*param_1 + 1]);
  FUN_004086c4(param_3,0,param_1[*param_1 + 0x81]);
  *param_1 = *param_1 + 1;
  return;
}

[ASK_GPT] f8ce9674328e4ea5
