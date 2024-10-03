
void ILibSetDirective(void **param_1,void *param_2,void *param_3,void *param_4,void *param_5)

{
  void *pvVar1;
  
[32m[32m[32m[32m  pvVar1 = malloc((int)param_3 + 1);[0m[0m[0m[0m
  *param_1 = pvVar1;
[32m  memcpy(pvVar1,param_2,(size_t)param_3);[0m
  *(undefined *)((int)*param_1 + (int)param_3) = 0;
  param_1[1] = param_3;
[32m[32m[32m[32m  pvVar1 = malloc((int)param_5 + 1);[0m[0m[0m[0m
  param_1[2] = pvVar1;
[32m  memcpy(pvVar1,param_4,(size_t)param_5);[0m
  *(undefined *)((int)param_1[2] + (int)param_5) = 0;
  param_1[0xb] = (void *)0xffffffff;
  param_1[3] = param_5;
  return;
}

[ASK_GPT] 0b63844dc01220c8
