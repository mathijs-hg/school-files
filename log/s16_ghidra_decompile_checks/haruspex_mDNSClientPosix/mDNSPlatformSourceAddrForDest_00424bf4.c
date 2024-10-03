
void mDNSPlatformSourceAddrForDest(int *param_1,int *param_2)

{
  int __fd;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  socklen_t __len;
  socklen_t local_40;
  sockaddr local_3c;
  undefined4 local_24;
  int local_20;
  
  local_40 = 0x1c;
  __fd = socket(2,1,0);
  *param_1 = 0;
  if (__fd != -1) {
    if (*param_2 == 4) {
      local_3c.sa_data._2_4_ = param_2[1];
      local_3c.sa_family = 2;
      __len = 0x10;
      local_3c.sa_data._0_2_ = 1;
    }
    else {
      if (*param_2 != 6) {
        return;
      }
      local_3c.sa_family = 10;
      local_3c.sa_data._0_2_ = 1;
      local_3c.sa_data._2_4_ = 0;
[32m[32m      memcpy(local_3c.sa_data + 6,param_2 + 1,0x10);[0m[0m
      __len = 0x1c;
      local_24 = 0;
    }
    iVar1 = connect(__fd,&local_3c,__len);
    if (iVar1 < 0) {
      piVar2 = __errno_location();
      local_20 = *piVar2;
      pcVar3 = strerror(local_20);
      LogMsgWithLevel(0,"mDNSPlatformSourceAddrForDest: connect %#a failed errno %d (%s)",param_2,
                      local_20,pcVar3);
    }
    else {
      iVar1 = getsockname(__fd,&local_3c,&local_40);
      if (iVar1 < 0) {
        piVar2 = __errno_location();
        local_20 = *piVar2;
        pcVar3 = strerror(local_20);
        LogMsgWithLevel(0,"mDNSPlatformSourceAddrForDest: getsockname failed errno %d (%s)",local_20
                        ,pcVar3);
      }
      else {
        *param_1 = *param_2;
        if (*param_2 == 4) {
          param_1[1] = local_3c.sa_data._2_4_;
        }
        else {
[32m[32m          memcpy(param_1 + 1,local_3c.sa_data + 6,0x10);[0m[0m
        }
      }
    }
    close(__fd);
  }
  return;
}

[ASK_GPT] cdd087896e8b495f
