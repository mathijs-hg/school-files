
size_t FUN_004026cc(char *param_1)

{
  int iVar1;
  FILE *__s;
  size_t __n;
  int iVar2;
  
  iVar1 = pfOpen(1);
  if (iVar1 == 0) {
    fwrite("[getpreviewimg] Snapshot Open Profile Fail!\n",1,0x2c,stderr);
[32m    __n = 0xffffffff;[0m
  }
  else {
    iVar2 = 0;
    do {
[32m      __n = pfRead(iVar1);[0m
      if (0 < (int)__n) {
[32m        __s = fopen(param_1,"wb");[0m
        if (__s == (FILE *)0x0) {
          fwrite("[getpreviewimg] Snapshot Open store file Fail!\n",1,0x2f,stderr);
[32m          __n = 0;[0m
          goto LAB_0040283c;
        }
[32m        __n = __n - 0x44;[0m
        fwrite((void *)(*(int *)(iVar1 + 8) + 0x44),1,__n,__s);
        fclose(__s);
        goto LAB_00402844;
      }
      usleep(500000);
      iVar2 = iVar2 + 1;
    } while (iVar2 != 3);
    fwrite("[getpreviewimg] Snapshot From Profile Fail!\n",1,0x2c,stderr);
  }
LAB_0040283c:
  if (iVar1 != 0) {
LAB_00402844:
    pfUnlock(iVar1);
    pfClose(iVar1);
  }
  return __n;
}

[ASK_GPT] 984f154047d2b18e
