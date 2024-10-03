
/* WARNING: Could not reconcile some variable overlaps */

void FUN_00400ad8(void)

{
  FILE *__stream;
  int iVar1;
  undefined local_278;
  undefined auStack_277 [255];
  undefined4 local_178;
  undefined local_174;
  undefined auStack_173 [255];
  undefined local_74;
  undefined auStack_73 [63];
  uint local_34;
  undefined2 local_30;
  char local_2e [2];
  undefined2 local_2c;
  undefined2 local_2a;
  char local_28 [4];
  uint local_24 [2];
  
  local_278 = 0;
[32m  memset(auStack_277,0,0xff);[0m
  local_178 = 0;
  local_174 = 0;
[32m  memset(auStack_173,0,0xff);[0m
  local_74 = 0;
[32m  memset(auStack_73,0,0x3f);[0m
  local_2e[0] = '\0';
  local_2c = 0;
  local_2a = 0;
  local_28[0] = '\0';
  local_24[0] = 0;
[32m  __stream = fopen("/var/bonjour-dhnap_service.txt","w");[0m
  if (__stream == (FILE *)0x0) {
    return;
  }
  cfgRead(&DAT_00401230,"ModelNumber",&local_278);
  cfgRead(&DAT_00401230,"HWVersion",&local_74);
  cfgRead(&DAT_00401254,&DAT_0040125c,&local_178);
  cfgRead("WIRELESS_AP",&DAT_004012f4,&local_174);
  cfgRead("System","MainVersion",&local_2c);
  cfgRead("System","FirmwareVersion",&local_2a);
  cfgRead("MYDLINK","RegisterStatus",local_2e);
  cfgRead("WIRELESS_AP","Enable",local_28);
  SIReadInt(6,local_24);
  local_34 = 0;
  local_30 = 0;
  net_get_hwaddr(&DAT_00401340);
  fprintf(__stream,"%s\n","D-Link HNAP Service");
  fprintf(__stream,"%s\n","_dhnap._tcp.");
  fprintf(__stream,"%d\n",local_178);
  fprintf(__stream,"mac=%02X:%02X:%02X:%02X:%02X:%02X\n",local_34 >> 0x18,local_34 >> 0x10 & 0xff,
          local_34 >> 8 & 0xff,local_34 & 0xff,(uint)local_30._0_1_,(uint)(byte)local_30);
  fprintf(__stream,"wlan0_ssid=%s\n",&local_174);
  fprintf(__stream,"model_number=%s\n",&local_278);
  fprintf(__stream,"hardware_ver=%s\n",&local_74);
  if ((local_28[0] == '\x01') && ((local_24[0] & 4) != 0)) {
    if (local_2e[0] == '\0') {
      fprintf(__stream,"dcs=%s\n","24601");
      goto LAB_00400f4c;
    }
  }
  else if (local_28[0] == '\0') {
    iVar1 = WStatus("wlan0-vxd");
    if (((iVar1 != 0) && ((local_24[0] & 4) == 0)) && (local_2e[0] == '\0')) {
      fprintf(__stream,"dcs=%s\n","Sinker");
      goto LAB_00400f4c;
    }
    if (local_28[0] == '\0') {
      iVar1 = WStatus("wlan0-vxd");
      if ((iVar1 == 0) && (local_2e[0] == '\x01')) {
        fprintf(__stream,"dcs=%s\n","Gervais");
        goto LAB_00400f4c;
      }
      if ((local_28[0] == '\0') &&
         ((iVar1 = WStatus("wlan0-vxd"), iVar1 != 0 && (local_2e[0] == '\x01')))) {
        fprintf(__stream,"dcs=%s\n","Medeleine");
        goto LAB_00400f4c;
      }
    }
  }
  fprintf(__stream,"dcs=%s\n","Medeleine");
LAB_00400f4c:
  fprintf(__stream,"version=%02d%02d\n",1,0xc);
  fprintf(__stream,"mydlink=%s\n",&DAT_0040141c);
  fprintf(__stream,"hnf=%s\n","false");
  if (local_2e[0] == '\0') {
    fprintf(__stream,"mydlinkr=%s\n","false");
  }
  else {
    fprintf(__stream,"mydlinkr=%s\n",&DAT_0040141c);
  }
  fprintf(__stream,"dtype=%s\n","100;101");
  fputc(10,__stream);
  fclose(__stream);
  return;
}

[ASK_GPT] d68b15626c228b7c
