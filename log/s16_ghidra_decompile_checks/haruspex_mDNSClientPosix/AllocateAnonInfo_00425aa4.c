
void ** AllocateAnonInfo(void *param_1,void *param_2,void *param_3,void *param_4)

{
  void **__ptr;
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined2 uVar4;
  char *pcVar5;
  uint uVar6;
  undefined *puVar7;
  undefined *__dest;
  undefined local_d8;
  undefined uStack_d7;
  undefined uStack_d6;
  undefined uStack_d5;
  int local_d4;
  undefined auStack_d0 [160];
  uint local_30;
  
  __ptr = (void **)mDNSPlatformMemAllocate(0x14);
  if (__ptr == (void **)0x0) {
    return (void **)0x0;
  }
  mDNSPlatformMemZero(__ptr,0x14);
  if (param_4 != (void *)0x0) {
    uVar6 = (uint)*(ushort *)((int)param_4 + 0xc);
    if (uVar6 < 0x40) {
      LogMsgWithLevel(0,"CopyNSEC3ResourceRecord: rdlength %d smaller than MCAST_NSEC3_RDLENGTH %d",
                      uVar6,0x40);
    }
    else {
      local_30 = uVar6;
      iVar1 = DomainNameLengthLimit
                        (*(int *)((int)param_4 + 0x1c),*(int *)((int)param_4 + 0x1c) + 0x100);
      iVar3 = 0;
      if (0x108 < iVar1 + local_30) {
        iVar3 = (iVar1 + local_30) - 0x108;
      }
      pvVar2 = mDNSPlatformMemAllocate(iVar3 + 0x138);
      if (pvVar2 != (void *)0x0) {
[32m[32m        memcpy(pvVar2,param_4,0x2c);[0m[0m
        *(undefined2 *)((int)pvVar2 + 0x2c) = *(undefined2 *)((int)param_4 + 0xc);
        mDNSPlatformMemCopy((void *)((int)pvVar2 + 0x30),(void *)(*(int *)((int)param_4 + 0x20) + 4)
                            ,(size_t)*(undefined2 *)((int)param_4 + 0xc));
        puVar7 = (undefined *)
                 ((int)(void *)((int)pvVar2 + 0x30) + (uint)*(ushort *)((int)param_4 + 0xc));
        uVar6 = DomainNameLengthLimit
                          (*(int *)((int)param_4 + 0x1c),*(int *)((int)param_4 + 0x1c) + 0x100);
        if (uVar6 < 0x101) {
          mDNSPlatformMemCopy(puVar7,*(void **)((int)param_4 + 0x1c),uVar6);
        }
        else {
          *puVar7 = 0;
        }
        *(undefined **)((int)pvVar2 + 0x1c) = puVar7;
        *(int *)((int)pvVar2 + 0x20) = (int)pvVar2 + 0x2c;
        __ptr[3] = pvVar2;
        return __ptr;
      }
    }
    goto LAB_00425e74;
  }
  pvVar2 = (void *)mDNSRandom(0xffffffff);
  __ptr[2] = pvVar2;
  pvVar2 = mDNSPlatformMemAllocate((size_t)param_3);
  *__ptr = pvVar2;
  if (pvVar2 == (void *)0x0) goto LAB_00425e74;
  __ptr[1] = param_3;
  mDNSPlatformMemCopy(pvVar2,param_2,(size_t)param_3);
  pvVar2 = __ptr[2];
  iVar3 = DomainNameLengthLimit(param_1,(int)param_1 + 0x100);
  puVar7 = (undefined *)mDNSPlatformMemAllocate(iVar3 + 0x138);
  if (puVar7 != (undefined *)0x0) {
    __dest = puVar7 + 0x2c;
    *puVar7 = 0xa0;
    *(undefined2 *)(puVar7 + 0xe) = 0x40;
    *(undefined4 *)(puVar7 + 0x18) = 0;
    *(undefined2 *)(puVar7 + 2) = 0x32;
    *(undefined2 *)(puVar7 + 4) = 1;
    *(undefined4 *)(puVar7 + 8) = 0x1194;
    *(undefined **)(puVar7 + 0x20) = __dest + iVar3;
    *(undefined **)(puVar7 + 0x1c) = __dest;
    *(undefined4 *)(puVar7 + 0x24) = 0;
    *(undefined2 *)(puVar7 + 0xc) = 0x40;
    uVar6 = DomainNameLengthLimit(param_1,(int)param_1 + 0x100);
    if (uVar6 < 0x101) {
      mDNSPlatformMemCopy(__dest,param_1,uVar6);
    }
    else {
      puVar7[0x2c] = 0;
    }
    iVar1 = *(int *)(puVar7 + 0x20);
    *(undefined *)(iVar1 + 4) = 1;
    *(undefined *)(iVar1 + 5) = 0;
    uVar4 = swap16(1);
    *(undefined *)(iVar1 + 8) = 4;
    *(char *)(iVar1 + 6) = (char)((ushort)uVar4 >> 8);
    *(char *)(iVar1 + 7) = (char)uVar4;
    local_d8 = (undefined)((uint)pvVar2 >> 0x18);
    *(undefined *)(iVar1 + 9) = local_d8;
    uStack_d7 = (undefined)((uint)pvVar2 >> 0x10);
    *(undefined *)(iVar1 + 10) = uStack_d7;
    uStack_d6 = (undefined)((uint)pvVar2 >> 8);
    *(undefined *)(iVar1 + 0xb) = uStack_d6;
    uStack_d5 = SUB41(pvVar2,0);
    *(undefined *)(iVar1 + 0xd) = 0x14;
    *(undefined *)(iVar1 + 0xc) = uStack_d5;
    *(undefined *)(iVar1 + 0x23) = 0x20;
    *(undefined *)(iVar1 + 0x22) = 0;
    mDNSPlatformMemZero(iVar1 + 0x24,0x20);
    *(byte *)(iVar1 + 0x25) = *(byte *)(iVar1 + 0x25) | 8;
    iVar3 = NSEC3HashName(*(undefined4 *)(puVar7 + 0x1c),iVar1 + 4,param_2,param_3,auStack_d0,
                          &local_d4);
    if (iVar3 == 0) {
      local_d4 = *(int *)(puVar7 + 0x1c);
      pcVar5 = "InitializeNSEC3Record: NSEC3HashName failed for ##s";
    }
    else {
      if (local_d4 == 0x14) {
        mDNSPlatformMemCopy((void *)(iVar1 + 0xe),auStack_d0,0x14);
        goto LAB_00425e6c;
      }
      pcVar5 = "InitializeNSEC3Record: hlen wrong %d";
    }
    LogMsgWithLevel(0,pcVar5,local_d4);
    mDNSPlatformMemFree(puVar7);
    puVar7 = (undefined *)0x0;
  }
LAB_00425e6c:
  __ptr[3] = puVar7;
  if (puVar7 != (undefined *)0x0) {
    return __ptr;
  }
LAB_00425e74:
  mDNSPlatformMemFree(__ptr);
  return (void **)0x0;
}

[ASK_GPT] f2078cf366ba7b32
