
void RecordRegistrationGotZoneData(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  short sVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined uVar14;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStackX_8;
  uint uStackX_c;
  
  if (param_3 == 0) {
    param_1 = 0;
    UNRECOVERED_JUMPTABLE = LogMsgWithLevel;
    pcVar6 = "ERROR: RecordRegistrationGotZoneData invoked with NULL result and no error";
LAB_0041605c:
                    /* WARNING: Could not recover jumptable at 0x00416078. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,pcVar6);
    return;
  }
  puVar10 = *(undefined4 **)(param_3 + 0x328);
  iVar7 = puVar10[0x40];
  if (iVar7 != param_3) {
    uVar12 = puVar10[8];
    uVar2 = DNSTypeName(*(undefined2 *)((int)puVar10 + 6));
    LogMsgWithLevel(0,"RecordRegistrationGotZoneData: nta (%p) != zoneData (%p)  %##s (%s)",iVar7,
                    param_3,uVar12,uVar2);
  }
  if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28)) {
    LogMsgWithLevel(0,"RecordRegistrationGotZoneData: mDNS_busy (%ld) != mDNS_reentrancy (%ld)");
  }
  puVar13 = *(undefined4 **)(param_1 + 0x2160);
  do {
    if (puVar13 == (undefined4 *)0x0) {
      LogMsgWithLevel(0,"RecordRegistrationGotZoneData - RR no longer in list.  Discarding.");
LAB_00415ac0:
      uVar2 = puVar10[0x40];
LAB_00415d70:
      CancelGetZoneData(param_1,uVar2);
      puVar10[0x40] = 0;
      return;
    }
    if (puVar13 == puVar10) {
      if (param_2 == 0) {
        uVar8 = (uint)*(ushort *)(puVar13 + 2);
        uVar9 = (uint)*(ushort *)(param_3 + 0x208);
        if (uVar8 != uVar9) {
          pcVar6 = "ERROR: New resource record\'s class (%d) does not match zone class (%d)";
LAB_004159a4:
          LogMsgWithLevel(0,pcVar6,uVar8,uVar9);
LAB_00415a04:
          CancelGetZoneData(param_1,puVar13[0x40]);
          puVar13[0x40] = 0;
          return;
        }
        if (*(char *)(param_3 + 0x108) == '\0') {
          if (mDNS_LoggingEnabled == 0) goto LAB_00415ac0;
          param_2 = puVar10[8];
          pcVar6 = 
          "RecordRegistrationGotZoneData: No name server found claiming responsibility for \"%##s\"!"
          ;
        }
        else {
          uVar8 = param_3 + 0x108;
          iVar7 = CountLabels(puVar13[8]);
          iVar3 = CountLabels(uVar8);
          uVar9 = puVar13[8];
          if (iVar7 < iVar3) {
            pcVar6 = "RecordRegistrationGotZoneData: Zone \"%##s\" is longer than \"%##s\"";
            goto LAB_004159a4;
          }
          uVar2 = SkipLeadingLabels(uVar9,iVar7 - iVar3);
          puVar13[0x3f] = uVar2;
          iVar7 = SameDomainName(uVar2,uVar8);
          if (iVar7 == 0) {
            LogMsgWithLevel(0,
                            "RecordRegistrationGotZoneData: Zone \"%##s\" does not match \"%##s\" for \"%##s\""
                            ,puVar13[0x3f],uVar8,puVar13[8]);
            goto LAB_00415a04;
          }
          if (*(short *)(param_3 + 0x30a) != 0) {
            if (*(int *)(param_3 + 0x30c) == 4) {
              iVar7 = *(int *)(param_3 + 0x310);
LAB_00415a74:
              if (iVar7 == 0) goto LAB_00415a88;
            }
            else if ((((*(int *)(param_3 + 0x30c) == 6) && (*(int *)(param_3 + 0x314) == 0)) &&
                     (*(int *)(param_3 + 0x310) == 0)) && (*(int *)(param_3 + 0x318) == 0)) {
              iVar7 = *(int *)(param_3 + 0x31c);
              goto LAB_00415a74;
            }
            if (*(char *)(param_3 + 0x20a) != '\0') {
              *(undefined *)(puVar10 + 0x3c) = *(undefined *)(param_3 + 800);
              if (puVar10[0x39] == 3) {
                mDNS_Lock_(param_1,"RecordRegistrationGotZoneData");
                uDNS_DeregisterRecord(param_1,puVar10);
                UNRECOVERED_JUMPTABLE = mDNS_Unlock_;
                pcVar6 = "RecordRegistrationGotZoneData";
                goto LAB_0041605c;
              }
[32m              sVar5 = *(short *)((int)puVar10 + 6);[0m
              if (sVar5 != 0x21) {
LAB_00415c10:
                if ((((sVar5 == 0x21) && (*(short *)(puVar10[9] + 8) != 0)) &&
                    ((iVar7 = mDNSv4AddrIsRFC1918(param_1 + 0x21b0), iVar7 != 0 &&
                     (iVar7 = puVar10[0x40], iVar7 != 0)))) &&
                   (((*(int *)(iVar7 + 0x30c) != 4 ||
                     (iVar7 = mDNSv4AddrIsRFC1918(iVar7 + 0x310), iVar7 == 0)) &&
                    (*(char *)(puVar10 + 0x12) == '\x02')))) {
                  iVar7 = FUN_0040d9ac(param_1,puVar10[8]);
                  if ((iVar7 != 0) && (*(char *)(iVar7 + 8) != '\0')) {
[32m                    sVar5 = *(short *)((int)puVar10 + 6);[0m
                    if ((sVar5 == 2) || (((sVar5 == 5 || (sVar5 == 0xc)) || (sVar5 == 0x27)))) {
                      puVar11 = (undefined *)(puVar10[9] + 4);
                    }
                    else if ((((sVar5 == 0xf) || (sVar5 == 0x12)) || (sVar5 == 0x15)) ||
                            (sVar5 == 0x24)) {
                      puVar11 = (undefined *)(puVar10[9] + 6);
                    }
                    else {
                      puVar11 = (undefined *)0x0;
                      if (sVar5 == 0x21) {
                        puVar11 = (undefined *)(puVar10[9] + 10);
                      }
                    }
                    uVar2 = GetRRDisplayString_rdb(puVar10 + 1,puVar10[9] + 4,param_1 + 0x2f);
                    pcVar6 = 
                    "RecordRegistrationGotZoneData: ERROR!! AutoTunnel has Target_AutoHostAndNATMAP for %s"
                    ;
                    uVar12 = 0;
                    goto LAB_00415d40;
                  }
                  if (puVar10[0x53] == 0) {
                    if (mDNS_LoggingEnabled != 0) {
                      uVar2 = GetRRDisplayString_rdb(puVar10 + 1,puVar10[9] + 4,param_1 + 0x2f);
                      LogMsgWithLevel(3,"RecordRegistrationGotZoneData StartRecordNatMap %s",uVar2);
                    }
                    uStackX_c = (uint)*(ushort *)((int)puVar10 + 6);
                    puVar10[0x39] = 6;
                    if (uStackX_c != 0x21) {
                      if (mDNS_LoggingEnabled == 0) {
                        return;
                      }
                      uStackX_8 = puVar10[8];
                      pcVar6 = "StartRecordNatMap: Resource Record %##s type %d, not supported";
                      uVar2 = 3;
code_r0x00407ce4:
                      FUN_00407c70(uVar2,pcVar6,&uStackX_8);
                      return;
                    }
                    pbVar4 = (byte *)puVar10[8];
                    if (*pbVar4 != 0) {
                      pbVar4 = pbVar4 + *pbVar4 + 1;
                      if (*pbVar4 != 0) {
                        pbVar4 = pbVar4 + *pbVar4 + 1;
                      }
                    }
                    uVar14 = 2;
                    iVar7 = SameDomainLabel(pbVar4,&DAT_00452000);
                    if (iVar7 == 0) {
                      uVar14 = 1;
                      iVar7 = SameDomainLabel(pbVar4,&DAT_0045c8c8);
                      if (iVar7 == 0) {
                        uStackX_8 = puVar10[8];
                        pcVar6 = 
                        "StartRecordNatMap: could not determine transport protocol of service %##s";
                        uVar2 = 0;
                        goto code_r0x00407ce4;
                      }
                    }
                    if (puVar10[0x53] != 0) {
                      mDNS_StopNATOperation_internal(param_1,puVar10 + 0x42);
                    }
                    *(undefined *)(puVar10 + 0x4f) = uVar14;
                    *(undefined2 *)((int)puVar10 + 0x13e) = *(undefined2 *)(puVar10[9] + 8);
                    uVar1 = *(undefined2 *)(puVar10[9] + 8);
                    puVar10[0x52] = FUN_00412fa0;
                    *(undefined2 *)(puVar10 + 0x50) = uVar1;
                    puVar10[0x51] = 0;
                    puVar10[0x53] = puVar10;
                    mDNS_StartNATOperation_internal(param_1,puVar10 + 0x42);
                    return;
                  }
                  if (mDNS_LoggingEnabled != 0) {
                    uVar2 = GetRRDisplayString_rdb(puVar10 + 1,puVar10[9] + 4,param_1 + 0x2f);
                    LogMsgWithLevel(3,
                                    "RecordRegistrationGotZoneData: StartRecordNatMap for %s, state %d, context %p"
                                    ,uVar2,puVar10[0x39],puVar10[0x53]);
                  }
                }
                mDNS_Lock_(param_1,"RecordRegistrationGotZoneData");
                if (puVar10[0x57] == 0) {
                  puVar10[0x2f] = mDNSPlatformOneSecond;
                  puVar10[0x30] = *(int *)(param_1 + 0x234) - mDNSPlatformOneSecond;
                }
                iVar7 = FUN_0040da24(param_1,puVar10,
                                     mDNSPlatformOneSecond + *(int *)(param_1 + 0x234));
                if (iVar7 != 0) {
                  if (mDNS_LoggingEnabled != 0) {
                    uVar2 = GetRRDisplayString_rdb(puVar10 + 1,puVar10[9] + 4,param_1 + 0x2f);
                    LogMsgWithLevel(3,"RecordRegistrationGotZoneData: Delayed registration for %s",
                                    uVar2);
                  }
                  puVar10[0x30] = puVar10[0x30] + mDNSPlatformOneSecond;
                }
                UNRECOVERED_JUMPTABLE = mDNS_Unlock_;
                pcVar6 = "RecordRegistrationGotZoneData";
                goto LAB_0041605c;
              }
              mDNS_Lock_(param_1,"RecordRegistrationGotZoneData");
              pcVar6 = (char *)GetServiceTarget(param_1,puVar10);
              mDNS_Unlock_(param_1,"RecordRegistrationGotZoneData");
              if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
[32m                sVar5 = *(short *)((int)puVar10 + 6);[0m
                goto LAB_00415c10;
              }
[32m              sVar5 = *(short *)((int)puVar10 + 6);[0m
              if (((sVar5 == 2) || (sVar5 == 5)) || ((sVar5 == 0xc || (sVar5 == 0x27)))) {
                puVar11 = (undefined *)(puVar10[9] + 4);
              }
              else if (((sVar5 == 0xf) || (sVar5 == 0x12)) || ((sVar5 == 0x15 || (sVar5 == 0x24))))
              {
                puVar11 = (undefined *)(puVar10[9] + 6);
              }
              else {
                puVar11 = (undefined *)0x0;
                if (sVar5 == 0x21) {
                  puVar11 = (undefined *)(puVar10[9] + 10);
                }
              }
              if (mDNS_LoggingEnabled != 0) {
                uVar12 = 3;
                uVar2 = puVar10[8];
                pcVar6 = "RecordRegistrationGotZoneData - no target for %##s";
LAB_00415d40:
                LogMsgWithLevel(uVar12,pcVar6,uVar2);
              }
              if (puVar11 != (undefined *)0x0) {
                *puVar11 = 0;
              }
              uVar2 = puVar10[0x40];
              puVar10[0x39] = 8;
              *(undefined2 *)((int)puVar10 + 0x12) = 0;
              *(undefined2 *)(puVar10 + 4) = 0;
              goto LAB_00415d70;
            }
          }
LAB_00415a88:
          if (mDNS_LoggingEnabled == 0) goto LAB_00415ac0;
          pcVar6 = "RecordRegistrationGotZoneData: No _dns-update._udp service found for \"%##s\"!";
          param_2 = puVar10[8];
        }
        uVar2 = 3;
      }
      else {
        if (param_2 == -0x10002) goto LAB_00415ac0;
        uVar2 = 0;
        pcVar6 = "RecordRegistrationGotZoneData: error %d";
      }
      LogMsgWithLevel(uVar2,pcVar6,param_2);
      goto LAB_00415ac0;
    }
    puVar13 = (undefined4 *)*puVar13;
  } while( true );
}

[ASK_GPT] dfd51b419226628e
