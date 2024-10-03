
void FUN_0040b4e4(int *param_1,int param_2)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  
  iVar6 = param_1[0x5b];
  *(int **)(iVar6 + 0x20) = param_1;
  *(int *)(iVar6 + 0xc) = param_2;
  bVar1 = param_1[0x4f] == 0;
  if (param_1[0x51] == 0) {
    if (bVar1) {
      pcVar2 = FUN_0040aa58;
    }
    else {
      pcVar2 = FUN_0040ac60;
    }
  }
  else {
    if (!bVar1) {
      *(code **)(iVar6 + 4) = FUN_0040b034;
      if (*(int *)(iVar6 + 0x40) == 0) {
        uVar4 = (**(code **)param_1[1])(param_1,1,1000);
        *(undefined4 *)(iVar6 + 0x40) = uVar4;
      }
      goto LAB_0040b5ac;
    }
    pcVar2 = FUN_0040aef8;
  }
  *(code **)(iVar6 + 4) = pcVar2;
LAB_0040b5ac:
  if (param_2 == 0) {
    pcVar2 = FUN_0040b3c8;
  }
  else {
    pcVar2 = FUN_0040b73c;
  }
  *(code **)(iVar6 + 8) = pcVar2;
  iVar7 = 0;
  iVar5 = iVar6;
  piVar8 = param_1;
  do {
    if (param_1[0x3d] <= iVar7) {
      *(undefined4 *)(iVar6 + 0x38) = 0;
      *(undefined4 *)(iVar6 + 0x3c) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      iVar5 = param_1[0x32];
      *(undefined4 *)(iVar6 + 0x48) = 0;
      *(int *)(iVar6 + 0x44) = iVar5;
      return;
    }
    iVar3 = piVar8[0x3e];
    *(undefined4 *)(iVar5 + 0x24) = 0;
    if (bVar1) {
      if (param_1[0x51] == 0) {
        uVar9 = *(uint *)(iVar3 + 0x14);
        goto LAB_0040b60c;
      }
    }
    else {
      uVar9 = *(uint *)(iVar3 + 0x18);
      *(uint *)(iVar6 + 0x34) = uVar9;
LAB_0040b60c:
      if (param_2 == 0) {
        jpeg_make_c_derived_tbl(param_1,bVar1,uVar9,iVar6 + (uVar9 + 0x12) * 4 + 4);
      }
      else {
        if (3 < uVar9) {
          *(undefined4 *)(*param_1 + 0x14) = 0x32;
          *(uint *)(*param_1 + 0x18) = uVar9;
          (**(code **)*param_1)(param_1);
        }
        iVar3 = iVar6 + (uVar9 + 0x16) * 4;
        if (*(int *)(iVar3 + 4) == 0) {
          uVar4 = (**(code **)param_1[1])(param_1,1,0x404);
          *(undefined4 *)(iVar3 + 4) = uVar4;
        }
[32m        memset(*(void **)(iVar6 + (uVar9 + 0x16) * 4 + 4),0,0x404);[0m
      }
    }
    iVar7 = iVar7 + 1;
    piVar8 = piVar8 + 1;
    iVar5 = iVar5 + 4;
  } while( true );
}

[ASK_GPT] 14f9ea564cd4e870
