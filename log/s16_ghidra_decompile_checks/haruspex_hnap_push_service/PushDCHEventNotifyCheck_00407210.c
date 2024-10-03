
/* WARNING: Type propagation algorithm not settling */

undefined4 PushDCHEventNotifyCheck(int param_1,code *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  char *pcVar18;
  int aiStack_55ff0 [10];
  char acStack_55fc7 [71];
  char acStack_55f80 [24];
  undefined auStack_55f68 [33];
  char acStack_55f47 [35];
  int iStack_55f24;
  undefined auStack_55f20 [5152];
  char acStack_54b00 [20];
  undefined4 uStack_54aec;
  undefined auStack_54ae8 [33];
  char acStack_54ac7 [35];
  int iStack_54aa4;
  undefined auStack_54aa0 [68];
  int aiStack_54a5c [1337];
  undefined auStack_53578 [33];
  int aiStack_53557 [84697];
  char local_9f0;
  undefined auStack_9ef [511];
  int local_7f0;
  int local_7ec;
  undefined4 local_7e8;
  uint local_7e4;
  undefined4 local_7e0;
  undefined4 local_7dc;
  undefined4 local_7d8;
  undefined4 local_7d4;
  undefined4 local_7d0;
  undefined4 local_7cc;
  char local_7c8;
  undefined auStack_7c7 [31];
  int local_7a8;
  int local_7a4;
  int local_7a0;
  undefined4 local_79c;
  undefined8 local_69c;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined local_38c;
  char *local_98;
  char *local_94;
  char *local_90;
  char *local_8c;
  int local_88;
  char *local_84;
  char *local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  char *local_70;
  int *local_6c;
  int *local_68;
  int local_64;
  int local_60;
  undefined *local_5c;
  int local_58;
  int *local_54;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int *local_44;
  char *local_40;
  char *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  int *local_30;
  
  local_9f0 = '\0';
[32m  memset(auStack_9ef,0,0x1ff);[0m
  local_7f0 = 0;
  local_7ec = 0;
  local_7e8 = local_7e8 & 0xffffff;
[32m  memset((void *)((int)&local_7e8 + 1),0,0x1f);[0m
  local_7c8 = '\0';
[32m  memset(auStack_7c7,0,0x1f);[0m
  local_58 = ixmlLoadDocument("/mnt/flash/config/hnap_policy.xml");
  if (local_58 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    local_60 = ixmlElement_getElementsByTagName(local_58,"PolicyInfo");
    if (local_60 == 0) {
[32m      memset(aiStack_55ff0,0,0x55600);[0m
      local_64 = 0;
    }
    else {
      local_5c = (undefined *)ixmlNodeList_length(local_60);
[32m      memset(aiStack_55ff0,0,0x55600);[0m
      if ((int)local_5c < 1) {
        local_64 = 0;
      }
      else {
        local_64 = 0;
        local_98 = "ModuleID";
        local_94 = "ModuleType";
        local_90 = "SubType";
        local_80 = "EventID";
        local_7c = "EventDesc";
        local_78 = "ActionID";
        local_74 = "ActionDesc";
        local_70 = "DelayAction";
        local_68 = aiStack_55ff0;
        do {
          local_6c = (int *)ixmlNodeList_item(local_60,local_64);
[32m          memset(&local_9f0,0,0x200);[0m
          iVar3 = ixmlGetElementValueByTag_s(local_6c,"Index",&local_9f0,0x200);
          if (iVar3 == 0) {
            iVar3 = atoi(&local_9f0);
            *local_68 = iVar3;
          }
          else {
            *local_68 = 0;
          }
[32m          memset(&local_9f0,0,0x200);[0m
          iVar3 = ixmlGetElementValueByTag_s(local_6c,"PolicyEnabled",&local_9f0,0x200);
          if (iVar3 == 0) {
            iVar3 = strcasecmp(&local_9f0,"true");
            if (iVar3 == 0) {
              local_68[1] = 1;
            }
            else {
              local_68[1] = 0;
            }
          }
          else {
            local_68[1] = 0;
          }
[32m          memset(&local_9f0,0,0x200);[0m
          iVar3 = ixmlGetElementValueByTag_s(local_6c,"PolicyName",&local_9f0,0x200);
          if (iVar3 == 0) {
[32m[32m            strcpy((char *)(aiStack_55ff0 + (local_64 * 0x556 + 1) * 2),&local_9f0);[0m[0m
          }
          else {
            *(undefined *)(aiStack_55ff0 + (local_64 * 0x556 + 1) * 2) = 0;
          }
[32m          memset(&local_9f0,0,0x200);[0m
          iVar3 = ixmlGetElementValueByTag_s(local_6c,"PolicyDesc",&local_9f0,0x200);
          if (iVar3 == 0) {
[32m[32m            strcpy(acStack_55fc7 + local_64 * 0x2ab0,&local_9f0);[0m[0m
          }
          else {
            acStack_55fc7[local_64 * 0x2ab0] = '\0';
          }
[32m          memset(&local_9f0,0,0x200);[0m
          iVar3 = ixmlGetElementValueByTag_s(local_6c,"PolicyNotification",&local_9f0,0x200);
          if (iVar3 == 0) {
            iVar3 = strcasecmp(&local_9f0,"true");
            if (iVar3 == 0) {
              local_68[0x1b] = 1;
            }
            else {
              local_68[0x1b] = 0;
            }
          }
          else {
            local_68[0x1b] = 0;
          }
          iVar3 = ixmlGetElementByTag_s(local_6c,"Sender",&local_7f0);
          if (iVar3 == 0) {
            local_88 = ixmlElement_getElementsByTagName(local_7f0,"Notifier");
            if (local_88 == 0) {
              iVar5 = 0;
            }
            else {
              iVar4 = ixmlNodeList_length(local_88);
              iVar3 = local_64;
              if (iVar4 < 1) goto LAB_00407cb0;
              piVar16 = &iStack_55f24 + local_64 * 0xaac;
              iVar5 = 0;
              iVar6 = local_64 * 0x2ab0;
              do {
                uVar2 = ixmlNodeList_item(local_88,iVar5);
[32m                memset(&local_9f0,0,0x200);[0m
                iVar14 = ixmlGetElementValueByTag_s(uVar2,"DeviceMacID",&local_9f0,0x200);
                if (iVar14 == 0) {
[32m[32m                  strcpy((char *)(aiStack_55ff0 + iVar3 * 0xaac + iVar5 * 0x29 + 0x1c),&local_9f0);[0m[0m
                }
                else {
                  acStack_55f80[iVar5 * 0xa4 + iVar6] = '\0';
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar14 = ixmlGetElementValueByTag_s(uVar2,local_98,&local_9f0,0x200);
                if (iVar14 == 0) {
                  iVar14 = atoi(&local_9f0);
                  piVar16[-0x12] = iVar14;
                }
                else {
                  piVar16[-0x12] = 0;
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar14 = ixmlGetElementValueByTag_s(uVar2,local_94,&local_9f0,0x200);
                if (iVar14 == 0) {
[32m[32m                  strcpy((char *)(aiStack_55ff0 + iVar3 * 0xaac + iVar5 * 0x29 + 0x22),&local_9f0);[0m[0m
                }
                else {
                  auStack_55f68[iVar5 * 0xa4 + iVar6] = 0;
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar14 = ixmlGetElementValueByTag_s(uVar2,local_90,&local_9f0,0x200);
                if (iVar14 == 0) {
[32m[32m                  strcpy(acStack_55f47 + iVar5 * 0xa4 + iVar6,&local_9f0);[0m[0m
                }
                else {
                  acStack_55f47[iVar5 * 0xa4 + iVar6] = '\0';
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar14 = ixmlGetElementValueByTag_s(uVar2,local_80,&local_9f0,0x200);
                if (iVar14 == 0) {
                  iVar14 = atoi(&local_9f0);
                  *piVar16 = iVar14;
                }
                else {
                  *piVar16 = 0;
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar14 = ixmlGetElementValueByTag_s(uVar2,local_7c,&local_9f0,0x200);
                if (iVar14 == 0) {
[32m[32m                  strcpy((char *)(aiStack_55ff0 + iVar3 * 0xaac + iVar5 * 0x29 + 0x34),&local_9f0);[0m[0m
                }
                else {
                  auStack_55f20[iVar5 * 0xa4 + iVar6] = 0;
                }
                iVar5 = iVar5 + 1;
              } while ((iVar5 < iVar4) && (piVar16 = piVar16 + 0x29, iVar5 != 0x20));
            }
          }
          else {
            local_7f0 = 0;
            local_88 = 0;
LAB_00407cb0:
            iVar5 = 0;
          }
          local_68[0xa9c] = iVar5;
          iVar3 = ixmlGetElementByTag_s(local_6c,"Receiver",&local_7ec);
          if (iVar3 == 0) {
            local_8c = (char *)ixmlElement_getElementsByTagName(local_7ec,"Reactor");
            if (local_8c == (char *)0x0) {
              iVar4 = 0;
            }
            else {
              local_84 = (char *)ixmlNodeList_length(local_8c);
              iVar3 = local_64;
              if ((int)local_84 < 1) goto LAB_00408158;
              piVar16 = aiStack_54a5c + local_64 * 0xaac;
              iVar4 = 0;
              iVar5 = local_64 * 0x2ab0;
              do {
                uVar2 = ixmlNodeList_item(local_8c,iVar4);
[32m                memset(&local_9f0,0,0x200);[0m
                iVar6 = ixmlGetElementValueByTag_s(uVar2,"DeviceMacID",&local_9f0,0x200);
                if (iVar6 == 0) {
[32m[32m                  strcpy((char *)(aiStack_55ff0 + iVar3 * 0xaac + iVar4 * 0x2b + 0x53c),&local_9f0);[0m[0m
                }
                else {
                  acStack_54b00[iVar4 * 0xac + iVar5] = '\0';
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar6 = ixmlGetElementValueByTag_s(uVar2,local_98,&local_9f0,0x200);
                if (iVar6 == 0) {
                  iVar6 = atoi(&local_9f0);
                  piVar16[-0x24] = iVar6;
                }
                else {
                  piVar16[-0x24] = 0;
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar6 = ixmlGetElementValueByTag_s(uVar2,local_94,&local_9f0,0x200);
                if (iVar6 == 0) {
[32m[32m                  strcpy((char *)(aiStack_55ff0 + iVar3 * 0xaac + iVar4 * 0x2b + 0x542),&local_9f0);[0m[0m
                }
                else {
                  auStack_54ae8[iVar4 * 0xac + iVar5] = 0;
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar6 = ixmlGetElementValueByTag_s(uVar2,local_90,&local_9f0,0x200);
                if (iVar6 == 0) {
[32m[32m                  strcpy(acStack_54ac7 + iVar4 * 0xac + iVar5,&local_9f0);[0m[0m
                }
                else {
                  acStack_54ac7[iVar4 * 0xac + iVar5] = '\0';
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar6 = ixmlGetElementValueByTag_s(uVar2,local_78,&local_9f0,0x200);
                if (iVar6 == 0) {
                  iVar6 = atoi(&local_9f0);
                  piVar16[-0x12] = iVar6;
                }
                else {
                  piVar16[-0x12] = 0;
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar6 = ixmlGetElementValueByTag_s(uVar2,local_74,&local_9f0,0x200);
                if (iVar6 == 0) {
[32m[32m                  strcpy((char *)(aiStack_55ff0 + iVar3 * 0xaac + iVar4 * 0x2b + 0x554),&local_9f0);[0m[0m
                }
                else {
                  auStack_54aa0[iVar4 * 0xac + iVar5] = 0;
                }
[32m                memset(&local_9f0,0,0x200);[0m
                iVar6 = ixmlGetElementValueByTag_s(uVar2,local_70,&local_9f0,0x200);
                if (iVar6 == 0) {
                  iVar6 = atoi(&local_9f0);
                  *piVar16 = iVar6;
                }
                else {
                  *piVar16 = 0;
                }
                iVar4 = iVar4 + 1;
              } while ((iVar4 < (int)local_84) && (piVar16 = piVar16 + 0x2b, iVar4 != 0x20));
            }
          }
          else {
            local_7ec = 0;
            local_8c = (char *)0x0;
LAB_00408158:
            iVar4 = 0;
          }
          local_68[0xa9d] = iVar4;
[32m          memset(&local_9f0,0,0x200);[0m
          iVar3 = ixmlGetElementValueByTag_s(local_6c,&DAT_00414cec,&local_9f0,0x200);
          if (iVar3 == 0) {
[32m[32m            strcpy((char *)(aiStack_55ff0 + local_64 * 0xaac + 0xa9e),&local_9f0);[0m[0m
          }
          else {
            auStack_53578[local_64 * 0x2ab0] = 0;
          }
          ixmlNodeList_free(local_8c);
          ixmlNodeList_free(local_88);
          if (local_7ec != 0) {
            ixmlNode_free();
            local_7ec = 0;
          }
          if (local_7f0 != 0) {
            ixmlNode_free();
            local_7f0 = 0;
          }
          local_64 = local_64 + 1;
        } while ((local_64 < (int)local_5c) && (local_68 = local_68 + 0xaac, local_64 != 0x20));
      }
    }
    ixmlNodeList_free(local_60);
    ixmlDocument_free(local_58);
    local_7e8 = 0;
    local_7e4 = 0;
    local_7e0 = 0;
    local_7dc = 0;
    local_7d8 = 0;
    local_7d4 = 0;
    local_7d0 = 0;
    local_7cc = 0;
    net_get_hwaddr(&DAT_00414bc0);
    sprintf(&local_7c8,"%02X:%02X:%02X:%02X:%02X:%02X",local_7e8 >> 0x18,local_7e8 >> 0x10 & 0xff,
[32m            local_7e8 >> 8 & 0xff,local_7e8 & 0xff,local_7e4 >> 0x18,local_7e4 >> 0x10 & 0xff);[0m
    local_4c = initEventMsg();
    piVar16 = aiStack_55ff0 + 1;
    if (0 < local_64) {
      local_60 = 0;
      local_30 = &local_7a8;
      local_3c = "mxuvc qparam dewarp0 Q_DEWARP_CMP_SET_LENS_MILI_HSHIFT 0 2>/dev/null 1>/dev/null";
      local_34 = (undefined4 *)0x41586c;
      local_40 = 
      "mxuvc qparam dewarp0 Q_DEWARP_CMP_SET_LENS_MILI_HSHIFT 1000000000 2>/dev/null 1>/dev/null";
      local_38 = (undefined4 *)0x4157c4;
      local_90 = "422015";
      local_8c = "422017";
      do {
        piVar17 = local_30;
        if (*piVar16 == 1) {
          *local_30 = 0;
          piVar17[1] = 0;
          piVar17[2] = 0;
          if (0 < piVar16[0xa9b]) {
            local_6c = aiStack_55ff0 + (local_60 * 0x556 + 1) * 2;
            local_74 = (char *)(piVar16 + -1);
            local_5c = auStack_53578 + local_60 * 0x2ab0;
            local_7c = (char *)(aiStack_53557 + local_60 * 0xaac);
            piVar17 = &iStack_55f24 + local_60 * 0xaac;
            local_58 = 0;
            local_68 = (int *)0x0;
            local_50 = 0;
            local_88 = 0;
            local_98 = (char *)(local_60 * 0x2ab0);
            local_44 = &iStack_54aa4 + local_60 * 0xaac;
            local_84 = "422019";
            local_54 = local_6c;
            do {
              if (((*piVar17 == param_1) &&
                  (iVar3 = strcasecmp(acStack_55f80 + (int)(local_98 + local_88 * 0xa4),&local_7c8),
                  iVar3 == 0)) && (0 < piVar16[0xa9c])) {
                local_70 = acStack_55f80 + (int)(local_98 + local_88 * 0xa4);
                local_48 = acStack_55f47 + (int)(local_98 + local_88 * 0xa4);
                iVar3 = 0;
                local_80 = "422021";
                local_78 = "422022";
                local_94 = (char *)&local_79c;
                piVar15 = local_44;
                do {
                  iVar4 = FUN_00402d50(*piVar15);
                  pcVar18 = local_98 + iVar3 * 0xac;
                  iVar5 = FUN_00402e94(acStack_54b00 + (int)pcVar18);
                  iVar14 = *piVar15;
                  iVar6 = atoi(local_90);
                  if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                    local_79c._0_1_ = 0;
[32m                    memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                    fprintf(stderr,"PushDCHEventNotifyCheck -> Event: %d ACTION_ID_SNAP_NOTIFY\n",
                            *piVar17);
                    sprintf(local_94,
                            "/usr/sbin/msger eventd 0 eiotsnapshottrigger 1 \"%d %s %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                            ,0,local_70,piVar17[-0x12],0,local_6c);[0m[0m
[32m[32m                    system(local_94);[0m[0m
                    iVar4 = FUN_00402dc8(local_74);
                    if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                       (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                       ((int)&uStack_54aec +
                                                       (int)(local_98 + iVar4 * 0xac)),0x1d52f,
                                             local_54), iVar4 != 0)) {
                      pcVar18 = (char *)ixmlNodetoString(iVar4);
                      if (pcVar18 != (char *)0x0) {
                        sVar7 = strlen(pcVar18);
                        fillEventMessageContent(local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                        ixmlFreeDOMString(pcVar18);
                      }
                      ixmlNode_free(iVar4);
                    }
                  }
                  else {
                    iVar6 = atoi(local_8c);
                    if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                      local_79c._0_1_ = 0;
[32m                      memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                      fprintf(stderr,"PushDCHEventNotifyCheck -> Event: %d ACTION_ID_SNAP_MYDLINK\n"
                              ,*piVar17);
                      sprintf(local_94,
                              "/usr/sbin/msger eventd 0 eiotsnapshottrigger 1 \"%d %s %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                              ,1,local_70,piVar17[-0x12],0,local_6c);[0m[0m
[32m[32m                      system(local_94);[0m[0m
                      iVar4 = FUN_00402dc8(local_74);
                      if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                         (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                         ((int)&uStack_54aec +
                                                         (int)(local_98 + iVar4 * 0xac)),0x1d52f,
                                               local_54), iVar4 != 0)) {
                        pcVar18 = (char *)ixmlNodetoString(iVar4);
                        if (pcVar18 != (char *)0x0) {
                          sVar7 = strlen(pcVar18);
                          fillEventMessageContent(local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                          ixmlFreeDOMString(pcVar18);
                        }
                        ixmlNode_free(iVar4);
                      }
                    }
                    else {
                      iVar6 = atoi(local_84);
                      if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                        local_79c._0_1_ = 0;
[32m                        memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                        fprintf(stderr,
                                "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_VCLIP_NOTIFY\n",
                                *piVar17);
                        sprintf(local_94,
                                "/usr/sbin/msger eventd 0 eiotvideocliptrigger 1 \"%d %s %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                ,0,local_70,piVar17[-0x12],0,local_6c);[0m[0m
[32m[32m                        system(local_94);[0m[0m
                        iVar4 = FUN_00402dc8(local_74);
                        if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                           (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                           ((int)&uStack_54aec +
                                                           (int)(local_98 + iVar4 * 0xac)),0x1d52f,
                                                 local_54), iVar4 != 0)) {
                          pcVar18 = (char *)ixmlNodetoString(iVar4);
                          if (pcVar18 != (char *)0x0) {
                            sVar7 = strlen(pcVar18);
                            fillEventMessageContent(local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                            ixmlFreeDOMString(pcVar18);
                          }
                          ixmlNode_free(iVar4);
                        }
                      }
                      else {
                        iVar6 = atoi(local_80);
                        if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                          local_79c._0_1_ = 0;
[32m                          memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                          fprintf(stderr,
                                  "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_VCLIP_MYDLINK\n",
                                  *piVar17);
                          sprintf(local_94,
                                  "/usr/sbin/msger eventd 0 eiotvideocliptrigger 1 \"%d %s %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                  ,1,local_70,piVar17[-0x12],0,local_6c);[0m[0m
[32m[32m                          system(local_94);[0m[0m
                          iVar4 = FUN_00402dc8(local_74);
                          if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                             (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                             ((int)&uStack_54aec +
                                                             (int)(local_98 + iVar4 * 0xac)),0x1d52f
                                                   ,local_54), iVar4 != 0)) {
                            pcVar18 = (char *)ixmlNodetoString(iVar4);
                            if (pcVar18 != (char *)0x0) {
                              sVar7 = strlen(pcVar18);
                              fillEventMessageContent
                                        (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                              ixmlFreeDOMString(pcVar18);
                            }
                            ixmlNode_free(iVar4);
                          }
                        }
                        else {
                          iVar6 = atoi(local_78);
                          if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                            local_79c._0_1_ = 0;
[32m                            memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                            fprintf(stderr,
                                    "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_SNAP_STORAGE\n",
                                    *piVar17);
                            sprintf(local_94,
                                    "/usr/sbin/msger eventd 0 eiotsnapshottrigger 1 \"%d %s %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                    ,4,local_70,piVar17[-0x12],0,local_6c);[0m[0m
[32m[32m                            system(local_94);[0m[0m
                            iVar4 = FUN_00402dc8(local_74);
                            if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                               (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                               ((int)&uStack_54aec +
                                                               (int)(local_98 + iVar4 * 0xac)),
                                                     0x1d52f,local_54), iVar4 != 0)) {
                              pcVar18 = (char *)ixmlNodetoString(iVar4);
                              if (pcVar18 != (char *)0x0) {
                                sVar7 = strlen(pcVar18);
                                fillEventMessageContent
                                          (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                                ixmlFreeDOMString(pcVar18);
                              }
                              ixmlNode_free(iVar4);
                            }
                          }
                          else {
                            iVar6 = atoi("422023");
                            if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                              local_79c._0_1_ = 0;
[32m                              memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                              fprintf(stderr,
                                      "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_VCLIP_STORAGE\n"
                                      ,*piVar17);
                              sprintf(local_94,
                                      "/usr/sbin/msger eventd 0 eiotvideocliptrigger 1 \"%d %s %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                      ,4,local_70,piVar17[-0x12],0,local_6c);[0m[0m
[32m[32m                              system(local_94);[0m[0m
                              iVar4 = FUN_00402dc8(local_74);
                              if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                 (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                 ((int)&uStack_54aec +
                                                                 (int)(local_98 + iVar4 * 0xac)),
                                                       0x1d52f,local_54), iVar4 != 0)) {
                                pcVar18 = (char *)ixmlNodetoString(iVar4);
                                if (pcVar18 != (char *)0x0) {
                                  sVar7 = strlen(pcVar18);
                                  fillEventMessageContent
                                            (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                                  ixmlFreeDOMString(pcVar18);
                                }
                                ixmlNode_free(iVar4);
                              }
                            }
                            else {
                              iVar6 = atoi("422012");
                              if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                                local_79c._0_1_ = 0;
[32m                                memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                                fprintf(stderr,
                                        "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_PRIVACY_MODE_ON\n"
                                        ,*piVar17);
                                puVar9 = (undefined4 *)local_40;
                                puVar11 = (undefined4 *)local_94;
                                do {
                                  puVar10 = puVar11;
                                  puVar8 = puVar9;
                                  uVar13 = puVar8[1];
                                  uVar12 = puVar8[2];
                                  uVar2 = puVar8[3];
                                  *puVar10 = *puVar8;
                                  puVar10[1] = uVar13;
                                  puVar10[2] = uVar12;
                                  puVar10[3] = uVar2;
                                  puVar9 = puVar8 + 4;
                                  puVar11 = puVar10 + 4;
                                } while (puVar9 != local_38);
                                uVar2 = puVar8[5];
                                puVar10[4] = *puVar9;
                                puVar10[5] = uVar2;
                                *(undefined2 *)(puVar10 + 6) = *(undefined2 *)(puVar8 + 6);
[32m[32m                                system(local_94);[0m[0m
                                iVar4 = FUN_00402dc8(local_74);
                                if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                   (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                   ((int)&uStack_54aec +
                                                                   (int)(local_98 + iVar4 * 0xac)),
                                                         0x1d52f,local_54), iVar4 != 0)) {
                                  pcVar18 = (char *)ixmlNodetoString(iVar4);
                                  if (pcVar18 != (char *)0x0) {
                                    sVar7 = strlen(pcVar18);
                                    fillEventMessageContent
                                              (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                                    ixmlFreeDOMString(pcVar18);
                                  }
                                  ixmlNode_free(iVar4);
                                }
                              }
                              else {
                                iVar6 = atoi("422013");
                                if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                                  local_79c._0_1_ = 0;
[32m                                  memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                                  fprintf(stderr,
                                          "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_PRIVACY_MODE_OFF\n"
                                          ,*piVar17);
                                  puVar9 = (undefined4 *)local_3c;
                                  puVar11 = (undefined4 *)local_94;
                                  do {
                                    uVar13 = puVar9[1];
                                    uVar12 = puVar9[2];
                                    uVar2 = puVar9[3];
                                    *puVar11 = *puVar9;
                                    puVar11[1] = uVar13;
                                    puVar11[2] = uVar12;
                                    puVar11[3] = uVar2;
                                    puVar9 = puVar9 + 4;
                                    puVar11 = puVar11 + 4;
                                  } while (puVar9 != local_34);
                                  *(char *)puVar11 = *(char *)puVar9;
[32m[32m                                  system(local_94);[0m[0m
                                  iVar4 = FUN_00402dc8(local_74);
                                  if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                     (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                     ((int)&uStack_54aec +
                                                                     (int)(local_98 + iVar4 * 0xac))
                                                           ,0x1d52f,local_54), iVar4 != 0)) {
                                    pcVar18 = (char *)ixmlNodetoString(iVar4);
                                    if (pcVar18 != (char *)0x0) {
                                      sVar7 = strlen(pcVar18);
                                      fillEventMessageContent
                                                (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                                      ixmlFreeDOMString(pcVar18);
                                    }
                                    ixmlNode_free(iVar4);
                                  }
                                }
                                else {
                                  iVar6 = atoi("420011");
                                  if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                                    local_79c._0_1_ = 0;
[32m                                    memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                                    fprintf(stderr,
                                            "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_NOTIFY_MYDLINK\n"
                                            ,*piVar17);
                                    iVar5 = *piVar17;
                                    iVar4 = atoi("230010");
                                    if (iVar5 == iVar4) {
                                      sprintf(local_94,
                                              "/usr/sbin/msger eventd 0 eiotnotification 1 \"1 %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                              ,param_3,0,local_6c);[0m[0m
                                    }
                                    else {
                                      iVar4 = atoi("225810");
                                      if (iVar5 == iVar4) {
                                        sprintf(local_94,
                                                "/usr/sbin/msger eventd 0 eiotnotification 1 \"2 %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                                ,param_3,0,local_6c);[0m[0m
                                      }
                                    }
[32m[32m                                    system(local_94);[0m[0m
                                    iVar4 = FUN_00404e70(*piVar17,piVar15[-0x12],0x1d52e,local_54);
                                    if (iVar4 != 0) {
                                      pcVar18 = (char *)ixmlNodetoString(iVar4);
                                      if (pcVar18 != (char *)0x0) {
                                        sVar7 = strlen(pcVar18);
                                        fillEventMessageContent
                                                  (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                                        ixmlFreeDOMString(pcVar18);
                                      }
                                      ixmlNode_free(iVar4);
                                    }
                                    iVar4 = FUN_00402dc8(local_74);
                                    if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                       (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                       ((int)&uStack_54aec +
                                                                       (int)(local_98 + iVar4 * 0xac
                                                                            )),0x1d52f,local_54),
                                       iVar4 != 0)) {
                                      pcVar18 = (char *)ixmlNodetoString(iVar4);
                                      if (pcVar18 != (char *)0x0) {
                                        sVar7 = strlen(pcVar18);
                                        fillEventMessageContent
                                                  (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7);
                                        ixmlFreeDOMString(pcVar18);
                                      }
                                      ixmlNode_free(iVar4);
                                    }
                                  }
                                  else {
                                    iVar6 = atoi("420010");
                                    if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                                      local_79c._0_1_ = 0;
[32m                                      memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                                      fprintf(stderr,
                                              "PushDCHEventNotifyCheck -> Event: %d ACTION_ID_EMAIL_MYDLINK\n"
                                              ,*piVar17);
                                      iVar5 = *piVar17;
                                      iVar4 = atoi("230010");
                                      if (iVar5 == iVar4) {
                                        sprintf(local_94,
                                                "/usr/sbin/msger eventd 0 eiotnotification 1 \"1 %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                                ,param_3,0,local_6c);[0m[0m
                                      }
                                      else {
                                        iVar4 = atoi("225810");
                                        if (iVar5 == iVar4) {
                                          sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotnotification 1 \"2 %d %d %s\" 2>/dev/null 1>/dev/null"
[32m[32m                                                  ,param_3,0,local_6c);[0m[0m
                                        }
                                      }
[32m[32m                                      system(local_94);[0m[0m
                                      iVar4 = FUN_00404e70(*piVar17,piVar15[-0x12],0x1d538,local_54)
                                      ;
                                      if (iVar4 != 0) {
                                        pcVar18 = (char *)ixmlNodetoString(iVar4);
                                        if (pcVar18 != (char *)0x0) {
                                          sVar7 = strlen(pcVar18);
                                          fillEventMessageContent
                                                    (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7)
                                          ;
                                          ixmlFreeDOMString(pcVar18);
                                        }
                                        ixmlNode_free(iVar4);
                                      }
                                      iVar4 = FUN_00402dc8(local_74);
                                      if (((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                         (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                         ((int)&uStack_54aec +
                                                                         (int)(local_98 +
                                                                              iVar4 * 0xac)),0x1d52f
                                                               ,local_54), iVar4 != 0)) {
                                        pcVar18 = (char *)ixmlNodetoString(iVar4);
                                        if (pcVar18 != (char *)0x0) {
                                          sVar7 = strlen(pcVar18);
                                          fillEventMessageContent
                                                    (local_4c,piVar17[-0x12],local_70,pcVar18,sVar7)
                                          ;
                                          ixmlFreeDOMString(pcVar18);
                                        }
                                        ixmlNode_free(iVar4);
                                      }
                                    }
                                    else {
                                      iVar6 = atoi("422210");
                                      if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                                        if (local_7a8 == 0) {
                                          local_7a8 = iVar14;
                                          if (((local_68 == (int *)0x0) && (iVar14 != 0)) &&
                                             ((local_7a4 != 0 && (local_7a0 != 0)))) {
                                            fprintf(stderr,
                                                  "\x1b[1;31mA + B + C Actions: A-[%d] B-[%d] C-[%d]\n\x1b[m"
                                                  ,iVar14,local_7a4,local_7a0);
                                            iVar5 = atoi("422210");
                                            iVar4 = local_7a4;
                                            if (local_7a8 == iVar5) {
                                              iVar5 = atoi("422230");
                                              if ((iVar4 == iVar5) &&
                                                 (iVar5 = atoi("422243"), local_7a0 == iVar5)) {
                                                local_79c._0_1_ = 0;
[32m                                                memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                                                local_39c = local_39c & 0xffffff;
[32m                                                memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                FUN_00404d40(local_54,&local_39c);
                                                FUN_00404d40(local_48,&local_69c);
                                                sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotsnapshottrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_39c,&local_69c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                system(local_94);[0m[0m
                                              }
                                              else {
                                                iVar5 = atoi("422231");
                                                if ((iVar4 == iVar5) &&
                                                   (iVar4 = atoi("422243"), local_7a0 == iVar4)) {
                                                  local_79c._0_1_ = 0;
[32m                                                  memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                                                  local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                  memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                  local_39c = local_39c & 0xffffff;
[32m                                                  memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                  FUN_00404d40(local_54,&local_69c);
                                                  FUN_00404d40(local_48,&local_39c);
                                                  sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotvideocliptrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_69c,&local_39c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                  system(local_94);[0m[0m
                                                }
                                              }
                                            }
                                          }
                                        }
                                        else {
                                          local_68 = (int *)0x1;
                                        }
                                        iVar4 = FUN_00402dc8(local_74);
                                        if ((((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                            (local_68 == (int *)0x0)) &&
                                           (((local_7a8 != 0 && (local_7a4 != 0)) &&
                                            ((local_7a0 != 0 &&
                                             (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                             ((int)&uStack_54aec +
                                                                             (int)(local_98 +
                                                                                  iVar4 * 0xac)),
                                                                   0x1d52f,local_54), iVar4 != 0))))
                                           )) {
                                          pcVar18 = (char *)ixmlNodetoString(iVar4);
                                          if (pcVar18 != (char *)0x0) {
                                            sVar7 = strlen(pcVar18);
                                            fillEventMessageContent
                                                      (local_4c,piVar17[-0x12],local_70,pcVar18,
                                                       sVar7);
                                            ixmlFreeDOMString(pcVar18);
                                          }
                                          ixmlNode_free(iVar4);
                                        }
                                      }
                                      else {
                                        iVar6 = atoi("422230");
                                        if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                                          if (local_7a4 == 0) {
                                            local_7a4 = iVar14;
                                            if (((local_68 == (int *)0x0) && (local_7a8 != 0)) &&
                                               ((iVar14 != 0 && (local_7a0 != 0)))) {
                                              fprintf(stderr,
                                                  "\x1b[1;31mA + B + C Actions: A-[%d] B-[%d] C-[%d]\n\x1b[m"
                                                  ,local_7a8,iVar14,local_7a0);
                                              iVar5 = atoi("422210");
                                              iVar4 = local_7a4;
                                              if (local_7a8 == iVar5) {
                                                iVar5 = atoi("422230");
                                                if ((iVar4 == iVar5) &&
                                                   (iVar5 = atoi("422243"), local_7a0 == iVar5)) {
                                                  local_79c._0_1_ = 0;
[32m                                                  memset((undefined *)((int)&local_79c + 1),0,0xff);[0m
                                                  local_39c = local_39c & 0xffffff;
[32m                                                  memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                  local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                  memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                  FUN_00404d40(local_54,&local_39c);
                                                  FUN_00404d40(local_48,&local_69c);
                                                  sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotsnapshottrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_39c,&local_69c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                  system(local_94);[0m[0m
                                                }
                                                else {
                                                  iVar5 = atoi("422231");
                                                  if ((iVar4 == iVar5) &&
                                                     (iVar4 = atoi("422243"), local_7a0 == iVar4)) {
                                                    local_79c._0_1_ = 0;
                                                    memset((undefined *)((int)&local_79c + 1),0,0xff
[32m                                                          );[0m
                                                    local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                    memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                    local_39c = local_39c & 0xffffff;
[32m                                                    memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                    FUN_00404d40(local_54,&local_69c);
                                                    FUN_00404d40(local_48,&local_39c);
                                                    sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotvideocliptrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_69c,&local_39c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                  system(local_94);[0m[0m
                                                  }
                                                }
                                              }
                                            }
                                          }
                                          else {
                                            local_68 = (int *)0x1;
                                          }
                                          iVar4 = FUN_00402dc8(local_74);
                                          if (((((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                               (local_68 == (int *)0x0)) &&
                                              ((local_7a8 != 0 && (local_7a4 != 0)))) &&
                                             ((local_7a0 != 0 &&
                                              (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                              ((int)&uStack_54aec +
                                                                              (int)(local_98 +
                                                                                   iVar4 * 0xac)),
                                                                    0x1d52f,local_54), iVar4 != 0)))
                                             ) {
                                            pcVar18 = (char *)ixmlNodetoString(iVar4);
                                            if (pcVar18 != (char *)0x0) {
                                              sVar7 = strlen(pcVar18);
                                              fillEventMessageContent
                                                        (local_4c,piVar17[-0x12],local_70,pcVar18,
                                                         sVar7);
                                              ixmlFreeDOMString(pcVar18);
                                            }
                                            ixmlNode_free(iVar4);
                                          }
                                        }
                                        else {
                                          iVar6 = atoi("422231");
                                          if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0)) {
                                            if (local_7a4 == 0) {
                                              local_7a4 = iVar14;
                                              if ((((local_68 == (int *)0x0) && (local_7a8 != 0)) &&
                                                  (iVar14 != 0)) && (local_7a0 != 0)) {
                                                fprintf(stderr,
                                                  "\x1b[1;31mA + B + C Actions: A-[%d] B-[%d] C-[%d]\n\x1b[m"
                                                  ,local_7a8,iVar14,local_7a0);
                                                iVar5 = atoi("422210");
                                                iVar4 = local_7a4;
                                                if (local_7a8 == iVar5) {
                                                  iVar5 = atoi("422230");
                                                  if ((iVar4 == iVar5) &&
                                                     (iVar5 = atoi("422243"), local_7a0 == iVar5)) {
                                                    local_79c._0_1_ = 0;
                                                    memset((undefined *)((int)&local_79c + 1),0,0xff
[32m                                                          );[0m
                                                    local_39c = local_39c & 0xffffff;
[32m                                                    memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                    local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                    memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                    FUN_00404d40(local_54,&local_39c);
                                                    FUN_00404d40(local_48,&local_69c);
                                                    sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotsnapshottrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_39c,&local_69c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                  system(local_94);[0m[0m
                                                  }
                                                  else {
                                                    iVar5 = atoi("422231");
                                                    if ((iVar4 == iVar5) &&
                                                       (iVar4 = atoi("422243"), local_7a0 == iVar4))
                                                    {
                                                      local_79c._0_1_ = 0;
                                                      memset((undefined *)((int)&local_79c + 1),0,
[32m                                                             0xff);[0m
                                                      local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                      memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                      local_39c = local_39c & 0xffffff;
[32m                                                      memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                      FUN_00404d40(local_54,&local_69c);
                                                      FUN_00404d40(local_48,&local_39c);
                                                      sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotvideocliptrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_69c,&local_39c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                  system(local_94);[0m[0m
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                            else {
                                              local_68 = (int *)0x1;
                                            }
                                            iVar4 = FUN_00402dc8(local_74);
                                            if ((((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                                (local_68 == (int *)0x0)) &&
                                               (((local_7a8 != 0 && (local_7a4 != 0)) &&
                                                ((local_7a0 != 0 &&
                                                 (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                                 ((int)&uStack_54aec
                                                                                 + (int)(local_98 +
                                                                                        iVar4 * 0xac
                                                                                        )),0x1d52f,
                                                                       local_54), iVar4 != 0)))))) {
                                              pcVar18 = (char *)ixmlNodetoString(iVar4);
                                              if (pcVar18 != (char *)0x0) {
                                                sVar7 = strlen(pcVar18);
                                                fillEventMessageContent
                                                          (local_4c,piVar17[-0x12],local_70,pcVar18,
                                                           sVar7);
                                                ixmlFreeDOMString(pcVar18);
                                              }
                                              ixmlNode_free(iVar4);
                                            }
                                          }
                                          else {
                                            iVar6 = atoi("422243");
                                            if (((iVar14 == iVar6) && (iVar4 == 0)) && (iVar5 == 0))
                                            {
                                              if (local_7a0 == 0) {
                                                local_7a0 = iVar14;
                                                if (((local_68 == (int *)0x0) && (local_7a8 != 0))
                                                   && ((local_7a4 != 0 && (iVar14 != 0)))) {
                                                  fprintf(stderr,
                                                  "\x1b[1;31mA + B + C Actions: A-[%d] B-[%d] C-[%d]\n\x1b[m"
                                                  ,local_7a8,local_7a4,iVar14);
                                                  iVar5 = atoi("422210");
                                                  iVar4 = local_7a4;
                                                  if (local_7a8 == iVar5) {
                                                    iVar5 = atoi("422230");
                                                    if ((iVar4 == iVar5) &&
                                                       (iVar5 = atoi("422243"), local_7a0 == iVar5))
                                                    {
                                                      local_79c._0_1_ = 0;
                                                      memset((undefined *)((int)&local_79c + 1),0,
[32m                                                             0xff);[0m
                                                      local_39c = local_39c & 0xffffff;
[32m                                                      memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                      local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                      memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                      FUN_00404d40(local_54,&local_39c);
                                                      FUN_00404d40(local_48,&local_69c);
                                                      sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotsnapshottrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_39c,&local_69c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                  system(local_94);[0m[0m
                                                  }
                                                  else {
                                                    iVar5 = atoi("422231");
                                                    if ((iVar4 == iVar5) &&
                                                       (iVar4 = atoi("422243"), local_7a0 == iVar4))
                                                    {
                                                      local_79c._0_1_ = 0;
                                                      memset((undefined *)((int)&local_79c + 1),0,
[32m                                                             0xff);[0m
                                                      local_69c._0_4_ = local_69c._0_4_ & 0xffffff;
[32m                                                      memset((void *)((int)&local_69c + 1),0,0x2ff);[0m
                                                      local_39c = local_39c & 0xffffff;
[32m                                                      memset((void *)((int)&local_39c + 1),0,0x2ff);[0m
                                                      FUN_00404d40(local_54,&local_69c);
                                                      FUN_00404d40(local_48,&local_39c);
                                                      sprintf(local_94,
                                                  "/usr/sbin/msger eventd 0 eiotvideocliptrigger 1 \"%d %s %d %d %s %s %d\" 2>/dev/null 1>/dev/null"
                                                  ,2,local_70,piVar17[-0x12],0,&local_69c,&local_39c
[32m[32m                                                  ,*piVar17);[0m[0m
[32m[32m                                                  system(local_94);[0m[0m
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                              else {
                                                local_68 = (int *)0x1;
                                              }
                                              iVar4 = FUN_00402dc8(local_74);
                                              if ((((((iVar4 == iVar3) && (piVar16[0x1a] == 1)) &&
                                                    (local_68 == (int *)0x0)) &&
                                                   ((local_7a8 != 0 && (local_7a4 != 0)))) &&
                                                  (local_7a0 != 0)) &&
                                                 (iVar4 = FUN_00404e70(*piVar17,*(undefined4 *)
                                                                                 ((int)&uStack_54aec
                                                                                 + (int)(local_98 +
                                                                                        iVar4 * 0xac
                                                                                        )),0x1d52f,
                                                                       local_54), iVar4 != 0)) {
                                                pcVar18 = (char *)ixmlNodetoString(iVar4);
                                                if (pcVar18 != (char *)0x0) {
                                                  sVar7 = strlen(pcVar18);
                                                  fillEventMessageContent
                                                            (local_4c,piVar17[-0x12],local_70,
                                                             pcVar18,sVar7);
                                                  ixmlFreeDOMString(pcVar18);
                                                }
                                                ixmlNode_free(iVar4);
                                              }
                                            }
                                            else {
                                              bVar1 = true;
                                              if (0x2b < iVar14 - 0x687ebU) {
                                                bVar1 = iVar14 - 0x67142U < 0x27;
                                              }
                                              if (iVar5 != 0) {
                                                fprintf(stderr,
                                                  "PushDCHEventNotifyCheck -> Event: %d PUSH DCH EVENT Action:%d\n"
                                                  ,*piVar17,iVar14);
[32m                                                memset(local_94,0,0x81);[0m
                                                local_39c = 0;
                                                local_398 = 0;
                                                local_394 = 0;
                                                local_390 = 0;
                                                local_38c = 0;
                                                gettimeofday((timeval *)&local_69c,
                                                             (__timezone_ptr_t)0x0);
[32m                                                sprintf((char *)&local_39c,"%ld",local_69c._0_4_);[0m
                                                FUN_0040710c(local_5c,&local_39c,local_94);
                                                iVar4 = FUN_004058a8(local_74,piVar16[0xa9b],
                                                                     piVar16[0xa9c],&local_39c,
                                                                     local_94);
                                                if (((iVar4 == 0) || (param_2 == (code *)0x0)) ||
                                                   ((bVar1 && (local_58 != 0)))) {
LAB_0040b304:
                                                  if (iVar4 == 0) goto LAB_0040b320;
                                                }
                                                else {
                                                  iVar5 = (*param_2)(iVar4,acStack_54b00 +
                                                                           (int)pcVar18);
                                                  if (iVar5 != -2) {
                                                    if ((iVar5 == 0) && (bVar1)) {
                                                      local_58 = 1;
                                                    }
                                                    goto LAB_0040b304;
                                                  }
                                                  *(undefined *)(piVar15 + 0x13) = 1;
                                                  *(undefined *)((int)piVar17 + 0x45) = 1;
                                                  iVar14 = piVar17[-0x16];
                                                  iVar6 = piVar17[-0x15];
                                                  iVar5 = piVar17[-0x14];
                                                  *(int *)local_7c = piVar17[-0x17];
                                                  *(int *)((int)local_7c + 4) = iVar14;
                                                  *(int *)((int)local_7c + 8) = iVar6;
                                                  *(int *)((int)local_7c + 0xc) = iVar5;
                                                  *(undefined *)((int)local_7c + 0x10) =
                                                       *(undefined *)(piVar17 + -0x13);
                                                  *(undefined *)((int)local_7c + 0x11) =
                                                       *(undefined *)((int)piVar17 + -0x4b);
                                                  *(undefined *)((int)local_7c + 0x12) =
                                                       *(undefined *)((int)piVar17 + -0x4a);
                                                  piVar16[0xaaa] = piVar17[-0x12];
                                                  local_50 = 1;
                                                }
                                                ixmlNode_free(iVar4);
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
LAB_0040b320:
                  iVar3 = iVar3 + 1;
                  piVar15 = piVar15 + 0x2b;
                } while (iVar3 < piVar16[0xa9c]);
              }
              local_88 = local_88 + 1;
              piVar17 = piVar17 + 0x29;
            } while (local_88 < piVar16[0xa9b]);
            if (local_50 != 0) {
[32m              memset(&local_79c,0,0x81);[0m
              local_39c = 0;
              local_398 = 0;
              local_394 = 0;
              local_390 = 0;
              local_38c = 0;
              gettimeofday((timeval *)&local_69c,(__timezone_ptr_t)0x0);
[32m              sprintf((char *)&local_39c,"%ld",local_69c._0_4_);[0m
              FUN_0040710c(local_5c,&local_39c,&local_79c);
              iVar3 = FUN_00405228(local_74,piVar16[0xa9b],piVar16[0xa9c],&local_39c,&local_79c);
              if (iVar3 != 0) {
                pcVar18 = (char *)ixmlNodetoString(iVar3);
                if (pcVar18 != (char *)0x0) {
                  sVar7 = strlen(pcVar18);
                  fillEventMessageContent
                            (local_4c,piVar16[0xaaa],aiStack_53557 + local_60 * 0xaac,pcVar18,sVar7)
                  ;
                  ixmlFreeDOMString(pcVar18);
                }
                ixmlNode_free(iVar3);
              }
            }
          }
        }
        local_60 = local_60 + 1;
        piVar16 = piVar16 + 0xaac;
      } while (local_60 < local_64);
    }
    sendEventMsg(local_4c);
    uninitEventMsg(local_4c);
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] 440180987680c373
