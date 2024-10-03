
undefined4 * ILibInitHashTree(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
[32m[32m[32m  puVar1 = (undefined4 *)malloc(0x14);[0m[0m[0m
[32m[32m[32m  puVar2 = (undefined4 *)malloc(0x18);[0m[0m[0m
  *puVar1 = puVar2;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  sem_init((sem_t *)(puVar1 + 1),0,1);
  return puVar1;
}

[ASK_GPT] 67567c033d82da49
