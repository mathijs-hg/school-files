
void acl_dip_meter(int param_1,int param_2)

{
  size_t sVar1;
  ulong uVar2;
  uint local_30;
  int local_2c;
  uint local_20;
  uint local_1c [5];
  
  if (param_1 < 7) {
    puts("insufficient arguments!");
  }
  else if ((*(int *)(param_2 + 0x14) == 0) ||
[32m          (sVar1 = strlen(*(char **)(param_2 + 0x14)), sVar1 != 8)) {[0m
    puts("portmap format error, should be of length 7");
  }
  else {
    local_2c = 0;
    for (local_30 = 0; local_30 < 7; local_30 = local_30 + 1) {
      if ((*(char *)(*(int *)(param_2 + 0x14) + local_30) != '0') &&
         (*(char *)(*(int *)(param_2 + 0x14) + local_30) != '1')) {
        puts("portmap format error, should be of combination of 0 or 1");
        return;
      }
      local_2c = local_2c +
                 (*(char *)(*(int *)(param_2 + 0x14) + local_30) + -0x30 << (local_30 & 0x1f));
    }
    str_to_ip(local_1c,*(undefined4 *)(param_2 + 0x10));
    local_20 = local_1c[0] >> 0x10 | 0xffff0000;
    reg_write(0x94,local_20);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_20);
    local_20 = local_2c << 8 | 0xa0010;
    reg_write(0x98,local_20);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_20);
    local_20 = 0x80005000;
    reg_write(0x90,0x80005000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_20);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_20), (int)local_20 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
    local_20 = local_1c[0] & 0xffff | 0xffff0000;
    reg_write(0x94,local_20);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_20);
    local_20 = local_2c << 8 | 0xa0012;
    reg_write(0x98,local_20);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_20);
    local_20 = 0x80005001;
    reg_write(0x90,0x80005001);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_20);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_20), (int)local_20 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
    local_20 = 3;
    reg_write(0x94,3);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_20);
    local_20 = 0;
    reg_write(0x98,0);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_20);
    local_20 = 0x80009000;
    reg_write(0x90,0x80009000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_20);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_20), (int)local_20 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
    uVar2 = strtoul(*(char **)(param_2 + 0x18),(char **)0x0,0);
    local_20 = uVar2 >> 6 | 0x8000;
    reg_write(0x94,local_20);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_20);
    local_20 = 0;
    reg_write(0x98,0);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_20);
    local_20 = 0x8000d000;
    reg_write(0x90,0x8000d000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_20);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_20), (int)local_20 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
  }
  return;
}

[ASK_GPT] 9aaa279408964ee0
