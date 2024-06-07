
undefined4 print_iface_version_info(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_4c4 [16];
  undefined *local_4b4;
  ushort local_4b0;
  undefined2 local_4ae;
  undefined auStack_4a4 [280];
  byte bStack_38c;
  byte bStack_38b;
  
[32m[32m[32m  strncpy(acStack_4c4,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b01,acStack_4c4);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
[32m    memset(auStack_4a4,0,0x498);[0m
    local_4b4 = auStack_4a4;
    local_4b0 = 0x498;
    local_4ae = 0;
[32m[32m[32m    strncpy(acStack_4c4,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8b0b,acStack_4c4);
    if (iVar1 < 0) {
      fprintf(stderr,"%-8.16s  Driver has no Wireless Extension version information.\n\n",param_2);
      uVar2 = 0;
    }
    else {
      if (local_4b0 < 300) {
        fprintf(stderr,"%-8.16s  Wireless Extension version too old.\n\n",param_2);
      }
      else {
        printf("%-8.16s  Recommend Wireless Extension v%d or later,\n",param_2,(uint)bStack_38b);
        printf("          Currently compiled with Wireless Extension v%d.\n\n",(uint)bStack_38c);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

[ASK_GPT] e5827b41429db4fa
