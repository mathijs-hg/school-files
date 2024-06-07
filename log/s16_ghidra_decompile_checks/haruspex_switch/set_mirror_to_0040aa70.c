
void set_mirror_to(undefined4 param_1,int param_2)

{
  ulong uVar1;
  uint local_c;
  
  uVar1 = strtoul(*(char **)(param_2 + 0xc),(char **)0x0,0);
  if (((int)uVar1 < 0) || (6 < (int)uVar1)) {
    printf("wrong port member, should be within 0~%d\n",6);
  }
  else {
[32m    reg_read(0x10,&local_c);[0m
    local_c = local_c & 0xfffffff8 | 8 | uVar1;
    reg_write(0x10,local_c);
  }
  return;
}

[ASK_GPT] d6afea6058a21937
