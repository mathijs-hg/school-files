
size_t iw_in_key_full(undefined4 param_1,undefined4 param_2,char *param_3,char *param_4,
                     ushort *param_5)

{
  int iVar1;
  char *pcVar2;
  size_t local_260;
  undefined auStack_258 [240];
  byte local_168;
  byte local_140;
  
  iVar1 = strncmp(param_3,"l:",2);
  if (iVar1 == 0) {
[32m    local_260 = strlen(param_3 + 2);[0m
[32m    local_260 = local_260 + 1;[0m
    if (0x40 < (int)local_260) {
[32m      local_260 = 0x40;[0m
    }
[32m    memcpy(param_4,param_3 + 2,local_260);[0m
    pcVar2 = strchr(param_4,0x3a);
    if (pcVar2 == (char *)0x0) {
      fwrite("Error: Invalid login format\n",1,0x1c,stderr);
[32m      local_260 = 0xffffffff;[0m
    }
    else {
      *pcVar2 = '\0';
      iVar1 = iw_get_range_info(param_1,param_2,auStack_258);
      if (iVar1 < 0) {
[32m        memset(auStack_258,0,0x24c);[0m
      }
      if (0xf < local_140) {
        printf("flags = %X, index = %X\n",(uint)*param_5,(uint)local_168);
        if ((*param_5 & 0xff) == 0) {
          iVar1 = iw_get_range_info(param_1,param_2,auStack_258);
          if (iVar1 < 0) {
[32m            memset(auStack_258,0,0x24c);[0m
          }
          printf("flags = %X, index = %X\n",(uint)*param_5,(uint)local_168);
          *param_5 = *param_5 | (ushort)local_168;
        }
        printf("flags = %X, index = %X\n",(uint)*param_5,(uint)local_168);
      }
    }
  }
  else {
    local_260 = iw_in_key(param_3,param_4);
  }
  return local_260;
}

[ASK_GPT] 54639bae8db019d1
