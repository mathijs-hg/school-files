
undefined4
FUN_00405228(undefined4 *param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char *__format;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 *local_70;
  undefined4 *local_6c;
  int local_68;
  char *local_64;
  char *local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  char *local_48;
  undefined4 local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  undefined4 *local_30;
  int local_2c;
  
  uVar1 = ixmlDocument_createDocument();
  if (0 < param_3) {
    local_68 = 0;
    local_48 = "%d";
    local_40 = "Reactor";
    local_5c = "DeviceMacID";
    local_58 = "ModuleID";
    local_54 = "ModuleType";
    local_50 = "SubType";
    local_3c = "ActionID";
    local_38 = "ActionDesc";
    local_34 = "DelayAction";
    local_4c = "Notifier";
    local_6c = param_1;
    local_30 = param_1;
    do {
      if ((*(char *)(local_6c + 0x566) != '\0') && (*(char *)((int)local_6c + 0x1599) == '\0')) {
        local_44 = ixmlDocument_createElement(uVar1,"PushDCHEvent");
        ixmlNode_appendChild(uVar1,local_44);
        local_80 = 0;
        local_7c = 0;
        local_78 = 0;
        local_74 = 0;
[32m[32m        sprintf((char *)&local_80,local_48,*param_1);[0m[0m
        ixmlAppendNewElement(uVar1,local_44,"Index",&local_80);
        ixmlAppendNewElement(uVar1,local_44,"Version",&DAT_00415168);
        local_70 = (undefined4 *)ixmlAppendNewElement(uVar1,local_44,"Sender",0);
        __format = local_48;
        if (0 < (int)param_2) {
          iVar4 = 0;
          local_64 = "EventID";
          local_60 = "EventDesc";
          puVar6 = local_30;
          local_2c = param_3;
          do {
            if (*(char *)((int)puVar6 + 0x111) != '\0') {
              uVar2 = ixmlDocument_createElement(uVar1,local_4c);
              ixmlAppendNewElement(uVar1,uVar2,local_5c,param_1 + iVar4 * 0x29 + 0x1c);
              local_80 = 0;
              local_7c = 0;
              local_78 = 0;
              local_74 = 0;
[32m[32m              sprintf((char *)&local_80,__format,puVar6[0x21]);[0m[0m
              ixmlAppendNewElement(uVar1,uVar2,local_58,&local_80);
              ixmlAppendNewElement(uVar1,uVar2,local_54,param_1 + iVar4 * 0x29 + 0x22);
              ixmlAppendNewElement(uVar1,uVar2,local_50,(int)param_1 + iVar4 * 0xa4 + 0xa9);
              local_80 = 0;
              local_7c = 0;
              local_78 = 0;
              local_74 = 0;
[32m[32m              sprintf((char *)&local_80,__format,puVar6[0x33]);[0m[0m
              ixmlAppendNewElement(uVar1,uVar2,local_64,&local_80);
              ixmlAppendNewElement(uVar1,uVar2,local_60,param_1 + iVar4 * 0x29 + 0x34);
              ixmlNode_appendChild(local_70,uVar2);
            }
            iVar4 = iVar4 + 1;
            puVar6 = puVar6 + 0x29;
            param_3 = local_2c;
          } while (iVar4 < (int)param_2);
        }
        local_64 = (char *)ixmlAppendNewElement(uVar1,local_44,"Receiver",0);
        iVar4 = local_68 * 0x2b;
        iVar5 = 0;
        local_70 = &local_80;
        puVar6 = local_30;
        local_60 = param_2;
        do {
          if (*(char *)(puVar6 + 0x566) != '\0') {
            iVar3 = strcmp((char *)(param_1 + iVar4 + 0x53c),
                           (char *)(param_1 + iVar5 * 0x2b + 0x53c));
            if ((iVar3 == 0) && (*(char *)((int)puVar6 + 0x1599) == '\0')) {
              uVar2 = ixmlDocument_createElement(uVar1,local_40);
              ixmlAppendNewElement(uVar1,uVar2,local_5c,param_1 + iVar5 * 0x2b + 0x53c);
              local_80 = 0;
              local_7c = 0;
              local_78 = 0;
              local_74 = 0;
[32m[32m[32m              sprintf((char *)local_70,local_48,puVar6[0x541]);[0m[0m[0m
              ixmlAppendNewElement(uVar1,uVar2,local_58,local_70);
              ixmlAppendNewElement(uVar1,uVar2,local_54,param_1 + iVar5 * 0x2b + 0x542);
              ixmlAppendNewElement(uVar1,uVar2,local_50,(int)param_1 + iVar5 * 0xac + 0x1529);
              local_80 = 0;
              local_7c = 0;
              local_78 = 0;
              local_74 = 0;
[32m[32m[32m              sprintf((char *)local_70,local_48,puVar6[0x553]);[0m[0m[0m
              ixmlAppendNewElement(uVar1,uVar2,local_3c,local_70);
              ixmlAppendNewElement(uVar1,uVar2,local_38,param_1 + iVar5 * 0x2b + 0x554);
              local_80 = 0;
              local_7c = 0;
              local_78 = 0;
              local_74 = 0;
[32m[32m[32m              sprintf((char *)local_70,local_48,puVar6[0x565]);[0m[0m[0m
              ixmlAppendNewElement(uVar1,uVar2,local_34,local_70);
              ixmlNode_appendChild(local_64,uVar2);
              *(undefined *)((int)puVar6 + 0x1599) = 1;
            }
          }
          param_2 = local_60;
          iVar5 = iVar5 + 1;
          puVar6 = puVar6 + 0x2b;
        } while (iVar5 < param_3);
        ixmlAppendNewElement(uVar1,local_44,"TimeStamp",param_4);
        ixmlAppendNewElement(uVar1,local_44,"SequenceNo",param_5);
      }
      local_68 = local_68 + 1;
      local_6c = local_6c + 0x2b;
    } while (local_68 < param_3);
  }
  uVar2 = ixmlNode_cloneNode(uVar1,1);
  ixmlDocument_free(uVar1);
  return uVar2;
}

[ASK_GPT] 0bc0e45722af3622
