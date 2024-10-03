
/* WARNING: Could not reconcile some variable overlaps */

void FUN_00401e50(int param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  char *__s;
  int iVar3;
  int iVar4;
  ushort local_40 [2];
  char *local_3c;
  char *local_38;
  undefined4 local_34;
  in_addr_t local_30;
  undefined4 local_2c;
  undefined4 local_28;
  char *local_20;
  
  iVar3 = *(int *)(param_1 + 0x20);
  ILibParseUri(*(undefined4 *)(param_1 + 0xc),&local_3c,local_40,&local_38);
  uVar1 = ILibCreateEmptyPacket();
  local_20 = local_38;
  sVar2 = strlen(local_38);
  ILibSetDirective(uVar1,"SUBSCRIBE",9,local_20,sVar2);
  sVar2 = strlen(local_3c);
[32m[32m[32m  __s = (char *)malloc(sVar2 + 7);[0m[0m[0m
[32m[32m  sprintf(__s,"%s:%d",local_3c,(uint)local_40[0]);[0m[0m
  sVar2 = strlen(__s);
  ILibAddHeaderLine(uVar1,&DAT_004159d4,4,__s,sVar2);
  free(__s);
  local_20 = *(char **)(param_1 + 0x14);
  sVar2 = strlen(local_20);
  ILibAddHeaderLine(uVar1,&DAT_004159dc,3,local_20,sVar2);
  ILibAddHeaderLine(uVar1,"TIMEOUT",7,"Second-180",10);
  ILibAddHeaderLine(uVar1,"User-Agent",10,"POSIX, UPnP/1.0, xxxxxxxxxxxxxxxxxxxxxxxxx",0x2a);
  local_30 = 0;
  local_34._2_2_ = 0;
  local_34._0_2_ = 2;
  local_2c = 0;
  local_28 = 0;
  local_30 = inet_addr(local_3c);
  local_34 = CONCAT22(local_34._0_2_,local_40[0]);
  ILibAddRequest(*(undefined4 *)(**(int **)(param_1 + 0x20) + 0x2c),uVar1,&local_34,FUN_0040be80,
                 param_1,**(int **)(param_1 + 0x20));
  do {
    iVar4 = iVar3;
    iVar3 = *(int *)(iVar4 + 0x4c);
  } while (*(int *)(iVar4 + 0x4c) != 0);
  *(int *)(iVar4 + 0x3c) = *(int *)(iVar4 + 0x3c) + -1;
  free(local_3c);
  free(local_38);
  return;
}

[ASK_GPT] 5e0b339a3067097a
