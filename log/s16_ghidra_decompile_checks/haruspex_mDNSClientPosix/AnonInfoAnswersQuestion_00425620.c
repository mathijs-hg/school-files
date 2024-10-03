
undefined4 AnonInfoAnswersQuestion(int param_1,int param_2)

{
  void **ppvVar1;
  int iVar2;
  undefined4 uVar3;
  void **ppvVar4;
  void *__s1;
  void *__s2;
  char *pcVar5;
  void *__n;
  char *pcVar6;
  void *pvVar7;
  int local_a1e0;
  int local_a1dc;
  int local_a1d8;
  char local_a1d4 [203];
  undefined auStack_a109 [41201];
  undefined4 local_18;
  
  if (*(short *)(param_2 + 0x254) != 0xc) {
    return 0xffffffff;
  }
  ppvVar4 = *(void ***)(param_2 + 0x44);
  if (ppvVar4 == (void **)0x0) {
    return 0xffffffff;
  }
  ppvVar1 = *(void ***)(param_1 + 0x28);
  if (ppvVar1 == (void **)0x0) {
    return 0xffffffff;
  }
  __s1 = *ppvVar4;
  __s2 = *ppvVar1;
  if (__s1 == (void *)0x0) {
    __n = ppvVar1[1];
    pvVar7 = ppvVar4[3];
    if (__s2 == (void *)0x0) {
      return 0;
    }
  }
  else {
    __n = ppvVar4[1];
    if (__s2 != (void *)0x0) {
      if (__n != ppvVar1[1]) {
        return 0;
      }
[32m      iVar2 = mDNSPlatformMemCmp(__s1,__s2,(size_t)__n);[0m
      if (iVar2 == 0) {
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,
                          "AnonInfoAnswersQuestion: Answering qname %##s, rname %##s, without validation"
                          ,param_2 + 0x154,*(undefined4 *)(param_1 + 0x1c));
          return 1;
        }
        return 1;
      }
      return 0;
    }
    pvVar7 = ppvVar1[3];
    __s2 = __s1;
  }
  if (pvVar7 == (void *)0x0) {
    return 0;
  }
  iVar2 = NSEC3HashName(*(undefined4 *)((int)pvVar7 + 0x1c),*(int *)((int)pvVar7 + 0x20) + 4,__s2,
                        __n,local_a1d4,&local_a1e0);
  if (iVar2 == 0) {
    local_a1e0 = *(int *)((int)pvVar7 + 0x1c);
    pcVar5 = "AnonInfoAnswersQuestion: NSEC3HashName failed for ##s";
  }
  else {
    if (local_a1e0 == 0x14) {
      NSEC3Parse(pvVar7,0,&local_a1dc,&local_a1d8,0,0);
      if (local_a1e0 != local_a1dc) {
        LogMsgWithLevel(0,"AnonInfoAnswersQuestion: ERROR!! hlen %d not same as nxtLength %d");
        return 0;
      }
      iVar2 = 0;
      do {
        pcVar6 = (char *)(local_a1d8 + iVar2);
        pcVar5 = local_a1d4 + iVar2;
        if (local_a1e0 <= iVar2) {
          if (mDNS_LoggingEnabled != 0) {
            local_18 = GetRRDisplayString_rdb(pvVar7,*(int *)((int)pvVar7 + 0x20) + 4,auStack_a109);
            uVar3 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
            LogMsgWithLevel(3,
                            "AnonInfoAnswersQuestion: ResourceRecord %s matched question %##s (%s)",
                            local_18,param_2 + 0x154,uVar3);
            return 1;
          }
          return 1;
        }
        iVar2 = iVar2 + 1;
      } while (*pcVar6 == *pcVar5);
      return 0;
    }
    pcVar5 = "AnonInfoAnswersQuestion: hlen wrong %d";
  }
  LogMsgWithLevel(0,pcVar5,local_a1e0);
  return 0;
}

[ASK_GPT] 2945b4af58aeb5af
