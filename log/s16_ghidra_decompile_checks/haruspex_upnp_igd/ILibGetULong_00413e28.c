
undefined4 ILibGetULong(char *param_1,size_t param_2,ulong *param_3)

{
  void *__ptr;
  char *__nptr;
  ulong uVar1;
  undefined4 uVar2;
  int *piVar3;
  char *local_20 [2];
  
[32m[32m[32m  __ptr = malloc(0x14);[0m[0m[0m
[32m[32m[32m  __nptr = (char *)malloc(param_2 + 1);[0m[0m[0m
[32m  memcpy(__nptr,param_1,param_2);[0m
  __nptr[param_2] = '\0';
  uVar1 = strtoul(__nptr,local_20,10);
  *param_3 = uVar1;
  if (*local_20[0] == '\0') {
    free(__nptr);
    free(__ptr);
    piVar3 = __errno_location();
    uVar2 = 0xffffffff;
    if ((*piVar3 != 0x22) && (uVar2 = 0, *param_1 == '-')) {
      uVar2 = 0xffffffff;
    }
  }
  else {
    free(__nptr);
    free(__ptr);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

[ASK_GPT] 029984914604b73f
