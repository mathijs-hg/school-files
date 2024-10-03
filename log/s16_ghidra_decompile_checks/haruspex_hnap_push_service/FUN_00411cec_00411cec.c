
undefined4 FUN_00411cec(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  fd_set *pfVar3;
  int iVar4;
  undefined4 uVar5;
  size_t __n;
  uint local_660;
  int local_65c;
  size_t local_658;
  fd_set local_654;
  timeval local_5d4;
  char local_5cc [8];
  char acStack_5c4 [1452];
  
  local_660 = 0xffffffff;
  local_65c = 0;
[32m  local_658 = 0;[0m
  local_5cc[0] = '\0';
[32m  memset(local_5cc + 1,0,0x5b3);[0m
  if ((((param_1 == 0) || (param_2 < 0)) || (0xffff < param_2)) || (param_3 == 0)) {
    fprintf(stderr,"[hnap_push_service][%s] invalid parameters\n","doPushDCHEvent");
    uVar5 = 0xffffffff;
  }
  else {
    iVar1 = FUN_00411860(&local_660,param_1,param_2,param_3);
    if (iVar1 == -1) {
      fprintf(stderr,"[hnap_push_service][%s] postHTTPRequest failed\n","doPushDCHEvent");
      uVar5 = 0xffffffff;
    }
    else {
[32m      memset(local_5cc,0,0x5b4);[0m
      iVar1 = FUN_00411af8(local_660,local_5cc,0x5b4);
      if (iVar1 == 0) {
[32m[32m        sscanf(acStack_5c4,"%d",&local_65c);[0m[0m
        if (local_65c == 200) {
          pcVar2 = strstr(local_5cc,"Content-Length:");
          if (pcVar2 == (char *)0x0) {
            fprintf(stderr,"[hnap_push_service][%s] recv response can\'t find content-length\n",
                    "doPushDCHEvent");
            uVar5 = 0xffffffff;
          }
          else {
[32m[32m            sscanf(pcVar2 + 0x10,"%d",&local_658);[0m[0m
            if (0x5b3 < local_658) {
              fprintf(stderr,"[hnap_push_service][%s] response content-length too large\n",
                      "doPushDCHEvent");
[32m              local_658 = 3;[0m
            }
[32m            __n = local_658;[0m
            local_5d4.tv_sec = 5;
            local_5d4.tv_usec = 0;
            pfVar3 = &local_654;
            do {
              pfVar3->fds_bits[0] = 0;
              pfVar3 = (fd_set *)pfVar3->fds_bits;
            } while ((timeval *)pfVar3 != &local_5d4);
            local_654.fds_bits[local_660 >> 5] =
                 local_654.fds_bits[local_660 >> 5] | 1 << (local_660 & 0x1f);
[32m            memset(local_5cc,0,0x5b4);[0m
            iVar1 = 0;
            if (0 < (int)__n) {
              do {
                iVar4 = select(local_660 + 1,&local_654,(fd_set *)0x0,(fd_set *)0x0,&local_5d4);
                if (iVar4 < 0) {
                  fprintf(stderr,"[hnap_push_service][%s] recv response timeout\n","doPushDCHEvent")
                  ;
                  uVar5 = 0xffffffff;
                  goto LAB_00412100;
                }
                if ((int)__n < 0x5b5) {
[32m[32m                  iVar4 = recv(local_660,local_5cc + iVar1,__n,0);[0m[0m
                }
                else {
[32m[32m                  iVar4 = recv(local_660,local_5cc + iVar1,0x5b4,0);[0m[0m
                }
[32m                __n = __n - iVar4;[0m
                if (iVar4 < 1) {
                  fprintf(stderr,"[hnap_push_service][%s] recv response failed\n","doPushDCHEvent");
                  uVar5 = 0xffffffff;
                  goto LAB_00412100;
                }
                iVar1 = iVar1 + iVar4;
              } while (0 < (int)__n);
            }
            fprintf(stderr,
                    "==[hnap_push_service][%s] PushDCHEventResponse begin==\n%s\n==[hnap_push_service][%s] PushDCHEventResponse end==\n"
                    ,"doPushDCHEvent",local_5cc,"doPushDCHEvent");
            pcVar2 = strstr(local_5cc,"<PushDCHEventResult>OK</PushDCHEventResult>");
            uVar5 = 0;
            if (pcVar2 == (char *)0x0) {
              fprintf(stderr,"[hnap_push_service][%s] got response == failed\n","doPushDCHEvent");
              uVar5 = 0xffffffff;
            }
          }
        }
        else {
          fprintf(stderr,"[hnap_push_service][%s] recv response nHTTPNumber=%d\n","doPushDCHEvent");
          uVar5 = 0xffffffff;
        }
      }
      else {
        fprintf(stderr,"[hnap_push_service][%s] recvHTTPHeader failed\n","doPushDCHEvent");
        uVar5 = 0xffffffff;
      }
    }
LAB_00412100:
    if (local_660 != 0xffffffff) {
      close(local_660);
    }
  }
  return uVar5;
}

[ASK_GPT] 61cb965e7c39d875
