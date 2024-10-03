
void FUN_0040f678(int *param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_4 = param_4 + param_3;
  if (param_3 < 0xe) {
    if (5 < param_3) goto LAB_0040f840;
LAB_0040f8f0:
    iVar2 = *param_1;
    uVar3 = 0x4d;
  }
  else if ((((*param_2 == 'J') && (param_2[1] == 'F')) && (param_2[2] == 'I')) &&
          ((param_2[3] == 'F' && (param_2[4] == '\0')))) {
    param_1[0x46] = 1;
[32m    cVar1 = param_2[5];[0m
    *(char *)(param_1 + 0x47) = cVar1;
    *(char *)((int)param_1 + 0x11d) = param_2[6];
    *(char *)((int)param_1 + 0x11e) = param_2[7];
    *(ushort *)(param_1 + 0x48) = (ushort)(byte)param_2[8] * 0x100 + (ushort)(byte)param_2[9];
    *(ushort *)((int)param_1 + 0x122) =
         (ushort)(byte)param_2[10] * 0x100 + (ushort)(byte)param_2[0xb];
    if (cVar1 != '\x01') {
      *(undefined4 *)(*param_1 + 0x14) = 0x77;
      *(uint *)(*param_1 + 0x18) = (uint)*(byte *)(param_1 + 0x47);
      *(uint *)(*param_1 + 0x1c) = (uint)*(byte *)((int)param_1 + 0x11d);
      (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    }
    iVar2 = *param_1;
    *(uint *)(iVar2 + 0x18) = (uint)*(byte *)(param_1 + 0x47);
    *(uint *)(iVar2 + 0x1c) = (uint)*(byte *)((int)param_1 + 0x11d);
    *(uint *)(iVar2 + 0x20) = (uint)*(ushort *)(param_1 + 0x48);
    *(uint *)(iVar2 + 0x24) = (uint)*(ushort *)((int)param_1 + 0x122);
    *(uint *)(iVar2 + 0x28) = (uint)*(byte *)((int)param_1 + 0x11e);
    *(undefined4 *)(*param_1 + 0x14) = 0x57;
    (**(code **)(*param_1 + 4))(param_1,1);
    if ((param_2[0xd] != '\0') || (param_2[0xc] != '\0')) {
      *(undefined4 *)(*param_1 + 0x14) = 0x5a;
      *(uint *)(*param_1 + 0x18) = (uint)(byte)param_2[0xc];
      *(uint *)(*param_1 + 0x1c) = (uint)(byte)param_2[0xd];
      (**(code **)(*param_1 + 4))(param_1,1);
    }
    param_4 = param_4 + -0xe;
    if (param_4 == (uint)(byte)param_2[0xc] * (uint)(byte)param_2[0xd] * 3) {
      return;
    }
    iVar2 = *param_1;
    uVar3 = 0x58;
  }
  else {
LAB_0040f840:
    if ((((*param_2 != 'J') || ((param_2[1] != 'F' || (param_2[2] != 'X')))) || (param_2[3] != 'X'))
       || (param_2[4] != '\0')) goto LAB_0040f8f0;
[32m    cVar1 = param_2[5];[0m
    if (cVar1 == '\x11') {
      iVar2 = *param_1;
      uVar3 = 0x6d;
    }
    else if (cVar1 == '\x13') {
      iVar2 = *param_1;
      uVar3 = 0x6e;
    }
    else {
      iVar2 = *param_1;
      uVar3 = 0x6c;
      if (cVar1 != '\x10') {
        *(undefined4 *)(iVar2 + 0x14) = 0x59;
        *(uint *)(*param_1 + 0x18) = (uint)(byte)param_2[5];
        *(int *)(*param_1 + 0x1c) = param_4;
        goto LAB_0040f90c;
      }
    }
  }
  *(undefined4 *)(iVar2 + 0x14) = uVar3;
  *(int *)(*param_1 + 0x18) = param_4;
LAB_0040f90c:
                    /* WARNING: Could not recover jumptable at 0x0040f924. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 4))(param_1,1);
  return;
}

[ASK_GPT] 1bbbcaf05c6e9dd0
