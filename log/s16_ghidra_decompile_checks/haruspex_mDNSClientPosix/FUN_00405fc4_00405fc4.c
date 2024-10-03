
int FUN_00405fc4(int param_1)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar3 = get_ifi_info(2,1);
  if (param_1 == 0) {
    __assert("m != ((void *)0)","mDNSPosix.c",0x3c0);
  }
  iVar7 = 2;
  iVar4 = iVar3;
  if (iVar3 != 0) {
    do {
      puVar8 = (undefined4 *)(iVar4 + 0x34);
      iVar4 = *(int *)(iVar4 + 0x34);
    } while (iVar4 != 0);
    iVar4 = 0;
    uVar5 = get_ifi_info(10,1);
    bVar2 = false;
    *puVar8 = uVar5;
    for (iVar7 = iVar3; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x34)) {
[32m      sVar1 = **(short **)(iVar7 + 0x24);[0m
      if (((sVar1 == 2) || (sVar1 == 10)) && ((*(ushort *)(iVar7 + 0x1a) & 0x11) == 1)) {
        if ((*(ushort *)(iVar7 + 0x1a) & 8) == 0) {
          iVar6 = FUN_00405bfc(param_1,*(short **)(iVar7 + 0x24),*(undefined4 *)(iVar7 + 0x28),iVar7
                               ,*(undefined4 *)(iVar7 + 0x20));
          if ((iVar6 == 0) && (**(short **)(iVar7 + 0x24) == 2)) {
            bVar2 = true;
          }
        }
        else if (iVar4 == 0) {
          iVar4 = iVar7;
        }
      }
    }
    if ((bVar2) || (iVar4 == 0)) {
      iVar7 = 0;
    }
    else {
      FUN_00405bfc(param_1,*(undefined4 *)(iVar4 + 0x24),*(undefined4 *)(iVar4 + 0x28),iVar4,
                   *(undefined4 *)(iVar4 + 0x20));
    }
  }
  if (iVar3 != 0) {
    free_ifi_info();
  }
  iVar3 = mDNSPlatformUTC();
  puVar8 = &DAT_0046e774;
  while (puVar9 = puVar8, puVar8 = (undefined4 *)*puVar9, puVar8 != (undefined4 *)0x0) {
    if (0x3b < iVar3 - puVar8[0x567]) {
      *puVar9 = *puVar8;
      free(puVar8);
      puVar8 = puVar9;
    }
  }
  return iVar7;
}

[ASK_GPT] d9b91a0e6ff59867
