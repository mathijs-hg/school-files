
undefined4 * FUN_004113e4(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  iVar3 = 2;
  pcVar10 = *(char **)(param_1 + 0x18);
  pcVar2 = pcVar10;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar3 = 1;
  }
  do {
    pcVar1 = pcVar2;
    pcVar2 = pcVar1 + -1;
  } while (pcVar1[-1] != '<');
  puVar4 = (undefined4 *)FUN_00410b58(pcVar1,0,pcVar10 + (-iVar3 - (int)pcVar1),&DAT_00416f8c,1);
  puVar12 = (undefined4 *)*puVar4;
  if (puVar12 != (undefined4 *)0x0) {
    puVar12 = (undefined4 *)puVar12[2];
  }
  puVar11 = (undefined4 *)0x0;
  for (; puVar12 != (undefined4 *)0x0; puVar12 = (undefined4 *)puVar12[2]) {
    if (puVar11 == (undefined4 *)0x0) {
[32m[32m[32m      puVar5 = (undefined4 *)malloc(0x1c);[0m[0m[0m
      puVar5[6] = 0;
    }
    else {
[32m[32m[32m      puVar5 = (undefined4 *)malloc(0x1c);[0m[0m[0m
      puVar5[6] = puVar11;
    }
    piVar6 = (int *)FUN_00410b58(*puVar12,0,puVar12[1],&DAT_00415af0,1);
    if (piVar6[2] == 1) {
      puVar5[2] = 0;
      puVar5[3] = 0;
      uVar8 = *puVar12;
      iVar3 = puVar12[1];
      iVar9 = 0;
    }
    else {
      puVar5[2] = *(undefined4 *)*piVar6;
      iVar3 = *(int *)(*piVar6 + 4);
      puVar5[3] = iVar3;
      iVar9 = iVar3 + 1;
      uVar8 = *puVar12;
      iVar3 = (puVar12[1] + -1) - iVar3;
    }
    piVar7 = (int *)FUN_00410b58(uVar8,iVar9,iVar3,&DAT_00416ce4,1);
    ILibDestructParserResults(piVar6);
    *puVar5 = *(undefined4 *)*piVar7;
    puVar5[1] = *(undefined4 *)(*piVar7 + 4);
    puVar5[4] = *(undefined4 *)piVar7[1];
    puVar5[5] = *(undefined4 *)(piVar7[1] + 4);
    ILibDestructParserResults(piVar7);
    puVar11 = puVar5;
  }
  ILibDestructParserResults(puVar4);
  return puVar11;
}

[ASK_GPT] fe040f1843fdc2c2
