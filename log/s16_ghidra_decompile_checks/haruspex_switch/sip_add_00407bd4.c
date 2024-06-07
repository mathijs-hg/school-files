
void sip_add(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  uint local_20;
  int local_1c;
  uint local_18 [4];
  
  str_to_ip(local_18,*(undefined4 *)(param_2 + 0xc),param_3,param_4,&_gp);
  reg_write(0x78,local_18[0]);
  printf("REG_ESW_WT_MAC_ATA2 is 0x%x\n\r",local_18[0]);
  local_18[0] = 0;
  str_to_ip(local_18,*(undefined4 *)(param_2 + 0x10));
  reg_write(0x74,local_18[0]);
  printf("REG_ESW_WT_MAC_ATA1 is 0x%x\n\r",local_18[0]);
[32m  if ((*(int *)(param_2 + 0x14) == 0) || (sVar1 = strlen(*(char **)(param_2 + 0x14)), sVar1 != 8)) {[0m
    puts("portmap format error, should be of length 7");
  }
  else {
    local_1c = 0;
    for (local_20 = 0; local_20 < 7; local_20 = local_20 + 1) {
      if ((*(char *)(*(int *)(param_2 + 0x14) + local_20) != '0') &&
         (*(char *)(*(int *)(param_2 + 0x14) + local_20) != '1')) {
        puts("portmap format error, should be of combination of 0 or 1");
        return;
      }
      local_1c = local_1c +
                 (*(char *)(*(int *)(param_2 + 0x14) + local_20) + -0x30 << (local_20 & 0x1f));
    }
    local_18[0] = local_1c << 4 | 0xc;
    reg_write(0x7c,local_18[0]);
    usleep(5000);
[32m    reg_read(0x7c,local_18);[0m
    printf("REG_ESW_WT_MAC_ATWD is 0x%x\n\r",local_18[0]);
    local_18[0] = 0x8021;
    reg_write(0x80,0x8021);
    usleep(1000);
    for (local_20 = 0; local_20 < 0x14; local_20 = local_20 + 1) {
[32m      reg_read(0x80,local_18);[0m
      if ((local_18[0] & 0x8000) == 0) {
        puts("done.");
        return;
      }
      usleep(1000);
    }
    if (local_20 == 0x14) {
      puts("timeout.");
    }
  }
  return;
}

[ASK_GPT] 88e5ef1304ba3156
