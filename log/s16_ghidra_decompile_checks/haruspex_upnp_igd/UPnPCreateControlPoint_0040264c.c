
code ** UPnPCreateControlPoint(code *param_1,code *param_2,code *param_3)

{
  code **ppcVar1;
  code *pcVar2;
  size_t sVar3;
  
[32m[32m[32m  ppcVar1 = (code **)malloc(0x5c);[0m[0m[0m
  ppcVar1[2] = FUN_00409050;
  ppcVar1[3] = param_2;
  ppcVar1[4] = param_3;
  *ppcVar1 = FUN_00408eac;
  ppcVar1[1] = (code *)0x0;
  sem_init((sem_t *)(ppcVar1 + 0xe),0,1);
  ppcVar1[9] = (code *)0x0;
  pcVar2 = (code *)ILibCreateMiniWebServer(param_1,5,FUN_00402e04,ppcVar1);
  ppcVar1[0xd] = pcVar2;
  pcVar2 = (code *)ILibInitHashTree();
  ppcVar1[0x12] = pcVar2;
  sVar3 = strlen(DeviceType);
  pcVar2 = (code *)ILibCreateSSDPClientModule(param_1,DeviceType,sVar3,FUN_0040c89c,ppcVar1);
  ppcVar1[0xc] = pcVar2;
  pcVar2 = (code *)ILibCreateHTTPClientModule(param_1,5);
  ppcVar1[0xb] = pcVar2;
  ILibAddToChain(param_1,ppcVar1);
  pcVar2 = (code *)ILibCreateLifeTime(param_1);
  ppcVar1[0x13] = param_1;
  ppcVar1[10] = pcVar2;
  ppcVar1[0x14] = (code *)0x0;
  pcVar2 = (code *)ILibGetLocalIPAddressList(ppcVar1 + 0x16);
  ppcVar1[0x15] = pcVar2;
  return ppcVar1;
}

[ASK_GPT] 7d63331e238cba52
