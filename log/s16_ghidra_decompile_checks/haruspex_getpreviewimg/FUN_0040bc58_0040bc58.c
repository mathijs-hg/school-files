
void FUN_0040bc58(int param_1,int param_2,int param_3,short *param_4,int param_5,int param_6,
                 uint param_7)

{
  short **ppsVar1;
  int iVar2;
  byte *pbVar3;
  short *psVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  int iVar10;
  uint uVar11;
  int iVar12;
  code *pcVar13;
  short *local_130 [66];
  short sVar9;
  
  iVar12 = *(int *)(*(int *)(param_1 + 0x168) + (*(int *)(param_2 + 0x10) + 2) * 4 + 4);
  pcVar13 = *(code **)(*(int *)(param_1 + 0x168) + 8);
  for (uVar11 = 0; ppsVar1 = local_130, piVar5 = (int *)(param_3 + param_5 * 4), uVar11 < param_7;
      uVar11 = uVar11 + 1) {
    do {
      pbVar3 = (byte *)(*piVar5 + param_6);
      *ppsVar1 = (short *)(*pbVar3 - 0x80);
      ppsVar1[1] = (short *)(pbVar3[1] - 0x80);
      ppsVar1[2] = (short *)(pbVar3[2] - 0x80);
      ppsVar1[3] = (short *)(pbVar3[3] - 0x80);
      ppsVar1[4] = (short *)(pbVar3[4] - 0x80);
      ppsVar1[5] = (short *)(pbVar3[5] - 0x80);
      ppsVar1[6] = (short *)(pbVar3[6] - 0x80);
      ppsVar1[7] = (short *)(pbVar3[7] - 0x80);
      ppsVar1 = ppsVar1 + 8;
      piVar5 = piVar5 + 1;
    } while (ppsVar1 != local_130 + 0x40);
    local_130[64] = param_4;
    (*pcVar13)(local_130);
    iVar2 = 0;
    psVar4 = local_130[64];
    do {
      iVar7 = *(int *)(iVar12 + iVar2);
[32m      sVar9 = 0;[0m
[32m      sVar8 = 0;[0m
      iVar10 = *(int *)((int)local_130 + iVar2);
      iVar6 = (iVar7 >> 1) + iVar10;
      if (iVar10 < 0) {
        iVar10 = (iVar7 >> 1) - iVar10;
[32m        if ((iVar7 <= iVar10) && (sVar9 = (short)(iVar10 / iVar7), iVar7 == 0)) {[0m
          trap(0x1c00);
        }
        sVar8 = -sVar9;
      }
[32m      else if ((iVar7 <= iVar6) && (sVar8 = (short)(iVar6 / iVar7), iVar7 == 0)) {[0m
        trap(0x1c00);
      }
      iVar2 = iVar2 + 4;
      *psVar4 = sVar8;
      psVar4 = psVar4 + 1;
    } while (iVar2 != 0x100);
    param_6 = param_6 + 8;
    param_4 = local_130[64] + 0x40;
  }
  return;
}

[ASK_GPT] f4aba7dfd71b6433
