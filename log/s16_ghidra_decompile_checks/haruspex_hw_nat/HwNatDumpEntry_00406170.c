
undefined4
HwNatDumpEntry(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int __fd;
  undefined4 uVar1;
  int iVar2;
  undefined auStack_14 [8];
  undefined2 local_c;
  
  local_c = param_1;
[32m  __fd = open("/dev/hwnat0",0,param_3,param_4,&_gp);[0m
  if (__fd < 0) {
    printf("Open %s pseudo device failed\n","/dev/hwnat0");
    uVar1 = 1;
  }
  else {
    iVar2 = ioctl(__fd,3,auStack_14);
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

[ASK_GPT] 2843c3065533c1ac
