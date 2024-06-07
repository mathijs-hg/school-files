
void table_del_fid(int param_1,int param_2)

{
  size_t sVar1;
  ulong uVar2;
  int local_20;
  uint local_18;
  char acStack_14 [4];
  undefined local_10;
  undefined local_c;
  
[32m  if ((*(int *)(param_2 + 0xc) == 0) || (sVar1 = strlen(*(char **)(param_2 + 0xc)), sVar1 != 0xc)) {[0m
    puts("MAC address format error, should be of length 12");
    return;
  }
[32m[32m[32m  strncpy(acStack_14,*(char **)(param_2 + 0xc),8);[0m[0m[0m
  local_c = 0;
  local_18 = strtoul(acStack_14,(char **)0x0,0x10);
  reg_write(0x74,local_18);
[32m[32m[32m  strncpy(acStack_14,(char *)(*(int *)(param_2 + 0xc) + 8),4);[0m[0m[0m
  local_10 = 0;
  uVar2 = strtoul(acStack_14,(char **)0x0,0x10);
  local_18 = uVar2 << 0x10;
  if (5 < param_1) {
    uVar2 = strtoul(*(char **)(param_2 + 0x14),(char **)0x0,0);
    if (((int)uVar2 < 0) || (7 < (int)uVar2)) {
      puts("wrong fid range, should be within 0~7");
      return;
    }
    local_18 = uVar2 << 0xc | local_18;
  }
  reg_write(0x78,local_18);
  local_18 = 0;
  reg_write(0x7c,0);
  local_18 = 0x8001;
  reg_write(0x80,0x8001);
  for (local_20 = 0; local_20 < 0x14; local_20 = local_20 + 1) {
[32m    reg_read(0x80,&local_18);[0m
    if ((local_18 & 0x8000) == 0) {
      if (*(int *)(param_2 + 4) == 0) {
        return;
      }
      puts("done.");
      return;
    }
    usleep(1000);
  }
  if (local_20 != 0x14) {
    return;
  }
  puts("timeout.");
  return;
}

[ASK_GPT] 0016d1014c59626f
