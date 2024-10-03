
/* WARNING: Removing unreachable block (ram,0x00433778) */
/* WARNING: Removing unreachable block (ram,0x00433738) */
/* WARNING: Removing unreachable block (ram,0x00433560) */

undefined4 mDNS_StartQuery_internal(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined uVar10;
  bool bVar11;
  bool bVar12;
  int iVar13;
  undefined4 *puVar14;
  char local_38;
  char local_37 [7];
  undefined2 local_30 [2];
  undefined4 *local_2c;
  
  if (*(int *)(param_1 + 0x2c8) == 0) {
    uVar3 = 0xfffefff6;
  }
  else {
    iVar13 = param_2[0x4f];
    if ((iVar13 != 0) &&
       (((iVar13 != 4 && (iVar13 != 6)) ||
        ((*(short *)(param_2 + 0x54) != 0x35 && (*(short *)(param_2 + 0x54) != 0x14e9)))))) {
      LogMsgWithLevel(0,
                      "ValidateParameters: Warning! Target.type = %ld port = %u (Client forgot to initialize before calling mDNS_StartQuery? for question %##s)"
                      ,iVar13,*(undefined2 *)(param_2 + 0x54),param_2 + 0x55);
      param_2[0x4f] = 0;
    }
    if (param_2[0x4f] == 0) {
      *(undefined2 *)(param_2 + 0x54) = 0;
    }
    puVar14 = param_2 + 0x55;
    uVar4 = DomainNameLengthLimit(puVar14,param_2 + 0x95);
    if (uVar4 < 0x101) {
      iVar13 = param_2[0x4d];
      if ((((iVar13 != 0) && (iVar13 != -2)) && (iVar13 != -3)) && (iVar13 != -4)) {
        for (puVar5 = *(undefined4 **)(param_1 + 0x2174); puVar5 != (undefined4 *)0x0;
            puVar5 = (undefined4 *)*puVar5) {
          if (puVar5[0x548] == iVar13) goto LAB_004336fc;
        }
        if (mDNS_LoggingEnabled != 0) {
          local_2c = (undefined4 *)iVar13;
          uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
          LogMsgWithLevel(3,
                          "ValidateParameters: Note: InterfaceID %d for question %##s (%s) not currently found in active interface list"
                          ,local_2c,puVar14,uVar3);
        }
      }
LAB_004336fc:
      if (((param_2[0x4f] == 0) && (iVar13 = param_2[0x4d], iVar13 != -3)) &&
         ((*(char *)((int)param_2 + 0x267) == '\0' &&
          (((iVar13 == -2 || (iVar13 == -4)) ||
           ((*(char *)((int)param_2 + 0x25a) != '\0' ||
            (iVar13 = IsLocalDomain(puVar14), iVar13 != 0)))))))) {
        local_30[0] = 0;
      }
      else {
        mDNS_NewMessageID(local_30,param_1);
      }
      *(undefined2 *)((int)param_2 + 0x152) = local_30[0];
      puVar5 = (undefined4 *)(param_1 + 0x2b8);
      if ((param_2[0x4d] != -2) && (puVar5 = (undefined4 *)(param_1 + 0x2ac), param_2[0x4d] == -4))
      {
        puVar5 = (undefined4 *)(param_1 + 0x2b8);
      }
      while (puVar6 = (undefined4 *)*puVar5, puVar6 != (undefined4 *)0x0) {
        puVar5 = puVar6;
        if (puVar6 == param_2) {
          uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
          LogMsgWithLevel(0,
                          "mDNS_StartQuery_internal: Error! Tried to add a question %##s (%s) %p that\'s already in the active list"
                          ,puVar14,uVar3,param_2);
          return 0xfffefff5;
        }
      }
      *puVar5 = param_2;
      *param_2 = 0;
      local_37[0] = '\0';
      param_2[4] = (mDNSPlatformOneSecond + 2) / 3;
      local_2c = (undefined4 *)DomainNameHashValue(puVar14);
      param_2[1] = local_2c;
      uVar4 = DomainNameHashValue(puVar14);
      uVar3 = FUN_004279b4(param_1,puVar14,local_2c,uVar4 % 499,&local_38);
      param_2[2] = uVar3;
      param_2[3] = *(undefined4 *)(param_1 + 0x234);
      param_2[5] = 0;
      uVar3 = *(undefined4 *)(param_1 + 0x26c);
      param_2[7] = 0;
      param_2[6] = uVar3;
      param_2[8] = 0;
      param_2[9] = 0;
      *(undefined *)((int)param_2 + 0xad) = 0;
      param_2[10] = 0;
      param_2[0xb] = 0;
      *(undefined *)((int)param_2 + 0xbd) = 0;
      param_2[0xc] = 0;
      param_2[0xd] = 0;
      if ((param_2[0x4e] & 0x10000000) == 0) {
        mDNSPlatformGetDNSRoutePolicy(param_1,param_2,local_37);
      }
      else if (mDNS_LoggingEnabled != 0) {
        uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
        LogMsgWithLevel(3,
                        "InitCommonState: Query for %##s (%s), PID[%d], EUID[%d], ServiceID[%d] is already set by client"
                        ,puVar14,uVar3,param_2[0x9b],param_2[0xa0],param_2[0x4c]);
      }
      param_2[0x37] = 0;
      param_2[0x39] = 0;
      param_2[0x38] = 0;
      *(undefined2 *)((int)param_2 + 0xea) = 0;
      *(undefined2 *)(param_2 + 0x3a) = 0;
      param_2[0x30] = 0;
      if ((param_2[0x4d] != -2) && (param_2[0x4d] != -4)) {
        if (*(short *)((int)param_2 + 0x152) == 0) {
          if (*(char *)(param_2 + 0x98) != '\0') {
            uVar3 = 0xffffffff;
            iVar13 = *(int *)(param_1 + 0x234);
            puVar5 = (undefined4 *)0x0;
            uVar8 = CountLabels(puVar14);
            for (puVar6 = *(undefined4 **)(param_1 + 0x2194); puVar6 != (undefined4 *)0x0;
                puVar6 = (undefined4 *)*puVar6) {
              local_2c = puVar6 + 3;
              uVar9 = CountLabels(puVar6 + 3);
              iVar7 = FUN_00428184(puVar14,uVar8,local_2c,uVar9,uVar3);
              if (iVar7 == 1) {
                uVar3 = uVar9;
                puVar5 = puVar6;
              }
            }
            if (mDNS_LoggingEnabled != 0) {
              uVar3 = 5;
              if (puVar5 != (undefined4 *)0x0) {
                uVar3 = puVar5[0x43];
              }
              LogMsgWithLevel(3,"GetTimeoutForMcastQuestion: question %##s curmatch %p, Timeout %d",
                              puVar14,puVar5,uVar3);
            }
            iVar7 = 5;
            if (puVar5 != (undefined4 *)0x0) {
              iVar7 = puVar5[0x43];
            }
            iVar13 = iVar7 * mDNSPlatformOneSecond + iVar13;
            if (iVar13 == 0) {
              iVar13 = 1;
            }
            param_2[0x30] = iVar13;
          }
        }
        else {
          iVar13 = SetValidDNSServers(param_1,param_2);
          if (*(char *)(param_2 + 0x98) != '\0') {
            iVar7 = iVar13 * mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
            if (iVar7 == 0) {
              iVar7 = 1;
            }
            param_2[0x30] = iVar7;
            if (mDNS_LoggingEnabled != 0) {
              uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
              LogMsgWithLevel(3,"InitDNSConfig: Setting StopTime on question %p %##s (%s)",param_2,
                              puVar14,uVar3);
            }
          }
          uVar3 = GetServerForQuestion(param_1,param_2);
          param_2[0x37] = uVar3;
          if (mDNS_LoggingEnabled != 0) {
            uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
            iVar7 = param_2[0x37];
            if (iVar7 == 0) {
              iVar7 = 0;
              uVar1 = 0;
            }
            else {
              uVar1 = *(undefined2 *)(iVar7 + 0x20);
              iVar7 = iVar7 + 0xc;
            }
            LogMsgWithLevel(3,"InitDNSConfig: question %p %##s (%s) Timeout %d, DNS Server %#a:%d",
                            param_2,puVar14,uVar3,iVar13,iVar7,uVar1);
          }
        }
        if (param_2[0x30] != 0) {
          if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28) + 1) {
            LogMsgWithLevel(0,"%s: Lock not held! mDNS_busy (%ld) mDNS_reentrancy (%ld)",
                            "SetNextQueryStopTime",*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x28)
                           );
          }
          if (0 < *(int *)(param_1 + 0x2a8) - param_2[0x30]) {
            *(undefined4 *)(param_1 + 0x2a8) = param_2[0x30];
          }
        }
        SetNextQueryTime(param_1,param_2);
      }
      uVar3 = GetAuthInfoForQuestion(param_1,param_2);
      param_2[0xe] = uVar3;
      *(undefined *)(param_2 + 0x2f) = 0;
      if (*(char *)(param_2 + 0x97) != '\0') {
        uVar10 = FUN_004326d4(param_1,param_2);
        *(undefined *)(param_2 + 0x2f) = uVar10;
      }
      bVar12 = true;
      if ((param_2[0x4c] != 0) && (bVar12 = false, local_37[0] != '\0')) {
        if (param_2[0x37] == 0) {
          bVar12 = false;
        }
        else {
          bVar12 = *(char *)(param_2[0x37] + 0x13c) != '\0';
        }
      }
      *(bool *)((int)param_2 + 0x12e) = bVar12;
      if ((bVar12) && (mDNS_LoggingEnabled != 0)) {
        uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
        LogMsgWithLevel(3,
                        "InitCommonState: Query suppressed for %##s (%s), PID %d/ServiceID %d not allowed"
                        ,puVar14,uVar3,param_2[0x9b],param_2[0x4c]);
      }
      param_2[0x2c] = 2;
      param_2[0x10] = 0;
      param_2[0x2a] = 0;
      *(undefined *)(param_2 + 0x2b) = 0;
      param_2[0x2d] = *(undefined4 *)(param_1 + 0x234);
      param_2[0x2e] = 0;
      *(undefined *)((int)param_2 + 0xbe) = 0;
      if (*(char *)((int)param_2 + 0x261) != '\0') {
        *(undefined *)((int)param_2 + 0xbe) = 3;
        local_38 = '\x01';
      }
      iVar13 = 0;
      do {
        iVar7 = iVar13 + 0xc;
        *(undefined4 *)((int)param_2 + iVar13 + 0x4c) = 0;
        iVar13 = iVar7;
      } while (iVar7 != 0x60);
      *(undefined *)((int)param_2 + 0x113) = 0;
      if ((param_2[2] != 0) && (mDNS_LoggingEnabled != 0)) {
        local_2c = (undefined4 *)(param_2[2] - *(int *)(param_1 + 0x234));
        uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
        LogMsgWithLevel(3,
                        "InitCommonState: Delaying answering for %d ticks while cache stabilizes for %##s (%s)"
                        ,local_2c,puVar14,uVar3);
      }
      cVar2 = local_38;
      param_2[0x36] = 0;
      *(undefined *)(param_2 + 0x3b) = 0;
      param_2[0x3c] = 0;
[32m[32m      memcpy(param_2 + 0x3d,zeroAddr,0x14);[0m[0m
      param_2[0x43] = 0;
      *(undefined2 *)(param_2 + 0x42) = 0;
      param_2[0x45] = 1;
      param_2[0x49] = 0;
      param_2[0x4a] = 0;
      *(undefined *)((int)param_2 + 0x112) = 0;
      param_2[0x46] = 0;
      param_2[0x47] = 0;
      *(undefined2 *)(param_2 + 0x48) = 0;
      if (param_2[0x37] != 0) {
        if (*(char *)(param_2[0x37] + 0x13c) != '\0') {
          *(undefined *)((int)param_2 + 0x266) = 0;
        }
        if ((*(char *)((int)param_2 + 0x266) == '\x02') &&
           (*(char *)(param_2[0x37] + 0x142) == '\0')) {
          if (mDNS_LoggingEnabled != 0) {
            uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
            LogMsgWithLevel(3,
                            "InitDNSSECProxyState: Turning off validation for %##s (%s); req_DO false"
                            ,puVar14,uVar3);
          }
          *(undefined *)((int)param_2 + 0x266) = 0;
        }
      }
      param_2[0x32] = 0;
      param_2[0x31] = (uint)(*(char *)((int)param_2 + 0x266) != '\0');
      *(undefined2 *)(param_2 + 0x4b) = 0;
      puVar5 = *(undefined4 **)(param_1 + 0x2ac);
      do {
        if (puVar5 == (undefined4 *)0x0) {
LAB_004333cc:
          param_2[0xf] = puVar5;
          if (puVar5 != (undefined4 *)0x0) {
            param_2[0xe] = puVar5[0xe];
          }
          if ((param_2[0x4d] == -2) || (param_2[0x4d] == -4)) {
            if (*(int *)(param_1 + 700) == 0) {
              *(undefined4 **)(param_1 + 700) = param_2;
              return 0;
            }
          }
          else {
            if (*(int *)(param_1 + 0x2b0) == 0) {
              *(undefined4 **)(param_1 + 0x2b0) = param_2;
            }
            if (*(short *)((int)param_2 + 0x152) == 0) {
              if (cVar2 == '\0') {
                return 0;
              }
              if (mDNS_LoggingEnabled != 0) {
                LogMsgWithLevel(3,"mDNS_StartQuery_internal: Purging for %##s",puVar14);
              }
              FUN_00428fe8(param_1,param_2);
            }
            else {
              puVar5 = (undefined4 *)param_2[0xf];
              if (puVar5 != (undefined4 *)0x0) {
                param_2[0x38] = puVar5[0x38];
                param_2[0x39] = puVar5[0x39];
                param_2[0x37] = puVar5[0x37];
                if (mDNS_LoggingEnabled != 0) {
                  local_2c = puVar5;
                  uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
                  iVar13 = param_2[0x37];
                  if (iVar13 == 0) {
                    iVar13 = 0;
                    uVar1 = 0;
                  }
                  else {
                    uVar1 = *(undefined2 *)(iVar13 + 0x20);
                    iVar13 = iVar13 + 0xc;
                  }
                  LogMsgWithLevel(3,
                                  "FinalizeUnicastQuestion: Duplicate question %p (%p) %##s (%s), DNS Server %#a:%d"
                                  ,param_2,local_2c,puVar14,uVar3,iVar13,uVar1);
                }
              }
              FUN_0042c3ac(param_1,param_2,0);
              if (cVar2 == '\0') {
                if ((param_2[0xf] == 0) &&
                   (((*(char *)((int)param_2 + 0x266) != '\0' || (*(char *)(param_2 + 0x33) != '\0')
                     ) || ((*(char *)((int)param_2 + 0x267) != '\0' &&
                           (*(char *)(param_2 + 0x9a) != '\0')))))) {
                  puVar5 = (undefined4 *)0x0;
                  uVar4 = DomainNameHashValue(puVar14);
                  iVar13 = CacheGroupForName(param_1,uVar4 % 499,param_2[1],puVar14);
                  if (iVar13 != 0) {
                    puVar5 = *(undefined4 **)(iVar13 + 8);
                  }
                  for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
                    iVar13 = SameNameRecordAnswersQuestion(puVar5 + 1,param_2);
                    if ((iVar13 != 0) &&
                       (((*(char *)(puVar5 + 1) != -0x10 || (puVar5[0x15] == 0)) &&
                        (*(char *)((int)puVar5 + 0x4d) == '\0')))) {
                      if (mDNS_LoggingEnabled != 0) {
                        uVar3 = GetRRDisplayString_rdb(puVar5 + 1,puVar5[9] + 4,param_1 + 0x2f);
                        LogMsgWithLevel(3,"CheckForDNSSECRecords: Flushing %s",uVar3);
                      }
                      mDNS_PurgeCacheResourceRecord(param_1,puVar5);
                    }
                  }
                }
              }
              else {
                param_2[2] = 0;
                FUN_00428fe8(param_1,param_2);
              }
              if (*(char *)(param_2 + 0x96) == '\0') {
                return 0;
              }
              if (*(int *)(param_1 + 0x29b0) != 0) {
                return 0;
              }
              *(undefined *)(param_1 + 0x29a4) = 1;
              *(code **)(param_1 + 0x29b0) = FUN_0042dc1c;
              *(undefined2 *)(param_1 + 0x29a8) = *(undefined2 *)(param_1 + 0x10);
              *(undefined4 *)(param_1 + 0x29b4) = 1;
              *(undefined2 *)(param_1 + 0x29a6) = *(undefined2 *)(param_1 + 0x10);
              mDNS_StartNATOperation_internal(param_1,param_1 + 0x2970);
            }
          }
          return 0;
        }
        if (puVar5 == param_2) {
          puVar5 = (undefined4 *)0x0;
          goto LAB_004333cc;
        }
        if ((puVar5[0x4d] == param_2[0x4d]) &&
           ((((puVar5[0x4f] == 0 && (param_2[0x4f] == 0)) ||
             ((iVar13 = mDNSSameAddress(puVar5 + 0x4f,param_2 + 0x4f), iVar13 != 0 &&
              (*(short *)(puVar5 + 0x54) == *(short *)(param_2 + 0x54))))) &&
            (puVar5[0x95] == param_2[0x95])))) {
          bVar12 = false;
          if (*(char *)(puVar5 + 0x96) != '\0') {
            bVar12 = *(short *)((int)puVar5 + 0x152) != 0;
          }
          bVar11 = false;
          if (*(char *)(param_2 + 0x96) != '\0') {
            bVar11 = *(short *)((int)param_2 + 0x152) != 0;
          }
          if ((((((bool)(bVar12 ^ 1U) != bVar11) &&
                (((puVar5[0xe] == 0 || (param_2[0xe] != 0)) && (puVar5[0x11] == param_2[0x11])))) &&
               ((*(char *)(puVar5 + 0x2f) == *(char *)(param_2 + 0x2f) &&
                (*(char *)((int)puVar5 + 0x266) == *(char *)((int)param_2 + 0x266))))) &&
              (*(char *)(puVar5 + 0x33) == *(char *)(param_2 + 0x33))) &&
             (((*(char *)((int)puVar5 + 0x12e) == *(char *)((int)param_2 + 0x12e) &&
               (puVar5[9] == param_2[9])) &&
              ((puVar5[1] == param_2[1] &&
               (((((uint)puVar5[0x4e] >> 0x14 ^ 1 ^ (uint)param_2[0x4e] >> 0x14) & 1) != 0 &&
                (iVar13 = SameDomainName(puVar5 + 0x55,puVar14), iVar13 != 0))))))))
          goto LAB_004333cc;
        }
        puVar5 = (undefined4 *)*puVar5;
      } while( true );
    }
    uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x95));
    LogMsgWithLevel(0,"ValidateParameters: Attempt to start query with invalid qname %##s (%s)",
                    puVar14,uVar3);
    uVar3 = 0xfffefff3;
  }
  return uVar3;
}

[ASK_GPT] cea3e3c601e19f7c
