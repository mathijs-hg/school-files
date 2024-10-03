
void FUN_0043cad4(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  undefined uVar3;
  undefined uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  
  iVar6 = *(int *)(param_1 + 0x216c);
  if (iVar6 != 0) {
    uVar5 = GetRRDisplayString_rdb(iVar6 + 4,*(int *)(iVar6 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,"ClearProxyRecords ERROR m->CurrentRecord already set %s",uVar5);
  }
  *(undefined4 *)(param_1 + 0x216c) = param_3;
  do {
    puVar8 = *(undefined4 **)(param_1 + 0x216c);
    if (puVar8 == (undefined4 *)0x0) {
      return;
    }
    if ((((*(int *)(param_1 + 0x7fc4) == puVar8[7]) &&
         (*(short *)((int)puVar8 + 0x4e) == *(short *)(param_2 + 2))) &&
        (*(short *)(puVar8 + 0x14) == *(short *)(param_2 + 4))) &&
       (*(short *)((int)puVar8 + 0x52) == *(short *)(param_2 + 6))) {
[32m      cVar1 = *(char *)(param_2 + 1);[0m
[32m      cVar2 = *(char *)((int)puVar8 + 0x4d);[0m
      if (((int)cVar1 != (int)cVar2) ||
         (mDNSPlatformOneSecond * 0x3c < *(int *)(param_1 + 0x234) - puVar8[0x1d])) {
        if (mDNS_LoggingEnabled != 0) {
          uVar7 = *(undefined4 *)(param_1 + 0x38e0);
          uVar3 = *(undefined *)((int)puVar8 + 0x87);
          uVar4 = *(undefined *)(puVar8 + 1);
          uVar5 = GetRRDisplayString_rdb(puVar8 + 1,puVar8[9] + 4,param_1 + 0x2f);
          LogMsgWithLevel(2,
                          "ClearProxyRecords: Removing %3d AC %2d %02X H-MAC %.6a I-MAC %.6a %d %d %s"
                          ,uVar7,uVar3,uVar4,(int)puVar8 + 0x4e,puVar8 + 0x15,(int)cVar2,(int)cVar1,
                          uVar5);
        }
        if (*(char *)(puVar8 + 1) == '\x01') {
          *(undefined *)(puVar8 + 1) = 8;
        }
[32m[32m        memcpy((void *)((int)puVar8 + 0x4e),&zeroEthAddr,6);[0m[0m
        *(undefined *)(puVar8 + 0x22) = 0;
        mDNS_Deregister_internal(param_1,puVar8,0);
        if (*(int *)(param_1 + 0x2aa4) == 0) {
LAB_0043ccf8:
          iVar6 = *(int *)(param_1 + 0x7fc4);
        }
        else {
          iVar6 = *(int *)(param_1 + 0x7fc4);
          if (*(int *)(param_1 + 0x2aa4) != iVar6) {
            mDNSPlatformUpdateProxyList(param_1);
            goto LAB_0043ccf8;
          }
        }
        *(int *)(param_1 + 0x2aa4) = iVar6;
      }
    }
    if (*(undefined4 **)(param_1 + 0x216c) == puVar8) {
      *(undefined4 *)(param_1 + 0x216c) = *puVar8;
    }
  } while( true );
}

[ASK_GPT] ca6c459a2986b1d0
