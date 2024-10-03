
undefined4 FUN_00404e88(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_450;
  char local_44c [4];
  undefined4 local_448;
  undefined local_444;
  undefined auStack_443 [255];
  undefined auStack_344 [400];
  undefined auStack_1b4 [404];
  
  local_450 = 0;
  SIReadInt(0x14,&local_450);
  if ((local_450 & 1) != 0) {
    FUN_00404c1c();
  }
  uVar2 = 1;
  if ((local_450 & 0x2000) == 0) {
    uVar2 = local_450 >> 0xc & 1;
  }
  if ((local_450 & 0x4000) != 0) {
    uVar2 = 1;
  }
  uVar3 = 1;
  if ((local_450 & 0x10000) == 0) {
    uVar3 = local_450 >> 0xf & 1;
  }
  if ((local_450 & 0x4000000) != 0) {
[32m    system("/usr/sbin/msger httpdmgr 0 hrestart 0 0 2>/dev/null 1>/dev/null");[0m
  }
  if ((uVar3 != 0) && (iVar1 = FUN_00401710(), iVar1 != 1)) {
    local_44c[0] = '\0';
    setWlanCliDrv(auStack_344);
    cfgRead("WIRELESS_REP","SameWithClient",local_44c);
    if (local_44c[0] != '\0') {
      local_444 = 0;
[32m      memset(auStack_443,0,0xff);[0m
      local_448 = 0;
[32m      memset(&local_444,0,0x100);[0m
      cfgRead("WIRELESS",&DAT_0040b410,&local_444);
      cfgWrite("WIRELESS_REP",&DAT_0040b410,&local_444,1);
      local_448 = 0;
      cfgRead("WIRELESS","Channel",&local_448);
      cfgWrite("WIRELESS_REP","Channel",&local_448,1);
      local_448 = 0;
      cfgRead("WIRELESS","Authentication",&local_448);
      cfgWrite("WIRELESS_REP","Authentication",&local_448,1);
      local_448 = 0;
      cfgRead("WIRELESS","Encryption",&local_448);
      cfgWrite("WIRELESS_REP","Encryption",&local_448,1);
      local_448 = 0;
      cfgRead("WIRELESS","WEPKeyFormat",&local_448);
      cfgWrite("WIRELESS_REP","WEPKeyFormat",&local_448,1);
      local_448 = 0;
      cfgRead("WIRELESS","WEPKeyLength",&local_448);
      cfgWrite("WIRELESS_REP","WEPKeyLength",&local_448,1);
      local_448 = 0;
      cfgRead("WIRELESS","WEPActiveKey",&local_448);
      cfgWrite("WIRELESS_REP","WEPActiveKey",&local_448,1);
[32m      memset(&local_444,0,0x100);[0m
      cfgRead("WIRELESS","WEPKey0",&local_444);
      cfgWrite("WIRELESS_REP","WEPKey0",&local_444,1);
[32m      memset(&local_444,0,0x100);[0m
      cfgRead("WIRELESS","WEPKey1",&local_444);
      cfgWrite("WIRELESS_REP","WEPKey1",&local_444,1);
[32m      memset(&local_444,0,0x100);[0m
      cfgRead("WIRELESS","WEPKey2",&local_444);
      cfgWrite("WIRELESS_REP","WEPKey2",&local_444,1);
[32m      memset(&local_444,0,0x100);[0m
      cfgRead("WIRELESS","WEPKey3",&local_444);
      cfgWrite("WIRELESS_REP","WEPKey3",&local_444,1);
[32m      memset(&local_444,0,0x100);[0m
      cfgRead("WIRELESS","PreSharedKey",&local_444);
      cfgWrite("WIRELESS_REP","PreSharedKey",&local_444,1);
      get_wlan2_rep(auStack_1b4);
      setWlanRepDrv(auStack_1b4);
    }
  }
  if (((uVar2 == 1) && (iVar1 = FUN_00401710(0x14), iVar1 != 1)) && (uVar3 == 0)) {
[32m    system("/etc/init.d/ipv4 restart 2>/dev/null 1>/dev/null &");[0m
  }
  SIWriteInt(0x14,0);
  if (stdout != (FILE *)0x0) {
    fprintf(stdout,"%d\n",1);
  }
  return 0;
}

[ASK_GPT] 6d84ec994fb14c01
