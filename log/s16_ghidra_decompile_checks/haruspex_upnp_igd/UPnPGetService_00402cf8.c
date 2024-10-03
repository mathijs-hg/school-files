
char ** UPnPGetService(int param_1,char *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  char **ppcVar3;
  char *__s;
  
  ppcVar3 = *(char ***)(param_1 + 0x54);
  while( true ) {
    if (ppcVar3 == (char **)0x0) {
      return (char **)0x0;
    }
    printf("Service:%s\n",*ppcVar3);
    __s = *ppcVar3;
    sVar1 = strlen(__s);
[32m    if ((sVar1 == param_3) && (iVar2 = strncmp(__s,param_2,param_3), iVar2 == 0)) break;[0m
    ppcVar3 = (char **)ppcVar3[9];
  }
  return ppcVar3;
}

[ASK_GPT] 3a395ab64c86f385
