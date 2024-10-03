
undefined4 main(void)

{
  undefined4 uVar1;
  int iVar2;
  int local_28 [3];
  
  local_28[0] = 2;
[32m  signal(2,FUN_00400880);[0m
[32m  signal(0xf,FUN_00400880);[0m
[32m  signal(3,FUN_00400880);[0m
[32m  signal(0xd,(__sighandler_t)0x1);[0m
[32m  signal(0xb,FUN_00400ab0);[0m
[32m  DAT_00410cf0 = open("/dev/hwmon",2);[0m
  if (DAT_00410cf0 < 0) {
    fwrite("[twinkling] open hwmon node fail!\n",1,0x22,stderr);
    uVar1 = 0xffffffff;
  }
  else {
    if (DAT_00410da0 == 0) {
      do {
        ioctl(DAT_00410cf0,0x8004480b,local_28);
        iVar2 = 2;
        if (local_28[0] != 0) {
          iVar2 = 0;
        }
        local_28[0] = iVar2;
        usleep(500000);
      } while (DAT_00410da0 == 0);
    }
    local_28[0] = 0;
    ioctl(DAT_00410cf0,0x8004480b,local_28);
    close(DAT_00410cf0);
    fwrite("[twinkling] exit!\n",1,0x12,stderr);
    uVar1 = 0;
  }
  return uVar1;
}

[ASK_GPT] ae96ee16e172378b
