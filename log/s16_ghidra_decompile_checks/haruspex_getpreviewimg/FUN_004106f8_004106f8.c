
undefined4 FUN_004106f8(int *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  byte **ppbVar8;
  byte *pbVar9;
  byte *pbVar10;
  void **ppvVar11;
  undefined local_150;
  byte local_14f;
  byte local_14e;
  byte local_14d;
  byte local_14c;
  byte local_14b;
  byte local_14a;
  byte local_149;
  byte local_148;
  byte local_147;
  byte local_146;
  byte local_145;
  byte local_144;
  byte local_143;
  byte local_142;
  byte local_141;
  byte local_140;
  byte abStack_13f [3];
  byte local_13c [260];
  uint local_38;
  byte *local_34;
  byte *local_30;
  undefined *local_2c;
  
  ppbVar8 = (byte **)param_1[6];
  pbVar9 = ppbVar8[1];
  pbVar2 = *ppbVar8;
  if (pbVar9 == (byte *)0x0) {
    iVar3 = (*(code *)ppbVar8[3])();
    if (iVar3 == 0) {
      return 0;
    }
    pbVar2 = *ppbVar8;
    pbVar9 = ppbVar8[1];
  }
  pbVar9 = pbVar9 + -1;
  bVar1 = *pbVar2;
  pbVar2 = pbVar2 + 1;
  if (pbVar9 == (byte *)0x0) {
    iVar3 = (*(code *)ppbVar8[3])(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    pbVar2 = *ppbVar8;
    pbVar9 = ppbVar8[1];
  }
  local_30 = abStack_13f;
  pbVar9 = pbVar9 + -1;
  iVar3 = (uint)bVar1 * 0x100 + -2 + (uint)*pbVar2;
  local_34 = &local_14f;
  local_2c = &local_150;
  pbVar2 = pbVar2 + 1;
  do {
    if (iVar3 < 0x11) {
      if (iVar3 != 0) {
        *(undefined4 *)(*param_1 + 0x14) = 0xb;
        (**(code **)*param_1)(param_1);
      }
      ppbVar8[1] = pbVar9;
      *ppbVar8 = pbVar2;
      return 1;
    }
    if (pbVar9 == (byte *)0x0) {
      iVar4 = (*(code *)ppbVar8[3])(param_1);
      if (iVar4 == 0) {
        return 0;
      }
      pbVar2 = *ppbVar8;
      pbVar9 = ppbVar8[1];
    }
    pbVar10 = local_34;
    local_38 = (uint)*pbVar2;
    pbVar9 = pbVar9 + -1;
    pbVar2 = pbVar2 + 1;
    *(undefined4 *)(*param_1 + 0x14) = 0x50;
    *(uint *)(*param_1 + 0x18) = local_38;
    iVar4 = 0;
    (**(code **)(*param_1 + 4))(param_1,1);
    local_150 = 0;
    do {
      if (pbVar9 == (byte *)0x0) {
        iVar5 = (*(code *)ppbVar8[3])(param_1);
        if (iVar5 == 0) {
          return 0;
        }
        pbVar2 = *ppbVar8;
        pbVar9 = ppbVar8[1];
      }
      bVar1 = *pbVar2;
      pbVar9 = pbVar9 + -1;
      *pbVar10 = bVar1;
      iVar4 = iVar4 + (uint)bVar1;
      pbVar10 = pbVar10 + 1;
      pbVar2 = pbVar2 + 1;
    } while (pbVar10 != local_30);
    iVar5 = *param_1;
    *(uint *)(iVar5 + 0x18) = (uint)local_14f;
    *(uint *)(iVar5 + 0x1c) = (uint)local_14e;
    *(uint *)(iVar5 + 0x20) = (uint)local_14d;
    *(uint *)(iVar5 + 0x24) = (uint)local_14c;
    *(uint *)(iVar5 + 0x28) = (uint)local_14b;
    *(uint *)(iVar5 + 0x2c) = (uint)local_14a;
    *(uint *)(iVar5 + 0x30) = (uint)local_149;
    *(uint *)(iVar5 + 0x34) = (uint)local_148;
    *(undefined4 *)(*param_1 + 0x14) = 0x56;
    (**(code **)(*param_1 + 4))(param_1,2);
    iVar5 = *param_1;
    *(uint *)(iVar5 + 0x18) = (uint)local_147;
    *(uint *)(iVar5 + 0x1c) = (uint)local_146;
    *(uint *)(iVar5 + 0x20) = (uint)local_145;
    *(uint *)(iVar5 + 0x24) = (uint)local_144;
    *(uint *)(iVar5 + 0x28) = (uint)local_143;
    *(uint *)(iVar5 + 0x2c) = (uint)local_142;
    *(uint *)(iVar5 + 0x30) = (uint)local_141;
    *(uint *)(iVar5 + 0x34) = (uint)local_140;
    *(undefined4 *)(*param_1 + 0x14) = 0x56;
    (**(code **)(*param_1 + 4))(param_1,2);
    if ((0x100 < iVar4) || (iVar3 + -0x11 < iVar4)) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    for (iVar5 = 0; iVar5 < iVar4; iVar5 = iVar5 + 1) {
      if (pbVar9 == (byte *)0x0) {
        iVar6 = (*(code *)ppbVar8[3])(param_1);
        if (iVar6 == 0) {
          return 0;
        }
        pbVar2 = *ppbVar8;
        pbVar9 = ppbVar8[1];
      }
      bVar1 = *pbVar2;
      pbVar9 = pbVar9 + -1;
      pbVar2 = pbVar2 + 1;
      local_13c[iVar5] = bVar1;
    }
    if ((local_38 & 0x10) == 0) {
      iVar5 = local_38 + 0x2c;
    }
    else {
      iVar5 = local_38 + 0x20;
      local_38 = local_38 - 0x10;
    }
    ppvVar11 = (void **)(param_1 + iVar5 + 1);
    if (3 < local_38) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1e;
      *(uint *)(*param_1 + 0x18) = local_38;
      (**(code **)*param_1)(param_1);
    }
    if (*ppvVar11 == (void *)0x0) {
      pvVar7 = (void *)jpeg_alloc_huff_table(param_1);
      *ppvVar11 = pvVar7;
    }
    iVar3 = (iVar3 + -0x11) - iVar4;
[32m[32m    memcpy(*ppvVar11,local_2c,0x11);[0m[0m
[32m[32m    memcpy((void *)((int)*ppvVar11 + 0x11),local_13c,0x100);[0m[0m
  } while( true );
}

[ASK_GPT] 5466aa870f84df87
