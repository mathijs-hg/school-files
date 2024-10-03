
undefined4
FUN_004018a4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int __fd;
  undefined4 uVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  
[32m  __fd = open("/dev/hwmon",2,param_3,param_4,&_gp);[0m
  if (__fd < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    local_18 = 0xb8003504;
    iVar2 = ioctl(__fd,0xc004480c,&local_18);
    if (iVar2 < 0) {
      close(__fd);
      uVar1 = 0xffffffff;
    }
    else {
      *param_1 = local_14;
      close(__fd);
      uVar1 = 0;
    }
  }
  return uVar1;
}

[ASK_GPT] f3e326ab2d3a565b
