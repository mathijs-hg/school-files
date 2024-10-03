
void FUN_0042b424(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  short local_88 [2];
  short local_84 [2];
  short local_80 [2];
  int local_7c;
  int local_78;
  int local_74;
  undefined auStack_70 [8];
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int *local_40;
  undefined *local_3c;
  int *local_38;
  int *local_34;
  short *local_30;
  
  local_40 = &local_7c;
  local_3c = auStack_70;
  local_38 = &local_78;
  local_34 = &local_74;
  local_30 = local_88;
  for (puVar2 = *(undefined4 **)(param_1 + 0x2160); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    local_74 = 0;
    local_78 = 0;
    local_7c = 0;
    local_88[0] = 0;
[32m[32m    memcpy(&local_54,zeroAddr,0x14);[0m[0m
[32m[32m    memcpy(&local_68,&local_54,0x14);[0m[0m
    local_84[0] = 0;
    local_80[0] = local_84[0];
    if (((((*(int *)((int)puVar2 + 0x4e) != 0) &&
          (FUN_0042ac48(puVar2,local_40,&local_68,&local_54,local_3c,local_38,local_34,local_84,
                        local_80,local_30), local_7c != 0)) &&
         (((iVar1 = local_64, local_68 != 4 &&
           ((((local_68 != 6 || (local_60 != 0)) || (local_64 != 0)) ||
            (iVar1 = local_58, local_5c != 0)))) || (iVar1 != 0)))) &&
        ((((iVar1 = local_50, local_54 != 4 &&
           (((local_54 != 6 || (local_4c != 0)) ||
            ((local_50 != 0 || (iVar1 = local_44, local_48 != 0)))))) || (iVar1 != 0)) &&
         ((local_78 != 0 && (local_74 != 0)))))) &&
       ((local_84[0] != 0 && ((local_80[0] != 0 && (local_88[0] != 0)))))) {
      LogMsgWithLevel(0,"mDNS_SendKeepalives: laddr %#a raddr %#a lport %d rport %d",&local_68,
                      &local_54,local_84[0],local_80[0]);
      if ((puVar2[0x20] == 0) || (-1 < *(int *)(param_1 + 0x234) - puVar2[0x20])) {
        mDNSPlatformSendKeepalive
                  (&local_68,&local_54,local_84,local_80,local_78,local_74,local_88[0]);
        iVar1 = mDNSPlatformOneSecond * local_7c + *(int *)(param_1 + 0x234);
        if (iVar1 == 0) {
          iVar1 = 1;
        }
        puVar2[0x20] = iVar1;
      }
      if (0 < *(int *)(param_1 + 0x260) - puVar2[0x20]) {
        *(undefined4 *)(param_1 + 0x260) = puVar2[0x20];
      }
    }
  }
  return;
}

[ASK_GPT] 0d3710d039aec71f
