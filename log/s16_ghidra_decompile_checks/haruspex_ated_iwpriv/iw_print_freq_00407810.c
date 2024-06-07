
void iw_print_freq(FLO_type param_1,FLO_type param_2,char *param_3,size_t param_4,
                  undefined4 param_5_00,undefined4 param_6_00,int param_5,uint param_6)

{
  char cVar1;
  CMPtype CVar2;
  undefined *puVar3;
  undefined auStack_24 [24];
  
  puVar3 = &_gp;
  if ((param_6 & 1) == 0) {
    cVar1 = ':';
  }
  else {
    cVar1 = '=';
  }
  iw_print_freq_value(auStack_24,0x10,param_5_00,param_6_00);
  CVar2 = __ltdf2(param_1,param_2);
  if (CVar2 < 0) {
[32m    snprintf(param_3,param_4,"Channel%c%s",(int)cVar1,auStack_24);[0m
  }
  else if (param_5 < 0) {
[32m    snprintf(param_3,param_4,"Frequency%c%s",(int)cVar1,auStack_24);[0m
  }
  else {
[32m    snprintf(param_3,param_4,"Frequency%c%s (Channel %d)",(int)cVar1,auStack_24,param_5,puVar3);[0m
  }
  return;
}

[ASK_GPT] 01d5baab4283213d
