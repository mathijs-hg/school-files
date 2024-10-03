
code ** ILibCreateHTTPClientModule(code *param_1,code *param_2)

{
  bool bVar1;
  code **ppcVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  timeval local_20;
  size_t local_18;
  
[32m[32m[32m  ppcVar2 = (code **)malloc(0x4c);[0m[0m[0m
  gettimeofday(&local_20,(__timezone_ptr_t)0x0);
[32m[32m  srand(local_20.tv_sec);[0m[0m
[32m  local_18 = (int)param_2 * 0x850;[0m
  ppcVar2[0xc] = (code *)0x0;
  ppcVar2[0x10] = (code *)0x0;
  ppcVar2[0xe] = param_2;
  ppcVar2[0xd] = (code *)0x0;
[32m[32m[32m  pcVar3 = (code *)malloc(local_18);[0m[0m[0m
  ppcVar2[0xf] = pcVar3;
  memset(pcVar3,0,local_18);
  iVar4 = 0;
  while( true ) {
    iVar5 = iVar4 * 0x850;
    bVar1 = (int)param_2 <= iVar4;
    iVar4 = iVar4 + 1;
    if (bVar1) break;
    *(undefined4 *)(ppcVar2[0xf] + iVar5 + 0x824) = 0xffffffff;
    *(code ***)(ppcVar2[0xf] + iVar5 + 0x830) = ppcVar2;
  }
  sem_init((sem_t *)(ppcVar2 + 4),0,1);
  sem_init((sem_t *)(ppcVar2 + 8),0,0);
  *ppcVar2 = FUN_0040e2b8;
  ppcVar2[1] = FUN_0040dcc0;
  ppcVar2[3] = param_1;
  ppcVar2[2] = FUN_0040e55c;
  pcVar3 = (code *)ILibCreateLifeTime(param_1);
  ppcVar2[0x12] = pcVar3;
  ILibAddToChain(param_1,ppcVar2);
  return ppcVar2;
}

[ASK_GPT] f81f3fe07e7c5af7
