
void FUN_0040eb3c(int *param_1)

{
  bool bVar1;
  void *__dest;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (param_1[0x52] == 1) {
    iVar2 = param_1[0x53];
    param_1[0x57] = *(int *)(iVar2 + 0x1c);
    param_1[0x58] = *(int *)(iVar2 + 0x20);
    uVar3 = *(uint *)(iVar2 + 0xc);
    uVar6 = *(uint *)(iVar2 + 0x20) % uVar3;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    *(undefined4 *)(iVar2 + 0x34) = 1;
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar2 + 0x24);
    *(undefined4 *)(iVar2 + 0x38) = 1;
    *(undefined4 *)(iVar2 + 0x3c) = 1;
    *(undefined4 *)(iVar2 + 0x44) = 1;
    if (uVar6 != 0) {
      uVar3 = uVar6;
    }
    *(uint *)(iVar2 + 0x48) = uVar3;
    param_1[0x59] = 1;
    param_1[0x5a] = 0;
  }
  else {
    if (3 < param_1[0x52] - 1U) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1a;
      *(int *)(*param_1 + 0x18) = param_1[0x52];
      *(undefined4 *)(*param_1 + 0x1c) = 4;
      (**(code **)*param_1)();
    }
    iVar2 = jdiv_round_up(param_1[7],param_1[0x4d] << 3);
    param_1[0x57] = iVar2;
    iVar2 = jdiv_round_up(param_1[8],param_1[0x4e] << 3);
    param_1[0x58] = iVar2;
    param_1[0x59] = 0;
    piVar4 = param_1;
    for (iVar2 = 0; iVar2 < param_1[0x52]; iVar2 = iVar2 + 1) {
      iVar5 = piVar4[0x53];
      uVar6 = *(uint *)(iVar5 + 8);
      uVar3 = *(uint *)(iVar5 + 0xc);
      iVar9 = uVar3 * uVar6;
      *(uint *)(iVar5 + 0x34) = uVar6;
      *(uint *)(iVar5 + 0x38) = uVar3;
      uVar7 = *(uint *)(iVar5 + 0x1c) % uVar6;
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      *(int *)(iVar5 + 0x3c) = iVar9;
      uVar8 = *(uint *)(iVar5 + 0x20) % uVar3;
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      if (uVar8 != 0) {
        uVar3 = uVar8;
      }
      uVar8 = uVar6;
      if (uVar7 != 0) {
        uVar8 = uVar7;
      }
      *(uint *)(iVar5 + 0x48) = uVar3;
      *(uint *)(iVar5 + 0x44) = uVar8;
      *(uint *)(iVar5 + 0x40) = *(int *)(iVar5 + 0x24) * uVar6;
      if (10 < iVar9 + param_1[0x59]) {
        *(undefined4 *)(*param_1 + 0x14) = 0xd;
        (**(code **)*param_1)(param_1);
      }
      for (; 0 < iVar9; iVar9 = iVar9 + -1) {
        iVar5 = param_1[0x59];
        param_1[iVar5 + 0x5a] = iVar2;
        param_1[0x59] = iVar5 + 1;
      }
      piVar4 = piVar4 + 1;
    }
  }
  iVar2 = 0;
  piVar4 = param_1;
  while (bVar1 = iVar2 < param_1[0x52], iVar2 = iVar2 + 1, bVar1) {
    iVar5 = piVar4[0x53];
    piVar4 = piVar4 + 1;
    if (*(int *)(iVar5 + 0x4c) == 0) {
      uVar3 = *(uint *)(iVar5 + 0x10);
      if ((3 < uVar3) || (param_1[uVar3 + 0x29] == 0)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x34;
        *(uint *)(*param_1 + 0x18) = uVar3;
        (**(code **)*param_1)(param_1);
      }
      __dest = (void *)(**(code **)param_1[1])(param_1,1,0x84);
[32m[32m      memcpy(__dest,(void *)param_1[uVar3 + 0x29],0x84);[0m[0m
      *(void **)(iVar5 + 0x4c) = __dest;
    }
  }
  (**(code **)param_1[0x6f])(param_1);
  (**(code **)param_1[0x6b])(param_1);
  *(undefined4 *)param_1[0x6d] = *(undefined4 *)(param_1[0x6b] + 4);
  return;
}

[ASK_GPT] bf93fcc0b4b897e0
