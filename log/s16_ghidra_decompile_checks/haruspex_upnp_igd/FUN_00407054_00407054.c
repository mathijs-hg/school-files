
/* WARNING: Could not reconcile some variable overlaps */

void FUN_00407054(char **param_1,undefined4 param_2,undefined4 param_3,char *param_4,ushort param_5,
                 char *param_6)

{
  char *__ptr;
  size_t sVar1;
  size_t sVar2;
  char *__s;
  int iVar3;
  size_t sVar4;
  char *__s_00;
  int *piVar5;
  ushort local_50 [2];
  char *local_4c;
  char *local_48;
  undefined4 local_44;
  in_addr_t local_40;
  undefined4 local_3c;
  undefined4 local_38;
  size_t local_30;
  
[32m[32m[32m  __ptr = (char *)malloc(0xc);[0m[0m[0m
  if (param_1 != (char **)0x0) {
    local_30 = strlen(*param_1);
    sVar1 = strlen(param_4);
    sVar2 = strlen(param_6);
[32m[32m[32m    __s = (char *)malloc(local_30 + sVar1 + 0x16c + sVar2);[0m[0m[0m
    iVar3 = sprintf(__s,
                    "%sDeletePortMapping xmlns:u=\"%s\"><NewRemoteHost>%s</NewRemoteHost><NewExternalPort>%u</NewExternalPort><NewProtocol>%s</NewProtocol></u:DeletePortMapping%s"
                    ,
                    "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:"
[32m[32m                    ,*param_1,param_4,(uint)param_5,param_6,"></s:Body></s:Envelope>");[0m[0m
    FUN_00405000(param_1[8]);
    ILibParseUri(param_1[2],&local_4c,local_50,&local_48);
    sVar1 = strlen(local_48);
    sVar2 = strlen(local_4c);
    sVar4 = strlen(*param_1);
[32m[32m[32m    __s_00 = (char *)malloc(sVar1 + sVar2 + 0xaa + sVar4);[0m[0m[0m
    local_30 = sprintf(__s_00,
                       "POST %s HTTP/1.0\r\nHost: %s:%d\r\nUser-Agent: POSIX, UPnP/1.0, Intel MicroStack/1.0.1423\r\nSOAPACTION: \"%s#%s\"\r\nContent-Type: text/xml\r\nContent-Length: %d\r\n\r\n"
[32m[32m[32m                       ,local_48,local_4c,(uint)local_50[0],*param_1,"DeletePortMapping",iVar3);[0m[0m[0m
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_44._2_2_ = 0;
    local_44._0_2_ = 2;
    local_40 = inet_addr(local_4c);
    piVar5 = (int *)param_1[8];
    *(undefined4 *)(__ptr + 4) = param_2;
    local_44 = CONCAT22(local_44._0_2_,local_50[0]);
    *(undefined4 *)(__ptr + 8) = param_3;
    ILibAddRequest_DirectEx
              (*(undefined4 *)(*piVar5 + 0x2c),__s_00,local_30,__s,iVar3,&local_44,FUN_0040af40,
               param_1,__ptr);
    free(local_4c);
    __ptr = local_48;
  }
  free(__ptr);
  return;
}

[ASK_GPT] 18e72cd2fdf0b2d2
