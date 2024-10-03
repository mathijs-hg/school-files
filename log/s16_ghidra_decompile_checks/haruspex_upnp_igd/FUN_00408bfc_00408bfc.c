
void FUN_00408bfc(int param_1)

{
  size_t __n;
  int iVar1;
  char **ppcVar2;
  char **ppcVar3;
  
  for (iVar1 = *(int *)(param_1 + 0x50); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x58)) {
    FUN_00408bfc(iVar1);
  }
  iVar1 = strncmp(*(char **)(param_1 + 4),"urn:schemas-upnp-org:device:WANConnectionDevice:1",0x31);
  if (iVar1 == 0) {
    ppcVar3 = *(char ***)(param_1 + 0x54);
    while (ppcVar2 = ppcVar3, ppcVar2 != (char **)0x0) {
      __n = strlen(WAN_Service);
[32m      iVar1 = strncmp(*ppcVar2,WAN_Service,__n);[0m
      ppcVar3 = (char **)ppcVar2[9];
      if (iVar1 != 0) {
        FUN_00408bac(param_1,ppcVar2);
      }
    }
  }
  return;
}

[ASK_GPT] a88d4e28da106c80
