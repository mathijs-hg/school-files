
undefined4
mDNSPlatformSendUDP(int **param_1,void *param_2,int param_3,int param_4,undefined4 param_5,
                   int *param_6,undefined4 param_11)

{
  socklen_t __addr_len;
  ssize_t sVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  sockaddr local_48 [2];
  int local_28;
  
  if (param_1 == (int **)0x0) {
    __assert("m != ((void *)0)","mDNSPosix.c",0x98);
  }
  if (param_2 == (void *)0x0) {
    __assert("msg != ((void *)0)","mDNSPosix.c",0x99);
  }
  if (param_3 == 0) {
    __assert("end != ((void *)0)","mDNSPosix.c",0x9a);
  }
  if (param_3 - (int)param_2 < 1) {
    __assert("(((char *) end) - ((char *) msg)) > 0","mDNSPosix.c",0x9b);
  }
  if (param_11._0_2_ == 0) {
    LogMsgWithLevel(0,"mDNSPlatformSendUDP: Invalid argument -dstPort is set to 0");
LAB_00406dac:
    uVar4 = 0xfffeffff;
  }
  else {
    if (*param_6 == 4) {
      local_48[0].sa_data._2_4_ = param_6[1];
      local_48[0].sa_family = 2;
      if (param_4 == 0) {
        iVar6 = **param_1;
      }
      else {
        iVar6 = *(int *)(param_4 + 0x15ac);
      }
    }
    else {
      if (*param_6 != 6) {
        return 0;
      }
      mDNSPlatformMemZero(local_48,0x1c);
      local_48[0].sa_family = 10;
[32m[32m      memcpy(local_48[0].sa_data + 6,param_6 + 1,0x10);[0m[0m
      if (param_4 == 0) {
        iVar6 = (*param_1)[1];
      }
      else {
        iVar6 = *(int *)(param_4 + 0x15b0);
      }
    }
    if (-1 < iVar6) {
      if ((local_48[0].sa_family == 2) || (__addr_len = 0x1c, local_48[0].sa_family != 10)) {
        __addr_len = 0x10;
      }
      sVar1 = sendto(iVar6,param_2,param_3 - (int)param_2,0,local_48,__addr_len);
      if ((sVar1 < 1) && (sVar1 != 0)) {
        if (*param_6 == 4) {
          iVar5 = param_6[1];
          iVar6 = -0x1fffff05;
LAB_00406ca4:
          if (iVar5 != iVar6) goto LAB_00406cac;
        }
        else {
          if ((((*param_6 == 6) && (param_6[1] == -0xfe0000)) && (param_6[2] == 0)) &&
             (param_6[3] == 0)) {
            iVar6 = 0xfb;
            iVar5 = param_6[4];
            goto LAB_00406ca4;
          }
LAB_00406cac:
          piVar2 = __errno_location();
          iVar6 = *piVar2;
          if (((iVar6 == 0x93) || (iVar6 == 0x7f)) || ((iVar6 == 0x94 || (iVar6 == 0x80)))) {
            return 0xfffeffe6;
          }
        }
        if (DAT_0046e6c0 < 1000) {
          if (param_4 == 0) {
            DAT_0046e6c0 = DAT_0046e6c0 + 1;
            piVar2 = __errno_location();
            local_28 = *piVar2;
            pcVar3 = strerror(local_28);
            LogMsgWithLevel(0,"mDNSPlatformSendUDP got error %d (%s) sending packet to %#a",local_28
                            ,pcVar3,param_6);
          }
          else {
            DAT_0046e6c0 = DAT_0046e6c0 + 1;
            piVar2 = __errno_location();
            local_28 = *piVar2;
            pcVar3 = strerror(local_28);
            LogMsgWithLevel(0,
                            "mDNSPlatformSendUDP got error %d (%s) sending packet to %#a on interface %#a/%s/%d"
                            ,local_28,pcVar3,param_6,param_4 + 0x1524,
                            *(undefined4 *)(param_4 + 0x15a0),*(undefined4 *)(param_4 + 0x15a8));
          }
        }
        goto LAB_00406dac;
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

[ASK_GPT] d5131d6cbd1bdb56
