
[32msize_t iw_in_key(char *param_1,void *param_2)[0m

{
  int iVar1;
  undefined *puVar2;
  size_t local_60;
  char *local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  undefined auStack_48 [64];
  
  puVar2 = &_gp;
[32m  local_60 = 0;[0m
  iVar1 = strncmp(param_1,"s:",2);
  if (iVar1 == 0) {
[32m    local_60 = strlen(param_1 + 2);[0m
    if (0x40 < (int)local_60) {
[32m      local_60 = 0x40;[0m
    }
[32m    memcpy(param_2,param_1 + 2,local_60);[0m
  }
  else {
    iVar1 = strncmp(param_1,"p:",2);
    if (iVar1 == 0) {
[32m      local_60 = iw_pass_key(param_1 + 2,param_2);[0m
    }
    else {
      local_58 = 0xffffffff;
      for (local_5c = param_1; *local_5c != '\0'; local_5c = local_5c + local_54) {
        if ((int)local_58 < 1) {
          if (local_58 == 0) {
            local_5c = local_5c + 1;
          }
          local_58 = strcspn(local_5c,"-:;.,");
        }
[32m        local_54 = sscanf(local_5c,"%1X%1X",&local_50,&local_4c,puVar2);[0m
        if (local_54 < 1) {
          return 0xffffffff;
        }
        if ((local_58 & 1) != 0) {
          local_54 = 1;
        }
        if (local_54 == 2) {
          local_4c = local_50 << 4 | local_4c;
        }
        else {
          local_4c = local_50;
        }
        auStack_48[local_60] = (char)local_4c;
[32m        local_60 = local_60 + 1;[0m
        if (0x3f < (int)local_60) break;
        local_58 = local_58 - local_54;
      }
[32m      memcpy(param_2,auStack_48,local_60);[0m
    }
  }
  return local_60;
}

[ASK_GPT] 13fa69a27e51ee2e
