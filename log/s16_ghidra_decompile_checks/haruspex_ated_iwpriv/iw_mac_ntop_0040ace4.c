
char * iw_mac_ntop(byte *param_1,int param_2,char *param_3,int param_4)

{
  int local_10;
  
  if (param_4 < param_2 * 3) {
    param_3 = (char *)0x0;
  }
  else {
[32m    sprintf(param_3,"%02X",(uint)*param_1,param_4,&_gp);[0m
    for (local_10 = 1; local_10 < param_2; local_10 = local_10 + 1) {
[32m      sprintf(param_3 + local_10 * 3 + -1,":%02X",(uint)param_1[local_10]);[0m
    }
  }
  return param_3;
}

[ASK_GPT] b6145464d5ea47d8
