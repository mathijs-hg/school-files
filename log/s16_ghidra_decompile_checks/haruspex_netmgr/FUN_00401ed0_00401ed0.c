
void FUN_00401ed0(void)

{
  int iVar1;
  undefined auStack_408 [1028];
  
  if (g_iNetPhy == 4) {
    iVar1 = realtek_GetStaInfo("wlan0",auStack_408,0x400);
    if (iVar1 == 0) {
[32m      system("msger hwmon 0 datatransfer 0 1 0 0 2>/dev/null 1>/dev/null");[0m
    }
  }
  return;
}

[ASK_GPT] a3d33daeb4b7531c
