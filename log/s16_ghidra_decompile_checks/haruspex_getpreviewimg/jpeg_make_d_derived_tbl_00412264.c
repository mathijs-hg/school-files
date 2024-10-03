
void jpeg_make_d_derived_tbl(int *param_1,int param_2,char *param_3,int *param_4)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined *puVar7;
  char *pcVar8;
  int *piVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  char local_540 [260];
  int local_43c [257];
  int *local_38;
  char *local_34;
  int local_30;
  uint local_2c;
  
  if ((char *)0x3 < param_3) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    *(char **)(*param_1 + 0x18) = param_3;
    local_34 = param_3;
    (**(code **)*param_1)();
    param_3 = local_34;
  }
  pcVar3 = param_3 + 0x2c;
  if (param_2 == 0) {
    pcVar3 = param_3 + 0x30;
  }
  iVar11 = param_1[(int)(pcVar3 + 1)];
  if (iVar11 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    *(char **)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (*param_4 == 0) {
    iVar4 = (**(code **)param_1[1])(param_1,1,0x590);
    *param_4 = iVar4;
  }
  iVar12 = *param_4;
  local_38 = (int *)local_540;
  iVar14 = 1;
  *(int *)(iVar12 + 0x8c) = iVar11;
  iVar4 = 8;
  uVar5 = 0xffffffff;
  iVar15 = 0;
  do {
    uVar16 = (uint)*(byte *)(iVar11 + iVar14);
    iVar13 = iVar15 + uVar16;
    if (0x100 < iVar13) {
      *(int *)(*param_1 + 0x14) = iVar4;
      local_30 = iVar4;
      local_2c = uVar5;
      (**(code **)*param_1)(param_1);
      uVar5 = local_2c;
      iVar4 = local_30;
    }
    pcVar3 = (char *)((int)local_38 + iVar15);
    while (uVar16 = uVar16 - 1, uVar16 != uVar5) {
      *pcVar3 = (char)iVar14;
      pcVar3 = pcVar3 + 1;
    }
    iVar14 = iVar14 + 1;
    pcVar3 = local_540;
    iVar15 = iVar13;
  } while (iVar14 != 0x11);
  iVar17 = 0;
  pcVar3[iVar13] = '\0';
  iVar15 = 0;
  iVar14 = 0;
  uVar5 = 1;
  iVar4 = (int)local_540[0];
  local_38 = local_43c;
  while( true ) {
    pcVar8 = pcVar3 + iVar14;
    if (*pcVar8 == '\0') break;
    piVar6 = local_38 + iVar14;
    while (cVar1 = *pcVar8, pcVar8 = pcVar8 + 1, (int)cVar1 == iVar17 + iVar4) {
      *piVar6 = iVar15;
      iVar14 = iVar14 + 1;
      iVar15 = iVar15 + 1;
      piVar6 = piVar6 + 1;
    }
    if ((int)(uVar5 << (iVar17 + iVar4 & 0x1fU)) <= iVar15) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      local_34 = pcVar3;
      local_30 = iVar4;
      local_2c = uVar5;
      (**(code **)*param_1)(param_1);
      uVar5 = local_2c;
      iVar4 = local_30;
      pcVar3 = local_34;
    }
    iVar15 = iVar15 << 1;
    iVar17 = iVar17 + 1;
  }
  iVar17 = 1;
  iVar14 = 0;
  iVar4 = iVar12;
  iVar15 = iVar11;
  do {
    if (*(char *)(iVar15 + 1) == '\0') {
      *(undefined4 *)(iVar4 + 4) = 0xffffffff;
    }
    else {
      *(int *)(iVar4 + 0x4c) = iVar14 - local_43c[iVar14];
      iVar14 = iVar14 + (uint)*(byte *)(iVar15 + 1);
      *(int *)(iVar4 + 4) = local_43c[iVar14 + -1];
    }
    iVar17 = iVar17 + 1;
    iVar15 = iVar15 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar17 != 0x11);
  *(undefined4 *)(iVar12 + 0x44) = 0xfffff;
[32m  memset((void *)(iVar12 + 0x90),0,0x400);[0m
  iVar4 = 1;
  iVar15 = 0;
  do {
    piVar6 = local_43c + iVar15;
    puVar7 = (undefined *)(iVar11 + iVar15 + 0x11);
    for (iVar14 = 1; iVar14 <= (int)(uint)*(byte *)(iVar11 + iVar4); iVar14 = iVar14 + 1) {
      iVar17 = *piVar6 << (8U - iVar4 & 0x1f);
      puVar10 = (undefined *)(iVar12 + iVar17 + 0x490);
      piVar9 = (int *)(iVar12 + (iVar17 + 0x24) * 4);
      for (iVar17 = 1 << (8U - iVar4 & 0x1f); 0 < iVar17; iVar17 = iVar17 + -1) {
        *piVar9 = iVar4;
        piVar9 = piVar9 + 1;
        *puVar10 = *puVar7;
        puVar10 = puVar10 + 1;
      }
      iVar15 = iVar15 + 1;
      piVar6 = piVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 9);
  iVar4 = 0;
  if (param_2 != 0) {
    while( true ) {
      bVar2 = iVar13 <= iVar4;
      iVar15 = iVar11 + iVar4;
      iVar4 = iVar4 + 1;
      if (bVar2) break;
      if (0xf < *(byte *)(iVar15 + 0x11)) {
        *(undefined4 *)(*param_1 + 0x14) = 8;
        (**(code **)*param_1)(param_1);
      }
    }
  }
  return;
}

[ASK_GPT] 07f057371ce8539c
