
undefined4 TFStats_get(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int __fd;
  undefined4 uVar1;
  int iVar2;
  
[32m  __fd = open("/dev/hwnat0",0,param_3,param_4,&_gp);[0m
  if (__fd < 0) {
    printf("Open %s pseudo device failed\n","/dev/hwnat0");
    free(param_1);
    uVar1 = 1;
  }
  else {
    iVar2 = ioctl(__fd,0x2c,param_1);
    if (iVar2 < 0) {
      puts("HW_NAT_API: ioctl error");
      close(__fd);
      free(param_1);
      uVar1 = 1;
    }
    else {
      close(__fd);
      free(param_1);
      puts("get one client hwnat traffic success!");
      uVar1 = 0;
    }
  }
  return uVar1;
}

[ASK_GPT] 6b443801a4864ac5
