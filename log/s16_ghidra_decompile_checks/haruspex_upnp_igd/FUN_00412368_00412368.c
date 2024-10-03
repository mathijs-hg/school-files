
undefined4 * FUN_00412368(void)

{
  undefined4 *puVar1;
  
[32m[32m[32m  puVar1 = (undefined4 *)malloc(0x18);[0m[0m[0m
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  sem_init((sem_t *)(puVar1 + 2),0,1);
  return puVar1;
}

[ASK_GPT] 31ab3da2c803cae8
