
void FUN_0041213c(undefined4 param_1,int param_2,short param_3)

{
  int iVar1;
  uint __n;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_3 != 0x21) goto LAB_004122e8;
  iVar1 = *(int *)(param_2 + 0x100);
  if (iVar1 == 0) {
    if (*(char *)(param_2 + 800) == '\0') {
      pcVar3 = "\v_dns-update\x04_udp";
    }
    else {
      pcVar3 = "\x0f_dns-update-tls\x04_tcp";
    }
  }
  else if (iVar1 == 1) {
    if (*(char *)(param_2 + 800) == '\0') {
      pcVar3 = "";
    }
    else {
      pcVar3 = "\x0e_dns-query-tls\x04_tcp";
    }
  }
  else if (iVar1 == 2) {
    if (*(char *)(param_2 + 800) == '\0') {
      pcVar3 = "\b_dns-llq\x04_udp";
    }
    else {
      pcVar3 = "\f_dns-llq-tls\x04_tcp";
    }
  }
  else {
    pcVar3 = "";
  }
  __n = DomainNameLengthLimit(pcVar3,pcVar3 + 0x100);
  if (__n < 0x101) {
    iVar1 = *(int *)(param_2 + 0x100);
    if (iVar1 == 0) {
      if (*(char *)(param_2 + 800) == '\0') {
        pcVar3 = "\v_dns-update\x04_udp";
      }
      else {
        pcVar3 = "\x0f_dns-update-tls\x04_tcp";
      }
    }
    else if (iVar1 == 1) {
      if (*(char *)(param_2 + 800) == '\0') {
LAB_004122b0:
        pcVar3 = "";
      }
      else {
        pcVar3 = "\x0e_dns-query-tls\x04_tcp";
      }
    }
    else {
      if (iVar1 != 2) goto LAB_004122b0;
      if (*(char *)(param_2 + 800) == '\0') {
        pcVar3 = "\b_dns-llq\x04_udp";
      }
      else {
        pcVar3 = "\f_dns-llq-tls\x04_tcp";
      }
    }
    mDNSPlatformMemCopy((void *)(param_2 + 0x480),pcVar3,__n);
  }
  else {
    *(undefined *)(param_2 + 0x480) = 0;
  }
  AppendDomainName(param_2 + 0x480,param_2 + 0x108);
LAB_004122e8:
  *(undefined4 *)(param_2 + 0x33c) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x460) = 0;
  *(undefined4 *)(param_2 + 0x464) = 0;
[32m[32m  memcpy((void *)(param_2 + 0x468),zeroAddr,0x14);[0m[0m
  *(short *)(param_2 + 0x580) = param_3;
  *(undefined *)(param_2 + 0x587) = 1;
  *(undefined2 *)(param_2 + 0x582) = 1;
  *(undefined *)(param_2 + 0x584) = 0;
  *(undefined *)(param_2 + 0x585) = 1;
  *(undefined *)(param_2 + 0x586) = 0;
  *(undefined *)(param_2 + 0x588) = 0;
  *(undefined *)(param_2 + 0x589) = 0;
  *(undefined *)(param_2 + 0x58a) = 0;
  *(undefined *)(param_2 + 0x58f) = 0;
  *(undefined *)(param_2 + 0x590) = 0;
  *(undefined *)(param_2 + 0x58b) = 0;
  *(undefined *)(param_2 + 0x58c) = 0;
  *(undefined *)(param_2 + 0x58d) = 0;
  *(undefined *)(param_2 + 0x58e) = 0;
  *(undefined *)(param_2 + 0x592) = 0;
  *(undefined *)(param_2 + 0x3f8) = 0;
  *(undefined *)(param_2 + 0x593) = 0;
  *(undefined4 *)(param_2 + 0x5b0) = 0;
  *(undefined4 *)(param_2 + 0x370) = 0;
  uVar2 = mDNSPlatformGetPID();
  *(undefined4 *)(param_2 + 0x598) = uVar2;
  *(code **)(param_2 + 0x5b4) = FUN_004123b4;
  *(undefined4 *)(param_2 + 0x5ac) = 0;
  *(int *)(param_2 + 0x5b8) = param_2;
                    /* WARNING: Treating indirect jump as call */
  mDNS_StartQuery(param_1,param_2 + 0x32c);
  return;
}

[ASK_GPT] a01fcc22fce02104
