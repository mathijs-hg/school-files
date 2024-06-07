
void acl_sp_add(int param_1,int param_2)

{
  size_t sVar1;
  ulong uVar2;
  uint local_28;
  int local_24;
  uint local_1c [5];
  
  if (param_1 < 6) {
    puts("insufficient arguments!");
  }
  else if ((*(int *)(param_2 + 0x14) == 0) ||
[32m          (sVar1 = strlen(*(char **)(param_2 + 0x14)), sVar1 != 8)) {[0m
    puts("portmap format error, should be of length 7");
  }
  else {
    local_24 = 0;
    for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
      if ((*(char *)(*(int *)(param_2 + 0x14) + local_28) != '0') &&
         (*(char *)(*(int *)(param_2 + 0x14) + local_28) != '1')) {
        puts("portmap format error, should be of combination of 0 or 1");
        return;
      }
      local_24 = local_24 +
                 (*(char *)(*(int *)(param_2 + 0x14) + local_28) + -0x30 << (local_28 & 0x1f));
    }
    uVar2 = strtoul(*(char **)(param_2 + 0x10),(char **)0x0,0);
    local_1c[0] = uVar2 | 0xffff0000;
    reg_write(0x94,local_1c[0]);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_1c[0]);
    local_1c[0] = local_24 << 8 | 0xc0000;
    reg_write(0x98,local_1c[0]);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_1c[0]);
    local_1c[0] = 0x80005000;
    reg_write(0x90,0x80005000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_1c[0]);
    local_28 = 0;
[32m    while ((local_28 < 0x14 && (reg_read(0x90,local_1c), (int)local_1c[0] < 0))) {[0m
      usleep(1000);
      local_28 = local_28 + 1;
    }
    if (local_28 == 0x14) {
      puts("timeout.");
    }
    local_1c[0] = 1;
    reg_write(0x94,1);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_1c[0]);
    local_1c[0] = 0;
    reg_write(0x98,0);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_1c[0]);
    local_1c[0] = 0x80009000;
    reg_write(0x90,0x80009000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_1c[0]);
    local_28 = 0;
[32m    while ((local_28 < 0x14 && (reg_read(0x90,local_1c), (int)local_1c[0] < 0))) {[0m
      usleep(1000);
      local_28 = local_28 + 1;
    }
    if (local_28 == 0x14) {
      puts("timeout.");
    }
    local_1c[0] = 7;
    reg_write(0x94,7);
    printf("REG_ESW_VLAN_VAWD1 value is 0x%x\n\r",local_1c[0]);
    local_1c[0] = 0;
    reg_write(0x98,0);
    printf("REG_ESW_VLAN_VAWD2 value is 0x%x\n\r",local_1c[0]);
    local_1c[0] = 0x8000b000;
    reg_write(0x90,0x8000b000);
    printf("REG_ESW_VLAN_VTCR value is 0x%x\n\r\n\r",local_1c[0]);
    local_28 = 0;
[32m    while ((local_28 < 0x14 && (reg_read(0x90,local_1c), (int)local_1c[0] < 0))) {[0m
      usleep(1000);
      local_28 = local_28 + 1;
    }
    if (local_28 == 0x14) {
      puts("timeout.");
    }
  }
  return;
}

[ASK_GPT] 234e2aeac4107821
