
void vlan_dump(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  int local_18;
  int local_14;
  uint local_10;
  undefined auStack_c [4];
  
  puVar3 = &_gp;
  puts("  vid  fid  portmap    s-tag");
  for (local_18 = 1; local_18 < 0xfff; local_18 = local_18 + 1) {
    local_10 = local_18 + 0x80000000;
    reg_write(0x90,local_10,param_3,param_4,puVar3);
    local_14 = 0;
[32m    while ((local_14 < 0x14 && (reg_read(0x90,&local_10), (int)local_10 < 0))) {[0m
      usleep(1000);
      local_14 = local_14 + 1;
    }
    if (local_14 == 0x14) {
      puts("timeout.");
    }
[32m    reg_read(0x94,&local_10);[0m
[32m    reg_read(0x98,auStack_c);[0m
    if ((local_10 & 1) == 0) {
      if (local_18 < 0x11) {
        printf(" %4d  ",local_18);
        printf(" %2d ",(int)(local_10 & 0xe) >> 1);
        puts(" invalid");
      }
    }
    else {
      printf(" %4d  ",local_18);
      printf(" %2d ",(int)(local_10 & 0xe) >> 1);
      if ((local_10 & 0x10000) == 0) {
        uVar1 = 0x2d;
      }
      else {
        uVar1 = 0x31;
      }
      printf(" %c",uVar1);
      if ((local_10 & 0x20000) == 0) {
        iVar2 = 0x2d;
      }
      else {
        iVar2 = 0x31;
      }
      putchar(iVar2);
      if ((local_10 & 0x40000) == 0) {
        iVar2 = 0x2d;
      }
      else {
        iVar2 = 0x31;
      }
      putchar(iVar2);
      if ((local_10 & 0x80000) == 0) {
        iVar2 = 0x2d;
      }
      else {
        iVar2 = 0x31;
      }
      putchar(iVar2);
      if ((local_10 & 0x100000) == 0) {
        iVar2 = 0x2d;
      }
      else {
        iVar2 = 0x31;
      }
      putchar(iVar2);
      if ((local_10 & 0x200000) == 0) {
        iVar2 = 0x2d;
      }
      else {
        iVar2 = 0x31;
      }
      putchar(iVar2);
      if ((local_10 & 0x400000) == 0) {
        iVar2 = 0x2d;
      }
      else {
        iVar2 = 0x31;
      }
      putchar(iVar2);
      if ((local_10 & 0x800000) == 0) {
        iVar2 = 0x2d;
      }
      else {
        iVar2 = 0x31;
      }
      putchar(iVar2);
      printf("    %4d\n",(int)(local_10 & 0xfff0) >> 4);
    }
  }
  return;
}

[ASK_GPT] ee3f31cb480d8d51
