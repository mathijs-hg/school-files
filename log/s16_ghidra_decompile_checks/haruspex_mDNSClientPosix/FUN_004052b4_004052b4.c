
int FUN_004052b4(short *param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *__s;
  sockaddr *__addr;
  socklen_t __len;
  uint uVar4;
  undefined2 uVar5;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  sockaddr local_6c;
  undefined auStack_5c [16];
  undefined4 local_4c;
  sockaddr local_48;
  undefined4 local_30;
  undefined *local_28;
  
  uVar4 = param_2 >> 0x10;
  if (param_1 == (short *)0x0) {
    __assert("intfAddr != ((void *)0)","mDNSPosix.c",0x273);
  }
  if (param_4 == (int *)0x0) {
    __assert("sktPtr != ((void *)0)","mDNSPosix.c",0x274);
  }
  if (*param_4 != -1) {
    __assert("*sktPtr == -1","mDNSPosix.c",0x275);
  }
  if (*param_1 == 2) {
    iVar3 = 2;
  }
  else {
    if (*param_1 != 10) {
      return 0x16;
    }
    iVar3 = 10;
  }
  iVar3 = socket(iVar3,1,0x11);
  *param_4 = iVar3;
  if (*param_4 < 0) {
    piVar1 = __errno_location();
    iVar3 = *piVar1;
    if (*param_1 == 2) {
      __s = "socket AF_INET";
    }
    else {
      __s = "socket AF_INET6";
    }
    perror(__s);
    if (iVar3 == 0) goto LAB_00405418;
  }
  else {
LAB_00405418:
    iVar3 = 0;
    if (uVar4 != 0) {
      iVar3 = setsockopt(*param_4,0xffff,4,&DAT_0044ce30,4);
      if (iVar3 < 0) {
        piVar1 = __errno_location();
        iVar3 = *piVar1;
        perror("setsockopt - SO_REUSExxxx");
      }
      iVar2 = setsockopt(*param_4,0xffff,0x1104,&DAT_0044ce30,4);
      if (iVar2 < 0) {
        perror("setsockopt - SO_RECV_ANYIF");
      }
    }
  }
  uVar5 = (undefined2)(param_2 >> 0x10);
  if (*param_1 == 2) {
    if (iVar3 == 0) {
      iVar3 = setsockopt(*param_4,0,8,&DAT_0044ce30,4);
      if (iVar3 < 0) {
        piVar1 = __errno_location();
        iVar3 = *piVar1;
        perror("setsockopt - IP_PKTINFO");
      }
      if (iVar3 == 0) {
        setsockopt(*param_4,0,0xc,&DAT_0044ce30,4);
        if (uVar4 == 0) {
LAB_00405620:
          iVar3 = setsockopt(*param_4,0,2,&DAT_0044ce2c,4);
          if (iVar3 < 0) {
            piVar1 = __errno_location();
            iVar3 = *piVar1;
            perror("setsockopt - IP_TTL");
          }
          if (iVar3 == 0) {
            iVar3 = setsockopt(*param_4,0,0x21,&DAT_0044ce28,1);
            if ((iVar3 < 0) &&
               ((piVar1 = __errno_location(), *piVar1 != 0x16 ||
                (iVar3 = setsockopt(*param_4,0,0x21,&DAT_0044ce2c,4), iVar3 < 0)))) {
              iVar3 = *piVar1;
              perror("setsockopt - IP_MULTICAST_TTL");
            }
            if (iVar3 == 0) {
              __addr = &local_6c;
              iVar3 = *param_4;
              __len = 0x10;
              local_6c.sa_family = 2;
              local_6c.sa_data._2_4_ = 0;
              local_6c.sa_data._0_2_ = uVar5;
LAB_00405a90:
              iVar3 = bind(iVar3,__addr,__len);
              if (iVar3 < 0) {
                piVar1 = __errno_location();
                iVar3 = *piVar1;
                perror("bind");
                fflush(stderr);
              }
              goto LAB_00405ae4;
            }
          }
        }
        else {
          local_70 = *(undefined4 *)(param_1 + 2);
          local_74 = 0xe00000fb;
          iVar3 = setsockopt(*param_4,0,0x23,&local_74,8);
          if (iVar3 < 0) {
            piVar1 = __errno_location();
            iVar3 = *piVar1;
            perror("setsockopt - IP_ADD_MEMBERSHIP");
          }
          if (iVar3 == 0) {
            iVar3 = setsockopt(*param_4,0,0x20,param_1 + 2,4);
            if (iVar3 < 0) {
              piVar1 = __errno_location();
              iVar3 = *piVar1;
              perror("setsockopt - IP_MULTICAST_IF");
            }
            if (iVar3 == 0) goto LAB_00405620;
          }
        }
      }
    }
  }
  else if (*param_1 == 10) {
    if (iVar3 == 0) {
      iVar3 = setsockopt(*param_4,0x29,2,&DAT_0044ce30,4);
      if (iVar3 < 0) {
        piVar1 = __errno_location();
        iVar3 = *piVar1;
        perror("setsockopt - IPV6_PKTINFO");
      }
      if (iVar3 == 0) {
        iVar3 = setsockopt(*param_4,0x29,8,&DAT_0044ce30,4);
        if (iVar3 < 0) {
          piVar1 = __errno_location();
          iVar3 = *piVar1;
          perror("setsockopt - IPV6_HOPLIMIT");
        }
        if (iVar3 == 0) {
          if (uVar4 == 0) {
LAB_004058ec:
            iVar3 = setsockopt(*param_4,0x29,0x1a,&DAT_0044ce30,4);
            if (iVar3 < 0) {
              piVar1 = __errno_location();
              iVar3 = *piVar1;
              perror("setsockopt - IPV6_V6ONLY");
            }
            if (iVar3 == 0) {
              iVar3 = setsockopt(*param_4,0x29,0x10,&DAT_0044ce2c,4);
              if (iVar3 < 0) {
                piVar1 = __errno_location();
                iVar3 = *piVar1;
                perror("setsockopt - IPV6_UNICAST_HOPS");
              }
              if (iVar3 == 0) {
                iVar3 = setsockopt(*param_4,0x29,0x12,&DAT_0044ce28,1);
                if ((iVar3 < 0) &&
                   ((piVar1 = __errno_location(), *piVar1 != 0x16 ||
                    (iVar3 = setsockopt(*param_4,0x29,0x12,&DAT_0044ce2c,4), iVar3 < 0)))) {
                  iVar3 = *piVar1;
                  perror("setsockopt - IPV6_MULTICAST_HOPS");
                }
                if (iVar3 == 0) {
                  __addr = &local_48;
                  mDNSPlatformMemZero(__addr,0x1c);
                  local_48.sa_family = 10;
                  local_48.sa_data._2_4_ = 0;
                  local_48.sa_data._0_2_ = uVar5;
[32m[32m                  memcpy(local_48.sa_data + 6,&in6addr_any,0x10);[0m[0m
                  __len = 0x1c;
                  iVar3 = *param_4;
                  local_30 = 0;
                  goto LAB_00405a90;
                }
              }
            }
          }
          else {
            local_28 = auStack_5c;
[32m[32m            memcpy(auStack_5c,AllDNSLinkGroup_v6 + 4,0x10);[0m[0m
            local_4c = param_3;
            iVar3 = setsockopt(*param_4,0x29,0x14,local_28,0x14);
            if (iVar3 < 0) {
              piVar1 = __errno_location();
              iVar3 = *piVar1;
              perror("setsockopt - IPV6_JOIN_GROUP");
            }
            if (iVar3 == 0) {
              local_78 = param_3;
              iVar3 = setsockopt(*param_4,0x29,0x11,&local_78,4);
              if (iVar3 < 0) {
                piVar1 = __errno_location();
                iVar3 = *piVar1;
                perror("setsockopt - IPV6_MULTICAST_IF");
              }
              if (iVar3 == 0) goto LAB_004058ec;
            }
          }
        }
      }
    }
  }
  else {
LAB_00405ae4:
    if (iVar3 == 0) {
      uVar4 = fcntl(*param_4,3,0);
      if (((int)uVar4 < 0) || (iVar3 = fcntl(*param_4,4,uVar4 | 0x80), iVar3 < 0)) {
        piVar1 = __errno_location();
        iVar3 = *piVar1;
      }
      if (iVar3 == 0) goto LAB_00405b98;
    }
  }
  if (*param_4 != -1) {
    iVar2 = close(*param_4);
    if (iVar2 != 0) {
      __assert("close(*sktPtr) == 0","mDNSPosix.c",0x354);
    }
    *param_4 = -1;
  }
LAB_00405b98:
  if ((iVar3 == 0) != (*param_4 != -1)) {
    __assert("(err == 0) == (*sktPtr != -1)","mDNSPosix.c",0x355);
  }
  return iVar3;
}

[ASK_GPT] cc9793b5a9a1bfac
