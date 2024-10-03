
undefined4
mDNSSendDNSMessage(undefined4 param_1,short *param_2,short *param_3,undefined4 param_4,
                  ushort *param_5,uint param_6,uint param_7,uint *param_8,int param_9,byte param_10)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  short *psVar4;
  ushort uVar5;
  char *pcVar6;
  short *psVar7;
  undefined *puVar8;
  undefined4 uVar9;
  short *local_res8;
  undefined4 local_resc;
  uint in_stack_ffffffa4;
  ushort in_stack_ffffffaa;
  uint in_stack_ffffffac;
  undefined local_40;
  undefined local_3f;
  short *local_38;
  uint local_34;
  short *local_30;
  
  psVar4 = param_2 + 6;
[32m  sVar1 = param_2[5];[0m
  local_34 = (uint)param_10;
  local_res8 = param_3;
  local_resc = param_4;
  if ((param_3 < psVar4) || (psVar7 = param_2 + 0x117c, 0x22ec < (int)param_3 - (int)psVar4)) {
    LogMsgWithLevel(0,"mDNSSendDNSMessage: invalid message %p %p %d",psVar4,param_3,
                    (int)param_3 - (int)(param_2 + 6));
    return 0xfffefffc;
  }
  local_30 = psVar7;
  psVar3 = (short *)putHINFO();
  if (psVar3 == (short *)0x0) {
    psVar7 = local_30;
    LogMsgWithLevel(0,"mDNSSendDNSMessage: putHINFO failed msg %p end %p, limit %p",psVar4,
                    local_res8,local_30);
    psVar3 = local_res8;
  }
  local_res8 = psVar3;
[32m  sVar2 = param_2[5];[0m
  *(char *)((int)param_2 + 7) = (char)param_2[3];
  *(char *)((int)param_2 + 5) = (char)param_2[2];
  *(char *)((int)param_2 + 9) = (char)param_2[4];
  *(char *)(param_2 + 3) = (char)((ushort)param_2[3] >> 8);
  *(char *)(param_2 + 2) = (char)((ushort)param_2[2] >> 8);
  *(char *)(param_2 + 4) = (char)((ushort)param_2[4] >> 8);
  *(char *)(param_2 + 5) = (char)((ushort)sVar2 >> 8);
  *(char *)((int)param_2 + 0xb) = (char)sVar2;
  if (param_9 != 0) {
    DNSDigest_SignMessage(param_2,&local_res8,param_9,0,psVar7);
  }
  if (local_res8 == (short *)0x0) {
    LogMsgWithLevel(0,"mDNSSendDNSMessage: DNSDigest_SignMessage failed");
    uVar9 = 0xfffefffd;
  }
  else if (param_8 == (uint *)0x0) {
    in_stack_ffffffa4 = param_6;
    in_stack_ffffffac = local_34;
    uVar9 = mDNSPlatformSendUDP(param_1,param_2,local_res8,local_resc,param_5,param_6,
                                param_7 & 0xffff0000 | (uint)in_stack_ffffffaa,local_34);
  }
  else {
    local_30 = (short *)((int)local_res8 - (int)param_2 & 0xffff);
    local_38 = local_30 + 1;
    local_3f = SUB41(local_30,0);
    local_40 = (undefined)((uint)local_30 >> 8);
    puVar8 = (undefined *)mDNSPlatformMemAllocate((size_t)local_38);
    if (puVar8 == (undefined *)0x0) {
      psVar4 = (short *)mDNSPlatformWriteTCP(param_8,&local_40,2);
      if (psVar4 == (short *)0x2) {
        uVar9 = 0;
        psVar4 = (short *)mDNSPlatformWriteTCP(param_8,param_2,local_30);
        if (psVar4 == local_30) goto LAB_00424548;
        pcVar6 = "mDNSSendDNSMessage: write msg body failed %d/%d";
        psVar7 = local_30;
      }
      else {
        pcVar6 = "mDNSSendDNSMessage: write msg length failed %d/%d";
        psVar7 = (short *)0x2;
      }
      LogMsgWithLevel(0,pcVar6,psVar4,psVar7);
      uVar9 = 0xfffeff04;
    }
    else {
      uVar9 = 0;
      *puVar8 = local_40;
      puVar8[1] = local_3f;
      mDNSPlatformMemCopy(puVar8 + 2,param_2,(size_t)local_30);
      psVar4 = (short *)mDNSPlatformWriteTCP(param_8,puVar8,local_38);
      if (psVar4 != local_38) {
        LogMsgWithLevel(0,"mDNSSendDNSMessage: write message failed %d/%d",psVar4,local_30);
        uVar9 = 0xfffeff04;
      }
      mDNSPlatformMemFree(puVar8);
    }
  }
LAB_00424548:
[32m  sVar2 = param_2[4];[0m
  *(char *)((int)param_2 + 5) = (char)param_2[2];
  *(char *)((int)param_2 + 7) = (char)param_2[3];
  *(char *)((int)param_2 + 0xb) = (char)param_2[5];
  *(char *)(param_2 + 2) = (char)((ushort)param_2[2] >> 8);
  *(char *)(param_2 + 3) = (char)((ushort)param_2[3] >> 8);
  *(char *)(param_2 + 4) = (char)((ushort)sVar2 >> 8);
  *(char *)((int)param_2 + 9) = (char)sVar2;
  *(char *)(param_2 + 5) = (char)((ushort)param_2[5] >> 8);
  if ((mDNS_PacketLoggingEnabled != 0) && (*param_2 != 0)) {
    if (param_8 == (uint *)0x0) {
      puVar8 = &DAT_0044d194;
    }
    else if ((*param_8 & 1) == 0) {
      puVar8 = &DAT_0044d19c;
    }
    else {
      puVar8 = &DAT_00450d50;
    }
    uVar5 = 0x14e9;
    if (param_5 != (ushort *)0x0) {
      uVar5 = *param_5;
    }
    DumpPacket(param_1,uVar9,1,puVar8,0,in_stack_ffffffa4 & 0xffff | (uint)uVar5 << 0x10,param_6,
               in_stack_ffffffac & 0xffff | param_7 & 0xffff0000,param_2,local_res8);
  }
  *(char *)((int)param_2 + 0xb) = (char)sVar1;
  *(char *)(param_2 + 5) = (char)((ushort)sVar1 >> 8);
  return uVar9;
}

[ASK_GPT] 4e0d7d9e1ff53463
