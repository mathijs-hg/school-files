
undefined4 FUN_00401c38(char *param_1,undefined4 param_2,char *param_3,char *param_4)

{
  undefined4 uVar1;
  size_t sVar2;
  char *__s;
  int iVar3;
  size_t sVar4;
  
  uVar1 = ILibCreateEmptyPacket();
  sVar2 = strlen(param_1);
[32m[32m[32m  __s = (char *)malloc(sVar2 + 7);[0m[0m[0m
[32m[32m  iVar3 = sprintf(__s,"%s:%d",param_1,param_2);[0m[0m
  sVar2 = strlen(param_4);
  sVar4 = strlen(param_3);
  ILibSetDirective(uVar1,param_4,sVar2,param_3,sVar4);
  ILibAddHeaderLine(uVar1,&DAT_00415988,4,__s,iVar3);
  ILibAddHeaderLine(uVar1,"User-Agent",10,"POSIX, UPnP/1.0, xxxxxxxxxxxxxxxxxxxxxxxxx",0x2a);
  free(__s);
  return uVar1;
}

[ASK_GPT] 351500273bce1261
