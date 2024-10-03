
void FUN_0040be80(undefined4 param_1,int param_2)

{
  int iVar1;
  char *__dest;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  int param_7;
  int param_8;
  int param_9;
  
  if (param_7 != 0) {
    if ((param_2 != 0) && (*(int *)(param_2 + 0x10) == 200)) {
      for (ppcVar4 = *(char ***)(param_2 + 0x34); ppcVar4 != (char **)0x0;
          ppcVar4 = (char **)ppcVar4[5]) {
        if (ppcVar4[1] == (char *)0x3) {
          iVar1 = strncasecmp(*ppcVar4,"SID",3);
          if ((iVar1 == 0) && (*(int *)(param_8 + 0x14) == 0)) {
[32m[32m[32m            __dest = (char *)malloc((size_t)(ppcVar4[3] + 1));[0m[0m[0m
            *(char **)(param_8 + 0x14) = __dest;
[32m[32m            strcpy(__dest,ppcVar4[2]);[0m[0m
            ILibAddEntry(*(undefined4 *)(param_9 + 0x48),ppcVar4[2],ppcVar4[3],param_8);
          }
        }
        else if ((ppcVar4[1] == (char *)0x7) &&
                (iVar1 = strncasecmp(*ppcVar4,"TIMEOUT",7), iVar1 == 0)) {
          iVar2 = ILibParseString(ppcVar4[2],0,ppcVar4[3],&DAT_004169a8,1);
          *(undefined *)(**(int **)(iVar2 + 4) + (*(int **)(iVar2 + 4))[1]) = 0;
          FUN_00405000(*(undefined4 *)(param_8 + 0x20));
          iVar1 = *(int *)(param_8 + 0x20);
          do {
            iVar3 = iVar1;
            iVar1 = *(int *)(iVar3 + 0x4c);
          } while (*(int *)(iVar3 + 0x4c) != 0);
          *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x3c) + 1;
          iVar1 = atoi(**(char ***)(iVar2 + 4));
          ILibLifeTime_AddEx(*(undefined4 *)(param_9 + 0x28),param_8,(iVar1 / 2) * 1000,FUN_00401e50
                             ,0);
          ILibDestructParserResults(iVar2);
        }
      }
    }
    FUN_0040917c(*(undefined4 *)(param_8 + 0x20));
    return;
  }
  return;
}

[ASK_GPT] ed688b84fb0fea5e
