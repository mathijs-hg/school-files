
code ** ILibCreateMiniWebServer
                  (undefined4 param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  code **ppcVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
[32m[32m[32m  ppcVar2 = (code **)malloc(0x24);[0m[0m[0m
  ppcVar2[5] = param_2;
[32m[32m[32m  pcVar3 = (code *)malloc((int)param_2 * 0x838);[0m[0m[0m
  *ppcVar2 = FUN_0040ea7c;
  ppcVar2[1] = FUN_0040f35c;
  ppcVar2[2] = FUN_0040ebd0;
  ppcVar2[3] = pcVar3;
  ppcVar2[7] = (code *)0x0;
  memset(pcVar3,0,(int)param_2 * 0x838);
  iVar4 = 0;
  while( true ) {
    iVar5 = iVar4 * 0x838;
    bVar1 = (int)param_2 <= iVar4;
    iVar4 = iVar4 + 1;
    if (bVar1) break;
    *(undefined4 *)(ppcVar2[3] + iVar5 + 0x824) = 0xffffffff;
    *(undefined4 *)(ppcVar2[3] + iVar5 + 0x834) = param_3;
    *(code ***)(ppcVar2[3] + iVar5 + 0x82c) = ppcVar2;
    *(undefined4 *)(ppcVar2[3] + iVar5 + 0x830) = param_4;
  }
  *(undefined2 *)(ppcVar2 + 6) = 0;
  pcVar3 = (code *)ILibCreateLifeTime(param_1);
  ppcVar2[8] = pcVar3;
  ILibAddToChain(param_1,ppcVar2);
  return ppcVar2;
}

[ASK_GPT] 9ddb885122cc3677
