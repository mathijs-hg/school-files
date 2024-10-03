
undefined4
mDNS_SetSecretForDomain
          (int param_1,undefined4 *param_2,void *param_3,void *param_4,char *param_5,void *param_6,
          undefined2 *param_7,char param_8)

{
  char *pcVar1;
  uint uVar2;
  undefined2 uVar4;
  int iVar3;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if ((param_2 == (undefined4 *)0x0) || (param_5 == (char *)0x0)) {
    LogMsgWithLevel(0,"mDNS_SetSecretForDomain: ERROR: info %p b64keydata %p",param_2,param_5);
  }
  else {
    if (mDNS_LoggingEnabled != 0) {
      if (param_8 == '\0') {
        pcVar1 = "";
      }
      else {
        pcVar1 = " AutoTunnel";
      }
      LogMsgWithLevel(3,"mDNS_SetSecretForDomain: domain %##s key %##s%s",param_3,param_4,pcVar1);
    }
    *(char *)(param_2 + 2) = param_8;
    uVar2 = DomainNameLengthLimit(param_3,(int)param_3 + 0x100);
    if (uVar2 < 0x101) {
      mDNSPlatformMemCopy(param_2 + 0x46d,param_3,uVar2);
    }
    else {
      *(undefined *)(param_2 + 0x46d) = 0;
    }
    uVar2 = DomainNameLengthLimit(param_4,(int)param_4 + 0x100);
    if (uVar2 < 0x101) {
      mDNSPlatformMemCopy(param_2 + 0x4ad,param_4,uVar2);
    }
    else {
      *(undefined *)(param_2 + 0x4ad) = 0;
    }
    if ((param_6 == (void *)0x0) ||
       (uVar2 = DomainNameLengthLimit(param_6,(int)param_6 + 0x100), 0x100 < uVar2)) {
      *(undefined *)(param_2 + 0x4ed) = 0;
    }
    else {
      mDNSPlatformMemCopy(param_2 + 0x4ed,param_6,uVar2);
    }
    if (param_7 == (undefined2 *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *param_7;
    }
    *(undefined2 *)(param_2 + 0x52d) = uVar4;
[32m    mDNS_snprintf((int)param_2 + 0x14b6,0x20,"%s",param_5);[0m
    iVar3 = DNSDigest_ConstructHMACKeyfromBase64(param_2,param_5);
    if (-1 < iVar3) {
      param_2[1] = 0;
      puVar6 = *(undefined4 **)(param_1 + 0x21d4);
      puVar7 = (undefined4 *)(param_1 + 0x21d4);
      while( true ) {
        puVar5 = puVar6;
        if (puVar5 == (undefined4 *)0x0) {
          *(undefined *)(param_2 + 4) = 0;
          *(undefined *)(param_2 + 0x61) = 0;
          *(undefined *)(param_2 + 0xe5) = 0;
          *(undefined *)(param_2 + 0x1c6) = 0;
          *(undefined *)(param_2 + 0x2a7) = 0;
          *(undefined *)(param_2 + 0x388) = 0;
          *(undefined *)(param_2 + 0x468) = 0;
[32m[32m          memcpy(param_2 + 0x469,zerov6Addr,0x10);[0m[0m
          *param_2 = 0;
          *puVar7 = param_2;
          for (puVar6 = *(undefined4 **)(param_1 + 0x2ac); puVar6 != (undefined4 *)0x0;
              puVar6 = (undefined4 *)*puVar6) {
            iVar3 = GetAuthInfoForQuestion(param_1,puVar6);
            if (puVar6[0xe] != iVar3) {
              puVar6[0xe] = iVar3;
            }
          }
          return 0;
        }
        if (puVar5 == param_2) break;
        puVar6 = (undefined4 *)*puVar5;
        puVar7 = puVar5;
      }
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(3,"mDNS_SetSecretForDomain: Domain %##s Already in list",puVar5 + 0x46d);
      }
      return 0xfffefff5;
    }
    if (mDNS_LoggingEnabled == 0) {
      param_5 = "";
    }
    LogMsgWithLevel(0,
                    "mDNS_SetSecretForDomain: ERROR: Could not convert shared secret from base64: domain %##s key %##s %s"
                    ,param_3,param_4,param_5);
  }
  return 0xfffefffc;
}

[ASK_GPT] 9a9c298c96b8cd4f
