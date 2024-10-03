
void mDNSCoreReceive(int param_1,ushort *param_2,uint param_3,int *param_4,undefined4 param_5,
                    int *param_6,undefined4 param_7,int *param_8)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  byte bVar8;
  void *pvVar5;
  undefined2 uVar7;
  byte *pbVar6;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  byte *pbVar13;
  undefined *puVar14;
  uint uVar15;
  undefined *puVar16;
  uint uVar17;
  undefined *puVar18;
  ushort *puVar19;
  undefined4 uVar20;
  short *psVar21;
  undefined4 *puVar22;
  uint uVar23;
  uint uVar24;
  size_t __n;
  undefined4 uVar25;
  code *pcVar26;
  int *piVar27;
  short *psVar28;
  int *in_stack_fffffb50;
  uint in_stack_fffffb54;
  int *in_stack_fffffb58;
  uint in_stack_fffffb5c;
  undefined uStack_478;
  char local_477;
  int local_476;
  undefined auStack_470 [6];
  undefined auStack_46a [6];
  undefined auStack_464 [128];
  undefined auStack_3e4 [4];
  undefined auStack_3e0 [4];
  undefined2 local_3dc;
  undefined4 local_3d8;
  undefined2 local_3d4;
  undefined2 local_3d2;
  int local_3c0;
  uint local_60;
  uint local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  undefined *local_4c;
  uint local_48;
  int *local_44;
  int local_40;
  int local_3c;
  char *local_38;
  uint local_34;
  uint local_30;
  ushort *local_2c;
  
  uVar23 = (uint)param_5._0_2_;
  local_5c = (uint)(param_6 == (int *)0x1);
  uVar24 = (uint)param_7._0_2_;
  iVar3 = mDNSSameAddress(param_4,param_1 + 0x2198);
  if (local_5c != 0) {
    param_6 = (int *)0x0;
  }
  if ((iVar3 != 0) && (uVar23 == 0x14e7)) {
    mDNS_Lock_(param_1,"mDNSCoreReceive");
    uDNS_ReceiveNATPacket(param_1,param_8,param_2,param_3 - (int)param_2 & 0xffff);
    pcVar26 = mDNS_Unlock_;
    pcVar12 = "mDNSCoreReceive";
    goto LAB_0044b574;
  }
  local_60 = param_3 - (int)param_2;
  if (local_60 < 0xc) {
    LogMsgWithLevel(0,"DNS Message from %#a:%d to %#a:%d length %d too short",param_4,uVar23,param_6
                    ,uVar24,local_60);
    return;
  }
  bVar8 = *(byte *)(param_2 + 1);
  *(char *)((int)param_2 + 5) = (char)param_2[2];
  *(char *)(param_2 + 2) = (char)(param_2[2] >> 8);
  *(char *)((int)param_2 + 7) = (char)param_2[3];
  *(char *)(param_2 + 3) = (char)(param_2[3] >> 8);
  *(char *)((int)param_2 + 9) = (char)param_2[4];
  *(char *)(param_2 + 4) = (char)(param_2[4] >> 8);
  *(char *)((int)param_2 + 0xb) = (char)param_2[5];
  *(char *)(param_2 + 5) = (char)(param_2[5] >> 8);
  if (param_1 == 0) {
    param_1 = 0;
    pcVar26 = LogMsgWithLevel;
    pcVar12 = "mDNSCoreReceive ERROR m is NULL";
    goto LAB_0044b574;
  }
  if (param_4 != (int *)0x0) {
    if (*param_4 == 4) {
      bVar2 = 0xfffffffd < param_4[1] - 1U;
    }
    else {
      bVar2 = true;
      if (*param_4 == 6) {
        if ((((param_4[2] == 0) && (param_4[1] == 0)) && (param_4[3] == 0)) && (param_4[4] == 0)) {
          bVar2 = true;
        }
        else {
          bVar2 = (param_4[2] & param_4[1] & param_4[3] & param_4[4]) == 0xffffffff;
        }
      }
    }
    if (bVar2) {
      return;
    }
  }
  mDNS_Lock_(param_1,"mDNSCoreReceive");
  *(int *)(param_1 + 0x26c) = *(int *)(param_1 + 0x26c) + 1;
  if (*param_2 == 0) {
    *(int *)(param_1 + 0x270) = *(int *)(param_1 + 0x270) + 1;
  }
  pcVar12 = (char *)(bVar8 & 0xf8);
  piVar27 = param_8;
  if (param_6 == (int *)0x0) {
LAB_0044a01c:
    if (*param_2 != 0) {
      piVar27 = (int *)0x0;
      local_38 = pcVar12;
      if (mDNS_PacketLoggingEnabled != 0) {
        if (local_5c == 0) {
          if (param_6 == (int *)0x0) {
            puVar14 = &DAT_0044d19c;
          }
          else {
            puVar14 = &DAT_0044d194;
          }
        }
        else {
          puVar14 = &DAT_00450d50;
        }
        in_stack_fffffb54 = in_stack_fffffb54 & 0xffff | (uint)param_5._0_2_ << 0x10;
        in_stack_fffffb5c = in_stack_fffffb5c & 0xffff | (uint)param_7._0_2_ << 0x10;
        in_stack_fffffb50 = param_4;
        in_stack_fffffb58 = param_6;
        DumpPacket(param_1,0,0,puVar14,param_4,in_stack_fffffb54,param_6,in_stack_fffffb5c,param_2,
                   param_3);
      }
      in_stack_fffffb50 = (int *)((uint)in_stack_fffffb50 & 0xffff);
      uDNS_ReceiveMsg(param_1,param_2,param_3,param_4);
      pcVar12 = local_38;
    }
  }
  else if (*param_6 == 4) {
    iVar10 = param_6[1];
    iVar3 = -0x1fffff05;
LAB_0044a000:
    if (iVar10 != iVar3) goto LAB_0044a00c;
  }
  else {
    if (((*param_6 == 6) && (param_6[1] == -0xfe0000)) && ((param_6[2] == 0 && (param_6[3] == 0))))
    {
      iVar3 = 0xfb;
      iVar10 = param_6[4];
      goto LAB_0044a000;
    }
LAB_0044a00c:
    if ((pcVar12 == (char *)0x80) || (pcVar12 == (char *)0xa8)) goto LAB_0044a01c;
  }
  if (pcVar12 == (char *)0x0) {
    if (((param_4 == (int *)0x0) || (param_6 == (int *)0x0)) ||
       (iVar3 = mDNSAddrIsDNSMulticast(param_6), iVar3 != 0)) {
LAB_0044a12c:
      local_60 = 0;
    }
    else {
      local_60 = 1;
      iVar3 = FUN_00426100(param_1,piVar27,param_4);
      if (iVar3 == 0) goto LAB_0044a12c;
    }
    if (((piVar27 == (int *)0x0) && (param_6 != (int *)0x0)) &&
       (iVar3 = mDNSAddrIsDNSMulticast(param_6), iVar3 != 0)) {
      if (param_2[2] == 1) {
        puVar14 = &DAT_0045b344;
      }
      else {
        puVar14 = &UNK_0045b348;
      }
      if (param_2[3] == 1) {
        puVar18 = &DAT_0045b344;
      }
      else {
        puVar18 = &UNK_0045b348;
      }
      if (param_2[4] == 1) {
        puVar16 = &DAT_0045b34c;
      }
      else {
        puVar16 = &UNK_0045b354;
      }
      if (param_2[5] == 1) {
        pcVar12 = " ";
      }
      else {
        pcVar12 = "s";
      }
      LogMsgWithLevel(0,
                      "Ignoring Query from %#-15a:%-5d to %#-15a:%-5d on 0x%p with %2d Question%s %2d Answer%s %2d Authorit%s %2d Additional%s %d bytes (Multicast, but no InterfaceID)"
                      ,param_4,(uint)(param_5._0_2_ >> 8) << 8 | uVar23 & 0xff,param_6,
                      (uint)(param_7._0_2_ >> 8) << 8 | uVar24 & 0xff,0,param_2[2],puVar14,
                      param_2[3],puVar18,param_2[4],puVar16,param_2[5],pcVar12,
                      param_3 - (int)(param_2 + 6));
    }
    else {
      uVar23 = mDNSAddrIsDNSMulticast(param_6);
      iVar3 = FUN_0043cd50(param_1,param_2,param_3,param_4,piVar27,param_5._0_2_ != 0x14e9,uVar23,
                           local_60,param_1 + 0x5cb0);
      if (iVar3 != 0) {
        mDNSSendDNSMessage(param_1,param_1 + 0x5cb0,iVar3,piVar27,0,param_4,
                           uVar23 & 0xffff | (uint)param_5._0_2_ << 0x10,0,0,0);
      }
    }
  }
  else if (pcVar12 == (char *)0x80) {
    FUN_00442f38(param_1,param_2,param_3,param_4,
                 (uint)in_stack_fffffb50 & 0xffff | (uint)param_5._0_2_ << 0x10,param_6,
                 (uint)in_stack_fffffb58 & 0xffff | (uint)param_7._0_2_ << 0x10,piVar27);
  }
  else if (pcVar12 == (char *)0x28) {
[32m[32m    memcpy(&uStack_478,zeroOwner,0x14);[0m[0m
    if (mDNS_LoggingEnabled != 0) {
      in_stack_fffffb5c = (uint)param_2[2];
      if (in_stack_fffffb5c == 1) {
        puVar14 = &DAT_0045b344;
      }
      else {
        puVar14 = &UNK_0045b348;
      }
      if (param_2[3] == 1) {
        puVar18 = &DAT_0045b344;
      }
      else {
        puVar18 = &UNK_0045b348;
      }
      if (param_2[4] == 1) {
        puVar16 = &DAT_0045b34c;
      }
      else {
        puVar16 = &UNK_0045b354;
      }
      if (param_2[5] == 1) {
        pcVar12 = " ";
      }
      else {
        pcVar12 = "s";
      }
      in_stack_fffffb54 = (uint)(param_7._0_2_ >> 8) << 8 | uVar24 & 0xff;
      in_stack_fffffb58 = param_8;
      LogMsgWithLevel(2,
                      "Received Update from %#-15a:%-5d to %#-15a:%-5d on 0x%p with %2d Question%s %2d Answer%s %2d Authorit%s %2d Additional%s %d bytes"
                      ,param_4,(uint)(param_5._0_2_ >> 8) << 8 | uVar23 & 0xff,param_6,
                      in_stack_fffffb54,param_8,in_stack_fffffb5c,puVar14,param_2[3],puVar18,
                      param_2[4],puVar16,param_2[5],pcVar12,param_3 - (int)(param_2 + 6));
    }
    if (((param_8 != (int *)0x0) && (*(ushort **)(param_1 + 0x2aa8) != (ushort *)0x0)) &&
       (uVar24 == **(ushort **)(param_1 + 0x2aa8))) {
      if (mDNS_PacketLoggingEnabled != 0) {
        DumpPacket(param_1,0,0,&DAT_0044d194,param_4,
                   in_stack_fffffb54 & 0xffff | (uint)param_5._0_2_ << 0x10,param_6,
                   in_stack_fffffb5c & 0xffff | (uint)param_7._0_2_ << 0x10,param_2,param_3);
        in_stack_fffffb58 = param_6;
      }
      uVar24 = 0;
      iVar3 = LocateOptRR(param_2,param_3,0x14);
      if (iVar3 != 0) {
        in_stack_fffffb58 = (int *)(param_1 + 0x7fa8);
        iVar3 = GetLargeResourceRecord(param_1,param_2,iVar3,param_3,0,0x80,in_stack_fffffb58);
        if (((iVar3 == 0) || (*(char *)(param_1 + 0x7fac) == -0x10)) ||
           (uVar17 = 2, *(short *)(param_1 + 0x7fae) != 0x29)) {
          uVar24 = 0;
          *(undefined *)(param_1 + 0x7fac) = 0;
        }
        else {
          uVar15 = 4;
          puVar19 = (ushort *)(*(int *)(param_1 + 0x7fcc) + 4);
          puVar9 = (ushort *)((int)puVar19 + (uint)*(ushort *)(param_1 + 0x7fb8));
          while (puVar19 < puVar9) {
            if (*puVar19 == uVar17) {
              uVar24 = *(uint *)(puVar19 + 2);
              puVar19 = puVar19 + 0xc;
            }
            else {
              if ((*puVar19 == uVar15) && (*(char *)(puVar19 + 2) == '\0')) {
                local_34 = uVar17;
                local_30 = uVar15;
                local_2c = puVar9;
[32m[32m                memcpy(&uStack_478,puVar19 + 2,0x14);[0m[0m
                puVar9 = local_2c;
                uVar15 = local_30;
                uVar17 = local_34;
              }
              puVar19 = puVar19 + 0xc;
            }
          }
          *(undefined *)(param_1 + 0x7fac) = 0;
        }
      }
      iVar3 = param_1 + 0x5cbc;
      InitializeDNSMessage(param_1 + 0x5cb0,(uint)*param_2 << 0x10,0xa8000000);
      if ((uVar24 == 0) || (local_476 == 0)) {
        if (DAT_0046e814 < 100) {
          if (uVar24 == 0) {
            pcVar12 = " No lease";
          }
          else {
            pcVar12 = "";
          }
          if (local_476 == 0) {
            pcVar4 = " No owner";
          }
          else {
            pcVar4 = "";
          }
          DAT_0046e814 = DAT_0046e814 + 1;
          LogMsgWithLevel(0,"Refusing sleep proxy registration from %#a:%d:%s%s",param_4,
                          (uint)(param_5._0_2_ >> 8) << 8 | uVar23 & 0xff,pcVar12,pcVar4);
        }
        bVar8 = *(byte *)(param_1 + 0x5cb3) | 1;
LAB_0044a780:
        *(byte *)(param_1 + 0x5cb3) = bVar8;
      }
      else {
        if (10000 < (int)((uint)param_2[4] + *(int *)(param_1 + 0x38e0))) {
          if (DAT_0046e810 < 100) {
            in_stack_fffffb58 = (int *)((uint)param_2[4] + *(int *)(param_1 + 0x38e0));
            DAT_0046e810 = DAT_0046e810 + 1;
            LogMsgWithLevel(0,
                            "Refusing sleep proxy registration from %#a:%d: Too many records %d + %d = %d > %d"
                            ,param_4,uVar23,*(int *)(param_1 + 0x38e0),(uint)param_2[4],
                            in_stack_fffffb58,10000);
          }
          bVar8 = *(byte *)(param_1 + 0x5cb3) | 5;
          goto LAB_0044a780;
        }
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(2,"Received Update for H-MAC %.6a I-MAC %.6a Password %.6a seq %d",
                          &local_476,auStack_470,auStack_46a,(int)local_477);
        }
        local_44 = (int *)(param_1 + 0x7fa8);
        if (mDNSPlatformOneSecond == 0) {
          trap(0x1c00);
        }
        local_3c = param_1 + 0x2f;
        local_40 = param_1 + 0x7fac;
        local_50 = 0;
        uVar17 = 0x15180;
        if (0x40000000 / mDNSPlatformOneSecond < 0x15181) {
          uVar17 = 0x40000000 / mDNSPlatformOneSecond;
        }
        local_48 = uVar24;
        if (uVar17 <= uVar24) {
          local_48 = uVar17;
        }
        local_4c = &uStack_478;
        local_60 = LocateAuthorities(param_2,param_3);
        FUN_0043e188(param_1,&uStack_478,*(undefined4 *)(param_1 + 0x2164),param_8);
        FUN_0043e188(param_1,&uStack_478,*(undefined4 *)(param_1 + 0x2160),param_8);
LAB_0044af2c:
        if (((local_50 < (int)(uint)param_2[4]) && (local_60 != 0)) && (local_60 < param_3)) {
          in_stack_fffffb58 = local_44;
          local_60 = GetLargeResourceRecord(param_1,param_2,local_60,param_3,param_8,0xa0,local_44);
          if ((local_60 == 0) || (*(char *)(param_1 + 0x7fac) == -0x10)) goto LAB_0044af1c;
[32m          sVar1 = *(short *)(param_1 + 0x7fae);[0m
[32m          __n = 0x200;[0m
[32m[32m          if ((sVar1 != 0x11) && ((__n = 0x202, sVar1 != 0x1a && (__n = 0x214, sVar1 != 6)))) {[0m[0m
[32m            __n = (size_t)*(ushort *)(param_1 + 0x7fb8);[0m
          }
          pvVar5 = mDNSPlatformMemAllocate(__n + 0x27c);
          if (pvVar5 != (void *)0x0) {
            *(ushort *)(param_1 + 0x7fb0) = *(ushort *)(param_1 + 0x7fb0) & 0x7fff;
            local_58 = 8;
            if ((*(byte *)(param_1 + 0x7fac) & 0x10) != 0) {
              local_58 = 2;
            }
            if (*(short *)(param_1 + 0x7fae) == 10) {
              uVar24 = (uint)**(byte **)(param_1 + 0x7fc8);
              iVar10 = uVar24 + 1;
              if (uVar24 == 0) {
                iVar10 = 0;
              }
              iVar10 = SameDomainLabel(*(byte **)(param_1 + 0x7fc8) + iVar10,"\n_keepalive");
              if (iVar10 == 0) goto LAB_0044a96c;
            }
            else {
LAB_0044a96c:
              FUN_0043e3a4(param_1,local_4c,*(undefined4 *)(param_1 + 0x2164));
              FUN_0043e3a4(param_1,local_4c,*(undefined4 *)(param_1 + 0x2160));
            }
            in_stack_fffffb58 = (int *)0x0;
            mDNS_SetupResourceRecord
                      (pvVar5,0,param_8,*(undefined2 *)(param_1 + 0x7fae),
                       *(undefined4 *)(param_1 + 0x7fb4),local_58,0,FUN_0043c28c,pvVar5);
            uVar24 = DomainNameLengthLimit
                               (*(int *)(param_1 + 0x7fc8),*(int *)(param_1 + 0x7fc8) + 0x100);
            if (uVar24 < 0x101) {
              mDNSPlatformMemCopy((void *)((int)pvVar5 + 0x178),*(void **)(param_1 + 0x7fc8),uVar24)
              ;
            }
            else {
              *(undefined *)((int)pvVar5 + 0x178) = 0;
            }
            uVar7 = GetRDLength(local_40,0);
            *(undefined2 *)((int)pvVar5 + 0x10) = uVar7;
            **(undefined2 **)((int)pvVar5 + 0x24) = (short)__n;
            mDNSPlatformMemCopy((void *)(*(int *)((int)pvVar5 + 0x24) + 4),
                                (void *)(*(int *)(param_1 + 0x7fcc) + 4),__n);
            *(undefined *)((int)pvVar5 + 0x4a) = 1;
[32m[32m            memcpy((void *)((int)pvVar5 + 0x4c),local_4c,0x14);[0m[0m
            if (*(short *)(param_1 + 0x7fae) == 0xc) {
              uVar25 = *(undefined4 *)(param_1 + 0x7fc8);
              iVar10 = CountLabels(uVar25);
              if (-1 < iVar10 + -2) {
                uVar25 = SkipLeadingLabels(uVar25);
                iVar10 = SameDomainName(uVar25,&DAT_004543a4);
                if (iVar10 == 0) {
                  iVar10 = SameDomainName(uVar25,&DAT_0045d038);
                  if (iVar10 != 0) {
                    local_38 = *(char **)(param_1 + 0x7fc8);
                    iVar10 = CountLabels(local_38);
                    if (-1 < iVar10 + -0x22) {
                      pcVar12 = (char *)SkipLeadingLabels(local_38);
                      iVar10 = 0x10;
LAB_0044ad64:
                      if (*pcVar12 == '\x01') {
                        uVar24 = (uint)(byte)pcVar12[1];
                        uVar17 = uVar24 - 0x30;
                        if (((9 < (uVar17 & 0xff)) &&
                            (uVar17 = uVar24 - 0x37, 5 < (uVar24 - 0x41 & 0xff))) &&
                           (uVar17 = uVar24 - 0x57, 5 < (uVar24 - 0x61 & 0xff))) {
                          uVar17 = 0xffffffff;
                        }
                        if (pcVar12[2] == '\x01') {
                          uVar24 = (uint)(byte)pcVar12[3];
                          uVar15 = uVar24 - 0x30;
                          if (((9 < (uVar15 & 0xff)) &&
                              (uVar15 = uVar24 - 0x37, 5 < (uVar24 - 0x41 & 0xff))) &&
                             (uVar15 = uVar24 - 0x57, 5 < (uVar24 - 0x61 & 0xff))) {
                            uVar15 = 0xffffffff;
                          }
                          if ((-1 < (int)uVar17) && (-1 < (int)uVar15)) {
                            *(byte *)((int)pvVar5 + iVar10 + 99) =
                                 (byte)(uVar15 << 4) | (byte)uVar17;
                            if (iVar10 + -1 != 0) goto code_r0x0044ae28;
                            uVar25 = 6;
LAB_0044ae34:
                            *(undefined4 *)((int)pvVar5 + 0x60) = uVar25;
                          }
                        }
                      }
                      goto LAB_0044ae38;
                    }
                    pcVar4 = "GetIPFromName: Need 34 labels in IPv6 reverse mapping name %##s";
                    pcVar12 = local_38;
LAB_0044ad38:
                    LogMsgWithLevel(0,pcVar4,pcVar12);
                  }
                }
                else {
                  pcVar12 = *(char **)(param_1 + 0x7fc8);
                  iVar10 = CountLabels(pcVar12);
                  local_5c = iVar10 - 6;
                  if ((int)local_5c < 0) {
                    pcVar4 = "GetIPFromName: Need six labels in IPv4 reverse mapping name %##s";
                    goto LAB_0044ad38;
                  }
                  pbVar6 = (byte *)SkipLeadingLabels(pcVar12,iVar10 + -3);
                  iVar10 = 0;
                  if ((*pbVar6 - 1 & 0xff) < 3) {
                    iVar11 = 1;
                    do {
                      pbVar13 = pbVar6 + iVar11;
                      if ((int)(uint)*pbVar6 < iVar11) {
                        if (iVar10 < 0x100) {
                          *(char *)((int)pvVar5 + 100) = (char)iVar10;
                          local_54 = (int)pvVar5 + 100;
                          pbVar6 = (byte *)SkipLeadingLabels(pcVar12,local_5c + 2);
                          iVar10 = 0;
                          if ((*pbVar6 - 1 & 0xff) < 3) {
                            iVar11 = 1;
                            goto LAB_0044ac04;
                          }
                        }
                        break;
                      }
                      iVar11 = iVar11 + 1;
                      iVar10 = (*pbVar13 - 0x30) + iVar10 * 10;
                    } while ((*pbVar13 - 0x30 & 0xff) < 10);
                  }
                }
              }
              goto LAB_0044ae38;
            }
            goto LAB_0044ae6c;
          }
          *(byte *)(param_1 + 0x5cb3) = *(byte *)(param_1 + 0x5cb3) | 5;
        }
        if ((*(byte *)(param_1 + 0x5cb3) & 0xf) == 0) {
          in_stack_fffffb58 = (int *)0x0;
          mDNS_SetupResourceRecord(auStack_3e4,0,0,0x29,0x1194,0x20,0,0,0);
          local_3d2 = 0x18;
          local_3d4 = 0x18;
          local_3dc = 0x5a0;
          *(undefined2 *)(local_3c0 + 4) = 2;
          *(uint *)(local_3c0 + 8) = local_48;
          iVar3 = PutResourceRecordTTLWithLimit
                            (param_1 + 0x5cb0,iVar3,param_1 + 0x5cba,auStack_3e0,local_3d8,
                             param_1 + 0x7fa8);
        }
        else {
          LogMsgWithLevel(0,"Refusing sleep proxy registration from %#a:%d: Out of memory",param_4,
                          uVar23);
          FUN_0043cad4(param_1,&uStack_478,*(undefined4 *)(param_1 + 0x2164));
          FUN_0043cad4(param_1,&uStack_478,*(undefined4 *)(param_1 + 0x2160));
        }
      }
      if (iVar3 != 0) {
        mDNSSendDNSMessage(param_1,param_1 + 0x5cb0,iVar3,param_8,*(undefined4 *)(param_1 + 0x2aa8),
                           param_4,(uint)in_stack_fffffb58 & 0xffff | (uint)param_5._0_2_ << 0x10,0,
                           0,0);
      }
      FUN_0042b424(param_1);
    }
  }
  else if (pcVar12 == (char *)0xa8) {
    if (param_8 != (int *)0x0) {
      local_2c = (ushort *)0x80;
      iVar10 = 0xe10;
      iVar3 = LocateOptRR(param_2,param_3,8);
      if (iVar3 != 0) {
        iVar3 = GetLargeResourceRecord(param_1,param_2,iVar3,param_3,0,local_2c,param_1 + 0x7fa8);
        if (((iVar3 == 0) || (*(char *)(param_1 + 0x7fac) == -0x10)) ||
           (*(short *)(param_1 + 0x7fae) != 0x29)) {
          iVar10 = 0xe10;
          *(undefined *)(param_1 + 0x7fac) = 0;
        }
        else {
          pcVar12 = "Sleep Proxy granted lease time %4d seconds, updateid %d, InterfaceID %p";
          psVar21 = (short *)(*(int *)(param_1 + 0x7fcc) + 4);
          psVar28 = (short *)((int)psVar21 + (uint)*(ushort *)(param_1 + 0x7fb8));
          for (; psVar21 < psVar28; psVar21 = psVar21 + 0xc) {
            if ((*psVar21 == 2) && (iVar10 = *(int *)(psVar21 + 2), mDNS_LoggingEnabled != 0)) {
              local_38 = pcVar12;
              LogMsgWithLevel(2,pcVar12,iVar10,*param_2,param_8);
              pcVar12 = local_38;
            }
          }
          *(undefined *)(param_1 + 0x7fac) = 0;
        }
      }
      iVar3 = *(int *)(param_1 + 0x216c);
      if (iVar3 != 0) {
        uVar25 = GetRRDisplayString_rdb(iVar3 + 4,*(int *)(iVar3 + 0x24) + 4,param_1 + 0x2f);
        LogMsgWithLevel(0,"mDNSCoreReceiveUpdateR ERROR m->CurrentRecord already set %s",uVar25);
      }
      *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(param_1 + 0x2160);
      local_60 = param_1 + 0x2f;
      while (puVar22 = *(undefined4 **)(param_1 + 0x216c), puVar22 != (undefined4 *)0x0) {
        if ((((int *)puVar22[7] == param_8) ||
            (((int *)puVar22[7] == (int *)0x0 &&
             ((*(char *)((int)puVar22 + 0x4a) != '\0' ||
              (iVar3 = IsLocalDomain(puVar22[8]), iVar3 != 0)))))) &&
           (*(ushort *)((int)puVar22 + 0xf2) == *param_2)) {
          uVar23 = mDNSPlatformInterfaceIndexfromInterfaceID(param_1,param_8,1);
          if (uVar23 < 0x40) {
            puVar22[(uVar23 >> 5) + 0x3d] = ~(1 << (uVar23 & 0x1f)) & puVar22[(uVar23 >> 5) + 0x3d];
          }
          if ((puVar22[0x3e] == 0) && (puVar22[0x3d] == 0)) {
            *(undefined2 *)((int)puVar22 + 0xf2) = 0;
          }
          iVar3 = iVar10 * mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
          if (iVar3 == 0) {
            iVar3 = 1;
          }
          puVar22[0x3b] = iVar3;
          if (mDNS_LoggingEnabled != 0) {
            local_30 = puVar22[0x3e];
            local_38 = "registered";
            if (*(int *)((int)puVar22 + 0x4e) != 0) {
              local_38 = "transferred";
            }
            local_34 = puVar22[0x3d];
            local_2c = (ushort *)(uint)*(ushort *)((int)puVar22 + 0xf2);
            uVar25 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,local_60);
            LogMsgWithLevel(2,"Sleep Proxy %s record %5d 0x%x 0x%x (%d) %s",local_38,iVar10,local_30
                            ,local_34,local_2c,uVar25);
          }
          if (*(int *)((int)puVar22 + 0x4e) != 0) {
[32m[32m            memcpy((void *)((int)puVar22 + 0x4e),&zeroEthAddr,6);[0m[0m
            *(undefined *)(puVar22 + 0x22) = 0;
            mDNS_Deregister_internal(param_1,puVar22,0);
          }
        }
        if (*(undefined4 **)(param_1 + 0x216c) == puVar22) {
          *(undefined4 *)(param_1 + 0x216c) = *puVar22;
        }
      }
      for (puVar22 = *(undefined4 **)(param_1 + 0x2174); puVar22 != (undefined4 *)0x0;
          puVar22 = (undefined4 *)*puVar22) {
        if ((int *)puVar22[0x548] == param_8) {
          iVar3 = (int)puVar22 + 0x1552;
          goto LAB_0044b418;
        }
      }
      iVar3 = 0;
LAB_0044b418:
      mDNSPlatformMemCopy(auStack_464,param_4,0x14);
      mDNSPlatformStoreSPSMACAddr(auStack_464,iVar3);
    }
    if (*(int *)(param_1 + 0x284) != 0) {
      *(undefined4 *)(param_1 + 0x2a4) = *(undefined4 *)(param_1 + 0x234);
    }
  }
  else {
    LogMsgWithLevel(0,
                    "Unknown DNS packet type %02X%02X from %#-15a:%-5d to %#-15a:%-5d length %d on %p (ignored)"
                    ,*(undefined *)(param_2 + 1),*(undefined *)((int)param_2 + 3),param_4,uVar23,
                    param_6,uVar24,local_60,param_8);
    if (mDNS_LoggingEnabled != 0) {
      uVar23 = 0;
      while ((int)uVar23 < (int)local_60) {
        puVar18 = (undefined *)((int)param_2 + uVar23);
[32m        iVar3 = mDNS_snprintf(auStack_464,0x80,&DAT_0045d240,uVar23);[0m
        puVar14 = auStack_464 + iVar3;
        do {
          bVar2 = (int)uVar23 < (int)local_60;
          uVar23 = uVar23 + 1;
          if (bVar2) {
[32m            iVar3 = mDNS_snprintf(puVar14,0x80," %02X",*puVar18);[0m
            puVar14 = puVar14 + iVar3;
          }
          puVar18 = puVar18 + 1;
        } while ((uVar23 & 0xf) != 0);
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,"%s",auStack_464);
        }
      }
    }
  }
  pcVar26 = mDNS_Unlock_;
  pcVar12 = "mDNSCoreReceive";
LAB_0044b574:
  (*pcVar26)(param_1,pcVar12);
  return;
  while( true ) {
    iVar11 = iVar11 + 1;
    iVar10 = (*pbVar13 - 0x30) + iVar10 * 10;
    if (9 < (*pbVar13 - 0x30 & 0xff)) break;
LAB_0044ac04:
    pbVar13 = pbVar6 + iVar11;
    if ((int)(uint)*pbVar6 < iVar11) {
      if (iVar10 < 0x100) {
        *(char *)(local_54 + 1) = (char)iVar10;
        pbVar6 = (byte *)SkipLeadingLabels(pcVar12,local_5c + 1);
        iVar10 = 0;
        if ((*pbVar6 - 1 & 0xff) < 3) {
          iVar11 = 1;
          goto LAB_0044ac80;
        }
      }
      break;
    }
  }
  goto LAB_0044ae38;
  while( true ) {
    iVar11 = iVar11 + 1;
    iVar10 = (*pbVar13 - 0x30) + iVar10 * 10;
    if (9 < (*pbVar13 - 0x30 & 0xff)) break;
LAB_0044ac80:
    pbVar13 = pbVar6 + iVar11;
    if ((int)(uint)*pbVar6 < iVar11) {
      if (iVar10 < 0x100) {
        *(char *)(local_54 + 2) = (char)iVar10;
        pbVar6 = (byte *)SkipLeadingLabels(pcVar12,local_5c);
        iVar10 = 0;
        if ((*pbVar6 - 1 & 0xff) < 3) {
          iVar11 = 1;
          goto LAB_0044acfc;
        }
      }
      break;
    }
  }
  goto LAB_0044ae38;
  while( true ) {
    iVar11 = iVar11 + 1;
    iVar10 = (*pbVar13 - 0x30) + iVar10 * 10;
    if (9 < (*pbVar13 - 0x30 & 0xff)) break;
LAB_0044acfc:
    pbVar13 = pbVar6 + iVar11;
    if ((int)(uint)*pbVar6 < iVar11) {
      if (iVar10 < 0x100) {
        *(char *)(local_54 + 3) = (char)iVar10;
        uVar25 = 4;
        goto LAB_0044ae34;
      }
      break;
    }
  }
LAB_0044ae38:
  if (*(int *)((int)pvVar5 + 0x60) != 0) {
    if ((*(int **)(param_1 + 0x2aa4) != (int *)0x0) && (*(int **)(param_1 + 0x2aa4) != param_8)) {
      mDNSPlatformUpdateProxyList(param_1);
    }
    *(int **)(param_1 + 0x2aa4) = param_8;
  }
LAB_0044ae6c:
  *(undefined4 *)((int)pvVar5 + 0x74) = *(undefined4 *)(param_1 + 0x234);
  iVar10 = local_48 * mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
  *(int *)((int)pvVar5 + 0x78) = iVar10;
  if (0 < *(int *)(param_1 + 0x25c) - iVar10) {
    *(int *)(param_1 + 0x25c) = iVar10;
  }
  *(undefined4 *)((int)pvVar5 + 0x80) = 0;
  mDNS_Register_internal(param_1,pvVar5);
  *(int *)(param_1 + 0x38e0) = *(int *)(param_1 + 0x38e0) + 1;
  FUN_0042f54c(param_1);
  if (mDNS_LoggingEnabled != 0) {
    uVar20 = *(undefined4 *)(param_1 + 0x38e0);
    uVar25 = GetRRDisplayString_rdb((int)pvVar5 + 4,*(int *)((int)pvVar5 + 0x24) + 4,local_3c);
    LogMsgWithLevel(2,"SPS Registered %4d %X %s",uVar20,local_58,uVar25);
  }
LAB_0044af1c:
  *(undefined *)(param_1 + 0x7fac) = 0;
  local_50 = local_50 + 1;
  goto LAB_0044af2c;
code_r0x0044ae28:
  pcVar12 = pcVar12 + 4;
  iVar10 = iVar10 + -1;
  goto LAB_0044ad64;
}

[ASK_GPT] e2ecf579b2164897
