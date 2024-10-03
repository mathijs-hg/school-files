
char * FUN_00408eac(char *param_1,char *param_2)

{
  char *pcVar1;
  
[32m[32m  pcVar1 = strcpy(param_2,param_1);[0m[0m
  pcVar1 = (char *)FUN_00408b5c(pcVar1,0x2f);
  if (*pcVar1 == '\0') {
    *param_2 = '\0';
  }
  else {
    *pcVar1 = '\0';
  }
  return param_2;
}

[ASK_GPT] c6aefb3dbecb6baf
