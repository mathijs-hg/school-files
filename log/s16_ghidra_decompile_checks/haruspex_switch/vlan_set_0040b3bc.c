
void vlan_set(int param_1,int param_2)

{
  ulong uVar1;
  size_t sVar2;
  uint uVar3;
  uint local_28;
  uint local_24;
  ulong local_20;
  uint local_10 [2];
  
  local_20 = 0;
  if (param_1 < 5) {
    puts("insufficient arguments!");
  }
  else {
    uVar1 = strtoul(*(char **)(param_2 + 0x10),(char **)0x0,0);
    if (((int)uVar1 < 0) || (0xfff < (int)uVar1)) {
      puts("wrong vlan id range, should be within 0~4095");
    }
    else {
[32m      sVar2 = strlen(*(char **)(param_2 + 0x14));[0m
      if (sVar2 == 8) {
        local_24 = 0;
        for (local_28 = 0; local_28 < 8; local_28 = local_28 + 1) {
          if ((*(char *)(*(int *)(param_2 + 0x14) + local_28) != '0') &&
             (*(char *)(*(int *)(param_2 + 0x14) + local_28) != '1')) {
            puts("portmap format error, should be of combination of 0 or 1");
            return;
          }
          local_24 = local_24 +
                     (*(char *)(*(int *)(param_2 + 0x14) + local_28) + -0x30 << (local_28 & 0x1f));
        }
        if (6 < param_1) {
          local_20 = strtoul(*(char **)(param_2 + 0x18),(char **)0x0,0x10);
          printf("STAG index is 0x%x\n",local_20);
        }
        uVar3 = (local_20 & 0xfff) << 4 | local_24 << 0x10 | 0x40000000;
        local_10[0] = uVar3 | 1;
        if (7 < param_1) {
          local_10[0] = uVar3 | 0x10000001;
        }
        if (8 < param_1) {
          local_10[0] = local_10[0] | 0x10000000;
          reg_write(0x98,0);
        }
        reg_write(0x94,local_10[0]);
        local_10[0] = uVar1 + 0x80001000;
        reg_write(0x90,local_10[0]);
        for (local_24 = 0; local_24 < 300; local_24 = local_24 + 1) {
          usleep(1000);
[32m          reg_read(0x90,local_10);[0m
          if (-1 < (int)local_10[0]) break;
        }
        if (local_24 == 300) {
          puts("config vlan timeout.");
        }
      }
      else {
        puts("portmap format error, should be of length 7");
      }
    }
  }
  return;
}

[ASK_GPT] 00e18d8cbc27fc18
