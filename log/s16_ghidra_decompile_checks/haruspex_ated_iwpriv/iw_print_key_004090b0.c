
void iw_print_key(char *param_1,size_t param_2,byte *param_3,int param_4,uint param_5)

{
  char *local_res0;
  uint local_10;
  
  if ((int)param_2 < param_4 * 3) {
[32m    snprintf(param_1,param_2,"<too big>");[0m
  }
  else if ((param_5 & 0x800) == 0) {
[32m    sprintf(param_1,"%.2X",(uint)*param_3,param_4,&_gp);[0m
    local_res0 = param_1 + 2;
    for (local_10 = 1; (int)local_10 < param_4; local_10 = local_10 + 1) {
      if ((local_10 & 1) == 0) {
        *local_res0 = '-';
        local_res0[1] = '\0';
        local_res0 = local_res0 + 1;
      }
[32m      sprintf(local_res0,"%.2X",(uint)param_3[local_10]);[0m
      local_res0 = local_res0 + 2;
    }
  }
  else if (param_4 < 1) {
    *param_1 = 'o';
    param_1[1] = 'n';
    param_1[2] = '\0';
  }
  else {
    *param_1 = '*';
    param_1[1] = '*';
    param_1[2] = '\0';
    local_res0 = param_1 + 2;
    for (local_10 = 1; (int)local_10 < param_4; local_10 = local_10 + 1) {
      if ((local_10 & 1) == 0) {
        *local_res0 = '-';
        local_res0[1] = '\0';
        local_res0 = local_res0 + 1;
      }
      *local_res0 = '*';
      local_res0[1] = '*';
      local_res0[2] = '\0';
      local_res0 = local_res0 + 2;
    }
  }
  return;
}

[ASK_GPT] 3c202abbd9ce02cd
