
void table_add(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  size_t sVar3;
  ulong uVar4;
  uint local_28;
  int local_24;
  uint local_18;
  char acStack_14 [4];
  undefined local_10;
  undefined local_c;
  
  bVar2 = **(char **)(param_2 + 4) == 'f';
[32m  cVar1 = **(char **)(param_2 + 4);[0m
[32m  if ((*(int *)(param_2 + 8) == 0) || (sVar3 = strlen(*(char **)(param_2 + 8)), sVar3 != 0xc)) {[0m
    puts("MAC address format error, should be of length 12");
  }
  else {
[32m[32m[32m    strncpy(acStack_14,*(char **)(param_2 + 8),8);[0m[0m[0m
    local_c = 0;
    local_18 = strtoul(acStack_14,(char **)0x0,0x10);
    reg_write(0x74,local_18);
    printf("REG_ESW_WT_MAC_ATA1 is 0x%x\n\r",local_18);
[32m[32m[32m    strncpy(acStack_14,(char *)(*(int *)(param_2 + 8) + 8),4);[0m[0m[0m
    local_10 = 0;
    uVar4 = strtoul(acStack_14,(char **)0x0,0x10);
    local_18 = uVar4 << 0x10 | 0x8000;
    if (4 < param_1) {
      uVar4 = strtoul(*(char **)(param_2 + 0x10),(char **)0x0,0);
      if (0xfff < uVar4) {
        puts("wrong vid range, should be within 0~4095");
        return;
      }
      local_18 = local_18 | uVar4;
    }
    reg_write(0x78,local_18);
    printf("REG_ESW_WT_MAC_ATA2 is 0x%x\n\r",local_18);
[32m    if ((*(int *)(param_2 + 0xc) == 0) || (sVar3 = strlen(*(char **)(param_2 + 0xc)), sVar3 != 8)) {[0m
      if (!bVar2) {
        puts("portmap format error, should be of length 7");
        return;
      }
      *(char **)(param_2 + 0xc) = "1111111";
    }
    local_24 = 0;
    for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
      if ((*(char *)(*(int *)(param_2 + 0xc) + local_28) != '0') &&
         (*(char *)(*(int *)(param_2 + 0xc) + local_28) != '1')) {
        puts("portmap format error, should be of combination of 0 or 1");
        return;
      }
      local_24 = local_24 +
                 (*(char *)(*(int *)(param_2 + 0xc) + local_28) + -0x30 << (local_28 & 0x1f));
    }
    local_18 = local_24 << 4;
    if (param_1 < 6) {
      local_18 = local_18 | 0xff00000c;
    }
    else {
      uVar4 = strtoul(*(char **)(param_2 + 0x14),(char **)0x0,0);
      if ((uVar4 == 0) || (0xff < uVar4)) {
        puts("wrong age range, should be within 1~255");
        return;
      }
      local_18 = uVar4 << 0x18 | local_18 | 4;
    }
    if (6 < param_1) {
      uVar4 = strtoul(*(char **)(param_2 + 0x18),(char **)0x0,0);
      if (7 < uVar4) {
        puts("wrong eg-tag range, should be within 0~7");
        return;
      }
      local_18 = uVar4 << 0xd | local_18;
    }
    if (bVar2) {
      local_18 = local_18 | 0x700000;
    }
    if (cVar1 == 'm') {
      local_18 = local_18 | 0x800000;
    }
    reg_write(0x7c,local_18);
    usleep(5000);
[32m    reg_read(0x7c,&local_18);[0m
    printf("REG_ESW_WT_MAC_ATWD is 0x%x\n\r",local_18);
    local_18 = 0x8001;
    reg_write(0x80,0x8001);
    usleep(1000);
    for (local_28 = 0; local_28 < 0x14; local_28 = local_28 + 1) {
[32m      reg_read(0x80,&local_18);[0m
      if ((local_18 & 0x8000) == 0) {
        puts("done.");
        return;
      }
      usleep(1000);
    }
    if (local_28 == 0x14) {
      puts("timeout.");
    }
  }
  return;
}

[ASK_GPT] 6cdd70b7bc70126b
