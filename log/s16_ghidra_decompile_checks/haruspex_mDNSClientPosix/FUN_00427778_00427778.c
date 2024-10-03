
undefined4 *
FUN_00427778(int param_1,undefined4 param_2,undefined4 param_3,int param_4,char param_5)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  short local_res4;
  short local_res8;
  
  puVar3 = *(undefined4 **)(param_1 + 0x2ac);
[32m  local_res4 = (short)((uint)param_2 >> 0x10);[0m
[32m  local_res8 = (short)((uint)param_3 >> 0x10);[0m
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (param_5 == '\0') {
      if ((short *)puVar3[0x36] != (short *)0x0) {
[32m        sVar1 = *(short *)puVar3[0x36];[0m
        goto LAB_004277f0;
      }
    }
    else {
[32m      sVar1 = *(short *)(puVar3 + 0x44);[0m
LAB_004277f0:
      if ((((sVar1 == local_res4) && (*(short *)((int)puVar3 + 0x152) == local_res8)) &&
          (puVar3[0x95] == *(int *)(param_4 + 0x254))) &&
         ((puVar3[1] == *(int *)(param_4 + 4) &&
          (iVar2 = SameDomainName(puVar3 + 0x55,param_4 + 0x154), iVar2 != 0)))) {
        return puVar3;
      }
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}

[ASK_GPT] 2adde577cf6bef55
