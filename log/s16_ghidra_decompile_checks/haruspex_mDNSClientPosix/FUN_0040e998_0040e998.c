
void FUN_0040e998(int param_1,short param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_res8 [2];
  
  local_res8[0] = param_3;
  if (param_2 == 0) {
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"Received external IP address %.4a from NAT",local_res8);
    }
    iVar3 = mDNSv4AddrIsRFC1918(local_res8);
    if (iVar3 != 0) {
      LogMsgWithLevel(0,
                      "Double NAT (external NAT gateway address %.4a is also a private RFC 1918 address)"
                      ,local_res8);
    }
[32m    param_2 = 3;[0m
    if (local_res8[0] != 0) {
[32m      param_2 = 0;[0m
    }
  }
  else {
    if (DAT_0046e7b4 != param_2) {
      LogMsgWithLevel(0,"Error getting external address %d",param_2);
    }
    local_res8[0] = 0;
  }
  *(int *)(param_1 + 0x29c8) = local_res8[0];
  if (param_2 == 0) {
    iVar3 = mDNSPlatformOneSecond * 900;
  }
  else {
    if (DAT_0046e7b4 != 0) goto LAB_0040eabc;
    iVar3 = mDNSPlatformOneSecond;
    if (mDNSPlatformOneSecond < 0) {
      iVar3 = mDNSPlatformOneSecond + 3;
    }
    iVar3 = iVar3 >> 2;
  }
  *(int *)(param_1 + 0x29c0) = iVar3;
LAB_0040eabc:
  iVar3 = *(int *)(param_1 + 0x29c0) + *(int *)(param_1 + 0x234);
  *(int *)(param_1 + 0x29c4) = iVar3;
  if (0 < *(int *)(param_1 + 600) - iVar3) {
    *(int *)(param_1 + 600) = iVar3;
  }
  DAT_0046e7b4 = param_2;
  for (puVar2 = *(undefined4 **)(param_1 + 0x29b8); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    if (puVar2[9] != local_res8[0]) {
      if (*(char *)(puVar2 + 0xd) == '\0') {
        bVar1 = puVar2[5] != 3;
      }
      else {
        bVar1 = puVar2[5] - 1 < 2;
      }
      if (bVar1) {
        puVar2[1] = 0;
        puVar2[9] = local_res8[0];
        iVar3 = mDNSPlatformOneSecond;
        if (mDNSPlatformOneSecond < 0) {
          iVar3 = mDNSPlatformOneSecond + 3;
        }
        puVar2[2] = iVar3 >> 2;
        puVar2[3] = *(undefined4 *)(param_1 + 0x234);
        *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x234);
      }
    }
  }
  return;
}

[ASK_GPT] 8089f9814c45a42c
