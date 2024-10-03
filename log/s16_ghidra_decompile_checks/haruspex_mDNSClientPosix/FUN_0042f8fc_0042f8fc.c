
/* WARNING: Removing unreachable block (ram,0x004309f8) */
/* WARNING: Removing unreachable block (ram,0x0042ffd8) */
/* WARNING: Removing unreachable block (ram,0x0042f9d4) */
/* WARNING: Removing unreachable block (ram,0x0042fe10) */
/* WARNING: Removing unreachable block (ram,0x0042fe90) */
/* WARNING: Removing unreachable block (ram,0x004316ac) */
/* WARNING: Removing unreachable block (ram,0x004300c8) */
/* WARNING: Removing unreachable block (ram,0x0042f9f4) */
/* WARNING: Removing unreachable block (ram,0x0043181c) */
/* WARNING: Removing unreachable block (ram,0x00430130) */

void FUN_0042f8fc(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  bool bVar6;
  bool bVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  ushort uVar17;
  uint uVar10;
  int *piVar11;
  uint **ppuVar12;
  int iVar13;
  int iVar14;
  uint **ppuVar15;
  undefined2 uVar18;
  uint **ppuVar16;
  int iVar19;
  undefined4 *puVar20;
  int *piVar21;
  undefined4 *puVar22;
  int *piVar23;
  int *__n;
  int iVar24;
  char *pcVar25;
  uint **ppuVar26;
  int iVar27;
  int iVar28;
  undefined4 uVar29;
  int iVar30;
  uint **in_stack_fffffb98;
  int local_448;
  uint *apuStack_444 [5];
  undefined auStack_430 [48];
  undefined auStack_400 [4];
  undefined auStack_3fc [4];
  undefined2 local_3f8;
  undefined4 local_3f4;
  undefined2 local_3f0;
  undefined2 local_3ee;
  int local_3dc;
  int local_78;
  undefined *local_74;
  undefined4 local_70;
  uint **local_6c;
  int *local_68;
  uint **local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  char *local_30;
  
  local_5c = param_1 + 0x7cc;
  local_4c = param_1;
  puVar8 = (undefined4 *)GetFirstActiveInterface(*(undefined4 *)(param_1 + 0x2174));
  local_448 = 0;
  iVar19 = param_1;
  do {
    for (puVar22 = *(undefined4 **)(iVar19 + 0x2e0); puVar22 != (undefined4 *)0x0;
        puVar22 = (undefined4 *)*puVar22) {
      for (puVar20 = (undefined4 *)puVar22[2]; puVar20 != (undefined4 *)0x0;
          puVar20 = (undefined4 *)*puVar20) {
        iVar28 = puVar20[0x11];
        if ((iVar28 != 0) && (*(byte *)(puVar20 + 0x13) < 4)) {
          iVar27 = *(int *)(param_1 + 0x234);
          iVar13 = puVar20[3] * mDNSPlatformOneSecond;
          if (-1 < (iVar27 - puVar20[0xf]) + iVar13 / 0x32) {
            iVar30 = puVar20[7];
            iVar24 = 0;
            iVar14 = iVar28;
            do {
              iVar24 = iVar24 + 1;
              if ((*(int *)(iVar14 + 0x4c) == iVar30) &&
                 (*(int *)(iVar14 + 0x48) - (iVar27 - iVar13 / 0x14) < 0)) {
                *(undefined4 *)(iVar14 + 0x4c) = 0;
              }
              iVar14 = iVar14 + 0xc;
            } while (iVar24 != 8);
            if (*(int *)(iVar28 + 0x13c) == 0) {
              if (*(short *)(iVar28 + 0x152) == 0) {
                iVar27 = puVar20[7];
                if (*(int *)(iVar28 + 0xa8) == 0) goto LAB_0042fa90;
                if (*(int *)(iVar28 + 0xa8) != iVar27) goto LAB_0042fa8c;
              }
              else {
                *(int *)(iVar28 + 0xc) = *(int *)(param_1 + 0x234) - *(int *)(iVar28 + 0x10);
                *(char *)(puVar20 + 0x13) = *(char *)(puVar20 + 0x13) + '\x01';
                *(int *)(param_1 + 0x39ac) = *(int *)(param_1 + 0x39ac) + 1;
              }
            }
            else {
LAB_0042fa8c:
              iVar27 = -1;
LAB_0042fa90:
              *(int *)(iVar28 + 0xa8) = iVar27;
            }
            if (*(short *)(iVar28 + 0x152) == 0) {
              *(undefined *)(iVar28 + 0xad) = 1;
            }
          }
        }
      }
    }
    iVar19 = iVar19 + 4;
  } while (iVar19 != local_5c);
  iVar19 = *(int *)(param_1 + 0x2b4);
  if (iVar19 != 0) {
    uVar9 = DNSTypeName(*(undefined2 *)(iVar19 + 0x254));
    LogMsgWithLevel(0,"SendQueries ERROR m->CurrentQuestion already set: %##s (%s)",iVar19 + 0x154,
                    uVar9);
  }
  local_6c = (uint **)(param_1 + 0x5cbc);
  local_58 = param_1 + 0x7fa8;
  iVar28 = param_1 + 0x5cb0;
  *(undefined4 *)(param_1 + 0x2b4) = *(undefined4 *)(param_1 + 0x2ac);
  iVar19 = 0;
  while ((puVar22 = *(undefined4 **)(param_1 + 0x2b4), puVar22 != (undefined4 *)0x0 &&
         (puVar22 != *(undefined4 **)(param_1 + 0x2b0)))) {
    iVar27 = iVar19;
    if ((puVar22[0x4f] == 0) ||
       ((puVar22[0x2a] == 0 &&
        ((((int)puVar22[4] < 1 || (puVar22[0xf] != 0)) ||
         ((-puVar22[3] - puVar22[4]) + *(int *)(param_1 + 0x234) < 0)))))) {
      if ((*(short *)((int)puVar22 + 0x152) != 0) ||
         ((puVar22[0x4f] == 0 &&
          (((iVar27 = puVar22[4], iVar27 < 1 || (puVar22[0xf] != 0)) ||
           (((-puVar22[3] - iVar27) + *(int *)(param_1 + 0x234) < 0 ||
            (puVar22[0x2a] = 0xffffffff, iVar27 <= iVar19)))))))) {
        iVar27 = iVar19;
      }
    }
    else {
      iVar19 = puVar22[0x36];
      if (iVar19 == 0) {
        uVar9 = mDNSPlatformUDPSocket(param_1,0);
        puVar22[0x36] = uVar9;
        iVar19 = puVar22[0x36];
      }
      if (iVar19 != 0) {
        InitializeDNSMessage(iVar28,(uint)*(ushort *)((int)puVar22 + 0x152) << 0x10,0);
        uVar9 = putQuestion(iVar28,local_6c,local_58,puVar22 + 0x55,*(undefined2 *)(puVar22 + 0x95),
                            *(undefined2 *)((int)puVar22 + 0x256));
        in_stack_fffffb98 =
             (uint **)((uint)in_stack_fffffb98 & 0xffff | (uint)*(ushort *)(puVar22 + 0x54) << 0x10)
        ;
        mDNSSendDNSMessage(param_1,iVar28,uVar9,0,puVar22[0x36],puVar22 + 0x4f,in_stack_fffffb98,0,0
                           ,*(undefined *)((int)puVar22 + 0x262));
        puVar22[4] = puVar22[4] * 3;
      }
      if ((int)(mDNSPlatformOneSecond * 0xe10) < (int)puVar22[4]) {
        puVar22[4] = mDNSPlatformOneSecond * 0xe10;
      }
      puVar22[3] = *(undefined4 *)(param_1 + 0x234);
      uVar9 = *(undefined4 *)(param_1 + 0x234);
      puVar22[7] = 0;
      puVar22[0x2d] = uVar9;
      puVar22[0x2a] = 0;
      iVar19 = *(int *)(param_1 + 0x234);
      if (iVar19 == 0) {
        iVar19 = 1;
      }
      puVar22[5] = iVar19;
    }
    iVar19 = iVar27;
    if (puVar22 == *(undefined4 **)(param_1 + 0x2b4)) {
      *(undefined4 *)(param_1 + 0x2b4) = *puVar22;
    }
  }
  while (iVar27 = *(int *)(param_1 + 0x2b4), iVar27 != 0) {
    if (mDNS_LoggingEnabled != 0) {
      uVar9 = DNSTypeName(*(undefined2 *)(iVar27 + 0x254));
      LogMsgWithLevel(3,"SendQueries question loop 1: Skipping NewQuestion %##s (%s)",iVar27 + 0x154
                      ,uVar9);
    }
    *(undefined4 *)(param_1 + 0x2b4) = **(undefined4 **)(param_1 + 0x2b4);
  }
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  *(int *)(param_1 + 0x24c) = *(int *)(param_1 + 0x234) + 0x78000000;
  for (puVar22 = *(undefined4 **)(param_1 + 0x2ac);
      (puVar22 != (undefined4 *)0x0 && (puVar22 != *(undefined4 **)(param_1 + 0x2b0)));
      puVar22 = (undefined4 *)*puVar22) {
    if (*(short *)((int)puVar22 + 0x152) == 0) {
      if (puVar22[0x2a] == 0) {
        if ((((puVar22[0x4f] == 0) && (iVar27 = puVar22[4], 0 < iVar27)) && (puVar22[0xf] == 0)) &&
           (iVar27 <= iVar19)) {
          if (-1 < (iVar27 / 10 + *(int *)(param_1 + 0x234)) - (iVar27 + puVar22[3]))
          goto LAB_0042ff68;
          if (-1 < (iVar27 / 2 + *(int *)(param_1 + 0x234)) - (iVar27 + puVar22[3])) {
            puVar20 = (undefined4 *)0x0;
            local_34 = puVar22 + 0x55;
            local_30 = (char *)DomainNameLengthLimit(puVar22 + 0x55,puVar22 + 0x95);
            uVar10 = DomainNameHashValue(local_34);
            iVar27 = CacheGroupForName(param_1,uVar10 % 499,puVar22[1],local_34);
            if (iVar27 != 0) {
              puVar20 = *(undefined4 **)(iVar27 + 8);
            }
            ppuVar16 = (uint **)((int)local_30 + 4);
            for (; puVar20 != (undefined4 *)0x0; puVar20 = (undefined4 *)*puVar20) {
              if (((*(ushort *)(puVar20 + 4) < 0x401) &&
                  (local_30 = (char *)ppuVar16,
                  iVar27 = SameNameRecordAnswersQuestion(puVar20 + 1,puVar22),
                  ppuVar16 = (uint **)local_30, iVar27 != 0)) &&
                 ((-1 < (puVar20[0xd] - *(int *)(param_1 + 0x234)) +
                        (int)(puVar20[3] * mDNSPlatformOneSecond) / 2 &&
                  ((0 < (-*(int *)(param_1 + 0x234) - puVar22[4]) + puVar20[0xf] &&
                   (ppuVar16 = (uint **)((int)local_30 + *(ushort *)((int)puVar20 + 0x12) + 0xc),
                   (uint **)0x1ff < ppuVar16)))))) goto LAB_00430230;
            }
            goto LAB_0042ff64;
          }
        }
      }
      else {
LAB_0042ff64:
        iVar27 = puVar22[4];
LAB_0042ff68:
        if (-1 < (*(int *)(param_1 + 0x234) - puVar22[3]) - iVar27 / 2) {
          if ((((puVar22[9] == 0) || ((uint)puVar22[8] < (uint)puVar22[9])) ||
              (*(char *)((int)puVar22 + 0xad) != '\0')) ||
             (((puVar22[0x4e] & 0x4000000) != 0 && (iVar27 == (int)(mDNSPlatformOneSecond + 2) / 3))
             )) {
            puVar22[0x2a] = 0xffffffff;
            puVar22[4] = puVar22[4] * 3;
          }
          else {
            puVar22[0x2a] = 0;
            puVar22[4] = mDNSPlatformOneSecond * 0xe10;
            uVar9 = *(undefined4 *)(param_1 + 0x234);
            puVar22[0x2c] = 0;
            puVar22[3] = uVar9;
            if (mDNS_LoggingEnabled != 0) {
              uVar9 = DNSTypeName(*(undefined2 *)(puVar22 + 0x95));
              LogMsgWithLevel(3,"SendQueries: (%s) %##s reached threshold of %d answers",uVar9,
                              puVar22 + 0x55,puVar22[9]);
            }
          }
          if ((int)puVar22[4] < (int)(mDNSPlatformOneSecond * 0x1b)) {
            if (((puVar22[8] == 0) && (puVar22[4] == ((int)(mDNSPlatformOneSecond + 2) / 3) * 0x1b))
               && (puVar22[0x2c] == 0)) {
              if ((*(short *)(puVar22 + 0x95) == 1) || (*(short *)(puVar22 + 0x95) == 0x1c)) {
                local_3c = (int *)puVar22[1];
                local_34 = puVar22 + 0x55;
                uVar10 = DomainNameHashValue(local_34);
                iVar27 = CacheGroupForName(param_1,uVar10 % 499,local_3c,local_34);
                puVar20 = (undefined4 *)0x0;
                if (iVar27 != 0) {
                  puVar20 = *(undefined4 **)(iVar27 + 8);
                }
                for (; puVar20 != (undefined4 *)0x0; puVar20 = (undefined4 *)*puVar20) {
                  if ((*(short *)((int)puVar20 + 6) == 1) || (*(short *)((int)puVar20 + 6) == 0x1c))
                  goto LAB_00430194;
                }
              }
              FUN_00429428(param_1,puVar22 + 0x55,puVar22[1],0);
            }
          }
          else {
            puVar22[4] = mDNSPlatformOneSecond * 0xe10;
          }
        }
LAB_00430194:
        *(bool *)(puVar22 + 0x2b) = puVar22[0x2a] == -1;
        if (puVar22[0x2a] == -1) {
          iVar27 = 0;
          if ((puVar8 != (undefined4 *)0x0) && (iVar27 = puVar22[0x4d], iVar27 == 0)) {
            iVar27 = puVar8[0x548];
          }
          puVar22[0x2a] = iVar27;
          puVar22[3] = *(undefined4 *)(param_1 + 0x234);
        }
        iVar13 = puVar22[4];
        iVar27 = 0;
        iVar14 = *(int *)(param_1 + 0x234);
        puVar20 = puVar22;
        do {
          iVar27 = iVar27 + 1;
          if (puVar20[0x12] - (iVar14 - iVar13 / 2) < 0) {
            puVar20[0x13] = 0;
          }
          puVar20 = puVar20 + 3;
        } while (iVar27 != 8);
        puVar22[0x2d] = *(undefined4 *)(param_1 + 0x234);
        puVar22[7] = 0;
        if (puVar22[0x2c] != 0) {
          puVar22[0x2c] = puVar22[0x2c] + -1;
        }
      }
    }
LAB_00430230:
    SetNextQueryTime(param_1,puVar22);
  }
  iVar19 = *(int *)(param_1 + 0x216c);
  *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x234) + 0x78000000;
  if (iVar19 != 0) {
    uVar9 = GetRRDisplayString_rdb(iVar19 + 4,*(int *)(iVar19 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,"SendQueries ERROR m->CurrentRecord already set %s",uVar9);
  }
  local_78 = param_1 + 0x2f;
  *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(param_1 + 0x2160);
LAB_004306bc:
  puVar22 = *(undefined4 **)(param_1 + 0x216c);
  if (puVar22 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x216c) = *puVar22;
    if ((((puVar22[7] != 0) || (*(char *)((int)puVar22 + 0x4a) != '\0')) ||
        (iVar19 = IsLocalDomain(puVar22[8]), iVar19 != 0)) && (*(char *)(puVar22 + 1) == '\x02')) {
      if (-1 < (-puVar22[0x30] - puVar22[0x2f]) + *(int *)(param_1 + 0x234)) {
        ppuVar16 = (uint **)(uint)*(byte *)((int)puVar22 + 0x86);
        if (ppuVar16 != (uint **)0x0) {
          if (puVar22[0x18] == 4) {
            if (mDNS_LoggingEnabled != 0) {
              for (puVar20 = *(undefined4 **)(param_1 + 0x2174); puVar20 != (undefined4 *)0x0;
                  puVar20 = (undefined4 *)*puVar20) {
                if (puVar20[0x548] == puVar22[7]) {
                  local_34 = (int *)((int)puVar20 + 0x1552);
                  goto LAB_00430394;
                }
              }
              local_34 = (int *)0x0;
LAB_00430394:
              local_30 = (char *)ppuVar16;
              uVar9 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,local_78);
              LogMsgWithLevel(2,"SendQueries ARP Probe %d %s %s",local_30,local_34,uVar9);
            }
            in_stack_fffffb98 = (uint **)(puVar22 + 0x15);
            FUN_004296e0(param_1,1,puVar22,&zerov4Addr,&zeroEthAddr,puVar22 + 0x19,in_stack_fffffb98
                        );
          }
          else if (puVar22[0x18] == 6) {
            if (mDNS_LoggingEnabled != 0) {
              for (puVar20 = *(undefined4 **)(param_1 + 0x2174); puVar20 != (undefined4 *)0x0;
                  puVar20 = (undefined4 *)*puVar20) {
                if (puVar20[0x548] == puVar22[7]) {
                  local_34 = (int *)((int)puVar20 + 0x1552);
                  goto LAB_0043045c;
                }
              }
              local_34 = (int *)0x0;
LAB_0043045c:
              local_30 = (char *)ppuVar16;
              uVar9 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,local_78);
              LogMsgWithLevel(2,"SendQueries NDP Probe %d %s %s",local_30,local_34,uVar9);
            }
            in_stack_fffffb98 = (uint **)(puVar22 + 0x19);
            FUN_0042989c(param_1,0x87,0,puVar22,zerov6Addr,0,in_stack_fffffb98,puVar22 + 0x15);
          }
          iVar19 = 0;
          if (((puVar8 == (undefined4 *)0x0) || (iVar19 = 0, *(int *)((int)puVar22 + 0x4e) != 0)) ||
             (iVar19 = puVar22[7], iVar19 != 0)) {
            puVar22[0x26] = iVar19;
          }
          else {
            puVar22[0x26] = puVar8[0x548];
          }
          puVar22[0x30] = *(undefined4 *)(param_1 + 0x234);
          if (3 < *(byte *)((int)puVar22 + 0x86)) {
            *(undefined *)((int)puVar22 + 0x86) = 3;
          }
          *(char *)((int)puVar22 + 0x86) = *(char *)((int)puVar22 + 0x86) + -1;
          FUN_00426db0(param_1,puVar22);
          if (*(char *)((int)puVar22 + 0x86) == '\0') {
            for (ppuVar16 = *(uint ***)(param_1 + 0x2164); ppuVar16 != (uint **)0x0;
                ppuVar16 = (uint **)*ppuVar16) {
              if ((*(char *)(ppuVar16 + 1) == '\x02') && (ppuVar16[7] == (uint *)puVar22[7])) {
                bVar1 = *(byte *)(puVar22 + 1);
                if ((((bVar1 == 2) || (((bVar1 | 2) == 0x12 || (bVar1 == 1)))) &&
                    (*(short *)((int)ppuVar16 + 6) == *(short *)((int)puVar22 + 6))) &&
                   (((((*(short *)(ppuVar16 + 2) == *(short *)(puVar22 + 2) &&
                       (ppuVar16[5] == (uint *)puVar22[5])) &&
                      (*(short *)(ppuVar16 + 4) == *(short *)(puVar22 + 4))) &&
                     ((ppuVar16[6] == (uint *)puVar22[6] &&
                      (local_30 = (char *)ppuVar16,
                      iVar19 = SameRDataBody(ppuVar16 + 1,puVar22[9] + 4,SameDomainName),
                      ppuVar16 = (uint **)local_30, iVar19 != 0)))) &&
                    (iVar19 = SameDomainName(*(uint **)((int)local_30 + 0x20),puVar22[8]),
                    ppuVar16 = (uint **)local_30, iVar19 != 0)))) {
                  *(char *)((int)local_30 + 0x86) = '\0';
                }
              }
            }
            if (*(char *)(puVar22 + 0x21) == '\0') {
              FUN_00426c2c(param_1,puVar22);
            }
          }
          goto LAB_004306bc;
        }
        if (*(char *)(puVar22 + 0x21) == '\0') {
          FUN_00426c2c(param_1,puVar22);
        }
        *(undefined *)(puVar22 + 1) = 0x10;
        puVar22[0x2f] = (int)mDNSPlatformOneSecond / 2;
        puVar22[0x30] = *(int *)(param_1 + 0x234) - (int)mDNSPlatformOneSecond / 2;
      }
      FUN_00426db0(param_1,puVar22);
    }
    goto LAB_004306bc;
  }
  *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(param_1 + 0x2164);
  while( true ) {
    puVar22 = *(undefined4 **)(param_1 + 0x216c);
    local_64 = (uint **)(param_1 + 0x625c);
    if (puVar22 == (undefined4 *)0x0) break;
    *(undefined4 *)(param_1 + 0x216c) = *puVar22;
    if ((*(char *)(puVar22 + 1) == '\x02') && ((puVar22[0x21] & 0xff00ff00) == 0)) {
      FUN_00426c2c(param_1);
    }
  }
  local_44 = param_1 + 0x5cb6;
  local_54 = param_1 + 0x5cb8;
  local_48 = param_1 + 0x5cba;
  local_60 = 0;
LAB_00431718:
  do {
    iVar19 = local_78;
    if (puVar8 == (undefined4 *)0x0) goto LAB_00431724;
    iVar19 = 0;
    if (((*(int *)(param_1 + 0x27c) != 0) && (puVar8[0x553] != 0)) &&
       ((iVar19 = 0x1d, *(int *)(param_1 + 0x14) == puVar8[0x553] &&
        (iVar19 = 0x17, *(short *)(param_1 + 0x18) != *(short *)(puVar8 + 0x554))))) {
      iVar19 = 0x1d;
    }
    iVar27 = 0x14;
    if (mDNS_McastTracingEnabled == 0) {
      iVar27 = 0;
    }
    InitializeDNSMessage(iVar28,0,0);
    ppuVar16 = local_6c;
    if (local_448 == 0) {
      puVar22 = *(undefined4 **)(param_1 + 0x2ac);
      local_70 = 0;
      ppuVar15 = (uint **)(iVar27 + iVar19);
      local_68 = &local_448;
      local_40 = iVar27;
      for (; (iVar27 = local_40, puVar22 != (undefined4 *)0x0 &&
             (puVar22 != *(undefined4 **)(param_1 + 0x2b0))); puVar22 = (undefined4 *)*puVar22) {
        ppuVar12 = ppuVar15;
        if ((*(short *)((int)puVar22 + 0x152) == 0) && (puVar22[0x2a] == puVar8[0x548])) {
          iVar27 = mDNSPlatformValidQuestionForInterface(puVar22,puVar8);
          if (iVar27 == 0) {
            if (mDNS_LoggingEnabled != 0) {
              uVar9 = DNSTypeName(*(undefined2 *)(puVar22 + 0x95));
              for (puVar20 = *(undefined4 **)(param_1 + 0x2174); puVar20 != (undefined4 *)0x0;
                  puVar20 = (undefined4 *)*puVar20) {
                if (puVar20[0x548] == puVar8[0x548]) {
                  iVar27 = (int)puVar20 + 0x1552;
                  goto LAB_00430878;
                }
              }
              iVar27 = 0;
LAB_00430878:
              LogMsgWithLevel(3,"SendQueries: Not sending (%s) %##s on %s",uVar9,puVar22 + 0x55,
                              iVar27);
            }
            if ((puVar22[0x4d] == 0) && (*(char *)(puVar22 + 0x2b) != '\0')) {
              uVar9 = GetNextActiveInterfaceID(puVar8);
              puVar22[0x2a] = uVar9;
            }
            else {
              puVar22[0x2a] = 0;
            }
          }
          else {
            iVar27 = 0;
            bVar7 = *(char *)((int)puVar8 + 5) == '\0';
            bVar6 = *(char *)((int)puVar8 + 6) == '\0';
            puVar20 = puVar22;
            do {
              iVar27 = iVar27 + 1;
              if (puVar20[0x13] == puVar8[0x548]) {
                if (puVar20[0x14] != 4) {
                  if (puVar20[0x14] == 6) {
                    bVar6 = true;
                  }
                  if (!bVar7) goto LAB_00430920;
                }
                bVar7 = true;
                if (bVar6) {
                  *(int *)(param_1 + 0x396c) = *(int *)(param_1 + 0x396c) + 1;
                  ppuVar26 = ppuVar16;
                  goto LAB_00430c38;
                }
              }
LAB_00430920:
              puVar20 = puVar20 + 3;
            } while (iVar27 != 8);
            if (((puVar22[10] == 0) && (puVar22[0x2c] == 0)) ||
               (uVar17 = 0x8000, *(char *)(param_1 + 8) == '\0')) {
              local_74 = (undefined *)0x0;
              uVar17 = 0;
            }
            else {
              local_74 = (undefined *)(uint)(*(char *)((int)puVar8 + 0x1599) != '\0');
              if (local_74 == (undefined *)0x0) {
                uVar17 = 0;
              }
            }
            local_30 = (char *)0x0;
            if (puVar22[0x11] != 0) {
              local_30 = (char *)(*(ushort *)(*(int *)(puVar22[0x11] + 0xc) + 0xc) + 0xc & 0xff);
            }
            local_38 = puVar22 + 0x55;
            ppuVar26 = (uint **)putQuestion(iVar28,ppuVar16,
                                            (char *)((int)local_64 +
                                                    (-(int)ppuVar15 - (int)local_30)),local_38,
                                            *(undefined2 *)(puVar22 + 0x95),
                                            uVar17 | *(ushort *)((int)puVar22 + 0x256));
            if (ppuVar26 != (uint **)0x0) {
              puVar20 = (undefined4 *)0x0;
              uVar10 = DomainNameHashValue(local_38);
              piVar11 = (int *)CacheGroupForName(param_1,uVar10 % 499,puVar22[1],local_38);
              if (piVar11 != (int *)0x0) {
                puVar20 = (undefined4 *)piVar11[2];
              }
              ppuVar12 = (uint **)((int)local_30 + (int)ppuVar15);
              piVar21 = local_68;
LAB_00430b64:
              if (puVar20 != (undefined4 *)0x0) {
                if (((((puVar20[7] != puVar22[0x2a]) || ((*(byte *)(puVar20 + 1) & 0x32) != 0)) ||
                     ((puVar20[0xc] != 0 ||
                      ((piVar21 == puVar20 + 0xc || (0x400 < *(ushort *)(puVar20 + 4))))))) ||
                    (local_3c = piVar21, local_38 = puVar20 + 0xc, local_34 = piVar11,
                    local_30 = (char *)ppuVar12,
                    iVar27 = SameNameRecordAnswersQuestion(puVar20 + 1,puVar22),
                    ppuVar12 = (uint **)local_30, piVar11 = local_34, piVar23 = local_38,
                    piVar21 = local_3c, iVar27 == 0)) ||
                   ((puVar20[0xd] - *(int *)(param_1 + 0x234)) +
                    (int)(mDNSPlatformOneSecond * puVar20[3]) / 2 <= (int)mDNSPlatformOneSecond))
                goto LAB_00430b5c;
                *local_3c = (int)puVar20;
                ppuVar12 = (uint **)((int)ppuVar12 + *(ushort *)((int)puVar20 + 0x12) + 0xc);
                piVar21 = piVar23;
                if ((*(ushort *)(param_1 + 0x5cb4) < 2) ||
                   ((uint **)((int)ppuVar26 + (int)ppuVar12) < local_64)) goto LAB_00430b5c;
                *(short *)(param_1 + 0x5cb4) = *(short *)(param_1 + 0x5cb4) + -1;
                piVar11 = local_68;
                while (iVar27 = *piVar11, ppuVar12 = ppuVar15, iVar27 != 0) {
                  *piVar11 = 0;
                  piVar11 = (int *)(iVar27 + 0x30);
                }
                goto LAB_00430e74;
              }
              if (local_74 != (undefined *)0x0) {
                iVar27 = *(int *)(param_1 + 0x234);
                if (iVar27 == 0) {
                  iVar27 = 1;
                }
                puVar22[5] = iVar27;
              }
              if (piVar11 != (int *)0x0) {
                puVar20 = (undefined4 *)piVar11[2];
              }
              for (; puVar20 != (undefined4 *)0x0; puVar20 = (undefined4 *)*puVar20) {
                if ((((puVar20[7] == puVar22[0x2a]) && (puVar20[0xc] == 0)) &&
                    (piVar21 != puVar20 + 0xc)) &&
                   (local_30 = (char *)ppuVar12,
                   iVar27 = SameNameRecordAnswersQuestion(puVar20 + 1,puVar22),
                   ppuVar12 = (uint **)local_30, iVar27 != 0)) {
                  *(char *)(puVar20 + 0x13) = *(char *)(puVar20 + 0x13) + '\x01';
                  puVar20[0x12] = *(undefined4 *)(param_1 + 0x234);
                  FUN_00428c90(param_1,puVar20);
                  ppuVar12 = (uint **)local_30;
                }
              }
              local_68 = piVar21;
              if (puVar22[0x11] != 0) {
                *(undefined4 *)(puVar22[0x11] + 0x10) = puVar8[0x548];
              }
LAB_00430c38:
              uVar9 = 0;
              if (puVar22[0x4d] == 0) {
                if (*(char *)(puVar22 + 0x2b) == '\0') {
                  uVar9 = 0;
                }
                else {
                  uVar9 = GetNextActiveInterfaceID(puVar8);
                }
              }
              puVar22[0x2a] = uVar9;
              if (*(char *)((int)puVar22 + 0xbe) != '\0') {
                piVar11 = (int *)puVar22[0x4d];
                if (((piVar11 == (int *)0x0) || (piVar11 == (int *)&SUB_fffffffe)) ||
                   (piVar11 == (int *)0xfffffffc)) {
                  pcVar25 = 
                  "mDNSSendWakeOnResolve: ERROR!! Invalid InterfaceID %p for question %##s";
                  piVar23 = puVar22 + 0x55;
                  piVar21 = piVar11;
LAB_00430d24:
                  LogMsgWithLevel(0,pcVar25,piVar21,piVar23);
                }
                else {
                  piVar23 = (int *)0x0;
                  for (iVar27 = 1; iVar27 < (int)(uint)*(byte *)(puVar22 + 0x55);
                      iVar27 = iVar27 + 1) {
[32m                    cVar2 = *(char *)((int)puVar22 + iVar27 + 0x154);[0m
                    if (cVar2 == '@') {
                      if (piVar23 == (int *)0x5) {
                        __n = (int *)(iVar27 + -1);
                        piVar23 = (int *)((uint)*(byte *)(puVar22 + 0x55) - iVar27);
                        if ((int)__n < 0x12) {
                          piVar21 = puVar22 + 0x55;
                          if (0x2e < (int)piVar23) {
                            pcVar25 = 
                            "mDNSSendWakeOnResolve: ERROR!! Malformed IP address %##s, length %d";
                            goto LAB_00430d24;
                          }
                          local_30 = (char *)apuStack_444;
                          local_50 = &local_448;
                          local_74 = auStack_430;
                          local_3c = piVar23;
                          local_38 = piVar21;
                          local_34 = __n;
                          mDNSPlatformMemCopy(local_30,(void *)((int)puVar22 + 0x155),(size_t)__n);
                          *(undefined *)((int)local_50 + (int)local_34 + 4) = 0;
                          mDNSPlatformMemCopy(local_74,(void *)((int)local_38 + iVar27 + 1),
                                              (size_t)local_3c);
                          iVar27 = *(int *)(param_1 + 0x39b4);
                          *(undefined *)((int)local_50 + (int)local_3c + 0x18) = 0;
                          *(int *)(param_1 + 0x39b4) = iVar27 + 1;
                          mDNSPlatformSendWakeupPacket
                                    (param_1,piVar11,local_30,local_74,
                                     3 - (uint)*(byte *)((int)puVar22 + 0xbe));
                          goto LAB_00430e50;
                        }
                        pcVar25 = 
                        "mDNSSendWakeOnResolve: ERROR!! Malformed Ethernet address %##s, length %d";
                        piVar23 = __n;
                      }
                      else {
                        pcVar25 = 
                        "mDNSSendWakeOnResolve: ERROR!! Malformed Ethernet address %##s, cnt %d";
                      }
                      piVar21 = puVar22 + 0x55;
                      goto LAB_00430d24;
                    }
                    piVar23 = (int *)((int)piVar23 + (uint)(cVar2 == ':'));
                  }
                  LogMsgWithLevel(0,
                                  "mDNSSendWakeOnResolve: ERROR!! Malformed WakeOnResolve name %##s"
                                  ,puVar22 + 0x55);
                }
LAB_00430e50:
                *(char *)((int)puVar22 + 0xbe) = *(char *)((int)puVar22 + 0xbe) + -1;
              }
              ppuVar16 = ppuVar26;
              if (*(char *)((int)puVar22 + 0x262) != '\0') {
                local_70 = 1;
              }
            }
          }
        }
LAB_00430e74:
        ppuVar15 = ppuVar12;
      }
      for (puVar22 = *(undefined4 **)(param_1 + 0x2160); puVar22 != (undefined4 *)0x0;
          puVar22 = (undefined4 *)*puVar22) {
        if (puVar22[0x26] == puVar8[0x548]) {
          bVar7 = false;
          if (1 < *(byte *)((int)puVar22 + 0x86)) {
            if (*(char *)(param_1 + 8) == '\0') {
              bVar7 = false;
            }
            else {
              bVar7 = *(char *)((int)puVar8 + 0x1599) != '\0';
            }
          }
          iVar13 = 0x22ec;
          if (*(short *)(param_1 + 0x5cb4) != 0) {
            iVar13 = 0x5a0;
          }
          uVar17 = 0x8000;
          if (!bVar7) {
            uVar17 = 0;
          }
          ppuVar26 = (uint **)(*(ushort *)((int)puVar22 + 0x12) + 0xc + (int)ppuVar15);
          ppuVar12 = (uint **)putQuestion(iVar28,ppuVar16,
                                          (param_1 + iVar13 + 0x5cbc) - (int)ppuVar26,puVar22[8],
                                          0xff,uVar17 | *(ushort *)(puVar22 + 2));
          if (ppuVar12 != (uint **)0x0) {
            uVar9 = 0;
            ppuVar16 = ppuVar12;
            if (puVar22[7] == 0) {
              local_30 = (char *)ppuVar12;
              uVar9 = GetNextActiveInterfaceID(puVar8);
              ppuVar16 = (uint **)local_30;
            }
            puVar22[0x26] = uVar9;
            *(undefined *)((int)puVar22 + 0x8a) = 1;
            ppuVar15 = ppuVar26;
          }
        }
      }
    }
    else {
      local_70 = 0;
    }
    while (iVar13 = local_448, local_448 != 0) {
      if (mDNSPlatformOneSecond == 0) {
        trap(0x1c00);
      }
      ppuVar15 = (uint **)PutResourceRecordTTLWithLimit
                                    (iVar28,ppuVar16,local_44,local_448 + 4,
                                     *(int *)(local_448 + 0xc) -
                                     (uint)(*(int *)(param_1 + 0x234) - *(int *)(local_448 + 0x34))
                                     / mDNSPlatformOneSecond,((param_1 - iVar27) - iVar19) + 0x625c)
      ;
      if (ppuVar15 == (uint **)0x0) {
        if (1 < *(ushort *)(param_1 + 0x5cb4)) {
          LogMsgWithLevel(0,"SendQueries:   Put %d answers; No more space for known answers",
                          *(undefined2 *)(param_1 + 0x5cb6));
        }
        *(byte *)(param_1 + 0x5cb2) = *(byte *)(param_1 + 0x5cb2) | 2;
        break;
      }
      local_448 = *(int *)(iVar13 + 0x30);
      *(undefined4 *)(iVar13 + 0x30) = 0;
      ppuVar16 = ppuVar15;
    }
    for (puVar22 = *(undefined4 **)(param_1 + 0x2160); puVar22 != (undefined4 *)0x0;
        puVar22 = (undefined4 *)*puVar22) {
      ppuVar15 = ppuVar16;
      if (*(char *)((int)puVar22 + 0x8a) != '\0') {
        iVar13 = 0x22ec;
        if ((*(short *)(param_1 + 0x5cb6) != 0) || (*(int *)(param_1 + 0x5cb8) != 0)) {
          iVar13 = 0x5a0;
        }
        ppuVar15 = (uint **)PutResourceRecordTTLWithLimit
                                      (iVar28,ppuVar16,local_54,puVar22 + 1,puVar22[3],
                                       param_1 + iVar13 + 0x5cbc);
        *(undefined *)((int)puVar22 + 0x8a) = 0;
        if (ppuVar15 == (uint **)0x0) {
          uVar9 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,local_78);
          LogMsgWithLevel(0,"SendQueries:   How did we fail to have space for the Update record %s",
                          uVar9);
          ppuVar15 = ppuVar16;
        }
      }
      ppuVar16 = ppuVar15;
    }
    for (puVar22 = *(undefined4 **)(param_1 + 0x2ac); puVar22 != (undefined4 *)0x0;
        puVar22 = (undefined4 *)*puVar22) {
      iVar13 = puVar22[0x11];
      ppuVar15 = ppuVar16;
      if ((iVar13 != 0) && (*(int *)(iVar13 + 0x10) == puVar8[0x548])) {
        iVar14 = 0x5a0;
        if ((*(short *)(param_1 + 0x5cb6) == 0) &&
           (iVar14 = 0x22ec, *(int *)(param_1 + 0x5cb8) != 0)) {
          iVar14 = 0x5a0;
        }
        ppuVar15 = (uint **)PutResourceRecordTTLWithLimit
                                      (iVar28,ppuVar16,local_54,*(int *)(iVar13 + 0xc),
                                       *(undefined4 *)(*(int *)(iVar13 + 0xc) + 8),
                                       param_1 + iVar14 + 0x5cbc);
        if (ppuVar15 == (uint **)0x0) {
          uVar9 = GetRRDisplayString_rdb
                            (*(int *)(puVar22[0x11] + 0xc),
                             *(int *)(*(int *)(puVar22[0x11] + 0xc) + 0x20) + 4,local_78);
          LogMsgWithLevel(0,"SendQueries: ERROR!! Cannot add NSEC3 record %s on InterfaceID %p",
                          uVar9,puVar8[0x548]);
          ppuVar15 = ppuVar16;
        }
        *(undefined4 *)(puVar22[0x11] + 0x10) = 0;
      }
      ppuVar16 = ppuVar15;
    }
    if (ppuVar16 <= local_6c) {
      puVar8 = (undefined4 *)GetFirstActiveInterface(*puVar8);
      goto LAB_00431718;
    }
    if ((iVar27 != 0) || (iVar19 != 0)) {
      in_stack_fffffb98 = (uint **)0x0;
      mDNS_SetupResourceRecord(auStack_400,0,0,0x29,0x1194,0x20,0,0,0);
      iVar13 = local_3dc;
      local_3f8 = 0x5a0;
      local_3ee = 0x18;
      local_3f0 = 0x18;
      if (iVar19 == 0) {
        if (iVar27 != 0) {
          *(char *)(local_3dc + 8) = (char)*(undefined4 *)(param_1 + 0x2184);
          *(undefined2 *)(local_3dc + 6) = 5;
          *(undefined4 *)(local_3dc + 0xc) = 0x5f6e16;
          *(undefined2 *)(local_3dc + 4) = 0xfde9;
        }
      }
      else if (iVar27 == 0) {
        *(undefined *)(local_3dc + 8) = 0;
        *(undefined *)(local_3dc + 9) = *(undefined *)(param_1 + 0x276);
        *(undefined2 *)(local_3dc + 10) = *(undefined2 *)(param_1 + 0x14);
        *(undefined2 *)(local_3dc + 0xc) = *(undefined2 *)(param_1 + 0x16);
        *(undefined2 *)(local_3dc + 0xe) = *(undefined2 *)(param_1 + 0x18);
        *(undefined4 *)(local_3dc + 0x10) = puVar8[0x553];
        *(undefined2 *)(local_3dc + 0x14) = *(undefined2 *)(puVar8 + 0x554);
[32m[32m        memcpy((void *)(local_3dc + 0x16),&zeroEthAddr,6);[0m[0m
        *(undefined2 *)(iVar13 + 4) = 4;
        uVar18 = 0xe;
        if ((*(int *)(param_1 + 0x14) == puVar8[0x553]) &&
           (uVar18 = 8, *(short *)(param_1 + 0x18) != *(short *)(puVar8 + 0x554))) {
          uVar18 = 0xe;
        }
        *(undefined2 *)(iVar13 + 6) = uVar18;
      }
      else {
        local_3ee = 0x30;
        local_3f0 = 0x30;
        *(undefined *)(local_3dc + 8) = 0;
        *(undefined *)(local_3dc + 9) = *(undefined *)(param_1 + 0x276);
        *(undefined2 *)(local_3dc + 10) = *(undefined2 *)(param_1 + 0x14);
        *(undefined2 *)(local_3dc + 0xc) = *(undefined2 *)(param_1 + 0x16);
        *(undefined2 *)(local_3dc + 0xe) = *(undefined2 *)(param_1 + 0x18);
        *(undefined4 *)(local_3dc + 0x10) = puVar8[0x553];
        *(undefined2 *)(local_3dc + 0x14) = *(undefined2 *)(puVar8 + 0x554);
[32m[32m        memcpy((void *)(local_3dc + 0x16),&zeroEthAddr,6);[0m[0m
        *(undefined2 *)(iVar13 + 4) = 4;
        uVar18 = 0xe;
        if ((*(int *)(param_1 + 0x14) == puVar8[0x553]) &&
           (uVar18 = 8, *(short *)(param_1 + 0x18) != *(short *)(puVar8 + 0x554))) {
          uVar18 = 0xe;
        }
        *(undefined2 *)(iVar13 + 6) = uVar18;
        *(char *)(local_3dc + 0x20) = (char)*(undefined4 *)(param_1 + 0x2184);
        *(undefined2 *)(local_3dc + 0x1e) = 5;
        *(undefined4 *)(local_3dc + 0x24) = 0x5f6e16;
        *(undefined2 *)(local_3dc + 0x1c) = 0xfde9;
      }
      if (mDNS_LoggingEnabled != 0) {
        pcVar25 = "";
        if (iVar19 != 0) {
          pcVar25 = "OWNER";
        }
        local_34 = (int *)0x44db00;
        if (iVar27 != 0) {
          local_34 = (int *)"TRACER";
        }
        uVar9 = GetRRDisplayString_rdb(auStack_3fc,local_3dc + 4,local_78);
        LogMsgWithLevel(3,"SendQueries putting %s %s: %s %s",pcVar25,local_34,(int)puVar8 + 0x1552,
                        uVar9);
      }
      ppuVar16 = (uint **)PutResourceRecordTTLWithLimit
                                    (iVar28,ppuVar16,local_48,auStack_3fc,local_3f4,local_58);
      if (ppuVar16 == (uint **)0x0) {
        local_30 = "";
        if (iVar19 != 0) {
          local_30 = "OWNER";
        }
        local_34 = (int *)0x44db00;
        if (iVar27 != 0) {
          local_34 = (int *)"TRACER";
        }
        uVar18 = *(undefined2 *)(param_1 + 0x5cb4);
        uVar3 = *(undefined2 *)(param_1 + 0x5cb6);
        in_stack_fffffb98 = (uint **)(uint)*(ushort *)(param_1 + 0x5cb8);
        uVar4 = *(undefined2 *)(param_1 + 0x5cba);
        uVar9 = GetRRDisplayString_rdb(auStack_3fc,local_3dc + 4,local_78);
        LogMsgWithLevel(0,
                        "SendQueries: How did we fail to have space for %s %s OPT record (%d/%d/%d/%d) %s"
                        ,local_30,local_34,uVar18,uVar3,in_stack_fffffb98,uVar4,uVar9);
      }
      else if ((local_64 < ppuVar16) &&
              ((*(int *)(param_1 + 0x5cb4) != 0x10000 || (*(int *)(param_1 + 0x5cb8) != 0x10001))))
      {
        local_30 = "";
        if (iVar19 != 0) {
          local_30 = "OWNER";
        }
        local_34 = (int *)0x44db00;
        if (iVar27 != 0) {
          local_34 = (int *)"TRACER";
        }
        uVar18 = *(undefined2 *)(param_1 + 0x5cb4);
        uVar3 = *(undefined2 *)(param_1 + 0x5cb6);
        uVar4 = *(undefined2 *)(param_1 + 0x5cb8);
        uVar5 = *(undefined2 *)(param_1 + 0x5cba);
        uVar9 = GetRRDisplayString_rdb(auStack_3fc,local_3dc + 4,local_78);
        in_stack_fffffb98 = ppuVar16;
        LogMsgWithLevel(0,
                        "SendQueries: Why did we generate oversized packet with %s %s OPT record %p %p %p (%d/%d/%d/%d) %s"
                        ,local_30,local_34,local_6c,local_64,ppuVar16,uVar18,uVar3,uVar4,uVar5,uVar9
                       );
      }
    }
    if (((*(byte *)(param_1 + 0x5cb2) & 2) != 0) && (1 < *(ushort *)(param_1 + 0x5cb4))) {
      LogMsgWithLevel(0,
                      "SendQueries: Should not have more than one question (%d) in a truncated packet"
                     );
    }
    if (*(char *)((int)puVar8 + 5) != '\0') {
      in_stack_fffffb98 = (uint **)((uint)in_stack_fffffb98 & 0xffff | 0x14e90000);
      mDNSSendDNSMessage(param_1,iVar28,ppuVar16,puVar8[0x548],0,AllDNSLinkGroup_v4,
                         in_stack_fffffb98,0,0,local_70);
    }
    if (*(char *)((int)puVar8 + 6) != '\0') {
      in_stack_fffffb98 = (uint **)((uint)in_stack_fffffb98 & 0xffff | 0x14e90000);
      mDNSSendDNSMessage(param_1,iVar28,ppuVar16,puVar8[0x548],0,AllDNSLinkGroup_v6,
                         in_stack_fffffb98,0,0,local_70);
    }
    iVar19 = local_78;
    if (*(int *)(param_1 + 0x244) == 0) {
      iVar27 = (int)(mDNSPlatformOneSecond + 9) / 10 + *(int *)(param_1 + 0x234);
      if (iVar27 == 0) {
        iVar27 = 1;
      }
      *(int *)(param_1 + 0x244) = iVar27;
    }
    local_60 = local_60 + 1;
    if (999 < local_60) {
      LogMsgWithLevel(0,"SendQueries exceeded loop limit %d: giving up",local_60);
LAB_00431724:
      for (puVar8 = *(undefined4 **)(param_1 + 0x2160); iVar28 = local_4c,
          puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
        iVar28 = puVar8[0x26];
        if (iVar28 != 0) {
          if ((1 < puVar8[0x1f] - 4) && (mDNS_LoggingEnabled != 0)) {
            local_34 = (int *)puVar8[7];
            uVar9 = GetRRDisplayString_rdb(puVar8 + 1,puVar8[9] + 4,iVar19);
            LogMsgWithLevel(3,"SendQueries: No active interface %d to send probe: %d %s",iVar28,
                            local_34,uVar9);
          }
          puVar8[0x26] = 0;
        }
      }
      do {
        for (puVar8 = *(undefined4 **)(iVar28 + 0x2e0); puVar8 != (undefined4 *)0x0;
            puVar8 = (undefined4 *)*puVar8) {
          for (puVar22 = (undefined4 *)puVar8[2]; puVar22 != (undefined4 *)0x0;
              puVar22 = (undefined4 *)*puVar22) {
            if (((puVar22[0x11] != 0) && (*(byte *)(puVar22 + 0x13) < 4)) &&
               (-1 < (*(int *)(param_1 + 0x234) - puVar22[0xf]) +
                     (int)(puVar22[3] * mDNSPlatformOneSecond) / 0x32)) {
              *(byte *)(puVar22 + 0x13) = *(byte *)(puVar22 + 0x13) + 1;
              *(undefined4 *)(puVar22[0x11] + 0xa8) = 0;
              FUN_00428c90(param_1,puVar22);
            }
          }
        }
        iVar28 = iVar28 + 4;
      } while (iVar28 != local_5c);
      for (puVar8 = *(undefined4 **)(param_1 + 0x2ac); puVar8 != (undefined4 *)0x0;
          puVar8 = (undefined4 *)*puVar8) {
        local_3c = (int *)puVar8[0x2a];
        if (local_3c != (int *)0x0) {
          for (puVar22 = *(undefined4 **)(param_1 + 0x2b0);
              (puVar22 != (undefined4 *)0x0 && (puVar22 != puVar8));
              puVar22 = (undefined4 *)*puVar22) {
          }
          if (mDNS_LoggingEnabled != 0) {
            local_34 = (int *)&UNK_00456ea4;
            if (puVar22 != (undefined4 *)0x0) {
              local_34 = (int *)&UNK_00456ea8;
            }
            uVar29 = puVar8[0x4d];
            uVar9 = DNSTypeName(*(undefined2 *)(puVar8 + 0x95));
            LogMsgWithLevel(3,
                            "SendQueries: No active interface %d to send %s question: %d %##s (%s)",
                            local_3c,local_34,uVar29,puVar8 + 0x55,uVar9);
          }
          puVar8[0x2a] = 0;
        }
        *(undefined *)((int)puVar8 + 0xad) = 0;
      }
      return;
    }
  } while( true );
LAB_00430b5c:
  puVar20 = (undefined4 *)*puVar20;
  goto LAB_00430b64;
}

[ASK_GPT] dda838739f654df8
