
/* WARNING: Heritage AFTER dead removal. Example location: r0x00413138 : 0x00402300 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 main(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  __fd_mask *p_Var4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_910;
  undefined4 local_90c;
  socklen_t local_908;
  sockaddr local_904;
  char acStack_8f4 [32];
  uint local_8d4 [32];
  undefined4 uStack_854;
  uint local_850;
  char local_84c;
  ushort local_84b;
  undefined2 local_849;
  undefined auStack_843 [6];
  ushort local_83d;
  uint local_83b;
  undefined auStack_54 [12];
  uint local_48;
  undefined4 *local_44;
  socklen_t *local_40;
  undefined4 *local_3c;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  
  local_910 = 1;
  local_90c = 1;
  local_908 = 0;
  if (param_1 < 2) {
    FUN_004013d0("Invaild ifname\n");
    uVar2 = 0xffffffff;
  }
  else {
    ifname = *(char **)(param_2 + 4);
    iVar3 = FUN_00401120();
    uVar2 = 0;
    if (-1 < iVar3) {
      FUN_00401240();
      server_sockfd = socket(2,1,0x11);
      if (server_sockfd == 0xffffffff) {
        FUN_004013d0("Can\'t get server socket\n");
        uVar2 = 0xffffffff;
      }
      else {
        local_904.sa_data._6_4_ = 0;
        local_904.sa_data._10_4_ = 0;
        local_904.sa_family = 2;
        local_904.sa_data._2_4_ = 0;
        local_904.sa_data._0_2_ = 0xf500;
[32m[32m[32m        strncpy(acStack_8f4,ifname,0x10);[0m[0m[0m
        iVar3 = setsockopt(server_sockfd,0xffff,0x19,acStack_8f4,0x20);
        if (iVar3 < 0) {
          FUN_004013d0("setsockopt SO_BINDTODEVICE failed\n");
          uVar2 = 0xffffffff;
        }
        else {
          iVar3 = setsockopt(server_sockfd,0xffff,0x20,&local_910,4);
          if (iVar3 < 0) {
            FUN_004013d0("setsockopt SO_BROADCAST failed\n");
            uVar2 = 0xffffffff;
          }
          else {
            iVar3 = setsockopt(server_sockfd,0xffff,4,&local_90c,4);
            if (iVar3 < 0) {
              FUN_004013d0("setsockopt SO_REUSEADDR failed\n");
              uVar2 = 0xffffffff;
            }
            else {
              iVar3 = bind(server_sockfd,&local_904,0x10);
              if (iVar3 < 0) {
                FUN_004013d0("bind port(%d) error\n",0xf500);
                uVar2 = 0xffffffff;
              }
              else {
                FUN_004013d0("IPFind start(%s)...\n",ifname);
                local_44 = &uStack_854;
                local_38 = auStack_843;
                local_40 = &local_908;
                local_3c = &DAT_00402ad0;
                local_34 = auStack_54;
                local_30 = &DAT_00402e90;
                do {
                  while( true ) {
                    p_Var4 = (__fd_mask *)local_8d4;
                    if (DAT_00413168 != 0) goto LAB_00402748;
                    do {
                      *p_Var4 = 0;
                      p_Var4 = p_Var4 + 1;
                    } while (p_Var4 != &uStack_854);
                    local_8d4[server_sockfd >> 5] =
                         local_8d4[server_sockfd >> 5] | 1 << (server_sockfd & 0x1f);
                    iVar3 = select(server_sockfd + 1,(fd_set *)local_8d4,(fd_set *)0x0,(fd_set *)0x0
                                   ,(timeval *)0x0);
                    if (iVar3 < 0) break;
                    if (((int)local_8d4[server_sockfd >> 5] >> (server_sockfd & 0x1f) & 1U) != 0) {
                      local_908 = 0x10;
[32m                      memset(&uStack_854,0,0x800);[0m
[32m[32m                      recvfrom(server_sockfd,&uStack_854,0x800,0,(sockaddr *)client_addr,local_40);[0m[0m
                      local_850 = local_850 << 0x18 | local_850 >> 0x18 |
                                  (local_850 & 0xff0000) >> 8 | (local_850 & 0xff00) << 8;
                      uVar7 = (local_84b & 0xff) << 8 | (uint)(local_84b >> 8);
                      local_84b = CONCAT11((char)(local_84b & 0xff),(char)(local_84b >> 8));
                      local_849 = CONCAT11((char)local_849,(char)((ushort)local_849 >> 8));
                      uVar6 = (uint)local_83d;
                      uVar1 = local_83d >> 8;
                      local_83d = CONCAT11((char)(uVar6 & 0xff),(char)(local_83d >> 8));
                      local_83b = local_83b << 0x18 | local_83b >> 0x18 |
                                  (local_83b & 0xff0000) >> 8 | (local_83b & 0xff00) << 8;
                      local_48 = local_83b;
                      iVar3 = strncmp((char *)local_44,(char *)local_3c,4);
                      if ((iVar3 == 0) && (local_84c == '\n')) {
                        if (uVar7 == 1) {
                          if (((((uVar6 & 0xff) << 8 | (uint)uVar1) == 0) &&
                              (iVar3 = memcmp(local_38,local_30,6), iVar3 == 0)) && (local_48 == 0))
                          {
                            FUN_0040172c(&uStack_854);
                          }
                        }
                        else if ((((uVar7 == 2) &&
                                  (iVar3 = net_get_hwaddr(ifname,local_34), -1 < iVar3)) &&
                                 (iVar3 = memcmp(local_38,local_34,6), iVar3 == 0)) &&
                                (local_83b == 0x8e)) {
                          FUN_004013f4(&uStack_854);
                        }
                      }
                    }
                  }
                  piVar5 = __errno_location();
                } while (*piVar5 == 4);
LAB_00402748:
                FUN_00402198(ifname);
                uVar2 = 0;
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

[ASK_GPT] da6a5609b518bff2
