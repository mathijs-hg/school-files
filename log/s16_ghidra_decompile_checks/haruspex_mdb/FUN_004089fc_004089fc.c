
char * FUN_004089fc(char *param_1,code *param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return param_1;
    }
    iVar2 = (*param_2)();
    if (iVar2 == 0) break;
[32m    cVar1 = param_1[1];[0m
    param_1 = param_1 + 1;
  }
  return param_1;
}

[ASK_GPT] fe353e9ff2ad6e73
