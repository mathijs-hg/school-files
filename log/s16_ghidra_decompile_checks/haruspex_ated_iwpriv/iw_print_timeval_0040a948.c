
void iw_print_timeval(char *param_1,size_t param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = (*param_3 + *param_4 * -0x3c) % 0x15180;
  snprintf(param_1,param_2,"%02d:%02d:%02d.%06u",iVar1 / 0xe10,(iVar1 % 0xe10) / 0x3c,iVar1 % 0x3c,
[32m           param_3[1]);[0m
  return;
}

[ASK_GPT] 0bbb8377c4ab5e97
