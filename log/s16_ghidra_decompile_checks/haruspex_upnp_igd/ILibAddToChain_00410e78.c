
void ILibAddToChain(void *param_1,undefined4 param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  do {
    pvVar2 = param_1;
    param_1 = *(void **)((int)pvVar2 + 0xc);
  } while (*(void **)((int)pvVar2 + 0xc) != (void *)0x0);
  pvVar1 = pvVar2;
  if (*(int *)((int)pvVar2 + 8) != 0) {
[32m[32m[32m    pvVar1 = malloc(0x10);[0m[0m[0m
    *(void **)((int)pvVar2 + 0xc) = pvVar1;
  }
  *(undefined4 *)((int)pvVar1 + 8) = param_2;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  return;
}

[ASK_GPT] a703394f50a6bc64
