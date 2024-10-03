
void jcopy_sample_rows(int param_1,int param_2,int param_3,int param_4,int param_5,size_t param_6)

{
  void *__dest;
  void *__src;
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar2 = (void **)(param_1 + param_2 * 4);
  ppvVar1 = (void **)(param_3 + param_4 * 4);
  for (; 0 < param_5; param_5 = param_5 + -1) {
    __src = *ppvVar2;
    __dest = *ppvVar1;
    ppvVar2 = ppvVar2 + 1;
    ppvVar1 = ppvVar1 + 1;
[32m    memcpy(__dest,__src,param_6);[0m
  }
  return;
}

[ASK_GPT] 34c172e5c806fe76
