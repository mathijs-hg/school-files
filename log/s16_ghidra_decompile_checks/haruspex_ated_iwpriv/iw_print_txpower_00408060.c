
void iw_print_txpower(char *param_1,size_t param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 local_10;
  
  puVar1 = &_gp;
  if (*(char *)((int)param_3 + 5) == '\0') {
    if ((*(ushort *)((int)param_3 + 6) & 2) == 0) {
      if ((*(ushort *)((int)param_3 + 6) & 1) == 0) {
        local_10 = *param_3;
      }
      else {
        local_10 = iw_mwatt2dbm(*param_3);
      }
[32m      snprintf(param_1,param_2,"%d dBm",local_10,puVar1);[0m
    }
    else {
[32m      snprintf(param_1,param_2,"%d",*param_3,&_gp);[0m
    }
  }
  else {
[32m    snprintf(param_1,param_2,"off",param_4,&_gp);[0m
  }
  return;
}

[ASK_GPT] bed282d3c41bdb31
