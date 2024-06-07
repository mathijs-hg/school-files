
void vlan_clear(void)

{
  uint local_18;
  int local_14;
  int local_10 [2];
  
  local_14 = 0;
  do {
    if (0xf < local_14) {
      return;
    }
    local_10[0] = 0;
    reg_write(0x94,0);
    local_10[0] = local_14 + -0x7ffff000;
    reg_write(0x90,local_10[0]);
    for (local_18 = 0; local_18 < 300; local_18 = local_18 + 1) {
      usleep(1000);
[32m      reg_read(0x90,local_10);[0m
      if (-1 < local_10[0]) break;
    }
    if (local_18 == 300) {
      puts("config vlan timeout.");
    }
    local_14 = local_14 + 1;
  } while( true );
}

[ASK_GPT] efa70f1ae71783b6
