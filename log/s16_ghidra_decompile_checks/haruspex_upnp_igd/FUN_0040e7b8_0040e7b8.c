
char * FUN_0040e7b8(int param_1)

{
  char *__s;
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = &_gp;
[32m[32m[32m  __s = (char *)malloc(0x10);[0m[0m[0m
  uVar1 = *(uint *)(param_1 + 0x810);
  sprintf(__s,"%d.%d.%d.%d",uVar1 & 0xff,(int)uVar1 >> 8 & 0xff,(int)uVar1 >> 0x10 & 0xff,
[32m          uVar1 >> 0x18,puVar2);[0m
  return __s;
}

[ASK_GPT] 38c99f6d5f84e234
