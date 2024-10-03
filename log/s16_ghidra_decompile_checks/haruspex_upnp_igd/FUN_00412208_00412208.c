
uint FUN_00412208(void *param_1,size_t param_2)

{
  uint uVar1;
  uint local_20 [3];
  
  if ((int)param_2 < 5) {
    local_20[0] = 0;
[32m    memcpy(local_20,param_1,param_2);[0m
    uVar1 = local_20[0];
  }
  else {
[32m[32m    memcpy(local_20,param_1,4);[0m[0m
    uVar1 = local_20[0];
[32m[32m    memcpy(local_20,(void *)((int)param_1 + (param_2 - 4)),4);[0m[0m
    uVar1 = uVar1 ^ local_20[0];
    if (9 < (int)param_2) {
[32m[32m      memcpy(local_20,(void *)((int)param_1 + ((int)param_2 >> 1)),4);[0m[0m
      uVar1 = uVar1 ^ local_20[0];
    }
  }
  return uVar1;
}

[ASK_GPT] e412849467400ded
