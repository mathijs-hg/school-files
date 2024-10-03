
void FUN_0040b388(int param_1,int param_2,undefined4 param_3,uint param_4,int param_5,
                 undefined4 param_6,uint param_7,undefined4 param_8)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined *puVar4;
  char *pcVar5;
  int iVar6;
  
[32m  cVar1 = *(char *)(param_2 + 0x34);[0m
  param_4 = param_4 & 0xffff;
  if (cVar1 == '\0') {
    puVar4 = &DAT_0044d190;
  }
  else if (cVar1 == '\x01') {
    puVar4 = &DAT_0044d194;
  }
  else if (cVar1 == '\x02') {
    puVar4 = &DAT_0044d19c;
  }
  else {
    puVar4 = &UNK_0044d198;
  }
  *(uint *)(param_2 + 0x10) = param_4;
  if (((param_4 == 0) && (param_7 != 0)) && (param_6._0_2_ != 0)) {
    if (mDNSPlatformOneSecond == 0) {
      trap(0x1c00);
    }
    uVar3 = param_7;
    if (999999999 / mDNSPlatformOneSecond < param_7) {
      uVar3 = 999999999 / mDNSPlatformOneSecond;
    }
    iVar6 = uVar3 * mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    *(int *)(param_2 + 4) = iVar6;
    if (((*(int *)(param_2 + 0x24) != param_5) || (*(short *)(param_2 + 0x38) != param_6._0_2_)) &&
       (mDNS_LoggingEnabled != 0)) {
      iVar6 = *(int *)(param_2 + 0x14);
      if (iVar6 == 0) {
        pcVar5 = "None    ";
      }
      else if (iVar6 == 1) {
        pcVar5 = "NAT-PMP ";
      }
      else if (iVar6 == 2) {
        pcVar5 = "UPnP/IGD";
      }
      else if (iVar6 == 3) {
        pcVar5 = "PCP     ";
      }
      else {
        pcVar5 = "Unknown ";
      }
      LogMsgWithLevel(3,
                      "natTraversalHandlePortMapReplyWithAddress: %p %s Response %s Port %5d External %.4a:%d changed to %.4a:%d lease %d"
                      ,param_2,pcVar5,puVar4,*(undefined2 *)(param_2 + 0x36),param_2 + 0x24,
                      *(undefined2 *)(param_2 + 0x38),&param_5,param_6._0_2_,uVar3);
    }
    *(undefined4 *)(param_2 + 0x1c) = param_3;
    *(int *)(param_2 + 0x24) = param_5;
    if (*(char *)(param_2 + 0x34) != '\0') {
      *(short *)(param_2 + 0x38) = param_6._0_2_;
    }
    *(undefined4 *)(param_2 + 0x14) = param_8;
    iVar6 = (*(int *)(param_2 + 4) - *(int *)(param_1 + 0x234)) / 2;
    *(int *)(param_2 + 8) = iVar6;
    if (iVar6 < (int)(mDNSPlatformOneSecond << 1)) {
      *(uint *)(param_2 + 8) = mDNSPlatformOneSecond << 1;
    }
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 8) + *(int *)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x234);
  }
  else {
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,
                      "natTraversalHandlePortMapReplyWithAddress: %p Response %s Port %5d External %.4a:%d lease %d error %d"
                      ,param_2,puVar4,*(undefined2 *)(param_2 + 0x36),&param_5,param_6._0_2_,param_7
                      ,param_4);
    }
    *(uint *)(param_2 + 8) = mDNSPlatformOneSecond * 900;
    *(uint *)(param_2 + 0xc) = mDNSPlatformOneSecond * 900 + *(int *)(param_1 + 0x234);
    if (param_4 == 2) {
      uVar2 = 0xfffeffe3;
    }
    else {
      if (4 < (param_4 - 1 & 0xffff)) {
        return;
      }
      uVar2 = 0xfffeffe4;
    }
    *(undefined4 *)(param_2 + 0x10) = uVar2;
  }
  return;
}

[ASK_GPT] f8329e5ff32c590e
