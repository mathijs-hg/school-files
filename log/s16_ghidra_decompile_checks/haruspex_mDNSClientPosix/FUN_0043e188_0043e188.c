
void FUN_0043e188(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  iVar5 = *(int *)(param_1 + 0x216c);
  if (iVar5 != 0) {
    uVar3 = GetRRDisplayString_rdb(iVar5 + 4,*(int *)(iVar5 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,"ClearIdenticalProxyRecords ERROR m->CurrentRecord already set %s",uVar3);
  }
  *(undefined4 *)(param_1 + 0x216c) = param_3;
  while (puVar7 = *(undefined4 **)(param_1 + 0x216c), puVar7 != (undefined4 *)0x0) {
    if ((((param_4 == puVar7[7]) && (*(short *)((int)puVar7 + 0x4e) == *(short *)(param_2 + 2))) &&
        (*(short *)(puVar7 + 0x14) == *(short *)(param_2 + 4))) &&
       ((*(short *)((int)puVar7 + 0x52) == *(short *)(param_2 + 6) &&
        (*(short *)(param_1 + 0x7fae) == 10)))) {
      uVar4 = (uint)**(byte **)(param_1 + 0x7fc8);
      iVar5 = uVar4 + 1;
      if (uVar4 == 0) {
        iVar5 = 0;
      }
      iVar5 = SameDomainLabel(*(byte **)(param_1 + 0x7fc8) + iVar5,"\n_keepalive");
      if (iVar5 != 0) {
        if (mDNS_LoggingEnabled != 0) {
          uVar6 = *(undefined4 *)(param_1 + 0x38e0);
[32m          cVar1 = *(char *)((int)puVar7 + 0x4d);[0m
[32m          cVar2 = *(char *)(param_2 + 1);[0m
          uVar3 = GetRRDisplayString_rdb(puVar7 + 1,puVar7[9] + 4,param_1 + 0x2f);
          LogMsgWithLevel(2,
                          "ClearKeepaliveProxyRecords: Removing %3d H-MAC %.6a I-MAC %.6a %d %d %s",
                          uVar6,(int)puVar7 + 0x4e,puVar7 + 0x15,(int)cVar1,(int)cVar2,uVar3);
        }
        FUN_0043e0f8(param_1,puVar7);
      }
    }
    if (*(undefined4 **)(param_1 + 0x216c) == puVar7) {
      *(undefined4 *)(param_1 + 0x216c) = *puVar7;
    }
  }
  return;
}

[ASK_GPT] 33393d7b4e694c87
