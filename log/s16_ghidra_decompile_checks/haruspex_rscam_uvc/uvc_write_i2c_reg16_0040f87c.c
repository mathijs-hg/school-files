
void uvc_write_i2c_reg16(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined local_10;
  undefined local_f;
  
[32m  memset(&local_10,0,2);[0m
  local_10 = (undefined)param_3;
  local_f = (undefined)((ushort)param_3 >> 8);
  uvc_exec_vendor_cmd(param_1,0x8a,param_2,&local_10,2,0);
  return;
}

[ASK_GPT] 430a3ee15a1963f1
