
void * ILibCreateEmptyPacket(void)

{
  void *__s;
  
[32m[32m[32m  __s = malloc(0x44);[0m[0m[0m
[32m  memset(__s,0,0x44);[0m
  *(undefined **)((int)__s + 0x1c) = &DAT_00416d40;
  *(undefined4 *)((int)__s + 0x10) = 0xffffffff;
  *(undefined4 *)((int)__s + 0x20) = 3;
  *(undefined4 *)((int)__s + 0x2c) = 0xffffffff;
  return __s;
}

[ASK_GPT] 1b0e80bd711c6127
