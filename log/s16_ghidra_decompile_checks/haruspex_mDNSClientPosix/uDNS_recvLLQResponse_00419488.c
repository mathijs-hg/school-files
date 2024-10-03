
/* WARNING: Removing unreachable block (ram,0x00419664) */

undefined4
uDNS_recvLLQResponse
          (int param_1,ushort *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 *param_6)

{
  undefined uVar1;
  undefined uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined auStack_2c0 [4];
  int local_2bc;
  undefined auStack_16c [256];
  short local_6c;
  undefined *local_30;
  
  if (param_2[2] != 0) {
    iVar3 = getQuestion(param_2,param_2 + 6,param_3,0,auStack_2c0);
    local_30 = auStack_16c;
    if (iVar3 != 0) {
      iVar3 = GetLLQOptData(param_1,param_2,param_3);
      for (puVar9 = *(undefined4 **)(param_1 + 0x2ac); puVar9 != (undefined4 *)0x0;
          puVar9 = (undefined4 *)*puVar9) {
        if ((((*(short *)((int)puVar9 + 0x152) == 0) || (*(char *)(puVar9 + 0x96) == '\0')) ||
            (*(short *)(puVar9 + 0x95) != local_6c)) ||
           ((puVar9[1] != local_2bc || (iVar4 = SameDomainName(puVar9 + 0x55,local_30), iVar4 == 0))
           )) goto LAB_00419bbc;
        uVar5 = puVar9[0x45];
        if ((uVar5 == 4) && (*(ushort *)((int)puVar9 + 0x152) == *param_2)) {
          *(undefined *)(param_1 + 0x7fac) = 0;
          if (puVar9[0x3d] == 4) {
            uVar5 = puVar9[0x3e];
LAB_00419608:
            if (uVar5 != 0xffffffff) goto LAB_00419610;
          }
          else {
            if (puVar9[0x3d] == 6) {
              uVar5 = puVar9[0x3f] & puVar9[0x3e] & puVar9[0x40] & puVar9[0x41];
              goto LAB_00419608;
            }
LAB_00419610:
            if ((*(short *)(param_1 + 0x2998) != 0) && (*(int *)(param_1 + 0x29a0) == 0)) {
              puVar9[0x45] = 1;
            }
          }
          *(undefined2 *)(puVar9 + 0x42) = 0;
          iVar4 = mDNSPlatformOneSecond * 900;
          iVar3 = mDNSRandom(iVar4 / 10);
          puVar9[4] = iVar3 + iVar4;
          puVar9[3] = *(undefined4 *)(param_1 + 0x234);
          SetNextQueryTime(param_1,puVar9);
          uVar6 = 2;
LAB_00419bb4:
          *param_6 = puVar9;
          return uVar6;
        }
        if (iVar3 == 0) goto LAB_00419bbc;
        if ((((uVar5 == 3) && (*(short *)(iVar3 + 6) == 3)) &&
            (*(int *)(iVar3 + 0xc) == puVar9[0x49])) && (*(int *)(iVar3 + 0x10) == puVar9[0x4a])) {
          iVar4 = param_1 + 0x5cb0;
          InitializeDNSMessage(iVar4,(uint)*param_2 << 0x10,0x84000000);
          iVar3 = FUN_0040e3f4(iVar4,param_1 + 0x5cbc,puVar9,iVar3 + 4);
          if (iVar3 != 0) {
            mDNSSendDNSMessage(param_1,iVar4,iVar3,0,puVar9[0x36],param_4);
          }
          *(undefined *)(param_1 + 0x7fac) = 0;
          uVar6 = 3;
          goto LAB_00419bb4;
        }
        if (*(ushort *)((int)puVar9 + 0x152) == *param_2) {
          if (uVar5 == 3) {
            if ((((*(short *)(iVar3 + 6) == 2) && (*(int *)(iVar3 + 0xc) == puVar9[0x49])) &&
                (*(int *)(iVar3 + 0x10) == puVar9[0x4a])) &&
               ((param_2[5] != 0 && (param_2[3] == 0)))) {
              if (*(short *)(iVar3 + 8) == 0) {
                if ((*(int *)(iVar3 + 0x14) == 0) && (*(int *)(param_1 + 0x284) != 0)) {
                  *(undefined4 *)(param_1 + 0x2a4) = *(undefined4 *)(param_1 + 0x234);
                }
                GrantCacheExtensions(param_1,puVar9,*(undefined4 *)(iVar3 + 0x14));
                FUN_0040ee4c(param_1,puVar9,iVar3 + 4);
                *(undefined2 *)(puVar9 + 0x48) = 0;
                *(undefined *)(param_1 + 0x7fac) = 0;
              }
              else {
                LogMsgWithLevel(0,"recvRefreshReply: received error %d from server");
                *(undefined *)(param_1 + 0x7fac) = 0;
              }
              uVar6 = 1;
              goto LAB_00419bb4;
            }
          }
          else if ((uVar5 < 3) && (iVar4 = mDNSSameAddress(param_4,puVar9 + 0x3d), iVar4 != 0)) {
            iVar4 = puVar9[0x45];
            if (((*(byte *)((int)param_2 + 3) & 0xf) != 0) &&
               ((*(byte *)((int)param_2 + 3) & 0xf) != 3)) {
              uVar6 = DNSTypeName(*(undefined2 *)(puVar9 + 0x95));
              LogMsgWithLevel(0,
                              "ERROR: recvSetupResponse %##s (%s) - rcode && rcode != kDNSFlag1_RC_NXDomain"
                              ,puVar9 + 0x55,uVar6);
              goto LAB_00419ba0;
            }
            if (*(short *)(iVar3 + 6) == 1) {
              if (*(short *)(iVar3 + 4) != 1) {
                uVar6 = DNSTypeName(*(undefined2 *)(puVar9 + 0x95));
                pcVar8 = "ERROR: recvSetupResponse %##s (%s) - bad vers %d";
                uVar1 = *(undefined *)(iVar3 + 4);
                uVar2 = *(undefined *)(iVar3 + 5);
                goto LAB_0041999c;
              }
              if (iVar4 == 1) {
                if (*(short *)(iVar3 + 8) == 0) {
                  puVar9[0x46] = *(undefined4 *)(iVar3 + 0x14);
                  iVar7 = *(int *)(param_1 + 0x234);
                  iVar10 = *(int *)(iVar3 + 0x14) * mDNSPlatformOneSecond;
                  puVar9[0x45] = 2;
                  puVar9[0x47] = iVar10 + iVar7;
[32m[32m                  memcpy(puVar9 + 0x49,(void *)(iVar3 + 0xc),8);[0m[0m
                  *(undefined2 *)(puVar9 + 0x48) = 0;
                  FUN_0040e578(param_1,puVar9,iVar3 + 4);
                }
                else {
                  LogMsgWithLevel(0,"recvSetupResponse - received llq->err %d from server");
LAB_00419b34:
                  FUN_0040e534(param_1,puVar9);
                }
              }
              else if (iVar4 == 2) {
                if ((puVar9[0xe] != 0) && (*(char *)(puVar9[0xe] + 8) != '\0')) {
                  if (mDNS_LoggingEnabled != 0) {
                    LogMsgWithLevel(3,"Private LLQ_SecondaryRequest; copying id %08X%08X",
                                    *(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x10));
                  }
[32m[32m                  memcpy(puVar9 + 0x49,(void *)(iVar3 + 0xc),8);[0m[0m
                }
                if (*(short *)(iVar3 + 8) != 0) {
                  uVar6 = DNSTypeName(*(undefined2 *)(puVar9 + 0x95));
                  LogMsgWithLevel(0,"ERROR: recvSetupResponse %##s (%s) code %d from server",
                                  puVar9 + 0x55,uVar6,*(undefined2 *)(iVar3 + 8));
                  goto LAB_00419b34;
                }
                if ((puVar9[0x49] == *(int *)(iVar3 + 0xc)) &&
                   (puVar9[0x4a] == *(int *)(iVar3 + 0x10))) {
                  puVar9[0x45] = 3;
                  *(undefined2 *)(puVar9 + 0x48) = 0;
                  FUN_0040ee4c(param_1,puVar9,iVar3 + 4);
                }
                else {
                  LogMsgWithLevel(0,"recvSetupResponse - ID changed.  discarding");
                }
              }
            }
            else {
              uVar6 = DNSTypeName(*(undefined2 *)(puVar9 + 0x95));
              pcVar8 = "ERROR: recvSetupResponse %##s (%s) - bad op %d";
              uVar1 = *(undefined *)(iVar3 + 6);
              uVar2 = *(undefined *)(iVar3 + 7);
LAB_0041999c:
              LogMsgWithLevel(0,pcVar8,puVar9 + 0x55,uVar6,CONCAT11(uVar1,uVar2));
            }
LAB_00419ba0:
            uVar6 = 1;
            if (iVar4 == 2) {
              uVar6 = 2;
            }
            *(undefined *)(param_1 + 0x7fac) = 0;
            goto LAB_00419bb4;
          }
        }
LAB_00419bbc:
      }
      *(undefined *)(param_1 + 0x7fac) = 0;
    }
  }
  *param_6 = 0;
  return 0;
}

[ASK_GPT] 2f89767ed65b9210
