
int FUN_00402b64(int param_1)

{
  int iVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  for (iVar3 = *(int *)(param_1 + 0x50); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x58)) {
    iVar1 = FUN_00402b64(iVar3);
    iVar2 = iVar2 + iVar1;
  }
  __n = strlen(DeviceType);
[32m  iVar3 = strncmp(*(char **)(param_1 + 4),DeviceType,__n);[0m
  return iVar2 + (uint)(iVar3 == 0);
}

[ASK_GPT] ed75295ae250a405
