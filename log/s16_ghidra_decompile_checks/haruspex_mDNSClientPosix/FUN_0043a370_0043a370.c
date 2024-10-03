
/* WARNING: Could not reconcile some variable overlaps */

void FUN_0043a370(int param_1,undefined6 *param_2,uint param_3,uint param_4,byte param_5,int param_6
                 ,ushort *param_7,ushort *param_8,uint *param_9,ushort param_10)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  char *pcVar4;
  undefined6 *puVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  short sVar11;
  int iVar10;
  char *pcVar12;
  uint **ppuVar13;
  char *pcVar14;
  char *pcVar15;
  undefined1 *puVar16;
  undefined *puVar17;
  uint **ppuVar18;
  undefined4 *puVar19;
  uint **ppuVar20;
  int *piVar21;
  undefined4 *puVar22;
  uint uVar23;
  ushort uVar24;
  uint uVar25;
  ushort *puVar26;
  ushort local_f0 [2];
  ushort local_ec;
  short local_ea;
  short local_e8 [2];
  short local_e4 [2];
  uint local_e0;
  uint local_dc;
  int local_d8;
  uint local_d4;
  uint local_d0;
  undefined4 local_cc;
  int local_c8;
  undefined auStack_c4 [8];
  undefined auStack_bc [8];
  uint *local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint **local_60;
  int *local_5c;
  uint **local_58;
  uint **local_54;
  uint *local_50;
  int *local_4c;
  undefined *local_48;
  uint *local_44;
  uint *local_40;
  ushort *local_3c;
  ushort *local_38;
  short *local_34;
  uint **local_30;
  uint local_2c;
  
  uVar25 = (uint)param_5;
  if (uVar25 == 6) {
    ppuVar20 = (uint **)(uint)param_7[1];
LAB_0043a478:
    local_5c = &local_a0;
    local_58 = &local_b4;
    local_4c = &local_d8;
    local_48 = auStack_c4;
    local_3c = local_f0;
    local_38 = &local_ec;
    local_50 = (uint *)(uint)*param_7;
    local_44 = &local_d4;
    local_34 = &local_ea;
    local_40 = &local_d0;
    local_54 = ppuVar20;
    for (puVar22 = *(undefined4 **)(param_1 + 0x2160); puVar22 != (undefined4 *)0x0;
        puVar22 = (undefined4 *)*puVar22) {
      local_d0 = 0;
      local_d4 = 0;
      local_d8 = 0;
[32m      local_ea = 0;[0m
[32m[32m      memcpy(local_5c,zeroAddr,0x14);[0m[0m
[32m[32m      memcpy(local_58,local_5c,0x14);[0m[0m
      local_f0[0] = 0;
      local_ec = local_f0[0];
      if (((((*(int *)((int)puVar22 + 0x4e) != 0) &&
            (FUN_0042ac48(puVar22,local_4c,local_58,local_5c,local_48,local_44,local_40,local_3c,
                          local_38,local_34), local_d8 != 0)) &&
           (((iVar6 = local_b0, local_b4 != (uint *)0x4 &&
             ((((local_b4 != (uint *)0x6 || (local_ac != 0)) || (local_b0 != 0)) ||
              (iVar6 = local_a4, local_a8 != 0)))) || (iVar6 != 0)))) &&
          (((iVar6 = local_9c, local_a0 != 4 &&
            (((local_a0 != 6 || (local_98 != 0)) ||
             ((local_9c != 0 || (iVar6 = local_90, local_94 != 0)))))) || (iVar6 != 0)))) &&
         (((local_d4 != 0 && (local_d0 != 0)) &&
          ((local_f0[0] != 0 &&
           (((((local_ec != 0 && (local_ea != 0)) &&
              (iVar6 = mDNSSameAddress(local_58,param_4), iVar6 != 0)) &&
             ((iVar6 = mDNSSameAddress(local_5c,param_3), iVar6 != 0 &&
              ((uint **)(uint)local_f0[0] == local_54)))) && ((uint *)(uint)local_ec == local_50))))
          )))) {
        local_e0 = local_d4;
        local_dc = local_d0;
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(2,
                          "mDNSCoreReceiveRawTransportPacket: Found a Keepalive record from %#a:%d  to %#a:%d"
                          ,param_3,*param_7,param_4,ppuVar20);
        }
        if ((*(byte *)((int)param_7 + 0xd) & 5) != 0) {
          if (mDNS_LoggingEnabled == 0) {
            uVar23 = 1;
          }
          else {
            LogMsgWithLevel(2,
                            "mDNSCoreReceiveRawTransportPacket: waking because of RST or FIN th_flags %d"
                           );
            uVar23 = 1;
          }
          goto LAB_0043b61c;
        }
        local_d8 = *(int *)(param_7 + 4);
        local_d4 = *(uint *)(param_7 + 2);
        bVar2 = *(byte *)(param_7 + 6);
        local_e0 = local_e0 & 0xff0000ff | (local_e0 >> 0x10 & 0xff) << 0x10 |
                   (local_e0 >> 8 & 0xff) << 8;
        local_60 = (uint **)((uint)(bVar2 >> 4) * 4);
        local_dc = local_dc & 0xff0000ff | (local_dc >> 0x10 & 0xff) << 0x10 |
                   (local_dc >> 8 & 0xff) << 8;
        uVar9 = (uint)(0 < (int)param_8 - (int)(param_7 + (uint)(bVar2 >> 4) * 2));
        if (((int)(local_d8 - local_e0) < 1) || (uVar23 = uVar9, (int)(local_d4 - local_dc) < 0)) {
          uVar23 = 0;
        }
        if ((((*(byte *)((int)param_7 + 0xd) & 0x10) != 0) && (uVar9 == 0)) &&
           (local_d4 == local_dc - 1)) {
          local_c8 = 0;
          local_cc = 0;
          local_d0 = 0;
[32m          local_ea = 0;[0m
          local_5c = &local_8c;
          local_2c = uVar23;
[32m[32m          memcpy(&local_78,zeroAddr,0x14);[0m[0m
[32m[32m          memcpy(local_5c,&local_78,0x14);[0m[0m
          local_e8[0] = 0;
          local_e4[0] = local_e8[0];
          FUN_0042ac48(puVar22,&local_d0,local_5c,&local_78,auStack_bc,&local_cc,&local_c8,local_e8,
                       local_e4,&local_ea);
          if ((local_d0 == 0) ||
             ((((local_8c == 4 ||
                (((local_8c == 6 && (local_84 == 0)) &&
                 ((local_88 == 0 && (local_88 = local_7c, local_80 == 0)))))) && (local_88 == 0)) ||
              ((((local_78 == 4 ||
                 (((local_78 == 6 && (local_70 == 0)) &&
                  ((local_74 == 0 && (local_74 = local_68, local_6c == 0)))))) && (local_74 == 0))
               || ((((local_cc == 0 || (local_c8 == 0)) || (local_e8[0] == 0)) ||
                   ((local_e4[0] == 0 || (local_ea == 0)))))))))) {
            uVar23 = local_2c;
            if (mDNS_LoggingEnabled != 0) {
              uVar8 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,param_1 + 0x2f);
              LogMsgWithLevel(3,"mDNS_SendKeepaliveACK: not a valid record %s for keepalive",uVar8);
              uVar23 = local_2c;
            }
          }
          else {
            uVar23 = (local_cc & 0xff0000ff | (local_cc >> 0x10 & 0xff) << 0x10 |
                     (local_cc >> 8 & 0xff) << 8) + 1;
            local_cc._1_3_ = (uint3)uVar23 & 0xff00ff;
            local_cc._2_2_ = CONCAT11((char)(uVar23 >> 8),(undefined)local_cc);
            local_cc = uVar23 & 0xff000000 | local_cc._1_3_ & 0xffff0000 | (uint)local_cc._2_2_;
            LogMsgWithLevel(0,"mDNS_SendKeepaliveACK: laddr %#a raddr %#a lport %d rport %d",
                            &local_8c,&local_78,local_e8[0],local_e4[0]);
            mDNSPlatformSendKeepalive
                      (&local_8c,&local_78,local_e8,local_e4,local_cc,local_c8,local_ea);
            uVar23 = local_2c;
          }
        }
        uVar9 = uVar23;
        if (mDNS_LoggingEnabled != 0) {
          local_2c = uVar23;
          LogMsgWithLevel(2,
                          "mDNSCoreReceiveRawTransportPacket: End %p, hlen %d, Datalen %d, pack %u, seq %u, pseq %u, ack %u, wake %d"
                          ,param_8,local_60,(int)param_8 - (int)(param_7 + (uint)(bVar2 >> 4) * 2),
                          local_d8,local_e0,local_d4,local_dc,uVar23);
          uVar9 = local_2c;
        }
        goto LAB_0043b614;
      }
    }
    uVar9 = 0;
    bVar2 = *(byte *)((int)param_7 + 0xd);
    if ((bVar2 & 4) == 0) {
      uVar9 = (uint)((bVar2 & 3) != 1);
    }
    if ((ppuVar20 != (uint **)0x16) && ((bVar2 & 2) == 0)) {
      uVar9 = 0;
    }
    uVar23 = 0;
    if (mDNS_LoggingEnabled != 0) {
      if (uVar9 == 0) {
        pcVar12 = "Ignoring";
      }
      else {
        pcVar12 = "Received";
      }
      if ((bVar2 & 2) == 0) {
        pcVar15 = "";
      }
      else {
        pcVar15 = " SYN";
      }
      if ((bVar2 & 1) == 0) {
        pcVar14 = "";
      }
      else {
        pcVar14 = " FIN";
      }
      if ((bVar2 & 4) == 0) {
        pcVar4 = "";
      }
      else {
        pcVar4 = " RST";
      }
      uVar23 = 0;
      local_2c = uVar9;
      LogMsgWithLevel(2,"%s %d-byte TCP from %#a:%d to %#a:%d%s%s%s",pcVar12,(int)param_8 - param_6,
                      param_3,*param_7,param_4,ppuVar20,pcVar15,pcVar14,pcVar4);
      uVar9 = local_2c;
    }
  }
  else {
    if (uVar25 != 0x11) {
      ppuVar20 = (uint **)0x0;
      if (uVar25 != 6) {
        if (uVar25 < 7) {
          if (uVar25 == 1) {
            if (mDNS_LoggingEnabled == 0) {
              return;
            }
            pcVar12 = "Ignoring %d-byte ICMP from %#a to %#a";
            uVar25 = param_3;
            param_3 = param_4;
            goto LAB_0043b604;
          }
        }
        else {
          if (uVar25 == 0x11) goto LAB_0043ac80;
          if (uVar25 == 0x3a) {
            piVar21 = (int *)(param_3 + 4);
            if (param_8 < (ushort *)((int)param_7 + (uint)param_10)) {
              return;
            }
            iVar6 = FUN_004262ac(piVar21,param_4 + 4,0x3a,param_7,(uint)param_10);
            if (iVar6 != 0) {
              if (mDNS_LoggingEnabled == 0) {
                return;
              }
              LogMsgWithLevel(3,"IPv6CheckSum bad %04X %02X%02X from %#a to %#a",iVar6,
                              *(char *)(param_7 + 1),*(char *)((int)param_7 + 3),param_3,param_4);
              return;
            }
            puVar22 = *(undefined4 **)(param_1 + 0x2174);
            while( true ) {
              if (puVar22 == (undefined4 *)0x0) {
                return;
              }
              local_50 = (uint *)puVar22[0x548];
              if (local_50 == param_9) break;
              puVar22 = (undefined4 *)*puVar22;
            }
            mDNS_Lock_(param_1,"mDNSCoreReceiveRawND");
            if (*(char *)param_7 == -0x79) {
              local_60 = (uint **)(param_1 + 0x2f);
              local_5c = (int *)((int)puVar22 + 0x1552);
              for (puVar19 = *(undefined4 **)(param_1 + 0x2160); puVar19 != (undefined4 *)0x0;
                  puVar19 = (undefined4 *)*puVar19) {
                if (((((uint *)puVar19[7] == param_9) && (*(char *)(puVar19 + 1) != '\x01')) &&
                    (puVar19[0x18] == 6)) &&
                   (((puVar19[0x19] == *(int *)(param_7 + 4) &&
                     (puVar19[0x1a] == *(int *)(param_7 + 6))) &&
                    ((puVar19[0x1b] == *(int *)(param_7 + 8) &&
                     (puVar19[0x1c] == *(int *)(param_7 + 10))))))) {
                  if ((((param_2 == (undefined6 *)0x0) ||
                       (*(short *)(puVar19 + 0x15) != *(short *)param_2)) ||
                      ((*(short *)((int)puVar19 + 0x56) != *(short *)((int)param_2 + 2) ||
                       (pcVar12 = "NDP Req from owner -- re-probing",
                       *(short *)(puVar19 + 0x16) != *(short *)((int)param_2 + 4))))) &&
                     ((pcVar12 = "Ignoring  NDP Request from      ",
                      *(char *)((int)puVar19 + 0x87) != '\x04' &&
                      (((((param_2 == (undefined6 *)0x0 ||
                          (*(short *)(puVar22 + 0x553) != *(short *)param_2)) ||
                         (*(short *)((int)puVar22 + 0x154e) != *(short *)((int)param_2 + 2))) ||
                        (pcVar12 = "Creating Local NDP Cache entry  ",
                        *(short *)(puVar22 + 0x554) != *(short *)((int)param_2 + 4))) &&
                       (((piVar21 == (int *)0x0 || (*(int *)(param_3 + 8) != 0)) ||
                        ((*piVar21 != 0 ||
                         ((*(int *)(param_3 + 0xc) != 0 ||
                          (pcVar12 = "Answering NDP Request from      ",
                          *(int *)(param_3 + 0x10) != 0)))))))))))) {
                    pcVar12 = "Answering NDP Probe   from      ";
                  }
                  if (mDNS_LoggingEnabled != 0) {
                    uVar8 = GetRRDisplayString_rdb(puVar19 + 1,puVar19[9] + 4,local_60);
                    LogMsgWithLevel(2,"%-7s %s %.6a %.16a for %.16a -- H-MAC %.6a I-MAC %.6a %s",
                                    local_5c,pcVar12,param_2,piVar21,param_7 + 4,(int)puVar19 + 0x4e
                                    ,puVar19 + 0x15,uVar8);
                  }
                  if (pcVar12 == "NDP Req from owner -- re-probing") {
                    if (*(byte *)((int)puVar19 + 0x85) < 0x14) {
                      FUN_00428af8(param_1,puVar19);
                    }
                    else if (mDNS_LoggingEnabled != 0) {
                      uVar8 = GetRRDisplayString_rdb(puVar19 + 1,puVar19[9] + 4,local_60);
                      LogMsgWithLevel(2,"Reached maximum number of restarts for probing - %s",uVar8)
                      ;
                    }
                  }
                  else if (pcVar12 == "Creating Local NDP Cache entry  ") {
                    mDNSPlatformSetLocalAddressCacheEntry
                              (param_1,puVar19 + 0x18,puVar19 + 0x15,param_9);
                  }
                  else {
                    if (pcVar12 == "Answering NDP Request from      ") {
                      uVar8 = 0x40;
                      puVar16 = (undefined1 *)piVar21;
                      puVar5 = param_2;
                    }
                    else {
                      if (pcVar12 != "Answering NDP Probe   from      ") goto LAB_0043b214;
                      puVar16 = AllHosts_v6;
                      puVar5 = &AllHosts_v6_Eth;
                      uVar8 = 0;
                    }
                    FUN_0042989c(param_1,0x88,uVar8,puVar19,param_7 + 4,0,puVar16,puVar5);
                  }
                }
LAB_0043b214:
              }
            }
            if (((*(short *)(puVar22 + 0x553) != *(short *)param_2) ||
                (*(short *)((int)puVar22 + 0x154e) != *(short *)((int)param_2 + 2))) ||
               (*(short *)(puVar22 + 0x554) != *(short *)((int)param_2 + 4))) {
              if (*(char *)param_7 == -0x78) {
                piVar21 = (int *)(param_7 + 4);
              }
              if (((*piVar21 != 0) || (piVar21[1] != 0)) || ((piVar21[2] != 0 || (piVar21[3] != 0)))
                 ) {
                iVar6 = (int)puVar22 + 0x1552;
                puVar26 = param_7 + 4;
                local_54 = (uint **)0x0;
                local_5c = (int *)0x0;
                local_58 = (uint **)0x0;
                iVar10 = param_1 + 0x2f;
                for (puVar22 = *(undefined4 **)(param_1 + 0x2160); puVar22 != (undefined4 *)0x0;
                    puVar22 = (undefined4 *)*puVar22) {
                  if ((((uint *)puVar22[7] == local_50) && (*(char *)(puVar22 + 1) != '\x01')) &&
                     ((puVar22[0x18] == 6 &&
                      ((((puVar22[0x19] == *piVar21 && (puVar22[0x1a] == piVar21[1])) &&
                        (puVar22[0x1b] == piVar21[2])) &&
                       ((puVar22[0x1c] == piVar21[3] && (*(byte *)((int)puVar22 + 0x85) < 0x14))))))
                     )) {
                    if (((int *)(uint)*(ushort *)((int)puVar22 + 0x4e) == local_5c) &&
                       (((uint **)(uint)*(ushort *)(puVar22 + 0x14) == local_58 &&
                        ((uint **)(uint)*(ushort *)((int)puVar22 + 0x52) == local_54)))) {
                      if (mDNS_LoggingEnabled != 0) {
                        uVar8 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,iVar10);
                        LogMsgWithLevel(2,
                                        "%-7s NDP from %.6a %.16a for %.16a -- Invalid H-MAC %.6a I-MAC %.6a %s"
                                        ,iVar6,param_2,piVar21,puVar26,(int)puVar22 + 0x4e,
                                        puVar22 + 0x15,uVar8);
                      }
                    }
                    else {
                      FUN_00428af8(param_1,puVar22);
                      if ((*(short *)(puVar22 + 0x15) == *(short *)param_2) &&
                         ((*(short *)((int)puVar22 + 0x56) == *(short *)((int)param_2 + 2) &&
                          (*(short *)(puVar22 + 0x16) == *(short *)((int)param_2 + 4))))) {
                        if (mDNS_LoggingEnabled != 0) {
                          local_30 = (uint **)"Advertisement";
                          if (*(char *)param_7 == -0x79) {
                            local_30 = (uint **)"Solicitation ";
                          }
                          uVar8 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,iVar10);
                          LogMsgWithLevel(2,
                                          "%-7s NDP %s from owner %.6a %.16a for %.16a -- re-starting probing for %s"
                                          ,iVar6,local_30,param_2,piVar21,puVar26,uVar8);
                        }
                      }
                      else {
                        local_60 = (uint **)((int)puVar22 + 0x4e);
                        uVar8 = GetRRDisplayString_rdb(puVar22 + 1,puVar22[9] + 4,iVar10);
                        LogMsgWithLevel(0,
                                        "%-7s Conflicting NDP from %.6a %.16a for %.16a -- waking H-MAC %.6a I-MAC %.6a %s"
                                        ,iVar6,param_2,piVar21,puVar26,local_60,puVar22 + 0x15,uVar8
                                       );
                        FUN_0043a2d8(param_1,puVar22[7],local_60);
                      }
                    }
                  }
                }
              }
            }
            pcVar12 = "mDNSCoreReceiveRawND";
            goto LAB_0043b8b8;
          }
        }
        if (mDNS_LoggingEnabled == 0) {
          return;
        }
        pcVar12 = "Ignoring %d-byte IP packet unknown protocol %d from %#a to %#a";
LAB_0043b604:
        LogMsgWithLevel(2,pcVar12,(int)param_8 - param_6,uVar25,param_3);
        return;
      }
      goto LAB_0043a478;
    }
    ppuVar20 = (uint **)(uint)param_7[1];
LAB_0043ac80:
    if (param_7[2] < 8) {
      return;
    }
    uVar24 = param_7[2] - 8;
    ppuVar18 = ppuVar20;
    if (ppuVar20 == (uint **)0x1194) {
      if (((uVar24 != 1) || (uVar9 = (uint)(param_8 < (ushort *)((int)param_7 + 9)), uVar9 != 0)) ||
         (*(char *)(param_7 + 4) != -1)) {
        bVar3 = false;
        if (((param_7 + 6 <= param_8) && (*(char *)(param_7 + 4) == '\0')) &&
           ((*(char *)((int)param_7 + 9) == '\0' && (*(char *)(param_7 + 5) == '\0')))) {
          bVar3 = *(char *)((int)param_7 + 0xb) == '\0';
        }
        sVar11 = 4;
        iVar6 = 0x120;
        if (!bVar3) {
          sVar11 = 0;
        }
        if (!bVar3) {
          iVar6 = 0xc0;
        }
        if ((((ushort)(uVar24 - sVar11) < 0x1c) ||
            (param_8 < (ushort *)((int)param_7 + iVar6 + 0x1c))) ||
           ((*(byte *)((int)param_7 + iVar6 + 0x11) & 0x10) == 0)) goto LAB_0043add8;
        cVar1 = *(char *)((int)param_7 + iVar6 + 0x12);
        uVar9 = 0;
        if (cVar1 != '\x05') {
          uVar9 = (uint)(cVar1 != '\"');
        }
        if (mDNS_LoggingEnabled != 0) {
          if (uVar9 == 0) {
            pcVar12 = "Ignoring";
          }
          else {
            pcVar12 = "Received";
          }
          local_30 = ppuVar20;
          local_2c = uVar9;
          LogMsgWithLevel(2,"%s %d-byte IKE ExchangeType %d",pcVar12,(int)param_8 - param_6,cVar1);
          ppuVar18 = local_30;
          uVar9 = local_2c;
        }
      }
    }
    else {
LAB_0043add8:
      uVar9 = 1;
    }
    if (((ppuVar18 == (uint **)0xcd3) && (uVar9 = 0, 0x6d < uVar24)) &&
       (uVar9 = 0, param_7 + 5 <= param_8)) {
      if (*(char *)(param_7 + 4) == '\x13') {
        uVar9 = (uint)(*(char *)((int)param_7 + 9) == -0x78);
      }
      else {
        uVar9 = 0;
      }
    }
    uVar23 = 0;
    if (mDNS_LoggingEnabled != 0) {
      if (uVar9 == 0) {
        pcVar12 = "Ignoring";
      }
      else {
        pcVar12 = "Received";
      }
      uVar23 = 0;
      local_2c = uVar9;
      LogMsgWithLevel(2,"%s %d-byte UDP from %#a:%d to %#a:%d",pcVar12,(int)param_8 - param_6,
                      param_3,*param_7,param_4,ppuVar20);
      uVar9 = local_2c;
    }
  }
LAB_0043b614:
  if (uVar9 == 0) {
    return;
  }
LAB_0043b61c:
  local_5c = (int *)(param_1 + 0x2f);
  mDNS_Lock_(param_1,"mDNSCoreReceiveRawTransportPacket");
  local_60 = (uint **)0x1194;
  local_58 = ppuVar20;
  for (ppuVar18 = *(uint ***)(param_1 + 0x2160); ppuVar18 != (uint **)0x0;
      ppuVar18 = (uint **)*ppuVar18) {
    if (((ppuVar18[7] == param_9) && (*(char *)(ppuVar18 + 1) != '\x01')) &&
       ((ppuVar18[0x18] != (uint *)0x0 &&
        (iVar6 = mDNSSameAddress(ppuVar18 + 0x18,param_4), iVar6 != 0)))) {
      puVar17 = &DAT_00452000;
      if (uVar25 != 6) {
        puVar17 = &DAT_0045c8c8;
      }
      for (ppuVar13 = *(uint ***)(param_1 + 0x2160); ppuVar13 != (uint **)0x0;
          ppuVar13 = (uint **)*ppuVar13) {
        if (((ppuVar13[7] == param_9) &&
            (*(short *)((int)ppuVar13 + 0x4e) == *(short *)((int)ppuVar18 + 0x4e))) &&
           ((ppuVar13[0x14] == ppuVar18[0x14] &&
            (((*(char *)(ppuVar13 + 1) != '\x01' && (*(short *)((int)ppuVar13 + 6) == 0x21)) &&
             ((uint **)(uint)*(ushort *)(ppuVar13[9] + 2) == ppuVar20)))))) {
          puVar7 = ppuVar13[8];
          uVar9 = (uint)*(byte *)puVar7;
          iVar6 = 0;
          if (uVar9 != 0) {
            iVar6 = uVar9 + 1;
          }
          iVar10 = 0;
          if (*(byte *)((int)puVar7 + iVar6) != 0) {
            iVar10 = uVar9 + 1;
            if (uVar9 == 0) {
              iVar10 = 0;
            }
            iVar10 = *(byte *)((int)puVar7 + iVar10) + 1;
          }
          local_30 = ppuVar13;
          iVar6 = SameDomainLabel((byte *)((int)puVar7 + iVar10 + iVar6),puVar17);
          ppuVar13 = local_30;
          if (iVar6 != 0) goto LAB_0043b79c;
        }
      }
      ppuVar13 = ppuVar18;
      if ((ppuVar20 == local_60) || (uVar23 != 0)) {
LAB_0043b79c:
        for (puVar22 = *(undefined4 **)(param_1 + 0x2174); puVar22 != (undefined4 *)0x0;
            puVar22 = (undefined4 *)*puVar22) {
          if ((uint *)puVar22[0x548] == ppuVar18[7]) {
            local_2c = (int)puVar22 + 0x1552;
            goto LAB_0043b7d0;
          }
        }
        local_2c = 0;
LAB_0043b7d0:
        uVar8 = GetRRDisplayString_rdb(ppuVar13 + 1,ppuVar13[9] + 1,local_5c);
        LogMsgWithLevel(0,"Waking host at %s %#a H-MAC %.6a I-MAC %.6a for %s",local_2c,param_4,
                        (int)ppuVar18 + 0x4e,ppuVar18 + 0x15,uVar8);
        FUN_0043a2d8(param_1,ppuVar18[7],(int)ppuVar18 + 0x4e);
      }
      else if (mDNS_LoggingEnabled != 0) {
        for (puVar22 = *(undefined4 **)(param_1 + 0x2174); puVar22 != (undefined4 *)0x0;
            puVar22 = (undefined4 *)*puVar22) {
          if ((uint *)puVar22[0x548] == ppuVar18[7]) {
            iVar6 = (int)puVar22 + 0x1552;
            goto LAB_0043b870;
          }
        }
        iVar6 = 0;
LAB_0043b870:
        LogMsgWithLevel(2,"Sleeping host at %s %#a %.6a has no service on %#s %d",iVar6,param_4,
                        (int)ppuVar18 + 0x4e,puVar17,local_58);
      }
    }
  }
  pcVar12 = "mDNSCoreReceiveRawTransportPacket";
LAB_0043b8b8:
  mDNS_Unlock_(param_1,pcVar12);
  return;
}

[ASK_GPT] 1e31594560013650
