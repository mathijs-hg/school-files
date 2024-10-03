
/* WARNING: Removing unreachable block (ram,0x00414208) */

void FUN_00413aec(uint *param_1,int *param_2,char param_3,int param_4)

{
  ushort uVar1;
  bool bVar2;
  ushort *puVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int **ppiVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  ushort uVar15;
  uint uVar16;
  int *in_stack_ffffff88;
  uint in_stack_ffffff90;
  char local_58 [4];
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined auStack_40 [24];
  
  local_58[0] = '\0';
  iVar9 = param_2[0x8c1];
  iVar10 = *param_2;
  ppiVar11 = (int **)(iVar9 + 0x10c);
  if ((iVar9 == 0) && (ppiVar11 = (int **)(param_2[0x8c2] + 0x104), param_2[0x8c2] == 0)) {
    ppiVar11 = (int **)0x0;
  }
  else if (*ppiVar11 != param_2) {
    uVar6 = mDNSPlatformTCPGetFD(param_2[1]);
    in_stack_ffffff90 = param_2[0x8c2];
    in_stack_ffffff88 = param_2;
    LogMsgWithLevel(0,"tcpCallback: %d backpointer %p incorrect tcpInfo %p question %p rr %p",uVar6,
                    *ppiVar11,param_2,iVar9,in_stack_ffffff90);
  }
  if (param_4 == 0) {
    if (param_3 == '\0') {
      uVar4 = param_2[0x8cb];
      bVar2 = uVar4 < 2;
      if (bVar2) {
        iVar8 = mDNSPlatformReadTCP(param_1,(int)param_2 + uVar4 + 9000,2 - uVar4,local_58);
        if (-1 < iVar8) {
          if (local_58[0] != '\0') goto LAB_0041405c;
          iVar12 = param_2[0x8cb];
          param_2[0x8cb] = iVar8 + iVar12;
          if ((uint)(iVar8 + iVar12) < 2) {
            return;
          }
          uVar4 = (uint)*(ushort *)(param_2 + 0x8ca);
          *(ushort *)(param_2 + 0x8ca) = *(ushort *)(param_2 + 0x8ca);
          if (0xb < uVar4) {
            pvVar5 = mDNSPlatformMemAllocate(uVar4);
            param_2[0x8c9] = (int)pvVar5;
            if (pvVar5 == (void *)0x0) {
              LogMsgWithLevel(0,"ERROR: tcpCallback - malloc failed");
              param_4 = -0x10003;
              goto LAB_0041419c;
            }
            uVar4 = param_2[0x8cb];
            goto LAB_00414008;
          }
          LogMsgWithLevel(0,"ERROR: tcpCallback - length too short (%d bytes)",uVar4);
          goto LAB_00414198;
        }
        pcVar7 = "ERROR: tcpCallback - attempt to read message length failed (%d)";
      }
      else {
LAB_00414008:
        iVar8 = mDNSPlatformReadTCP(param_1,param_2[0x8c9] + (uVar4 - 2),
                                    (*(ushort *)(param_2 + 0x8ca) - uVar4) + 2,local_58);
        if (iVar8 < 0) {
          if (bVar2) {
            return;
          }
          pcVar7 = "ERROR: tcpCallback - read returned %d";
        }
        else {
          if (local_58[0] == '\0') {
            uVar4 = (iVar8 + param_2[0x8cb]) - 2;
            param_2[0x8cb] = iVar8 + param_2[0x8cb];
            if (uVar4 != *(ushort *)(param_2 + 0x8ca)) {
              return;
            }
            pvVar5 = (void *)param_2[0x8c9];
[32m[32m            memcpy(auStack_40,param_2 + 0x8c3,0x14);[0m[0m
            param_2[0x8cc] = param_2[0x8cc] + 1;
            param_2[0x8c9] = 0;
            param_2[0x8cb] = 0;
            *(undefined2 *)(param_2 + 0x8ca) = 0;
            uVar16 = *param_1;
            uVar15 = 0;
            uVar1 = *(ushort *)(param_2 + 0x8c8);
            if ((iVar9 != 0) && (*(int *)(iVar9 + 0x10c) != 0)) {
              uVar15 = *(ushort *)(*(int *)(iVar9 + 0x10c) + 0x2322);
              *(ushort *)(iVar9 + 0x110) = uVar15;
            }
            if ((ppiVar11 != (int **)0x0) &&
               (((iVar9 == 0 || (*(char *)(iVar9 + 600) == '\0')) ||
                (*(char *)(iVar10 + 0x275) != '\0')))) {
              *ppiVar11 = (int *)0x0;
              DisposeTCPConn(param_2);
            }
            mDNSCoreReceive(iVar10,pvVar5,(int)pvVar5 + uVar4,auStack_40,
                            (uint)in_stack_ffffff88 & 0xffff | (uint)uVar1 << 0x10,uVar16 & 1,
                            in_stack_ffffff90 & 0xffff | (uint)uVar15 << 0x10,0);
            mDNSPlatformMemFree(pvVar5);
            return;
          }
LAB_0041405c:
          if (param_2[0x8cc] != 0) {
            if (ppiVar11 != (int **)0x0) {
              *ppiVar11 = (int *)0x0;
            }
            goto LAB_00414444;
          }
          pcVar7 = "ERROR: socket closed prematurely tcpInfo->nread = %d";
          iVar8 = param_2[0x8cb];
        }
      }
      LogMsgWithLevel(0,pcVar7,iVar8);
      param_4 = -0x100fc;
    }
    else {
      iVar8 = param_2[0x8c2];
      iVar12 = param_2[0x8c0];
      if ((iVar8 != 0) && (*(int *)(iVar8 + 0x20) != iVar8 + 0x178)) {
        LogMsgWithLevel(0,
                        "tcpCallback: ERROR: tcpInfo->rr->resrec.name %p != &tcpInfo->rr->namestorage %p"
                       );
      }
      iVar8 = param_2[0x8c2];
      uVar6 = 0;
      if (iVar8 != 0) {
        if (*(int *)(iVar8 + 0x20) != iVar8 + 0x178) {
          return;
        }
        uVar6 = FUN_0040d9ac(iVar10);
      }
      if (iVar9 == 0) {
        iVar8 = (int)param_2 + iVar12 + 8;
      }
      else {
        if (*(char *)(iVar9 + 600) == '\0') {
LAB_00413d3c:
          if (((*(char *)(iVar9 + 0x266) == '\0') && (*(char *)(iVar9 + 0xcc) == '\0')) &&
             ((*(char *)(iVar9 + 0x267) == '\0' || (*(char *)(iVar9 + 0x268) == '\0')))) {
            puVar3 = &uQueryFlags;
          }
          else {
            puVar3 = &DNSSecQFlags;
          }
          piVar14 = param_2 + 2;
          piVar13 = param_2 + 0x8c0;
          InitializeDNSMessage
                    (param_2 + 2,(uint)*(ushort *)(iVar9 + 0x152) << 0x10,(uint)*puVar3 << 0x10);
          iVar8 = putQuestion(piVar14,param_2 + 5,piVar13,iVar9 + 0x154,
                              *(undefined2 *)(iVar9 + 0x254),*(undefined2 *)(iVar9 + 0x256));
          if ((((*(char *)(iVar9 + 0x266) != '\0') || (*(char *)(iVar9 + 0xcc) != '\0')) ||
              ((*(char *)(iVar9 + 0x267) != '\0' && (*(char *)(iVar9 + 0x268) != '\0')))) &&
             ((*(int *)(iVar9 + 0xdc) != 0 && (*(char *)(*(int *)(iVar9 + 0xdc) + 0x13c) == '\0'))))
          {
            if (*(char *)(iVar9 + 0x267) == '\0') {
              iVar8 = putDNSSECOption(piVar14,iVar8,piVar13);
            }
            else {
              iVar8 = DNSProxySetAttributes(iVar9,param_2 + 2,piVar14,iVar8,piVar13);
            }
          }
        }
        else {
          if (*(int *)(iVar9 + 0x114) == 3) {
            iVar8 = (int)param_2 + param_2[0x8c0] + 8;
            goto LAB_00413e60;
          }
          if (((*(int *)(iVar9 + 0x114) == 4) || (*(short *)(iVar10 + 0x2998) == 0)) ||
             (*(short *)(iVar9 + 0x108) == 0)) goto LAB_00413d3c;
          local_52 = 1;
          local_54 = 1;
          uVar6 = FUN_0040e7b0(iVar10,param_2 + 0x8c3);
          local_50 = (undefined2)uVar6;
          if (mDNS_LoggingEnabled != 0) {
            LogMsgWithLevel(3,"tcpCallback: eventPort %d",uVar6);
          }
          local_48 = 0;
          local_4c = 0;
          local_44 = 0x1c20;
          InitializeDNSMessage(param_2 + 2,(uint)*(ushort *)(iVar9 + 0x152) << 0x10,0x1000000);
          iVar8 = FUN_0040e3f4(param_2 + 2,param_2 + 5,iVar9,&local_54);
          if (iVar8 == 0) {
            LogMsgWithLevel(0,"ERROR: tcpCallback - putLLQ");
            goto LAB_00414198;
          }
          *(undefined2 *)(iVar9 + 0x120) = 0;
        }
        uVar6 = *(undefined4 *)(iVar9 + 0x38);
      }
LAB_00413e60:
      iVar8 = mDNSSendDNSMessage(iVar10,param_2 + 2,iVar8,0,0,param_2 + 0x8c3,
                                 in_stack_ffffff90 & 0xffff |
                                 (uint)*(ushort *)(param_2 + 0x8c8) << 0x10,param_1,uVar6,0);
      if (iVar8 == 0) {
        if (iVar9 == 0) {
          return;
        }
        mDNS_Lock_(iVar10,"tcpCallback");
        *(undefined4 *)(iVar9 + 0xc) = *(undefined4 *)(iVar10 + 0x234);
        if (*(int *)(iVar9 + 0x10) < mDNSPlatformOneSecond << 8) {
          *(int *)(iVar9 + 0x10) = mDNSPlatformOneSecond << 8;
        }
        SetNextQueryTime(iVar10,iVar9);
        mDNS_Unlock_(iVar10,"tcpCallback");
        return;
      }
LAB_00414198:
      param_4 = -0x10001;
    }
  }
LAB_0041419c:
  if (ppiVar11 != (int **)0x0) {
    *ppiVar11 = (int *)0x0;
  }
  mDNS_Lock_(iVar10,"tcpCallback");
  if (iVar9 != 0) {
    iVar8 = *(int *)(iVar10 + 0x234);
    if (*(int *)(iVar9 + 0x10) == 0) {
      *(int *)(iVar9 + 0xc) = iVar8;
      if (*(char *)(iVar9 + 600) == '\0') {
        *(int *)(iVar9 + 0x10) = mDNSPlatformOneSecond * 0xe10;
        uVar6 = DNSTypeName(*(undefined2 *)(iVar9 + 0x254));
        pcVar7 = "tcpCallback: stream connection for %##s (%s) failed, retrying in %d ms";
        iVar8 = *(int *)(iVar9 + 0x10);
      }
      else {
        iVar8 = *(short *)(iVar9 + 0x120) + 1;
        *(int *)(iVar9 + 0x10) = (mDNSPlatformOneSecond + 2) / 3;
        while( true ) {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          *(int *)(iVar9 + 0x10) = *(int *)(iVar9 + 0x10) * 3;
        }
        if (mDNSPlatformOneSecond * 900 < *(int *)(iVar9 + 0x10)) {
          *(int *)(iVar9 + 0x10) = mDNSPlatformOneSecond * 900;
        }
        else {
          *(short *)(iVar9 + 0x120) = *(short *)(iVar9 + 0x120) + 1;
        }
        uVar6 = DNSTypeName(*(undefined2 *)(iVar9 + 0x254));
        iVar8 = (int)*(short *)(iVar9 + 0x120);
        pcVar7 = 
        "tcpCallback: stream connection for LLQ %##s (%s) failed %d times, retrying in %d ms";
      }
      LogMsgWithLevel(0,pcVar7,iVar9 + 0x154,uVar6,iVar8);
      SetNextQueryTime(iVar10,iVar9);
    }
    else {
      if (*(char *)(iVar9 + 600) == '\0') {
        iVar12 = 0xe10;
      }
      else {
        iVar12 = 900;
      }
      if (mDNSPlatformOneSecond * iVar12 < (*(int *)(iVar9 + 0xc) + *(int *)(iVar9 + 0x10)) - iVar8)
      {
        *(int *)(iVar9 + 0xc) = iVar8;
        if (*(char *)(iVar9 + 600) == '\0') {
          iVar8 = 0xe10;
        }
        else {
          iVar8 = 900;
        }
        *(int *)(iVar9 + 0x10) = mDNSPlatformOneSecond * iVar8;
        SetNextQueryTime(iVar10,iVar9);
        uVar6 = DNSTypeName(*(undefined2 *)(iVar9 + 0x254));
        LogMsgWithLevel(0,"tcpCallback: stream connection for %##s (%s) failed, retrying in %d ms",
                        iVar9 + 0x154,uVar6,*(undefined4 *)(iVar9 + 0x10));
      }
    }
    if ((*(char *)(iVar9 + 600) != '\0') && (*(int *)(iVar9 + 0x114) == 2)) {
      *(undefined4 *)(iVar9 + 0x114) = 1;
    }
    if (((param_4 != -0x100fc) && (*(char *)(iVar9 + 600) != '\0')) &&
       (*(int *)(iVar9 + 0x114) != 4)) {
      FUN_0040e534(iVar10,iVar9);
    }
  }
  mDNS_Unlock_(iVar10,"tcpCallback");
LAB_00414444:
  DisposeTCPConn(param_2);
  return;
}

[ASK_GPT] 7233b118f00fa7f1
