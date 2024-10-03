
void startWPS(int param_1)

{
  g_State = g_State | 4;
  g_iWait = 600;
[32m  system("rm -rf /tmp/wscd_status");[0m
  if (param_1 == 0) {
    WSCPinStart();
  }
  else {
    WSCPBCStart();
  }
  LEDcontrol("apoff");
  LEDcontrol("wpsproc");
  return;
}

[ASK_GPT] 50176433f06ed4c1
