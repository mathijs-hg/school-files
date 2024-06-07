
undefined4 main(int param_1,char **param_2)

{
  int __fd;
  uint *__ptr;
  int iVar1;
  longlong lVar2;
  undefined4 local_1e8;
  int local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  int local_1d8;
  void *local_1d4;
  uint local_1d0;
  char acStack_1c0 [108];
  int local_154;
  undefined4 local_150 [2];
  int local_148;
  undefined4 local_140;
  undefined auStack_13c [6];
  undefined auStack_136 [6];
  undefined2 local_130;
  undefined2 local_12e;
  undefined2 local_12c;
  undefined auStack_128 [4];
  undefined auStack_124 [4];
  undefined auStack_120 [4];
  undefined auStack_11c [4];
  undefined auStack_118 [4];
  undefined auStack_114 [4];
  undefined auStack_110 [4];
  undefined auStack_10c [4];
  undefined auStack_108 [4];
  undefined auStack_104 [4];
  undefined auStack_100 [4];
  undefined auStack_fc [38];
  undefined2 local_d6;
  undefined2 local_d4;
  undefined2 local_d2;
  undefined2 local_d0;
  undefined local_cd;
  undefined4 local_cc;
  undefined local_c8;
  undefined4 local_c4;
  undefined local_a8 [24];
  uint local_90;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  undefined local_78;
  undefined local_77;
  undefined2 local_76;
  undefined2 local_74;
  undefined2 local_72;
  undefined2 local_70;
  undefined2 local_6e;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  memcpy(acStack_1c0,
         "abefgyzMD?c:m:r:A:B:C:E:F:G:H:I:J:K:L:R:S:d:h:i:j:1:k:2:l:3:n:o:p:q:4:s:t:u:v:w:5:x:y:N:O:P:Q:T:U:W:Z:L:6"
[32m[32m         ,0x6a);[0m[0m
  local_1e8 = 0xffffffff;
  local_154 = 0;
  local_150[0] = 0;
[32m  __fd = open("/dev/hwnat0",0);[0m
  if (__fd < 0) {
    printf("Open %s pseudo device failed\n","/dev/hwnat0");
  }
  else if (param_1 < 2) {
    show_usage();
    close(__fd);
  }
  else {
[32m[32m    __ptr = (uint *)malloc(0x28000c);[0m[0m
    if (__ptr == (uint *)0x0) {
      puts(" Allocate memory for hwnat_args and hwnat_tuple failed.");
      close(__fd);
    }
    else {
[32m      while (iVar1 = getopt(param_1,param_2,acStack_1c0), iVar1 != -1) {[0m
        switch(iVar1) {
        case 0x31:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_1d8 = (int)lVar2;
          local_148 = local_1d8;
          break;
        case 0x32:
          if (local_1d8 == 0) {
            str_to_ip(auStack_124,optarg);
          }
          else {
            if (local_1d8 != 5) {
              puts("hwnat type error");
              return 0;
            }
            str_to_ipv6(auStack_110,optarg,0);
            str_to_ipv6(auStack_10c,optarg,1);
            str_to_ipv6(auStack_108,optarg,2);
            str_to_ipv6(auStack_104,optarg,3);
          }
          break;
        case 0x33:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_d4 = (undefined2)lVar2;
          break;
        case 0x34:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_cc = (undefined4)lVar2;
          break;
        case 0x35:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_c4 = (undefined4)lVar2;
        case 0x61:
          local_1e8 = 1;
          break;
        case 0x36:
          local_1e8 = 0x27;
          break;
        case 0x3f:
          show_usage();
          break;
        case 0x41:
          iVar1 = strncmp(param_2[2],"dump",4);
          if (iVar1 == 0) {
[32m[32m            local_1d4 = malloc(0x7058);[0m[0m
            local_1e8 = 0x2b;
            puts("dump");
          }
          else {
            iVar1 = strncmp(param_2[2],"clear",5);
            if (iVar1 == 0) {
[32m[32m              local_1d4 = malloc(0x58);[0m[0m
              local_1e8 = 0x2a;
              puts("clear");
            }
            else {
              if (param_1 < 5) {
                show_usage();
                close(__fd);
                return 0;
              }
              iVar1 = strncmp(param_2[2],"mac_get",7);
              if (iVar1 == 0) {
[32m[32m                local_1d4 = malloc(0x90);[0m[0m
                local_1e8 = 0x2c;
                if (local_1d4 == (void *)0x0) {
                  puts(" Allocate memory for traffic_stats_opt failed.");
                  close(__fd);
                  return 0;
                }
                *(undefined2 *)((int)local_1d4 + 0x50) = 0;
              }
              else {
                iVar1 = strncmp(param_2[2],"get",3);
                if (iVar1 != 0) {
                  show_usage();
                  close(__fd);
                  return 0;
                }
                local_1e8 = 9;
                lVar2 = strtoll(optarg,(char **)0x0,10);
                local_a8[0] = (undefined)lVar2;
              }
            }
          }
          break;
        case 0x4e:
          local_1e8 = 0x16;
          lVar2 = strtoll(param_2[2],(char **)0x0,10);
          local_88 = local_88 & 0xffff0000 | (uint)(ushort)lVar2;
          break;
        case 0x4f:
          local_1e8 = 0x17;
          lVar2 = strtoll(param_2[2],(char **)0x0,10);
          local_84 = local_84 & 0xf0003fff | ((uint)lVar2 & 0x3fff) << 0xe;
          lVar2 = strtoll(param_2[3],(char **)0x0,10);
          local_84 = local_84 & 0xffffc000 | (uint)lVar2 & 0x3fff;
          lVar2 = strtoll(param_2[4],(char **)0x0,10);
          local_88 = local_88 & 0xc000ffff | ((uint)lVar2 & 0x3fff) << 0x10;
          break;
        case 0x50:
          local_1e8 = 0x18;
          lVar2 = strtoll(param_2[2],(char **)0x0,10);
          local_80 = local_80 & 0xfffffe00 | (uint)lVar2 & 0x1ff;
          lVar2 = strtoll(param_2[3],(char **)0x0,10);
          local_80 = local_80 & 0xfffc01ff | ((uint)lVar2 & 0x1ff) << 9;
          lVar2 = strtoll(param_2[4],(char **)0x0,10);
          local_80 = local_80 & 0xf803ffff | ((uint)lVar2 & 0x1ff) << 0x12;
          lVar2 = strtoll(param_2[5],(char **)0x0,10);
          local_7c = local_7c & 0xfffffe00 | (uint)lVar2 & 0x1ff;
          lVar2 = strtoll(param_2[6],(char **)0x0,10);
          local_7c = local_7c & 0xfffc01ff | ((uint)lVar2 & 0x1ff) << 9;
          break;
        case 0x51:
          local_1e8 = 0x19;
          lVar2 = strtoll(param_2[2],(char **)0x0,10);
          local_7c = local_7c & 0xfc03ffff | ((uint)lVar2 & 0xff) << 0x12;
          lVar2 = strtoll(param_2[3],(char **)0x0,10);
          local_78 = (undefined)lVar2;
          break;
        case 0x53:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_12e = (undefined2)lVar2;
          break;
        case 0x54:
          local_1e8 = 0x1a;
          lVar2 = strtoll(param_2[2],(char **)0x0,10);
          local_77 = (undefined)lVar2;
          break;
        case 0x55:
          local_1e8 = 0x1b;
          lVar2 = strtoll(param_2[2],(char **)0x0,10);
          local_76 = (undefined2)lVar2;
          lVar2 = strtoll(param_2[3],(char **)0x0,10);
          local_74 = (undefined2)lVar2;
          lVar2 = strtoll(param_2[4],(char **)0x0,10);
          local_72 = (undefined2)lVar2;
          break;
        case 0x56:
          local_1e8 = 0x1d;
          lVar2 = strtoll(param_2[2],(char **)0x0,10);
          local_6e = (undefined2)lVar2;
          lVar2 = strtoll(param_2[3],(char **)0x0,10);
          local_70 = (undefined2)lVar2;
          break;
        case 0x57:
          local_1e8 = 0x28;
[32m          iVar1 = sscanf(optarg,"%d_%d",&local_154,local_150);[0m
          if ((iVar1 < 2) && (local_154 != 0)) {
            puts("usage:hw_nat -W 1_vid or 0");
            local_1e8 = 0xffffffff;
          }
          break;
        case 0x5a:
          local_1e8 = 0x1c;
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_6c = local_6c & 0xfffffffc | (uint)lVar2 & 3;
          break;
        case 0x62:
          local_1e8 = 2;
          break;
        case 99:
          local_1e8 = 3;
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_1e0 = (undefined4)lVar2;
          break;
        case 100:
          local_1e8 = 8;
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_1dc = (undefined4)lVar2;
          break;
        case 0x65:
          local_1e8 = 4;
          *__ptr = *__ptr & 0xffffff9f;
          break;
        case 0x66:
          local_1e8 = 4;
          *__ptr = *__ptr & 0xffffff9f | 0x20;
          break;
        case 0x67:
          local_1e8 = 4;
          *__ptr = *__ptr & 0xffffff9f | 0x40;
          break;
        case 0x68:
          str_to_mac(auStack_136,optarg);
          break;
        case 0x69:
          str_to_mac(auStack_13c,optarg);
          break;
        case 0x6a:
          if (local_1d8 == 0) {
            str_to_ip(auStack_128,optarg);
          }
          else {
            if (local_1d8 != 5) {
              puts("hwnat type error");
              return 0;
            }
            str_to_ipv6(auStack_120,optarg,0);
            str_to_ipv6(auStack_11c,optarg,1);
            str_to_ipv6(auStack_118,optarg,2);
            str_to_ipv6(auStack_114,optarg,3);
          }
          break;
        case 0x6b:
          local_1e8 = 0x36;
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_1e0 = (undefined4)lVar2;
          break;
        case 0x6c:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_d6 = (undefined2)lVar2;
          break;
        case 0x6e:
          str_to_ip(auStack_100,optarg);
          break;
        case 0x6f:
          str_to_ip(auStack_fc,optarg);
          break;
        case 0x70:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_d2 = (undefined2)lVar2;
          break;
        case 0x71:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_d0 = (undefined2)lVar2;
          break;
        case 0x73:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_130 = (undefined2)lVar2;
          break;
        case 0x74:
          iVar1 = strcasecmp(optarg,"Ins");
          if (iVar1 == 0) {
            local_cd = 1;
          }
          else {
            iVar1 = strcasecmp(optarg,"Del");
            if (iVar1 != 0) {
              puts("Error: -t No/Mod/Ins/Del");
              return 0;
            }
            local_cd = 0;
          }
          break;
        case 0x75:
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_12c = (undefined2)lVar2;
        case 0x76:
          iVar1 = strcasecmp(optarg,"Tcp");
          if (iVar1 == 0) {
            local_140 = 0;
          }
          else {
            iVar1 = strcasecmp(optarg,"Udp");
            if (iVar1 != 0) {
              puts("Error: -v Tcp/Udp");
              return 0;
            }
            local_140 = 1;
          }
          break;
        case 0x77:
          iVar1 = strcasecmp(optarg,"CPU");
          if (iVar1 == 0) {
            local_c8 = 0;
          }
          else {
            iVar1 = strcasecmp(optarg,"GE1");
            if (iVar1 == 0) {
              local_c8 = 1;
            }
            else {
              iVar1 = strcasecmp(optarg,"GE2");
              if (iVar1 != 0) {
                puts("Error: -w CPU/GE1/GE2");
                return 0;
              }
              local_c8 = 2;
            }
          }
          break;
        case 0x78:
          local_1e8 = 6;
          lVar2 = strtoll(optarg,(char **)0x0,10);
          local_1e0 = (undefined4)lVar2;
          break;
        case 0x79:
          local_1e8 = 0x37;
          break;
        case 0x7a:
          local_1e8 = 0x24;
        }
      }
      switch(local_1e8) {
      case 3:
        local_1d0 = HwNatDumpEntry(local_1e0);
        break;
      case 4:
        HwNatGetAllEntries(__ptr);
        printf("Total Entry Count = %d\n",(uint)*(ushort *)((int)__ptr + 10));
        for (local_1e4 = 0; local_1e4 < (int)(uint)*(ushort *)((int)__ptr + 10);
            local_1e4 = local_1e4 + 1) {
          if (__ptr[local_1e4 * 0x28 + 4] == 0) {
            local_64 = 0;
            local_60 = 0;
            local_5c = 0;
            local_58 = 0;
            if_indextoname(__ptr[local_1e4 * 0x28 + 0x28],(char *)&local_64);
            local_40 = (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x31);
            local_3c = (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0xc);
            printf("IPv4_NAPT=%d : %u.%u.%u.%u:%d->%u.%u.%u.%u:%d => %u.%u.%u.%u:%d->%u.%u.%u.%u:%d packets=%u bytes=%u act_dp = %d, ifname = %s\n"
                   ,(uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x33),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x32),local_40,local_3c,
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x82),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x37),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x36),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x35),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0xd),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x21),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5b),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5a),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x59),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x16),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x86),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5f),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5e),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5d),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x17),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x22),__ptr[local_1e4 * 0x28 + 0x26]
                   ,__ptr[local_1e4 * 0x28 + 0x27],__ptr[local_1e4 * 0x28 + 0x28],&local_64);
          }
          else if (__ptr[local_1e4 * 0x28 + 4] == 1) {
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            if_indextoname(__ptr[local_1e4 * 0x28 + 0x28],(char *)&local_54);
            printf("IPv4_NAT=%d : %u.%u.%u.%u->%u.%u.%u.%u => %u.%u.%u.%u->%u.%u.%u.%u packets=%u bytes=%u act_dp = %d, ifname = %s\n"
                   ,(uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x33),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x32),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x31),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0xc),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x37),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x36),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x35),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0xd),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5b),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5a),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x59),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x16),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5f),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5e),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5d),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x17),__ptr[local_1e4 * 0x28 + 0x26],
                   __ptr[local_1e4 * 0x28 + 0x27],__ptr[local_1e4 * 0x28 + 0x28],&local_54);
          }
          else if (__ptr[local_1e4 * 0x28 + 4] == 2) {
            printf("IPv6_1T= %d /DIP: %x:%x:%x:%x:%x:%x:%x:%x\n",
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4a),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x12),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4e),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x13),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x52),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x14),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x56),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x15));
          }
          else if (__ptr[local_1e4 * 0x28 + 4] == 3) {
            local_38 = (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x82);
            local_34 = (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x37);
            local_30 = (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x36);
            local_2c = (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x35);
            printf("DS-Lite= %d : %u.%u.%u.%u:%d->%u.%u.%u.%u:%d (%x:%x:%x:%x:%x:%x:%x:%x -> %x:%x:%x:%x:%x:%x:%x:%x) \n"
                   ,(uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x33),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x32),
                   (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x31),
                   (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0xc),local_38,local_34,local_30,
                   local_2c,(uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0xd),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x21),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x62),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x18),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x66),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x19),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x6a),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x1a),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x6e),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x1b),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x72),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x1c),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x76),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x1d),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x7a),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x1e),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x7e),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x1f));
          }
          else if (__ptr[local_1e4 * 0x28 + 4] == 4) {
            printf("IPv6_3T= %d SIP: %x:%x:%x:%x:%x:%x:%x:%x DIP: %x:%x:%x:%x:%x:%x:%x:%x\n",
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3a),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xe),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3e),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xf),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x42),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x10),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x46),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x11),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4a),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x12),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4e),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x13),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x52),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x14),
                   (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x56),
                   (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x15));
          }
          else if (__ptr[local_1e4 * 0x28 + 4] == 5) {
            if (*(char *)((int)__ptr + local_1e4 * 0xa0 + 0x8a) == '\x01') {
              printf("IPv6_5T= %d SIP: %x:%x:%x:%x:%x:%x:%x:%x DIP: %x:%x:%x:%x:%x:%x:%x:%x (Flow Label=%x)\n"
                     ,(uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xe),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xf),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x42),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x10),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x46),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x11),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x12),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x13),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x52),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x14),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x56),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x15),
                     CONCAT22(*(undefined2 *)((int)__ptr + local_1e4 * 0xa0 + 0x82),
                              *(undefined2 *)(__ptr + local_1e4 * 0x28 + 0x21)) & 0xfffff);
            }
            else {
              printf("IPv6_5T= %d SIP: %x:%x:%x:%x:%x:%x:%x:%x (SP:%d) DIP: %x:%x:%x:%x:%x:%x:%x:%x (DP=%d)\n"
                     ,(uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xe),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xf),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x42),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x10),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x46),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x11),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x82),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x12),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x13),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x52),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x14),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x56),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x15),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x21));
            }
          }
          else if (__ptr[local_1e4 * 0x28 + 4] == 7) {
            if (*(char *)((int)__ptr + local_1e4 * 0xa0 + 0x8a) == '\x01') {
              printf("6RD= %d %x:%x:%x:%x:%x:%x:%x:%x->%x:%x:%x:%x:%x:%x:%x:%x [Flow Label=%x]\n",
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xe),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xf),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x42),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x10),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x46),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x11),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x12),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x13),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x52),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x14),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x56),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x15),
                     CONCAT22(*(undefined2 *)((int)__ptr + local_1e4 * 0xa0 + 0x82),
                              *(undefined2 *)(__ptr + local_1e4 * 0x28 + 0x21)) & 0xfffff);
              printf("(%u.%u.%u.%u->%u.%u.%u.%u)\n",
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5b),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5a),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x59),
                     (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x16),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5f),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5e),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5d),
                     (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x17));
            }
            else {
              printf("6RD= %d /SIP: %x:%x:%x:%x:%x:%x:%x:%x [SP:%d] /DIP: %x:%x:%x:%x:%x:%x:%x:%x [DP=%d]"
                     ,(uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 3),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xe),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x3e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0xf),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x42),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x10),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x46),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x11),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x82),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4a),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x12),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x4e),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x13),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x52),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x14),
                     (uint)*(ushort *)((int)__ptr + local_1e4 * 0xa0 + 0x56),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x15),
                     (uint)*(ushort *)(__ptr + local_1e4 * 0x28 + 0x21));
              printf("(%u.%u.%u.%u->%u.%u.%u.%u)\n",
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5b),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5a),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x59),
                     (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x16),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5f),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5e),
                     (uint)*(byte *)((int)__ptr + local_1e4 * 0xa0 + 0x5d),
                     (uint)*(byte *)(__ptr + local_1e4 * 0x28 + 0x17));
            }
          }
          else {
            printf("unknown packet type! (pkt_type=%d) \n",__ptr[local_1e4 * 0x28 + 4]);
          }
        }
        local_1d0 = __ptr[1];
        break;
      default:
        local_1d0 = 1;
        break;
      case 6:
        local_1d0 = HwNatUnBindEntry(local_1e0);
        break;
      case 8:
        local_1d0 = HwNatDebug(local_1dc);
        break;
      case 9:
        HwNatGetAGCnt(local_a8);
        printf("Byte cnt=%llu\n");
        printf("Pkt cnt=%llu\n");
        local_1d0 = local_90;
        break;
      case 0x16:
        HwNatSetBindThreshold(&local_88);
        local_1d0 = local_68;
        break;
      case 0x17:
        HwNatSetMaxEntryRateLimit(&local_88);
        local_1d0 = local_68;
        break;
      case 0x18:
        HwNatSetRuleSize(&local_88);
        local_1d0 = local_68;
        break;
      case 0x19:
        HwNatSetKaInterval(&local_88);
        local_1d0 = local_68;
        break;
      case 0x1a:
        HwNatSetUnbindLifeTime(&local_88);
        local_1d0 = local_68;
        break;
      case 0x1b:
        local_1d0 = HwNatSetBindLifeTime(&local_88);
        break;
      case 0x1c:
        local_1d0 = HwNatSetBindDir(&local_88);
        break;
      case 0x1d:
        local_1d0 = HwNatSetVID(&local_88);
        break;
      case 0x24:
        local_1d0 = HwNatCacheDumpEntry();
        break;
      case 0x27:
        local_1d0 = HwNatDumpDport();
        break;
      case 0x28:
        local_1d0 = HwNatSwitchDsliteMape(local_154,local_150[0]);
        break;
      case 0x2a:
        local_1d0 = TFStats_clear_all(local_1d4);
        break;
      case 0x2b:
        local_1d0 = TFStats_get_all(local_1d4);
        break;
      case 0x2c:
        local_1d0 = TFStats_get(local_1d4);
        break;
      case 0x36:
        local_1d0 = HwNatDropEntry(local_1e0);
        break;
      case 0x37:
        local_1d0 = HwNatTblClear();
      }
      if (local_1d0 == 0) {
        puts("done");
      }
      else if (local_1d0 == 2) {
        puts("entry not found");
      }
      else {
        puts("fail");
      }
      free(__ptr);
      close(__fd);
    }
  }
  return 0;
}

[ASK_GPT] 8ccd4d8cf38212de
