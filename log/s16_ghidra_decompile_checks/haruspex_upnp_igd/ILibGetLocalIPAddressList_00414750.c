
int ILibGetLocalIPAddressList(void **param_1)

{
  int __fd;
  int iVar1;
  int iVar2;
  void *__dest;
  int iVar3;
  int iVar4;
  char *__s1;
  int local_2a8;
  undefined *local_2a4;
  undefined auStack_2a0 [4];
  int local_29c;
  char acStack_290 [16];
  ushort local_280;
  undefined auStack_270 [64];
  undefined auStack_230 [512];
  int *local_30;
  
  __fd = socket(2,1,0x11);
  if (-1 < __fd) {
    local_2a8 = 0x200;
    local_2a4 = auStack_230;
    iVar1 = ioctl(__fd,0x8912,&local_2a8);
    if (-1 < iVar1) {
      iVar4 = 0;
      iVar1 = 0;
      local_30 = &local_2a8;
      do {
        if (local_2a8 <= iVar4) {
          close(__fd);
[32m[32m          __dest = malloc(iVar1 << 2);[0m[0m
          *param_1 = __dest;
[32m          memcpy(__dest,auStack_270,iVar1 << 2);[0m
          return iVar1;
        }
        __s1 = local_2a4 + iVar4;
        iVar2 = strcmp(__s1,IFaceName);
        iVar3 = iVar1;
        if (iVar2 == 0) {
[32m[32m          strcpy(acStack_290,__s1);[0m[0m
          iVar2 = ioctl(__fd,0x8913,acStack_290);
          if (iVar2 < 0) break;
          if (((local_280 & 9) == 1) && (*(short *)(__s1 + 0x10) == 2)) {
[32m[32m            memcpy(auStack_2a0,__s1 + 0x10,0x10);[0m[0m
            if (local_29c != 0x7f000001) {
              iVar3 = iVar1 + 1;
              local_30[iVar1 + 0xe] = local_29c;
            }
          }
        }
        iVar4 = iVar4 + 0x20;
        iVar1 = iVar3;
      } while( true );
    }
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}

[ASK_GPT] e6d1e6e626ca6234
