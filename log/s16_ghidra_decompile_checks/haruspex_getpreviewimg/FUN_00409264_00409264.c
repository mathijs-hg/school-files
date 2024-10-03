
undefined4 FUN_00409264(int *param_1,short **param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  short *psVar5;
  int iVar6;
  undefined4 uVar7;
  char **ppcVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  char *local_68 [4];
  undefined4 local_58 [4];
  int *local_48;
  int *local_40;
  int *local_3c;
  int local_38;
  int local_34;
  short *local_30;
  
  iVar6 = param_1[0x5b];
  local_68[0] = *(char **)param_1[6];
  local_68[1] = ((char **)param_1[6])[1];
[32m[32m  memcpy(local_68 + 2,(void *)(iVar6 + 0xc),0x18);[0m[0m
  local_48 = param_1;
  if ((param_1[0x32] != 0) && (*(int *)(iVar6 + 0x24) == 0)) {
    uVar7 = *(undefined4 *)(iVar6 + 0x28);
    iVar3 = FUN_004090f0(local_68,0x7f,7);
    if (iVar3 == 0) {
      return 0;
    }
    local_68[2] = (char *)0x0;
    local_68[3] = (char *)0x0;
    pcVar4 = local_68[0] + 1;
    *local_68[0] = -1;
    local_68[1] = local_68[1] + -1;
    local_68[0] = pcVar4;
    if (local_68[1] == (char *)0x0) {
      ppcVar8 = (char **)local_48[6];
      iVar3 = (*(code *)ppcVar8[3])();
      if (iVar3 == 0) {
        return 0;
      }
      local_68[0] = *ppcVar8;
      local_68[1] = ppcVar8[1];
    }
    *local_68[0] = (char)uVar7 + -0x30;
    local_68[0] = local_68[0] + 1;
    local_68[1] = local_68[1] + -1;
    if (local_68[1] == (char *)0x0) {
      ppcVar8 = (char **)local_48[6];
      iVar3 = (*(code *)ppcVar8[3])();
      if (iVar3 == 0) {
        return 0;
      }
      local_68[0] = *ppcVar8;
      local_68[1] = ppcVar8[1];
    }
    piVar2 = local_48;
    puVar11 = local_58;
    iVar3 = 0;
    while (bVar1 = iVar3 < piVar2[0x3d], iVar3 = iVar3 + 1, bVar1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
  }
  local_34 = 0;
  local_3c = param_1;
  do {
    if (param_1[0x44] <= local_34) {
      *(char **)param_1[6] = local_68[0];
      *(char **)(param_1[6] + 4) = local_68[1];
[32m[32m      memcpy((void *)(iVar6 + 0xc),local_68 + 2,0x18);[0m[0m
      if (param_1[0x32] != 0) {
        if (*(int *)(iVar6 + 0x24) == 0) {
          *(int *)(iVar6 + 0x24) = param_1[0x32];
          *(uint *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x28) + 1U & 7;
        }
        *(int *)(iVar6 + 0x24) = *(int *)(iVar6 + 0x24) + -1;
      }
      return 1;
    }
    local_38 = local_3c[0x45];
    local_30 = *param_2;
    iVar10 = (int)**param_2 - (int)local_68[local_38 + 4];
    iVar12 = *(int *)(iVar6 + (*(int *)(param_1[local_38 + 0x3e] + 0x14) + 10) * 4 + 4);
    puVar11 = *(undefined4 **)(iVar6 + (*(int *)(param_1[local_38 + 0x3e] + 0x18) + 0xe) * 4 + 4);
    iVar3 = iVar10;
    if (iVar10 < 0) {
      iVar3 = -iVar10;
      iVar10 = iVar10 + -1;
    }
    iVar9 = 0;
    while (bVar1 = iVar3 != 0, iVar3 = iVar3 >> 1, bVar1) {
      iVar9 = iVar9 + 1;
    }
    if (0xb < iVar9) {
      *(undefined4 *)(*local_48 + 0x14) = 6;
      (**(code **)*local_48)();
    }
    iVar3 = FUN_004090f0(local_68,*(undefined4 *)(iVar12 + iVar9 * 4),
                         (int)*(char *)(iVar12 + iVar9 + 0x400));
    if (iVar3 == 0) {
      return 0;
    }
    if ((iVar9 != 0) && (iVar3 = FUN_004090f0(local_68,iVar10,iVar9), iVar3 == 0)) {
      return 0;
    }
    iVar3 = 0;
    local_40 = (int *)(jpeg_natural_order + 4);
    do {
      iVar10 = (int)local_30[*local_40];
      if (iVar10 == 0) {
        iVar3 = iVar3 + 1;
      }
      else {
        while (0xf < iVar3) {
          iVar3 = iVar3 + -0x10;
          iVar12 = FUN_004090f0(local_68,puVar11[0xf0],(int)*(char *)(puVar11 + 0x13c));
          if (iVar12 == 0) {
            return 0;
          }
        }
        iVar12 = iVar10;
        if (iVar10 < 0) {
          iVar12 = -iVar10;
          iVar10 = iVar10 + -1;
        }
        iVar9 = 1;
        do {
          iVar13 = iVar9;
          iVar12 = iVar12 >> 1;
          iVar9 = iVar13 + 1;
        } while (iVar12 != 0);
        if (10 < iVar13) {
          *(undefined4 *)(*local_48 + 0x14) = 6;
          (**(code **)*local_48)();
        }
        iVar3 = iVar13 + iVar3 * 0x10;
        iVar3 = FUN_004090f0(local_68,puVar11[iVar3],(int)*(char *)((int)puVar11 + iVar3 + 0x400));
        if (iVar3 == 0) {
          return 0;
        }
        iVar10 = FUN_004090f0(local_68,iVar10,iVar13);
        iVar3 = 0;
        if (iVar10 == 0) {
          return 0;
        }
      }
      local_40 = local_40 + 1;
    } while (local_40 != (int *)(jpeg_natural_order + 0x100));
    if ((iVar3 != 0) &&
       (iVar3 = FUN_004090f0(local_68,*puVar11,(int)*(char *)(puVar11 + 0x100)), iVar3 == 0)) {
      return 0;
    }
    psVar5 = *param_2;
    param_2 = param_2 + 1;
    local_34 = local_34 + 1;
    local_3c = local_3c + 1;
    local_68[local_38 + 4] = (char *)(int)*psVar5;
  } while( true );
}

[ASK_GPT] f1d953e78064a48f
