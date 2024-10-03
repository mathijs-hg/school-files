
void FUN_0040c250(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  void **ppvVar6;
  char **ppcVar7;
  int iVar8;
  ushort local_38 [2];
  char *local_34;
  void *local_30;
  void *local_2c;
  
  iVar1 = ILibParseXML(param_2,0);
  ILibProcessXMLNodeList(iVar1);
  ppvVar6 = *(void ***)(iVar1 + 0x20);
  do {
    if (ppvVar6 == (void **)0x0) {
LAB_0040c3dc:
      ILibParseUri(param_4,&local_34,local_38,&local_30);
      sVar2 = strlen(local_34);
[32m[32m[32m      pcVar3 = (char *)malloc(sVar2 + 0x12);[0m[0m[0m
[32m[32m      sprintf(pcVar3,"http://%s:%d/",local_34,(uint)local_38[0]);[0m[0m
      free(local_34);
      free(local_30);
LAB_0040c468:
      ppvVar6 = *(void ***)(iVar1 + 0x20);
      while ((ppvVar6[1] != (void *)0x6 && (iVar4 = memcmp(*ppvVar6,"device",6), iVar4 != 0))) {
        ppvVar6 = (void **)ppvVar6[10];
      }
      iVar4 = FUN_00403160(ppvVar6,param_1,pcVar3,param_6,param_5);
      for (iVar8 = *(int *)(iVar4 + 0x50); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x50)) {
        iVar5 = strcmp(*(char **)(iVar8 + 4),"urn:schemas-upnp-org:device:WANConnection:1");
        if (iVar5 != 0) {
          for (ppcVar7 = *(char ***)(iVar8 + 0x54); ppcVar7 != (char **)0x0;
              ppcVar7 = (char **)ppcVar7[9]) {
            iVar5 = strcmp(*ppcVar7,"urn:schemas-upnp-org:service:WANPPPConnection:1");
            if (iVar5 == 0) {
              puts("I\'m using PPP conection service");
[32m[32m              strcpy(WAN_Service,*ppcVar7);[0m[0m
            }
            iVar5 = strcmp(*ppcVar7,"urn:schemas-upnp-org:service:WANIPConnection:1");
            if (iVar5 == 0) {
              puts("I\'m using IP conection service");
[32m[32m              strcpy(WAN_Service,*ppcVar7);[0m[0m
            }
          }
        }
      }
      free(pcVar3);
      ILibDestructXMLNodeList(iVar1);
      FUN_00404c30(param_1,*(undefined4 *)(iVar4 + 8));
      sVar2 = strlen(param_4);
[32m[32m[32m      pcVar3 = (char *)malloc(sVar2 + 1);[0m[0m[0m
      *(char **)(iVar4 + 0xc) = pcVar3;
[32m[32m      strcpy(pcVar3,param_4);[0m[0m
      FUN_00408bfc(iVar4);
      *(undefined4 *)(iVar4 + 0x34) = 0;
      FUN_00401b68(iVar4);
      if (*(int *)(iVar4 + 0x34) == 0) {
        FUN_0040c0f8(param_1,iVar4);
      }
      else {
        FUN_004020d4(iVar4);
      }
      return;
    }
    if ((ppvVar6[1] == (void *)0x7) && (iVar4 = memcmp(*ppvVar6,"URLBase",7), iVar4 == 0)) {
      sVar2 = ILibReadInnerXML(ppvVar6,&local_2c);
      if (*(char *)((int)local_2c + (sVar2 - 1)) == '/') {
[32m[32m[32m        pcVar3 = (char *)malloc(sVar2 + 1);[0m[0m[0m
[32m        memcpy(pcVar3,local_2c,sVar2);[0m
        pcVar3[sVar2] = '\0';
      }
      else {
[32m[32m[32m        pcVar3 = (char *)malloc(sVar2 + 2);[0m[0m[0m
[32m        memcpy(pcVar3,local_2c,sVar2);[0m
        pcVar3[sVar2] = '/';
        (pcVar3 + sVar2)[1] = '\0';
      }
      if (pcVar3 != (char *)0x0) {
        iVar4 = strcmp(pcVar3,"/");
        if (iVar4 != 0) goto LAB_0040c468;
        free(pcVar3);
      }
      goto LAB_0040c3dc;
    }
    ppvVar6 = (void **)ppvVar6[10];
  } while( true );
}

[ASK_GPT] 2180f6af433ffbe7
