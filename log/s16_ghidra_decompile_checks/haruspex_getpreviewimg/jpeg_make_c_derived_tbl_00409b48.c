
void jpeg_make_c_derived_tbl(int *param_1,int param_2,char *param_3,int *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  char local_540 [260];
  undefined4 local_43c [257];
  undefined4 *local_38;
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
  pcVar2 = param_3 + 0x16;
  if (param_2 == 0) {
    pcVar2 = param_3 + 0x1a;
  }
  iVar9 = param_1[(int)pcVar2];
  if (iVar9 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    *(char **)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (*param_4 == 0) {
    iVar3 = (**(code **)param_1[1])(param_1,1,0x500);
    *param_4 = iVar3;
  }
  local_38 = (undefined4 *)local_540;
  iVar10 = 1;
  iVar7 = *param_4;
  iVar3 = 8;
  uVar4 = 0xffffffff;
  iVar11 = 0;
  do {
    uVar12 = (uint)*(byte *)(iVar9 + iVar10);
    iVar8 = iVar11 + uVar12;
    if (0x100 < iVar8) {
      *(int *)(*param_1 + 0x14) = iVar3;
      local_30 = iVar3;
      local_2c = uVar4;
      (**(code **)*param_1)(param_1);
      uVar4 = local_2c;
      iVar3 = local_30;
    }
    pcVar2 = (char *)((int)local_38 + iVar11);
    while (uVar12 = uVar12 - 1, uVar12 != uVar4) {
      *pcVar2 = (char)iVar10;
      pcVar2 = pcVar2 + 1;
    }
    iVar10 = iVar10 + 1;
    pcVar2 = local_540;
    iVar11 = iVar8;
  } while (iVar10 != 0x11);
  iVar13 = 0;
  pcVar2[iVar8] = '\0';
  iVar10 = 0;
  iVar11 = 0;
  uVar4 = 1;
  iVar3 = (int)local_540[0];
  local_38 = local_43c;
  while( true ) {
    pcVar6 = pcVar2 + iVar10;
    if (*pcVar6 == '\0') break;
    piVar5 = local_38 + iVar10;
    while (cVar1 = *pcVar6, pcVar6 = pcVar6 + 1, (int)cVar1 == iVar13 + iVar3) {
      *piVar5 = iVar11;
      iVar10 = iVar10 + 1;
      iVar11 = iVar11 + 1;
      piVar5 = piVar5 + 1;
    }
    if ((int)(uVar4 << (iVar13 + iVar3 & 0x1fU)) <= iVar11) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      local_34 = pcVar2;
      local_30 = iVar3;
      local_2c = uVar4;
      (**(code **)*param_1)(param_1);
      uVar4 = local_2c;
      iVar3 = local_30;
      pcVar2 = local_34;
    }
    iVar11 = iVar11 << 1;
    iVar13 = iVar13 + 1;
  }
[32m  memset((void *)(iVar7 + 0x400),0,0x100);[0m
  uVar4 = 0xff;
  puVar14 = local_43c;
  if (param_2 != 0) {
    uVar4 = 0xf;
  }
  local_2c = 8;
  for (iVar3 = 0; iVar3 < iVar8; iVar3 = iVar3 + 1) {
    uVar12 = (uint)*(byte *)(iVar9 + iVar3 + 0x11);
    if ((uVar4 < uVar12) || (*(char *)(iVar7 + uVar12 + 0x400) != '\0')) {
      *(uint *)(*param_1 + 0x14) = local_2c;
      (**(code **)*param_1)(param_1);
    }
    *(undefined4 *)(iVar7 + uVar12 * 4) = *puVar14;
    puVar14 = puVar14 + 1;
    *(char *)(iVar7 + uVar12 + 0x400) = local_540[iVar3];
  }
  return;
}

[ASK_GPT] aeec09e20360e388
