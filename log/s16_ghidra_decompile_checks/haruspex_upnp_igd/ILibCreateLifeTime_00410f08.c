
code ** ILibCreateLifeTime(code *param_1)

{
  code **ppcVar1;
  
[32m[32m[32m  ppcVar1 = (code **)malloc(0x28);[0m[0m[0m
  *ppcVar1 = FUN_004123d4;
  ppcVar1[4] = param_1;
  ppcVar1[2] = FUN_0041109c;
  ppcVar1[3] = (code *)0x0;
  ppcVar1[1] = (code *)0x0;
  ppcVar1[5] = (code *)0x0;
  sem_init((sem_t *)(ppcVar1 + 6),0,1);
  ILibAddToChain(param_1,ppcVar1);
  return ppcVar1;
}

[ASK_GPT] a1abaf6a341905bb
