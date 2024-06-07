
/* WARNING: Could not reconcile some variable overlaps */

undefined4
set_private_cmd(FLO_type param_1,FLO_type param_2,int param_3,char **param_4,uint param_5_00,
               char *param_6_00,char *param_5,int param_6,int param_7,char *param_8,size_t param_9)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  CMPtype CVar8;
  size_t sVar9;
  char **local_res4;
  uint local_res8;
  int local_1100;
  int local_10fc;
  undefined4 ******local_10f8;
  int local_10f4;
  undefined4 local_10f0;
  int local_10ec;
  int local_10e8;
  uint local_10e4;
  undefined4 ******local_10e0;
  char acStack_10c8 [16];
  undefined4 ******local_10b8;
  undefined4 local_10b4;
  undefined4 local_10b0;
  undefined4 local_10ac;
  undefined4 ******local_10a8;
  uint local_10a4;
  undefined4 local_10a0;
  undefined4 local_109c;
  undefined local_a9;
  undefined4 ******local_a8 [2];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined auStack_98 [132];
  
  local_1100 = 0;
  local_10f8 = (undefined4 ******)0x0;
  local_10f4 = 0;
  local_10f0 = 0;
  memset(param_8,0,param_9);
  local_res4 = param_4;
  local_res8 = param_5_00;
[32m  if ((0 < (int)param_5_00) && (iVar3 = sscanf(*param_4,"[%i]",local_a8), iVar3 == 1)) {[0m
    local_10f8 = local_a8[0];
    local_res4 = param_4 + 1;
    local_res8 = param_5_00 - 1;
  }
  local_10fc = -1;
  do {
    iVar3 = local_10fc + 1;
    local_10fc = iVar3;
    if (param_7 <= iVar3) break;
    iVar4 = strcmp((char *)(param_6 + iVar3 * 0x18 + 8),param_5);
  } while (iVar4 != 0);
  if (iVar3 == param_7) {
    sVar5 = strlen(param_8);
    sVar6 = strlen(param_8);
[32m    snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"Invalid command : %s\n",param_5);[0m
    return 0xffffffff;
  }
  if (*(uint *)(param_6 + iVar3 * 0x18) < 0x89f0) {
    local_10ec = -1;
    do {
      local_10fc = local_10ec + 1;
      if (param_7 <= local_10fc) break;
      local_10ec = local_10fc;
    } while (((*(char *)(param_6 + local_10fc * 0x18 + 8) != '\0') ||
             (*(short *)(param_6 + local_10fc * 0x18 + 4) != *(short *)(param_6 + iVar3 * 0x18 + 4))
             ) || (*(short *)(param_6 + local_10fc * 0x18 + 6) !=
                   *(short *)(param_6 + iVar3 * 0x18 + 6)));
    if (local_10fc == param_7) {
      sVar5 = strlen(param_8);
      sVar6 = strlen(param_8);
      snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"Invalid private ioctl definition for : %s\n",
[32m               param_5);[0m
      return 0xffffffff;
    }
    local_10f8 = *(undefined4 *******)(param_6 + iVar3 * 0x18);
    local_10f4 = 4;
  }
  if (((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7000) == 0) ||
     ((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff) == 0)) {
    local_10b4 = (uint)local_10b4._2_2_ << 0x10;
  }
  else {
    uVar2 = *(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7000;
    if (uVar2 == 0x4000) {
      uVar1 = local_10b4 & 0xffff0000;
      local_10b4 = uVar1 | local_res8 & 0xffff;
      if ((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff) < (local_res8 & 0xffff)) {
        local_10b4 = uVar1 | *(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0xffff07ff;
      }
      for (; local_1100 < (int)(local_10b4 & 0xffff); local_1100 = local_1100 + 1) {
[32m[32m        sscanf(local_res4[local_1100],"%i",local_a8);[0m[0m
        (&local_10a8)[local_1100] = local_a8[0];
      }
    }
    else if (uVar2 < 0x4001) {
      if (uVar2 == 0x1000) {
        uVar1 = local_10b4 & 0xffff0000;
        local_10b4 = uVar1 | local_res8 & 0xffff;
        if ((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff) < (local_res8 & 0xffff)) {
          local_10b4 = uVar1 | *(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0xffff07ff;
        }
        for (; local_1100 < (int)(local_10b4 & 0xffff); local_1100 = local_1100 + 1) {
[32m[32m          sscanf(local_res4[local_1100],"%i",local_a8);[0m[0m
          *(char *)((int)&local_10a8 + local_1100) = (char)local_a8[0];
        }
      }
      else {
        if (uVar2 != 0x2000) {
LAB_00403554:
          sVar5 = strlen(param_8);
          sVar6 = strlen(param_8);
[32m          snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"Not implemented...\n");[0m
          return 0xffffffff;
        }
        if ((int)local_res8 < 1) {
          local_10b4 = CONCAT22(local_10b4._2_2_,1);
          local_10a8 = (undefined4 ******)((uint)local_10a8 & 0xffffff00);
        }
        else {
          sVar5 = strlen(*local_res4);
          uVar2 = (short)sVar5 + 1;
          if ((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff) < uVar2) {
            uVar2 = *(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff;
          }
          local_10b4 = CONCAT22(local_10b4._2_2_,uVar2);
[32m          memcpy(&local_10a8,*local_res4,(uint)uVar2);[0m
          local_a9 = 0;
        }
      }
    }
    else if (uVar2 == 0x5000) {
      uVar1 = local_10b4 & 0xffff0000;
      local_10b4 = uVar1 | local_res8 & 0xffff;
      if ((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff) < (local_res8 & 0xffff)) {
        local_10b4 = uVar1 | *(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0xffff07ff;
      }
      for (; local_1100 < (int)(local_10b4 & 0xffff); local_1100 = local_1100 + 1) {
[32m        iVar3 = sscanf(local_res4[local_1100],"%lg",&local_a0);[0m
        if (iVar3 != 1) {
          sVar5 = strlen(param_8);
          sVar6 = strlen(param_8);
          snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"Invalid float [%s]...\n",
[32m                   local_res4[local_1100]);[0m
          return 0xffffffff;
        }
        pcVar7 = strchr(local_res4[local_1100],0x47);
        if (pcVar7 != (char *)0x0) {
          __muldf3(param_1,param_2);
        }
        pcVar7 = strchr(local_res4[local_1100],0x4d);
        if (pcVar7 != (char *)0x0) {
          __muldf3(param_1,param_2);
        }
        pcVar7 = strchr(local_res4[local_1100],0x6b);
        if (pcVar7 != (char *)0x0) {
          __muldf3(param_1,param_2);
        }
[32m[32m        sscanf(local_res4[local_1100],"%i",local_a8);[0m[0m
        iw_float2freq(local_a0,local_9c,&local_10a8 + local_1100 * 2);
      }
    }
    else {
      if (uVar2 != 0x6000) goto LAB_00403554;
      uVar1 = local_10b4 & 0xffff0000;
      local_10b4 = uVar1 | local_res8 & 0xffff;
      if ((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff) < (local_res8 & 0xffff)) {
        local_10b4 = uVar1 | *(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0xffff07ff;
      }
      for (; local_1100 < (int)(local_10b4 & 0xffff); local_1100 = local_1100 + 1) {
        iVar3 = iw_in_addr(param_3,param_6_00,local_res4[local_1100],&local_10a8 + local_1100 * 4);
        if (iVar3 < 0) {
          sVar5 = strlen(param_8);
          sVar6 = strlen(param_8);
          snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"Invalid address [%s]...\n",
[32m                   local_res4[local_1100]);[0m
          return 0xffffffff;
        }
      }
    }
    if (((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x800) != 0) &&
       ((local_10b4 & 0xffff) != (*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff))) {
      sVar5 = strlen(param_8);
      sVar6 = strlen(param_8);
      snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,
               "The command %s needs exactly %d argument(s)...\n",param_5,
[32m               *(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x7ff);[0m
      return 0xffffffff;
    }
  }
[32m[32m[32m  strncpy(acStack_10c8,param_6_00,0x10);[0m[0m[0m
  if (((*(ushort *)(param_6 + local_10fc * 0x18 + 4) & 0x800) == 0) ||
     (iVar3 = iw_get_priv_size(*(undefined2 *)(param_6 + local_10fc * 0x18 + 4)),
     0x10 < iVar3 + local_10f4)) {
    if ((*(short *)(param_6 + local_10fc * 0x18 + 4) == 0) &&
       (((*(ushort *)(param_6 + local_10fc * 0x18 + 6) & 0x800) != 0 &&
        (iVar3 = iw_get_priv_size(*(undefined2 *)(param_6 + local_10fc * 0x18 + 6)), iVar3 < 0x11)))
       ) {
      if (local_10f4 != 0) {
        local_10b8 = local_10f8;
      }
    }
    else {
      local_10b8 = &local_10a8;
      local_10b4 = local_10b4 & 0xffff | (int)local_10f8 << 0x10;
    }
  }
  else {
    if (local_10f4 != 0) {
      local_10b8 = local_10f8;
    }
[32m[32m    memcpy((void *)((int)&local_10b8 + local_10f4),&local_10a8,0x10 - local_10f4);[0m[0m
  }
  iVar3 = ioctl(param_3,*(ulong *)(param_6 + local_10fc * 0x18),acStack_10c8);
  if (((-1 < iVar3) && ((*(ushort *)(param_6 + local_10fc * 0x18 + 6) & 0x7000) != 0)) &&
     ((*(ushort *)(param_6 + local_10fc * 0x18 + 6) & 0x7ff) != 0)) {
    if (((*(ushort *)(param_6 + local_10fc * 0x18 + 6) & 0x800) == 0) ||
       (iVar3 = iw_get_priv_size(*(undefined2 *)(param_6 + local_10fc * 0x18 + 6)), 0x10 < iVar3)) {
      local_10e4 = local_10b4 & 0xffff;
    }
    else {
      local_10a8 = local_10b8;
      local_10a4 = local_10b4;
      local_10a0 = local_10b0;
      local_109c = local_10ac;
      local_10e4 = *(ushort *)(param_6 + local_10fc * 0x18 + 6) & 0x7ff;
    }
    uVar2 = *(ushort *)(param_6 + local_10fc * 0x18 + 6) & 0x7000;
    if (uVar2 == 0x4000) {
      for (local_10e8 = 0; local_10e8 < (int)local_10e4; local_10e8 = local_10e8 + 1) {
        sVar5 = strlen(param_8);
        sVar6 = strlen(param_8);
[32m        snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"%d  ",(&local_10a8)[local_10e8]);[0m
      }
    }
    else {
      if (uVar2 < 0x4001) {
        if (uVar2 == 0x1000) {
          for (local_10e8 = 0; local_10e8 < (int)local_10e4; local_10e8 = local_10e8 + 1) {
            sVar5 = strlen(param_8);
            sVar6 = strlen(param_8);
            snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"%d  ",
[32m                     (uint)*(byte *)((int)&local_10a8 + local_10e8));[0m
          }
          return 0;
        }
        if (uVar2 == 0x2000) {
          *(undefined *)((int)&local_10a8 + local_10e4) = 0;
          sVar5 = strlen(param_8);
          sVar6 = strlen(param_8);
[32m          snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"%s",&local_10a8);[0m
          return 0;
        }
      }
      else {
        if (uVar2 == 0x5000) {
          for (local_10e8 = 0; local_10e8 < (int)local_10e4; local_10e8 = local_10e8 + 1) {
            iw_freq2float(&local_10a8 + local_10e8 * 2);
            CVar8 = __gedf2(param_1,param_2);
            if (CVar8 < 0) {
              CVar8 = __gedf2(param_1,param_2);
              if (CVar8 < 0) {
                sVar5 = strlen(param_8);
                sVar6 = strlen(param_8);
                __divdf3(param_1,param_2);
[32m                snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"%gk  ");[0m
                __divdf3(param_1,param_2);
                printf("%gk  ");
              }
              else {
                sVar5 = strlen(param_8);
                sVar6 = strlen(param_8);
                __divdf3(param_1,param_2);
[32m                snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"%gM  ");[0m
                __divdf3(param_1,param_2);
                printf("%gM  ");
              }
            }
            else {
              sVar5 = strlen(param_8);
              sVar6 = strlen(param_8);
              __divdf3(param_1,param_2);
[32m              snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"%gG  ");[0m
              __divdf3(param_1,param_2);
              printf("%gG  ");
            }
          }
          return 0;
        }
        if (uVar2 == 0x6000) {
          for (local_10e8 = 0; local_10e8 < (int)local_10e4; local_10e8 = local_10e8 + 1) {
            local_10e0 = &local_10a8 + local_10e8 * 4;
            if (local_10e8 != 0) {
              sVar5 = strlen(param_8);
              sVar6 = strlen(param_8);
              sVar9 = strlen(param_5);
              snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"           %.*s",sVar9,
[32m                       "                ");[0m
            }
          }
          sVar5 = strlen(param_8);
          sVar6 = strlen(param_8);
          iw_ether_ntop((int)local_10e0 + 2,auStack_98);
[32m          snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"%s",auStack_98);[0m
          return 0;
        }
      }
      sVar5 = strlen(param_8);
      sVar6 = strlen(param_8);
[32m      snprintf(param_8 + sVar5,(param_9 - sVar6) - 1,"Not yet implemented...\n");[0m
      local_10f0 = 0xffffffff;
    }
  }
  return local_10f0;
}

[ASK_GPT] 44310ae0a9a35dad
