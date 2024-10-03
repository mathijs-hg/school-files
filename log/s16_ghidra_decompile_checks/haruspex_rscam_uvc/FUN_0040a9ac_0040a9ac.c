
short FUN_0040a9ac(int param_1,byte param_2)

{
  int local_14;
  short local_10;
  
[32m  local_10 = 3;[0m
  if (param_1 == 0) {
[32m    local_10 = 0;[0m
  }
  else {
    for (local_14 = 0; local_14 < (int)(uint)param_2; local_14 = local_14 + 1) {
[32m      local_10 = *(short *)(param_1 + local_14 * 0xc + 4) * 3 + local_10 + 3;[0m
    }
  }
  return local_10;
}

[ASK_GPT] 1d05aad7dc6ce128
