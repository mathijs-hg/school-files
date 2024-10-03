
/* WARNING: Could not reconcile some variable overlaps */

void DNSDigest_SignMessage(undefined *param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  void *__src;
  int iVar5;
  int iVar6;
  undefined2 local_438;
  undefined2 local_436;
  undefined local_434;
  undefined local_433;
  undefined local_432;
  undefined local_431;
  undefined local_430;
  undefined local_42f;
  undefined auStack_42c [16];
  undefined4 local_41c;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 local_3c4;
  undefined auStack_3c0 [4];
  undefined auStack_3bc [4];
  undefined2 local_3b8;
  undefined4 local_3b4;
  short local_3b0;
  undefined4 local_39c;
  undefined local_248 [528];
  undefined2 *local_38;
  undefined *local_34;
  int local_30;
  int local_2c;
  
  local_436 = *(undefined2 *)(param_1 + 10);
  local_40c = 0;
  __src = (void *)(param_3 + 0x12b4);
  local_408 = 0;
  local_41c = 0x67452301;
  local_3c4 = 0;
  local_418 = 0xefcdab89;
  local_414 = 0x98badcfe;
  local_410 = 0x10325476;
  iVar6 = *param_2;
  FUN_0040a2d0(&local_41c,param_3 + 0x14d6,0x40);
  FUN_0040a2d0(&local_41c,param_1,*param_2 - (int)param_1);
  mDNS_SetupResourceRecord(auStack_3c0,0,0,0xfa,0,0x20,0,0,0);
  uVar2 = DomainNameLengthLimit(__src,param_3 + 0x13b4);
  if (uVar2 < 0x101) {
    mDNSPlatformMemCopy(local_248,__src,uVar2);
  }
  else {
    local_248[0] = 0;
  }
  uVar3 = DomainNameLengthLimit(__src,param_3 + 0x13b4);
  FUN_0040a2d0(&local_41c,param_3 + 0x12b4,uVar3);
  local_3b8 = 0xff;
  local_438 = 0xff;
  FUN_0040a2d0(&local_41c,&local_438,2);
  local_3b4 = 0;
  FUN_0040a2d0(&local_41c,&local_3b4,4);
  uVar2 = DomainNameLengthLimit(&DAT_0044cfc0,"nature");
  if (uVar2 < 0x101) {
    mDNSPlatformMemCopy((void *)(local_39c + 4),&DAT_0044cfc0,uVar2);
  }
  else {
    *(undefined *)(local_39c + 4) = 0;
  }
  iVar4 = DomainNameLengthLimit(&DAT_0044cfc0,"nature");
  iVar5 = local_39c + iVar4;
  FUN_0040a2d0(&local_41c,&DAT_0044cfc0,iVar4);
  local_34 = (undefined *)mDNSPlatformUTC();
  if (local_34 == (undefined *)0xffffffff) {
    LogMsgWithLevel(0,"ERROR: DNSDigest_SignMessage - mDNSPlatformUTC returned bad time -1");
    *param_2 = 0;
  }
  local_38 = &local_438;
  local_432 = (undefined)((uint)local_34 >> 0x18);
  local_30 = iVar5 + 10;
  local_2c = iVar5 + 0xc;
  local_431 = (undefined)((uint)local_34 >> 0x10);
  local_430 = (undefined)((uint)local_34 >> 8);
  local_42f = SUB41(local_34,0);
  local_434 = 0;
  local_433 = 0;
  local_34 = &local_434;
  mDNSPlatformMemCopy((void *)(iVar5 + 4),&local_434,6);
  FUN_0040a2d0(&local_41c,local_34,6);
  *(undefined *)(iVar5 + 10) = 1;
  *(undefined *)(local_30 + 1) = 0x2c;
  FUN_0040a2d0(&local_41c,local_30,2);
  local_438 = (undefined2)param_4;
  FUN_0040a2d0(&local_41c,local_38,2);
  local_438 = 0;
  FUN_0040a2d0(&local_41c,local_38,2);
  FUN_00409040(auStack_42c,&local_41c);
  local_41c = 0x67452301;
  local_40c = 0;
  local_418 = 0xefcdab89;
  local_408 = 0;
  local_414 = 0x98badcfe;
  local_3c4 = 0;
  local_410 = 0x10325476;
  FUN_0040a2d0(&local_41c,param_3 + 0x1516,0x40);
  FUN_0040a2d0(&local_41c,auStack_42c,0x10);
  FUN_00409040(auStack_42c,&local_41c);
  *(undefined *)(iVar5 + 0xc) = 0;
  *(undefined *)(local_2c + 1) = 0x10;
  mDNSPlatformMemCopy((void *)(iVar5 + 0xe),auStack_42c,0x10);
  *(undefined *)(iVar5 + 0x1e) = *param_1;
  uVar1 = param_1[1];
  *(char *)(iVar5 + 0x20) = (char)((uint)param_4 >> 8);
  *(undefined *)(iVar5 + 0x1f) = uVar1;
  *(char *)(iVar5 + 0x21) = (char)param_4;
  *(undefined *)(iVar5 + 0x23) = 0;
  *(undefined *)(iVar5 + 0x22) = 0;
[32m  local_3b0 = ((short)(void *)(iVar5 + 4) - local_39c._2_2_) + 0x1c;[0m
  iVar6 = PutResourceRecordTTLWithLimit(param_1,iVar6,&local_436,auStack_3bc,0,param_1 + 0x22f8);
  *param_2 = iVar6;
  if (iVar6 == 0) {
    LogMsgWithLevel(0,"ERROR: DNSDigest_SignMessage - could not put TSIG");
    *param_2 = 0;
  }
  else {
    param_1[0xb] = (char)local_436;
    param_1[10] = (char)((ushort)local_436 >> 8);
  }
  return;
}

[ASK_GPT] c949e44a6c60a5a6
