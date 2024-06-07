
void sip_clear(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10 [2];
  
  reg_write(0x80,0x8202,param_3,param_4,&_gp);
  usleep(5000);
[32m  reg_read(0x80,local_10);[0m
  printf("REG_ESW_WT_MAC_ATC is 0x%x\n\r",local_10[0]);
  return;
}

[ASK_GPT] 46a6ab40436aa17d
