
undefined4 FUN_00404e70(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint local_178;
  uint local_174;
  char local_170;
  undefined auStack_16f [31];
  char local_150;
  undefined auStack_14f [255];
  timeval local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined local_38;
  undefined4 local_30;
  
  local_178 = 0;
  local_174 = 0;
  local_170 = '\0';
[32m  memset(auStack_16f,0,0x1f);[0m
  local_150 = '\0';
[32m  memset(auStack_14f,0,0xff);[0m
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  gettimeofday(&local_50,(__timezone_ptr_t)0x0);
[32m  sprintf((char *)&local_48,"%ld",local_50.tv_sec);[0m
  uVar1 = ixmlDocument_createDocument();
  uVar2 = ixmlDocument_createElement(uVar1,"ReportStatus");
  local_30 = uVar1;
  ixmlNode_appendChild(uVar1,uVar2);
  local_178 = 0;
  local_174 = 0;
  net_get_hwaddr(&DAT_00414bc0,&local_178);
  sprintf(&local_170,"%02X:%02X:%02X:%02X:%02X:%02X",local_178 >> 0x18,local_178 >> 0x10 & 0xff,
[32m          local_178 >> 8 & 0xff,local_178 & 0xff,local_174 >> 0x18,local_174 >> 0x10 & 0xff);[0m
  ixmlAppendNewElement(uVar1,uVar2,"DeviceMacId",&local_170);
[32m  sprintf(&local_150,"%d",param_2);[0m
  ixmlAppendNewElement(uVar1,uVar2,"ModuleID",&local_150);
[32m  sprintf(&local_150,"%d",param_3);[0m
  ixmlAppendNewElement(uVar1,uVar2,"StatusID",&local_150);
  uVar3 = ixmlAppendNewElement(uVar1,uVar2,"Parameters",0);
  if (param_3 == 0x1d52f) {
    ixmlAppendNewElement(uVar1,uVar3,"string",param_4);
  }
  else if ((param_3 == 0x1d52e) || (param_3 == 0x1d538)) {
[32m    sprintf(&local_150,"%d",param_1);[0m
    ixmlAppendNewElement(uVar1,uVar3,"string",&local_150);
[32m    memset(&local_150,0,0x100);[0m
    cfgRead("CAMSYSTEM","CameraName",&local_150);
    ixmlAppendNewElement(uVar1,uVar3,"string",&local_150);
  }
  ixmlAppendNewElement(uVar1,uVar2,"Timestamp",&local_48);
  uVar2 = ixmlNode_cloneNode(local_30,1);
  ixmlDocument_free(uVar1);
  return uVar2;
}

[ASK_GPT] 11b1dcb2d986236a
