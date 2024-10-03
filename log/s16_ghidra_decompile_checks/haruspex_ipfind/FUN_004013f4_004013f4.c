
/* WARNING: Could not reconcile some variable overlaps */

void FUN_004013f4(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  ssize_t sVar4;
  char *pcVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  undefined local_18;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  FUN_00400e50(&local_34,param_1);
  iVar2 = FUN_00400f50(param_1 + 0x1d,param_1 + 0x5d);
  iVar6 = -1;
  if (iVar2 == 0) {
    uVar1 = *(undefined2 *)(param_1 + 0x9d);
    *(char *)(param_1 + 0x9d) = (char)uVar1;
    *(char *)(param_1 + 0x9e) = (char)((ushort)uVar1 >> 8);
    FUN_004013d0("request->net_type = %d\n");
    if (*(short *)(param_1 + 0x9d) == 1) {
      local_38 = 1;
      cfgWrite("NETWORK_V4","BootProto",&local_38,1);
      iVar6 = 0;
    }
    else {
      iVar6 = -1;
      if (*(short *)(param_1 + 0x9d) == 0) {
        local_38 = 0;
        cfgWrite("NETWORK_V4","BootProto",&local_38,1);
        pcVar3 = inet_ntoa((in_addr)*(in_addr_t *)(param_1 + 0x9f));
        cfgWrite("NETWORK_V4",&DAT_00402b78,pcVar3,1);
        FUN_004013d0("set IP:%s\n",pcVar3);
        pcVar3 = inet_ntoa((in_addr)*(in_addr_t *)(param_1 + 0xa3));
        cfgWrite("NETWORK_V4","SubnetMask",pcVar3,1);
        FUN_004013d0("set mask: %s\n",pcVar3);
        iVar6 = 0;
        pcVar3 = inet_ntoa((in_addr)*(in_addr_t *)(param_1 + 0xa7));
        cfgWrite("NETWORK_V4","Gateway",pcVar3,1);
        FUN_004013d0("set gateway: %s\n",pcVar3);
      }
    }
    iVar2 = FUN_004010c0();
    if (iVar2 == 0) {
      if (iVar6 == 0) {
        local_1c._0_1_ = 0;
        goto LAB_00401660;
      }
    }
    else {
      iVar6 = -1;
    }
  }
  local_1c._0_1_ = 1;
LAB_00401660:
  local_20 = local_20 & 0xffffff00;
  local_1c = (uint)local_1c._0_1_ << 0x18;
  local_18 = 0;
  pcVar3 = inet_ntoa(client_addr._4_4_);
  client_addr._4_4_ = inet_addr("255.255.255.255");
  sVar4 = sendto(server_sockfd,&local_34,0x1d,0,(sockaddr *)client_addr,0x10);
  if (sVar4 < 0) {
    pcVar5 = "Failed";
  }
  else {
    pcVar5 = "Success";
  }
  FUN_004013d0("from %s: Change IP %s.\n",pcVar3,pcVar5);
  if (iVar6 == 0) {
[32m    system("/sbin/reboot&");[0m
  }
  return;
}

[ASK_GPT] 159c1352e89aada2
