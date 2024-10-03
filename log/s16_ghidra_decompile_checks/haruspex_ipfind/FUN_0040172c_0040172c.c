
/* WARNING: Could not reconcile some variable overlaps */

void FUN_0040172c(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  ssize_t sVar3;
  uint uVar4;
  char *pcVar5;
  char local_358;
  undefined auStack_357 [255];
  uint local_258;
  byte local_254 [4];
  undefined auStack_250 [20];
  uint local_23c;
  undefined4 local_238;
  undefined uStack_234;
  char acStack_233 [64];
  char acStack_1f3 [32];
  char acStack_1d3 [16];
  char acStack_1c3 [7];
  uint local_1bc;
  undefined4 uStack_1b8;
  undefined4 local_135;
  undefined4 local_131;
  undefined4 local_12d;
  undefined4 local_129;
  byte bStack_125;
  uint local_124;
  undefined4 local_30;
  ushort local_2c;
  ushort local_2a;
  ushort local_28 [6];
  
  local_358 = '\0';
[32m  memset(auStack_357,0,0xff);[0m
  local_258 = 0;
  local_254[0] = 0;
  local_2c = 0;
  local_2a = 0;
  local_28[0] = 0;
[32m  memset(auStack_250,0,0x21d);[0m
  FUN_00400e50(auStack_250,param_1);
  local_23c = local_23c & 0xffffff00;
  local_238 = 0x200;
  uStack_234 = 0;
[32m  memset(&local_358,0,0x100);[0m
  cfgRead(&DAT_00402c08,"BrandName",&local_358);
[32m[32m[32m  strncpy(acStack_233,&local_358,0x40);[0m[0m[0m
[32m  memset(&local_358,0,0x100);[0m
  cfgRead("System","MainVersion",&local_2c);
  cfgRead("System","FirmwareVersion",&local_2a);
  cfgRead("System","CustomerVersion",local_28);
[32m  sprintf(acStack_1c3,"%u.%u.%u",(uint)local_2c,(uint)local_2a,(uint)local_28[0]);[0m
  local_258 = 0;
  cfgRead(&DAT_00402c08,"MachineType",&local_258);
  local_1bc = local_1bc & 0xff0000ff | ((local_258 & 0xff) << 8 | local_258 >> 8 & 0xff) << 8;
  local_254[0] = 0;
  cfgRead(&DAT_00402c08,"Wireless",local_254);
  uStack_1b8 = uStack_1b8 & 0xff | (local_254[0] & 1 | uStack_1b8 >> 8) << 8;
  local_258 = 0;
  cfgRead(&DAT_00402c08,"TriggerIn",&local_258);
  uStack_1b8 = uStack_1b8 & 0xff | ((local_258 & 3) << 1 | uStack_1b8 >> 8) << 8;
  local_258 = 0;
  cfgRead(&DAT_00402c08,"TriggerOut",&local_258);
  uStack_1b8 = uStack_1b8 & 0xff | ((local_258 & 3) << 3 | uStack_1b8 >> 8) << 8;
  local_254[0] = 0;
  cfgRead(&DAT_00402c08,&DAT_00402c8c,local_254);
  uStack_1b8 = uStack_1b8 & 0xff | ((local_254[0] & 1) << 5 | uStack_1b8 >> 8) << 8;
  local_254[0] = 0;
  cfgRead(&DAT_00402c08,&DAT_00402c90,local_254);
  uVar4 = local_1bc & 0xff;
  local_1bc = local_1bc & 0xffffff00 | (local_254[0] & 1) << 6 | uStack_1b8._0_3_ & 0xff;
  uStack_1b8 = uStack_1b8 & 0xff |
               (uVar4 | (uStack_1b8._0_3_ & 0xff0000) >> 8 | (uStack_1b8._0_3_ & 0xff00) << 8) << 8;
[32m  memset(&local_358,0,0x100);[0m
  cfgRead("System","ModelName",&local_358);
[32m[32m[32m  strncpy(acStack_1f3,&local_358,0x20);[0m[0m[0m
[32m  memset(&local_358,0,0x100);[0m
  cfgRead(&DAT_00402c08,"ModelNumber",&local_358);
[32m[32m[32m  strncpy(acStack_1d3,&local_358,0x10);[0m[0m[0m
[32m  memset(&local_358,0,0x100);[0m
  cfgRead("CAMSYSTEM","CameraName",&local_358);
[32m[32m[32m  strncpy((char *)((int)&uStack_1b8 + 3),&local_358,0x40);[0m[0m[0m
  iVar1 = net_get_netmask(ifname,&local_30);
  if (-1 < iVar1) {
    local_135 = local_30;
  }
  iVar1 = net_get_gateway(&local_30);
  if (-1 < iVar1) {
    local_131 = local_30;
  }
  iVar1 = net_get_dns(&local_30);
  if (-1 < iVar1) {
    local_12d = local_30;
  }
  iVar1 = net_get_dns2(&local_30);
  if (-1 < iVar1) {
    local_129 = local_30;
  }
  local_258 = 0;
  cfgRead(&DAT_00402cc8,&DAT_00402cd0,&local_258);
  if (local_258 == 0) {
    bStack_125 = 0;
    local_124 = local_124 & 0xffffff | 0x50000000;
  }
  else {
    bStack_125 = (byte)((local_258 & 0xffff) >> 8);
    local_124 = local_124 & 0xffffff | (local_258 & 0xffff) << 0x18;
  }
  uVar4 = (uint)bStack_125;
  bStack_125 = (byte)(local_124 >> 0x18);
  local_124 = local_124 & 0xffffff | uVar4 << 0x18;
  local_258 = 0;
  cfgRead(&DAT_00402cd8,&DAT_00402cd0,&local_258);
  local_124 = local_124 & 0xff0000ff | ((local_258 & 0xff) << 8 | local_258 >> 8 & 0xff) << 8;
  pcVar2 = inet_ntoa(client_addr._4_4_);
  client_addr._4_4_ = inet_addr("255.255.255.255");
  sVar3 = sendto(server_sockfd,auStack_250,0x21d,0,(sockaddr *)client_addr,0x10);
  if (sVar3 < 0) {
    pcVar5 = "Failed";
  }
  else {
    pcVar5 = "Success";
  }
  FUN_004013d0("from %s: Discovery %s.\n",pcVar2,pcVar5);
  return;
}

[ASK_GPT] a24d52d8b7c71b13
