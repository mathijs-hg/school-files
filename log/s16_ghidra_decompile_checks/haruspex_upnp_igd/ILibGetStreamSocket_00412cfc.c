
/* WARNING: Removing unreachable block (ram,0x00412d98) */

uint ILibGetStreamSocket(undefined4 param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_30;
  sockaddr local_2c;
  
  local_30 = 1;
  param_2 = param_2 & 0xffff;
  local_2c._0_4_ = 0x20000;
  local_2c.sa_data._6_4_ = 0;
  local_2c.sa_data._10_4_ = 0;
  local_2c.sa_data._2_4_ = param_1;
  iVar1 = socket(2,2,0);
  *param_3 = iVar1;
  if (param_2 == 0) {
    do {
[32m[32m      uVar2 = rand();[0m[0m
      param_2 = (uVar2 & 0xffff) % 15000 - 0x3cb0 & 0xffff;
      local_2c._0_4_ = local_2c._0_4_ & 0xffff0000 | param_2;
      iVar1 = bind(*param_3,&local_2c,0x10);
    } while (iVar1 < 0);
  }
  else {
    local_2c._0_4_ = local_2c._0_4_ & 0xffff0000 | param_2;
    setsockopt(iVar1,0xffff,4,&local_30,4);
    iVar1 = bind(*param_3,&local_2c,0x10);
    if (iVar1 < 0) {
      param_2 = 0;
    }
  }
  return param_2;
}

[ASK_GPT] e4ecd12dd3d3fcb9
