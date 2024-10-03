
undefined4 FUN_00414d64(int param_1,int *param_2)

{
  int iVar1;
  short **ppsVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined auStack_138 [2];
  short local_136;
  short local_134;
  short local_128;
  short local_126;
  short local_118;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int *local_a0;
  int local_9c;
  int local_98;
  uint local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined *local_70;
  int local_6c;
  code *local_68;
  uint local_64;
  int local_60;
  int local_5c;
  uint local_58;
  int local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  short *local_30;
  uint local_2c;
  
  local_90 = *(int *)(param_1 + 0x1ac);
  local_64 = *(int *)(param_1 + 0x140) - 1;
  while( true ) {
    if (((*(int *)(param_1 + 0x98) < *(int *)(param_1 + 0x90)) ||
        ((*(code ***)(param_1 + 0x1b4))[5] != (code *)0x0)) ||
       ((*(int *)(param_1 + 0x90) == *(int *)(param_1 + 0x98) &&
        ((uint)(*(int *)(param_1 + 400) == 0) + *(int *)(param_1 + 0x9c) < *(uint *)(param_1 + 0x94)
        )))) break;
    local_50 = param_2;
    iVar10 = (***(code ***)(param_1 + 0x1b4))(param_1);
    param_2 = local_50;
    if (iVar10 == 0) {
      return 0;
    }
  }
  local_70 = auStack_138;
  iVar9 = *(int *)(param_1 + 0xd8);
  local_a4 = local_90;
  local_a0 = param_2;
  for (iVar10 = 0; uVar3 = 4, iVar10 < *(int *)(param_1 + 0x24); iVar10 = iVar10 + 1) {
    if (*(int *)(iVar9 + 0x30) != 0) {
      uVar6 = *(uint *)(param_1 + 0x9c);
      uVar4 = *(uint *)(iVar9 + 0xc);
      if (uVar6 < local_64) {
        local_9c = 0;
        uVar15 = uVar4 << 1;
      }
      else {
        uVar15 = *(uint *)(iVar9 + 0x20) % uVar4;
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        if (uVar15 == 0) {
          local_9c = 1;
          uVar15 = uVar4;
        }
        else {
          local_9c = 1;
          uVar4 = uVar15;
        }
      }
      if (uVar6 == 0) {
        local_98 = 1;
        ppsVar2 = (short **)
                  (**(code **)(*(int *)(param_1 + 4) + 0x20))
                            (param_1,*(undefined4 *)(local_a4 + 0x48),0,uVar15,0);
      }
      else {
        local_98 = 0;
        iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                          (param_1,*(undefined4 *)(local_a4 + 0x48),
                           *(int *)(iVar9 + 0xc) * (uVar6 - 1),uVar15 + *(int *)(iVar9 + 0xc),0);
        ppsVar2 = (short **)(iVar1 + *(int *)(iVar9 + 0xc) * 4);
      }
      local_5c = uVar4 - 1;
      puVar7 = *(ushort **)(iVar9 + 0x4c);
      uVar6 = (uint)*puVar7;
      local_60 = uVar6 * 5;
      local_b8 = (uint)puVar7[2] << 8;
      local_8c = (uint)puVar7[2] << 7;
      local_a8 = (uint)puVar7[1] << 8;
      local_78 = (uint)puVar7[1] << 7;
      local_ac = (uint)puVar7[8] << 8;
      local_7c = (uint)puVar7[8] << 7;
      local_74 = uVar6 * 0x24;
      local_b0 = (uint)puVar7[0x10] << 8;
      local_b4 = (uint)puVar7[9] << 8;
      local_84 = (uint)puVar7[0x10] << 7;
      local_88 = (uint)puVar7[9] << 7;
      local_68 = *(code **)(*(int *)(param_1 + 0x1c0) + iVar10 * 4 + 4);
      iVar13 = *(int *)(local_90 + 0x70) + iVar10 * 0x18;
      local_80 = uVar6 * 9;
      iVar1 = *local_a0;
      local_6c = param_1;
      local_58 = uVar4;
      local_54 = iVar10;
      for (iVar14 = 0; param_1 = local_6c, iVar10 = local_54, iVar14 < (int)local_58;
          iVar14 = iVar14 + 1) {
        psVar8 = *ppsVar2;
        if ((local_98 == 0) || (local_30 = psVar8, iVar14 != 0)) {
          local_30 = ppsVar2[-1];
        }
        if ((local_9c == 0) || (psVar12 = psVar8, iVar14 != local_5c)) {
          psVar12 = ppsVar2[1];
        }
        local_38 = 0;
        local_3c = (int)*local_30;
        local_2c = 0;
        local_40 = (int)*psVar8;
        local_94 = *(int *)(iVar9 + 0x1c) - 1;
        local_44 = (int *)(int)*psVar12;
        local_34 = iVar1;
        iVar10 = local_40;
        iVar1 = local_3c;
        piVar11 = local_44;
        while( true ) {
          local_50 = local_44;
          local_4c = local_40;
          local_48 = local_3c;
          local_44 = piVar11;
          local_40 = iVar10;
          local_3c = iVar1;
          jcopy_block_row(psVar8,local_70,1);
          if (local_2c < local_94) {
            iVar1 = (int)local_30[0x40];
            iVar10 = (int)psVar8[0x40];
            piVar11 = (int *)(int)psVar12[0x40];
          }
          uVar4 = *(uint *)(iVar13 + 4);
          if ((uVar4 != 0) && (local_136 == 0)) {
            iVar16 = (local_4c - iVar10) * local_74;
            if (iVar16 < 0) {
              iVar16 = (local_78 - iVar16) / local_a8;
              if (local_a8 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
              iVar16 = -iVar16;
            }
            else {
              iVar16 = (iVar16 + local_78) / local_a8;
              if (local_a8 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
            }
[32m            local_136 = (short)iVar16;[0m
          }
          uVar4 = *(uint *)(iVar13 + 8);
          if ((uVar4 != 0) && (local_128 == 0)) {
            iVar16 = (local_3c - (int)local_44) * local_74;
            if (iVar16 < 0) {
              iVar16 = (local_7c - iVar16) / local_ac;
              if (local_ac == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
              iVar16 = -iVar16;
            }
            else {
              iVar16 = (iVar16 + local_7c) / local_ac;
              if (local_ac == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
            }
[32m            local_128 = (short)iVar16;[0m
          }
          uVar4 = *(uint *)(iVar13 + 0xc);
          if ((uVar4 != 0) && (local_118 == 0)) {
            iVar16 = ((int)local_44 + local_40 * -2 + local_3c) * local_80;
            if (iVar16 < 0) {
              iVar16 = (local_84 - iVar16) / local_b0;
              if (local_b0 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
              iVar16 = -iVar16;
            }
            else {
              iVar16 = (iVar16 + local_84) / local_b0;
              if (local_b0 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
            }
[32m            local_118 = (short)iVar16;[0m
          }
          uVar4 = *(uint *)(iVar13 + 0x10);
          if ((uVar4 != 0) && (local_126 == 0)) {
            iVar16 = ((int)piVar11 + ((local_48 - (int)local_50) - iVar1)) * local_60;
            if (iVar16 < 0) {
              iVar16 = (local_88 - iVar16) / local_b4;
              if (local_b4 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
              iVar16 = -iVar16;
            }
            else {
              iVar16 = (iVar16 + local_88) / local_b4;
              if (local_b4 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
            }
[32m            local_126 = (short)iVar16;[0m
          }
          uVar4 = *(uint *)(iVar13 + 0x14);
          if ((uVar4 != 0) && (local_134 == 0)) {
            iVar16 = (local_40 * -2 + local_4c + iVar10) * local_80;
            if (iVar16 < 0) {
              iVar16 = (local_8c - iVar16) / local_b8;
              if (local_b8 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
              iVar16 = -iVar16;
            }
            else {
              iVar16 = (iVar16 + local_8c) / local_b8;
              if (local_b8 == 0) {
                trap(0x1c00);
              }
              if ((0 < (int)uVar4) && (iVar5 = 1 << (uVar4 & 0x1f), iVar5 <= iVar16)) {
                iVar16 = iVar5 + -1;
              }
            }
[32m            local_134 = (short)iVar16;[0m
          }
          local_2c = local_2c + 1;
          (*local_68)(local_6c,iVar9,local_70,local_34,local_38);
          if (local_94 < local_2c) break;
          local_38 = local_38 + *(int *)(iVar9 + 0x24);
          psVar8 = psVar8 + 0x40;
          local_30 = local_30 + 0x40;
          psVar12 = psVar12 + 0x40;
        }
        ppsVar2 = ppsVar2 + 1;
        iVar1 = local_34 + *(int *)(iVar9 + 0x24) * 4;
      }
    }
    iVar9 = iVar9 + 0x54;
    local_a0 = local_a0 + 1;
    local_a4 = local_a4 + 4;
  }
  uVar4 = *(int *)(param_1 + 0x9c) + 1;
  *(uint *)(param_1 + 0x9c) = uVar4;
  if (uVar4 < *(uint *)(param_1 + 0x140)) {
    uVar3 = 3;
  }
  return uVar3;
}

[ASK_GPT] 9cd3576709c9a842
