
void * FUN_004071f8(int param_1,int param_2)

{
  char *__s;
  FILE *__stream;
  int iVar1;
  void *__dest;
  void *__dest_00;
  undefined2 *puVar2;
  int *piVar3;
  int iVar4;
  void **ppvVar5;
  void *local_168;
  undefined auStack_164 [4];
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  addrinfo *local_154;
  char acStack_150 [12];
  char local_144 [16];
  addrinfo local_134;
  undefined auStack_114 [16];
  undefined2 local_104;
  undefined auStack_f4 [5];
  undefined auStack_ef [5];
  undefined auStack_ea [5];
  undefined auStack_e5 [5];
  undefined auStack_e0 [5];
  undefined auStack_db [5];
  undefined auStack_d6 [5];
  undefined auStack_d1 [5];
  char acStack_cc [40];
  char acStack_a4 [52];
  undefined *local_70;
  undefined *local_6c;
  undefined *local_68;
  undefined *local_64;
  undefined *local_60;
  undefined *local_5c;
  undefined *local_58;
  char *local_54;
  char *local_50;
  addrinfo *local_4c;
  char *local_48;
  void *local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined *local_34;
  addrinfo **local_30;
  
  local_154 = (addrinfo *)0x0;
  local_168 = (void *)0x0;
  local_144[0] = '\0';
[32m  __stream = fopen("/proc/net/if_inet6","r");[0m
  if (__stream == (FILE *)0x0) {
    return local_168;
  }
  iVar1 = socket(10,1,0);
  if (iVar1 < 0) {
LAB_0040760c:
    if (local_168 != (void *)0x0) {
      free_ifi_info();
      local_168 = (void *)0x0;
    }
    if (local_154 != (addrinfo *)0x0) {
      freeaddrinfo(local_154);
      local_154 = (addrinfo *)0x0;
    }
    if (iVar1 == -1) goto LAB_00407690;
  }
  else {
    local_6c = auStack_ea;
    local_68 = auStack_e5;
    local_64 = auStack_e0;
    local_60 = auStack_db;
    local_5c = auStack_d6;
    local_58 = auStack_d1;
    local_40 = &local_160;
    local_3c = &local_15c;
    local_38 = &local_158;
    local_34 = auStack_164;
    local_54 = local_144;
    local_50 = acStack_cc;
    local_4c = &local_134;
    ppvVar5 = &local_168;
    local_30 = &local_154;
    local_48 = acStack_a4;
    while (iVar4 = fscanf(__stream,"%4s%4s%4s%4s%4s%4s%4s%4s %02x %02x %02x %02x %8s\n",auStack_f4,
                          auStack_ef,local_6c,local_68,local_64,local_60,local_5c,local_58,local_40,
[32m                          local_3c,local_38,local_34,acStack_150), iVar4 != -1) {[0m
      iVar4 = strncmp(local_54,acStack_150,0x10);
      if ((iVar4 != 0) || (param_2 != 0)) {
[32m[32m        memcpy(local_54,acStack_150,0x10);[0m[0m
[32m[32m        __dest = calloc(1,0x38);[0m[0m
        __s = local_50;
        if (__dest == (void *)0x0) goto LAB_0040760c;
        local_44 = *ppvVar5;
        *ppvVar5 = __dest;
        sprintf(__s,"%s:%s:%s:%s:%s:%s:%s:%s",auStack_f4,auStack_ef,local_6c,local_68,local_64,
[32m[32m                local_60,local_5c,local_58);[0m[0m
[32m        memset(local_4c,0,0x20);[0m
        local_134.ai_family = 10;
        local_134.ai_flags = 4;
        iVar4 = getaddrinfo(local_50,(char *)0x0,local_4c,local_30);
        if (iVar4 != 0) goto LAB_0040760c;
[32m[32m        __dest_00 = calloc(1,0x1c);[0m[0m
        *(void **)((int)__dest + 0x24) = __dest_00;
        if (__dest_00 == (void *)0x0) goto LAB_0040760c;
[32m[32m        memcpy(__dest_00,local_154->ai_addr,0x1c);[0m[0m
        FUN_00407108(local_15c,local_48);
[32m[32m        puVar2 = (undefined2 *)calloc(1,0x1c);[0m[0m
        *(undefined2 **)((int)__dest + 0x28) = puVar2;
        if (puVar2 == (undefined2 *)0x0) goto LAB_0040760c;
        local_70 = auStack_114;
        *(undefined4 *)(puVar2 + 0xc) = local_158;
        *puVar2 = (short)param_1;
        inet_pton(param_1,local_48,puVar2 + 4);
[32m[32m        memcpy(__dest,acStack_150,0x10);[0m[0m
        *(undefined4 *)((int)__dest + 0x20) = local_160;
[32m[32m        memcpy(local_70,acStack_150,0x10);[0m[0m
        iVar4 = ioctl(iVar1,0x8913,local_70);
        if (iVar4 < 0) {
          piVar3 = __errno_location();
          if (*piVar3 != 0x7e) goto LAB_0040760c;
          free(*(void **)((int)__dest + 0x24));
          free(*(void **)((int)__dest + 0x28));
          free(__dest);
          *ppvVar5 = local_44;
        }
        else {
          ppvVar5 = (void **)((int)__dest + 0x34);
          *(undefined2 *)((int)__dest + 0x1a) = local_104;
          freeaddrinfo(local_154);
          local_154 = (addrinfo *)0x0;
        }
      }
    }
  }
  iVar1 = close(iVar1);
  if (iVar1 != 0) {
    __assert("close(sockfd) == 0","mDNSUNP.c",0xca);
  }
LAB_00407690:
  fclose(__stream);
  return local_168;
}

[ASK_GPT] 53319ee5285ac7ac
