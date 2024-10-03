
undefined4 get_range_info(int param_1,char *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_4a8 [16];
  undefined4 *local_498;
  ushort local_494;
  undefined2 local_492;
  undefined4 local_488 [284];
  
  local_488[0] = 0;
[32m[32m[32m  strncpy(acStack_4a8,param_2,0x10);[0m[0m[0m
  local_494 = 0;
  local_492 = 0;
  local_498 = local_488;
  iVar1 = ioctl(param_1,0x8b0b,acStack_4a8);
  uVar2 = 0xffffffff;
  if (-1 < iVar1) {
[32m[32m    memcpy(param_3,local_488,0x238);[0m[0m
    if (local_494 < 300) {
      fprintf(stderr,"Warning : Device %s has been compiled with a different version\n",param_2);
      fprintf(stderr,"of Wireless Extension than ours (we are using version %d).\n",0x16);
      fputs("Some things may be broken...\n\n",stderr);
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (*(char *)((int)param_3 + 0x118) != '\x16') {
        fprintf(stderr,"Warning : Device %s has been compiled with version %d\n",param_2);
        fprintf(stderr,"of Wireless Extension, while we are using version %d.\n",0x16);
        fputs("Some things may be broken...\n\n",stderr);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

[ASK_GPT] 967fea207e90be9c
