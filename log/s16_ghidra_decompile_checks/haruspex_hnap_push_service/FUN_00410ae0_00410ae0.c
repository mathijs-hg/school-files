
/* WARNING: Removing unreachable block (ram,0x00410f10) */

undefined4 FUN_00410ae0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  size_t sVar6;
  FILE *__s;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char acStack_130 [128];
  char local_b0 [128];
  undefined4 local_30;
  
  local_30 = ixmlGetElementByTag(param_1,"PolicyList");
  iVar2 = ixmlElement_getElementsByTagName(local_30,"PolicyInfo");
  if ((iVar2 != 0) && (iVar3 = ixmlNodeList_length(iVar2), 0 < iVar3)) {
    iVar11 = 0;
    do {
[32m      memset(acStack_130,0,0x80);[0m
[32m      memset(local_b0,0,0x80);[0m
      uVar4 = ixmlNodeList_item(iVar2,iVar11);
      pcVar5 = (char *)ixmlGetElementValueByTag(uVar4,&DAT_00414cec);
      if (pcVar5 != (char *)0x0) {
[32m[32m        strcpy(acStack_130,pcVar5);[0m[0m
      }
      AESDecrypt(param_2,acStack_130,local_b0);
      sVar6 = strlen(local_b0);
      if (sVar6 == 0) {
        ixmlSetElementValueByTag(uVar4,local_b0,&DAT_00414cec);
      }
      else {
        uVar10 = uVar4;
        if (sVar6 != 0x20) {
LAB_00410cb4:
          uVar7 = ixmlDocument_createDocument(uVar10);
          uVar8 = ixmlDocument_createElement(uVar7,"SetDCHPolicyResponse");
          ixmlElement_setAttribute(uVar8,"xmlns","http://purenetworks.com/HNAP1/");
          ixmlNode_appendChild(uVar7,uVar8);
          ixmlAppendNewElement(uVar7,uVar8,"SetDCHPolicyResult","ERROR");
          uVar8 = ixmlNode_cloneNode(uVar7,1);
          ixmlNodeList_free(iVar2);
          ixmlDocument_free(uVar7);
          return uVar8;
        }
        uVar9 = 0;
        do {
[32m          cVar1 = local_b0[uVar9];[0m
          if (((9 < (byte)(cVar1 - 0x30U)) && (5 < (byte)(cVar1 + 0x9fU))) &&
             (uVar10 = (uint)((byte)(cVar1 + 0xbfU) < 6), uVar10 == 0)) goto LAB_00410cb4;
          uVar9 = uVar9 + 1;
        } while (uVar9 < 0x20);
        ixmlSetElementValueByTag(uVar4,local_b0,&DAT_00414cec);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar3);
  }
  pcVar5 = (char *)ixmlPrintNode(local_30);
[32m  __s = fopen("/mnt/flash/config/hnap_policy.xml","wb");[0m
  sVar6 = strlen(pcVar5);
  fwrite(pcVar5,1,sVar6,__s);
  fflush(__s);
  fclose(__s);
  ixmlFreeDOMString(pcVar5);
  uVar7 = ixmlDocument_createDocument();
  uVar8 = ixmlDocument_createElement(uVar7,"SetDCHPolicyResponse");
  ixmlElement_setAttribute(uVar8,"xmlns","http://purenetworks.com/HNAP1/");
  ixmlNode_appendChild(uVar7,uVar8);
  ixmlAppendNewElement(uVar7,uVar8,"SetDCHPolicyResult",&DAT_004151ec);
  uVar8 = ixmlNode_cloneNode(uVar7,1);
  ixmlNodeList_free(iVar2);
  ixmlDocument_free(uVar7);
  ReviewPolicyFromFile();
  return uVar8;
}

[ASK_GPT] 5e64ed79b75d9f1e
