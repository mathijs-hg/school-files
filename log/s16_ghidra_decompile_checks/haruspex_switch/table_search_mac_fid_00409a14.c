
void table_search_mac_fid(undefined4 param_1,int param_2)

{
  size_t sVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_30;
  uint local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  char acStack_18 [4];
  undefined local_14;
  undefined local_10;
  
[32m  if ((*(int *)(param_2 + 0xc) == 0) || (sVar1 = strlen(*(char **)(param_2 + 0xc)), sVar1 != 0xc)) {[0m
    puts("MAC address format error, should be of length 12");
  }
  else {
[32m[32m[32m    strncpy(acStack_18,*(char **)(param_2 + 0xc),8);[0m[0m[0m
    local_10 = 0;
    local_28 = strtoul(acStack_18,(char **)0x0,0x10);
    reg_write(0x74,local_28);
[32m[32m[32m    strncpy(acStack_18,(char *)(*(int *)(param_2 + 0xc) + 8),4);[0m[0m[0m
    local_14 = 0;
    uVar2 = strtoul(acStack_18,(char **)0x0,0x10);
    local_28 = uVar2 << 0x10;
    uVar2 = strtoul(*(char **)(param_2 + 0x14),(char **)0x0,0);
    if (uVar2 < 8) {
      local_28 = uVar2 << 0xc | local_28;
      reg_write(0x78,local_28);
      local_28 = 0x8000;
      reg_write(0x80,0x8000);
      usleep(1000);
      local_30 = 0;
[32m      while ((local_30 < 0x14 && (reg_read(0x80,&local_28), (local_28 & 0x8000) != 0))) {[0m
        usleep(1000);
        local_30 = local_30 + 1;
      }
      if (local_30 == 0x14) {
        puts("search timeout.");
      }
      else if ((local_28 & 0x1000) == 0) {
        puts("search done.");
        puts("hash  port(0:6)   fid   vid  age   mac-address     filter my_mac");
        printf("%03x:   ",local_28 >> 0x10 & 0xfff);
[32m        reg_read(0x8c,&local_1c);[0m
        uVar3 = local_1c >> 4;
        if ((uVar3 & 1) == 0) {
          iVar4 = 0x2d;
        }
        else {
          iVar4 = 0x31;
        }
        putchar(iVar4);
        if ((uVar3 & 2) == 0) {
          iVar4 = 0x2d;
        }
        else {
          iVar4 = 0x31;
        }
        putchar(iVar4);
        if ((uVar3 & 4) == 0) {
          iVar4 = 0x2d;
        }
        else {
          iVar4 = 0x31;
        }
        putchar(iVar4);
        if ((uVar3 & 8) == 0) {
          uVar5 = 0x2d;
        }
        else {
          uVar5 = 0x31;
        }
        printf("%c ",uVar5);
        if ((uVar3 & 0x10) == 0) {
          iVar4 = 0x2d;
        }
        else {
          iVar4 = 0x31;
        }
        putchar(iVar4);
        if ((uVar3 & 0x20) == 0) {
          iVar4 = 0x2d;
        }
        else {
          iVar4 = 0x31;
        }
        putchar(iVar4);
        if ((uVar3 & 0x40) == 0) {
          iVar4 = 0x2d;
        }
        else {
          iVar4 = 0x31;
        }
        putchar(iVar4);
        if ((uVar3 & 0x80) == 0) {
          iVar4 = 0x2d;
        }
        else {
          iVar4 = 0x31;
        }
        putchar(iVar4);
[32m        reg_read(0x88,&local_20);[0m
        printf("   %2d",local_20 >> 0xc & 7);
        printf("  %4d",local_20 & 0xfff);
        printf(" %4d",local_1c >> 0x18);
[32m        reg_read(0x84,&local_24);[0m
        printf("  %08x",local_24);
        printf("%04x",local_20 >> 0x10);
        if ((local_1c >> 0x14 & 3) == 3) {
          uVar5 = 0x79;
        }
        else {
          uVar5 = 0x2d;
        }
        printf("     %c",uVar5);
        if ((local_1c & 0x800000) == 0) {
          uVar5 = 0x2d;
        }
        else {
          uVar5 = 0x79;
        }
        printf("     %c\n",uVar5);
      }
      else {
        puts("search no entry.");
      }
    }
    else {
      puts("wrong fid range, should be within 0~7");
    }
  }
  return;
}

[ASK_GPT] e8376d2304891df2
