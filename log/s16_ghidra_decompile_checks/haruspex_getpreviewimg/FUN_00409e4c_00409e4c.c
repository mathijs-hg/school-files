
void FUN_00409e4c(int *param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  
  iVar5 = param_1[0x5b];
  if (param_2 == 0) {
    *(code **)(iVar5 + 4) = FUN_00409264;
    pcVar1 = (code *)&LAB_0040973c;
  }
  else {
    *(code **)(iVar5 + 4) = FUN_00409820;
    pcVar1 = FUN_0040a424;
  }
  *(code **)(iVar5 + 8) = pcVar1;
  piVar7 = param_1;
  iVar3 = iVar5;
  for (iVar8 = 0; iVar8 < param_1[0x3d]; iVar8 = iVar8 + 1) {
    uVar6 = *(uint *)(piVar7[0x3e] + 0x18);
    uVar9 = *(uint *)(piVar7[0x3e] + 0x14);
    if (param_2 == 0) {
      jpeg_make_c_derived_tbl(param_1,1,uVar9,iVar5 + (uVar9 + 10) * 4 + 4);
      jpeg_make_c_derived_tbl(param_1,0,uVar6,iVar5 + (uVar6 + 0xe) * 4 + 4);
    }
    else {
      if (3 < uVar9) {
        *(undefined4 *)(*param_1 + 0x14) = 0x32;
        *(uint *)(*param_1 + 0x18) = uVar9;
        (**(code **)*param_1)(param_1);
      }
      if (3 < uVar6) {
        *(undefined4 *)(*param_1 + 0x14) = 0x32;
        *(uint *)(*param_1 + 0x18) = uVar6;
        (**(code **)*param_1)(param_1);
      }
      iVar4 = iVar5 + (uVar9 + 0x12) * 4;
      if (*(int *)(iVar4 + 4) == 0) {
        uVar2 = (**(code **)param_1[1])(param_1,1,0x404);
        *(undefined4 *)(iVar4 + 4) = uVar2;
      }
      iVar4 = iVar5 + (uVar6 + 0x16) * 4;
[32m      memset(*(void **)(iVar5 + (uVar9 + 0x12) * 4 + 4),0,0x404);[0m
      if (*(int *)(iVar4 + 4) == 0) {
        uVar2 = (**(code **)param_1[1])(param_1,1,0x404);
        *(undefined4 *)(iVar4 + 4) = uVar2;
      }
[32m      memset(*(void **)(iVar5 + (uVar6 + 0x16) * 4 + 4),0,0x404);[0m
    }
    *(undefined4 *)(iVar3 + 0x14) = 0;
    piVar7 = piVar7 + 1;
    iVar3 = iVar3 + 4;
  }
  *(undefined4 *)(iVar5 + 0xc) = 0;
  *(undefined4 *)(iVar5 + 0x10) = 0;
  iVar3 = param_1[0x32];
  *(undefined4 *)(iVar5 + 0x28) = 0;
  *(int *)(iVar5 + 0x24) = iVar3;
  return;
}

[ASK_GPT] 8b43512213e32dd2
