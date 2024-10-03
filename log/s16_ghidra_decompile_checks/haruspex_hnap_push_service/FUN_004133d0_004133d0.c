
void FUN_004133d0(int param_1)

{
  FILE *__s;
  ushort *puVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  char *__haystack;
  ushort *puVar5;
  uint uVar6;
  char local_468;
  undefined auStack_467 [1023];
  undefined2 local_68;
  undefined2 local_66;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char *local_40;
  ushort *local_3c;
  char *local_38;
  ushort *local_34;
  undefined **local_30;
  undefined2 *local_2c;
  
  local_468 = '\0';
[32m  memset(auStack_467,0,0x3ff);[0m
  local_68 = 0xa00;
  local_66 = 0;
  local_64 = 0x1b5b6d00;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  if ((param_1 != 0) && (*(short *)(param_1 + 0xe) != 0)) {
    fprintf(stderr,"pMsgInfo->stHeader.uPayloadLen: [%d]\n");
    fprintf(stderr,"pMsgInfo->stHeader size: [%d]\n",0x10);
[32m    __s = tmpfile();[0m
    if (__s != (FILE *)0x0) {
      puVar1 = (ushort *)(param_1 + 0x10);
      uVar6 = 0;
      local_30 = &PTR_DAT_00427058;
      local_2c = &local_68;
      local_40 = "<ReportStatus>";
      local_38 = "<PushDCHEvent>";
      local_34 = puVar1;
      do {
        fprintf(stderr,"pPayloadInfo->uTag: [0x%X]\n",(uint)*puVar1);
        fprintf(stderr,"pPayloadInfo->uDataLength: [%d]\n",(uint)puVar1[1]);
        if (*puVar1 == 0x29) {
          pcVar3 = local_30[uVar6];
          sVar2 = strlen(pcVar3);
          fwrite(pcVar3,1,sVar2,__s);
          uVar6 = uVar6 + 1;
          if (6 < uVar6) {
            uVar6 = 0;
          }
          if (puVar1[1] != 0) {
            iVar4 = 0;
            puVar5 = puVar1;
            local_3c = puVar1 + 2;
            do {
              __haystack = (char *)((int)puVar1 + iVar4 + 4);
              pcVar3 = strstr(__haystack,local_40);
              if ((__haystack == pcVar3) ||
                 (pcVar3 = strstr(__haystack,local_38), __haystack == pcVar3)) {
                pcVar3 = local_30[uVar6];
                sVar2 = strlen(pcVar3);
                fwrite(pcVar3,1,sVar2,__s);
                uVar6 = uVar6 + 1;
                if (6 < uVar6) {
                  uVar6 = 0;
                }
              }
              fwrite((void *)((int)local_3c + iVar4),1,1,__s);
              if (((puVar1[1] - 1 != iVar4) && (*(char *)(puVar5 + 2) == '>')) &&
                 (*(char *)((int)puVar5 + 5) == '<')) {
                sVar2 = strlen((char *)local_2c);
                fwrite(local_2c,1,sVar2,__s);
              }
              iVar4 = iVar4 + 1;
              puVar5 = (ushort *)((int)puVar5 + 1);
            } while (iVar4 < (int)(uint)puVar1[1]);
          }
          sVar2 = strlen((char *)local_2c);
          fwrite(local_2c,1,sVar2,__s);
        }
        puVar1 = (ushort *)((int)puVar1 + puVar1[1] + 4);
      } while (puVar1 < (ushort *)((int)local_34 + (uint)*(ushort *)(param_1 + 0xe)));
      sVar2 = strlen((char *)&local_64);
      fwrite(&local_64,1,sVar2,__s);
      fseek(__s,0,0);
[32m      memset(&local_468,0,0x400);[0m
[32m[32m[32m      while (sVar2 = fread(&local_468,1,0x3ff,__s), sVar2 != 0) {[0m[0m[0m
        fputs(&local_468,stderr);
[32m        memset(&local_468,0,0x400);[0m
      }
      fclose(__s);
    }
  }
  return;
}

[ASK_GPT] aaa004b93928e85a
