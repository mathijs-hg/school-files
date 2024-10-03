
int FUN_0042ee98(int param_1,int param_2,int param_3,char param_4,undefined4 param_5)

{
  undefined4 uVar1;
  short sVar4;
  undefined2 *puVar2;
  int iVar3;
  char *pcVar5;
  uint __n;
  int iVar6;
  uint uVar7;
  short local_170 [2];
  short local_16c;
  undefined auStack_16a [2];
  int local_168;
  undefined auStack_164 [4];
  undefined auStack_160 [4];
  undefined auStack_15c [8];
  int local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined2 local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  char local_11c;
  undefined auStack_11b [259];
  
  FUN_0042ac48(param_2,&local_168,&local_144,&local_130,auStack_15c,auStack_164,auStack_160,
               local_170,&local_16c,auStack_16a);
  if ((((local_168 == 0) ||
       (((local_144 == 4 ||
         ((((local_144 == 6 && (local_13c == 0)) && (local_140 == 0)) &&
          (local_140 = local_134, local_138 == 0)))) && (local_140 == 0)))) ||
      (((local_130 == 4 ||
        (((local_130 == 6 && (local_128 == 0)) &&
         ((local_12c == 0 && (local_12c = local_120, local_124 == 0)))))) && (local_12c == 0)))) ||
     ((local_170[0] == 0 || (local_16c == 0)))) {
    uVar1 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,"UpdateKeepaliveRData: not a valid record %s for keepalive %#a:%d %#a:%d",
                    uVar1,&local_144,local_170[0],&local_130,local_16c);
    return -0x10001;
  }
  if (param_4 == '\0') {
    mDNSPlatformMemZero(&local_154,0x10);
    iVar3 = mDNSPlatformRetrieveTCPInfo
                      (param_1,&local_144,local_170,&local_130,&local_16c,&local_154);
    if (iVar3 == 0) {
      if ((param_3 != 0) && (local_154 != *(int *)(param_3 + 0x1520))) {
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,
                          "mDNSPlatformRetrieveTCPInfo: InterfaceID  mismatch mti.IntfId = %p InterfaceID = %p"
                         );
        }
        return -0x10004;
      }
      if (local_144 == 4) {
        pcVar5 = "t=%d i=%d c=%d h=%#a d=%#a l=%u r=%u m=%.6a s=%u a=%u w=%u";
      }
      else {
        pcVar5 = "t=%d i=%d c=%d H=%#a D=%#a l=%u r=%u m=%.6a s=%u a=%u w=%u";
      }
      sVar4 = mDNS_snprintf(auStack_11b,0xff,pcVar5,local_168,0x1e,10,&local_144,&local_130,
[32m[32m                            local_170[0],local_16c,auStack_15c,local_150,local_14c,local_148);[0m[0m
      goto LAB_0042f204;
    }
    uVar1 = 0;
    pcVar5 = "mDNSPlatformRetrieveTCPInfo: mDNSPlatformRetrieveTCPInfo failed %d";
    iVar6 = iVar3;
LAB_0042f380:
    LogMsgWithLevel(uVar1,pcVar5,iVar3);
  }
  else {
    if (local_144 == 4) {
      pcVar5 = "t=%d i=%d c=%d h=%#a d=%#a l=%u r=%u m=%s";
    }
    else {
      pcVar5 = "t=%d i=%d c=%d H=%#a D=%#a l=%u r=%u m=%s";
    }
    sVar4 = mDNS_snprintf(auStack_11b,0xff,pcVar5,local_168,0x1e,10,&local_144,&local_130,
[32m[32m                          local_170[0],local_16c,param_5);[0m[0m
LAB_0042f204:
    if (sVar4 == 0xff) {
      uVar1 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
      LogMsgWithLevel(0,"UpdateKeepaliveRData: could not allocate memory %s",uVar1);
    }
    else {
      __n = (uint)(ushort)(sVar4 + 2);
[32m      local_11c = (char)sVar4 + '\x01';[0m
      uVar7 = 0x108;
      if (0x108 < __n) {
        uVar7 = __n;
      }
      puVar2 = (undefined2 *)mDNSPlatformMemAllocate(uVar7 + 4);
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = (short)uVar7;
        mDNSPlatformMemCopy(puVar2 + 2,&local_11c,__n);
        if (*(void **)(param_2 + 0x24) != (void *)(param_2 + 0x278)) {
          mDNSPlatformMemFree(*(void **)(param_2 + 0x24));
          if (mDNS_LoggingEnabled != 0) {
            uVar1 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
            LogMsgWithLevel(2,
                            "UpdateKeepaliveRData: Freed allocated memory for keep alive packet: %s "
                            ,uVar1);
          }
        }
        SetNewRData(param_2 + 4,puVar2,__n);
        if (mDNS_LoggingEnabled == 0) {
          return 0;
        }
        iVar3 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
        pcVar5 = "UpdateKeepaliveRData: successfully updated the record %s";
        uVar1 = 2;
        iVar6 = 0;
        goto LAB_0042f380;
      }
      LogMsgWithLevel(0,"UpdateKeepaliveRData: ptr NULL");
    }
    iVar6 = -0x10003;
  }
  return iVar6;
}

[ASK_GPT] f74d81e0928c2334
