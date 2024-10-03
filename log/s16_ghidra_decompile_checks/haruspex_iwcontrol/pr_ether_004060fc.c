
undefined * pr_ether(byte *param_1)

{
  sprintf(&DAT_00418f20,"%02X:%02X:%02X:%02X:%02X:%02X",(uint)*param_1,(uint)param_1[1],
[32m          (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5],&_gp);[0m
  return &DAT_00418f20;
}

[ASK_GPT] 49490e08e4089f7c
