
undefined4 FUN_00410640(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
[32m  pcVar1 = getenv("REMOTE_ADDR");[0m
  uVar2 = ixmlDocument_createDocument();
  uVar3 = ixmlDocument_createElement(uVar2,"GetNotifierSettingsResponse");
  ixmlElement_setAttribute(uVar3,"xmlns","http://purenetworks.com/HNAP1/");
  ixmlNode_appendChild(uVar2,uVar3);
  if ((pcVar1 != (char *)0x0) && (pcVar1 = strstr(pcVar1,"127.0.0.1"), pcVar1 != (char *)0x0)) {
    iVar4 = ixmlLoadDocument("/mnt/flash/config/hnap_notifier.xml");
    if (iVar4 == 0) {
      ixmlAppendNewElement(uVar2,uVar3,"GetNotifierSettingsResult","ERROR");
    }
    else {
      ixmlAppendNewElement(uVar2,uVar3,"GetNotifierSettingsResult",&DAT_004151ec);
      uVar5 = ixmlDocument_getElementById(iVar4,"NotifierSettingsList");
      uVar5 = ixmlNode_cloneNode(uVar5,1);
      ixmlNode_appendChild(uVar3,uVar5);
    }
    uVar3 = ixmlNode_cloneNode(uVar2,1);
    ixmlDocument_free(uVar2);
    ixmlDocument_free(iVar4);
    return uVar3;
  }
  ixmlAppendNewElement(uVar2,uVar3,"GetNotifierSettingsResult","ERROR");
  uVar3 = ixmlNode_cloneNode(uVar2,1);
  ixmlDocument_free(uVar2);
  ixmlDocument_free(0);
  return uVar3;
}

[ASK_GPT] 53d08621638bc0a0
