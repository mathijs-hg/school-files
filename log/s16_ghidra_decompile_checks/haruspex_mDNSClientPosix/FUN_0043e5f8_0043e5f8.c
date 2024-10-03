
void FUN_0043e5f8(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  *(undefined4 *)(param_1 + 0x216c) = param_2;
  do {
    puVar4 = *(undefined4 **)(param_1 + 0x216c);
    if (puVar4 == (undefined4 *)0x0) {
      return;
    }
    if ((*(char *)(puVar4 + 1) != '\x01') && (*(int *)((int)puVar4 + 0x4e) != 0)) {
      if ((*(int *)(param_1 + 0x2aa8) == 0) ||
         (iVar2 = puVar4[0x1e], -1 < *(int *)(param_1 + 0x234) - iVar2)) {
        if (mDNS_LoggingEnabled != 0) {
          uVar5 = *(undefined4 *)(param_1 + 0x38e0);
[32m          cVar1 = *(char *)((int)puVar4 + 0x4d);[0m
          uVar3 = GetRRDisplayString_rdb(puVar4 + 1,puVar4[9] + 4,param_1 + 0x2f);
          LogMsgWithLevel(2,"CheckProxyRecords: Removing %d H-MAC %.6a I-MAC %.6a %d %s",uVar5,
                          (int)puVar4 + 0x4e,puVar4 + 0x15,(int)cVar1,uVar3);
        }
        if (*(int *)(param_1 + 0x2aa4) == 0) {
LAB_0043e71c:
          iVar2 = puVar4[7];
        }
        else {
          iVar2 = puVar4[7];
          if (*(int *)(param_1 + 0x2aa4) != iVar2) {
            mDNSPlatformUpdateProxyList(param_1);
            goto LAB_0043e71c;
          }
        }
        *(int *)(param_1 + 0x2aa4) = iVar2;
        mDNS_Deregister_internal(param_1,puVar4,0);
      }
      else if (0 < *(int *)(param_1 + 0x25c) - iVar2) {
        *(int *)(param_1 + 0x25c) = iVar2;
      }
    }
    if (*(undefined4 **)(param_1 + 0x216c) == puVar4) {
      *(undefined4 *)(param_1 + 0x216c) = *puVar4;
    }
  } while( true );
}

[ASK_GPT] 3427089c81e2fb2b
