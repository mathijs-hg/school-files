
void jpeg_CreateDecompress(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  param_1[1] = 0;
  if (param_2 != 0x3e) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    *(undefined4 *)(*param_1 + 0x18) = 0x3e;
    *(int *)(*param_1 + 0x1c) = param_2;
    (**(code **)*param_1)();
  }
  if (param_3 != 0x1d0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(undefined4 *)(*param_1 + 0x18) = 0x1d0;
    *(int *)(*param_1 + 0x1c) = param_3;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = *param_1;
  iVar1 = param_1[3];
[32m  memset(param_1,0,0x1d0);[0m
  param_1[4] = 1;
  *param_1 = iVar2;
  param_1[3] = iVar1;
  jinit_memory_mgr(param_1);
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x31] = 0;
  param_1[0x2e] = 0;
  param_1[0x32] = 0;
  param_1[0x2f] = 0;
  param_1[0x33] = 0;
  param_1[0x30] = 0;
  param_1[0x34] = 0;
  param_1[0x4c] = 0;
  jinit_marker_reader(param_1);
  jinit_input_controller(param_1);
  param_1[5] = 200;
  return;
}

[ASK_GPT] 9aa0ed5936c408ec
