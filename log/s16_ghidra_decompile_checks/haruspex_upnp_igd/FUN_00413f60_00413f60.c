
undefined4 FUN_00413f60(void *param_1,size_t param_2,long *param_3)

{
  void *__ptr;
  char *__nptr;
  long lVar1;
  int *piVar2;
  undefined4 uVar3;
  char *local_20 [3];
  
[32m[32m[32m  __ptr = malloc(0x14);[0m[0m[0m
[32m[32m[32m  __nptr = (char *)malloc(param_2 + 1);[0m[0m[0m
[32m  memcpy(__nptr,param_1,param_2);[0m
  __nptr[param_2] = '\0';
  lVar1 = strtol(__nptr,local_20,10);
  *param_3 = lVar1;
  if (*local_20[0] == '\0') {
    free(__nptr);
    free(__ptr);
    piVar2 = __errno_location();
    uVar3 = 0xffffffff;
    if (*piVar2 != 0x22) {
      uVar3 = 0;
    }
  }
  else {
    free(__nptr);
    free(__ptr);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

[ASK_GPT] 2446c06c89925fbd
