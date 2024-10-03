
bool FUN_00401650(char *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  bool bVar8;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar9;
  int *piVar10;
  undefined4 local_70;
  char acStack_6c [68];
  
  local_70 = 0;
  iVar4 = RequestIndication(DAT_00418328,param_1,&DAT_00418431,&local_70,&_gp);
  if (iVar4 < 0) {
    iw_message(0x14,"RequestIndication return Fail");
    return false;
  }
  if (DAT_00418431 == '\0') {
    return false;
  }
[32m  memset(acStack_6c,0,0x40);[0m
  if (DAT_00418431 == '0') {
    pcVar9 = "WPA_MULTICAST_CIPHER";
    goto LAB_004018e8;
  }
  if ('0' < DAT_00418431) {
    if (DAT_00418431 == ':') {
      pcVar9 = "WSC_ASSOC_REQ_IE_IND";
LAB_00401b1c:
[32m[32m      sprintf(acStack_6c,"Receive Event %s",pcVar9);[0m[0m
    }
    else {
      if (DAT_00418431 < ';') {
        if (DAT_00418431 == '4') {
          pcVar9 = "AUTOCONF_PACKET";
LAB_00401a24:
[32m[32m          sprintf(acStack_6c,"Receive Event %s",pcVar9);[0m[0m
          bVar2 = true;
        }
        else {
          if ('4' < DAT_00418431) {
            if (DAT_00418431 == '8') {
              pcVar9 = "WSC_PROBE_REQ_IND";
              goto LAB_00401b1c;
            }
            if ('8' < DAT_00418431) {
              pcVar9 = "WSC_PIN_IND";
              goto LAB_00401b3c;
            }
            if (DAT_00418431 == '5') {
              pcVar9 = "AUTOCONF_LINK_IND";
              goto LAB_00401a44;
            }
LAB_00401b58:
[32m            sprintf(acStack_6c,"Receive Invalid or Unhandled Event %d");[0m
            bVar3 = false;
            bVar2 = false;
            bVar1 = false;
            goto LAB_00401b7c;
          }
          if (DAT_00418431 == '2') {
            pcVar9 = "AUTOCONF_ASSOC_IND";
            goto LAB_00401a24;
          }
          if (DAT_00418431 != '3') goto LAB_00401b58;
          pcVar9 = "AUTOCONF_ASSOC_CONFIRM";
LAB_00401a44:
[32m[32m          sprintf(acStack_6c,"Receive Event %s",pcVar9);[0m[0m
          bVar2 = true;
        }
LAB_004018b8:
        bVar3 = false;
        bVar1 = true;
        goto LAB_00401b7c;
      }
      if (DAT_00418431 == 'f') {
        pcVar9 = "WSC_SET_MY_PIN";
        goto LAB_00401b1c;
      }
      if (DAT_00418431 < 'g') {
        if (DAT_00418431 == 'd') {
          pcVar9 = "WSC_P2P_IND";
          goto LAB_00401b1c;
        }
        if (DAT_00418431 != 'e') goto LAB_00401b58;
        pcVar9 = "WSC_P2P_STOP";
      }
      else {
        if (DAT_00418431 == 'h') {
          pcVar9 = "WSC_SPEC_MAC";
          goto LAB_00401b1c;
        }
        if (DAT_00418431 < 'h') {
          pcVar9 = "WSC_SPEC_SSID";
        }
        else {
          if (DAT_00418431 != 'w') goto LAB_00401b58;
          pcVar9 = "WSC_ASSOC_REQ_IE_IND";
        }
      }
LAB_00401b3c:
[32m[32m      sprintf(acStack_6c,"Receive Event %s",pcVar9);[0m[0m
    }
    bVar2 = false;
    bVar3 = true;
    bVar1 = false;
    goto LAB_00401b7c;
  }
  if (DAT_00418431 == '\x10') {
    pcVar9 = "MIC_FAILURE";
LAB_004018e8:
    bVar3 = false;
  }
  else {
    if (DAT_00418431 < '\x11') {
      if (DAT_00418431 != '\x06') {
        if (DAT_00418431 < '\a') {
          if (DAT_00418431 == '\x03') {
            pcVar9 = "ASSOCIATION_IND";
            goto LAB_004018e8;
          }
          if (DAT_00418431 != '\x05') goto LAB_00401b58;
          pcVar9 = "AUTHENTICATION_IND";
        }
        else {
          if (DAT_00418431 == '\a') {
            pcVar9 = "DEAUTHENTICATION_IND";
            goto LAB_004018e8;
          }
          if (DAT_00418431 != '\b') goto LAB_00401b58;
          pcVar9 = "DISASSOCIATION_IND";
        }
        goto LAB_004018a4;
      }
      pcVar9 = "REAUTHENTICATION_IND";
      goto LAB_004018e8;
    }
    if (DAT_00418431 != ')') {
      if (DAT_00418431 < '*') {
        if (DAT_00418431 == '\x13') {
          pcVar9 = "EAPOL_START";
          goto LAB_004018e8;
        }
        if (DAT_00418431 != '\"') goto LAB_00401b58;
        pcVar9 = "REASSOCIATION_IND";
      }
      else {
        if (DAT_00418431 == '.') {
          pcVar9 = "EAP_PACKET_PREAUTH";
          goto LAB_004018e8;
        }
        if (DAT_00418431 < '/') {
          if (DAT_00418431 != '-') goto LAB_00401b58;
          pcVar9 = "EAPOLSTART_PREAUTH";
        }
        else {
          pcVar9 = "WPA2_MULTICAST_CIPHER";
        }
      }
LAB_004018a4:
[32m[32m      sprintf(acStack_6c,"Receive Event %s",pcVar9);[0m[0m
      bVar2 = false;
      goto LAB_004018b8;
    }
    pcVar9 = "EAP_PACKET";
    bVar3 = true;
  }
  bVar2 = false;
[32m[32m  sprintf(acStack_6c,"Receive Event %s",pcVar9);[0m[0m
  bVar1 = true;
LAB_00401b7c:
  iw_message(0x14,"[iwcontrol]: %s",acStack_6c);
  bVar8 = false;
  if (bVar1) {
    if ((DAT_0041831c == 0) || (!bVar2)) {
      if (DAT_00418314 != 0) {
        piVar10 = &DAT_00418324;
        for (iVar4 = 0; iVar4 < DAT_00418310; iVar4 = iVar4 + 1) {
          iVar5 = strcmp((char *)(&DAT_00418324 + (iVar4 * 3 + 1) * 2),param_1);
          if (iVar5 == 0) {
            pcVar6 = (char *)write(*piVar10,&DAT_0041842c,0x640);
            pcVar9 = "Write %d bytes\n";
            if ((int)pcVar6 < 0) {
              piVar7 = __errno_location();
              pcVar6 = strerror(*piVar7);
              pcVar9 = "Write FIFO: %s";
            }
            iw_message(0x14,pcVar9,pcVar6);
          }
          piVar10 = piVar10 + 6;
        }
      }
      if (DAT_00418318 != 0) {
        pcVar9 = (char *)write(DAT_00418414,&DAT_0041842c,0x640);
        if ((int)pcVar9 < 0) {
          piVar10 = __errno_location();
          pcVar9 = strerror(*piVar10);
          pcVar6 = "Write FIFO: %s";
        }
        else {
          pcVar6 = "Write %d bytes\n";
        }
        iw_message(0x14,pcVar6,pcVar9);
      }
    }
    else {
      piVar10 = &DAT_00418b34;
      for (iVar4 = 0; iVar4 < DAT_0041831c; iVar4 = iVar4 + 1) {
        iVar5 = strcmp((char *)(&DAT_00418b34 + (iVar4 * 3 + 1) * 2),param_1);
        if (iVar5 == 0) {
          pcVar6 = (char *)write(*piVar10,&DAT_0041842c,0x640);
          pcVar9 = "Write %d bytes\n";
          if ((int)pcVar6 < 0) {
            piVar7 = __errno_location();
            pcVar6 = strerror(*piVar7);
            pcVar9 = "Write FIFO: %s";
          }
          iw_message(0x14,pcVar9,pcVar6);
        }
        piVar10 = piVar10 + 6;
      }
    }
    bVar8 = DAT_00418432 == '\x01';
  }
  if (bVar3) {
    if (DAT_00418320 != 0) {
      piVar10 = &DAT_00418c24;
      for (iVar4 = 0; iVar4 < DAT_00418320; iVar4 = iVar4 + 1) {
        iVar5 = strcmp((char *)(&DAT_00418c24 + (iVar4 * 3 + 1) * 2),param_1);
        if (iVar5 == 0) {
          pcVar6 = (char *)write(*piVar10,&DAT_0041842c,0x640);
          pcVar9 = "Write %d bytes\n";
          if ((int)pcVar6 < 0) {
            piVar7 = __errno_location();
            pcVar6 = strerror(*piVar7);
            pcVar9 = "Write FIFO: %s";
          }
          iw_message(0x14,pcVar9,pcVar6);
        }
        piVar10 = piVar10 + 6;
      }
    }
    bVar8 = DAT_00418432 == '\x01';
  }
  return bVar8;
}

[ASK_GPT] 43d5eb64c42cbe0c
