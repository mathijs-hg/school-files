
void iw_print_bitrate(FLO_type param_1,FLO_type param_2,char *param_3,size_t param_4,SItype param_5)

{
  CMPtype CVar1;
  SItype local_1c;
  
  __floatsidf(param_5);
  CVar1 = __gedf2(param_1,param_2);
  if (CVar1 < 0) {
    CVar1 = __gedf2(param_1,param_2);
    if (CVar1 < 0) {
      local_1c = 1000;
    }
    else {
      local_1c = 1000000;
    }
  }
  else {
    local_1c = 1000000000;
  }
  __floatsidf(local_1c);
  __divdf3(param_1,param_2);
[32m  snprintf(param_3,param_4,"%g %cb/s");[0m
  return;
}

[ASK_GPT] 8f13dfd0901c15b7
