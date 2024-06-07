
/* WARNING: Removing unreachable block (ram,0x0040bea8) */
/* WARNING: Removing unreachable block (ram,0x0040bcb0) */
/* WARNING: Removing unreachable block (ram,0x0040b9e8) */
/* WARNING: Removing unreachable block (ram,0x0040bc38) */
/* WARNING: Removing unreachable block (ram,0x0040be1c) */
/* WARNING: Removing unreachable block (ram,0x0040c05c) */

void igmp_on(int param_1,int param_2)

{
  int iVar1;
  ulong local_20;
  uint local_1c;
  uint local_10 [2];
  
  local_20 = 0;
  if (3 < param_1) {
    local_20 = strtoul(*(char **)(param_2 + 0xc),(char **)0x0,10);
  }
  if (local_20 == 1) {
[32m    reg_read(0x2410,local_10);[0m
    reg_write(0x2410,local_10[0] | 8);
[32m    reg_read(0x2010,local_10);[0m
    reg_write(0x2010,local_10[0] & 0xfffffff7);
    reg_write(0x18,0x10027d10);
  }
  else {
    reg_write(0x18,0x10027d60);
  }
[32m  reg_read(0x10,local_10);[0m
  reg_write(0x10,local_10[0] & 0xff00ffff);
  reg_write(0x1c,0x8100810);
  reg_write(0x2008,0xb3ff);
  reg_write(0x2108,0xb3ff);
  reg_write(0x2208,0xb3ff);
  reg_write(0x2308,0xb3ff);
  reg_write(0x2408,0xb3ff);
  reg_write(0x2608,0xb3ff);
  for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
    iVar1 = local_1c * 0x100 + 0x2004;
[32m    reg_read(iVar1,local_10);[0m
    reg_write(iVar1,local_10[0] | 0x400);
  }
  reg_write(0x94,0xff0002);
  reg_write(0x98,0xa1008);
  reg_write(0x90,0x80005000);
  reg_write(0x94,0xff001100);
  reg_write(0x98,0xb1000);
  reg_write(0x90,0x80005001);
  reg_write(0x94,3);
  reg_write(0x98,0);
  reg_write(0x90,0x80009000);
  reg_write(0x94,0x1a002080);
  reg_write(0x98,0);
  reg_write(0x90,0x8000b000);
  reg_write(0x94,0xff0002);
  reg_write(0x98,0xa2008);
  reg_write(0x90,0x80005002);
  reg_write(0x94,4);
  reg_write(0x98,0);
  reg_write(0x90,0x80009001);
  reg_write(0x94,0x1a001080);
  reg_write(0x98,0);
  reg_write(0x90,0x8000b001);
  reg_write(0x94,0xff0002);
  reg_write(0x98,0xa0f08);
  reg_write(0x90,0x80005003);
  reg_write(0x94,8);
  reg_write(0x98,0);
  reg_write(0x90,0x80009002);
  reg_write(0x94,0x1a004080);
  reg_write(0x98,0);
  reg_write(0x90,0x8000b002);
  reg_write(0x94,0xff0002);
  reg_write(0x98,0xa4008);
  reg_write(0x90,0x80005004);
  reg_write(0x94,0xff001100);
  reg_write(0x98,0xb4000);
  reg_write(0x90,0x80005005);
  reg_write(0x94,0x30);
  reg_write(0x98,0);
  reg_write(0x90,0x80009003);
  reg_write(0x94,0x1a000f80);
  reg_write(0x98,0);
  reg_write(0x90,0x8000b003);
[32m  system("echo 2 > /sys/devices/virtual/net/br0/brif/eth0/multicast_router");[0m
  return;
}

[ASK_GPT] 4e8b45428367ce7d
