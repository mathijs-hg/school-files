
undefined4 main(int param_1,char **param_2)

{
  FILE *pFVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  byte *pbVar7;
  byte local_28 [4];
  undefined auStack_24 [3];
  byte local_21;
  byte local_20 [4];
  byte local_1c;
  byte local_1b;
  
  if (param_1 < 2) {
    fprintf(stderr,"%s: Invalid argument\n","rtkmib.c");
    FUN_00400960(*param_2);
    return 0xffffffff;
  }
  pcVar6 = param_2[1];
  iVar2 = strcmp(pcVar6,"mac");
  if (iVar2 == 0) {
    if (param_1 != 2) {
      pcVar6 = param_2[2];
      sVar3 = strlen(pcVar6);
      pFVar1 = stderr;
      if (sVar3 != 0x11) {
        pcVar6 = __xpg_basename(*param_2);
        fprintf(pFVar1,"%s: Invalid value format\n",pcVar6);
        return 0xffffffff;
      }
      if (pcVar6[2] == ':') {
        iVar2 = 0;
        pcVar5 = pcVar6;
        while (iVar2 = iVar2 + 3, pcVar5[5] == ':') {
          pcVar5 = pcVar6 + iVar2;
          if (iVar2 == 0xc) {
            pbVar7 = local_20;
            iVar2 = 0;
            do {
              lVar4 = strtol(param_2[2] + iVar2,(char **)0x0,0x10);
              *pbVar7 = (byte)lVar4;
              iVar2 = iVar2 + 3;
              pbVar7 = pbVar7 + 1;
            } while (iVar2 != 0x12);
            iVar2 = HWMIB_setMAC(local_20);
            if (-1 < iVar2) {
              return 0;
            }
            return 0xffffffff;
          }
        }
      }
      pcVar6 = __xpg_basename(*param_2);
      fprintf(pFVar1,"%s: Invalid value format\n",pcVar6);
      return 0xffffffff;
    }
    iVar2 = HWMIB_getMAC(local_20);
    if (-1 < iVar2) {
      printf("%02x:%02x:%02x:%02x:%02x:%02x",(uint)local_20[0],(uint)local_20[1],(uint)local_20[2],
             (uint)local_20[3],(uint)local_1c,(uint)local_1b);
      return 0;
    }
  }
  else {
    iVar2 = strcmp(pcVar6,"region");
    pFVar1 = stderr;
    if (iVar2 != 0) {
      pcVar6 = __xpg_basename(*param_2);
      fprintf(pFVar1,"%s: Invalid argument\n",pcVar6);
      FUN_00400960(*param_2);
      return 0xffffffff;
    }
    if (param_1 != 2) {
[32m[32m      sscanf(param_2[2],"%d",auStack_24);[0m[0m
      local_28[0] = local_21;
      iVar2 = HWMIB_setRegion();
      if (-1 < iVar2) {
        return 0;
      }
      return 0xffffffff;
    }
    iVar2 = HWMIB_getRegion(local_28);
    if (-1 < iVar2) {
      printf("%d",(uint)local_28[0]);
      return 0;
    }
  }
  return 0xffffffff;
}

[ASK_GPT] 2c95eccdb1307551
