
void * FUN_00411fdc(int param_1,char *param_2,size_t param_3)

{
  int iVar1;
  void *__dest;
  char *pcVar2;
  char *pcVar3;
  char **ppcVar4;
  
  ppcVar4 = *(char ***)(param_1 + 0x34);
  while( true ) {
    if (ppcVar4 == (char **)0x0) {
      return (void *)0x0;
    }
[32m    iVar1 = strncasecmp(param_2,*ppcVar4,param_3);[0m
    if (iVar1 == 0) break;
    ppcVar4 = (char **)ppcVar4[5];
  }
[32m[32m[32m  __dest = malloc((size_t)(ppcVar4[3] + 1));[0m[0m[0m
  pcVar3 = ppcVar4[3];
  for (pcVar2 = (char *)0x0; ((int)pcVar2 < (int)pcVar3 && (ppcVar4[2][(int)pcVar2] == ' '));
      pcVar2 = pcVar2 + 1) {
  }
  if (pcVar2 == pcVar3 + -1) {
    pcVar2 = (char *)0x0;
  }
[32m[32m[32m  memcpy(__dest,ppcVar4[2] + (int)pcVar2,(int)pcVar3 - (int)pcVar2);[0m[0m[0m
  *(undefined *)((int)__dest + ((int)ppcVar4[3] - (int)pcVar2)) = 0;
  return __dest;
}

[ASK_GPT] 8d91ea1b82b433c6
