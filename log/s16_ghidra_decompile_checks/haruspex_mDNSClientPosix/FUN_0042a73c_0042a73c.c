
undefined4 FUN_0042a73c(int param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(param_1 + 0x2160);
  do {
    if (puVar4 == (undefined4 *)0x0) {
      return 0;
    }
[32m    sVar1 = *(short *)((int)puVar4 + 6);[0m
    if (sVar1 == 10) {
      uVar2 = (uint)*(byte *)puVar4[8];
      iVar3 = uVar2 + 1;
      if (uVar2 == 0) {
        iVar3 = 0;
      }
      iVar3 = SameDomainLabel((byte *)puVar4[8] + iVar3,"\n_keepalive");
      if (iVar3 != 0) {
        return 1;
      }
[32m      sVar1 = *(short *)((int)puVar4 + 6);[0m
    }
    if (((sVar1 == 0x21) &&
        (((puVar4[7] != 0 || (*(char *)((int)puVar4 + 0x4a) != '\0')) ||
         (iVar3 = IsLocalDomain(puVar4[8]), iVar3 != 0)))) && (*(short *)(puVar4[9] + 8) != 9)) {
      return 1;
    }
    puVar4 = (undefined4 *)*puVar4;
  } while( true );
}

[ASK_GPT] 770d314807742e68
