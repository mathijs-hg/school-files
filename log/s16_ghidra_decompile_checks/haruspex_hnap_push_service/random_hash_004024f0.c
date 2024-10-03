
void random_hash(char *param_1,size_t param_2)

{
  char *__src;
  int iVar1;
  int iVar2;
  timeval atStack_28 [2];
  
  gettimeofday(atStack_28,(__timezone_ptr_t)0x0);
  __src = (char *)MD5_1(atStack_28,0xc);
[32m[32m  strncpy(param_1,__src,param_2);[0m[0m
  free(__src);
[32m  iVar2 = (int)param_2 / 2;[0m
  while (0 < iVar2) {
    iVar2 = iVar2 + -1;
[32m[32m    iVar1 = rand();[0m[0m
    if (param_2 == 0) {
      trap(0x1c00);
    }
    param_1[iVar1 % (int)param_2] =
         (char)*(undefined2 *)(__ctype_toupper + param_1[iVar1 % (int)param_2] * 2);
  }
  return;
}

[ASK_GPT] 8d0ca724cdf79254
