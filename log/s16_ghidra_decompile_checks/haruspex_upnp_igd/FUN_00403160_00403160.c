
undefined4 *
FUN_00403160(int param_1,undefined4 param_2,char *param_3,undefined4 param_4,uint param_5)

{
  void **ppvVar1;
  undefined4 *__s;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  char **ppcVar5;
  size_t sVar6;
  char *__dest;
  size_t sVar7;
  void **ppvVar8;
  char **ppcVar9;
  size_t sVar10;
  void *pvVar11;
  undefined *puVar12;
  char *local_68;
  char *local_64;
  char *local_60;
  char *local_5c;
  char *local_58 [2];
  void **local_50;
  int local_4c;
  int local_48;
  char **local_44;
  char **local_40;
  char **local_3c;
  char **local_38;
  void **local_34;
  uint local_30;
  char *local_2c;
  
  puVar12 = &_gp;
  local_64 = (char *)0x0;
  local_60 = (char *)0x0;
  local_5c = (char *)0x0;
  local_58[0] = (char *)0x0;
[32m[32m[32m  __s = (undefined4 *)malloc(0x5c);[0m[0m[0m
[32m  memset(__s,0,0x5c);[0m
  *__s = param_2;
  __s[0x11] = param_4;
[32m[32m  pcVar2 = (char *)malloc(0x10);[0m[0m
  __s[0x10] = pcVar2;
  sprintf(pcVar2,"%d.%d.%d.%d",param_5 & 0xff,(int)param_5 >> 8 & 0xff,(int)param_5 >> 0x10 & 0xff,
[32m          param_5 >> 0x18,puVar12);[0m
  ppvVar8 = *(void ***)(param_1 + 0x20);
  do {
    if (ppvVar8 == (void **)0x0) {
      return __s;
    }
    puVar12 = (undefined *)ppvVar8[1];
    if (puVar12 == (undefined *)0xa) {
      pvVar11 = *ppvVar8;
      iVar3 = memcmp(pvVar11,"deviceList",10);
      if (iVar3 == 0) {
        ppvVar1 = (void **)ppvVar8[8];
        if (*(void **)((int)ppvVar8[8] + 0x10) != (void *)0x0) {
          do {
            ppvVar8 = ppvVar1;
            if ((ppvVar8[1] == (void *)0x6) && (iVar3 = memcmp(*ppvVar8,"device",6), iVar3 == 0)) {
              iVar3 = FUN_00403160(ppvVar8,param_2,param_3,param_4,param_5);
              *(undefined4 **)(iVar3 + 0x4c) = __s;
              *(undefined4 *)(iVar3 + 0x58) = __s[0x14];
              __s[0x14] = iVar3;
            }
            ppvVar1 = (void **)ppvVar8[10];
          } while ((void **)ppvVar8[10] != (void **)0x0);
          ppvVar8 = (void **)ppvVar8[9];
        }
      }
      else {
        iVar3 = memcmp(pvVar11,"deviceType",10);
        if (iVar3 == 0) {
          sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m          pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
          __s[1] = pvVar11;
[32m          memcpy(pvVar11,local_68,sVar4);[0m
          puVar12 = (undefined *)(__s[1] + sVar4);
          goto LAB_0040342c;
        }
LAB_0040361c:
        if (puVar12 == (undefined *)0x9) {
          iVar3 = memcmp(*ppvVar8,"modelName",9);
          if (iVar3 == 0) {
            sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m            pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
            __s[8] = pvVar11;
[32m            memcpy(pvVar11,local_68,sVar4);[0m
            puVar12 = (undefined *)(__s[8] + sVar4);
LAB_0040342c:
            *puVar12 = 0;
          }
        }
        else {
LAB_00403694:
          if (puVar12 == (undefined *)0xb) {
            iVar3 = memcmp(*ppvVar8,"modelNumber",0xb);
            if (iVar3 != 0) goto LAB_00403978;
            sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m            pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
            __s[10] = pvVar11;
[32m            memcpy(pvVar11,local_68,sVar4);[0m
            puVar12 = (undefined *)(__s[10] + sVar4);
            goto LAB_0040342c;
          }
LAB_0040370c:
          if (puVar12 == &DAT_00000008) {
            iVar3 = memcmp(*ppvVar8,"modelURL",8);
            if (iVar3 == 0) {
              sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m              pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
              __s[0xb] = pvVar11;
[32m              memcpy(pvVar11,local_68,sVar4);[0m
              puVar12 = (undefined *)(__s[0xb] + sVar4);
              goto LAB_0040342c;
            }
          }
          else {
            if (puVar12 != (undefined *)0xf) goto LAB_00403970;
            iVar3 = memcmp(*ppvVar8,"presentationURL",0xf);
            if (iVar3 == 0) {
              sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
              local_68[sVar4] = '\0';
[32m              iVar3 = ILibParseString(local_68,0,sVar4,&DAT_00415bb4,3);[0m
              if (*(int *)(iVar3 + 8) == 1) {
                if (*local_68 == '/') {
                  sVar10 = strlen(param_3);
[32m[32m[32m                  pvVar11 = malloc(sVar4 + 1 + sVar10);[0m[0m[0m
                  __s[4] = pvVar11;
                  sVar4 = strlen(param_3);
[32m                  memcpy(pvVar11,param_3,sVar4);[0m
                  sVar4 = strlen(param_3);
                  __dest = (char *)(__s[4] + sVar4);
                  pcVar2 = local_68 + 1;
                }
                else {
                  sVar10 = strlen(param_3);
[32m[32m[32m                  pvVar11 = malloc(sVar4 + 2 + sVar10);[0m[0m[0m
                  __s[4] = pvVar11;
                  sVar4 = strlen(param_3);
[32m                  memcpy(pvVar11,param_3,sVar4);[0m
                  sVar4 = strlen(param_3);
                  __dest = (char *)(__s[4] + sVar4);
                  pcVar2 = local_68;
                }
[32m[32m                strcpy(__dest,pcVar2);[0m[0m
              }
              else {
[32m[32m[32m                pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
                __s[4] = pvVar11;
[32m                memcpy(pvVar11,local_68,sVar4);[0m
                *(undefined *)(__s[4] + sVar4) = 0;
              }
              ILibDestructParserResults(iVar3);
            }
          }
        }
      }
    }
    else if (puVar12 == (undefined *)0x3) {
      iVar3 = memcmp(*ppvVar8,&DAT_00415ae8,3);
      if (iVar3 != 0) goto LAB_0040361c;
      sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
      pcVar2 = local_68;
      if (5 < (int)sVar4) {
        iVar3 = memcmp(local_68,&DAT_00415aec,5);
        if (iVar3 == 0) {
[32m          sVar4 = sVar4 - 5;[0m
          local_68 = pcVar2 + 5;
        }
[32m[32m[32m        pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
        __s[2] = pvVar11;
[32m        memcpy(pvVar11,local_68,sVar4);[0m
        puVar12 = (undefined *)(__s[2] + sVar4);
        goto LAB_0040342c;
      }
    }
    else {
      if (puVar12 == &DAT_0000000c) {
        pvVar11 = *ppvVar8;
        iVar3 = memcmp(pvVar11,"friendlyName",0xc);
        if (iVar3 == 0) {
          sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m          pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
          __s[5] = pvVar11;
[32m          memcpy(pvVar11,local_68,sVar4);[0m
          puVar12 = (undefined *)(__s[5] + sVar4);
        }
        else {
          iVar3 = memcmp(pvVar11,"manufacturer",0xc);
          if (iVar3 != 0) goto LAB_00403694;
          sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m          pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
          __s[6] = pvVar11;
[32m          memcpy(pvVar11,local_68,sVar4);[0m
          puVar12 = (undefined *)(__s[6] + sVar4);
        }
        goto LAB_0040342c;
      }
      if (puVar12 == (undefined *)0xf) {
        iVar3 = memcmp(*ppvVar8,"manufacturerURL",0xf);
        if (iVar3 == 0) {
          sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m          pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
          __s[7] = pvVar11;
[32m          memcpy(pvVar11,local_68,sVar4);[0m
          puVar12 = (undefined *)(__s[7] + sVar4);
          goto LAB_0040342c;
        }
        goto LAB_0040370c;
      }
      if (puVar12 != &DAT_00000010) goto LAB_0040361c;
      iVar3 = memcmp(*ppvVar8,"modelDescription",0x10);
      if (iVar3 == 0) {
        sVar4 = ILibReadInnerXML(ppvVar8,&local_68);
[32m[32m[32m        pvVar11 = malloc(sVar4 + 1);[0m[0m[0m
        __s[9] = pvVar11;
[32m        memcpy(pvVar11,local_68,sVar4);[0m
        puVar12 = (undefined *)(__s[9] + sVar4);
        goto LAB_0040342c;
      }
LAB_00403970:
      if (puVar12 == (undefined *)0xb) {
LAB_00403978:
        iVar3 = memcmp(*ppvVar8,"serviceList",0xb);
        if (iVar3 == 0) {
          local_3c = &local_5c;
          local_40 = &local_60;
          local_38 = &local_64;
          local_44 = local_58;
          local_34 = ppvVar8;
          local_30 = param_5;
          for (local_50 = (void **)ppvVar8[8]; ppvVar8 = local_34, param_5 = local_30,
              local_50 != (void **)0x0; local_50 = (void **)local_50[10]) {
            if (local_50[1] == (void *)0x7) {
              iVar3 = memcmp(*local_50,"service",7);
[32m              sVar4 = 0;[0m
              if (iVar3 == 0) {
                local_64 = (char *)0x0;
[32m                sVar7 = 0;[0m
                local_60 = (char *)0x0;
[32m                sVar10 = 0;[0m
                local_5c = (char *)0x0;
                local_58[0] = (char *)0x0;
                local_4c = 0;
                ppcVar5 = (char **)local_50[8];
                do {
                  ppcVar9 = ppcVar5;
                  pcVar2 = ppcVar9[1];
                  if (pcVar2 == (char *)0xb) {
                    local_2c = *ppcVar9;
                    iVar3 = memcmp(local_2c,"serviceType",0xb);
                    if (iVar3 == 0) {
                      local_4c = ILibReadInnerXML(ppcVar9,local_38);
                    }
                    else {
                      iVar3 = memcmp(local_2c,"eventSubURL",0xb);
                      if (iVar3 == 0) {
                        sVar7 = ILibReadInnerXML(ppcVar9,local_3c);
                      }
                    }
                  }
                  else if (pcVar2 == (char *)0x7) {
                    iVar3 = memcmp(*ppcVar9,"SCPDURL",7);
                    if (iVar3 == 0) {
                      sVar10 = ILibReadInnerXML(ppcVar9,local_40);
                    }
                  }
                  else if ((pcVar2 == (char *)0xa) &&
                          (iVar3 = memcmp(*ppcVar9,"controlURL",10), iVar3 == 0)) {
                    sVar4 = ILibReadInnerXML(ppcVar9,local_44);
                  }
                  ppcVar5 = (char **)ppcVar9[10];
                } while ((char **)ppcVar9[10] != (char **)0x0);
                local_50 = (void **)ppcVar9[9];
                local_64[local_4c] = '\0';
                local_60[sVar10] = '\0';
                local_5c[sVar7] = '\0';
                local_58[0][sVar4] = '\0';
[32m[32m[32m                ppcVar5 = (char **)malloc(0x28);[0m[0m[0m
                ppcVar5[5] = (char *)0x0;
                ppcVar5[1] = (char *)0x0;
                ppcVar5[6] = (char *)0x0;
                ppcVar5[7] = (char *)0x0;
                ppcVar5[9] = (char *)0x0;
                ppcVar5[8] = (char *)__s;
                if (((int)sVar7 < 7) || (iVar3 = memcmp(local_5c,&DAT_00415bb0,6), iVar3 != 0)) {
[32m                  local_48 = sVar7 + 1;[0m
                  if (*local_5c != '/') {
                    sVar6 = strlen(param_3);
[32m[32m[32m                    local_2c = (char *)malloc(local_48 + sVar6);[0m[0m[0m
                    ppcVar5[3] = local_2c;
                    sVar6 = strlen(param_3);
[32m                    memcpy(local_2c,param_3,sVar6);[0m
                    sVar6 = strlen(param_3);
[32m                    memcpy(ppcVar5[3] + sVar6,local_5c,sVar7);[0m
                    sVar6 = strlen(param_3);
                    pcVar2 = ppcVar5[3] + sVar6 + sVar7;
                    goto LAB_00403ce4;
                  }
                  sVar6 = strlen(param_3);
[32m[32m[32m                  local_2c = (char *)malloc(local_48 + sVar6);[0m[0m[0m
                  ppcVar5[3] = local_2c;
                  sVar6 = strlen(param_3);
[32m                  memcpy(local_2c,param_3,sVar6);[0m
                  sVar6 = strlen(param_3);
[32m                  memcpy(ppcVar5[3] + sVar6,local_5c + 1,sVar7 - 1);[0m
                  sVar6 = strlen(param_3);
                  ppcVar5[3][sVar6 + sVar7 + -1] = '\0';
                }
                else {
[32m[32m                  pcVar2 = (char *)malloc(sVar7 + 1);[0m[0m
                  ppcVar5[3] = pcVar2;
[32m                  memcpy(pcVar2,local_5c,sVar7);[0m
                  pcVar2 = ppcVar5[3] + sVar7;
LAB_00403ce4:
                  *pcVar2 = '\0';
                }
                if (((int)sVar4 < 7) || (iVar3 = memcmp(local_58[0],&DAT_00415bb0,6), iVar3 != 0)) {
                  if (*local_58[0] != '/') {
                    sVar7 = strlen(param_3);
[32m[32m                    pcVar2 = (char *)malloc(sVar4 + 1 + sVar7);[0m[0m
                    ppcVar5[2] = pcVar2;
                    sVar7 = strlen(param_3);
[32m                    memcpy(pcVar2,param_3,sVar7);[0m
                    sVar7 = strlen(param_3);
[32m                    memcpy(ppcVar5[2] + sVar7,local_58[0],sVar4);[0m
                    sVar7 = strlen(param_3);
                    pcVar2 = ppcVar5[2] + sVar7 + sVar4;
                    goto LAB_00403e9c;
                  }
                  sVar7 = strlen(param_3);
[32m[32m                  pcVar2 = (char *)malloc(sVar4 + 1 + sVar7);[0m[0m
                  ppcVar5[2] = pcVar2;
                  sVar7 = strlen(param_3);
[32m                  memcpy(pcVar2,param_3,sVar7);[0m
                  sVar7 = strlen(param_3);
[32m                  memcpy(ppcVar5[2] + sVar7,local_58[0] + 1,sVar4 - 1);[0m
                  sVar7 = strlen(param_3);
                  ppcVar5[2][sVar7 + sVar4 + -1] = '\0';
                }
                else {
[32m[32m                  pcVar2 = (char *)malloc(sVar4 + 1);[0m[0m
                  ppcVar5[2] = pcVar2;
[32m                  memcpy(pcVar2,local_58[0],sVar4);[0m
                  pcVar2 = ppcVar5[2] + sVar4;
LAB_00403e9c:
                  *pcVar2 = '\0';
                }
                if (((int)sVar10 < 7) || (iVar3 = memcmp(local_60,&DAT_00415bb0,6), iVar3 != 0)) {
                  if (*local_60 != '/') {
                    sVar4 = strlen(param_3);
[32m[32m                    pcVar2 = (char *)malloc(sVar10 + 1 + sVar4);[0m[0m
                    ppcVar5[4] = pcVar2;
                    sVar4 = strlen(param_3);
[32m                    memcpy(pcVar2,param_3,sVar4);[0m
                    sVar4 = strlen(param_3);
[32m                    memcpy(ppcVar5[4] + sVar4,local_60,sVar10);[0m
                    sVar4 = strlen(param_3);
                    pcVar2 = ppcVar5[4] + sVar4 + sVar10;
                    goto LAB_0040404c;
                  }
                  sVar4 = strlen(param_3);
[32m[32m                  pcVar2 = (char *)malloc(sVar10 + 1 + sVar4);[0m[0m
                  ppcVar5[4] = pcVar2;
                  sVar4 = strlen(param_3);
[32m                  memcpy(pcVar2,param_3,sVar4);[0m
                  sVar4 = strlen(param_3);
[32m                  memcpy(ppcVar5[4] + sVar4,local_60 + 1,sVar10 - 1);[0m
                  sVar4 = strlen(param_3);
                  ppcVar5[4][sVar4 + sVar10 + -1] = '\0';
                }
                else {
[32m[32m                  pcVar2 = (char *)malloc(sVar10 + 1);[0m[0m
                  ppcVar5[4] = pcVar2;
[32m                  memcpy(pcVar2,local_60,sVar10);[0m
                  pcVar2 = ppcVar5[4] + sVar10;
LAB_0040404c:
                  *pcVar2 = '\0';
                }
[32m[32m[32m                pcVar2 = (char *)malloc(local_4c + 1);[0m[0m[0m
                *ppcVar5 = pcVar2;
[32m[32m[32m                sprintf(pcVar2,local_64,local_4c);[0m[0m[0m
                pcVar2 = (char *)__s[0x15];
                __s[0x15] = ppcVar5;
                ppcVar5[9] = pcVar2;
              }
            }
          }
        }
      }
    }
    ppvVar8 = (void **)ppvVar8[10];
  } while( true );
}

[ASK_GPT] 84e360a09f75aa9e
