
undefined4 check_addr_type(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_30 [16];
  short local_20;
  
[32m[32m[32m  strncpy(acStack_30,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8915,acStack_30);
  if ((iVar1 < 0) || (local_20 != 2)) {
    fprintf(stderr,"Interface %s doesn\'t support IP addresses\n",param_2);
    uVar2 = 0xffffffff;
  }
  else {
[32m[32m[32m    strncpy(acStack_30,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8927,acStack_30);
    if ((iVar1 < 0) || (uVar2 = 0, local_20 != 1)) {
      fprintf(stderr,"Interface %s doesn\'t support MAC addresses\n",param_2);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

[ASK_GPT] c8512b1a2107a792
