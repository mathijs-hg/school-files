
void jinit_c_prep_controller(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  code **ppcVar4;
  undefined4 *puVar5;
  undefined4 *__src;
  undefined4 *puVar6;
  code *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 *__dest;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  
  if (param_2 != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)();
  }
  ppcVar4 = (code **)(**(code **)param_1[1])(param_1,1,0x40);
  param_1[0x55] = (int)ppcVar4;
  *ppcVar4 = FUN_00406740;
  if (*(int *)(param_1[0x59] + 8) == 0) {
    ppcVar4[1] = FUN_00406a60;
    iVar12 = param_1[0x11];
    iVar13 = 0;
    while( true ) {
      bVar3 = param_1[0xf] <= iVar13;
      iVar13 = iVar13 + 1;
      if (bVar3) break;
      piVar1 = (int *)(iVar12 + 0x1c);
      piVar2 = (int *)(iVar12 + 8);
      iVar12 = iVar12 + 0x54;
      if (*piVar2 == 0) {
        trap(0x1c00);
      }
      pcVar7 = (code *)(**(code **)(param_1[1] + 8))
                                 (param_1,1,(param_1[0x3a] * 8 * *piVar1) / *piVar2,param_1[0x3b]);
      ppcVar4[2] = pcVar7;
      ppcVar4 = ppcVar4 + 1;
    }
  }
  else {
    ppcVar4[1] = FUN_00406d2c;
    iVar12 = param_1[0x3b];
    iVar15 = param_1[0x55];
    puVar5 = (undefined4 *)(**(code **)param_1[1])(param_1,1,iVar12 * param_1[0xf] * 0x14);
    __dest = puVar5 + iVar12;
    iVar13 = param_1[0x11];
    puVar14 = puVar5 + iVar12 * 4;
    for (iVar16 = 0; iVar16 < param_1[0xf]; iVar16 = iVar16 + 1) {
      if (*(int *)(iVar13 + 8) == 0) {
        trap(0x1c00);
      }
      __src = (undefined4 *)
              (**(code **)(param_1[1] + 8))
                        (param_1,1,
                         (param_1[0x3a] * 8 * *(int *)(iVar13 + 0x1c)) / *(int *)(iVar13 + 8),
                         iVar12 * 3);
[32m      memcpy(__dest,__src,iVar12 * 0xc);[0m
      iVar8 = 0;
      puVar10 = __src + iVar12 * 2;
      puVar6 = puVar14;
      puVar9 = puVar5;
      while (bVar3 = iVar8 < iVar12, iVar8 = iVar8 + 1, bVar3) {
        uVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        *puVar9 = uVar11;
        puVar9 = puVar9 + 1;
        uVar11 = *__src;
        __src = __src + 1;
        *puVar6 = uVar11;
        puVar6 = puVar6 + 1;
      }
      *(undefined4 **)(iVar15 + 8) = __dest;
      puVar5 = puVar5 + iVar12 * 5;
      iVar13 = iVar13 + 0x54;
      __dest = __dest + iVar12 * 5;
      iVar15 = iVar15 + 4;
      puVar14 = puVar14 + iVar12 * 5;
    }
  }
  return;
}

[ASK_GPT] 949356026a2b0bda
