
void FUN_0040fc44(int param_1,int param_2)

{
  in_addr_t iVar1;
  ssize_t sVar2;
  char **ppcVar3;
  int iVar4;
  int **ppiVar5;
  in_addr_t iVar6;
  int iVar7;
  char **ppcVar8;
  void *__dest;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined auStack_60 [4];
  socklen_t local_5c;
  char *local_58;
  void *local_54;
  sockaddr sStack_50;
  void *local_40;
  char *local_3c;
  uint local_38;
  sockaddr *local_34;
  char *local_30;
  
  iVar9 = 0;
  iVar11 = 0;
  local_38 = 0;
  iVar10 = 0;
[32m[32m[32m  local_40 = malloc(0x1000);[0m[0m[0m
  __dest = (void *)0x0;
  local_5c = 0x10;
  local_34 = &sStack_50;
  do {
[32m[32m    sVar2 = recvfrom(param_1,local_40,0x1000,0,local_34,&local_5c);[0m[0m
    if (sVar2 < 1) {
      free(local_40);
      return;
    }
    ppcVar3 = (char **)ILibParsePacketHeader(local_40,0);
    if (*ppcVar3 == (char *)0x0) {
      if (ppcVar3[4] == (char *)0xc8) {
        for (ppcVar8 = (char **)ppcVar3[0xd]; ppcVar8 != (char **)0x0; ppcVar8 = (char **)ppcVar8[5]
            ) {
          iVar4 = strncasecmp(*ppcVar8,"LOCATION",8);
          if (iVar4 == 0) {
[32m[32m            __dest = malloc((size_t)(ppcVar8[3] + 1));[0m[0m
[32m            memcpy(__dest,ppcVar8[2],(size_t)ppcVar8[3]);[0m
            *(char *)((int)__dest + (int)ppcVar8[3]) = '\0';
          }
          iVar4 = strncasecmp(*ppcVar8,"CACHE-CONTROL",0xd);
          if (iVar4 == 0) {
            iVar4 = ILibParseString(ppcVar8[2],0,ppcVar8[3],&DAT_00416ce4,1);
            *(undefined *)(**(int **)(iVar4 + 4) + (*(int **)(iVar4 + 4))[1]) = 0;
            iVar11 = atoi(**(char ***)(iVar4 + 4));
            ILibDestructParserResults(iVar4);
          }
          iVar4 = strncasecmp(*ppcVar8,"USN",3);
          if (iVar4 == 0) {
            ppiVar5 = (int **)ILibParseString(ppcVar8[2],0,ppcVar8[3],&DAT_00416cec,2);
            *(undefined *)(**ppiVar5 + (*ppiVar5)[1]) = 0;
            iVar10 = **ppiVar5 + 5;
            ILibDestructParserResults(ppiVar5);
          }
        }
        ILibParseUri(__dest,&local_58,auStack_60,&local_54);
        iVar1 = sStack_50.sa_data._2_4_;
        iVar6 = inet_addr(local_58);
        if ((iVar1 == iVar6) && (*(code **)(param_2 + 0xc) != (code *)0x0)) {
          (**(code **)(param_2 + 0xc))
                    (param_2,iVar10,0xffffffff,__dest,iVar11,*(undefined4 *)(param_2 + 0x2c));
        }
        free(local_58);
        free(local_54);
      }
    }
    else {
      iVar4 = strncasecmp(*ppcVar3,"NOTIFY",6);
      iVar12 = 0;
      if (iVar4 == 0) {
        iVar4 = 0;
        for (ppcVar8 = (char **)ppcVar3[0xd]; ppcVar8 != (char **)0x0; ppcVar8 = (char **)ppcVar8[5]
            ) {
          (*ppcVar8)[(int)ppcVar8[1]] = '\0';
          iVar7 = strncasecmp(*ppcVar8,"NT",2);
          if ((iVar7 == 0) && (ppcVar8[1] == (char *)0x2)) {
            ppcVar8[2][(int)ppcVar8[3]] = '\0';
            local_30 = ppcVar8[2];
            iVar7 = strncasecmp(local_30,*(char **)(param_2 + 0x10),*(size_t *)(param_2 + 0x14));
            if (iVar7 == 0) {
              iVar4 = -1;
            }
            else {
              iVar7 = strncasecmp(local_30,"upnp:rootdevice",0xf);
              if (iVar7 != 0) break;
              iVar12 = -1;
            }
          }
          local_3c = *ppcVar8;
          iVar7 = strncasecmp(local_3c,"NTS",3);
          if (iVar7 == 0) {
            iVar9 = -1;
            iVar7 = strncasecmp(ppcVar8[2],"ssdp:alive",10);
            if (iVar7 == 0) {
              iVar12 = 0;
            }
            else {
              iVar4 = 0;
              iVar9 = 0;
            }
          }
          iVar7 = strncasecmp(local_3c,"USN",3);
          if (iVar7 == 0) {
            ppiVar5 = (int **)ILibParseString(ppcVar8[2],0,ppcVar8[3],&DAT_00416cec,2);
            *(undefined *)(**ppiVar5 + (*ppiVar5)[1]) = 0;
            iVar10 = **ppiVar5 + 5;
            ILibDestructParserResults(ppiVar5);
          }
          iVar7 = strncasecmp(*ppcVar8,"LOCATION",8);
          if (iVar7 == 0) {
[32m[32m            __dest = malloc((size_t)(ppcVar8[3] + 1));[0m[0m
[32m            memcpy(__dest,ppcVar8[2],(size_t)ppcVar8[3]);[0m
            *(char *)((int)__dest + (int)ppcVar8[3]) = '\0';
          }
          iVar7 = strncasecmp(*ppcVar8,"CACHE-CONTROL",0xd);
          if (iVar7 == 0) {
            iVar7 = ILibParseString(ppcVar8[2],0,ppcVar8[3],&DAT_00416ce4,1);
            *(undefined *)(**(int **)(iVar7 + 4) + (*(int **)(iVar7 + 4))[1]) = 0;
            iVar11 = atoi(**(char ***)(iVar7 + 4));
            ILibDestructParserResults(iVar7);
          }
        }
        if (((iVar4 != 0) && (iVar9 != 0)) || ((iVar12 != 0 && (iVar9 == 0)))) {
          if (__dest != (void *)0x0) {
            ILibParseUri(__dest,&local_58,auStack_60,&local_54);
            iVar1 = sStack_50.sa_data._2_4_;
            iVar6 = inet_addr(local_58);
            local_38 = (uint)(iVar1 == iVar6);
            free(local_58);
            free(local_54);
          }
          if (((iVar9 == 0) || (local_38 != 0)) && (*(code **)(param_2 + 0xc) != (code *)0x0)) {
            (**(code **)(param_2 + 0xc))
                      (param_2,iVar10,iVar9,__dest,iVar11,*(undefined4 *)(param_2 + 0x2c));
          }
        }
      }
    }
    if (__dest != (void *)0x0) {
      free(__dest);
    }
    ILibDestructPacket(ppcVar3);
  } while( true );
}

[ASK_GPT] 24e53c3b5612285c
