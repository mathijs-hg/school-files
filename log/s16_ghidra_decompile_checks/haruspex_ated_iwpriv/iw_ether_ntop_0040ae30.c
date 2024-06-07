
void iw_ether_ntop(byte *param_1,char *param_2)

{
  sprintf(param_2,"%02X:%02X:%02X:%02X:%02X:%02X",(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
[32m          (uint)param_1[3],(uint)param_1[4],(uint)param_1[5],&_gp);[0m
  return;
}

[ASK_GPT] ce6f03eee7433121
