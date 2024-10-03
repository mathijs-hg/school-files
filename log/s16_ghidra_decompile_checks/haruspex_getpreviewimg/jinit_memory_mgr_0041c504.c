
void jinit_memory_mgr(int *param_1)

{
  code **ppcVar1;
  char *__s;
  int iVar2;
  char local_18 [4];
  code *local_14 [2];
  
  param_1[1] = 0;
  local_14[0] = (code *)jpeg_mem_init();
  ppcVar1 = (code **)jpeg_get_small(param_1,0x54);
  if (ppcVar1 == (code **)0x0) {
    jpeg_mem_term(param_1);
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 0;
    (**(code **)*param_1)(param_1);
  }
  *ppcVar1 = FUN_0041c13c;
  ppcVar1[1] = FUN_0041cdf4;
  ppcVar1[2] = FUN_0041d094;
  ppcVar1[3] = FUN_0041cf44;
  ppcVar1[4] = FUN_0041c43c;
  ppcVar1[5] = (code *)&LAB_0041c374;
  ppcVar1[6] = FUN_0041d1e4;
  ppcVar1[7] = FUN_0041cb88;
  ppcVar1[8] = FUN_0041c918;
  ppcVar1[9] = FUN_0041c6dc;
  ppcVar1[10] = FUN_0041c894;
  ppcVar1[0xc] = (code *)0x3b9aca00;
  ppcVar1[0xe] = (code *)0x0;
  ppcVar1[0xb] = local_14[0];
  ppcVar1[0x13] = (code *)0x54;
  ppcVar1[0x10] = (code *)0x0;
  ppcVar1[0xd] = (code *)0x0;
  ppcVar1[0xf] = (code *)0x0;
  ppcVar1[0x11] = (code *)0x0;
  ppcVar1[0x12] = (code *)0x0;
  param_1[1] = (int)ppcVar1;
[32m  __s = getenv("JPEGMEM");[0m
  if (__s != (char *)0x0) {
    local_18[0] = 'x';
[32m    iVar2 = sscanf(__s,"%ld%c",local_14,local_18);[0m
    if (0 < iVar2) {
      if ((local_18[0] == 'm') || (local_18[0] == 'M')) {
        local_14[0] = (code *)((int)local_14[0] * 1000);
      }
      ppcVar1[0xb] = (code *)((int)local_14[0] * 1000);
    }
  }
  return;
}

[ASK_GPT] c4605470bfebee25
