
void FUN_0042494c(undefined4 param_1,char *param_2,undefined *param_3,char *param_4,
                 undefined *param_5)

{
  FILE *__stream;
  int iVar1;
  int *piVar2;
  void *pvVar3;
  char local_418;
  undefined auStack_417 [1019];
  
  local_418 = '\0';
[32m  memset(auStack_417,0,0x3f0);[0m
[32m  __stream = fopen(param_2,"r");[0m
  if (param_3 != (undefined *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (char *)0x0) {
    *param_4 = '\0';
  }
  if (param_5 != (undefined *)0x0) {
    *param_5 = 0;
  }
  if (__stream == (FILE *)0x0) {
    piVar2 = __errno_location();
    if (*piVar2 == 2) {
      return;
    }
    LogMsgWithLevel(0,"ERROR: Config file exists, but cannot be opened.");
    return;
  }
  if (((param_5 != (undefined *)0x0) &&
      (iVar1 = FUN_004247f0(&local_418,"DomainDiscoveryDisabled",__stream), iVar1 != 0)) &&
     (iVar1 = strcasecmp(&local_418,"true"), iVar1 == 0)) {
    *param_5 = 1;
  }
  if (param_3 != (undefined *)0x0) {
    iVar1 = FUN_004247f0(&local_418,"hostname",__stream);
    if ((iVar1 != 0) && (iVar1 = MakeDomainNameFromDNSNameString(param_3,&local_418), iVar1 == 0))
    goto LAB_00424bac;
  }
  if ((param_4 == (char *)0x0) ||
     ((iVar1 = FUN_004247f0(&local_418,&DAT_00454430,__stream), iVar1 == 0 ||
      (iVar1 = MakeDomainNameFromDNSNameString(param_4,&local_418), iVar1 != 0)))) {
    local_418 = '\0';
    FUN_004247f0(&local_418,"secret-64",__stream);
    fclose(__stream);
    if (param_4 == (char *)0x0) {
      return;
    }
    if (*param_4 == '\0') {
      return;
    }
    if (local_418 == '\0') {
      return;
    }
    pvVar3 = mDNSPlatformMemAllocate(0x1558);
    iVar1 = mDNS_SetSecretForDomain(param_1,pvVar3,param_4,param_4,&local_418,0,0,0);
    if (iVar1 == 0) {
      return;
    }
    LogMsgWithLevel(0,"ERROR: mDNS_SetSecretForDomain returned %d for domain %##s",iVar1,param_4);
    return;
  }
LAB_00424bac:
  LogMsgWithLevel(0,"ERROR: malformatted config file");
  fclose(__stream);
  return;
}

[ASK_GPT] 84ac7e2588fb3270
