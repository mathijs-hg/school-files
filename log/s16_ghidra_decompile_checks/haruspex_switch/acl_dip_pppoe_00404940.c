
void acl_dip_pppoe(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined *puVar2;
  uint local_30;
  int local_2c;
  uint local_24;
  uint local_20 [6];
  
  puVar2 = &_gp;
  if (param_1 < 6) {
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
    str_to_ip(local_20,*(undefined4 *)(param_2 + 0x10),param_3,param_4,puVar2);
    local_24 = local_20[0] >> 0x10 | 0xffff0000;
    reg_write(0x94,local_24);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = local_2c << 8 | 0xa0010;
    reg_write(0x98,local_24);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x80005000;
    reg_write(0x90,0x80005000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
    local_24 = local_20[0] & 0xffff | 0xffff0000;
    reg_write(0x94,local_24);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = local_2c << 8 | 0xa0012;
    reg_write(0x98,local_24);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x80005001;
    reg_write(0x90,0x80005001);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
    local_24 = 3;
    reg_write(0x94,3);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = 0;
    reg_write(0x98,0);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x80009007;
    reg_write(0x90,0x80009007);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
    local_24 = 0x18700000;
    reg_write(0x94,0x18700000);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = 0;
    reg_write(0x98,0);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x8000b007;
    reg_write(0x90,0x8000b007);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_30 = 0;
[32m    while ((local_30 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_30 = local_30 + 1;
    }
    if (local_30 == 0x14) {
      puts("timeout.");
    }
  }
  return;
}

[ASK_GPT] 6f748f09d8f8df40
