
undefined4 FUN_0040710c(char *param_1,char *param_2,char *param_3)

{
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined local_a4;
  char acStack_a0 [136];
  
  local_d8 = 0;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
[32m  memset(acStack_a0,0,0x81);[0m
[32m[32m  strcpy((char *)&local_d8,param_1);[0m[0m
[32m[32m  strcpy((char *)&local_b4,param_2);[0m[0m
  AESEncrypt(param_1,param_2,0,acStack_a0);
[32m[32m  strcpy(param_3,acStack_a0);[0m[0m
  return 0;
}

[ASK_GPT] dd984a6b73b86bf2
