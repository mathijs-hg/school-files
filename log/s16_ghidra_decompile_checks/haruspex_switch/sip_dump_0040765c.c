
void sip_dump(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int local_70;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  uint auStack_58 [16];
  undefined auStack_18 [16];
  
  puVar4 = &_gp;
  for (local_70 = 0; local_70 < 8; local_70 = local_70 + 1) {
[32m    reg_read((local_70 + 0x40) * 4,&local_68,param_3,param_4,puVar4);[0m
    auStack_58[local_70 * 2] = local_68 & 0xfff;
    auStack_58[local_70 * 2 + 1] = (int)(local_68 & 0xfff000) >> 0xc;
  }
  reg_write(0x80,0x8204);
  puts("hash  port(0:6)   dip-address    sip-address      ATRD");
  local_70 = 0;
  while( true ) {
    if (0x7ff < local_70) {
      return;
    }
[32m    while (reg_read(0x80,&local_68), (local_68 & 0x2000) == 0) {[0m
      if ((local_68 & 0x4000) != 0) {
        printf("found the last entry %d (not ready)\n",local_70);
        return;
      }
      usleep(5000);
    }
[32m    reg_read(0x8c,&local_5c);[0m
    printf("%03x:  ",(int)local_68 >> 0x10 & 0xfff);
    uVar1 = local_5c >> 4;
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
      iVar2 = 0x2d;
    }
    else {
      iVar2 = 0x31;
    }
    putchar(iVar2);
    if ((uVar1 & 0x10) == 0) {
      uVar3 = 0x2d;
    }
    else {
      uVar3 = 0x31;
    }
    printf(" %c",uVar3);
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
[32m    reg_read(0x88,&local_60);[0m
    ip_to_str(auStack_18,local_60);
    printf("   %s",auStack_18);
[32m    reg_read(0x84,&local_64);[0m
    ip_to_str(auStack_18,local_64);
    printf("    %s",auStack_18);
    printf("      0x%x\n",local_5c);
    if ((local_68 & 0x4000) != 0) break;
    reg_write(0x80,0x8205);
    usleep(5000);
    local_70 = local_70 + 1;
  }
  printf("end of table %d\n",local_70);
  return;
}

[ASK_GPT] cd982b4c530371ba
