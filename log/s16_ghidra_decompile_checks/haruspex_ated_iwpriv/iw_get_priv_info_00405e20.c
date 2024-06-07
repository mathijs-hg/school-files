
uint iw_get_priv_info(int param_1,char *param_2,void **param_3)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  void *local_48;
  uint local_44;
  char acStack_2c [16];
  void *local_1c;
  ushort local_18;
  undefined2 local_16;
  
  local_48 = (void *)0x0;
  local_44 = 0x10;
  do {
[32m[32m    pvVar1 = realloc(local_48,local_44 * 0x18);[0m[0m
    if (pvVar1 == (void *)0x0) {
      fprintf(stderr,"%s: Allocation failed\n","iw_get_priv_info");
      break;
    }
    local_18 = (ushort)local_44;
    local_16 = 0;
    local_1c = pvVar1;
[32m[32m[32m    strncpy(acStack_2c,param_2,0x10);[0m[0m[0m
    iVar2 = ioctl(param_1,0x8b0d,acStack_2c);
    if (-1 < iVar2) {
      *param_3 = pvVar1;
      return (uint)local_18;
    }
    piVar3 = __errno_location();
    local_48 = pvVar1;
    if (*piVar3 != 7) break;
    if ((int)local_44 < (int)(uint)local_18) {
      local_44 = (uint)local_18;
    }
    else {
      local_44 = local_44 << 1;
    }
  } while ((int)local_44 < 1000);
  if (local_48 != (void *)0x0) {
    free(local_48);
  }
  *param_3 = (void *)0x0;
  return 0xffffffff;
}

[ASK_GPT] 27d84c8ff0ac8020
