
int FUN_00401170(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,char **param_5
                )

{
  int iVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  ulong uVar5;
  ulong local_228 [128];
  char *apcStack_28 [2];
  
  iVar1 = cfgGetIndex(param_2,param_3,param_3,param_4,&_gp);
  if (iVar1 < 0) {
    puts("userconfig: invalid config name");
    return -1;
  }
  iVar2 = cfgGetType(iVar1);
  switch(iVar2) {
  case 0:
  case 2:
    if (param_4 != 1) goto LAB_00401460;
    local_228[0] = strtol(*param_5,apcStack_28,0);
    iVar2 = 0;
    goto LAB_00401478;
  case 1:
    if (param_4 != 1) goto LAB_00401460;
    lVar3 = strtol(*param_5,apcStack_28,0);
    iVar2 = -2;
    if (lVar3 + 0x8000U < 0x10000) {
      iVar2 = 0;
    }
    local_228[0] = local_228[0] & 0xffff | lVar3 << 0x10;
    break;
  case 3:
    if (param_4 == 1) {
      local_228[0] = strtoul(*param_5,apcStack_28,0);
      iVar2 = 0;
      goto LAB_00401478;
    }
    goto LAB_00401460;
  case 4:
    if (param_4 != 1) goto LAB_00401460;
    uVar5 = strtoul(*param_5,apcStack_28,0);
    iVar2 = -2;
    if (uVar5 < 0x10000) {
      iVar2 = 0;
    }
    local_228[0] = local_228[0] & 0xffff | uVar5 << 0x10;
    break;
  case 5:
    if (param_4 != 1) goto LAB_00401460;
    uVar5 = strtoul(*param_5,apcStack_28,0);
    iVar2 = -2;
    if (uVar5 < 0x100) {
      iVar2 = 0;
    }
    local_228[0] = local_228[0] & 0xffffff | uVar5 << 0x18;
    break;
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
[32m    sVar4 = 1 << (iVar2 - 5U & 0x1f);[0m
    if (param_4 <= (int)sVar4) {
      memset(local_228,0,sVar4);
      if (param_4 < 1) {
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
        do {
          uVar5 = strtoul(*param_5,apcStack_28,0);
          if (0xff < uVar5) goto LAB_004014e4;
          *(char *)((int)local_228 + iVar2) = (char)uVar5;
          iVar2 = iVar2 + 1;
          param_5 = param_5 + 1;
        } while (iVar2 < param_4);
        iVar2 = 0;
      }
      goto LAB_00401478;
    }
    goto LAB_00401460;
  case 0xe:
    if (param_4 != 1) goto LAB_00401460;
    lVar3 = strtol(*param_5,apcStack_28,0);
    iVar2 = -2;
    if (lVar3 + 0x80U < 0x100) {
      iVar2 = 0;
    }
    local_228[0] = local_228[0] & 0xffffff | lVar3 << 0x18;
    break;
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    if (param_4 == 1) {
[32m[32m      strcpy((char *)local_228,*param_5);[0m[0m
      sVar4 = strlen((char *)local_228);
      if (8 << (iVar2 - 0xfU & 0x1f) < (int)sVar4) {
LAB_004014e4:
        iVar2 = -2;
      }
      else {
        iVar2 = 0;
      }
      goto LAB_00401478;
    }
    goto LAB_00401460;
  default:
    iVar2 = 0;
  }
  if (iVar2 != -1) {
LAB_00401478:
    if (iVar2 == -2) {
      puts("userconfig: argument range over flow!");
      return -2;
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar1 = cfgWriteItem(iVar1,local_228,param_1);
    return iVar1;
  }
LAB_00401460:
  puts("userconfig: argument count uncorrect!");
  return -1;
}

[ASK_GPT] fa906236f5ac5cb9
