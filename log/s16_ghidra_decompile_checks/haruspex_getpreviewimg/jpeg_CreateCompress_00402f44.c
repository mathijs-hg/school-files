
void jpeg_CreateCompress(int *param_1,int param_2,int param_3)

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
  if (param_3 != 0x178) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(undefined4 *)(*param_1 + 0x18) = 0x178;
    *(int *)(*param_1 + 0x1c) = param_3;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = *param_1;
  iVar1 = param_1[3];
[32m  memset(param_1,0,0x178);[0m
  *param_1 = iVar2;
  param_1[3] = iVar1;
  param_1[4] = 0;
  jinit_memory_mgr(param_1);
  param_1[5] = 100;
  param_1[2] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0x3ff00000;
  param_1[6] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x1a] = 0;
  param_1[0x17] = 0;
  param_1[0x1b] = 0;
  param_1[0x18] = 0;
  param_1[0x1c] = 0;
  param_1[0x19] = 0;
  param_1[0x1d] = 0;
  param_1[0x5c] = 0;
  return;
}

[ASK_GPT] cbd706183003f016
