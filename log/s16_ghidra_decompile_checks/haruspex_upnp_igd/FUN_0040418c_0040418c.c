
void FUN_0040418c(undefined4 param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  char **ppcVar2;
  char **ppcVar3;
  int iVar4;
  void **ppvVar5;
  size_t sVar6;
  undefined4 *puVar7;
  void **ppvVar8;
  undefined *puVar9;
  void *pvVar10;
  undefined4 uVar11;
  int iVar12;
  void **ppvVar13;
  void **ppvVar14;
  void *local_30 [2];
  
  ppcVar2 = (char **)ILibParseXML(param_1,0,param_2);
  ILibProcessXMLNodeList(ppcVar2);
  for (ppcVar3 = ppcVar2; (ppcVar3 != (char **)0x0 && (**ppcVar3 == '!'));
      ppcVar3 = (char **)ppcVar3[8]) {
  }
  ppvVar13 = (void **)ppcVar3[8];
  do {
    if (ppvVar13 == (void **)0x0) goto LAB_00404810;
    if (ppvVar13[1] == (void *)0xa) {
      iVar4 = memcmp(*ppvVar13,"actionList",10);
      if (iVar4 == 0) {
        ppvVar13 = (void **)ppvVar13[8];
        do {
          if ((ppvVar13[1] == (void *)0x6) && (iVar4 = memcmp(*ppvVar13,"action",6), iVar4 == 0)) {
[32m[32m[32m            ppvVar5 = (void **)malloc(8);[0m[0m[0m
            pvVar10 = *(void **)(param_3 + 0x18);
            *ppvVar5 = (void *)0x0;
            ppvVar5[1] = pvVar10;
            *(void ***)(param_3 + 0x18) = ppvVar5;
            ppvVar13 = (void **)ppvVar13[8];
            do {
              ppvVar8 = ppvVar13;
              if (((undefined *)ppvVar8[1] == &DAT_00000004) &&
                 (iVar4 = memcmp(*ppvVar8,&DAT_00415bcc,4), iVar4 == 0)) {
                sVar6 = ILibReadInnerXML(ppvVar8,local_30);
[32m[32m[32m                pvVar10 = malloc(sVar6 + 1);[0m[0m[0m
                *ppvVar5 = pvVar10;
[32m                memcpy(pvVar10,local_30[0],sVar6);[0m
                *(undefined *)((int)*ppvVar5 + sVar6) = 0;
              }
              ppvVar13 = (void **)ppvVar8[10];
            } while ((void **)ppvVar8[10] != (void **)0x0);
            ppvVar13 = (void **)ppvVar8[9];
          }
          ppvVar13 = (void **)ppvVar13[10];
        } while (ppvVar13 != (void **)0x0);
LAB_00404810:
        ILibDestructXMLNodeList(ppcVar2);
        return;
      }
    }
    else if (((ppvVar13[1] == (void *)0x11) &&
             (iVar4 = memcmp(*ppvVar13,"serviceStateTable",0x11), iVar4 == 0)) &&
            (*(void **)((int)ppvVar13[8] + 0x10) != (void *)0x0)) {
      ppvVar13 = (void **)ppvVar13[8];
      do {
        ppvVar5 = ppvVar13;
        if ((ppvVar5[1] == (void *)0xd) &&
           (iVar4 = memcmp(*ppvVar5,"stateVariable",0xd), iVar4 == 0)) {
[32m[32m[32m          puVar7 = (undefined4 *)malloc(0x20);[0m[0m[0m
          uVar11 = *(undefined4 *)(param_3 + 0x1c);
          puVar7[3] = 0;
          *puVar7 = uVar11;
          puVar7[4] = 0;
          puVar7[6] = 0;
          puVar7[5] = 0;
          puVar7[7] = 0;
          puVar7[2] = 0;
          *(undefined4 **)(param_3 + 0x1c) = puVar7;
          puVar7[1] = param_3;
          ppvVar13 = (void **)ppvVar5[8];
          do {
            ppvVar5 = ppvVar13;
            if (((undefined *)ppvVar5[1] == &DAT_00000004) &&
               (iVar4 = memcmp(*ppvVar5,&DAT_00415bcc,4), iVar4 == 0)) {
              sVar6 = ILibReadInnerXML(ppvVar5,local_30);
[32m[32m[32m              pvVar10 = malloc(sVar6 + 1);[0m[0m[0m
              puVar7[2] = pvVar10;
[32m              memcpy(pvVar10,local_30[0],sVar6);[0m
              *(undefined *)(puVar7[2] + sVar6) = 0;
            }
            if ((((undefined *)ppvVar5[1] == &DAT_00000010) &&
                (iVar4 = memcmp(*ppvVar5,"allowedValueList",0x10), iVar4 == 0)) &&
               (*(void **)((int)ppvVar5[8] + 0x10) != (void *)0x0)) {
              ppvVar13 = (void **)ppvVar5[8];
              ppvVar5 = (void **)0x0;
              do {
                ppvVar14 = ppvVar13;
                ppvVar8 = ppvVar5;
                if (((undefined *)ppvVar14[1] == &DAT_0000000c) &&
                   (iVar4 = memcmp(*ppvVar14,"allowedValue",0xc), iVar4 == 0)) {
[32m[32m[32m                  ppvVar8 = (void **)malloc(8);[0m[0m[0m
                  *ppvVar8 = ppvVar5;
                  sVar6 = ILibReadInnerXML(ppvVar14,local_30);
[32m[32m[32m                  pvVar10 = malloc(sVar6 + 1);[0m[0m[0m
                  ppvVar8[1] = pvVar10;
[32m                  memcpy(pvVar10,local_30[0],sVar6);[0m
                  *(undefined *)((int)ppvVar8[1] + sVar6) = 0;
                }
                ppvVar13 = (void **)ppvVar14[10];
                ppvVar5 = ppvVar8;
              } while ((void **)ppvVar14[10] != (void **)0x0);
              ppvVar5 = (void **)ppvVar14[9];
              ppvVar13 = ppvVar8;
              while( true ) {
                if (ppvVar13 == (void **)0x0) break;
                puVar7[4] = puVar7[4] + 1;
                ppvVar13 = (void **)*ppvVar13;
              }
[32m[32m              pvVar10 = malloc(puVar7[4] << 2);[0m[0m
              iVar4 = 0;
              puVar7[3] = pvVar10;
              ppvVar13 = ppvVar8;
              while( true ) {
                iVar12 = iVar4 * 4;
                bVar1 = (int)puVar7[4] <= iVar4;
                iVar4 = iVar4 + 1;
                if (bVar1) break;
                *(void **)(puVar7[3] + iVar12) = ppvVar13[1];
                ppvVar13 = (void **)*ppvVar13;
              }
              while (ppvVar8 != (void **)0x0) {
                ppvVar13 = (void **)*ppvVar8;
                free(ppvVar8);
                ppvVar8 = ppvVar13;
              }
            }
            if (((ppvVar5[1] == (void *)0x11) &&
                (iVar4 = memcmp(*ppvVar5,"allowedValueRange",0x11), iVar4 == 0)) &&
               (ppvVar13 = (void **)ppvVar5[8], *(void **)((int)ppvVar5[8] + 0x10) != (void *)0x0))
            {
              do {
                ppvVar5 = ppvVar13;
                puVar9 = (undefined *)ppvVar5[1];
                if (puVar9 == (undefined *)0x7) {
                  pvVar10 = *ppvVar5;
                  iVar4 = memcmp(pvVar10,"minimum",7);
                  if (iVar4 == 0) {
                    sVar6 = ILibReadInnerXML(ppvVar5,local_30);
[32m[32m[32m                    pvVar10 = malloc(sVar6 + 1);[0m[0m[0m
                    puVar7[5] = pvVar10;
[32m                    memcpy(pvVar10,local_30[0],sVar6);[0m
                    puVar9 = (undefined *)(puVar7[5] + sVar6);
LAB_00404750:
                    *puVar9 = 0;
                  }
                  else {
                    iVar4 = memcmp(pvVar10,"maximum",7);
                    if (iVar4 == 0) {
                      sVar6 = ILibReadInnerXML(ppvVar5,local_30);
[32m[32m[32m                      pvVar10 = malloc(sVar6 + 1);[0m[0m[0m
                      puVar7[6] = pvVar10;
[32m                      memcpy(pvVar10,local_30[0],sVar6);[0m
                      puVar9 = (undefined *)(puVar7[6] + sVar6);
                      goto LAB_00404750;
                    }
                  }
                  puVar9 = (undefined *)ppvVar5[1];
                }
                if ((puVar9 == &DAT_00000004) &&
                   (iVar4 = memcmp(*ppvVar5,&DAT_00415c40,4), iVar4 == 0)) {
                  sVar6 = ILibReadInnerXML(ppvVar5,local_30);
[32m[32m[32m                  pvVar10 = malloc(sVar6 + 1);[0m[0m[0m
                  puVar7[7] = pvVar10;
[32m                  memcpy(pvVar10,local_30[0],sVar6);[0m
                  *(undefined *)(puVar7[7] + sVar6) = 0;
                }
                ppvVar13 = (void **)ppvVar5[10];
              } while ((void **)ppvVar5[10] != (void **)0x0);
              ppvVar5 = (void **)ppvVar5[9];
            }
            ppvVar13 = (void **)ppvVar5[10];
          } while ((void **)ppvVar5[10] != (void **)0x0);
          ppvVar5 = (void **)ppvVar5[9];
        }
        ppvVar13 = (void **)ppvVar5[10];
      } while ((void **)ppvVar5[10] != (void **)0x0);
      ppvVar13 = (void **)ppvVar5[9];
    }
    ppvVar13 = (void **)ppvVar13[10];
  } while( true );
}

[ASK_GPT] 30c473b1aa40fe97
