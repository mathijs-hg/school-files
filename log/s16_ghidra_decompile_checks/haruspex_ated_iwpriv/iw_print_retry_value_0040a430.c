
void iw_print_retry_value
               (FLO_type param_1,FLO_type param_2,undefined4 *param_3,size_t param_4,
               SItype param_5_00,uint param_6,int param_5)

{
  char *__s;
  undefined4 *local_res0;
  SItype local_res8;
  
  if ((int)param_4 < 0x14) {
[32m    snprintf((char *)param_3,param_4,"<too big>");[0m
  }
  else {
[32m    param_4 = param_4 - 0x14;[0m
    local_res0 = param_3;
    if ((param_6 & 1) != 0) {
      *param_3 = 0x6e696d20;
      *(undefined *)(param_3 + 1) = 0;
      local_res0 = param_3 + 1;
    }
    if ((param_6 & 2) != 0) {
      *local_res0 = 0x78616d20;
      *(undefined *)(local_res0 + 1) = 0;
      local_res0 = local_res0 + 1;
    }
    if ((param_6 & 0x10) != 0) {
      *local_res0 = 0x6f687320;
      *(char *)(local_res0 + 1) = 'r';
      *(char *)((int)local_res0 + 5) = 't';
      *(char *)((int)local_res0 + 6) = '\0';
      local_res0 = (undefined4 *)((int)local_res0 + 6);
    }
    if ((param_6 & 0x20) != 0) {
      *local_res0 = 0x6f6c2020;
      *(char *)(local_res0 + 1) = 'n';
      *(char *)((int)local_res0 + 5) = 'g';
      *(char *)((int)local_res0 + 6) = '\0';
      local_res0 = (undefined4 *)((int)local_res0 + 6);
    }
    if ((param_6 & 0x2000) == 0) {
[32m      snprintf((char *)local_res0,param_4," limit:%d",param_5_00);[0m
    }
    else {
      *local_res0 = 0x66696c20;
      local_res0[1] = 0x6d697465;
      *(char *)(local_res0 + 2) = 'e';
      *(char *)((int)local_res0 + 9) = ':';
      *(char *)((int)local_res0 + 10) = '\0';
      __s = (char *)((int)local_res0 + 10);
      if ((param_6 & 4) == 0) {
        if (param_5_00 < 1000000) {
          if (param_5_00 < 1000) {
[32m            snprintf(__s,param_4,"%dus",param_5_00);[0m
          }
          else {
            __floatsidf(param_5_00);
            __divdf3(param_1,param_2);
[32m            snprintf(__s,param_4,"%gms");[0m
          }
        }
        else {
          __floatsidf(param_5_00);
          __divdf3(param_1,param_2);
[32m          snprintf(__s,param_4,"%gs");[0m
        }
      }
      else {
        local_res8 = param_5_00;
        if (param_5 < 0x15) {
          __floatsidf(param_5_00);
          __divdf3(param_1,param_2);
          local_res8 = __fixdfsi(param_1);
        }
[32m        snprintf(__s,param_4,"%d",local_res8);[0m
      }
    }
  }
  return;
}

[ASK_GPT] b9678cb78f2d313f
