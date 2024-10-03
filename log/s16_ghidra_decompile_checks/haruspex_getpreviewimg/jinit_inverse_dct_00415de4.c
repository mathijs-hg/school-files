
void jinit_inverse_dct(int param_1)

{
  bool bVar1;
  code **ppcVar2;
  void *__s;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  ppcVar2 = (code **)(***(code ***)(param_1 + 4))(param_1,1,0x54);
  *(code ***)(param_1 + 0x1c0) = ppcVar2;
  *ppcVar2 = FUN_00415aa0;
  iVar3 = *(int *)(param_1 + 0xd8);
  while( true ) {
    bVar1 = *(int *)(param_1 + 0x24) <= iVar4;
    iVar4 = iVar4 + 1;
    if (bVar1) break;
    __s = (void *)(***(code ***)(param_1 + 4))(param_1,1,0x100);
    *(void **)(iVar3 + 0x50) = __s;
    iVar3 = iVar3 + 0x54;
[32m    memset(__s,0,0x100);[0m
    ppcVar2[0xb] = (code *)0xffffffff;
    ppcVar2 = ppcVar2 + 1;
  }
  return;
}

[ASK_GPT] 5077381a17ffc755
