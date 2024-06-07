
void igmp_off(void)

{
  uint local_10 [2];
  
[32m  reg_read(0x18,local_10);[0m
  local_10[0] = local_10[0] & 0xfffbffff;
  reg_write(0x18,local_10[0]);
  puts("config igmpsnoop off.");
  return;
}

[ASK_GPT] b0db7b7112d46b45
