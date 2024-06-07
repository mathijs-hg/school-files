
undefined4
HwNatSetMaxEntryRateLimit
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int __fd;
  undefined4 uVar1;
  int iVar2;
  
[32m  __fd = open("/dev/hwnat0",0,param_3,param_4,&_gp);[0m
  if (__fd < 0) {
    printf("Open %s pseudo device failed\n","/dev/hwnat0");
    uVar1 = 1;
  }
  else {
    iVar2 = ioctl(__fd,0x17,param_1);
    if (iVar2 < 0) {
      puts("HW_NAT_API: ioctl error");
      close(__fd);
      uVar1 = 1;
    }
    else {
      close(__fd);
      uVar1 = 0;
    }
  }
  return uVar1;
}

[ASK_GPT] 19ef758bf88d2c33
