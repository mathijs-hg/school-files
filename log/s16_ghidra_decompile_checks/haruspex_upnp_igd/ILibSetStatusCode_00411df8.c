
void ILibSetStatusCode(int param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  void *__dest;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
[32m[32m[32m  __dest = malloc(param_4 + 1);[0m[0m[0m
  *(void **)(param_1 + 0x14) = __dest;
[32m  memcpy(__dest,param_3,param_4);[0m
  *(undefined *)(*(int *)(param_1 + 0x14) + param_4) = 0;
  *(size_t *)(param_1 + 0x18) = param_4;
  return;
}

[ASK_GPT] bc223e99312150d8
