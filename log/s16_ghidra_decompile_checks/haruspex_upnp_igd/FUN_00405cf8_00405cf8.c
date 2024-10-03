
/* WARNING: Could not reconcile some variable overlaps */

void FUN_00405cf8(char **param_1,undefined4 param_2,undefined4 param_3)

{
  char *__ptr;
  size_t sVar1;
  char *__s;
  int iVar2;
  size_t sVar3;
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
  int local_30;
  
[32m[32m[32m  __ptr = (char *)malloc(0xc);[0m[0m[0m
  if (param_1 != (char **)0x0) {
    sVar1 = strlen(*param_1);
[32m[32m[32m    __s = (char *)malloc(sVar1 + 0x116);[0m[0m[0m
    iVar2 = sprintf(__s,"%sGetLinkLayerMaxBitRates xmlns:u=\"%s\"></u:GetLinkLayerMaxBitRates%s",
                    "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:"
[32m[32m                    ,*param_1,"></s:Body></s:Envelope>");[0m[0m
    FUN_00405000(param_1[8]);
    ILibParseUri(param_1[2],&local_4c,local_50,&local_48);
    sVar1 = strlen(local_48);
    sVar3 = strlen(local_4c);
    sVar4 = strlen(*param_1);
[32m[32m[32m    __s_00 = (char *)malloc(sVar1 + sVar3 + 0xb0 + sVar4);[0m[0m[0m
    local_30 = sprintf(__s_00,
                       "POST %s HTTP/1.0\r\nHost: %s:%d\r\nUser-Agent: POSIX, UPnP/1.0, Intel MicroStack/1.0.1423\r\nSOAPACTION: \"%s#%s\"\r\nContent-Type: text/xml\r\nContent-Length: %d\r\n\r\n"
                       ,local_48,local_4c,(uint)local_50[0],*param_1,"GetLinkLayerMaxBitRates",iVar2
[32m[32m                      );[0m[0m
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
              (*(undefined4 *)(*piVar5 + 0x2c),__s_00,local_30,__s,iVar2,&local_44,FUN_0040990c,
               param_1,__ptr);
    free(local_4c);
    __ptr = local_48;
  }
  free(__ptr);
  return;
}

[ASK_GPT] 6bcc72ad13b95f8e
