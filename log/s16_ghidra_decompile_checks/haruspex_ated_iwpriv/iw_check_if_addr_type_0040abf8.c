
undefined4 iw_check_if_addr_type(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_28 [16];
  short local_18;
  
[32m[32m[32m  strncpy(acStack_28,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8915,acStack_28);
  if ((iVar1 < 0) || (local_18 != 2)) {
    fprintf(stderr,"Interface %s doesn\'t support IP addresses\n",param_2);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] 2ec43d466233d4ff
