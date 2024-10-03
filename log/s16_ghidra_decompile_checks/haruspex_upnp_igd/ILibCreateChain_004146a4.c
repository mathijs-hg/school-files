
undefined4 * ILibCreateChain(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint __seed;
  int iVar3;
  
[32m[32m[32m  puVar2 = (undefined4 *)malloc(0x10);[0m[0m[0m
  __seed = time((time_t *)0x0);
[32m[32m  srand(__seed);[0m[0m
  puVar2[2] = 0;
  puVar2[3] = 0;
  iVar3 = socket(2,1,0);
  iVar1 = DAT_00427680;
  puVar2[1] = iVar3;
  *puVar2 = 0;
  if (iVar1 == 0) {
    sem_init((sem_t *)&DAT_00427688,0,1);
  }
  return puVar2;
}

[ASK_GPT] f7531d9636036e86
