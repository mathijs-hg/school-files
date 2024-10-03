
uint FUN_00410730(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = LocateAdditionals(param_2,param_3);
  if (iVar2 != 0) {
    iVar5 = 0;
    while( true ) {
      bVar1 = (int)(uint)*(ushort *)(param_2 + 10) <= iVar5;
      iVar5 = iVar5 + 1;
      if (bVar1) break;
      iVar2 = GetLargeResourceRecord(param_1,param_2,iVar2,param_3,0,0x80,param_1 + 0x7fa8);
      if (iVar2 == 0) break;
      if ((*(char *)(param_1 + 0x7fac) != -0x10) && (*(short *)(param_1 + 0x7fae) == 0xfa)) {
        iVar5 = *(int *)(param_1 + 0x7fcc);
        uVar4 = iVar5 + (uint)*(ushort *)(param_1 + 0x7fb8) + 4;
        iVar2 = DomainNameLengthLimit(iVar5 + 4,uVar4);
        iVar5 = iVar5 + iVar2;
        if ((((iVar2 < 0x101) && (iVar5 + 10U <= uVar4)) && (iVar5 + 0xcU <= uVar4)) &&
           (iVar5 + 0xeU <= uVar4)) {
          uVar3 = iVar5 + 0xeU + (uint)*(ushort *)(iVar5 + 0xc);
[32m          if (((uVar3 <= uVar4) && (uVar3 + 2 <= uVar4)) && (uVar3 + 4 <= uVar4)) {[0m
            uVar4 = (uint)*(ushort *)(uVar3 + 2);
            if (uVar4 == 0x10) {
              LogMsgWithLevel(0,"%##s: bad signature",param_4);
              uVar4 = 0xfffeffe8;
            }
            else if (uVar4 == 0x11) {
              LogMsgWithLevel(0,"%##s: bad key",param_4);
              uVar4 = 0xfffeffe7;
            }
            else if (uVar4 == 0x12) {
              LogMsgWithLevel(0,"%##s: bad time",param_4);
              uVar4 = 0xfffeffe9;
            }
            else if (uVar4 != 0) {
              LogMsgWithLevel(0,"%##s: unknown tsig error %d",param_4,uVar4);
              uVar4 = 0xfffeffff;
            }
            goto LAB_0041094c;
          }
        }
        break;
      }
      *(undefined *)(param_1 + 0x7fac) = 0;
    }
  }
  uVar4 = 0;
LAB_0041094c:
  *(undefined *)(param_1 + 0x7fac) = 0;
  return uVar4;
}

[ASK_GPT] b423b6a3ec18b029
