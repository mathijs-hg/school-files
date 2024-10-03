
uint FUN_00406210(int param_1)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined auStack_2050 [4128];
  undefined *local_1030;
  int local_1028 [1024];
  
  local_1030 = &_gp;
  uVar5 = 0;
[32m[32m  iVar2 = read(param_1,local_1028,0x1000);[0m[0m
  piVar3 = local_1028;
  puVar7 = local_1030;
  while( true ) {
    for (; (piVar4 = (int *)((int)local_1028 + iVar2), piVar4 < piVar3 + 4 ||
           (piVar4 < (int *)((int)piVar3 + *piVar3))); iVar2 = iVar2 + iVar6) {
      if (piVar3 <= local_1028) {
        return uVar5;
      }
      iVar6 = (int)local_1028 + (iVar2 - (int)piVar3);
      (**(code **)(puVar7 + -0x7ad8))(local_1028,piVar3,iVar6);
      iVar2 = (**(code **)(local_1030 + -0x7d44))(param_1,(int)local_1028 + iVar6,0x1000 - iVar6);
      piVar3 = local_1028;
      puVar7 = local_1030;
    }
[32m    sVar1 = *(short *)(piVar3 + 1);[0m
    if ((sVar1 == 0x12) || ((sVar1 == 0x10 || ((ushort)(sVar1 - 0x14U) < 2)))) {
      uVar5 = uVar5 | 1 << (piVar3[5] & 0x1fU);
    }
    if ((*(ushort *)((int)piVar3 + 6) & 2) == 0) break;
    if (sVar1 == 3) {
      return uVar5;
    }
    piVar3 = (int *)((int)piVar3 + (*piVar3 + 3U & 0xfffffffc));
  }
  return uVar5;
}

[ASK_GPT] 85596649950ba609
