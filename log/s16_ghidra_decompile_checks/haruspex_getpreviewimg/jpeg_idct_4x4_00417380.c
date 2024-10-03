
void jpeg_idct_4x4(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  int *piVar7;
  undefined uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_b8 [8];
  int local_98 [8];
  int local_78 [8];
  int local_58 [10];
  int local_30;
  
  iVar4 = 8;
  piVar5 = *(int **)(param_2 + 0x50);
  local_30 = *(int *)(param_1 + 0x144) + 0x80;
  piVar7 = local_b8;
  while( true ) {
    if (iVar4 != 4) {
      if ((((param_3[8] == 0) && (param_3[0x10] == 0)) && (param_3[0x18] == 0)) &&
         (((param_3[0x28] == 0 && (param_3[0x30] == 0)) && (param_3[0x38] == 0)))) {
        iVar9 = (int)*param_3 * *piVar5 * 4;
        piVar7[0x18] = iVar9;
        *piVar7 = iVar9;
        piVar7[8] = iVar9;
        piVar7[0x10] = iVar9;
      }
      else {
[32m        sVar1 = param_3[0x38];[0m
        iVar9 = piVar5[0x38];
[32m        sVar2 = param_3[0x28];[0m
        iVar10 = piVar5[0x28];
        iVar13 = piVar5[0x18];
[32m        sVar3 = param_3[0x18];[0m
        iVar15 = (int)param_3[8] * piVar5[8];
        iVar12 = (int)*param_3 * *piVar5 * 0x4000;
        iVar11 = piVar5[0x30] * -0x187e * (int)param_3[0x30] +
                 piVar5[0x10] * 0x3b21 * (int)param_3[0x10];
        iVar14 = (iVar12 - iVar11) + 0x800;
        iVar12 = iVar11 + iVar12 + 0x800;
        iVar11 = sVar2 * iVar10 * -0x133e + sVar1 * iVar9 * -0x1050 + iVar15 * 0x5203 +
                 sVar3 * iVar13 * 0x1ccd;
        piVar7[0x18] = iVar12 - iVar11 >> 0xc;
        *piVar7 = iVar12 + iVar11 >> 0xc;
        iVar9 = sVar2 * iVar10 * 0x2e75 + sVar1 * iVar9 * -0x6c2 + iVar15 * 0x21f9 +
                sVar3 * iVar13 * -0x4587;
        piVar7[8] = iVar14 + iVar9 >> 0xc;
        piVar7[0x10] = iVar14 - iVar9 >> 0xc;
      }
    }
    iVar4 = iVar4 + -1;
    param_3 = param_3 + 1;
    if (iVar4 == 0) break;
    piVar5 = piVar5 + 1;
    piVar7 = piVar7 + 1;
  }
  piVar5 = local_98;
  do {
    iVar4 = piVar5[-7];
    puVar6 = (undefined *)(*param_4 + param_5);
    if (((iVar4 == 0) && (piVar5[-6] == 0)) &&
       ((piVar5[-5] == 0 && (((piVar5[-3] == 0 && (piVar5[-2] == 0)) && (piVar5[-1] == 0)))))) {
      uVar8 = *(undefined *)(local_30 + (piVar5[-8] + 0x10 >> 5 & 0x3ffU));
      puVar6[3] = uVar8;
      *puVar6 = uVar8;
      puVar6[1] = uVar8;
    }
    else {
      iVar9 = piVar5[-2] * -0x187e + piVar5[-6] * 0x3b21;
      iVar12 = iVar9 + piVar5[-8] * 0x4000 + 0x40000;
      iVar9 = (piVar5[-8] * 0x4000 - iVar9) + 0x40000;
      iVar10 = piVar5[-3] * -0x133e + piVar5[-1] * -0x1050 + iVar4 * 0x5203 + piVar5[-5] * 0x1ccd;
      iVar4 = piVar5[-3] * 0x2e75 + piVar5[-1] * -0x6c2 + iVar4 * 0x21f9 + piVar5[-5] * -0x4587;
      *puVar6 = *(undefined *)(local_30 + (iVar12 + iVar10 >> 0x13 & 0x3ffU));
      puVar6[3] = *(undefined *)(local_30 + (iVar12 - iVar10 >> 0x13 & 0x3ffU));
      puVar6[1] = *(undefined *)(local_30 + (iVar9 + iVar4 >> 0x13 & 0x3ffU));
      uVar8 = *(undefined *)(local_30 + (iVar9 - iVar4 >> 0x13 & 0x3ffU));
    }
    puVar6[2] = uVar8;
    piVar5 = piVar5 + 8;
    param_4 = param_4 + 1;
  } while (piVar5 != (int *)&stack0xffffffe8);
  return;
}

[ASK_GPT] fc208910af137d91
