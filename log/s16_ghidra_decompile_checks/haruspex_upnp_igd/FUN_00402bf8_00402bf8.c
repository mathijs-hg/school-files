
int FUN_00402bf8(int param_1,int param_2,int *param_3)

{
  size_t __n;
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  iVar2 = *param_3;
  local_20[0] = iVar2;
  __n = strlen(DeviceType);
[32m  iVar1 = strncmp(*(char **)(param_1 + 4),DeviceType,__n);[0m
  if ((iVar1 == 0) && (local_20[0] = iVar2 + 1, local_20[0] == param_2)) {
    *param_3 = local_20[0];
  }
  else {
    iVar1 = *(int *)(param_1 + 0x50);
    param_1 = 0;
    while ((iVar1 != 0 && (param_1 = FUN_00402bf8(iVar1,param_2,local_20), param_1 == 0))) {
      iVar1 = *(int *)(iVar1 + 0x58);
    }
    *param_3 = local_20[0];
  }
  return param_1;
}

[ASK_GPT] 6416bbbf9b5ffbed
