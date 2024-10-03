
/* WARNING: Removing unreachable block (ram,0x00445c84) */
/* WARNING: Removing unreachable block (ram,0x00445114) */
/* WARNING: Removing unreachable block (ram,0x0044323c) */
/* WARNING: Removing unreachable block (ram,0x0044485c) */
/* WARNING: Removing unreachable block (ram,0x00445a04) */
/* WARNING: Removing unreachable block (ram,0x00446204) */
/* WARNING: Removing unreachable block (ram,0x00444ba4) */
/* WARNING: Removing unreachable block (ram,0x00444b60) */
/* WARNING: Type propagation algorithm not settling */

void FUN_00442f38(int param_1,ushort *param_2,ushort *param_3,int param_4,uint param_5,int param_6,
                 undefined4 param_7,uint param_8)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int ********ppppppppiVar5;
  short sVar16;
  int ********ppppppppiVar6;
  int iVar7;
  undefined4 uVar8;
  ushort *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  int ********ppppppppiVar14;
  int ******ppppppiVar15;
  int ********ppppppppiVar17;
  uint uVar18;
  undefined *puVar19;
  int ********ppppppppiVar20;
  char *pcVar21;
  uint uVar22;
  undefined *puVar23;
  int ********ppppppppiVar24;
  int ********ppppppppiVar25;
  int ********ppppppppiVar26;
  int ********ppppppppiVar27;
  int ********ppppppppiVar28;
  int *piVar29;
  ushort *puVar30;
  int ********ppppppppiVar31;
  int iVar32;
  undefined4 *puVar33;
  undefined4 uVar34;
  int ******ppppppiVar35;
  int iVar36;
  undefined4 *puVar37;
  int *******pppppppiVar38;
  uint uVar39;
  code *pcVar40;
  ushort in_stack_fffff762;
  int local_880;
  int ********local_87c;
  int ******local_878;
  int *local_874;
  undefined auStack_870 [4];
  undefined4 local_86c;
  undefined auStack_71c [256];
  undefined2 local_61c;
  undefined auStack_5e0 [656];
  undefined auStack_350 [4];
  undefined4 *local_34c;
  int *******local_1fc [64];
  short local_fc;
  undefined2 local_fa;
  int ********local_c0;
  int ********local_bc;
  ushort *local_b8;
  undefined *local_b4;
  ushort *local_b0;
  uint local_ac;
  undefined4 *local_a8;
  uint local_a4;
  undefined *local_a0;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  int local_84;
  ushort *local_80;
  int local_7c;
  uint *local_78;
  int local_74;
  uint local_70;
  int *******local_6c;
  int local_68;
  int ********local_64;
  int local_60;
  int local_5c;
  uint local_58;
  int ********local_54;
  int ********local_50;
  int ********local_4c;
  int ********local_48;
  int ********local_44;
  int ********local_40;
  int ********local_3c;
  int ********local_38;
  int ********local_34;
  int ********local_30;
  
  local_58 = param_5 >> 0x10;
  if (param_6 == 0) {
LAB_00442fa8:
    local_84 = 0;
  }
  else {
    local_84 = 1;
    iVar4 = mDNSAddrIsDNSMulticast(param_6);
    if (iVar4 == 0) goto LAB_00442fa8;
  }
  if (param_4 != 0) {
    iVar4 = FUN_00426100(param_1,param_8,param_4);
    local_68 = 0;
    if (iVar4 == 0) goto LAB_00442fd4;
  }
  local_68 = 1;
LAB_00442fd4:
  local_a8 = (undefined4 *)0x0;
  local_880 = 0;
  local_98 = uDNS_recvLLQResponse
                       (param_1,param_2,param_3,param_4,
                        param_5 & 0xffff0000 | (uint)in_stack_fffff762,&local_880);
  local_87c = (int ********)0x1;
  local_878 = (int ******)0x0;
  local_874 = (int *)0x0;
  if (param_8 != 0) {
    for (local_a8 = *(undefined4 **)(param_1 + 0x2174);
        (local_a8 != (undefined4 *)0x0 &&
        (((local_a8[0x548] != param_8 || (local_a8[0x549] != 4)) ||
         ((local_a8[0x54a] & 0xffff0000) != 0xa9fe0000)))); local_a8 = (undefined4 *)*local_a8) {
    }
  }
  local_70 = (uint)param_2[3];
  local_74 = param_2[4] + local_70;
  local_60 = local_74 + (uint)param_2[5];
  if ((param_8 == 0) && ((*(byte *)(param_2 + 1) & 2) != 0)) {
    return;
  }
  if (local_98 == 1) {
    return;
  }
  local_b8 = param_2 + 6;
  local_b0 = local_b8;
  if (((local_84 == 0) && (local_98 != 3)) && ((*(byte *)(param_2 + 1) & 2) == 0)) {
    local_ac = *(byte *)((int)param_2 + 3) & 0xf;
    if (((*(byte *)((int)param_2 + 3) & 0xf) == 0) || (local_ac == 3)) {
      local_9c = 0;
    }
    else {
      local_9c = (uint)(local_ac != 9);
    }
    local_90 = param_1 + 0x2f;
    local_c0 = (int ********)auStack_71c;
    local_8c = (uint)(param_6 == 0);
    local_a0 = auStack_870;
    iVar4 = 0;
    iVar32 = 0;
    local_bc = (int ********)0x0;
    local_88 = 0;
    while (((iVar32 < (int)(uint)param_2[2] && (local_b8 != (ushort *)0x0)) && (local_b8 < param_3))
          ) {
      local_b8 = (ushort *)getQuestion(param_2,local_b8,param_3,param_8,local_a0);
      if ((local_b8 == (ushort *)0x0) ||
         (iVar36 = FUN_00427778(param_1,(uint)param_7._0_2_ << 0x10,(uint)*param_2 << 0x10,local_a0,
                                local_8c), iVar36 == 0)) {
LAB_00443548:
        iVar32 = iVar32 + 1;
      }
      else {
        if (local_9c != 0) {
          if (((*(char *)(iVar36 + 0x266) == '\x02') &&
              (ppppppppiVar14 = *(int *********)(iVar36 + 0xdc), ppppppppiVar14 != (int ********)0x0
              )) && (*(char *)(ppppppppiVar14 + 0x51) == '\0')) {
            if (mDNS_LoggingEnabled != 0) {
              local_34 = ppppppppiVar14;
              uVar8 = DNSTypeName(local_61c);
              LogMsgWithLevel(3,
                              "mDNSCoreReceiveResponse: Server %p responded with code %d to DNSSEC Query %##s (%s), clear DO flag"
                              ,local_34,local_ac,local_c0,uVar8);
            }
            local_bc = (int ********)0x1;
            *(undefined *)(*(int *)(iVar36 + 0xdc) + 0x142) = 0;
          }
          else {
            if (mDNS_LoggingEnabled != 0) {
              local_34 = *(int *********)(iVar36 + 0xdc);
              uVar8 = DNSTypeName(local_61c);
              LogMsgWithLevel(3,
                              "mDNSCoreReceiveResponse: Server %p responded with code %d to query %##s (%s)"
                              ,local_34,local_ac,local_c0,uVar8);
            }
            local_bc = (int ********)0x1;
            PenalizeDNSServer(param_1,iVar36,(uint)param_2[1] << 0x10);
          }
          goto LAB_00443548;
        }
        uVar10 = DomainNameHashValue(local_c0);
        ppppppppiVar14 = (int ********)CacheGroupForName(param_1,uVar10 % 499,local_86c,local_c0);
        iVar11 = local_88;
        if (*param_2 != 0) {
          if ((*(int *)(iVar36 + 0xdc) != 0) &&
             (((*(char *)(iVar36 + 0x266) != '\0' || (*(char *)(iVar36 + 0xcc) != '\0')) ||
              ((*(char *)(iVar36 + 0x267) != '\0' && (*(char *)(iVar36 + 0x268) != '\0')))))) {
            if (mDNS_LoggingEnabled != 0) {
              local_30 = ppppppppiVar14;
              uVar8 = DNSTypeName(*(undefined2 *)(iVar36 + 0x254));
              LogMsgWithLevel(3,"mDNSCoreReceiveResponse: Setting aware for %##s (%s) on %#a",
                              iVar36 + 0x154,uVar8,*(int *)(iVar36 + 0xdc) + 0xc);
              ppppppppiVar14 = local_30;
            }
            *(undefined *)(*(int *)(iVar36 + 0xdc) + 0x144) = 1;
            *(undefined *)(*(int *)(iVar36 + 0xdc) + 0x142) = 1;
          }
          iVar4 = iVar36;
          iVar11 = 1;
          if (*(char *)(iVar36 + 0xcc) == '\0') {
            iVar11 = local_88;
          }
        }
        local_88 = iVar11;
        pppppppiVar38 = (int *******)0x0;
        if (ppppppppiVar14 != (int ********)0x0) {
          pppppppiVar38 = ppppppppiVar14[2];
        }
        local_94 = iVar4 + 0x154;
        for (; pppppppiVar38 != (int *******)0x0; pppppppiVar38 = (int *******)*pppppppiVar38) {
          local_30 = (int ********)(pppppppiVar38 + 1);
          iVar11 = SameNameRecordAnswersQuestion(pppppppiVar38 + 1,iVar36);
          if (iVar11 != 0) {
            iVar11 = *(int *)(param_1 + 0x234);
            iVar7 = (int)pppppppiVar38[3] * mDNSPlatformOneSecond;
            *(undefined *)(pppppppiVar38 + 0x13) = 4;
            *(undefined *)((int)pppppppiVar38 + 0x4d) = 0;
            pppppppiVar38[0xd] = (int ******)((iVar11 + -1) - iVar7);
            if ((iVar4 != 0) &&
               (((*(char *)(iVar4 + 0x266) != '\0' || (*(char *)(iVar4 + 0xcc) != '\0')) ||
                ((*(char *)(iVar4 + 0x267) != '\0' && (*(char *)(iVar4 + 0x268) != '\0')))))) {
              if (mDNS_LoggingEnabled != 0) {
                local_34 = (int ********)
                           GetRRDisplayString_rdb(local_30,pppppppiVar38[9] + 1,local_90);
                uVar8 = DNSTypeName(*(undefined2 *)(iVar4 + 0x254));
                LogMsgWithLevel(3,
                                "mDNSCoreReceiveResponse: CRDNSSECQuestion set for record %s, question %##s (%s)"
                                ,local_34,local_94,uVar8);
              }
              *(undefined *)((int)pppppppiVar38 + 0x4d) = 1;
            }
          }
        }
        iVar32 = iVar32 + 1;
      }
    }
    if (local_bc != (int ********)0x0) {
      if (mDNS_LoggingEnabled == 0) {
        return;
      }
      if (param_2[3] == 1) {
        puVar23 = &DAT_0045b344;
      }
      else {
        puVar23 = &UNK_0045b348;
      }
      if (param_2[4] == 1) {
        puVar19 = &DAT_0045b34c;
      }
      else {
        puVar19 = &UNK_0045b354;
      }
      if (param_2[5] == 1) {
        pcVar21 = "";
      }
      else {
        pcVar21 = "s";
      }
      LogMsgWithLevel(3,"Ignoring %2d Answer%s %2d Authorit%s %2d Additional%s",param_2[3],puVar23,
                      param_2[4],puVar19,param_2[5],pcVar21);
      return;
    }
    if ((iVar4 != 0) &&
       (((*(char *)(iVar4 + 0x266) != '\0' || (*(char *)(iVar4 + 0xcc) != '\0')) ||
        ((*(char *)(iVar4 + 0x267) != '\0' && (*(char *)(iVar4 + 0x268) != '\0')))))) {
      BumpDNSSECStats(param_1,3,5,(int)param_3 - (int)(param_2 + 6));
    }
  }
  else {
    iVar4 = 0;
    local_88 = 0;
    local_ac = 0;
    local_b8 = (ushort *)LocateAnswers(param_2,param_3);
  }
  if (*param_2 == 0) {
    FUN_004382b0(param_1,param_2,param_3,param_8,&local_874);
  }
  local_64 = (int ********)(uint)param_7._0_2_;
  local_78 = (uint *)(param_1 + 0x801c);
  local_a0 = (undefined *)(param_1 + 0x7fa8);
  local_bc = (int ********)&local_87c;
  local_6c = &local_878;
  local_7c = iVar4 + 0x154;
  iVar36 = param_1 + 0x7fac;
  iVar32 = param_1 + 0x2f;
  local_c0 = (int ********)0x0;
  local_94 = 0;
  local_8c = 0;
  local_9c = 0;
  local_80 = param_3;
  local_54 = local_64;
LAB_004450a4:
  if ((((int)local_9c < local_60) && (local_b8 != (ushort *)0x0)) && (local_b8 < local_80)) {
    bVar2 = true;
    if ((local_84 == 0) && (bVar2 = local_98 != 0, param_6 == 0)) {
      bVar2 = true;
    }
    uVar8 = 0xc0;
    if (((int)local_70 <= (int)local_9c) && (uVar8 = 0x80, (int)local_9c < local_74)) {
      uVar8 = 0xa0;
    }
    local_b8 = (ushort *)
               GetLargeResourceRecord(param_1,param_2,local_b8,local_80,param_8,uVar8,local_a0);
    if (local_b8 != (ushort *)0x0) {
      if ((*(char *)(param_1 + 0x7fac) != -0x10) &&
         (((*param_2 != 0 || (*(short *)(param_1 + 0x7fae) != 0x32)) &&
[32m          (sVar16 = *(short *)(param_1 + 0x7fae), sVar16 != 0xfa)))) {[0m
        if (sVar16 == 0x29) {
          ppppppppiVar14 = (int ********)0x4;
          puVar30 = (ushort *)(*(int *)(param_1 + 0x7fcc) + 4);
          puVar9 = (ushort *)((int)puVar30 + (uint)*(ushort *)(param_1 + 0x7fb8));
          for (; puVar30 < puVar9; puVar30 = puVar30 + 0xc) {
            if ((((int ********)(uint)*puVar30 == ppppppppiVar14) &&
                (*(char *)(puVar30 + 2) == '\0')) && (*(int *)(puVar30 + 3) != 0)) {
              local_50 = ppppppppiVar14;
              FUN_0043cad4(param_1,puVar30 + 2,*(undefined4 *)(param_1 + 0x2164));
              FUN_0043cad4(param_1,puVar30 + 2,*(undefined4 *)(param_1 + 0x2160));
              ppppppppiVar14 = local_50;
            }
          }
          goto LAB_0044508c;
        }
        if ((sVar16 != 5) ||
           (iVar11 = SameDomainName(*(undefined4 *)(param_1 + 0x7fc8),*(int *)(param_1 + 0x7fcc) + 4
                                   ), iVar11 == 0)) {
          if (*param_2 != 0) {
            uVar8 = FUN_0042678c(local_98,*(undefined4 *)(param_1 + 0x7fb4));
            *(undefined4 *)(param_1 + 0x7fb4) = uVar8;
          }
          if (local_84 == 0) {
            if (local_98 == 0) {
              if ((bVar2) && (param_6 != 0)) {
LAB_00443bf8:
                bVar2 = true;
              }
              else {
                ppppppppiVar14 = (int ********)(uint)*param_2;
                for (puVar33 = *(undefined4 **)(param_1 + 0x2ac); puVar33 != (undefined4 *)0x0;
                    puVar33 = (undefined4 *)*puVar33) {
                  if ((puVar33[0xf] == 0) &&
                     (local_30 = ppppppppiVar14,
                     iVar11 = ResourceRecordAnswersUnicastResponse(iVar36,puVar33),
                     ppppppppiVar14 = local_30, iVar11 != 0)) {
                    if ((int ********)(uint)*(ushort *)((int)puVar33 + 0x152) == (int ********)0x0)
                    {
                      if (((local_68 != 0) && (puVar33[5] != 0)) &&
                         ((uint)(*(int *)(param_1 + 0x234) - puVar33[5]) <
                          (uint)(mDNSPlatformOneSecond << 1))) goto LAB_00443b0c;
                    }
                    else if ((int ********)(uint)*(ushort *)((int)puVar33 + 0x152) == local_30) {
                      if (param_6 == 0) {
                        uVar1 = *(ushort *)(puVar33 + 0x44);
                      }
                      else {
                        puVar30 = (ushort *)puVar33[0x36];
                        if (puVar30 == (ushort *)0x0) {
                          puVar30 = &zeroIPPort;
                        }
                        uVar1 = *puVar30;
                      }
                      ppppppppiVar14 = (int ********)(uint)uVar1;
                      if (ppppppppiVar14 == local_64) {
LAB_00443b0c:
                        bVar2 = true;
                        if (param_8 == 0) {
                          local_94 = puVar33[0x37];
                          *(int *)(param_1 + 0x7fd0) = local_94;
                        }
                        else {
                          if (mDNS_LoggingEnabled == 0) goto LAB_00443bf8;
                          local_34 = (int ********)puVar33[0x4d];
                          bVar2 = true;
                          uVar8 = DNSTypeName(*(undefined2 *)(puVar33 + 0x95));
                          LogMsgWithLevel(3,"mDNSCoreReceiveResponse: InterfaceID %p %##s (%s)",
                                          local_34,puVar33 + 0x55,uVar8);
                        }
                        goto LAB_00443c04;
                      }
                      if (mDNS_LoggingEnabled != 0) {
                        local_30 = ppppppppiVar14;
                        local_38 = (int ********)DNSTypeName(*(undefined2 *)(puVar33 + 0x95));
                        uVar10 = (uint)local_30 & 0xff00;
                        uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32)
                        ;
                        LogMsgWithLevel(3,
                                        "WARNING: Ignoring suspect uDNS response for %##s (%s) [q->Target %#a:%d] from %#a:%d %s"
                                        ,puVar33 + 0x55,local_38,puVar33 + 0x4f,
                                        (uint)ppppppppiVar14 & 0xff | uVar10,param_4,local_54,uVar8)
                        ;
                      }
                      break;
                    }
                  }
                }
                if (param_8 == 0) {
                  bVar2 = false;
                }
              }
            }
            else {
              if (local_880 != 0) {
                local_94 = *(undefined4 *)(local_880 + 0xdc);
                *(int *)(param_1 + 0x7fd0) = local_94;
              }
              if ((iVar4 != 0) &&
                 (((*(char *)(iVar4 + 0x266) != '\0' || (*(char *)(iVar4 + 0xcc) != '\0')) ||
                  ((*(char *)(iVar4 + 0x267) != '\0' && (*(char *)(iVar4 + 0x268) != '\0')))))) {
                bVar2 = false;
              }
            }
          }
          else if ((((local_a8 != (undefined4 *)0x0) && (*(char *)((int)local_a8 + 0x1596) != '\0'))
                   && (*(short *)(param_1 + 0x7fae) == 1)) &&
                  ((*local_78 & 0xffff0000) == 0xa9fe0000)) {
            if (mDNS_LoggingEnabled != 0) {
              iVar11 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
              pcVar21 = "mDNSResponder: Dropping LinkLocal packet %s";
              goto LAB_00443bf0;
            }
            goto LAB_0044508c;
          }
LAB_00443c04:
          if ((*param_2 == 0) && (*(short *)(param_1 + 0x7fae) != 0x2f)) {
            iVar11 = *(int *)(param_1 + 0x216c);
            if (iVar11 != 0) {
              uVar8 = GetRRDisplayString_rdb(iVar11 + 4,*(int *)(iVar11 + 0x24) + 4,iVar32);
              LogMsgWithLevel(0,"mDNSCoreReceiveResponse ERROR m->CurrentRecord already set %s",
                              uVar8);
            }
            *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(param_1 + 0x2160);
LAB_0044430c:
            puVar33 = *(undefined4 **)(param_1 + 0x216c);
            if (puVar33 != (undefined4 *)0x0) {
              *(undefined4 *)(param_1 + 0x216c) = *puVar33;
              if ((((bVar2) || ((local_68 != 0 && (*(char *)(puVar33 + 1) == '\x02')))) &&
                  ((*(int *)(param_1 + 0x7fc4) == 0 ||
                   ((puVar33[7] == 0 || (*(int *)(param_1 + 0x7fc4) == puVar33[7])))))) &&
                 ((((*(byte *)(puVar33 + 1) & 0x32) != 0 && (*(int *)((int)puVar33 + 0x4e) == 0)) ||
                  (*(short *)(param_1 + 0x7fae) == *(short *)((int)puVar33 + 6))))) {
                bVar3 = false;
                if ((*(short *)(param_1 + 0x7fb0) == *(short *)(puVar33 + 2)) &&
                   (bVar3 = false, *(int *)(param_1 + 0x7fbc) == puVar33[5])) {
                  iVar11 = SameDomainName(*(undefined4 *)(param_1 + 0x7fc8),puVar33[8]);
                  bVar3 = true;
                  if (iVar11 == 0) {
                    bVar3 = false;
                  }
                }
                if (bVar3) {
                  if ((((*(short *)(param_1 + 0x7fae) == *(short *)((int)puVar33 + 6)) &&
                       (*(short *)(param_1 + 0x7fb0) == *(short *)(puVar33 + 2))) &&
                      (*(short *)(param_1 + 0x7fb8) == *(short *)(puVar33 + 4))) &&
                     ((*(int *)(param_1 + 0x7fc0) == puVar33[6] &&
                      (iVar11 = SameRDataBody(iVar36,puVar33[9] + 4,SameDomainName), iVar11 != 0))))
                  {
                    if (((uint)puVar33[3] >> 1 <= *(uint *)(param_1 + 0x7fb4)) ||
                       (*(char *)(param_1 + 0x275) != '\0')) {
                      if (puVar33[0x24] == param_8) {
                        *(undefined *)((int)puVar33 + 0x8b) = 0;
                        puVar33[0x24] = 0;
                      }
                      goto LAB_0044430c;
                    }
                    if (puVar33[0x24] != 0) {
                      if (puVar33[0x24] != param_8) goto LAB_004442f8;
                      goto LAB_0044430c;
                    }
                    puVar33[0x24] = param_8;
                  }
                  else {
                    if ((*(int *)(param_1 + 0x7fb4) != 0) &&
                       (iVar11 = FUN_0042d4d0(param_1,puVar33,local_a0), iVar11 != 0)) {
                      if (mDNS_LoggingEnabled != 0) {
                        local_30 = *(int *********)(param_1 + 0x7fc0);
                        uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32)
                        ;
                        LogMsgWithLevel(3,"mDNSCoreReceiveResponse: Pkt Record: %08lX %s",local_30,
                                        uVar8);
                      }
                      if (mDNS_LoggingEnabled != 0) {
                        local_30 = (int ********)puVar33[6];
                        uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                        LogMsgWithLevel(3,"mDNSCoreReceiveResponse: Our Record: %08lX %s",local_30,
                                        uVar8);
                      }
                      puVar37 = puVar33;
                      if (puVar33[0xe] != 0) {
                        do {
                          puVar33 = puVar37;
                          puVar37 = (undefined4 *)puVar33[0xe];
                        } while ((undefined4 *)puVar33[0xe] != (undefined4 *)0x0);
                        if (mDNS_LoggingEnabled != 0) {
                          local_30 = (int ********)puVar33[6];
                          uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                          LogMsgWithLevel(3,"mDNSCoreReceiveResponse: Dep Record: %08lX %s",local_30
                                          ,uVar8);
                        }
                      }
                      if (*(byte *)((int)puVar33 + 0x86) < 4) {
                        if (*(byte *)((int)puVar33 + 0x86) != 3) {
                          uVar8 = GetRRDisplayString_rdb
                                            (iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                          LogMsgWithLevel(0,"mDNSCoreReceiveResponse: Received from %#a:%d %s",
                                          param_4,local_58,uVar8);
                          ppppppppiVar14 = (int ********)(uint)*(byte *)(puVar33 + 1);
                          if (ppppppppiVar14 != (int ********)0x10) {
                            if (ppppppppiVar14 == (int ********)0x2) {
                              for (ppppppppiVar14 = *(int *********)(param_1 + 0x2a98);
                                  ppppppppiVar14 != (int ********)0x0;
                                  ppppppppiVar14 = (int ********)*ppppppppiVar14) {
                                if (((*(short *)((int)ppppppppiVar14 + 6) ==
                                      *(short *)((int)puVar33 + 6)) &&
                                    (*(short *)(ppppppppiVar14 + 2) == *(short *)(puVar33 + 2))) &&
                                   ((ppppppppiVar14[5] == (int *******)puVar33[5] &&
                                    ((((*(short *)(ppppppppiVar14 + 4) == *(short *)(puVar33 + 4) &&
                                       (ppppppppiVar14[6] == (int *******)puVar33[6])) &&
                                      (local_30 = ppppppppiVar14,
                                      iVar11 = SameRDataBody(ppppppppiVar14 + 1,puVar33[9] + 4,
                                                             SameDomainName),
                                      ppppppppiVar14 = local_30, iVar11 != 0)) &&
                                     (iVar11 = SameDomainName(local_30[8],puVar33[8]),
                                     ppppppppiVar14 = local_30, iVar11 != 0)))))) {
                                  if (mDNS_LoggingEnabled == 0) goto LAB_0044430c;
                                  uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                                  pcVar21 = 
                                  "mDNSCoreRegisteredProxyRecord: Ignoring packet registered with sleep proxy : %s "
                                  ;
                                  uVar13 = 2;
                                  goto LAB_00443fc8;
                                }
                              }
                              if (mDNS_LoggingEnabled != 0) {
                                LogMsgWithLevel(2,"Stored Proxy records :");
                              }
                              ppppppppiVar14 = (int ********)&mDNS_LoggingEnabled;
                              for (local_30 = *(int *********)(param_1 + 0x2a98);
                                  local_30 != (int ********)0x0; local_30 = (int ********)*local_30)
                              {
                                if (*ppppppppiVar14 != (int *******)0x0) {
                                  local_38 = ppppppppiVar14;
                                  uVar8 = GetRRDisplayString_rdb
                                                    (local_30 + 1,(int)local_30[9] + 4,iVar32);
                                  LogMsgWithLevel(2,"%s",uVar8);
                                  ppppppppiVar14 = local_38;
                                }
                              }
                              local_30 = (int ********)(uint)*(byte *)((int)puVar33 + 0x86);
                              uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                              LogMsgWithLevel(0,
                                              "mDNSCoreReceiveResponse: ProbeCount %d; will deregister %s"
                                              ,local_30,uVar8);
                              *(int *)(param_1 + 0x3964) = *(int *)(param_1 + 0x3964) + 1;
                            }
                            else {
                              if (ppppppppiVar14 != (int ********)&DAT_00000020) {
                                local_30 = ppppppppiVar14;
                                uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                                LogMsgWithLevel(0,
                                                "mDNSCoreReceiveResponse: Unexpected record type %X %s"
                                                ,local_30,uVar8);
                                goto LAB_0044430c;
                              }
                              uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                              LogMsgWithLevel(0,
                                              "mDNSCoreReceiveResponse: Unexpected conflict discarding %s"
                                              ,uVar8);
                              *(int *)(param_1 + 0x3968) = *(int *)(param_1 + 0x3968) + 1;
                            }
                            mDNS_Deregister_internal(param_1,puVar33,2);
                            goto LAB_0044430c;
                          }
                          uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                          LogMsgWithLevel(0,"mDNSCoreReceiveResponse: Resetting to Probing: %s",
                                          uVar8);
                          *(undefined *)(puVar33 + 1) = 2;
                          *(undefined *)((int)puVar33 + 0x87) = 4;
                          *(undefined *)((int)puVar33 + 0x86) = 4;
                          FUN_00428828(param_1,puVar33);
                          FUN_004276dc(param_1,puVar33);
                          goto LAB_0044430c;
                        }
                        if (mDNS_LoggingEnabled == 0) goto LAB_0044430c;
                        uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                        pcVar21 = 
                        "mDNSCoreReceiveResponse: Ignoring response received before we even began probing: %s"
                        ;
                      }
                      else {
                        if (mDNS_LoggingEnabled == 0) goto LAB_0044430c;
                        uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                        pcVar21 = "mDNSCoreReceiveResponse: Already reset to Probing: %s";
                      }
                      uVar13 = 3;
LAB_00443fc8:
                      LogMsgWithLevel(uVar13,pcVar21,uVar8);
                      goto LAB_0044430c;
                    }
                    if (((*(short *)(param_1 + 0x7fae) != *(short *)((int)puVar33 + 6)) ||
                        ((*(byte *)(param_1 + 0x7fac) & 0x10) == 0)) ||
                       (*(int *)(param_1 + 0x234) - puVar33[0x31] <= mDNSPlatformOneSecond / 2))
                    goto LAB_0044430c;
LAB_004442f8:
                    puVar33[0x24] = 0xffffffff;
                  }
                  *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(param_1 + 0x234);
                }
              }
              goto LAB_0044430c;
            }
          }
          bVar3 = false;
          if (bVar2) {
LAB_004447e8:
            bVar2 = true;
          }
          else {
            ppppppppiVar24 = (int ********)0x1;
            ppppppppiVar6 = (int ********)0x2;
            ppppppppiVar20 = (int ********)0x5;
            ppppppppiVar17 = (int ********)&DAT_0000000c;
            ppppppppiVar14 = (int ********)0x27;
            ppppppppiVar25 = (int ********)0x12;
            ppppppppiVar26 = (int ********)&DAT_00000015;
            ppppppppiVar27 = (int ********)&DAT_00000024;
            ppppppppiVar28 = (int ********)&DAT_00000021;
            for (ppppppppiVar31 = local_87c; ppppppppiVar31 != ppppppppiVar24;
                ppppppppiVar31 = (int ********)ppppppppiVar31[0x14]) {
              ppppppppiVar5 = (int ********)(uint)*(ushort *)((int)ppppppppiVar31 + 6);
              if ((((ppppppppiVar5 == ppppppppiVar6) || (ppppppppiVar5 == ppppppppiVar20)) ||
                  (ppppppppiVar5 == ppppppppiVar17)) || (ppppppppiVar5 == ppppppppiVar14)) {
                pppppppiVar38 = ppppppppiVar31[9] + 1;
LAB_004443bc:
                if (((pppppppiVar38 != (int *******)0x0) &&
                    (ppppppppiVar31[6] == *(int ********)(param_1 + 0x7fbc))) &&
                   (local_50 = ppppppppiVar24, local_4c = ppppppppiVar6, local_48 = ppppppppiVar25,
                   local_44 = ppppppppiVar26, local_40 = ppppppppiVar27, local_3c = ppppppppiVar28,
                   local_38 = ppppppppiVar20, local_34 = ppppppppiVar17, local_30 = ppppppppiVar14,
                   iVar11 = SameDomainName(pppppppiVar38,*(undefined4 *)(param_1 + 0x7fc8)),
                   ppppppppiVar14 = local_30, ppppppppiVar17 = local_34, ppppppppiVar20 = local_38,
                   ppppppppiVar6 = local_4c, ppppppppiVar24 = local_50, ppppppppiVar25 = local_48,
                   ppppppppiVar26 = local_44, ppppppppiVar27 = local_40, ppppppppiVar28 = local_3c,
                   iVar11 != 0)) {
                  if (mDNS_LoggingEnabled == 0) goto LAB_004447d4;
                  bVar3 = false;
                  ppppppppiVar14 = *(int *********)(param_1 + 0x7fc8);
                  uVar8 = GetRRDisplayString_rdb(ppppppppiVar31 + 1,ppppppppiVar31[9] + 1,iVar32);
                  pcVar21 = 
                  "IsResponseAcceptable: Found a matching entry for %##s in the CacheFlushRecords %s"
                  ;
                  goto LAB_00444644;
                }
              }
              else {
                if (((ppppppppiVar5 == (int ********)0xf) || (ppppppppiVar5 == ppppppppiVar25)) ||
                   ((ppppppppiVar5 == ppppppppiVar26 || (ppppppppiVar5 == ppppppppiVar27)))) {
                  pppppppiVar38 = (int *******)((int)ppppppppiVar31[9] + 6);
                  goto LAB_004443bc;
                }
                if (ppppppppiVar5 == ppppppppiVar28) {
                  pppppppiVar38 = (int *******)((int)ppppppppiVar31[9] + 10);
                  goto LAB_004443bc;
                }
              }
            }
            if ((iVar4 == 0) ||
               (((*(char *)(iVar4 + 0x266) == '\0' && (*(char *)(iVar4 + 0xcc) == '\0')) &&
                ((*(char *)(iVar4 + 0x267) == '\0' || (*(char *)(iVar4 + 0x268) == '\0'))))))
            goto LAB_0044637c;
            iVar11 = SameDomainName(local_7c,*(undefined4 *)(param_1 + 0x7fc8));
            if (iVar11 != 0) {
[32m              sVar16 = *(short *)(param_1 + 0x7fae);[0m
              if ((*(short *)(iVar4 + 0x254) != sVar16) && (sVar16 != 5)) goto LAB_00444550;
              if (mDNS_LoggingEnabled != 0) {
                bVar3 = false;
                ppppppppiVar14 = (int ********)DNSTypeName();
                uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                pcVar21 = "IsResponseAcceptable: Accepting, same name and qtype %s, CR %s";
                goto LAB_00444644;
              }
LAB_004447d4:
              bVar3 = false;
LAB_004447e0:
              *(int *)(param_1 + 0x7fd0) = local_94;
              goto LAB_004447e8;
            }
[32m            sVar16 = *(short *)(param_1 + 0x7fae);[0m
LAB_00444550:
            if (sVar16 == 0x2e) {
              uVar10 = swap16(*(undefined2 *)local_78);
              if ((iVar11 == 0) || ((*(ushort *)(iVar4 + 0x254) != uVar10 && (uVar10 != 5)))) {
                if ((uVar10 == 0x2f) || (uVar10 == 0x32)) {
                  if (mDNS_LoggingEnabled != 0) {
                    bVar3 = true;
                    local_34 = (int ********)
                               GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                    uVar8 = DNSTypeName(uVar10);
                    pcVar21 = 
                    "IsResponseAcceptable: Accepting RRSIG %s matches %s type (nseclist = 1)";
                    ppppppppiVar14 = local_34;
                    goto LAB_00444644;
                  }
                }
                else {
                  if (uVar10 != 6) goto LAB_0044637c;
                  if (mDNS_LoggingEnabled != 0) {
                    uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                    pcVar21 = 
                    "IsResponseAcceptable: Accepting RRSIG %s matches SOA type (nseclist = 1)";
                    goto LAB_004447bc;
                  }
                }
                goto LAB_004447dc;
              }
              if (mDNS_LoggingEnabled == 0) goto LAB_004447d4;
              bVar3 = false;
              local_34 = (int ********)
                         GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
              uVar8 = DNSTypeName(*(undefined2 *)(iVar4 + 0x254));
              pcVar21 = "IsResponseAcceptable: Accepting RRSIG %s matches question type %s";
              ppppppppiVar14 = local_34;
LAB_00444644:
              LogMsgWithLevel(3,pcVar21,ppppppppiVar14,uVar8);
              goto LAB_004447e0;
            }
            if (sVar16 != 0x2f) {
              if (sVar16 == 6) {
                if (mDNS_LoggingEnabled != 0) {
                  uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                  pcVar21 = "IsResponseAcceptable: Accepting SOA %s (nseclist = 1)";
LAB_004447bc:
                  bVar3 = true;
                  LogMsgWithLevel(3,pcVar21,uVar8);
                  goto LAB_004447e0;
                }
              }
              else {
                if (sVar16 != 0x32) goto LAB_0044637c;
                if (mDNS_LoggingEnabled != 0) {
                  uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                  pcVar21 = "IsResponseAcceptable: Accepting NSEC3 %s (nseclist = 1)";
                  goto LAB_004447bc;
                }
              }
LAB_004447dc:
              bVar3 = true;
              goto LAB_004447e0;
            }
            iVar11 = RRAssertsExistence(iVar36,0x2f);
            if (iVar11 != 0) {
              if (mDNS_LoggingEnabled != 0) {
                uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                pcVar21 = "IsResponseAcceptable: Accepting NSEC %s (nseclist = 1)";
                goto LAB_004447bc;
              }
              goto LAB_004447dc;
            }
            uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
            LogMsgWithLevel(0,"IsResponseAcceptable: ERROR!! Not a unicast NSEC %s",uVar8);
LAB_0044637c:
            bVar3 = false;
            if (mDNS_LoggingEnabled != 0) {
              bVar3 = false;
              uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
              LogMsgWithLevel(3,"mDNSCoreReceiveResponse ignoring %s",uVar8);
            }
          }
          if ((*(int *)(param_1 + 0x2c8) != 0) && (bVar2)) {
            uVar10 = DomainNameHashValue(*(undefined4 *)(param_1 + 0x7fc8));
            local_b4 = (undefined *)(uVar10 % 499);
            local_90 = CacheGroupForName(param_1,local_b4,*(undefined4 *)(param_1 + 0x7fbc),
                                         *(undefined4 *)(param_1 + 0x7fc8));
            if (local_874 != (int *)0x0) {
              InitializeAnonInfoForCR(param_1,&local_874,local_a0);
            }
            ppppppppiVar14 = local_bc;
            if (!bVar3) {
              pcVar21 = (char *)0x0;
              if (local_90 != 0) {
                pcVar21 = *(char **)(local_90 + 8);
              }
              local_5c = param_1 + ((int)local_b4 + 0x2aaU) * 4;
              for (; (int ********)pcVar21 != (int ********)0x0; pcVar21 = *(char **)pcVar21) {
                if (param_8 == 0) {
                  uVar10 = 0;
                  if (*(int ********)((int)pcVar21 + 0x28) != (int *******)0x0) {
                    uVar10 = (uint)*(ushort *)((int)*(int ********)((int)pcVar21 + 0x28) + 0x13e);
                  }
                  uVar39 = 0;
                  if (*(int *)(param_1 + 0x7fd0) != 0) {
                    uVar39 = (uint)*(ushort *)(*(int *)(param_1 + 0x7fd0) + 0x13e);
                  }
                  uVar10 = uVar10 ^ uVar39;
                }
                else {
                  uVar10 = param_8 ^ (uint)*(int ********)((int)pcVar21 + 0x1c);
                }
                if ((((uVar10 == 0) &&
                     (*(short *)(param_1 + 0x7fae) == *(short *)((int)pcVar21 + 6))) &&
                    (*(short *)(param_1 + 0x7fb0) == *(short *)((int)pcVar21 + 8))) &&
                   (((*(short *)(param_1 + 0x7fb8) == *(short *)((int)pcVar21 + 0x10) &&
                     (*(int ********)(param_1 + 0x7fc0) == *(int ********)((int)pcVar21 + 0x18))) &&
                    (iVar11 = SameRDataBody(iVar36,*(int ********)((int)pcVar21 + 0x24) + 1,
                                            SameDomainName), iVar11 != 0)))) {
                  if ((*(byte *)(param_1 + 0x7fac) & 0x10) != 0) {
                    ppppppppiVar17 = (int ********)((int)pcVar21 + 0x50);
                    if (((*(int ********)((int)pcVar21 + 0x50) == (int *******)0x0) &&
                        (ppppppppiVar14 != ppppppppiVar17)) && (local_98 != 3)) {
                      *local_bc = (int *******)pcVar21;
                      *(int ********)((int)pcVar21 + 0x50) = (int *******)0x1;
                      local_bc = ppppppppiVar17;
                      ppppppppiVar14 = ppppppppiVar17;
                    }
                    if ((*(byte *)((int)pcVar21 + 4) & 0x10) == 0) {
                      ppppppppiVar6 = *(int *********)(param_1 + 0x2ac);
                      ppppppppiVar17 = local_bc;
                      ppppppppiVar20 = (int ********)((int)pcVar21 + 4);
                      while (ppppppppiVar6 != (int ********)0x0) {
                        local_38 = ppppppppiVar20;
                        local_34 = ppppppppiVar17;
                        local_30 = ppppppppiVar6;
                        iVar11 = ResourceRecordAnswersQuestion(ppppppppiVar20,ppppppppiVar6);
                        if (iVar11 != 0) {
                          local_30[0xb] = (int *******)((int)local_30[0xb] + 1);
                        }
                        ppppppppiVar17 = local_34;
                        ppppppppiVar20 = local_38;
                        ppppppppiVar6 = (int ********)*local_30;
                      }
                      *(undefined *)((int)pcVar21 + 4) = *(undefined *)(param_1 + 0x7fac);
                      local_bc = ppppppppiVar17;
                    }
                  }
                  iVar11 = SameRDataBody(iVar36,*(int ********)((int)pcVar21 + 0x24) + 1,
                                         SameDomainNameCS);
                  if (iVar11 == 0) {
                    *(int ********)((int)pcVar21 + 0xc) = (int *******)0x0;
                    pppppppiVar38 = *(int ********)(param_1 + 0x234);
                    *(undefined *)((int)pcVar21 + 0x4c) = 4;
                    *(int ********)((int)pcVar21 + 0x34) = pppppppiVar38;
                    FUN_00428c90(param_1,pcVar21);
                    if (mDNS_LoggingEnabled != 0) {
                      uVar8 = GetRRDisplayString_rdb
                                        ((int ********)((int)pcVar21 + 4),
                                         *(int ********)((int)pcVar21 + 0x24) + 1,iVar32);
                      LogMsgWithLevel(3,
                                      "mDNSCoreReceiveCacheCheck: Discarding due to domainname case change old: %s"
                                      ,uVar8);
                    }
                    if (mDNS_LoggingEnabled != 0) {
                      uVar8 = GetRRDisplayString_rdb(iVar36,*(int *)(param_1 + 0x7fcc) + 4,iVar32);
                      LogMsgWithLevel(3,
                                      "mDNSCoreReceiveCacheCheck: Discarding due to domainname case change new: %s"
                                      ,uVar8);
                    }
                    if (mDNS_LoggingEnabled != 0) {
                      if (*(int ********)((int)pcVar21 + 0x44) == (int *******)0x0) {
                        iVar11 = mDNSPlatformOneSecond * 0x3c;
                      }
                      else {
                        pppppppiVar38 = *(int ********)((int)pcVar21 + 0xc);
                        if (*(byte *)((int)pcVar21 + 0x4c) < 4) {
                          iVar11 = ((int)pppppppiVar38 * mDNSPlatformOneSecond) / 0x32;
                        }
                        else {
                          iVar11 = mDNSPlatformOneSecond;
                          if ((pppppppiVar38 < (int *******)0xb) &&
                             (iVar11 = 0, pppppppiVar38 != (int *******)0x0)) {
                            iVar11 = mDNSPlatformOneSecond / 10;
                          }
                        }
                      }
                      iVar7 = *(int *)(param_1 + 0x234);
                      LogMsgWithLevel(3,
                                      "mDNSCoreReceiveCacheCheck: Discarding due to domainname case change in %d slot %3d in %d %d"
                                      ,(int)*(int ********)((int)pcVar21 + 0x3c) + (iVar11 - iVar7),
                                      local_b4,*(int *)(local_5c + 4) - iVar7,
                                      *(int *)(param_1 + 0x248) - iVar7);
                    }
                  }
                  else {
                    iVar11 = IdenticalAnonInfo(*(undefined4 *)(param_1 + 0x7fd4),
                                               *(int ********)((int)pcVar21 + 0x2c));
                    if (iVar11 != 0) {
                      pppppppiVar38 = *(int ********)(param_1 + 0x7fb4);
                      if (pppppppiVar38 == (int *******)0x0) {
                        if (mDNSPlatformOneSecond <
                            (int)*(int ********)((int)pcVar21 + 0x34) +
                            (mDNSPlatformOneSecond * (int)*(int ********)((int)pcVar21 + 0xc) -
                            (int)*(int ********)(param_1 + 0x234))) {
                          *(int ********)((int)pcVar21 + 0xc) = (int *******)0x1;
                          pppppppiVar38 = *(int ********)(param_1 + 0x234);
                          *(undefined *)((int)pcVar21 + 0x4c) = 4;
                          *(int ********)((int)pcVar21 + 0x34) = pppppppiVar38;
                          local_bc = ppppppppiVar14;
                          FUN_00428c90(param_1,pcVar21);
                          ppppppppiVar14 = local_bc;
                        }
                        goto LAB_00444e6c;
                      }
                      *(int *)(param_1 + 0x39b0) = *(int *)(param_1 + 0x39b0) + 1;
                      *(int ********)((int)pcVar21 + 0x34) = *(int ********)(param_1 + 0x234);
                      *(int ********)((int)pcVar21 + 0xc) = pppppppiVar38;
                      *(undefined *)((int)pcVar21 + 0x4c) = 0;
                      FUN_00428c90(param_1,pcVar21);
                      *(ushort *)((int)pcVar21 + 0x4e) = param_2[1];
                      ppppppppiVar17 = local_c0;
                      if ((((param_2[3] != 0) && (iVar4 != 0)) &&
                          (*(short *)(iVar4 + 0x254) == *(short *)((int)pcVar21 + 6))) &&
                         ((local_c0 == (int ********)0x0 &&
                          (ppppppppiVar17 = (int ********)pcVar21, mDNS_LoggingEnabled != 0)))) {
                        uVar8 = GetRRDisplayString_rdb
                                          ((int ********)((int)pcVar21 + 4),
                                           *(int ********)((int)pcVar21 + 0x24) + 1,iVar32);
                        LogMsgWithLevel(3,"mDNSCoreReceiveCacheCheck: rescuing RR %s",uVar8);
                      }
                      local_c0 = ppppppppiVar17;
                      ppppppppiVar17 = (int ********)((int)pcVar21 + 4);
                      if ((*(byte *)((int)pcVar21 + 4) & 0x10) == 0) goto LAB_00444e6c;
                      puVar33 = *(undefined4 **)(param_1 + 0x2ac);
                      goto LAB_00444de8;
                    }
                    *(int ********)((int)pcVar21 + 0xc) = (int *******)0x0;
                    pppppppiVar38 = *(int ********)(param_1 + 0x234);
                    *(undefined *)((int)pcVar21 + 0x4c) = 4;
                    *(int ********)((int)pcVar21 + 0x34) = pppppppiVar38;
                    FUN_00428c90(param_1,pcVar21);
                    if (mDNS_LoggingEnabled != 0) {
                      uVar8 = GetRRDisplayString_rdb
                                        ((int ********)((int)pcVar21 + 4),
                                         *(int ********)((int)pcVar21 + 0x24) + 1,iVar32);
                      LogMsgWithLevel(3,"mDNSCoreReceiveCacheCheck: AnonInfo changed for %s",uVar8);
                    }
                  }
                }
              }
            }
            local_bc = ppppppppiVar14;
            if (*(int *)(param_1 + 0x7fb4) != 0) {
              bVar2 = false;
              if (((*(byte *)(param_1 + 0x7fac) & 0x10) == 0) || (bVar2 = local_98 != 3, !bVar2)) {
                iVar11 = FUN_004279b4(param_1,*(undefined4 *)(param_1 + 0x7fc8),
                                      *(undefined4 *)(param_1 + 0x7fbc),local_b4,0);
              }
              else {
                iVar11 = mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
                if (iVar11 == 0) {
                  iVar11 = 1;
                }
              }
              pppppppiVar38 =
                   (int *******)CreateNewCacheEntry(param_1,local_b4,local_90,iVar11,!bVar3,param_4)
              ;
              if (pppppppiVar38 != (int *******)0x0) {
                *(ushort *)((int)pppppppiVar38 + 0x4e) = param_2[1];
                if ((*(short *)((int)pppppppiVar38 + 6) == 0x2e) && (!bVar3)) {
                  local_8c = 1;
                }
                *(undefined *)((int)pppppppiVar38 + 0x4d) = 0;
                if ((iVar4 != 0) &&
                   (((*(char *)(iVar4 + 0x266) != '\0' || (*(char *)(iVar4 + 0xcc) != '\0')) ||
                    ((*(char *)(iVar4 + 0x267) != '\0' && (*(char *)(iVar4 + 0x268) != '\0')))))) {
                  if (mDNS_LoggingEnabled != 0) {
                    local_34 = (int ********)
                               GetRRDisplayString_rdb(pppppppiVar38 + 1,pppppppiVar38[9] + 1,iVar32)
                    ;
                    uVar8 = DNSTypeName(*(undefined2 *)(iVar4 + 0x254));
                    LogMsgWithLevel(3,
                                    "mDNSCoreReceiveResponse: CRDNSSECQuestion set for new record %s, question %##s (%s)"
                                    ,local_34,local_7c,uVar8);
                  }
                  *(undefined *)((int)pppppppiVar38 + 0x4d) = 1;
                }
                if (bVar3) {
                  pppppppiVar38[0xd] = *(int *******)(param_1 + 0x234);
                  *local_6c = (int ******)pppppppiVar38;
                  local_6c = pppppppiVar38;
                }
                else if (bVar2) {
                  *local_bc = pppppppiVar38;
                  pppppppiVar38[0x14] = (int ******)0x1;
                  local_bc = (int ********)(pppppppiVar38 + 0x14);
                }
                else {
                  ppppppiVar35 = pppppppiVar38[0xe];
                  if (ppppppiVar35 != (int ******)0x0) {
                    iVar11 = param_1 + ((int)local_b4 + 0x2aaU) * 4;
                    if (0 < *(int *)(iVar11 + 4) - (int)ppppppiVar35) {
                      *(int *******)(iVar11 + 4) = ppppppiVar35;
                    }
                    if (0 < *(int *)(param_1 + 0x248) - (int)ppppppiVar35) {
                      *(int *******)(param_1 + 0x248) = ppppppiVar35;
                    }
                  }
                }
              }
            }
          }
          goto LAB_0044508c;
        }
        if (mDNS_LoggingEnabled == 0) goto LAB_0044508c;
        iVar11 = *(int *)(param_1 + 0x7fc8);
        pcVar21 = "mDNSCoreReceiveResponse: CNAME loop domain name %##s";
LAB_00443bf0:
        pcVar40 = LogMsgWithLevel;
        iVar7 = 3;
        goto LAB_00445084;
      }
      goto LAB_0044508c;
    }
  }
  puVar30 = local_80;
  FUN_0042cb28(param_1);
  while (ppppppppiVar14 = local_87c, local_87c != (int ********)0x1) {
    puVar33 = (undefined4 *)0x0;
    uVar10 = DomainNameHashValue(local_87c[8]);
    local_bc = (int ********)(uVar10 % 499);
    iVar36 = CacheGroupForName(param_1,local_bc,ppppppppiVar14[5],ppppppppiVar14[8]);
    local_87c = (int ********)local_87c[0x14];
    ppppppppiVar14[0x14] = (int *******)0x0;
    if (iVar36 != 0) {
      puVar33 = *(undefined4 **)(iVar36 + 8);
    }
    for (; puVar33 != (undefined4 *)0x0; puVar33 = (undefined4 *)*puVar33) {
      ppppppppiVar17 = (int ********)0x0;
      if (ppppppppiVar14[7] == (int *******)0x0) {
        ppppppppiVar20 = (int ********)0x0;
        if (ppppppppiVar14[10] != (int *******)0x0) {
          ppppppppiVar20 = (int ********)(uint)*(ushort *)((int)ppppppppiVar14[10] + 0x13e);
        }
        ppppppppiVar17 = (int ********)0x0;
        if (puVar33[10] != 0) {
          ppppppppiVar17 = (int ********)(uint)*(ushort *)(puVar33[10] + 0x13e);
        }
      }
      else {
        ppppppppiVar20 = (int ********)0x0;
      }
      if ((*(short *)((int)puVar33 + 6) == *(short *)((int)ppppppppiVar14 + 6)) &&
         (*(short *)((int)puVar33 + 6) == 0x2e)) {
        local_34 = (int ********)puVar33[9];
        local_38 = (int ********)((int)local_34 + 4);
        local_50 = ppppppppiVar20;
        local_30 = ppppppppiVar17;
        ppppppppiVar17 = (int ********)swap16(*(undefined2 *)(ppppppppiVar14[9] + 1));
        puVar23 = (undefined *)((int)local_34 + 4);
        local_34 = ppppppppiVar17;
        ppppppppiVar6 = (int ********)swap16(CONCAT11(*puVar23,*(undefined *)((int)local_38 + 1)));
        ppppppppiVar17 = local_30;
        ppppppppiVar20 = local_50;
        if (local_34 == ppppppppiVar6) goto LAB_00445214;
      }
      else {
LAB_00445214:
        if (((ppppppppiVar14[7] == (int *******)puVar33[7]) &&
            (((ppppppppiVar14[7] != (int *******)0x0 || (ppppppppiVar20 == ppppppppiVar17)) &&
             (*(short *)((int)puVar33 + 6) == *(short *)((int)ppppppppiVar14 + 6))))) &&
           (*(short *)(ppppppppiVar14 + 2) == *(short *)(puVar33 + 2))) {
          iVar36 = *(int *)(param_1 + 0x234);
          iVar11 = puVar33[0xd];
          if ((iVar36 - iVar11 < mDNSPlatformOneSecond) &&
             (ppppppppiVar17 = (int ********)puVar33[3],
             mDNSPlatformOneSecond < (iVar11 - iVar36) + (int)ppppppppiVar17 * mDNSPlatformOneSecond
             )) {
            ppppppppiVar20 = (int ********)ppppppppiVar14[3];
            if ((ppppppppiVar17 != ppppppppiVar20) && ((int ********)0x1 < ppppppppiVar20)) {
              if (ppppppppiVar17 == (int ********)0xf0) {
[32m                sVar16 = 0x10;[0m
                if (ppppppppiVar20 != (int ********)0x3c) goto LAB_004452d8;
LAB_004452d0:
                if (*(short *)((int)puVar33 + 6) != sVar16) goto LAB_004452d8;
              }
              else {
                if ((ppppppppiVar17 == (int ********)0x78) &&
[32m                   (sVar16 = 0x21, ppppppppiVar20 == (int ********)0x1194)) goto LAB_004452d0;[0m
LAB_004452d8:
                if ((*param_2 == 0) && (mDNS_LoggingEnabled != 0)) {
                  local_38 = ppppppppiVar20;
                  local_30 = ppppppppiVar17;
                  uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                  LogMsgWithLevel(3,"Correcting TTL from %4d to %4d for %s",local_30,local_38,uVar8)
                  ;
                }
              }
              puVar33[3] = ppppppppiVar14[3];
            }
            puVar33[0xd] = *(undefined4 *)(param_1 + 0x234);
          }
          else {
            if (iVar11 == iVar36) {
              iVar7 = puVar33[3];
              if (iVar7 == 1) {
                if (*(char *)(puVar33 + 0x13) != '\x04') goto LAB_004453b8;
                if (mDNS_LoggingEnabled != 0) {
                  uVar8 = GetRRDisplayString_rdb(puVar33 + 1,puVar33[9] + 4,iVar32);
                  LogMsgWithLevel(3,"Cache flush for DE record %s",uVar8);
                }
                puVar33[3] = 0;
                goto LAB_004453f8;
              }
            }
            else {
LAB_004453b8:
              iVar7 = puVar33[3];
            }
            if (mDNSPlatformOneSecond < (iVar11 - iVar36) + mDNSPlatformOneSecond * iVar7) {
              puVar33[3] = 1;
              *(undefined *)(puVar33 + 0x13) = 4;
              puVar33[0xd] = *(int *)(param_1 + 0x234) + -1;
            }
          }
LAB_004453f8:
          FUN_00428c90(param_1,puVar33);
        }
      }
    }
    if (ppppppppiVar14[0xe] != (int *******)0x0) {
      if (((param_2[3] != 0) && (iVar4 != 0)) && (local_878 != (int ******)0x0)) {
        ppppppppiVar17 = local_c0;
        if ((local_c0 == (int ********)0x0) &&
           (ppppppppiVar17 = ppppppppiVar14, mDNS_LoggingEnabled != 0)) {
          uVar8 = GetRRDisplayString_rdb(ppppppppiVar14 + 1,ppppppppiVar14[9] + 1,iVar32);
          LogMsgWithLevel(3,"mDNSCoreReceiveResponse: Updating NSECCachePtr to %s",uVar8);
        }
        iVar36 = AddNSECSForCacheRecord(param_1,local_878,ppppppppiVar17,local_ac);
        if (iVar36 == 0) {
          ppppppiVar35 = local_878;
          if (mDNS_LoggingEnabled != 0) {
            uVar8 = GetRRDisplayString_rdb(ppppppppiVar17 + 1,ppppppppiVar17[9] + 1,iVar32);
            LogMsgWithLevel(3,
                            "mDNSCoreReceiveResponse: AddNSECSForCacheRecord failed to add NSEC for %s"
                            ,uVar8);
            ppppppiVar35 = local_878;
          }
          while (ppppppiVar35 != (int ******)0x0) {
            ppppppiVar15 = (int ******)*ppppppiVar35;
            ReleaseCacheRecord(param_1,ppppppiVar35);
            ppppppiVar35 = ppppppiVar15;
          }
        }
        local_878 = (int ******)0x0;
        local_c0 = (int ********)0x0;
      }
      pppppppiVar38 =
           (int *******)FUN_004279b4(param_1,ppppppppiVar14[8],ppppppppiVar14[5],local_bc,0);
      ppppppppiVar14[0xe] = pppppppiVar38;
      if (pppppppiVar38 == (int *******)0x0) {
        FUN_00437804(param_1,ppppppppiVar14);
      }
      else {
        iVar36 = param_1 + ((int)local_bc + 0x2aa) * 4;
        if (0 < *(int *)(iVar36 + 4) - (int)pppppppiVar38) {
          *(int ********)(iVar36 + 4) = pppppppiVar38;
        }
        if (0 < *(int *)(param_1 + 0x248) - (int)pppppppiVar38) {
          *(int ********)(param_1 + 0x248) = pppppppiVar38;
        }
      }
    }
  }
  if ((local_878 != (int ******)0x0) && (local_c0 != (int ********)0x0)) {
    if (mDNS_LoggingEnabled != 0) {
      uVar8 = GetRRDisplayString_rdb(local_c0 + 1,local_c0[9] + 1,iVar32);
      LogMsgWithLevel(3,"mDNSCoreReceieveResponse: Updating NSEC records in %s",uVar8);
    }
    iVar4 = AddNSECSForCacheRecord(param_1,local_878,local_c0,local_ac);
    if (iVar4 == 0) {
      ppppppiVar35 = local_878;
      if (mDNS_LoggingEnabled != 0) {
        uVar8 = GetRRDisplayString_rdb(local_c0 + 1,local_c0[9] + 1,iVar32);
        LogMsgWithLevel(3,
                        "mDNSCoreReceiveResponse: AddNSECSForCacheRecord failed to add NSEC for %s",
                        uVar8);
        ppppppiVar35 = local_878;
      }
      while (ppppppiVar35 != (int ******)0x0) {
        ppppppiVar15 = (int ******)*ppppppiVar35;
        ReleaseCacheRecord(param_1,ppppppiVar35);
        ppppppiVar35 = ppppppiVar15;
      }
    }
    local_878 = (int ******)0x0;
  }
  if ((((param_2[3] != 0) && (local_8c == 0)) && (local_88 != 0)) && (local_878 == (int ******)0x0))
  {
    local_c0 = (int ********)auStack_5e0;
    iVar4 = 0;
    local_b8 = (ushort *)(uint)(param_6 == 0);
    puVar9 = local_b0;
    while (((iVar4 < (int)(uint)param_2[2] && (puVar9 != (ushort *)0x0)) && (puVar9 < puVar30))) {
      puVar9 = (ushort *)getQuestion(param_2,puVar9,puVar30,param_8,local_c0);
      if (((puVar9 != (ushort *)0x0) &&
          (pppppppiVar38 =
                (int *******)
                FUN_00427778(param_1,(uint)param_7._0_2_ << 0x10,(uint)*param_2 << 0x10,local_c0,
                             local_b8), pppppppiVar38 != (int *******)0x0)) &&
         (*(char *)(pppppppiVar38 + 0x33) != '\0')) {
        if (pppppppiVar38[0xf] != (int ******)0x0) {
          uVar8 = DNSTypeName(*(undefined2 *)(pppppppiVar38 + 0x95));
          LogMsgWithLevel(0,
                          "mDNSCoreReceiveNoDNSSECAnswers: ERROR!! qptr %##s (%s) Duplicate question matching response"
                          ,pppppppiVar38 + 0x55,uVar8);
        }
        iVar36 = *(int *)(param_1 + 0x28) + 1;
        *(int *)(param_1 + 0x28) = iVar36;
        if (*(int *)(param_1 + 0x24) != iVar36) {
          LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                          "mDNSCoreReceiveNoDNSSECAnswers",*(int *)(param_1 + 0x24),iVar36);
        }
        ppppppppiVar14 = (int ********)*pppppppiVar38;
        while ((ppppppppiVar17 = ppppppppiVar14, ppppppppiVar17 != (int ********)0x0 &&
               (ppppppppiVar17 != *(int *********)(param_1 + 0x2b0)))) {
          local_bc = (int ********)*ppppppppiVar17;
          ppppppppiVar14 = local_bc;
          if (ppppppppiVar17[0xf] == pppppppiVar38) {
            if (*(char *)(ppppppppiVar17 + 0x33) == '\0') {
              uVar8 = DNSTypeName(*(undefined2 *)(ppppppppiVar17 + 0x95));
              pcVar21 = 
              "mDNSCoreReceiveNoDNSSECAnswers: ERROR!! qptr %##s (%s) Duplicate question not ValidatingResponse"
              ;
              uVar13 = 0;
LAB_00445878:
              LogMsgWithLevel(uVar13,pcVar21,ppppppppiVar17 + 0x55,uVar8);
            }
            else if (mDNS_LoggingEnabled != 0) {
              uVar8 = DNSTypeName(*(undefined2 *)(ppppppppiVar17 + 0x95));
              uVar13 = 3;
              pcVar21 = "mDNSCoreReceiveNoDNSSECAnswers: qptr %##s (%s) Duplicate question found";
              goto LAB_00445878;
            }
            ppppppppiVar14 = local_bc;
            if (ppppppppiVar17[0xa2] != (int *******)0x0) {
              (*(code *)ppppppppiVar17[0xa2])(param_1,ppppppppiVar17,0,5);
              ppppppppiVar14 = local_bc;
            }
          }
        }
        if (pppppppiVar38[0xa2] != (int ******)0x0) {
          (*(code *)pppppppiVar38[0xa2])(param_1,pppppppiVar38,0,5);
        }
        iVar36 = *(int *)(param_1 + 0x28);
        if (*(int *)(param_1 + 0x24) != iVar36) {
          LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                          "mDNSCoreReceiveNoDNSSECAnswers",*(int *)(param_1 + 0x24),iVar36);
          iVar36 = *(int *)(param_1 + 0x28);
        }
        *(int *)(param_1 + 0x28) = iVar36 + -1;
      }
      iVar4 = iVar4 + 1;
    }
  }
  local_b4 = auStack_350;
  local_bc = (int ********)puVar30;
  local_c0 = (int ********)0x0;
  local_b8 = (ushort *)0x0;
  local_a4 = param_8;
  ppppppiVar35 = local_878;
  do {
    if ((((int)(uint)param_2[2] <= (int)local_b8) || (local_b0 == (ushort *)0x0)) ||
       (local_bc <= local_b0)) {
      if (ppppppiVar35 != (int ******)0x0) {
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,"mDNSCoreReceiveNoUnicastAnswers: NSECRecords not used");
        }
        while (ppppppiVar35 != (int ******)0x0) {
          ppppppiVar15 = (int ******)*ppppppiVar35;
          ReleaseCacheRecord(param_1,ppppppiVar35);
          ppppppiVar35 = ppppppiVar15;
        }
      }
      piVar29 = local_874;
      if (local_c0 != (int ********)0x0) {
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,"mDNSCoreReceiveNoUnicastAnswers: SOARecord not used");
        }
        ReleaseCacheRecord(param_1,local_c0);
        piVar29 = local_874;
      }
      while (piVar29 != (int *)0x0) {
        piVar29 = (int *)*piVar29;
        ReleaseCacheRecord(param_1);
      }
      return;
    }
    local_b0 = (ushort *)getQuestion(param_2,local_b0,local_bc,local_a4,local_b4);
    if ((local_b0 != (ushort *)0x0) &&
       (iVar4 = FUN_00427778(param_1,(uint)param_7._0_2_ << 0x10,(uint)*param_2 << 0x10,local_b4,
                             param_6 == 0), iVar4 != 0)) {
      local_38 = local_1fc;
      puVar33 = (undefined4 *)0x0;
      uVar10 = DomainNameHashValue(local_38);
      uVar10 = uVar10 % 499;
      iVar36 = CacheGroupForName(param_1,uVar10,local_34c,local_38);
      if (iVar36 != 0) {
        puVar33 = *(undefined4 **)(iVar36 + 8);
      }
      puVar37 = (undefined4 *)0x0;
      for (; puVar33 != (undefined4 *)0x0; puVar33 = (undefined4 *)*puVar33) {
        iVar36 = SameNameRecordAnswersQuestion(puVar33 + 1,iVar4);
        if (iVar36 != 0) {
          if (0 < (puVar33[0xd] - *(int *)(param_1 + 0x234)) + puVar33[3] * mDNSPlatformOneSecond)
          break;
          if (*(char *)(puVar33 + 1) == -0x10) {
            puVar37 = puVar33;
          }
        }
      }
      if (((local_a4 == 0) && (local_fc != 6)) &&
         (local_34 = local_1fc, iVar36 = IsLocalDomain(local_1fc), iVar36 != 0)) {
        if (puVar33 == (undefined4 *)0x0) {
          if (mDNS_LoggingEnabled != 0) {
            uVar8 = DNSTypeName(local_fc);
            LogMsgWithLevel(3,
                            "mDNSCoreReceiveNoUnicastAnswers: Generate negative response for %##s (%s)"
                            ,local_34,uVar8);
          }
          *(int *)(param_1 + 0x2b4) = iVar4;
          if (*(char *)(iVar4 + 0x267) != '\0') {
            *(ushort *)(iVar4 + 300) = param_2[1];
          }
          FUN_004378f4(param_1,3);
          *(undefined4 *)(param_1 + 0x2b4) = 0;
        }
        else if (mDNS_LoggingEnabled != 0) {
          uVar8 = DNSTypeName(local_fc);
          LogMsgWithLevel(3,
                          "mDNSCoreReceiveNoUnicastAnswers: Skipping check and not creating a negative cache entry for %##s (%s)"
                          ,local_34,uVar8);
        }
      }
      else if (puVar33 == (undefined4 *)0x0) {
        local_a8 = local_34c;
        if (local_fc == 6) {
          iVar36 = SameDomainName(local_1fc,&DAT_0044d544);
          uVar39 = 0x15180;
          if (iVar36 == 0) goto LAB_00445bd0;
        }
        else {
LAB_00445bd0:
          uVar39 = 0x3c;
        }
        iVar36 = 0;
        if (param_2[4] != 0) {
          iVar11 = LocateAuthorities(param_2,local_bc);
          if (iVar11 == 0) {
            local_b0 = (ushort *)0x0;
          }
          else {
            local_b0 = (ushort *)
                       GetLargeResourceRecord
                                 (param_1,param_2,iVar11,local_bc,local_a4,0xa0,local_a0);
            if ((local_b0 == (ushort *)0x0) || (*(char *)(param_1 + 0x7fac) == -0x10)) {
LAB_00445d7c:
              iVar36 = 0;
            }
            else {
              iVar36 = 0;
              if (*(short *)(param_1 + 0x7fae) == 6) {
                uVar12 = DomainNameHashValue(*(undefined4 *)(param_1 + 0x7fc8));
                uVar8 = CacheGroupForName(param_1,uVar12 % 499,*(undefined4 *)(param_1 + 0x7fbc),
                                          *(undefined4 *)(param_1 + 0x7fc8));
                uVar22 = *(uint *)(*(int *)(param_1 + 0x7fcc) + 0x214);
                if ((uVar22 <= *(uint *)(param_1 + 0x7fb4)) ||
                   (uVar18 = *(uint *)(param_1 + 0x7fb4), **(char **)(param_1 + 0x7fc8) == '\0')) {
                  uVar18 = uVar22;
                }
                if (uVar39 < uVar18) {
                  uVar39 = uVar18;
                }
                local_c0 = (int ********)CreateNewCacheEntry(param_1,uVar12 % 499,uVar8,1,0,0);
                if (*(char *)(iVar4 + 0x267) == '\0') {
                  iVar36 = 0;
                  if (local_fc != 6) goto LAB_00445d80;
                  local_30 = (int ********)CountLabels(local_1fc);
                  iVar11 = CountLabels(*(undefined4 *)(param_1 + 0x7fc8));
                  if (iVar11 < (int)((int)local_30 + -1)) {
                    iVar36 = ((int)local_30 - iVar11) + -1;
                    uVar8 = SkipLeadingLabels(local_1fc,(int)local_30 - iVar11);
                    iVar11 = SameDomainName(uVar8,*(undefined4 *)(param_1 + 0x7fc8));
                    if (iVar11 != 0) goto LAB_00445d80;
                  }
                }
                goto LAB_00445d7c;
              }
            }
LAB_00445d80:
            *(undefined *)(param_1 + 0x7fac) = 0;
          }
        }
        if (puVar37 != (undefined4 *)0x0) {
          uVar12 = puVar37[3] << 1;
          if ((uint)(puVar37[3] << 1) <= uVar39) {
            uVar12 = uVar39;
          }
          uVar39 = 0xe10;
          if (uVar12 < 0xe11) {
            uVar39 = uVar12;
          }
        }
        uVar8 = FUN_0042678c(local_98,uVar39);
        if (puVar37 == (undefined4 *)0x0) {
          pppppppiVar38 = (int *******)local_1fc;
          local_9c = 0;
LAB_00445f68:
          MakeNegativeCacheRecord
                    (param_1,local_a0,pppppppiVar38,local_a8,local_fc,local_fa,uVar8,local_9c,
                     *(undefined4 *)(iVar4 + 0xdc));
          *(ushort *)(param_1 + 0x7ff6) = param_2[1];
          uVar13 = CacheGroupForName(param_1,uVar10,local_a8,pppppppiVar38);
          if ((ppppppiVar35 == (int ******)0x0) ||
             (((*(char *)(iVar4 + 0x266) == '\0' && (*(char *)(iVar4 + 0xcc) == '\0')) &&
              ((*(char *)(iVar4 + 0x267) == '\0' || (*(char *)(iVar4 + 0x268) == '\0')))))) {
            ppppppppiVar14 = (int ********)CreateNewCacheEntry(param_1,uVar10,uVar13,1,1,0);
            if (ppppppppiVar14 != (int ********)0x0) {
              *(undefined *)((int)ppppppppiVar14 + 0x4d) = 0;
              if (((*(char *)(iVar4 + 0x266) != '\0') || (*(char *)(iVar4 + 0xcc) != '\0')) ||
                 ((*(char *)(iVar4 + 0x267) != '\0' && (*(char *)(iVar4 + 0x268) != '\0')))) {
                *(undefined *)((int)ppppppppiVar14 + 0x4d) = 1;
              }
              ppppppppiVar14[0xe] = (int *******)0x0;
              if (local_c0 != (int ********)0x0) {
                if (ppppppppiVar14[0x16] != (int *******)0x0) {
                  local_50 = ppppppppiVar14;
                  ReleaseCacheRecord(param_1);
                  ppppppppiVar14 = local_50;
                }
                ppppppppiVar14[0x16] = (int *******)local_c0;
              }
              local_c0 = (int ********)0x0;
              FUN_00437804(param_1,ppppppppiVar14);
            }
            *(undefined *)(param_1 + 0x7fac) = 0;
            *(undefined2 *)(param_1 + 0x7ff6) = 0;
            if (iVar36 != 0) goto code_r0x004461c4;
          }
          else {
            iVar4 = CreateNewCacheEntry(param_1,uVar10,uVar13,1,1,0);
            if (iVar4 != 0) {
              *(undefined *)(iVar4 + 0x4d) = 0;
              iVar36 = AddNSECSForCacheRecord(param_1,ppppppiVar35,iVar4,local_ac);
              if (iVar36 == 0) {
                if (mDNS_LoggingEnabled != 0) {
                  uVar8 = GetRRDisplayString_rdb(iVar4 + 4,*(int *)(iVar4 + 0x24) + 4,iVar32);
                  LogMsgWithLevel(3,
                                  "mDNSCoreReceiveNoUnicastAnswers: AddNSECSForCacheRecord failed to add NSEC for negcr %s"
                                  ,uVar8);
                }
                do {
                  ppppppiVar15 = (int ******)*ppppppiVar35;
                  ReleaseCacheRecord(param_1,ppppppiVar35);
                  ppppppiVar35 = ppppppiVar15;
                } while (ppppppiVar15 != (int ******)0x0);
                *(undefined4 *)(iVar4 + 0x38) = 0;
              }
              else {
                *(undefined *)(iVar4 + 0x4d) = 1;
                if (mDNS_LoggingEnabled != 0) {
                  uVar8 = GetRRDisplayString_rdb(iVar4 + 4,*(int *)(iVar4 + 0x24) + 4,iVar32);
                  LogMsgWithLevel(3,
                                  "mDNSCoreReceiveNoUnicastAnswers: AddNSECSForCacheRecord added neg NSEC for %s"
                                  ,uVar8);
                }
                *(undefined4 *)(iVar4 + 0x38) = 0;
              }
              ppppppiVar35 = (int ******)0x0;
              FUN_00437804(param_1,iVar4);
            }
            *(undefined *)(param_1 + 0x7fac) = 0;
          }
          goto LAB_00446210;
        }
        if (mDNS_LoggingEnabled != 0) {
          uVar34 = puVar37[3];
          uVar13 = GetRRDisplayString_rdb(puVar37 + 1,puVar37[9] + 4,iVar32);
          LogMsgWithLevel(3,
                          "mDNSCoreReceiveNoUnicastAnswers: Renewing negative TTL from %d to %d %s",
                          uVar34,uVar8,uVar13);
        }
        uVar13 = *(undefined4 *)(param_1 + 0x234);
        puVar37[3] = uVar8;
        puVar37[0xd] = uVar13;
        *(undefined *)(puVar37 + 0x13) = 0;
        FUN_00428c90(param_1,puVar37);
        *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(param_1 + 0x234);
        uVar8 = *(undefined4 *)(param_1 + 0x234);
        *(undefined4 *)(iVar4 + 0x1c) = 0;
        *(undefined4 *)(iVar4 + 0xb4) = uVar8;
        iVar36 = mDNSPlatformOneSecond * 0xe10;
        *(undefined4 *)(iVar4 + 0xb0) = 0;
        *(undefined *)(iVar4 + 0xec) = 0;
        *(int *)(iVar4 + 0x10) = iVar36;
        if (((*(char *)(iVar4 + 0x266) != '\0') || (*(char *)(iVar4 + 0xcc) != '\0')) ||
           ((*(char *)(iVar4 + 0x267) != '\0' && (*(char *)(iVar4 + 0x268) != '\0')))) {
          *(undefined *)((int)puVar37 + 0x4d) = 1;
        }
        if ((ppppppiVar35 != (int ******)0x0) &&
           (iVar4 = AddNSECSForCacheRecord(param_1,ppppppiVar35,puVar37,local_ac), iVar4 == 0)) {
          if (mDNS_LoggingEnabled != 0) {
            uVar8 = GetRRDisplayString_rdb(puVar37 + 1,puVar37[9] + 4,iVar32);
            LogMsgWithLevel(3,
                            "mDNSCoreReceiveNoUnicastAnswers: AddNSECSForCacheRecord failed to add NSEC for negcr %s during refresh"
                            ,uVar8);
          }
          do {
            ppppppiVar15 = (int ******)*ppppppiVar35;
            ReleaseCacheRecord(param_1,ppppppiVar35);
            ppppppiVar35 = ppppppiVar15;
          } while (ppppppiVar15 != (int ******)0x0);
          *(undefined *)((int)puVar37 + 0x4d) = 0;
        }
        ppppppiVar35 = (int ******)0x0;
        if (local_c0 != (int ********)0x0) {
          if (puVar37[0x16] != 0) {
            ReleaseCacheRecord(param_1);
          }
          ppppppiVar35 = (int ******)0x0;
          puVar37[0x16] = local_c0;
          local_c0 = (int ********)0x0;
        }
      }
    }
LAB_00446210:
    local_b8 = (ushort *)((int)local_b8 + 1);
  } while( true );
LAB_00444de8:
  if (puVar33 == (undefined4 *)0x0) goto LAB_00444e6c;
  if (((puVar33[0xf] == 0) && (*(char *)(puVar33 + 0x96) == '\0')) &&
     ((0 < (int)puVar33[4] &&
      (local_30 = ppppppppiVar17, iVar11 = ResourceRecordAnswersQuestion(ppppppppiVar17,puVar33),
      ppppppppiVar17 = local_30, iVar11 != 0)))) {
    puVar33[3] = *(undefined4 *)(param_1 + 0x234);
    uVar8 = *(undefined4 *)(param_1 + 0x234);
    puVar33[7] = 0;
    puVar33[0x2d] = uVar8;
    iVar11 = mDNSPlatformOneSecond;
    *(undefined *)(puVar33 + 0x3b) = 0;
    puVar33[0x2c] = 0;
    puVar33[4] = iVar11 * 0xe10;
    goto LAB_00444e6c;
  }
  puVar33 = (undefined4 *)*puVar33;
  goto LAB_00444de8;
LAB_00444e6c:
  local_bc = ppppppppiVar14;
  if ((*(int ********)((int)pcVar21 + 0x2c) != (int *******)0x0) &&
     (*(int *)(param_1 + 0x7fd4) != 0)) {
    pcVar40 = CopyAnonInfoForCR;
    iVar7 = param_1;
    iVar11 = (int)local_a0;
LAB_00445084:
    (*pcVar40)(iVar7,pcVar21,iVar11);
  }
LAB_0044508c:
  FUN_0042cb28(param_1);
  local_9c = local_9c + 1;
  goto LAB_004450a4;
code_r0x004461c4:
  iVar36 = iVar36 + -1;
  pppppppiVar38 = (int *******)((int)pppppppiVar38 + *(byte *)pppppppiVar38 + 1);
  local_a8 = (undefined4 *)DomainNameHashValue(pppppppiVar38);
  uVar10 = DomainNameHashValue(pppppppiVar38);
  uVar10 = uVar10 % 499;
  goto LAB_00445f68;
}

[ASK_GPT] 30fc7fdd42b1ed4d
