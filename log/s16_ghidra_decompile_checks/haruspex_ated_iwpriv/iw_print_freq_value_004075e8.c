
void iw_print_freq_value(FLO_type param_1,FLO_type param_2,char *param_3,size_t param_4)

{
  CMPtype CVar1;
  SItype local_14;
  
  CVar1 = __ltdf2(param_1,param_2);
  if (CVar1 < 0) {
[32m    snprintf(param_3,param_4,"%g");[0m
  }
  else {
    CVar1 = __gedf2(param_1,param_2);
    if (CVar1 < 0) {
      CVar1 = __gedf2(param_1,param_2);
      if (CVar1 < 0) {
        local_14 = 1000;
      }
      else {
        local_14 = 1000000;
      }
    }
    else {
      local_14 = 1000000000;
    }
    __floatsidf(local_14);
    __divdf3(param_1,param_2);
[32m    snprintf(param_3,param_4,"%g %cHz");[0m
  }
  return;
}

[ASK_GPT] 6f973be8d09223c7
