
uint FUN_00405c6c(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  char acStack_30 [16];
  undefined4 local_20;
  ushort local_1c;
  undefined2 local_1a;
  
  puVar3 = &_gp;
[32m[32m[32m  strncpy(acStack_30,param_2,0x10);[0m[0m[0m
  local_1c = 0;
  local_1a = 0;
  local_20 = param_3;
  iVar1 = ioctl(param_1,0x8b0d,acStack_30,param_4,puVar3);
  uVar2 = 0xffffffff;
  if (-1 < iVar1) {
    uVar2 = (uint)local_1c;
  }
  return uVar2;
}

[ASK_GPT] 81d36c7e475b58cf
