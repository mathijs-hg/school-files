
void FUN_00434f7c(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined auStack_40 [24];
  undefined *local_28;
  
  local_28 = auStack_40;
[32m[32m  memcpy(auStack_40,zeroOwner,0x14);[0m[0m
  FUN_004344b8(param_1,param_2,param_3 & 0xffff0000,local_28);
  puVar2 = *(undefined4 **)(param_1 + 0x2160);
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    iVar1 = mDNSPlatformMemSame(auStack_40,puVar2 + 0x13,0x14);
    if (iVar1 == 0) {
      for (puVar3 = *(undefined4 **)(param_1 + 0x2160);
          (puVar3 != (undefined4 *)0x0 && (puVar3 != puVar2)); puVar3 = (undefined4 *)*puVar3) {
        iVar1 = mDNSPlatformMemSame(puVar2 + 0x13,puVar3 + 0x13,0x14);
        if (iVar1 != 0) goto LAB_00435064;
      }
[32m[32m      memcpy(auStack_40,puVar2 + 0x13,0x14);[0m[0m
      FUN_004344b8(param_1,param_2,param_3 & 0xffff0000,auStack_40);
    }
LAB_00435064:
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}

[ASK_GPT] e2929e51d1baca24
