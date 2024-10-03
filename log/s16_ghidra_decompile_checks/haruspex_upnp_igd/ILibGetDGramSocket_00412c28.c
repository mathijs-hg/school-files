
/* WARNING: Removing unreachable block (ram,0x00412cb4) */

uint ILibGetDGramSocket(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  sockaddr local_28;
  
  local_28._0_4_ = 0x20000;
  local_28.sa_data._6_4_ = 0;
  local_28.sa_data._10_4_ = 0;
  local_28.sa_data._2_4_ = param_1;
  iVar1 = socket(2,1,0);
  *param_2 = iVar1;
  do {
[32m[32m    uVar2 = rand();[0m[0m
    uVar2 = (uVar2 & 0xffff) % 15000 - 0x3cb0 & 0xffff;
    local_28._0_4_ = local_28._0_4_ & 0xffff0000 | uVar2;
    iVar1 = bind(*param_2,&local_28,0x10);
  } while (iVar1 < 0);
  return uVar2;
}

[ASK_GPT] d4507fb7ceee6aaf
