
void FUN_0043e3a4(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  iVar4 = *(int *)(param_1 + 0x216c);
  if (iVar4 != 0) {
    uVar3 = GetRRDisplayString_rdb(iVar4 + 4,*(int *)(iVar4 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,"ClearIdenticalProxyRecords ERROR m->CurrentRecord already set %s",uVar3);
  }
  *(undefined4 *)(param_1 + 0x216c) = param_3;
  while (puVar5 = *(undefined4 **)(param_1 + 0x216c), puVar5 != (undefined4 *)0x0) {
    if ((((((*(int *)(param_1 + 0x7fc4) == puVar5[7]) &&
           (*(short *)((int)puVar5 + 0x4e) == *(short *)(param_2 + 2))) &&
          (*(short *)(puVar5 + 0x14) == *(short *)(param_2 + 4))) &&
         ((*(short *)((int)puVar5 + 0x52) == *(short *)(param_2 + 6) &&
          (*(short *)((int)puVar5 + 6) == *(short *)(param_1 + 0x7fae))))) &&
        ((*(short *)(puVar5 + 2) == *(short *)(param_1 + 0x7fb0) &&
         ((puVar5[5] == *(int *)(param_1 + 0x7fbc) &&
          (*(short *)(puVar5 + 4) == *(short *)(param_1 + 0x7fb8))))))) &&
       (puVar5[6] == *(int *)(param_1 + 0x7fc0))) {
      iVar4 = SameRDataBody(puVar5 + 1,*(int *)(param_1 + 0x7fcc) + 4,SameDomainName);
      if (iVar4 != 0) {
        iVar4 = SameDomainName(puVar5[8],*(undefined4 *)(param_1 + 0x7fc8));
        if (iVar4 != 0) {
          if (mDNS_LoggingEnabled != 0) {
            uVar6 = *(undefined4 *)(param_1 + 0x38e0);
[32m            cVar1 = *(char *)((int)puVar5 + 0x4d);[0m
[32m            cVar2 = *(char *)(param_2 + 1);[0m
            uVar3 = GetRRDisplayString_rdb(puVar5 + 1,puVar5[9] + 4,param_1 + 0x2f);
            LogMsgWithLevel(2,
                            "ClearIdenticalProxyRecords: Removing %3d H-MAC %.6a I-MAC %.6a %d %d %s"
                            ,uVar6,(int)puVar5 + 0x4e,puVar5 + 0x15,(int)cVar1,(int)cVar2,uVar3);
          }
          FUN_0043e0f8(param_1,puVar5);
        }
      }
    }
    if (*(undefined4 **)(param_1 + 0x216c) == puVar5) {
      *(undefined4 *)(param_1 + 0x216c) = *puVar5;
    }
  }
  return;
}

[ASK_GPT] 51e136898d1f4eea
