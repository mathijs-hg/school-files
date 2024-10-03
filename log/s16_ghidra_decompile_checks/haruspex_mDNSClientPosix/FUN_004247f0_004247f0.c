
undefined4 FUN_004247f0(char *param_1,char *param_2,FILE *param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char acStack_430 [1048];
  
  sVar1 = strlen(param_2);
  if (sVar1 + 0x3f2 < 0x412) {
    fseek(param_3,0,0);
    do {
[32m      pcVar4 = fgets(acStack_430,0x412,param_3);[0m
      if (pcVar4 == (char *)0x0) {
        return 0;
      }
[32m      iVar3 = strncmp(acStack_430,param_2,sVar1);[0m
    } while (iVar3 != 0);
[32m[32m    strncpy(param_1,acStack_430 + sVar1 + 1,0x3f0);[0m[0m
    if (param_1[0x3f0] != '\0') {
      param_1[0x3f0] = '\0';
    }
    sVar1 = strlen(param_1);
    if (sVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 1;
      if (param_1[sVar1 - 1] == '\n') {
        param_1[sVar1 - 1] = '\0';
      }
    }
  }
  else {
    LogMsgWithLevel(0,"GetConfigOption: option %s too long",param_2);
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] b2cc13a4e448b7de
