
void DumpPacket(undefined4 param_1,int param_2,char param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,int param_7,undefined4 param_8,undefined2 *param_9,int param_10)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  byte bVar7;
  byte bVar8;
  undefined2 *puVar5;
  undefined4 uVar6;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  undefined auStack_380 [64];
  undefined auStack_340 [64];
  undefined local_300 [64];
  undefined auStack_2c0 [340];
  undefined auStack_16c [256];
  undefined2 local_6c;
  int local_30;
  
  local_300[0] = 0;
  bVar2 = (*(byte *)(param_9 + 1) & 0x78) == 0x28;
  local_30 = param_2;
[32m  memset(local_300 + 1,0,0x3f);[0m
  if (local_30 == 0) {
    if (param_3 == '\0') {
      pcVar11 = "Received";
    }
    else {
      pcVar11 = "Sent";
    }
[32m    iVar3 = mDNS_snprintf(auStack_380,0x40,pcVar11);[0m
    puVar4 = auStack_380 + iVar3;
  }
  else {
    if (param_3 == '\0') {
      pcVar11 = "Receive";
    }
    else {
      pcVar11 = "Send";
    }
[32m    iVar3 = mDNS_snprintf(auStack_380,0x40,"ERROR %d %sing",local_30,pcVar11);[0m
    puVar4 = auStack_380 + iVar3;
  }
  *puVar4 = 0;
  if (param_3 == '\0') {
[32m    iVar3 = mDNS_snprintf(auStack_340,0x40,&DAT_0045409c,param_5);[0m
  }
  else {
[32m    iVar3 = mDNS_snprintf(auStack_340,0x40,"port ");[0m
  }
  auStack_340[iVar3] = 0;
  if ((param_7 != 0) || (param_8._0_2_ != 0)) {
[32m    iVar3 = mDNS_snprintf(local_300,0x40," to %#a:%d",param_7,param_8._0_2_);[0m
    local_300[iVar3] = 0;
  }
  bVar1 = *(byte *)(param_9 + 1);
  bVar7 = bVar1 & 0x78;
  if ((bVar1 & 0x78) == 0) {
    pcVar11 = "";
  }
  else if (bVar7 == 8) {
    pcVar11 = "Iquery ";
  }
  else if (bVar7 == 0x10) {
    pcVar11 = "Status ";
  }
  else if (bVar7 == 0x18) {
    pcVar11 = "Unused3 ";
  }
  else if (bVar7 == 0x20) {
    pcVar11 = "Notify ";
  }
  else if (bVar7 == 0x28) {
    pcVar11 = "Update ";
  }
  else {
    pcVar11 = "?? ";
  }
  if ((char)bVar1 < '\0') {
    pcVar10 = "Response";
  }
  else {
    pcVar10 = "Query";
  }
  bVar7 = *(byte *)((int)param_9 + 3);
  bVar8 = bVar7 & 0xf;
  if ((bVar7 & 0xf) == 0) {
    pcVar9 = "NoErr";
  }
  else if (bVar8 == 1) {
    pcVar9 = "FormErr";
  }
  else if (bVar8 == 2) {
    pcVar9 = "ServFail";
  }
  else if (bVar8 == 3) {
    pcVar9 = "NXDomain";
  }
  else if (bVar8 == 4) {
    pcVar9 = "NotImpl";
  }
  else if (bVar8 == 5) {
    pcVar9 = "Refused";
  }
  else if (bVar8 == 6) {
    pcVar9 = "YXDomain";
  }
  else if (bVar8 == 7) {
    pcVar9 = "YXRRSet";
  }
  else if (bVar8 == 8) {
    pcVar9 = "NXRRSet";
  }
  else if (bVar8 == 9) {
    pcVar9 = "NotAuth";
  }
  else if (bVar8 == 10) {
    pcVar9 = "NotZone";
  }
  else {
    pcVar9 = "??";
  }
  if ((bVar1 & 4) == 0) {
    pcVar18 = "";
  }
  else {
    pcVar18 = "AA ";
  }
  if ((bVar1 & 2) == 0) {
    pcVar17 = "";
  }
  else {
    pcVar17 = "TC ";
  }
  if ((bVar1 & 1) == 0) {
    pcVar16 = "";
  }
  else {
    pcVar16 = "RD ";
  }
  if ((char)bVar7 < '\0') {
    pcVar15 = "RA ";
  }
  else {
    pcVar15 = "";
  }
  if ((bVar7 & 0x20) == 0) {
    pcVar14 = "";
  }
  else {
    pcVar14 = "AD ";
  }
  if ((bVar7 & 0x10) == 0) {
    pcVar13 = "";
  }
  else {
    pcVar13 = "CD ";
  }
  if ((bVar1 & 2) == 0) {
    pcVar12 = "";
  }
  else {
    pcVar12 = " (truncated)";
  }
  LogMsgWithLevel(0,
                  "-- %s %s DNS %s%s (flags %02X%02X) RCODE: %s (%d) %s%s%s%s%s%sID: %d %d bytes from %s%d%s%s --"
                  ,auStack_380,param_4,pcVar11,pcVar10,bVar1,bVar7,pcVar9,bVar8,pcVar18,pcVar17,
                  pcVar16,pcVar15,pcVar14,pcVar13,*param_9,param_10 - (int)(param_9 + 6),auStack_340
                  ,(uint)(param_6._0_2_ >> 8) << 8 | param_6._0_2_ & 0xff,local_300,pcVar12);
  if (bVar2) {
    pcVar11 = "Zone";
  }
  else {
    pcVar11 = "Questions";
  }
  puVar5 = param_9 + 6;
  LogMsgWithLevel(0,"%2d %s",param_9[2],pcVar11);
  iVar3 = 0;
  while ((iVar3 < (int)(uint)(ushort)param_9[2] && (puVar5 != (undefined2 *)0x0))) {
    puVar5 = (undefined2 *)getQuestion(param_9,puVar5,param_10,0,auStack_2c0);
    if (puVar5 != (undefined2 *)0x0) {
      uVar6 = DNSTypeName(local_6c);
      LogMsgWithLevel(0,"%2d %##s %s",iVar3,auStack_16c,uVar6);
    }
    iVar3 = iVar3 + 1;
  }
  if (bVar2) {
    pcVar11 = "Prerequisites";
  }
  else {
    pcVar11 = "Answers";
  }
  uVar6 = FUN_00423a3c(param_1,param_9,puVar5,param_10,param_9[3],pcVar11);
  if (bVar2) {
    pcVar11 = "Updates";
  }
  else {
    pcVar11 = "Authorities";
  }
  uVar6 = FUN_00423a3c(param_1,param_9,uVar6,param_10,param_9[4],pcVar11);
  FUN_00423a3c(param_1,param_9,uVar6,param_10,param_9[5],"Additionals");
  LogMsgWithLevel(0,"--------------");
  return;
}

[ASK_GPT] 0c7897b7fe77a7d2
