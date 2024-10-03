
void FUN_0043b970(int param_1,int param_2,uint param_3,char *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  char cVar15;
  undefined2 uVar16;
  undefined4 local_70;
  uint local_6c [4];
  undefined4 local_5c;
  uint local_58 [4];
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  char *local_34;
  char *local_30;
  
  if ((((param_2 + 0x2aU <= param_3) && (*(short *)(param_2 + 0xc) == 0x806)) &&
      (*(short *)(param_2 + 0xe) == 1)) && (*(short *)(param_2 + 0x10) == 0x800)) {
    puVar7 = *(undefined4 **)(param_1 + 0x2174);
    while( true ) {
      if (puVar7 == (undefined4 *)0x0) {
        return;
      }
      local_34 = (char *)puVar7[0x548];
      if (local_34 == param_4) break;
      puVar7 = (undefined4 *)*puVar7;
    }
    mDNS_Lock_(param_1,"mDNSCoreReceiveRawARP");
    local_38 = 1;
    if ((*(short *)(param_2 + 0x14) == 1) && (*(int *)(param_2 + 0x1c) != *(int *)(param_2 + 0x26)))
    {
      local_48 = param_2 + 0x1c;
      local_44 = param_2 + 0x26;
      local_40 = param_1 + 0x2f;
      iVar11 = param_2 + 0x16;
      local_3c = (int)puVar7 + 0x1552;
      for (puVar6 = *(undefined4 **)(param_1 + 0x2160); puVar6 != (undefined4 *)0x0;
          puVar6 = (undefined4 *)*puVar6) {
        pcVar5 = (char *)puVar6[7];
        if (((pcVar5 == local_34) && (*(char *)(puVar6 + 1) != '\x01')) &&
           ((puVar6[0x18] == 4 && (puVar6[0x19] == *(int *)(param_2 + 0x26))))) {
          if (((((*(short *)(puVar6 + 0x15) != *(short *)(param_2 + 0x16)) ||
                (*(short *)((int)puVar6 + 0x56) != *(short *)(param_2 + 0x18))) ||
               (pcVar8 = "ARP Req from owner -- re-probing",
               *(short *)(puVar6 + 0x16) != *(short *)(param_2 + 0x1a))) &&
              ((pcVar8 = "Ignoring  ARP Request from      ", *(char *)((int)puVar6 + 0x87) != '\x04'
               && (pcVar8 = "Answering ARP Request from      ",
                  *(short *)(puVar7 + 0x553) == *(short *)(param_2 + 0x16))))) &&
             ((pcVar8 = "Answering ARP Request from      ",
              *(short *)((int)puVar7 + 0x154e) == *(short *)(param_2 + 0x18) &&
              (pcVar8 = "Creating Local ARP Cache entry  ",
              *(short *)(puVar7 + 0x554) != *(short *)(param_2 + 0x1a))))) {
            pcVar8 = "Answering ARP Request from      ";
          }
          if (mDNS_LoggingEnabled != 0) {
            local_30 = pcVar5;
            uVar3 = GetRRDisplayString_rdb(puVar6 + 1,puVar6[9] + 4,local_40);
            LogMsgWithLevel(2,"%-7s %s %.6a %.4a for %.4a -- H-MAC %.6a I-MAC %.6a %s",local_3c,
                            pcVar8,iVar11,local_48,local_44,(int)puVar6 + 0x4e,puVar6 + 0x15,uVar3);
            pcVar5 = local_30;
          }
          if (pcVar8 == "ARP Req from owner -- re-probing") {
            if (*(byte *)((int)puVar6 + 0x85) < 0x14) {
              FUN_00428af8(param_1,puVar6);
            }
            else if (mDNS_LoggingEnabled != 0) {
              uVar3 = GetRRDisplayString_rdb(puVar6 + 1,puVar6[9] + 4,local_40);
              LogMsgWithLevel(2,"Reached maximum number of restarts for probing - %s",uVar3);
            }
          }
          else if (pcVar8 == "Creating Local ARP Cache entry  ") {
            mDNSPlatformSetLocalAddressCacheEntry(param_1,puVar6 + 0x18,puVar6 + 0x15,pcVar5);
          }
          else if (pcVar8 == "Answering ARP Request from      ") {
            FUN_004296e0(param_1,2,puVar6,local_44,iVar11,local_48,iVar11);
          }
        }
      }
    }
    if ((((*(short *)(puVar7 + 0x553) != *(short *)(param_2 + 0x16)) ||
         (*(short *)((int)puVar7 + 0x154e) != *(short *)(param_2 + 0x18))) ||
        (*(short *)(puVar7 + 0x554) != *(short *)(param_2 + 0x1a))) &&
       (iVar11 = (int)puVar7 + 0x1552, *(int *)(param_2 + 0x1c) != 0)) {
      iVar14 = param_2 + 0x16;
      iVar13 = param_2 + 0x1c;
      iVar12 = param_2 + 0x26;
      local_3c = 0;
      local_44 = 0;
      local_40 = 0;
      iVar9 = param_1 + 0x2f;
      for (puVar7 = *(undefined4 **)(param_1 + 0x2160); puVar7 != (undefined4 *)0x0;
          puVar7 = (undefined4 *)*puVar7) {
        if (((((char *)puVar7[7] == param_4) && (*(char *)(puVar7 + 1) != '\x01')) &&
            (puVar7[0x18] == 4)) &&
           ((puVar7[0x19] == *(int *)(param_2 + 0x1c) && (*(byte *)((int)puVar7 + 0x85) < 0x14)))) {
          if ((*(ushort *)((int)puVar7 + 0x4e) == local_44) &&
             ((*(ushort *)(puVar7 + 0x14) == local_40 &&
              (*(ushort *)((int)puVar7 + 0x52) == local_3c)))) {
            if (mDNS_LoggingEnabled != 0) {
              uVar3 = GetRRDisplayString_rdb(puVar7 + 1,puVar7[9] + 4,iVar9);
              LogMsgWithLevel(2,
                              "%-7s ARP from %.6a %.4a for %.4a -- Invalid H-MAC %.6a I-MAC %.6a %s"
                              ,iVar11,iVar14,iVar13,iVar12,(int)puVar7 + 0x4e,puVar7 + 0x15,uVar3);
            }
          }
          else {
            FUN_00428af8(param_1,puVar7);
            if ((*(short *)(puVar7 + 0x15) == *(short *)(param_2 + 0x16)) &&
               ((*(short *)((int)puVar7 + 0x56) == *(short *)(param_2 + 0x18) &&
                (*(short *)(puVar7 + 0x16) == *(short *)(param_2 + 0x1a))))) {
              if (mDNS_LoggingEnabled != 0) {
                local_30 = "Announcement ";
                if (*(int *)(param_2 + 0x1c) != *(int *)(param_2 + 0x26)) {
                  local_30 = "Response     ";
                  if (*(ushort *)(param_2 + 0x14) == local_38) {
                    local_30 = "Request      ";
                  }
                }
                uVar3 = GetRRDisplayString_rdb(puVar7 + 1,puVar7[9] + 4,iVar9);
                LogMsgWithLevel(2,
                                "%-7s ARP %s from owner %.6a %.4a for %-15.4a -- re-starting probing for %s"
                                ,iVar11,local_30,iVar14,iVar13,iVar12,uVar3);
              }
            }
            else {
              local_48 = (int)puVar7 + 0x4e;
              uVar3 = GetRRDisplayString_rdb(puVar7 + 1,puVar7[9] + 4,iVar9);
              LogMsgWithLevel(0,
                              "%-7s Conflicting ARP from %.6a %.4a for %.4a -- waking H-MAC %.6a I-MAC %.6a %s"
                              ,iVar11,iVar14,iVar13,iVar12,local_48,puVar7 + 0x15,uVar3);
              FUN_0043a2d8(param_1,puVar7[7],local_48);
            }
          }
        }
      }
    }
    mDNS_Unlock_(param_1,"mDNSCoreReceiveRawARP");
    return;
  }
  uVar10 = param_2 + 0x36;
  if ((((param_3 < param_2 + 0x22U) || (*(short *)(param_2 + 0xc) != 0x800)) ||
      ((*(byte *)(param_2 + 0x14) & 0x1f) != 0)) || (*(char *)(param_2 + 0x15) != '\0')) {
    if (param_3 < uVar10) {
      return;
    }
    if (*(short *)(param_2 + 0xc) != -0x7923) {
      return;
    }
    local_70 = 6;
[32m[32m    memcpy(local_6c,(void *)(param_2 + 0x16),0x10);[0m[0m
    local_5c = 6;
[32m[32m    memcpy(local_58,(void *)(param_2 + 0x26),0x10);[0m[0m
[32m    cVar15 = *(char *)(param_2 + 0x14);[0m
    iVar11 = 4;
    if (((cVar15 != '\x01') && (iVar11 = 0x14, cVar15 != '\x06')) &&
       ((iVar11 = 8, cVar15 != '\x11' && (iVar11 = 0x18, cVar15 != ':')))) {
      iVar11 = 0;
    }
    if (param_3 < uVar10 + iVar11) {
      return;
    }
    uVar16 = *(undefined2 *)(param_2 + 0x12);
  }
  else {
    iVar11 = 4;
    uVar10 = param_2 + 0x1eU & 3;
    uVar1 = param_2 + 0x1aU & 3;
    uVar4 = param_2 + *(ushort *)(param_2 + 0x10) + 0xe;
    uVar2 = param_2 + 0x21U & 3;
    local_58[0] = (*(int *)((param_2 + 0x1eU) - uVar10) << uVar10 * 8 |
                  (uint)*(byte *)(param_2 + 0x11) & 0xffffffffU >> (4 - uVar10) * 8) &
                  -1 << (uVar2 + 1) * 8 | *(uint *)((param_2 + 0x21U) - uVar2) >> (3 - uVar2) * 8;
    uVar10 = param_2 + 0x1dU & 3;
    local_6c[0] = (*(int *)((param_2 + 0x1aU) - uVar1) << uVar1 * 8 |
                  param_3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar10 + 1) * 8 |
                  *(uint *)((param_2 + 0x1dU) - uVar10) >> (3 - uVar10) * 8;
    if (uVar4 <= param_3) {
      param_3 = uVar4;
    }
[32m    cVar15 = *(char *)(param_2 + 0x17);[0m
    uVar10 = param_2 + (*(byte *)(param_2 + 0xe) & 0xf) * 4 + 0xe;
    local_5c = 4;
    local_70 = 4;
    if (((cVar15 != '\x01') && (iVar11 = 0x14, cVar15 != '\x06')) &&
       ((iVar11 = 8, cVar15 != '\x11' && (iVar11 = 0x18, cVar15 != ':')))) {
      iVar11 = 0;
    }
    if (param_3 < uVar10 + iVar11) {
      return;
    }
    uVar16 = 0;
  }
  FUN_0043a370(param_1,param_2 + 6,&local_70,&local_5c,cVar15,param_2,uVar10,param_3,param_4,uVar16)
  ;
  return;
}

[ASK_GPT] f38bafe0a7b6b635
