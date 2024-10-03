
void FUN_0041e054(byte *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  while( true ) {
    if (param_2 < 1) {
      return;
    }
    iVar6 = param_2 + -2;
    if (param_2 < 3) break;
    uVar4 = (uint)param_1[1];
    if (((iVar6 < (int)uVar4) || (uVar4 == 0)) || (uVar7 = (uint)*param_1 << 8, 0x20 < uVar4)) {
      if (mDNS_LoggingEnabled == 0) {
        return;
      }
                    /* WARNING: Treating indirect jump as call */
      LogMsgWithLevel(3,"PrintTypeBitmap: malformed nsec, bitmaplen %d wlen %d",iVar6,uVar4);
      return;
    }
    uVar5 = 0;
    do {
      iVar3 = (int)uVar5 >> 3;
      uVar1 = uVar5 & 7;
      uVar5 = uVar5 + 1;
      if (((uint)param_1[iVar3 + 2] & 0x80 >> uVar1) != 0) {
        uVar2 = DNSTypeName(uVar7);
[32m        iVar3 = mDNS_snprintf(param_3 + param_4,0x1ff - param_4,"%s ",uVar2);[0m
        param_4 = param_4 + iVar3;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while ((int)uVar5 < (int)(uVar4 << 3));
    param_2 = iVar6 - uVar4;
    param_1 = param_1 + uVar4 + 2;
  }
                    /* WARNING: Treating indirect jump as call */
  LogMsgWithLevel(0,"PrintTypeBitmap: malformed bitmap, bitmaplen %d short",param_2);
  return;
}

[ASK_GPT] a2ead068173d45a7
