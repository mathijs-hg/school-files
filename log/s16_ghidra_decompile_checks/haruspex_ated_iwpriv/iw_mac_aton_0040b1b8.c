
int iw_mac_aton(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  char *local_20;
  int local_1c;
  int local_14;
  uint local_10 [2];
  
  puVar3 = &_gp;
  local_1c = 0;
  local_20 = param_1;
  while ((*local_20 != '\0' &&
[32m         (iVar1 = sscanf(local_20,"%1X%1X",&local_14,local_10,puVar3), iVar1 == 2))) {[0m
    local_10[0] = local_14 << 4 | local_10[0];
    *(char *)(param_2 + local_1c) = (char)local_10[0];
    local_1c = local_1c + 1;
    if (local_20[2] == '\0') {
      return local_1c;
    }
    if (param_3 <= local_1c) {
      piVar2 = __errno_location();
      *piVar2 = 7;
      return 0;
    }
    if (local_20[2] != ':') break;
    local_20 = local_20 + 3;
  }
  piVar2 = __errno_location();
  *piVar2 = 0x16;
  return 0;
}

[ASK_GPT] a651b2b4c213a46d
