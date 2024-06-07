
undefined4 iw_protocol_compare(char *param_1,char *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  size_t sVar8;
  char *pcVar9;
  uint local_30;
  
  iVar5 = strncmp(param_1,param_2,0x10);
  if (iVar5 == 0) {
    return 1;
  }
  sVar6 = strlen("IEEE 802.11");
[32m  iVar5 = strncmp(param_1,"IEEE 802.11",sVar6);[0m
  if (iVar5 == 0) {
    sVar6 = strlen("IEEE 802.11");
[32m    iVar5 = strncmp(param_2,"IEEE 802.11",sVar6);[0m
    if (iVar5 == 0) {
      sVar6 = strlen("IEEE 802.11");
      sVar7 = strlen("IEEE 802.11");
      bVar1 = false;
      bVar2 = false;
      bVar3 = false;
      bVar4 = false;
      for (local_30 = 0; sVar8 = strlen("Dbg"), local_30 < sVar8; local_30 = local_30 + 1) {
        pcVar9 = strchr(param_1 + sVar6,(int)(char)(&DAT_0040f364)[local_30]);
        if (pcVar9 != (char *)0x0) {
          bVar1 = true;
        }
        pcVar9 = strchr(param_2 + sVar7,(int)(char)(&DAT_0040f364)[local_30]);
        if (pcVar9 != (char *)0x0) {
          bVar2 = true;
        }
      }
      if ((bVar1) && (bVar2)) {
        return 1;
      }
      for (local_30 = 0; sVar8 = strlen("a"), local_30 < sVar8; local_30 = local_30 + 1) {
        pcVar9 = strchr(param_1 + sVar6,(int)(char)(&DAT_0040f368)[local_30]);
        if (pcVar9 != (char *)0x0) {
          bVar3 = true;
        }
        pcVar9 = strchr(param_2 + sVar7,(int)(char)(&DAT_0040f368)[local_30]);
        if (pcVar9 != (char *)0x0) {
          bVar4 = true;
        }
      }
      if ((bVar3) && (bVar4)) {
        return 1;
      }
    }
  }
  return 0;
}

[ASK_GPT] 77b58ae229426438
