
void sip_del(undefined4 param_1,int param_2)

{
  uint local_20;
  uint local_1c [5];
  
  str_to_ip(local_1c,*(undefined4 *)(param_2 + 0xc));
  reg_write(0x78,local_1c[0]);
  str_to_ip(local_1c,*(undefined4 *)(param_2 + 0x10));
  reg_write(0x74,local_1c[0]);
  local_1c[0] = 0;
  reg_write(0x7c,0);
  local_1c[0] = 0x8021;
  reg_write(0x80,0x8021);
  local_20 = 0;
  while( true ) {
    if (0x13 < local_20) {
      if (local_20 == 0x14) {
        puts("timeout.");
      }
      return;
    }
[32m    reg_read(0x80,local_1c);[0m
    if ((local_1c[0] & 0x8000) == 0) break;
    usleep(1000);
    local_20 = local_20 + 1;
  }
  if (*(int *)(param_2 + 4) == 0) {
    return;
  }
  puts("done.");
  return;
}

[ASK_GPT] 5b7b9b1ff26ba4b8
