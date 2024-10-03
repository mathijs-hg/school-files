
void FUN_004082d8(void *param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = 0;
  pvVar1 = param_1;
  do {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      free(*(void **)((int)pvVar1 + 4));
    }
    if (*(void **)((int)pvVar1 + 0x204) != (void *)0x0) {
      free(*(void **)((int)pvVar1 + 0x204));
    }
    iVar2 = iVar2 + 1;
    pvVar1 = (void *)((int)pvVar1 + 4);
  } while (iVar2 != 0x80);
[32m  memset(param_1,0,0x404);[0m
  return;
}

[ASK_GPT] f62bb4a84eebf173
