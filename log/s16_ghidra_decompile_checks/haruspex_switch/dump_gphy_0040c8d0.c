
undefined4 dump_gphy(void)

{
  int __fd;
  undefined4 uVar1;
  int local_80;
  int local_7c;
  undefined4 local_60 [4];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined local_44;
  undefined4 *local_38;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  
  local_60[0] = 0;
  local_60[1] = 1;
  local_60[2] = 4;
  local_60[3] = 5;
  local_50 = 9;
  local_4c = 10;
  __fd = socket(2,1,0);
  if (__fd < 0) {
    puts("Open socket failed");
  }
  local_48 = 0x30687465;
  local_44 = 0;
  local_38 = &local_28;
  for (local_80 = 0; local_80 < 5; local_80 = local_80 + 1) {
    printf("== Port %d ==\n",local_80);
    for (local_7c = 0x9b; local_7c < 0xa3; local_7c = local_7c + 1) {
[32m      uVar1 = mii_mgr_cl45_read(local_80,0x1e,local_7c);[0m
      printf("dev1Eh_reg%xh = 0x%x\n",local_7c,uVar1);
    }
  }
  puts("== Global ==");
  for (local_80 = 0; local_80 < 6; local_80 = local_80 + 1) {
    local_28 = 0;
    local_24 = local_60[local_80];
    ioctl(__fd,0x89f3,&local_48);
    printf("Reg%xh = 0x%x\n",local_60[local_80],local_1c);
  }
  close(__fd);
  return 0;
}

[ASK_GPT] c4013f27b85bcb37
