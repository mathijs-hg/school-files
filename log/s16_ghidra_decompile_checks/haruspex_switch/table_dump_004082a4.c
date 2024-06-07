
void table_dump(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int local_60;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  uint auStack_48 [16];
  
  puVar4 = &_gp;
  for (local_60 = 0; local_60 < 8; local_60 = local_60 + 1) {
[32m    reg_read((local_60 + 0x40) * 4,&local_58,param_3,param_4,puVar4);[0m
    auStack_48[local_60 * 2] = local_58 & 0xfff;
    auStack_48[local_60 * 2 + 1] = (int)(local_58 & 0xfff000) >> 0xc;
  }
  reg_write(0x80,0x8004);
  puts("hash  port(0:6)   fid   vid  age   mac-address     filter my_mac");
  local_60 = 0;
  while( true ) {
    if (0x7ff < local_60) {
      return;
    }
    while( true ) {
[32m      reg_read(0x80,&local_58);[0m
      if (((local_58 & 0x2000) != 0) && ((local_58 & 0x8000) == 0)) break;
      if (((local_58 & 0x4000) != 0) &&
         (((local_58 & 0x8000) == 0 && (((int)local_58 >> 0x10 & 0xfffU) == 0x7ff)))) {
        printf("found the last entry %d (not ready)\n",local_60);
        return;
      }
      usleep(5);
    }
    printf("%03x:   ",(int)local_58 >> 0x10 & 0xfff);
[32m    reg_read(0x8c,&local_4c);[0m
    uVar1 = (int)local_4c >> 4;
    if ((uVar1 & 1) == 0) {
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
    if ((uVar1 & 2) == 0) {
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
    if ((uVar1 & 4) == 0) {
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
    if ((uVar1 & 8) == 0) {
      uVar3 = 0x2d;
    }
    else {
      uVar3 = 0x31;
    }
    printf("%c ",uVar3);
    if ((uVar1 & 0x10) == 0) {
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
    if ((uVar1 & 0x20) == 0) {
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
    if ((uVar1 & 0x40) == 0) {
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
    if ((uVar1 & 0x80) == 0) {
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
[32m    reg_read(0x88,&local_50);[0m
    printf("   %2d",(int)local_50 >> 0xc & 7);
    printf("  %4d",local_50 & 0xfff);
    printf(" %4d",local_4c >> 0x18);
[32m    reg_read(0x84,&local_54);[0m
    printf("  %08x",local_54);
    printf("%04x",local_50 >> 0x10);
    if (((int)local_4c >> 0x14 & 3U) == 3) {
      uVar3 = 0x79;
    }
    else {
      uVar3 = 0x2d;
    }
    printf("     %c",uVar3);
    if ((local_4c & 0x800000) == 0) {
      uVar3 = 0x2d;
    }
    else {
      uVar3 = 0x79;
    }
    printf("     %c\n",uVar3);
    if (((local_58 & 0x4000) != 0) && (((int)local_58 >> 0x10 & 0xfffU) == 0x7ff)) break;
    reg_write(0x80,0x8005);
    usleep(5);
    local_60 = local_60 + 1;
  }
  printf("end of table %d\n",local_60);
  return;
}

[ASK_GPT] 961bbfabfcbd3018
