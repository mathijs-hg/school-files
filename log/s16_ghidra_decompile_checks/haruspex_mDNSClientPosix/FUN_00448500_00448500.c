
int FUN_00448500(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,char *param_6,undefined4 param_7,ushort *param_8,ushort param_9,
                undefined4 param_10,uint param_11,int param_12,undefined4 param_13,
                undefined4 param_14,uint param_15)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  int iVar4;
  ushort *__dest;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  byte local_150 [256];
  uint local_50;
  undefined4 *local_4c;
  byte *local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  code *local_30;
  undefined4 local_2c;
  
  local_2c = 2;
  uVar6 = 4;
  if ((param_15 & 4) != 0) {
    local_2c = 0x20;
  }
  *param_2 = param_13;
  param_2[1] = param_14;
  *(undefined *)(param_2 + 2) = 0;
  param_2[5] = param_10;
  param_2[3] = 0;
  param_2[7] = param_15;
  param_2[4] = param_11;
  uVar8 = (uint)param_9;
  if (((param_12 != -2) && (uVar6 = 5, param_12 != -4)) &&
     ((param_12 != 0 ||
      (((uVar6 = 3, (param_15 & 3) != 3 && (uVar6 = 1, (param_15 & 1) == 0)) &&
       (uVar6 = 2, (param_15 & 2) == 0)))))) {
    uVar6 = 0;
  }
  local_3c = param_2 + 8;
  local_40 = param_2 + 0xe9;
  local_30 = (code *)0x1194;
  mDNS_SetupResourceRecord(local_3c,0,param_12,0xc,0x1194,4,uVar6,FUN_0043c870,param_2);
  mDNS_SetupResourceRecord(local_40,0,param_12,0xc,local_30,8,uVar6,FUN_0043c870,param_2);
  if ((param_15 & 8) != 0) {
    *(undefined *)((int)param_2 + 0x3ef) = 1;
  }
  puVar7 = param_2 + 0x1ca;
  iVar1 = SameDomainName(param_4,&DAT_0045c8a8);
  uVar5 = 0x78;
  if (iVar1 != 0) {
    uVar5 = 10;
  }
  local_4c = param_2 + 0x2ab;
  local_30 = FUN_0043c870;
  mDNS_SetupResourceRecord(puVar7,0,param_12,0x21,uVar5,local_2c,uVar6,FUN_0043c870,param_2);
  mDNS_SetupResourceRecord(local_4c,0,param_12,0x10,0x1194,2,uVar6,local_30,param_2);
  if (param_7._0_2_ == 0) {
    iVar1 = FUN_00448324(param_1,puVar7,param_3,param_4,param_5,0,param_12,&LAB_00426904,param_2,
                         param_15);
    return iVar1;
  }
  if (*(ushort *)param_2[0x2b4] < uVar8) {
    *(ushort *)param_2[0x2b4] = param_9;
  }
  iVar1 = ConstructServiceName(param_2 + 0x66,"\t_services",&DAT_0045c8c0,param_5);
  if (iVar1 != 0) {
    iVar1 = ConstructServiceName(param_2 + 0x147,0,param_4,param_5);
    local_44 = param_2 + 0x228;
    if ((iVar1 != 0) && (iVar1 = ConstructServiceName(local_44,param_3,param_4,param_5), iVar1 != 0)
       ) {
      uVar2 = DomainNameLengthLimit(param_2[0x1d2],param_2[0x1d2] + 0x100);
      if (uVar2 < 0x101) {
        mDNSPlatformMemCopy(param_2 + 0x309,(void *)param_2[0x1d2],uVar2);
      }
      else {
        *(undefined *)(param_2 + 0x309) = 0;
      }
      uVar2 = DomainNameLengthLimit(param_2[0xf1],param_2[0xf1] + 0x100);
      if (uVar2 < 0x101) {
        mDNSPlatformMemCopy((void *)(param_2[0x11] + 4),(void *)param_2[0xf1],uVar2);
      }
      else {
        *(undefined *)(param_2[0x11] + 4) = 0;
      }
      uVar2 = DomainNameLengthLimit(param_2[0x1d2],param_2[0x1d2] + 0x100);
      if (uVar2 < 0x101) {
        mDNSPlatformMemCopy((void *)(param_2[0xf2] + 4),(void *)param_2[0x1d2],uVar2);
      }
      else {
        *(undefined *)(param_2[0xf2] + 4) = 0;
      }
      local_34 = param_2 + 0x228;
      local_38 = param_2 + 0x268;
      local_48 = local_150;
      param_2[0xf5] = puVar7;
      param_2[0xf6] = local_4c;
      local_50 = 0;
      while (iVar1 = local_50 * 900, local_50 < param_11) {
        iVar9 = *(int *)(param_2[5] + iVar1 + 0x20);
        uVar2 = DomainNameLengthLimit(iVar9,iVar9 + 0x100);
        if (uVar2 < 0x101) {
          mDNSPlatformMemCopy(local_48,*(void **)(param_2[5] + iVar1 + 0x20),uVar2);
        }
        else {
          local_150[0] = 0;
        }
        local_48[local_150[0] + 1] = 0;
        AppendDomainName(local_48,param_4);
        mDNS_SetupResourceRecord
                  (param_2[5] + iVar1,0,param_12,0xc,0x1194,8,uVar6,FUN_0043c870,param_2);
        iVar9 = ConstructServiceName(param_2[5] + iVar1 + 0x178,0,local_48,param_5);
        if (iVar9 == 0) {
          return -0x10004;
        }
        uVar2 = DomainNameLengthLimit(local_44,local_38);
        if (uVar2 < 0x101) {
          mDNSPlatformMemCopy((void *)(*(int *)(param_2[5] + iVar1 + 0x24) + 4),local_34,uVar2);
        }
        else {
          *(undefined *)(*(int *)(param_2[5] + iVar1 + 0x24) + 4) = 0;
        }
        local_50 = local_50 + 1;
        *(undefined4 **)(param_2[5] + iVar1 + 0x30) = puVar7;
        *(undefined4 **)(param_2[5] + iVar1 + 0x34) = local_4c;
      }
      if ((char *)param_2[6] != (char *)0x0) {
[32m        sVar3 = mDNSPlatformStrLen((char *)param_2[6]);[0m
        if (param_2[0xf4] != 0) {
          LogMsgWithLevel(0,
                          "SetAnonInfoSRS: Freeing AnonInfo for PTR record %##s, should have been freed already"
                          ,param_2[0xf1]);
          FreeAnonInfo(param_2[0xf4]);
        }
        iVar1 = 0;
        uVar6 = AllocateAnonInfo(param_2[0xf1],param_2[6],sVar3,0);
        param_2[0xf4] = uVar6;
        while (iVar9 = iVar1 * 900, iVar1 < (int)param_11) {
          iVar1 = iVar1 + 1;
          if (*(int *)(param_2[5] + iVar9 + 0x2c) != 0) {
            LogMsgWithLevel(0,
                            "SetAnonInfoSRS: Freeing AnonInfo for subtype record %##s, should have been freed already"
                            ,*(undefined4 *)(param_2[5] + iVar9 + 0x20));
            FreeAnonInfo(*(undefined4 *)(param_2[5] + iVar9 + 0x2c));
          }
          iVar4 = param_2[5];
          uVar6 = AllocateAnonInfo(*(undefined4 *)(iVar4 + iVar9 + 0x20),param_2[6],sVar3,0);
          *(undefined4 *)(iVar4 + iVar9 + 0x2c) = uVar6;
        }
      }
      *(undefined2 *)(param_2[0x1d3] + 4) = 0;
      *(undefined2 *)(param_2[0x1d3] + 6) = 0;
      *(short *)(param_2[0x1d3] + 8) = param_7._0_2_;
      if ((param_6 == (char *)0x0) || (*param_6 == '\0')) {
        *(undefined *)(param_2 + 0x1dc) = 1;
        *(undefined *)(param_2[0x1d3] + 10) = 0;
      }
      else {
        uVar2 = DomainNameLengthLimit(param_6,param_6 + 0x100);
        if (uVar2 < 0x101) {
          mDNSPlatformMemCopy((void *)(param_2[0x1d3] + 10),param_6,uVar2);
        }
        else {
          *(undefined *)(param_2[0x1d3] + 10) = 0;
        }
      }
      if (param_8 == (ushort *)0x0) {
        *(undefined2 *)(param_2 + 0x2af) = 0;
      }
      else {
        __dest = (ushort *)param_2[0x2b4] + 2;
        if (param_8 != __dest) {
          *(ushort *)(param_2 + 0x2af) = param_9;
          if (*(ushort *)param_2[0x2b4] < uVar8) {
            return -0x10004;
          }
          mDNSPlatformMemCopy(__dest,param_8,uVar8);
        }
      }
      param_2[0x2b9] = puVar7;
      mDNS_Lock_(param_1,"mDNS_RegisterService");
      iVar1 = mDNS_Register_internal(param_1,puVar7);
      if (iVar1 == 0) {
        iVar1 = mDNS_Register_internal(param_1,local_4c);
        if (iVar1 == 0) {
          iVar1 = mDNS_Register_internal(param_1,local_3c);
        }
        for (uVar8 = 0; uVar8 < param_11; uVar8 = uVar8 + 1) {
          if (iVar1 == 0) {
            iVar1 = mDNS_Register_internal(param_1,param_2[5] + uVar8 * 900);
          }
        }
        if (iVar1 == 0) {
          iVar1 = mDNS_Register_internal(param_1,local_40);
        }
        mDNS_Unlock_(param_1,"mDNS_RegisterService");
        if (iVar1 != 0) {
          FUN_0043c5a8(param_1,param_2,0);
          return iVar1;
        }
        return 0;
      }
      mDNS_Unlock_(param_1,"mDNS_RegisterService");
      return iVar1;
    }
  }
  return -0x10004;
}

[ASK_GPT] e6ceafbe1ec004f2
