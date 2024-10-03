
/* WARNING: Removing unreachable block (ram,0x00437f28) */
/* WARNING: Removing unreachable block (ram,0x00437fb8) */
/* WARNING: Removing unreachable block (ram,0x00437ffc) */

undefined4 *
CreateNewCacheEntry(int param_1,int param_2,undefined4 *param_3,undefined4 param_4,char param_5,
                   void *param_6)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  size_t __size;
  undefined *__dest;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *puVar12;
  uint uVar13;
  code *pcVar14;
  
[32m  sVar1 = *(short *)(param_1 + 0x7fae);[0m
  uVar13 = 0x200;
  if (((sVar1 != 0x11) && (uVar13 = 0x202, sVar1 != 0x1a)) && (uVar13 = 0x214, sVar1 != 6)) {
    uVar13 = (uint)*(ushort *)(param_1 + 0x7fb8);
  }
  if (param_3 == (undefined4 *)0x0) {
    uVar3 = DomainNameLengthLimit(*(int *)(param_1 + 0x7fc8),*(int *)(param_1 + 0x7fc8) + 0x100);
    param_3 = (undefined4 *)FUN_0042e568(param_1,0);
    if (param_3 == (undefined4 *)0x0) {
      LogMsgWithLevel(0,"GetCacheGroup: Failed to allocate memory for %##s",
                      *(undefined4 *)(param_1 + 0x7fc8));
      goto LAB_00438224;
    }
    *param_3 = *(undefined4 *)(param_1 + (param_2 + 0xb8) * 4);
    uVar8 = *(undefined4 *)(param_1 + 0x7fbc);
    param_3[3] = param_3 + 2;
    param_3[1] = uVar8;
    param_3[2] = 0;
    if (uVar3 < 0xa5) {
      param_3[4] = param_3 + 5;
    }
    else {
      pvVar4 = mDNSPlatformMemAllocate(uVar3);
      param_3[4] = pvVar4;
    }
    iVar9 = *(int *)(param_1 + 0x7fc8);
    if (param_3[4] != 0) {
      uVar3 = DomainNameLengthLimit(iVar9,iVar9 + 0x100);
      if (uVar3 < 0x101) {
        mDNSPlatformMemCopy((undefined *)param_3[4],*(void **)(param_1 + 0x7fc8),uVar3);
      }
      else {
        *(undefined *)param_3[4] = 0;
      }
      iVar9 = CacheGroupForName(param_1,param_2,*(undefined4 *)(param_1 + 0x7fbc),
                                *(undefined4 *)(param_1 + 0x7fc8));
      if (iVar9 != 0) {
        LogMsgWithLevel(0,"GetCacheGroup: Already have CacheGroup for %##s",
                        *(undefined4 *)(param_1 + 0x7fc8));
      }
      *(undefined4 **)(param_1 + (param_2 + 0xb8) * 4) = param_3;
      puVar5 = (undefined4 *)
               CacheGroupForName(param_1,param_2,*(undefined4 *)(param_1 + 0x7fbc),
                                 *(undefined4 *)(param_1 + 0x7fc8));
      if (param_3 != puVar5) {
        LogMsgWithLevel(0,"GetCacheGroup: Not finding CacheGroup for %##s",
                        *(undefined4 *)(param_1 + 0x7fc8));
      }
      goto LAB_00437d28;
    }
    LogMsgWithLevel(0,"GetCacheGroup: Failed to allocate name storage for %##s",iVar9);
    *param_3 = *(undefined4 *)(param_1 + 0x2dc);
    iVar9 = *(int *)(param_1 + 0x2cc);
    *(undefined4 **)(param_1 + 0x2dc) = param_3;
LAB_00437d80:
    *(int *)(param_1 + 0x2cc) = iVar9 + -1;
    goto LAB_00438224;
  }
LAB_00437d28:
  puVar5 = (undefined4 *)FUN_0042e568(param_1,param_3);
  if (puVar5 == (undefined4 *)0x0) goto LAB_00438224;
  puVar5[9] = puVar5 + 0x1c;
  if (0x44 < uVar13) {
    puVar6 = (undefined2 *)mDNSPlatformMemAllocate(uVar13 + 4);
    puVar5[9] = puVar6;
    if (puVar6 == (undefined2 *)0x0) {
      *puVar5 = *(undefined4 *)(param_1 + 0x2dc);
      iVar9 = *(int *)(param_1 + 0x2cc);
      *(undefined4 **)(param_1 + 0x2dc) = puVar5;
      goto LAB_00437d80;
    }
    *(short *)(puVar5 + 4) = (short)uVar13;
    *puVar6 = (short)uVar13;
  }
  uVar8 = puVar5[9];
[32m[32m  memcpy(puVar5,(void *)(param_1 + 0x7fa8),0xb8);[0m[0m
  puVar5[9] = uVar8;
  puVar5[8] = param_3[4];
  if (*(int *)(param_1 + 0x7fd4) != 0) {
    puVar5[0xb] = *(int *)(param_1 + 0x7fd4);
    *(undefined4 *)(param_1 + 0x7fd4) = 0;
  }
  puVar5[0xe] = param_4;
  if ((undefined4 *)puVar5[9] == puVar5 + 0x1c) {
    if (0x44 < uVar13) {
      LogMsgWithLevel(0,"rr->resrec.rdata == &rr->rdatastorage but length > InlineCacheRDSize %##s",
                      *(undefined4 *)(param_1 + 0x7fc8));
LAB_00438260:
      pcVar14 = mDNSPlatformMemCopy;
      uVar8 = puVar5[9];
      pcVar11 = *(char **)(param_1 + 0x7fcc);
      iVar9 = uVar13 + 4;
      goto LAB_00437df0;
    }
  }
  else {
    if (0x44 < uVar13) goto LAB_00438260;
    uVar8 = 0;
    pcVar14 = LogMsgWithLevel;
    pcVar11 = "rr->resrec.rdata != &rr->rdatastorage but length <= InlineCacheRDSize %##s";
    iVar9 = *(int *)(param_1 + 0x7fc8);
LAB_00437df0:
    (*pcVar14)(uVar8,pcVar11,iVar9);
  }
  *puVar5 = 0;
  puVar5[0x15] = 0;
  puVar5[0x16] = 0;
  if (param_6 != (void *)0x0) {
[32m[32m    memcpy(puVar5 + 0x17,param_6,0x14);[0m[0m
  }
  if (puVar5[7] == 0) {
    *(uint *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) + (uint)*(ushort *)(puVar5 + 4);
[32m    sVar1 = *(short *)((int)puVar5 + 6);[0m
    if ((((ushort)(sVar1 - 0x2eU) < 3) || (sVar1 == 0x2b)) || (sVar1 == 0x32)) {
      BumpDNSSECStats(param_1,0,0,*(undefined2 *)(puVar5 + 4));
    }
  }
  if (param_5 != '\0') {
    *(undefined4 **)param_3[3] = puVar5;
    param_3[3] = puVar5;
    for (puVar12 = *(undefined4 **)(param_1 + 0x2ac);
        (puVar12 != (undefined4 *)0x0 && (puVar12 != *(undefined4 **)(param_1 + 0x2b0)));
        puVar12 = (undefined4 *)*puVar12) {
      iVar9 = ResourceRecordAnswersQuestion(puVar5 + 1,puVar12);
      if (iVar9 != 0) {
        if (((((puVar12[6] != *(int *)(param_1 + 0x26c)) &&
              (puVar12[6] = *(int *)(param_1 + 0x26c), *(short *)((int)puVar12 + 0x152) == 0)) &&
             (0 < (int)puVar12[4])) &&
            ((puVar12[0xf] == 0 && (iVar9 = puVar12[7], puVar12[7] = iVar9 + 1U, 9 < iVar9 + 1U))))
           && ((((mDNSPlatformOneSecond + 2) / 3) * 0x1b < (int)puVar12[4] &&
               (*(int *)(param_1 + 0x234) - puVar12[0x2d] < mDNSPlatformOneSecond)))) {
          uVar8 = DNSTypeName(*(undefined2 *)(puVar12 + 0x95));
          LogMsgWithLevel(0,
                          "CacheRecordAdd: %##s (%s) got immediate answer burst (%d); restarting exponential backoff sequence (%d)"
                          ,puVar12 + 0x55,uVar8,puVar12[7],puVar12[4]);
          iVar10 = mDNSPlatformOneSecond + 2;
          iVar9 = *(int *)(param_1 + 0x234);
          iVar7 = mDNSRandom(mDNSPlatformOneSecond << 2);
          puVar12[3] = (iVar9 - iVar10 / 3) + iVar7;
          puVar12[4] = (mDNSPlatformOneSecond + 2) / 3;
          SetNextQueryTime(param_1,puVar12);
        }
        *(undefined *)(puVar12 + 0x3b) = 0;
        puVar12[8] = puVar12[8] + 1;
        if (0x400 < *(ushort *)(puVar5 + 4)) {
          puVar12[10] = puVar12[10] + 1;
        }
        if ((*(byte *)(puVar5 + 1) & 0x10) != 0) {
          puVar12[0xb] = puVar12[0xb] + 1;
        }
        if (4000 < (uint)puVar12[8]) {
          bVar2 = DAT_0046e818 < 10;
          DAT_0046e818 = DAT_0046e818 + 1;
          if (bVar2) {
            uVar8 = DNSTypeName(*(undefined2 *)(puVar12 + 0x95));
            LogMsgWithLevel(0,
                            "CacheRecordAdd: %##s (%s) has %d answers; shedding records to resist DOS attack"
                            ,puVar12 + 0x55,uVar8,puVar12[8]);
          }
          puVar5[3] = 0;
          *(undefined *)(puVar5 + 0x13) = 4;
        }
      }
    }
    if (puVar5[0xe] == 0) {
      iVar9 = *(int *)(param_1 + 0x2b4);
      if (iVar9 != 0) {
        uVar8 = DNSTypeName(*(undefined2 *)(iVar9 + 0x254));
        LogMsgWithLevel(0,"CacheRecordAdd ERROR m->CurrentQuestion already set: %##s (%s)",
                        iVar9 + 0x154,uVar8);
      }
      *(undefined4 *)(param_1 + 0x2b4) = *(undefined4 *)(param_1 + 0x2ac);
      while ((puVar12 = *(undefined4 **)(param_1 + 0x2b4), puVar12 != (undefined4 *)0x0 &&
             (puVar12 != *(undefined4 **)(param_1 + 0x2b0)))) {
        iVar9 = ResourceRecordAnswersQuestion(puVar5 + 1,puVar12);
        if (iVar9 != 0) {
          FUN_004355d0(param_1,puVar5,1);
        }
        if (*(undefined4 **)(param_1 + 0x2b4) == puVar12) {
          *(undefined4 *)(param_1 + 0x2b4) = *puVar12;
        }
      }
      *(undefined4 *)(param_1 + 0x2b4) = 0;
    }
    FUN_00428c90(param_1,puVar5);
    return puVar5;
  }
[32m  __size = DomainNameLengthLimit(param_3[4],param_3[4] + 0x100);[0m
  __dest = (undefined *)mDNSPlatformMemAllocate(__size);
  if (__dest != (undefined *)0x0) {
    uVar13 = DomainNameLengthLimit(param_3[4],param_3[4] + 0x100);
    if (uVar13 < 0x101) {
      mDNSPlatformMemCopy(__dest,(void *)param_3[4],uVar13);
      puVar5[8] = __dest;
      return puVar5;
    }
    *__dest = 0;
    puVar5[8] = __dest;
    return puVar5;
  }
  ReleaseCacheRecord(param_1,puVar5);
LAB_00438224:
  FUN_00437a18(param_1,param_1 + 0x7fa8);
  return (undefined4 *)0x0;
}

[ASK_GPT] 0a185aa48c7eb327
