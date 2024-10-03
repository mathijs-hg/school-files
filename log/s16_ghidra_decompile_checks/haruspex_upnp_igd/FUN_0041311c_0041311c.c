
int FUN_0041311c(int param_1,char *param_2)

{
  undefined *puVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  char local_48;
  undefined local_47;
  char *local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  char *local_2c;
  
  puVar6 = &_gp;
  local_40 = &local_48;
  iVar5 = 0;
  local_2c = "%02X";
  local_3c = 0x3b;
  local_38 = 0x3a;
  local_34 = 0x3d;
  local_30 = 0x2b;
  while( true ) {
    uVar2 = (uint)*param_2;
    uVar4 = uVar2 & 0xff;
    if (uVar2 == 0) break;
    if ((((((uVar4 - 0x3f & 0xff) < 0x1c) || ((uVar4 - 0x61 & 0xff) < 0x1a)) ||
         ((uVar4 - 0x2f & 0xff) < 0xb)) ||
        ((((uVar2 == local_3c || (uVar2 == local_38)) ||
          ((uVar2 == local_34 || ((uVar2 == local_30 || (uVar2 == 0x24)))))) || (uVar2 == 0x2d))))
       || (((uVar2 == 0x5f || (uVar2 == 0x2e)) || (uVar2 == 0x2a)))) {
      pcVar3 = (char *)(param_1 + iVar5);
      iVar5 = iVar5 + 1;
      *pcVar3 = *param_2;
    }
    else {
[32m[32m[32m      sprintf(local_40,local_2c,uVar4,local_34,puVar6);[0m[0m[0m
      puVar1 = (undefined *)(param_1 + iVar5);
      iVar5 = iVar5 + 3;
      puVar1[1] = local_48;
      puVar1[2] = local_47;
      *puVar1 = 0x25;
    }
    param_2 = param_2 + 1;
  }
  *(undefined *)(param_1 + iVar5) = 0;
  return iVar5 + 1;
}

[ASK_GPT] 8bfc1e16a19044d8
