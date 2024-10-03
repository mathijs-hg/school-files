
void FUN_00401df4(void)

{
  int __fd;
  int iVar1;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined uStack_58;
  undefined local_57;
  undefined local_56;
  undefined local_55;
  undefined4 local_54;
  undefined4 local_50;
  undefined uStack_4c;
  undefined4 local_48;
  sockaddr local_44;
  char acStack_34 [40];
  
  local_48 = 1;
  local_68 = 0x46495649;
  uStack_58 = 0;
  local_57 = 0xff;
  local_56 = 0xff;
  local_55 = 0xff;
  local_54 = 0xffffff00;
  local_64 = 1;
  local_60 = 0xa010000;
  local_5c = 0;
  local_50 = 0;
  uStack_4c = 0;
  __fd = socket(2,1,0x11);
  if (__fd == -1) {
    FUN_004013d0("Can\'t get hello socket\n");
  }
  else {
    local_44.sa_data._6_4_ = 0;
    local_44.sa_data._10_4_ = 0;
    local_44.sa_family = 2;
    local_44.sa_data._2_4_ = 0;
    local_44.sa_data._0_2_ = 0xf500;
[32m[32m[32m    strncpy(acStack_34,ifname,0x10);[0m[0m[0m
    iVar1 = setsockopt(__fd,0xffff,0x19,acStack_34,0x20);
    if (iVar1 < 0) {
      FUN_004013d0("setsockopt SO_BINDTODEVICE failed\n");
      close(__fd);
    }
    else {
      iVar1 = setsockopt(__fd,0xffff,0x20,&local_48,4);
      if (iVar1 < 0) {
        FUN_004013d0("setsockopt SO_BROADCAST failed\n");
        close(__fd);
      }
      else {
        sendto(__fd,&local_68,0x1d,0,&local_44,0x10);
        close(__fd);
      }
    }
  }
  return;
}

[ASK_GPT] 94e5502d7b641c14
