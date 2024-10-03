
undefined4 FUN_00413630(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  uint local_54;
  int local_50;
  undefined auStack_4c [4];
  int aiStack_48 [4];
  undefined2 *local_38;
  uint local_34;
  int local_30;
  
  local_34 = *(uint *)(param_1 + 0x19c);
  iVar8 = *(int *)(param_1 + 0x1bc);
  if (((*(int *)(param_1 + 0x114) != 0) && (*(int *)(iVar8 + 0x28) == 0)) &&
     (iVar3 = FUN_00412840(), iVar3 == 0)) {
    return 0;
  }
  if (*(int *)(iVar8 + 8) == 0) {
    local_60 = **(undefined4 **)(param_1 + 0x18);
    local_5c = (*(undefined4 **)(param_1 + 0x18))[1];
    local_30 = *(int *)(iVar8 + 0xc);
    uVar7 = *(uint *)(iVar8 + 0x10);
    local_50 = param_1;
[32m[32m    memcpy(auStack_4c,(void *)(iVar8 + 0x14),0x14);[0m[0m
    iVar3 = local_30;
    iVar11 = param_1;
    for (iVar10 = 0; iVar10 < *(int *)(param_1 + 0x164); iVar10 = iVar10 + 1) {
      iVar12 = *(int *)(iVar11 + 0x168);
      local_38 = (undefined2 *)*param_2;
      iVar9 = *(int *)(iVar8 + (*(int *)(*(int *)(param_1 + (iVar12 + 0x52) * 4 + 4) + 0x14) + 10) *
                               4 + 4);
      if ((int)uVar7 < 8) {
        iVar3 = jpeg_fill_bit_buffer(&local_60,iVar3,uVar7,0);
        if (iVar3 == 0) {
          return 0;
        }
        uVar4 = 1;
        iVar3 = local_58;
        uVar7 = local_54;
        if (7 < (int)local_54) goto LAB_00413784;
LAB_004137b4:
        uVar6 = jpeg_huff_decode(&local_60,iVar3,uVar7,iVar9,uVar4);
        iVar3 = local_58;
        uVar7 = local_54;
        if ((int)uVar6 < 0) {
          return 0;
        }
      }
      else {
LAB_00413784:
        uVar6 = iVar3 >> (uVar7 - 8 & 0x1f) & 0xff;
        iVar5 = *(int *)(iVar9 + (uVar6 + 0x24) * 4);
        uVar4 = 9;
        if (iVar5 == 0) goto LAB_004137b4;
        uVar6 = (uint)*(byte *)(iVar9 + uVar6 + 0x490);
        uVar7 = uVar7 - iVar5;
      }
      if (uVar6 != 0) {
        if (((int)uVar7 < (int)uVar6) &&
           (iVar9 = jpeg_fill_bit_buffer(&local_60,iVar3,uVar7,uVar6), iVar3 = local_58,
           uVar7 = local_54, iVar9 == 0)) {
          return 0;
        }
        iVar9 = uVar6 * 4;
        uVar7 = uVar7 - uVar6;
        uVar6 = iVar3 >> (uVar7 & 0x1f) & (1 << (uVar6 & 0x1f)) - 1U;
        if ((int)uVar6 < *(int *)(&DAT_0041e060 + iVar9)) {
          uVar6 = uVar6 + *(int *)(&DAT_0041e0a0 + iVar9);
        }
      }
      puVar2 = local_38;
      param_2 = param_2 + 1;
      iVar9 = aiStack_48[iVar12];
      iVar11 = iVar11 + 4;
      uVar1 = local_34 & 0x1f;
      aiStack_48[iVar12] = uVar6 + iVar9;
      *puVar2 = (short)(uVar6 + iVar9 << uVar1);
    }
    **(undefined4 **)(param_1 + 0x18) = local_60;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = local_5c;
    *(int *)(iVar8 + 0xc) = iVar3;
    *(uint *)(iVar8 + 0x10) = uVar7;
[32m[32m    memcpy((void *)(iVar8 + 0x14),auStack_4c,0x14);[0m[0m
  }
  *(int *)(iVar8 + 0x28) = *(int *)(iVar8 + 0x28) + -1;
  return 1;
}

[ASK_GPT] 188583628f8fa513
