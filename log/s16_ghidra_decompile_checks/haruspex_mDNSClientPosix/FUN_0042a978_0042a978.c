
byte * FUN_0042a978(byte *param_1,byte *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  undefined *puVar10;
  uint uVar11;
  char cVar13;
  uint uVar12;
  code *pcVar14;
  char local_18 [16];
  
  bVar2 = false;
  iVar3 = 0;
  bVar1 = false;
  uVar11 = 0;
  iVar5 = 0;
  while( true ) {
[32m    cVar13 = (char)(uVar11 >> 8);[0m
    if (param_2 <= param_1) break;
    uVar12 = (uint)*param_1;
    uVar8 = uVar12 - 0x30;
    if (uVar12 == 0x20) break;
    iVar9 = iVar5;
    if (((((uVar8 & 0xff) < 10) || (uVar8 = uVar12 - 0x37, (uVar12 - 0x41 & 0xff) < 6)) ||
        (uVar8 = uVar12 - 0x57, (uVar12 - 0x61 & 0xff) < 6)) && (uVar8 != 0xffffffff)) {
      bVar1 = true;
      uVar11 = uVar8 | uVar11 << 4;
    }
    else if (uVar12 == 0x3a) {
      if (bVar1) {
        if ((param_1 + 1 < param_2) && (param_1[1] == 0x20)) {
          LogMsgWithLevel(0,"GetValueForIPv6Addr: Trailing colon",iVar5 < 0xe,iVar5,&_gp);
          return (byte *)0x0;
        }
        if (0xd < iVar5) {
          pcVar7 = "GetValueForIPv6Addr:1: numBytes is %d";
          goto LAB_0042ab54;
        }
        iVar9 = iVar5 + 2;
        local_18[iVar5] = cVar13;
        local_18[iVar5 + 1] = (char)uVar11;
        if (iVar9 == 0xf) {
          pcVar7 = "GetValueForIPv6Addr:2: numBytes is %d";
          iVar9 = 0xf;
          goto LAB_0042ac28;
        }
        bVar1 = false;
        uVar11 = 0;
      }
      else {
        if (bVar2) {
          if (((iVar5 == 0) && (param_1 = param_1 + 1, param_1 < param_2)) && (*param_1 == 0x20)) {
            mDNSPlatformMemZero(param_3,0x10);
            return param_1;
          }
          pcVar7 = "GetValueForIPv6Addr: zeroFillStart non-zero %d";
          iVar5 = iVar3;
          goto LAB_0042ab54;
        }
        bVar2 = true;
        iVar3 = iVar5;
      }
    }
    param_1 = param_1 + 1;
    iVar5 = iVar9;
  }
  if (bVar1) {
    pcVar7 = local_18;
    if (iVar5 < 0xf) {
      iVar9 = iVar5 + 2;
      pcVar7[iVar5] = cVar13;
      local_18[iVar5 + 1] = (char)uVar11;
      if (iVar3 != 0) {
        iVar5 = 0;
        do {
          iVar4 = iVar5;
          iVar5 = iVar4 + 1;
          *(char *)(param_3 + iVar4) = pcVar7[iVar4];
        } while (iVar5 < iVar3);
        puVar10 = (undefined *)(param_3 + iVar5);
        iVar3 = 0;
        while (bVar1 = iVar3 < 0x10 - iVar9, iVar3 = iVar3 + 1, bVar1) {
          *puVar10 = 0;
          iVar5 = iVar5 + 1;
          puVar10 = puVar10 + 1;
        }
        pcVar6 = (char *)(param_3 + iVar5);
        pcVar7 = local_18 + iVar4 + 1;
        while (bVar1 = iVar5 < 0x10, iVar5 = iVar5 + 1, bVar1) {
          cVar13 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          *pcVar6 = cVar13;
          pcVar6 = pcVar6 + 1;
        }
        return param_1;
      }
      if (iVar9 == 0x10) {
        pcVar14 = mDNSPlatformMemCopy;
        iVar9 = 0x10;
      }
      else {
        pcVar7 = "GetValueForIPv6addr: Not enough bytes for IPv6 address, numBytes is %d";
LAB_0042ac28:
        pcVar14 = LogMsgWithLevel;
        param_3 = 0;
        param_1 = (byte *)0x0;
      }
      (*pcVar14)(param_3,pcVar7,iVar9);
      return param_1;
    }
    pcVar7 = "GetValueForIPv6Addr:3: numBytes is %d";
  }
  else {
    pcVar7 = "GetValueForIPv6Addr: no trailing bytes after colon, numBytes is %d";
  }
LAB_0042ab54:
  LogMsgWithLevel(0,pcVar7,iVar5);
  return (byte *)0x0;
}

[ASK_GPT] 37fee83eb18ec378
