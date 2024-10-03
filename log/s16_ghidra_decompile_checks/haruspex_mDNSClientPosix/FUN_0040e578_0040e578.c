
void FUN_0040e578(int param_1,int param_2,undefined2 *param_3)

{
  short sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 *local_18;
  
  if (*(int *)(param_2 + 0x10c) == 0) {
    if ((*(int *)(param_2 + 0x38) == 0) || (*(char *)(*(int *)(param_2 + 0x38) + 8) == '\0')) {
[32m      sVar1 = *(short *)(param_2 + 0x120);[0m
      *(short *)(param_2 + 0x120) = sVar1 + 1;
      if (sVar1 == 3) {
        LogMsgWithLevel(0,"sendChallengeResponse: %d failed attempts for LLQ %##s",3,param_2 + 0x154
                       );
LAB_0040e790:
        FUN_0040e534(param_1,param_2);
        return;
      }
      if (param_3 == (undefined2 *)0x0) {
        local_28 = *(undefined4 *)(param_2 + 0x124);
        local_24 = *(undefined4 *)(param_2 + 0x128);
        param_3 = &local_30;
        local_20 = *(undefined4 *)(param_2 + 0x118);
        local_2e = 1;
        local_30 = 1;
        local_2c = 0;
      }
      iVar2 = 0;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x234);
      if (*(int *)(param_2 + 0x10c) == 0) {
        iVar2 = mDNSPlatformOneSecond * 2 * (int)*(short *)(param_2 + 0x120);
      }
      iVar5 = param_1 + 0x5cb0;
      *(int *)(param_2 + 0x10) = iVar2;
      local_18 = param_3;
      SetNextQueryTime(param_1,param_2);
      InitializeDNSMessage(iVar5,(uint)*(ushort *)(param_2 + 0x152) << 0x10,0x1000000);
      iVar2 = FUN_0040e3f4(iVar5,param_1 + 0x5cbc,param_2,local_18);
      if (iVar2 == 0) goto LAB_0040e790;
      iVar2 = mDNSSendDNSMessage(param_1,iVar5,iVar2,0,*(undefined4 *)(param_2 + 0xd8),
                                 param_2 + 0xf4);
      if (iVar2 == 0) {
        return;
      }
      if (*(int *)(param_2 + 0x10c) == 0) {
        pcVar4 = "";
      }
      else {
        pcVar4 = " (TCP)";
      }
      pcVar3 = "sendChallengeResponse: mDNSSendDNSMessage%s failed: %d";
      goto LAB_0040e77c;
    }
    iVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
    pcVar3 = "sendChallengeResponse: ERROR!!: Private Query %##s (%s)";
  }
  else {
    iVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
    pcVar3 = "sendChallengeResponse: ERROR!!: question %##s (%s) tcp non-NULL";
  }
  pcVar4 = (char *)(param_2 + 0x154);
LAB_0040e77c:
  LogMsgWithLevel(0,pcVar3,pcVar4,iVar2);
  return;
}

[ASK_GPT] b55252d7222ddf07
