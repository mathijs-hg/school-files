
undefined4 FUN_00402294(undefined4 param_1,undefined4 param_2,char *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = ixmlElement_getElementsByTagName();
  if (iVar1 != 0) {
    iVar2 = ixmlNodeList_length(iVar1);
    uVar4 = 0xffffffff;
    if (iVar2 == 0) goto LAB_00402390;
    uVar4 = ixmlNodeList_item(iVar1,0);
    for (iVar2 = ixmlNode_getFirstChild(uVar4); iVar2 != 0; iVar2 = ixmlNode_getNextSibling(iVar2))
    {
      iVar3 = ixmlNode_getNodeType(iVar2);
      if (iVar3 == 3) {
        iVar2 = ixmlNode_getNodeValue(iVar2);
        if (iVar2 != 0) {
[32m          snprintf(param_3,param_4,"%s",iVar2);[0m
          uVar4 = 0;
          goto LAB_00402390;
        }
        break;
      }
    }
  }
  uVar4 = 0xffffffff;
LAB_00402390:
  ixmlNodeList_free(iVar1);
  return uVar4;
}

[ASK_GPT] b3c81dfefe8c8f1e
