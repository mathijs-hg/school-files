
void acl_dip_trtcm(int param_1,int param_2)

{
  size_t sVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  uint local_40;
  int local_3c;
  uint local_24;
  uint local_20 [6];
  
  if (param_1 < 6) {
    puts("insufficient arguments!");
  }
  else if ((*(int *)(param_2 + 0x14) == 0) ||
[32m          (sVar1 = strlen(*(char **)(param_2 + 0x14)), sVar1 != 8)) {[0m
    puts("portmap format error, should be of length 7");
  }
  else {
    local_3c = 0;
    for (local_40 = 0; local_40 < 7; local_40 = local_40 + 1) {
      if ((*(char *)(*(int *)(param_2 + 0x14) + local_40) != '0') &&
         (*(char *)(*(int *)(param_2 + 0x14) + local_40) != '1')) {
        puts("portmap format error, should be of combination of 0 or 1");
        return;
      }
      local_3c = local_3c +
                 (*(char *)(*(int *)(param_2 + 0x14) + local_40) + -0x30 << (local_40 & 0x1f));
    }
    str_to_ip(local_20,*(undefined4 *)(param_2 + 0x10));
    local_24 = local_20[0] >> 0x10 | 0xffff0000;
    reg_write(0x94,local_24);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = local_3c << 8 | 0xa0010;
    reg_write(0x98,local_24);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x80005000;
    reg_write(0x90,0x80005000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_40 = 0;
[32m    while ((local_40 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_40 = local_40 + 1;
    }
    if (local_40 == 0x14) {
      puts("timeout.");
    }
    local_24 = local_20[0] & 0xffff | 0xffff0000;
    reg_write(0x94,local_24);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = local_3c << 8 | 0xa0012;
    reg_write(0x98,local_24);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x80005001;
    reg_write(0x90,0x80005001);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_40 = 0;
[32m    while ((local_40 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_40 = local_40 + 1;
    }
    if (local_40 == 0x14) {
      puts("timeout.");
    }
    uVar2 = strtoul(*(char **)(param_2 + 0x18),(char **)0x0,0);
    uVar3 = strtoul(*(char **)(param_2 + 0x1c),(char **)0x0,0);
    uVar4 = strtoul(*(char **)(param_2 + 0x20),(char **)0x0,0);
    uVar5 = strtoul(*(char **)(param_2 + 0x24),(char **)0x0,0);
    local_24 = uVar3 << 0x10 | uVar5;
    reg_write(0x94,local_24);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = (uVar2 >> 6) << 0x10 | uVar4 >> 6;
    reg_write(0x98,local_24);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x80007000;
    reg_write(0x90,0x80007000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_40 = 0;
[32m    while ((local_40 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_40 = local_40 + 1;
    }
    if (local_40 == 0x14) {
      puts("timeout.");
    }
    local_24 = 3;
    reg_write(0x94,3);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = 0;
    reg_write(0x98,0);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x80009000;
    reg_write(0x90,0x80009000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_40 = 0;
[32m    while ((local_40 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_40 = local_40 + 1;
    }
    if (local_40 == 0x14) {
      puts("timeout.");
    }
    local_24 = 0;
    reg_write(0x94,0);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_24);
    local_24 = 0x14c1;
    reg_write(0x98,0x14c1);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_24);
    local_24 = 0x8000b000;
    reg_write(0x90,0x8000b000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_24);
    local_40 = 0;
[32m    while ((local_40 < 0x14 && (reg_read(0x90,&local_24), (int)local_24 < 0))) {[0m
      usleep(1000);
      local_40 = local_40 + 1;
    }
    if (local_40 == 0x14) {
      puts("timeout.");
    }
  }
  return;
}

[ASK_GPT] 8bf44f018411ba35
