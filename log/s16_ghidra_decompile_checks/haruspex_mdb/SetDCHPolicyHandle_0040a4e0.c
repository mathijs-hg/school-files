
void SetDCHPolicyHandle(char *param_1)

{
  FILE *pFVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *__s;
  
[32m  unlink("/tmp/.hnap_set_policy.xml");[0m
[32m  pFVar1 = fopen("/tmp/.hnap_set_policy.xml","wb");[0m
  sVar2 = strlen(param_1);
  fwrite(param_1,1,sVar2,pFVar1);
  fclose(pFVar1);
  iVar3 = ixmlLoadDocument("/tmp/.hnap_set_policy.xml");
  if (iVar3 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_00409d5c(iVar3,"SetDCHPolicy");
    __s = (char *)0x0;
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      uVar4 = ixmlNode_getFirstChild(iVar5);
      iVar5 = ixmlNode_cloneNode(uVar4,1);
      if (iVar5 == 0) {
        __s = (char *)0x0;
      }
      else {
        __s = (char *)ixmlNodetoString(iVar5);
        if (__s != (char *)0x0) {
[32m          unlink("/mnt/flash/config/hnap_policy.xml");[0m
[32m          pFVar1 = fopen("/mnt/flash/config/hnap_policy.xml","wb");[0m
          sVar2 = strlen(__s);
          fwrite(__s,1,sVar2,pFVar1);
          fclose(pFVar1);
        }
      }
    }
    ixmlDocument_free(iVar3);
    if (__s != (char *)0x0) {
      ixmlFreeDOMString(__s);
    }
  }
  if (iVar5 != 0) {
    ixmlNode_free(iVar5);
  }
[32m  unlink("/tmp/.hnap_set_policy.xml");[0m
  return;
}

[ASK_GPT] 7e6ada3a412d04f9
