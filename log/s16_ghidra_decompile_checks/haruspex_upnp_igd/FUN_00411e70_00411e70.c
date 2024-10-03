
void FUN_00411e70(int param_1,void *param_2,size_t param_3)

{
  void *__dest;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    free(*(void **)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x30) = 1;
[32m[32m[32m  __dest = malloc(param_3 + 1);[0m[0m[0m
  *(void **)(param_1 + 0x1c) = __dest;
[32m  memcpy(__dest,param_2,param_3);[0m
  *(undefined *)(*(int *)(param_1 + 0x1c) + param_3) = 0;
  return;
}

[ASK_GPT] 14dbf86d1186159b
