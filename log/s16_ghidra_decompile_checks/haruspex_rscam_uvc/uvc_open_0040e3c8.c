
int uvc_open(char *param_1,int param_2)

{
  int __fd;
  int iVar1;
  
[32m  __fd = open(param_1,param_2);[0m
  if (__fd < 0) {
    fprintf(stderr,"open %s failed,fd = %d\n",param_1,__fd);
  }
  else {
    iVar1 = add_xu_ctrls(__fd);
    if (iVar1 == 0) {
      FUN_0040e2d8();
    }
    else {
      close(__fd);
      __fd = iVar1;
    }
  }
  return __fd;
}

[ASK_GPT] 33e3baa95c5752ff
