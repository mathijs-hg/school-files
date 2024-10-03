
bool mDNSPlatformMemSame(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
[32m  iVar1 = memcmp(param_1,param_2,param_3);[0m
  return iVar1 == 0;
}

[ASK_GPT] 6138e0a4a94cdb36
