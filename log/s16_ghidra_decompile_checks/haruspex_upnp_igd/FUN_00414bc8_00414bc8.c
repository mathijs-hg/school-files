
void FUN_00414bc8(char *param_1)

{
  FILE *__stream;
  char *pcVar1;
  undefined auStack_178 [4];
  undefined auStack_174 [4];
  undefined auStack_170 [4];
  undefined auStack_16c [4];
  undefined auStack_168 [4];
  undefined auStack_164 [4];
  undefined auStack_160 [4];
  int local_15c;
  uint local_158;
  undefined auStack_154 [4];
  undefined auStack_150 [12];
  char acStack_144 [260];
  undefined *local_40;
  int *local_3c;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  
[32m  __stream = fopen("/proc/net/route","r");[0m
  local_40 = auStack_150;
  local_3c = &local_15c;
[32m  fgets(acStack_144,0x100,__stream);[0m
  local_38 = auStack_154;
  local_34 = auStack_168;
  local_30 = auStack_164;
  local_2c = auStack_160;
  while( true ) {
[32m    pcVar1 = fgets(acStack_144,0x100,__stream);[0m
    if (pcVar1 == (char *)0x0) break;
    sscanf(acStack_144,"%s%lx%lx%X%d%d%d%lx%d%d%d",local_40,local_3c,&local_158,auStack_178,
[32m[32m[32m           auStack_174,auStack_170,auStack_16c,local_38,local_34,local_30,local_2c);[0m[0m[0m
    if (local_15c == 0) {
      sprintf(param_1,"%d.%d.%d.%d",local_158 >> 0x18,local_158 >> 0x10 & 0xff,local_158 >> 8 & 0xff
[32m              ,local_158 & 0xff);[0m
    }
  }
  fclose(__stream);
  return;
}

[ASK_GPT] 67f79b8a3c66ece3
