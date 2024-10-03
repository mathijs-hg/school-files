
/* WARNING: Could not reconcile some variable overlaps */

void FUN_00405070(int param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  char *pcVar3;
  size_t sVar4;
  undefined4 uVar5;
  ushort local_40 [2];
  char *local_3c;
  char *local_38;
  undefined4 local_34;
  in_addr_t local_30;
  undefined4 local_2c;
  undefined4 local_28;
  char *local_20;
  
  printf("subscribe: URL:[%s]\n",*(undefined4 *)(param_1 + 0xc));
  ILibParseUri(*(undefined4 *)(param_1 + 0xc),&local_3c,local_40,&local_38);
  uVar1 = ILibCreateEmptyPacket();
  local_20 = local_38;
  sVar2 = strlen(local_38);
  ILibSetDirective(uVar1,"SUBSCRIBE",9,local_20,sVar2);
  sVar2 = strlen(local_3c);
[32m[32m[32m  pcVar3 = (char *)malloc(sVar2 + 7);[0m[0m[0m
[32m[32m  sprintf(pcVar3,"%s:%d",local_3c,(uint)local_40[0]);[0m[0m
  sVar2 = strlen(pcVar3);
  ILibAddHeaderLine(uVar1,&DAT_004159d4,4,pcVar3,sVar2);
  free(pcVar3);
  ILibAddHeaderLine(uVar1,&DAT_00415ca8,2,"upnp:event",10);
  ILibAddHeaderLine(uVar1,"TIMEOUT",7,"Second-180",10);
  ILibAddHeaderLine(uVar1,"User-Agent",10,"POSIX, UPnP/1.0, xxxxxxxxxxxxxxxxxxxxxxxxx",0x2a);
[32m  sVar2 = strlen(*(char **)(*(int *)(param_1 + 0x20) + 0x40));[0m
  sVar4 = strlen(local_38);
[32m[32m[32m  pcVar3 = (char *)malloc(sVar2 + sVar4 + 0x10);[0m[0m[0m
  local_20 = (char *)(*(int **)(param_1 + 0x20))[0x10];
  uVar5 = ILibGetMiniWebServerPortNumber(*(undefined4 *)(**(int **)(param_1 + 0x20) + 0x34));
[32m[32m  sprintf(pcVar3,"<http://%s:%d%s>",local_20,uVar5,local_38);[0m[0m
  sVar2 = strlen(pcVar3);
  ILibAddHeaderLine(uVar1,"CALLBACK",8,pcVar3,sVar2);
  free(pcVar3);
  local_30 = 0;
  local_34._2_2_ = 0;
  local_34._0_2_ = 2;
  local_2c = 0;
  local_28 = 0;
  local_30 = inet_addr(local_3c);
  local_34 = CONCAT22(local_34._0_2_,local_40[0]);
  FUN_00405000(*(undefined4 *)(param_1 + 0x20));
  ILibAddRequest(*(undefined4 *)(**(int **)(param_1 + 0x20) + 0x2c),uVar1,&local_34,FUN_0040be80,
                 param_1,**(int **)(param_1 + 0x20));
  free(local_3c);
  free(local_38);
  return;
}

[ASK_GPT] 0b655c666d66b838
