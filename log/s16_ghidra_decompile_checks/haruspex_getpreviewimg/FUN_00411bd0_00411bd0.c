
undefined4 FUN_00411bd0(int param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined auStack_68 [16];
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  uint local_4c;
  int local_48;
  undefined4 *local_40;
  int local_3c;
  undefined2 *local_38;
  undefined *local_34;
  undefined4 *local_30;
  
  iVar9 = *(int *)(param_1 + 0x1bc);
  if ((*(int *)(param_1 + 0x114) != 0) && (*(int *)(iVar9 + 0x24) == 0)) {
    iVar2 = *(int *)(iVar9 + 0x10);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    *(int *)(*(int *)(param_1 + 0x1b8) + 0x18) =
         *(int *)(*(int *)(param_1 + 0x1b8) + 0x18) + (iVar2 >> 3);
    *(undefined4 *)(iVar9 + 0x10) = 0;
    local_30 = param_2;
    iVar2 = (**(code **)(*(int *)(param_1 + 0x1b8) + 8))();
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = 0;
    iVar2 = iVar9;
    while( true ) {
      bVar1 = *(int *)(param_1 + 0x148) <= iVar3;
      iVar3 = iVar3 + 1;
      if (bVar1) break;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      iVar2 = iVar2 + 4;
    }
    *(undefined4 *)(iVar9 + 0x24) = *(undefined4 *)(param_1 + 0x114);
    param_2 = local_30;
    if (*(int *)(param_1 + 0x1a0) == 0) {
      *(undefined4 *)(iVar9 + 8) = 0;
    }
  }
  local_34 = auStack_68;
  if (*(int *)(iVar9 + 8) == 0) {
    local_58 = **(undefined4 **)(param_1 + 0x18);
    local_3c = 0;
    local_54 = (*(undefined4 **)(param_1 + 0x18))[1];
    local_30 = *(undefined4 **)(iVar9 + 0xc);
    uVar8 = *(uint *)(iVar9 + 0x10);
    local_48 = param_1;
    local_40 = param_2;
[32m[32m    memcpy(local_34,(void *)(iVar9 + 0x14),0x10);[0m[0m
    iVar2 = (int)local_30;
    iVar3 = iVar9;
    iVar13 = param_1;
    for (; local_3c < *(int *)(param_1 + 0x164); local_3c = local_3c + 1) {
      local_38 = (undefined2 *)*local_40;
      iVar11 = *(int *)(iVar3 + 0x48);
      iVar10 = *(int *)(iVar3 + 0x70);
      if ((int)uVar8 < 8) {
        iVar2 = jpeg_fill_bit_buffer(&local_58,iVar2,uVar8,0);
        if (iVar2 == 0) {
          return 0;
        }
        uVar4 = 1;
        iVar2 = local_50;
        uVar8 = local_4c;
        if (7 < (int)local_4c) goto LAB_00411d70;
LAB_00411da0:
        uVar7 = jpeg_huff_decode(&local_58,iVar2,uVar8,iVar11,uVar4);
        iVar2 = local_50;
        uVar8 = local_4c;
        if ((int)uVar7 < 0) {
          return 0;
        }
      }
      else {
LAB_00411d70:
        uVar7 = iVar2 >> (uVar8 - 8 & 0x1f) & 0xff;
        iVar6 = *(int *)(iVar11 + (uVar7 + 0x24) * 4);
        uVar4 = 9;
        if (iVar6 == 0) goto LAB_00411da0;
        uVar7 = (uint)*(byte *)(iVar11 + uVar7 + 0x490);
        uVar8 = uVar8 - iVar6;
      }
      if (uVar7 != 0) {
        if (((int)uVar8 < (int)uVar7) &&
           (iVar11 = jpeg_fill_bit_buffer(&local_58,iVar2,uVar8,uVar7), iVar2 = local_50,
           uVar8 = local_4c, iVar11 == 0)) {
          return 0;
        }
        iVar11 = uVar7 * 4;
        uVar8 = uVar8 - uVar7;
        uVar7 = iVar2 >> (uVar8 & 0x1f) & (1 << (uVar7 & 0x1f)) - 1U;
        if ((int)uVar7 < *(int *)(&DAT_0041dfe0 + iVar11)) {
          uVar7 = uVar7 + *(int *)(&DAT_0041e020 + iVar11);
        }
      }
      if (*(int *)(iVar3 + 0x98) != 0) {
        iVar11 = uVar7 + *(int *)(local_34 + *(int *)(iVar13 + 0x168) * 4);
        *(int *)(local_34 + *(int *)(iVar13 + 0x168) * 4) = iVar11;
        *local_38 = (short)iVar11;
      }
      iVar11 = 1;
      if (*(int *)(iVar3 + 0xc0) == 0) {
        do {
          if ((int)uVar8 < 8) {
            iVar2 = jpeg_fill_bit_buffer(&local_58,iVar2,uVar8,0);
            if (iVar2 == 0) {
              return 0;
            }
            uVar4 = 1;
            iVar2 = local_50;
            uVar8 = local_4c;
            if (7 < (int)local_4c) goto LAB_00412064;
LAB_00412094:
            uVar7 = jpeg_huff_decode(&local_58,iVar2,uVar8,iVar10,uVar4);
            iVar2 = local_50;
            uVar8 = local_4c;
            if ((int)uVar7 < 0) {
              return 0;
            }
          }
          else {
LAB_00412064:
            uVar7 = iVar2 >> (uVar8 - 8 & 0x1f) & 0xff;
            iVar6 = *(int *)(iVar10 + (uVar7 + 0x24) * 4);
            uVar4 = 9;
            if (iVar6 == 0) goto LAB_00412094;
            uVar7 = (uint)*(byte *)(iVar10 + uVar7 + 0x490);
            uVar8 = uVar8 - iVar6;
          }
          uVar12 = uVar7 & 0xf;
          iVar6 = (int)uVar7 >> 4;
          if (uVar12 == 0) {
            iVar11 = iVar11 + 0xf;
            if (iVar6 != 0xf) break;
          }
          else {
            if (((int)uVar8 < (int)uVar12) &&
               (local_30 = (undefined4 *)iVar6,
               iVar5 = jpeg_fill_bit_buffer(&local_58,iVar2,uVar8,uVar12), iVar6 = (int)local_30,
               iVar2 = local_50, uVar8 = local_4c, iVar5 == 0)) {
              return 0;
            }
            iVar11 = iVar6 + iVar11;
            uVar8 = uVar8 - uVar12;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < 0x40);
      }
      else {
        iVar11 = 1;
        do {
          if ((int)uVar8 < 8) {
            iVar2 = jpeg_fill_bit_buffer(&local_58,iVar2,uVar8,0);
            if (iVar2 == 0) {
              return 0;
            }
            uVar4 = 1;
            iVar2 = local_50;
            uVar8 = local_4c;
            if (7 < (int)local_4c) goto LAB_00411edc;
LAB_00411f0c:
            uVar7 = jpeg_huff_decode(&local_58,iVar2,uVar8,iVar10,uVar4);
            iVar2 = local_50;
            uVar8 = local_4c;
            if ((int)uVar7 < 0) {
              return 0;
            }
          }
          else {
LAB_00411edc:
            uVar7 = iVar2 >> (uVar8 - 8 & 0x1f) & 0xff;
            iVar6 = *(int *)(iVar10 + (uVar7 + 0x24) * 4);
            uVar4 = 9;
            if (iVar6 == 0) goto LAB_00411f0c;
            uVar7 = (uint)*(byte *)(iVar10 + uVar7 + 0x490);
            uVar8 = uVar8 - iVar6;
          }
          uVar12 = uVar7 & 0xf;
          iVar6 = (int)uVar7 >> 4;
          if (uVar12 == 0) {
            iVar11 = iVar11 + 0xf;
            if (iVar6 != 0xf) break;
          }
          else {
            if (((int)uVar8 < (int)uVar12) &&
               (local_30 = (undefined4 *)iVar6,
               iVar5 = jpeg_fill_bit_buffer(&local_58,iVar2,uVar8,uVar12), iVar6 = (int)local_30,
               iVar2 = local_50, uVar8 = local_4c, iVar5 == 0)) {
              return 0;
            }
            uVar8 = uVar8 - uVar12;
            uVar7 = iVar2 >> (uVar8 & 0x1f) & (1 << uVar12) - 1U;
            if ((int)uVar7 < *(int *)(&DAT_0041dfe0 + uVar12 * 4)) {
              uVar7 = uVar7 + *(int *)(&DAT_0041e020 + uVar12 * 4);
            }
            iVar11 = iVar6 + iVar11;
            local_38[*(int *)(jpeg_natural_order + iVar11 * 4)] = (short)uVar7;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < 0x40);
      }
      iVar3 = iVar3 + 4;
      iVar13 = iVar13 + 4;
      local_40 = local_40 + 1;
    }
    **(undefined4 **)(param_1 + 0x18) = local_58;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = local_54;
    *(int *)(iVar9 + 0xc) = iVar2;
    *(uint *)(iVar9 + 0x10) = uVar8;
[32m[32m    memcpy((void *)(iVar9 + 0x14),auStack_68,0x10);[0m[0m
  }
  *(int *)(iVar9 + 0x24) = *(int *)(iVar9 + 0x24) + -1;
  return 1;
}

[ASK_GPT] 06feb428845f23ab
