
int FUN_00402248(int param_1,char *param_2,int param_3)

{
  size_t sVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__s;
  
  iVar4 = 0;
  iVar3 = *(int *)(param_1 + 0x50);
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    __s = *(char **)(iVar3 + 4);
    sVar1 = strlen(__s);
    __n = strlen(param_2);
[32m    if (((__n <= sVar1) && (iVar2 = memcmp(__s,param_2,__n), iVar2 == 0)) &&[0m
       (iVar4 = iVar4 + 1, param_3 == iVar4)) break;
    iVar3 = *(int *)(iVar3 + 0x58);
  }
  return iVar3;
}

[ASK_GPT] e971bc6d540ff3ae
