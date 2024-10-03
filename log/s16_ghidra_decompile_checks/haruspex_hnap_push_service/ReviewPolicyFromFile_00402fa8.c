
undefined4 ReviewPolicyFromFile(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int aiStack_55888 [10];
  char acStack_5585f [71];
  undefined auStack_55818 [24];
  undefined auStack_55800 [33];
  char acStack_557df [35];
  int iStack_557bc;
  undefined auStack_557b8 [5152];
  undefined auStack_54398 [24];
  undefined auStack_54380 [33];
  char acStack_5435f [35];
  int iStack_5433c;
  undefined auStack_54338 [68];
  int aiStack_542f4 [1336];
  int iStack_52e14;
  undefined auStack_52e10 [338824];
  char local_288;
  undefined auStack_287 [511];
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  char *local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  char *local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  local_288 = '\0';
[32m  memset(auStack_287,0,0x1ff);[0m
  local_88 = 0;
  local_84 = 0;
  local_30 = ixmlLoadDocument("/mnt/flash/config/hnap_policy.xml");
  if (local_30 == 0) {
    return 0xffffffff;
  }
  local_38 = ixmlElement_getElementsByTagName(local_30,"PolicyInfo");
  if (local_38 == 0) {
[32m    memset(aiStack_55888,0,0x55600);[0m
LAB_00404c9c:
    ixmlNodeList_free(local_38);
    ixmlDocument_free(local_30);
LAB_00404cdc:
    local_34 = 0;
    local_30 = 0;
  }
  else {
    local_34 = ixmlNodeList_length(local_38);
[32m    memset(aiStack_55888,0,0x55600);[0m
    if (local_34 < 1) goto LAB_00404c9c;
    local_40 = 0;
    local_70 = "ModuleID";
    local_6c = "ModuleType";
    local_68 = "SubType";
    local_58 = "EventID";
    local_54 = "EventDesc";
    local_50 = "ActionID";
    local_4c = "ActionDesc";
    local_48 = "DelayAction";
    local_3c = aiStack_55888;
    do {
      local_44 = (int *)ixmlNodeList_item(local_38,local_40);
[32m      memset(&local_288,0,0x200);[0m
      iVar2 = ixmlGetElementValueByTag_s(local_44,"Index",&local_288,0x200);
      if (iVar2 == 0) {
        iVar2 = atoi(&local_288);
        *local_3c = iVar2;
      }
      else {
        *local_3c = 0;
      }
[32m      memset(&local_288,0,0x200);[0m
      iVar2 = ixmlGetElementValueByTag_s(local_44,"PolicyEnabled",&local_288,0x200);
      if (iVar2 == 0) {
        iVar2 = strcasecmp(&local_288,"true");
        if (iVar2 == 0) {
          local_3c[1] = 1;
        }
        else {
          local_3c[1] = 0;
        }
      }
      else {
        local_3c[1] = 0;
      }
[32m      memset(&local_288,0,0x200);[0m
      iVar2 = ixmlGetElementValueByTag_s(local_44,"PolicyName",&local_288,0x200);
      if (iVar2 == 0) {
[32m[32m        strcpy((char *)(aiStack_55888 + (local_40 * 0x556 + 1) * 2),&local_288);[0m[0m
      }
      else {
        *(undefined *)(aiStack_55888 + (local_40 * 0x556 + 1) * 2) = 0;
      }
[32m      memset(&local_288,0,0x200);[0m
      iVar2 = ixmlGetElementValueByTag_s(local_44,"PolicyDesc",&local_288,0x200);
      if (iVar2 == 0) {
[32m[32m        strcpy(acStack_5585f + local_40 * 0x2ab0,&local_288);[0m[0m
      }
      else {
        acStack_5585f[local_40 * 0x2ab0] = '\0';
      }
[32m      memset(&local_288,0,0x200);[0m
      iVar2 = ixmlGetElementValueByTag_s(local_44,"PolicyNotification",&local_288,0x200);
      if (iVar2 == 0) {
        iVar2 = strcasecmp(&local_288,"true");
        if (iVar2 == 0) {
          local_3c[0x1b] = 1;
        }
        else {
          local_3c[0x1b] = 0;
        }
      }
      else {
        local_3c[0x1b] = 0;
      }
      iVar2 = ixmlGetElementByTag_s(local_44,"Sender",&local_88);
      if (iVar2 == 0) {
        local_60 = (char *)ixmlElement_getElementsByTagName(local_88,"Notifier");
        if (local_60 == (char *)0x0) {
          iVar8 = 0;
        }
        else {
          iVar9 = ixmlNodeList_length(local_60);
          iVar2 = local_40;
          if (iVar9 < 1) goto LAB_004039d0;
          piVar11 = &iStack_557bc + local_40 * 0xaac;
          iVar8 = 0;
          iVar4 = local_40 * 0x2ab0;
          do {
            uVar3 = ixmlNodeList_item(local_60,iVar8);
[32m            memset(&local_288,0,0x200);[0m
            iVar5 = ixmlGetElementValueByTag_s(uVar3,"DeviceMacID",&local_288,0x200);
            if (iVar5 == 0) {
[32m[32m              strcpy((char *)(aiStack_55888 + iVar2 * 0xaac + iVar8 * 0x29 + 0x1c),&local_288);[0m[0m
            }
            else {
              auStack_55818[iVar8 * 0xa4 + iVar4] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar5 = ixmlGetElementValueByTag_s(uVar3,local_70,&local_288,0x200);
            if (iVar5 == 0) {
              iVar5 = atoi(&local_288);
              piVar11[-0x12] = iVar5;
            }
            else {
              piVar11[-0x12] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar5 = ixmlGetElementValueByTag_s(uVar3,local_6c,&local_288,0x200);
            if (iVar5 == 0) {
[32m[32m              strcpy((char *)(aiStack_55888 + iVar2 * 0xaac + iVar8 * 0x29 + 0x22),&local_288);[0m[0m
            }
            else {
              auStack_55800[iVar8 * 0xa4 + iVar4] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar5 = ixmlGetElementValueByTag_s(uVar3,local_68,&local_288,0x200);
            if (iVar5 == 0) {
[32m[32m              strcpy(acStack_557df + iVar8 * 0xa4 + iVar4,&local_288);[0m[0m
            }
            else {
              acStack_557df[iVar8 * 0xa4 + iVar4] = '\0';
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar5 = ixmlGetElementValueByTag_s(uVar3,local_58,&local_288,0x200);
            if (iVar5 == 0) {
              iVar5 = atoi(&local_288);
              *piVar11 = iVar5;
            }
            else {
              *piVar11 = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar5 = ixmlGetElementValueByTag_s(uVar3,local_54,&local_288,0x200);
            if (iVar5 == 0) {
[32m[32m              strcpy((char *)(aiStack_55888 + iVar2 * 0xaac + iVar8 * 0x29 + 0x34),&local_288);[0m[0m
            }
            else {
              auStack_557b8[iVar8 * 0xa4 + iVar4] = 0;
            }
            iVar8 = iVar8 + 1;
          } while ((iVar8 < iVar9) && (piVar11 = piVar11 + 0x29, iVar8 != 0x20));
        }
      }
      else {
        local_88 = 0;
        local_60 = (char *)0x0;
LAB_004039d0:
        iVar8 = 0;
      }
      local_3c[0xa9c] = iVar8;
      iVar2 = ixmlGetElementByTag_s(local_44,"Receiver",&local_84);
      if (iVar2 == 0) {
        local_64 = (char *)ixmlElement_getElementsByTagName(local_84,"Reactor");
        if (local_64 == (char *)0x0) {
          iVar9 = 0;
        }
        else {
          local_5c = (char *)ixmlNodeList_length(local_64);
          iVar2 = local_40;
          if ((int)local_5c < 1) goto LAB_00403e74;
          piVar11 = aiStack_542f4 + local_40 * 0xaac;
          iVar9 = 0;
          iVar8 = local_40 * 0x2ab0;
          do {
            uVar3 = ixmlNodeList_item(local_64,iVar9);
[32m            memset(&local_288,0,0x200);[0m
            iVar4 = ixmlGetElementValueByTag_s(uVar3,"DeviceMacID",&local_288,0x200);
            if (iVar4 == 0) {
[32m[32m              strcpy((char *)(aiStack_55888 + iVar2 * 0xaac + iVar9 * 0x2b + 0x53c),&local_288);[0m[0m
            }
            else {
              auStack_54398[iVar9 * 0xac + iVar8] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar4 = ixmlGetElementValueByTag_s(uVar3,local_70,&local_288,0x200);
            if (iVar4 == 0) {
              iVar4 = atoi(&local_288);
              piVar11[-0x24] = iVar4;
            }
            else {
              piVar11[-0x24] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar4 = ixmlGetElementValueByTag_s(uVar3,local_6c,&local_288,0x200);
            if (iVar4 == 0) {
[32m[32m              strcpy((char *)(aiStack_55888 + iVar2 * 0xaac + iVar9 * 0x2b + 0x542),&local_288);[0m[0m
            }
            else {
              auStack_54380[iVar9 * 0xac + iVar8] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar4 = ixmlGetElementValueByTag_s(uVar3,local_68,&local_288,0x200);
            if (iVar4 == 0) {
[32m[32m              strcpy(acStack_5435f + iVar9 * 0xac + iVar8,&local_288);[0m[0m
            }
            else {
              acStack_5435f[iVar9 * 0xac + iVar8] = '\0';
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar4 = ixmlGetElementValueByTag_s(uVar3,local_50,&local_288,0x200);
            if (iVar4 == 0) {
              iVar4 = atoi(&local_288);
              piVar11[-0x12] = iVar4;
            }
            else {
              piVar11[-0x12] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar4 = ixmlGetElementValueByTag_s(uVar3,local_4c,&local_288,0x200);
            if (iVar4 == 0) {
[32m[32m              strcpy((char *)(aiStack_55888 + iVar2 * 0xaac + iVar9 * 0x2b + 0x554),&local_288);[0m[0m
            }
            else {
              auStack_54338[iVar9 * 0xac + iVar8] = 0;
            }
[32m            memset(&local_288,0,0x200);[0m
            iVar4 = ixmlGetElementValueByTag_s(uVar3,local_48,&local_288,0x200);
            if (iVar4 == 0) {
              iVar4 = atoi(&local_288);
              *piVar11 = iVar4;
            }
            else {
              *piVar11 = 0;
            }
            iVar9 = iVar9 + 1;
          } while ((iVar9 < (int)local_5c) && (piVar11 = piVar11 + 0x2b, iVar9 != 0x20));
        }
      }
      else {
        local_84 = 0;
        local_64 = (char *)0x0;
LAB_00403e74:
        iVar9 = 0;
      }
      local_3c[0xa9d] = iVar9;
[32m      memset(&local_288,0,0x200);[0m
      iVar2 = ixmlGetElementValueByTag_s(local_44,&DAT_00414cec,&local_288,0x200);
      if (iVar2 == 0) {
[32m[32m        strcpy((char *)(aiStack_55888 + local_40 * 0xaac + 0xa9e),&local_288);[0m[0m
      }
      else {
        auStack_52e10[local_40 * 0x2ab0] = 0;
      }
      ixmlNodeList_free(local_64);
      ixmlNodeList_free(local_60);
      if (local_84 != 0) {
        ixmlNode_free();
        local_84 = 0;
      }
      if (local_88 != 0) {
        ixmlNode_free();
        local_88 = 0;
      }
      local_40 = local_40 + 1;
      if (local_34 <= local_40) {
        ixmlNodeList_free(local_38);
        ixmlDocument_free(local_30);
        if (local_40 < 1) goto LAB_00404cdc;
        goto LAB_004040b4;
      }
      local_3c = local_3c + 0xaac;
    } while (local_40 != 0x20);
    ixmlNodeList_free(local_38);
    ixmlDocument_free(local_30);
LAB_004040b4:
    piVar11 = &iStack_52e14;
    local_30 = 0;
    local_34 = 0;
    local_38 = 0;
    local_48 = (char *)0x0;
    local_44 = &local_80;
    local_70 = "422015";
    local_6c = "422017";
    local_68 = "422019";
    local_64 = "422021";
    local_60 = "420011";
    local_5c = "420010";
    local_58 = "422022";
    local_54 = "422023";
    local_50 = "422210";
    local_4c = "422230";
    do {
      piVar10 = local_44;
      *local_44 = 0;
      piVar10[1] = 0;
      piVar10[2] = 0;
      if ((piVar11[-0xa9c] == 1) && (0 < *piVar11)) {
        piVar10 = &iStack_5433c + (int)local_48 * 0xaac;
        piVar12 = &iStack_557bc + (int)local_48 * 0xaac;
        local_3c = (int *)0x0;
        iVar2 = 0;
        iVar9 = (int)local_48 * 0x2ab0;
        do {
          iVar8 = FUN_00402d50(*piVar10);
          iVar4 = FUN_00402e94(auStack_54398 + iVar2 * 0xac + iVar9);
          iVar7 = *piVar10;
          iVar5 = atoi(local_70);
          if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
            fprintf(stderr,"ReviewPolicyFromFile -> Event: %d ACTION_ID_SNAP_NOTIFY\n",*piVar12);
            local_38 = 1;
          }
          else {
            iVar5 = atoi(local_6c);
            if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
              fprintf(stderr,"ReviewPolicyFromFile -> Event: %d ACTION_ID_SNAP_MYDLINK\n",*piVar12);
              local_38 = 1;
            }
            else {
              iVar5 = atoi(local_68);
              if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
                fprintf(stderr,"ReviewPolicyFromFile -> Event: %d ACTION_ID_VCLIP_NOTIFY\n",*piVar12
                       );
                local_34 = 1;
              }
              else {
                iVar5 = atoi(local_64);
                if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
                  fprintf(stderr,"ReviewPolicyFromFile -> Event: %d ACTION_ID_VCLIP_MYDLINK\n",
                          *piVar12);
                  local_34 = 1;
                }
                else {
                  iVar5 = atoi(local_60);
                  if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
                    fprintf(stderr,"ReviewPolicyFromFile -> Event: %d ACTION_ID_NOTIFY_MYDLINK\n",
                            *piVar12);
                    local_30 = 1;
                  }
                  else {
                    iVar5 = atoi(local_5c);
                    if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
                      fprintf(stderr,"ReviewPolicyFromFile -> Event: %d ACTION_ID_EMAIL_MYDLINK\n",
                              *piVar12);
                      local_30 = 1;
                    }
                    else {
                      iVar5 = atoi(local_58);
                      if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
                        fprintf(stderr,"ReviewPolicyFromFile -> Event: %d ACTION_ID_SNAP_STORAGE\n",
                                *piVar12);
                        local_38 = 1;
                      }
                      else {
                        iVar5 = atoi(local_54);
                        if (((iVar7 == iVar5) && (iVar8 == 0)) && (iVar4 == 0)) {
                          fprintf(stderr,
                                  "ReviewPolicyFromFile -> Event: %d ACTION_ID_VCLIP_STORAGE\n",
                                  *piVar12);
                          local_34 = 1;
                        }
                        else {
                          iVar6 = atoi(local_50);
                          iVar1 = local_78;
                          iVar5 = local_7c;
                          if (((iVar7 == iVar6) && (iVar8 == 0)) && (iVar4 == 0)) {
                            if (local_80 == 0) {
                              local_80 = iVar7;
                              if ((((local_3c == (int *)0x0) && (iVar7 != 0)) && (local_7c != 0)) &&
                                 ((local_78 != 0 && (iVar8 = atoi(local_50), iVar7 == iVar8)))) {
                                iVar8 = atoi(local_4c);
                                if ((iVar5 == iVar8) && (iVar8 = atoi("422243"), iVar1 == iVar8)) {
LAB_00404a90:
                                  local_38 = 1;
                                }
                                else {
                                  iVar8 = atoi("422231");
                                  if ((iVar5 == iVar8) && (iVar8 = atoi("422243"), iVar1 == iVar8))
                                  {
LAB_00404aa8:
                                    local_34 = 1;
                                  }
                                }
                              }
                            }
                            else {
LAB_00404abc:
                              local_3c = (int *)0x1;
                            }
                          }
                          else {
                            iVar6 = atoi(local_4c);
                            iVar1 = local_78;
                            iVar5 = local_80;
                            if (((iVar7 == iVar6) && (iVar8 == 0)) && (iVar4 == 0)) {
                              if (local_7c != 0) goto LAB_00404abc;
                              local_7c = iVar7;
                              if ((((local_3c == (int *)0x0) && (local_80 != 0)) && (iVar7 != 0)) &&
                                 ((local_78 != 0 && (iVar8 = atoi(local_50), iVar5 == iVar8)))) {
                                iVar8 = atoi(local_4c);
                                if ((iVar7 == iVar8) && (iVar8 = atoi("422243"), iVar1 == iVar8))
                                goto LAB_00404a90;
                                iVar8 = atoi("422231");
                                if ((iVar7 == iVar8) && (iVar8 = atoi("422243"), iVar1 == iVar8))
                                goto LAB_00404aa8;
                              }
                            }
                            else {
                              iVar6 = atoi("422231");
                              iVar1 = local_78;
                              iVar5 = local_80;
                              if (((iVar7 == iVar6) && (iVar8 == 0)) && (iVar4 == 0)) {
                                if (local_7c != 0) goto LAB_00404abc;
                                local_7c = iVar7;
                                if ((((local_3c == (int *)0x0) && (local_80 != 0)) && (iVar7 != 0))
                                   && ((local_78 != 0 && (iVar8 = atoi(local_50), iVar5 == iVar8))))
                                {
                                  iVar8 = atoi(local_4c);
                                  if ((iVar7 == iVar8) && (iVar8 = atoi("422243"), iVar1 == iVar8))
                                  goto LAB_00404a90;
                                  iVar8 = atoi("422231");
                                  if ((iVar7 == iVar8) && (iVar8 = atoi("422243"), iVar1 == iVar8))
                                  goto LAB_00404aa8;
                                }
                              }
                              else {
                                iVar6 = atoi("422243");
                                iVar1 = local_7c;
                                iVar5 = local_80;
                                if (((iVar7 == iVar6) && (iVar8 == 0)) && (iVar4 == 0)) {
                                  if (local_78 != 0) goto LAB_00404abc;
                                  local_78 = iVar7;
                                  if ((((local_3c == (int *)0x0) && (local_80 != 0)) &&
                                      (local_7c != 0)) &&
                                     ((iVar7 != 0 && (iVar8 = atoi(local_50), iVar5 == iVar8)))) {
                                    iVar8 = atoi(local_4c);
                                    if ((iVar1 == iVar8) && (iVar8 = atoi("422243"), iVar7 == iVar8)
                                       ) goto LAB_00404a90;
                                    iVar8 = atoi("422231");
                                    if ((iVar1 == iVar8) && (iVar8 = atoi("422243"), iVar7 == iVar8)
                                       ) goto LAB_00404aa8;
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
          iVar2 = iVar2 + 1;
          piVar10 = piVar10 + 0x2b;
          piVar12 = piVar12 + 0x29;
        } while (iVar2 < *piVar11);
      }
      local_48 = local_48 + 1;
      piVar11 = piVar11 + 0xaac;
    } while ((int)local_48 < local_40);
    if (local_38 != 0) {
[32m      system("/usr/sbin/msger eventd 0 eiotenablesnapshot 0 1 2>/dev/null 1>/dev/null");[0m
      goto LAB_00404b94;
    }
  }
[32m  system("/usr/sbin/msger eventd 0 eiotenablesnapshot 0 0 2>/dev/null 1>/dev/null");[0m
LAB_00404b94:
  if (local_34 == 0) {
[32m    system("/usr/sbin/msger eventd 0 eiotenablevideoclip 0 0 2>/dev/null 1>/dev/null");[0m
  }
  else {
[32m    system("/usr/sbin/msger eventd 0 eiotenablevideoclip 0 1 2>/dev/null 1>/dev/null");[0m
  }
  if (local_30 == 0) {
[32m    system("/usr/sbin/msger eventd 0 eiotenablenotification 0 0 2>/dev/null 1>/dev/null");[0m
  }
  else {
[32m    system("/usr/sbin/msger eventd 0 eiotenablenotification 0 1 2>/dev/null 1>/dev/null");[0m
  }
  return 0;
}

[ASK_GPT] 8a37c9748ed164fb
