
undefined4 FUN_00405cf8(char *param_1,undefined2 *param_2)

{
  char *pcVar1;
  char cVar2;
  byte bVar6;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  int iVar7;
  undefined2 *puVar8;
  
  *param_2 = 1;
  puVar8 = param_2 + 1;
  do {
    uVar5 = (uint)*param_1;
    if ((uVar5 == 0) || (puVar8 == param_2 + 4)) {
      return 0;
    }
    iVar7 = uVar5 - 0x30;
    if ((*(ushort *)(__ctype_b + uVar5 * 2) & 8) == 0) {
      iVar7 = uVar5 - 0x57;
      if ((5 < ((uVar5 & 0xff) - 0x61 & 0xff)) &&
         (iVar7 = uVar5 - 0x37, 5 < ((uVar5 & 0xff) - 0x41 & 0xff))) goto LAB_00405dec;
    }
[32m    cVar2 = param_1[1];[0m
    if ((*(ushort *)(__ctype_b + cVar2 * 2) & 8) == 0) {
      uVar5 = (int)cVar2 & 0xff;
      if ((uVar5 - 0x61 & 0xff) < 6) {
        bVar6 = cVar2 + 0xa9;
      }
      else {
        if (5 < (uVar5 - 0x41 & 0xff)) {
LAB_00405dec:
          piVar4 = __errno_location();
          *piVar4 = 0x16;
          return 0xffffffff;
        }
        bVar6 = cVar2 - 0x37;
      }
    }
    else {
      bVar6 = cVar2 - 0x30;
    }
    *(byte *)puVar8 = (byte)(iVar7 << 4) | bVar6;
    pcVar3 = param_1 + 3;
    pcVar1 = param_1 + 2;
    puVar8 = (undefined2 *)((int)puVar8 + 1);
    param_1 = param_1 + 2;
    if (*pcVar1 == ':') {
      param_1 = pcVar3;
    }
  } while( true );
}

[ASK_GPT] 51db6fb4c1bd564c
