
void FUN_0042f54c(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined local_a8 [128];
  
  local_a8[0] = 0;
  if (*(char *)(param_1 + 0x279) != '\0') {
    if (*(int *)(param_1 + 0x38e0) != 0) {
[32m      mDNS_snprintf(local_a8,0x80,"sleep proxy for %d records");[0m
      if (mDNS_LoggingEnabled == 0) {
LAB_0042f8b8:
        uVar4 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 0x38e0);
        pcVar3 = "mDNS_UpdateAllowSleep: Sleep disabled because we are proxying %d records";
LAB_0042f87c:
        LogMsgWithLevel(3,pcVar3,iVar5);
        uVar4 = 0;
      }
      goto LAB_0042f8bc;
    }
    iVar5 = FUN_0042a73c();
    uVar4 = 1;
    if (iVar5 == 0) goto LAB_0042f8bc;
    for (puVar1 = (undefined4 *)GetFirstActiveInterface(*(undefined4 *)(param_1 + 0x2174),1);
        puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)GetFirstActiveInterface(*puVar1)) {
      if (((*(char *)((int)puVar1 + 0x1593) != '\0') && (*(char *)((int)puVar1 + 0x1595) == '\0'))
         && (iVar5 = mDNSPlatformInterfaceIsD2D(puVar1[0x548]), iVar5 == 0)) {
        if (*(char *)(puVar1 + 0x565) == '\0') {
          iVar5 = (int)puVar1 + 0x1552;
[32m          mDNS_snprintf(local_a8,0x80,"%s does not support NetWake",iVar5);[0m
          if (mDNS_LoggingEnabled == 0) goto LAB_0042f8b8;
          pcVar3 = "mDNS_UpdateAllowSleep: Sleep disabled because %s does not support NetWake";
          goto LAB_0042f87c;
        }
        iVar5 = FUN_0042d894(param_1,puVar1 + 2,0,0);
        if (iVar5 == 0) {
          iVar5 = (int)puVar1 + 0x1552;
[32m          mDNS_snprintf(local_a8,0x80,"No sleep proxy server on %s",iVar5);[0m
          if (mDNS_LoggingEnabled == 0) goto LAB_0042f8b8;
          pcVar3 = "mDNS_UpdateAllowSleep: Sleep disabled because %s has no sleep proxy server";
          goto LAB_0042f87c;
        }
        if (*(byte *)(param_1 + 0x2a9c) == 0) goto LAB_0042f890;
        iVar5 = *(int *)(iVar5 + 0x24);
        if (((*(byte *)(iVar5 + 4) < 5) || (9 < (*(byte *)(iVar5 + 5) - 0x30 & 0xff))) ||
           ((9 < (*(byte *)(iVar5 + 6) - 0x30 & 0xff) || (9 < (*(byte *)(iVar5 + 8) - 0x30 & 0xff)))
           )) {
LAB_0042f814:
          uVar2 = 1000000;
        }
        else {
          if ((9 < (*(byte *)(iVar5 + 9) - 0x30 & 0xff)) ||
             (((10 < *(byte *)(iVar5 + 4) && (*(char *)(iVar5 + 7) == '-')) &&
              ((*(int *)(iVar5 + 8) == 0x39392d39 && (*(int *)(iVar5 + 0xc) == 0x392d3939))))))
          goto LAB_0042f814;
          uVar2 = (*(byte *)(iVar5 + 0xc) - 0x516150) + (uint)*(byte *)(iVar5 + 5) * 100000 +
                  (uint)*(byte *)(iVar5 + 6) * 10000 + (uint)*(byte *)(iVar5 + 8) * 1000 +
                  (uint)*(byte *)(iVar5 + 9) * 100 + (uint)*(byte *)(iVar5 + 0xb) * 10;
        }
        if ((uint)*(byte *)(param_1 + 0x2a9c) * 10000 + (uint)*(byte *)(param_1 + 0x2a9d) * 100 +
            (uint)*(byte *)(param_1 + 0x2a9e) <= uVar2) {
          iVar5 = (int)puVar1 + 0x1552;
[32m          mDNS_snprintf(local_a8,0x80,"No sleep proxy server with better metric on %s",iVar5);[0m
          if (mDNS_LoggingEnabled == 0) goto LAB_0042f8b8;
          pcVar3 = 
          "mDNS_UpdateAllowSleep: Sleep disabled because %s has no sleep proxy server with a better metric"
          ;
          goto LAB_0042f87c;
        }
      }
LAB_0042f890:
    }
  }
  uVar4 = 1;
LAB_0042f8bc:
  mDNSPlatformSetAllowSleep(param_1,uVar4,local_a8);
  return;
}

[ASK_GPT] 4ac5f9225b236797
