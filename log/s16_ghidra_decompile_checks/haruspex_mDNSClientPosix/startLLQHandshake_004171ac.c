
/* WARNING: Removing unreachable block (ram,0x00417318) */
/* WARNING: Removing unreachable block (ram,0x0041724c) */

void startLLQHandshake(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint in_stack_ffffffb4;
  undefined2 in_stack_ffffffba;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(param_1 + 0x29b4) != 0) {
    if (mDNS_LoggingEnabled != 0) {
      uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
      LogMsgWithLevel(3,"startLLQHandshake: waiting for NAT status for %##s (%s)",param_2 + 0x154,
                      uVar2);
    }
    iVar4 = mDNSPlatformOneSecond * 900;
    iVar3 = mDNSRandom(iVar4 / 10);
    *(int *)(param_2 + 0x10) = iVar3 + iVar4;
    uVar2 = *(undefined4 *)(param_1 + 0x234);
    goto LAB_0041768c;
  }
  if ((*(short *)(param_1 + 0x2998) == 0) || (*(int *)(param_1 + 0x29a0) != 0)) {
    if (mDNS_LoggingEnabled != 0) {
      uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
      LogMsgWithLevel(3,
                      "startLLQHandshake: Cannot receive inbound packets; will poll for %##s (%s) External Port %d, NAT Result %d"
                      ,param_2 + 0x154,uVar2,*(undefined2 *)(param_1 + 0x2998),
                      *(undefined4 *)(param_1 + 0x29a0));
    }
LAB_00417610:
    FUN_0040e534(param_1,param_2);
  }
  else {
    if (*(short *)(param_2 + 0x108) == 0) {
      iVar4 = mDNSPlatformOneSecond * 900;
      iVar3 = mDNSRandom(iVar4 / 10);
      *(int *)(param_2 + 0x10) = iVar3 + iVar4;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x234);
      SetNextQueryTime(param_1,param_2);
[32m[32m      memcpy((void *)(param_2 + 0xf4),zeroAddr,0x14);[0m[0m
      if (*(int *)(param_2 + 0xf0) != 0) {
        CancelGetZoneData(param_1);
      }
    }
    else {
      if ((*(int *)(param_2 + 0x38) == 0) || (*(char *)(*(int *)(param_2 + 0x38) + 8) == '\0')) {
[32m        sVar1 = *(short *)(param_2 + 0x120);[0m
        *(short *)(param_2 + 0x120) = sVar1 + 1;
        if (sVar1 < 3) {
          iVar4 = param_1 + 0x5cb0;
          local_24 = 0;
          local_28 = 0;
          local_2e = 1;
          local_30 = 1;
          local_2c = 0;
          local_20 = 0x1c20;
          InitializeDNSMessage(iVar4,(uint)*(ushort *)(param_2 + 0x152) << 0x10,0x1000000);
          iVar3 = FUN_0040e3f4(iVar4,param_1 + 0x5cbc,param_2,&local_30);
          if (iVar3 != 0) {
            mDNSSendDNSMessage(param_1,iVar4,iVar3,0,*(undefined4 *)(param_2 + 0xd8),param_2 + 0xf4,
                               CONCAT22(*(undefined2 *)(param_2 + 0x108),in_stack_ffffffba),0,0,0);
            *(undefined4 *)(param_2 + 0x114) = 1;
            *(undefined4 *)(param_2 + 0x118) = 0x1c20;
            *(int *)(param_2 + 0x10) = mDNSPlatformOneSecond << 1;
            uVar2 = *(undefined4 *)(param_1 + 0x234);
            goto LAB_0041768c;
          }
          LogMsgWithLevel(0,"ERROR: startLLQHandshake - putLLQ");
        }
        else {
          LogMsgWithLevel(0,"startLLQHandshake: %d failed attempts for LLQ %##s Polling.",3,
                          param_2 + 0x154);
        }
        goto LAB_00417610;
      }
      if ((*(int *)(param_2 + 0x10c) != 0) && (mDNS_LoggingEnabled != 0)) {
        uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
        LogMsgWithLevel(3,"startLLQHandshake: Disposing existing TCP connection for %##s (%s)",
                        param_2 + 0x154,uVar2);
      }
      if (*(int *)(param_2 + 0x10c) != 0) {
        DisposeTCPConn();
        *(undefined4 *)(param_2 + 0x10c) = 0;
      }
      if (*(int *)(param_2 + 0xf0) != 0) {
        if (*(char *)(*(int *)(param_2 + 0xf0) + 0x20a) == '\0') {
          uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
          in_stack_ffffffb4 = (uint)*(byte *)(param_2 + 600);
          LogMsgWithLevel(0,
                          "startLLQHandshake: ERROR!!: nta non NULL for %##s (%s) but HostName %d NULL, LongLived %d"
                          ,param_2 + 0x154,uVar2,*(undefined *)(*(int *)(param_2 + 0xf0) + 0x20a),
                          in_stack_ffffffb4);
        }
        iVar3 = FUN_0041447c(param_1,0,0,1,param_2 + 0xf4,
                             in_stack_ffffffb4 & 0xffff | (uint)*(ushort *)(param_2 + 0x108) << 0x10
                             ,*(int *)(param_2 + 0xf0) + 0x20a,param_2,0);
        *(int *)(param_2 + 0x10c) = iVar3;
        if (iVar3 == 0) {
          *(int *)(param_2 + 0x10) = mDNSPlatformOneSecond * 5;
        }
        else {
          *(undefined4 *)(param_2 + 0x114) = 2;
          *(undefined4 *)(param_2 + 0x118) = 0x1c20;
          *(undefined4 *)(param_2 + 0x10) = 0;
        }
        uVar2 = *(undefined4 *)(param_1 + 0x234);
LAB_0041768c:
        *(undefined4 *)(param_2 + 0xc) = uVar2;
        SetNextQueryTime(param_1,param_2);
        return;
      }
      if (mDNS_LoggingEnabled != 0) {
        uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
        LogMsgWithLevel(3,"startLLQHandshake: nta is NULL for %##s (%s)",param_2 + 0x154,uVar2);
      }
    }
    uVar2 = StartGetZoneData(param_1,param_2 + 0x154,2,&LAB_00419238,param_2);
    *(undefined4 *)(param_2 + 0xf0) = uVar2;
  }
  return;
}

[ASK_GPT] e87a6cf03a485da4
