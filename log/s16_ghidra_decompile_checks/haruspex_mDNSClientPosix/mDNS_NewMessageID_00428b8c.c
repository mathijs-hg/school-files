
short * mDNS_NewMessageID(short *param_1,int param_2)

{
  short sVar2;
  undefined4 *puVar1;
  int iVar3;
  
  iVar3 = 0;
  do {
[32m    sVar2 = mDNSRandom(0xfffe);[0m
    *param_1 = sVar2 + 1;
    for (puVar1 = *(undefined4 **)(param_2 + 0x2160); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (*(short *)((int)puVar1 + 0xf2) == (short)(sVar2 + 1)) goto LAB_00428c4c;
    }
    puVar1 = *(undefined4 **)(param_2 + 0x2ac);
    while( true ) {
      if (puVar1 == (undefined4 *)0x0) {
        return param_1;
      }
      if (*(short *)((int)puVar1 + 0x152) == *param_1) break;
      puVar1 = (undefined4 *)*puVar1;
    }
LAB_00428c4c:
    iVar3 = iVar3 + 1;
    if (iVar3 == 10) {
      return param_1;
    }
  } while( true );
}

[ASK_GPT] 6288699585a6e7fc
