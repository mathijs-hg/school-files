
int add_xu_ctrls(int param_1)

{
  int iVar1;
  int local_60;
  int local_5c;
  int local_58 [2];
  char acStack_50 [60];
  char *local_14 [2];
  char local_c [4];
  
  local_5c = 0;
  local_14[0] = "Command status";
  local_14[1] = "Data in out";
  local_c[0] = '\0';
  local_c[1] = 0;
[32m  memset(local_58,0,0x44);[0m
  local_58[0] = 0x8000000;
  for (local_60 = 0; local_60 < 2; local_60 = local_60 + 1) {
    iVar1 = ioctl(param_1,0xc0445624,local_58);
    if ((iVar1 == 0) && (iVar1 = strcmp(acStack_50,local_14[local_60]), iVar1 == 0)) {
      local_c[local_60] = '\x01';
    }
    local_58[0] = local_58[0] + 1;
  }
  local_60 = 0;
  while( true ) {
    if (1 < local_60) {
      return local_5c;
    }
    if ((local_c[local_60] == '\0') &&
       (local_5c = ioctl(param_1,0xc0587520,&uvc_xu_ctrl_mappings + local_60 * 0x58), local_5c != 0)
       ) break;
    local_60 = local_60 + 1;
  }
  fprintf(stderr,"Map ctrl %d fail!\n",local_60);
  return local_5c;
}

[ASK_GPT] 93ed18778ad88364
