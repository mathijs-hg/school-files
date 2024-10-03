
undefined4 sendEventMsg(int param_1)

{
  size_t sVar1;
  int __fd;
  ssize_t sVar2;
  undefined4 uVar3;
  int iVar4;
  sockaddr local_90;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  char local_72;
  undefined auStack_71 [49];
  undefined local_40;
  undefined auStack_3f [15];
  sockaddr *local_30;
  
  local_80 = 0x3c2f4d75;
  local_7c = 0x6c746952;
  local_78 = 0x65706f72;
  local_74 = 0x743e;
  local_72 = '\0';
[32m  memset(auStack_71,0,0x31);[0m
  local_40 = 0;
[32m  memset(auStack_3f,0,0xf);[0m
  if (param_1 == 0) {
    fprintf(stderr,"[hnap_push_service][%s] invalid parameters\n","sendEventMsg");
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0xffffffff;
    if (*(short *)(param_1 + 0xe) != 0) {
[32m      sVar1 = strlen((char *)&local_80);[0m
      fillEventMessageContent(param_1,0,&local_40,&local_80,sVar1);
      __fd = socket(2,1,0);
      if (__fd < 0) {
        fprintf(stderr,"[hnap_push_service][%s] create udp socket failed\n","sendEventMsg");
        uVar3 = 0xffffffff;
      }
      else {
        local_90.sa_family = 2;
        local_90.sa_data._2_4_ = inet_addr("127.0.0.1");
        local_90.sa_data._0_2_ = 0xbc3;
[32m        sVar1 = *(ushort *)(param_1 + 0xe) + 0x10;[0m
        iVar4 = 0;
        if (sVar1 != 0) {
          local_30 = &local_90;
          do {
            sVar2 = sendto(__fd,(void *)(param_1 + iVar4 * 0x10010),sVar1,0,local_30,0x10);
            if (sVar2 < 1) {
              fprintf(stderr,"[hnap_push_service][%s] send event message failed\n","sendEventMsg");
              uVar3 = 0xffffffff;
              goto LAB_00413f90;
            }
            fprintf(stderr,"[hnap_push_service][%s] send event message length [%d]\n","sendEventMsg"
                    ,sVar2);
            sVar1 = sVar1 - sVar2;
            iVar4 = iVar4 + sVar2;
          } while (sVar1 != 0);
        }
        uVar3 = 0;
      }
LAB_00413f90:
      if (__fd != -1) {
        close(__fd);
      }
    }
  }
  return uVar3;
}

[ASK_GPT] 7825a1d6f8691e97
