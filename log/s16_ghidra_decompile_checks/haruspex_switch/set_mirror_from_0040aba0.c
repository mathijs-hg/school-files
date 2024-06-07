
void set_mirror_from(undefined4 param_1,int param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  uint local_c;
  
  uVar1 = strtoul(*(char **)(param_2 + 0xc),(char **)0x0,0);
  uVar2 = strtoul(*(char **)(param_2 + 0x10),(char **)0x0,0);
  if (((int)uVar1 < 0) || (6 < (int)uVar1)) {
    printf("wrong port member, should be within 0~%d\n",6);
  }
  else if (((int)uVar2 < 0) || (3 < (int)uVar2)) {
    puts("wrong mirror setting, should be within 0~3");
  }
  else {
    uVar3 = uVar1 << 8 | 0x2004;
[32m    reg_read(uVar3,&local_c);[0m
    local_c = uVar2 << 8 | local_c & 0xfffffcff;
    reg_write(uVar3,local_c);
  }
  return;
}

[ASK_GPT] 192ac7799aa80fa9
