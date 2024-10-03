
undefined4 FUN_00410864(undefined4 param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  FILE *__s;
  size_t __n;
  
[32m  pcVar1 = getenv("REMOTE_ADDR");[0m
  if ((pcVar1 != (char *)0x0) && (pcVar1 = strstr(pcVar1,"127.0.0.1"), pcVar1 != (char *)0x0)) {
    uVar2 = ixmlGetElementByTag(param_1,"NotifierSettingsList");
    pcVar1 = (char *)ixmlPrintNode(uVar2);
[32m    __s = fopen("/mnt/flash/config/hnap_notifier.xml","wb");[0m
    __n = strlen(pcVar1);
    fwrite(pcVar1,1,__n,__s);
    fflush(__s);
    fclose(__s);
    ixmlFreeDOMString(pcVar1);
    uVar2 = ixmlDocument_createDocument();
    uVar3 = ixmlDocument_createElement(uVar2,"SetNotifierSettingsResponse");
    ixmlElement_setAttribute(uVar3,"xmlns","http://purenetworks.com/HNAP1/");
    ixmlNode_appendChild(uVar2,uVar3);
    ixmlAppendNewElement(uVar2,uVar3,"SetNotifierSettingsResult",&DAT_004151ec);
    uVar3 = ixmlNode_cloneNode(uVar2,1);
    ixmlDocument_free(uVar2);
    return uVar3;
  }
  uVar2 = ixmlDocument_createDocument();
  uVar3 = ixmlDocument_createElement(uVar2,"SetNotifierSettingsResponse");
  ixmlElement_setAttribute(uVar3,"xmlns","http://purenetworks.com/HNAP1/");
  ixmlNode_appendChild(uVar2,uVar3);
  ixmlAppendNewElement(uVar2,uVar3,"SetNotifierSettingsResult","ERROR");
  uVar3 = ixmlNode_cloneNode(uVar2,1);
  ixmlDocument_free(uVar2);
  return uVar3;
}

[ASK_GPT] 637d9a53b0ca7b96
