
void * get_ifi_info(uint param_1,int param_2)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  char *__ptr;
  int iVar5;
  int *piVar6;
  uint uVar7;
  char *pcVar8;
  void *__dest;
  void *pvVar9;
  size_t __size;
  size_t sVar10;
  char *__s;
  void **ppvVar11;
  void **ppvVar12;
  void *local_80;
  size_t local_7c;
  char *local_78;
  char local_74 [16];
  undefined auStack_64 [16];
  ushort local_54 [10];
  void **local_40;
  undefined4 local_3c;
  int local_38;
  char *local_34;
  void *local_30;
  
  if (param_1 == 10) {
    local_80 = (void *)FUN_004071f8();
  }
  else {
    local_80 = (void *)0x0;
    iVar4 = socket(2,1,0);
    if (iVar4 < 0) {
      __ptr = (char *)0x0;
    }
    else {
[32m      sVar10 = 0;[0m
[32m      __size = 0xc80;[0m
[32m[32m[32m      while (__ptr = (char *)malloc(__size), __ptr != (char *)0x0) {[0m[0m[0m
        local_7c = __size;
        local_78 = __ptr;
[32m        iVar5 = ioctl(iVar4,0x8912,&local_7c);[0m
        if (iVar5 < 0) {
          piVar6 = __errno_location();
          if ((*piVar6 != 0x16) || (sVar10 != 0)) break;
        }
        else {
          bVar1 = local_7c == sVar10;
          sVar10 = local_7c;
          if (bVar1) {
            local_34 = local_74;
            local_80 = (void *)0x0;
            local_74[0] = '\0';
            __s = __ptr;
            ppvVar12 = &local_80;
            goto LAB_00407ba4;
          }
        }
        free(__ptr);
[32m        __size = __size + 0x140;[0m
      }
    }
LAB_00407bc4:
    if (local_80 != (void *)0x0) {
      free_ifi_info();
      local_80 = (void *)0x0;
    }
    if (__ptr != (char *)0x0) {
LAB_00407be8:
      free(__ptr);
    }
    if ((iVar4 != -1) && (iVar4 = close(iVar4), iVar4 != 0)) {
      __assert("junk == 0","mDNSUNP.c",0x1da);
    }
  }
  return local_80;
LAB_00407ba4:
  if (__ptr + local_7c <= __s) goto LAB_00407be8;
  uVar7 = (uint)*(ushort *)(__s + 0x10);
  if ((uVar7 == 2) || (local_38 = 0x2c, uVar7 != 10)) {
    local_38 = 0x20;
  }
  ppvVar11 = ppvVar12;
  if (uVar7 == param_1) {
    pcVar8 = strchr(__s,0x3a);
    if (pcVar8 != (char *)0x0) {
      *pcVar8 = '\0';
    }
    local_3c = 0;
    iVar5 = strncmp(local_34,__s,0x10);
    if (iVar5 == 0) {
      if (param_2 == 0) goto LAB_00407b9c;
      local_3c = 1;
    }
[32m[32m    memcpy(local_34,__s,0x10);[0m[0m
[32m[32m    memcpy(auStack_64,__s,0x20);[0m[0m
    iVar5 = ioctl(iVar4,0x8913,auStack_64);
    uVar3 = local_54[0];
    if (iVar5 < 0) goto LAB_00407bc4;
    if ((local_54[0] & 1) != 0) {
[32m[32m      __dest = calloc(1,0x38);[0m[0m
      if (__dest == (void *)0x0) goto LAB_00407bc4;
      local_40 = (void **)((int)__dest + 0x34);
      local_30 = *ppvVar12;
      *ppvVar12 = __dest;
      *(ushort *)((int)__dest + 0x1a) = uVar3;
      *(short *)((int)__dest + 0x1c) = (short)local_3c;
      uVar7 = if_nametoindex(__s);
      *(uint *)((int)__dest + 0x20) = uVar7;
[32m[32m      memcpy(__dest,__s,0x10);[0m[0m
[32m      sVar2 = *(short *)(__s + 0x10);[0m
      *(undefined *)((int)__dest + 0xf) = 0;
      ppvVar11 = local_40;
      if (sVar2 == 2) {
        if (*(int *)((int)__dest + 0x24) == 0) {
[32m[32m          pvVar9 = calloc(1,0x10);[0m[0m
          *(void **)((int)__dest + 0x24) = pvVar9;
          if (pvVar9 == (void *)0x0) goto LAB_00407bc4;
[32m[32m          memcpy(pvVar9,__s + 0x10,0x10);[0m[0m
          iVar5 = ioctl(iVar4,0x891b,auStack_64);
          if (iVar5 < 0) {
            piVar6 = __errno_location();
            if (*piVar6 != 0x7e) goto LAB_00407bc4;
            free(*(void **)((int)__dest + 0x24));
            free(__dest);
            *ppvVar12 = local_30;
            ppvVar11 = ppvVar12;
          }
          else {
[32m[32m            pvVar9 = calloc(1,0x10);[0m[0m
            *(void **)((int)__dest + 0x28) = pvVar9;
            if (pvVar9 == (void *)0x0) goto LAB_00407bc4;
            local_54[0] = 2;
[32m[32m            memcpy(pvVar9,local_54,0x10);[0m[0m
            if ((uVar3 & 2) != 0) {
              iVar5 = ioctl(iVar4,0x8919,auStack_64);
              if (iVar5 < 0) goto LAB_00407bc4;
              local_54[0] = 2;
[32m[32m              pvVar9 = calloc(1,0x10);[0m[0m
              *(void **)((int)__dest + 0x2c) = pvVar9;
              if (pvVar9 == (void *)0x0) goto LAB_00407bc4;
[32m[32m              memcpy(pvVar9,local_54,0x10);[0m[0m
            }
            ppvVar11 = local_40;
            if ((uVar3 & 0x10) != 0) {
              iVar5 = ioctl(iVar4,0x8917,auStack_64);
              if (iVar5 < 0) goto LAB_00407bc4;
              local_54[0] = 2;
[32m[32m              pvVar9 = calloc(1,0x10);[0m[0m
              *(void **)((int)__dest + 0x30) = pvVar9;
              if (pvVar9 == (void *)0x0) goto LAB_00407bc4;
[32m[32m              memcpy(pvVar9,local_54,0x10);[0m[0m
              ppvVar11 = local_40;
            }
          }
        }
      }
      else if ((sVar2 == 10) && (*(int *)((int)__dest + 0x24) == 0)) {
[32m[32m        pvVar9 = calloc(1,0x1c);[0m[0m
        ppvVar11 = local_40;
        *(void **)((int)__dest + 0x24) = pvVar9;
        if (pvVar9 == (void *)0x0) goto LAB_00407bc4;
        if ((*(uint *)(__s + 0x18) & 0xffc00000) == 0xfe800000) {
          __s[0x1b] = '\0';
          __s[0x1a] = '\0';
        }
[32m[32m        memcpy(*(void **)((int)__dest + 0x24),__s + 0x10,0x1c);[0m[0m
      }
    }
  }
LAB_00407b9c:
  __s = __s + local_38;
  ppvVar12 = ppvVar11;
  goto LAB_00407ba4;
}

[ASK_GPT] 3765ee2ed32ac6b6
