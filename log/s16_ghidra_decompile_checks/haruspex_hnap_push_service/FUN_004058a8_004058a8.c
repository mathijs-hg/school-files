
undefined4
FUN_004058a8(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  uVar1 = ixmlDocument_createDocument();
  local_34 = ixmlDocument_createElement(uVar1,"PushDCHEvent");
  ixmlElement_setAttribute(local_34,"xmlns","http://purenetworks.com/HNAP1/");
  local_30 = uVar1;
  ixmlNode_appendChild(uVar1,local_34);
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
[32m  sprintf((char *)&local_48,"%d",*param_1);[0m
  ixmlAppendNewElement(uVar1,local_34,"Index",&local_48);
  ixmlAppendNewElement(uVar1,local_34,"Version",&DAT_00415168);
  local_38 = ixmlAppendNewElement(uVar1,local_34,"Sender",0);
  if (0 < param_2) {
    iVar4 = 0;
    puVar5 = param_1;
    do {
      uVar2 = ixmlDocument_createElement(uVar1,"Notifier");
      ixmlAppendNewElement(uVar1,uVar2,"DeviceMacID",param_1 + iVar4 * 0x29 + 0x1c);
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
[32m      sprintf((char *)&local_48,"%d",puVar5[0x21]);[0m
      ixmlAppendNewElement(uVar1,uVar2,"ModuleID",&local_48);
      ixmlAppendNewElement(uVar1,uVar2,"ModuleType",param_1 + iVar4 * 0x29 + 0x22);
      ixmlAppendNewElement(uVar1,uVar2,"SubType",(int)param_1 + iVar4 * 0xa4 + 0xa9);
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
[32m      sprintf((char *)&local_48,"%d",puVar5[0x33]);[0m
      ixmlAppendNewElement(uVar1,uVar2,"EventID",&local_48);
      ixmlAppendNewElement(uVar1,uVar2,"EventDesc",param_1 + iVar4 * 0x29 + 0x34);
      ixmlNode_appendChild(local_38,uVar2);
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 0x29;
    } while (iVar4 < param_2);
  }
  uVar2 = ixmlAppendNewElement(uVar1,local_34,"Receiver",0);
  if (0 < param_3) {
    iVar4 = 0;
    puVar5 = param_1;
    do {
      uVar3 = ixmlDocument_createElement(uVar1,"Reactor");
      ixmlAppendNewElement(uVar1,uVar3,"DeviceMacID",param_1 + iVar4 * 0x2b + 0x53c);
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
[32m      sprintf((char *)&local_48,"%d",puVar5[0x541]);[0m
      ixmlAppendNewElement(uVar1,uVar3,"ModuleID",&local_48);
      ixmlAppendNewElement(uVar1,uVar3,"ModuleType",param_1 + iVar4 * 0x2b + 0x542);
      ixmlAppendNewElement(uVar1,uVar3,"SubType",(int)param_1 + iVar4 * 0xac + 0x1529);
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
[32m      sprintf((char *)&local_48,"%d",puVar5[0x553]);[0m
      ixmlAppendNewElement(uVar1,uVar3,"ActionID",&local_48);
      ixmlAppendNewElement(uVar1,uVar3,"ActionDesc",param_1 + iVar4 * 0x2b + 0x554);
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
[32m      sprintf((char *)&local_48,"%d",puVar5[0x565]);[0m
      ixmlAppendNewElement(uVar1,uVar3,"DelayAction",&local_48);
      ixmlNode_appendChild(uVar2,uVar3);
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 0x2b;
    } while (iVar4 < param_3);
  }
  ixmlAppendNewElement(uVar1,local_34,"TimeStamp",param_4);
  ixmlAppendNewElement(uVar1,local_34,"SequenceNo",param_5);
  uVar2 = ixmlNode_cloneNode(local_30,1);
  ixmlDocument_free(uVar1);
  return uVar2;
}

[ASK_GPT] f1ee736a1820ff26
