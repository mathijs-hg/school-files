
undefined4 * GetServiceTarget(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined auStack_50 [32];
  undefined4 *local_30;
  undefined4 local_2c;
  
  if (*(char *)(param_2 + 0x48) == '\0') {
    return (undefined4 *)(*(int *)(param_2 + 0x24) + 10);
  }
  iVar10 = 0;
  puVar9 = (undefined4 *)0x0;
  iVar1 = CountLabels(*(undefined4 *)(param_2 + 0x20));
  for (puVar7 = *(undefined4 **)(param_1 + 0x28f8); puVar7 != (undefined4 *)0x0;
      puVar7 = (undefined4 *)*puVar7) {
    if ((((puVar7[0x8c] == 2) || (puVar7[0x8c] == 5)) || (puVar7[0x16d] == 2)) ||
       (puVar7[0x16d] == 5)) {
      local_30 = puVar7 + 0x13;
      iVar2 = CountLabels(local_30);
      iVar8 = iVar1;
      if (iVar2 <= iVar1) {
        iVar8 = iVar2;
      }
      iVar11 = iVar1 - iVar8;
      iVar2 = iVar2 - iVar8;
      while( true ) {
        if ((iVar8 < 1) || (iVar8 <= iVar10)) break;
        local_2c = SkipLeadingLabels(*(undefined4 *)(param_2 + 0x20),iVar11);
        uVar5 = SkipLeadingLabels(local_30,iVar2);
        iVar3 = SameDomainName(local_2c,uVar5);
        if (iVar3 != 0) {
          puVar9 = puVar7;
          iVar10 = iVar8;
        }
        iVar8 = iVar8 + -1;
        iVar11 = iVar11 + 1;
        iVar2 = iVar2 + 1;
      }
    }
  }
  if (puVar9 != (undefined4 *)0x0) {
    return puVar9 + 0x13;
  }
  if (*(char *)(param_1 + 0x26f8) != '\0') {
    return (undefined4 *)(param_1 + 0x26f8);
  }
  if ((*(int *)(param_1 + 0x21e8) == -1) && (*(int *)(param_1 + 0x21b0) != 0)) {
    mDNSPlatformMemZero(param_1 + 0x21d8,0x290);
    puVar4 = auStack_50;
    mDNS_snprintf(puVar4,0x1e,"%d.%d.%d.%d.in-addr.arpa.",*(undefined *)(param_1 + 0x21b3),
                  *(undefined *)(param_1 + 0x21b2),*(undefined *)(param_1 + 0x21b1),
[32m                  *(undefined *)(param_1 + 0x21b0));[0m
    iVar10 = MakeDomainNameFromDNSNameString(param_1 + 0x232c,puVar4);
    if (iVar10 == 0) {
      pcVar6 = "Error: GetStaticHostname - bad name %s";
    }
    else {
      *(undefined4 *)(param_1 + 0x230c) = 0;
      *(undefined4 *)(param_1 + 0x2310) = 0;
[32m[32m      memcpy((void *)(param_1 + 0x2314),zeroAddr,0x14);[0m[0m
      *(undefined2 *)(param_1 + 0x242c) = 0xc;
      *(undefined *)(param_1 + 0x2433) = 1;
      *(undefined2 *)(param_1 + 0x242e) = 1;
      *(undefined *)(param_1 + 0x2430) = 0;
      *(undefined *)(param_1 + 0x2431) = 0;
      *(undefined *)(param_1 + 0x2432) = 0;
      *(undefined *)(param_1 + 0x2434) = 0;
      *(undefined *)(param_1 + 0x2435) = 0;
      *(undefined *)(param_1 + 0x2436) = 0;
      *(undefined *)(param_1 + 0x243b) = 0;
      *(undefined *)(param_1 + 0x243c) = 0;
      *(undefined *)(param_1 + 0x2437) = 0;
      *(undefined *)(param_1 + 0x2438) = 0;
      *(undefined *)(param_1 + 0x2439) = 0;
      *(undefined *)(param_1 + 0x243a) = 0;
      *(undefined *)(param_1 + 0x243e) = 0;
      *(undefined *)(param_1 + 0x22a4) = 0;
      *(undefined *)(param_1 + 0x243f) = 0;
      *(undefined4 *)(param_1 + 0x245c) = 0;
      *(undefined4 *)(param_1 + 0x221c) = 0;
      uVar5 = mDNSPlatformGetPID();
      *(undefined4 *)(param_1 + 0x2444) = uVar5;
      *(undefined **)(param_1 + 0x2460) = &LAB_0040ce54;
      *(undefined4 *)(param_1 + 0x2458) = 0;
      *(undefined4 *)(param_1 + 0x2464) = 0;
      if (mDNS_LoggingEnabled != 0) {
        uVar5 = DNSTypeName(*(undefined2 *)(param_1 + 0x242c));
        LogMsgWithLevel(3,"GetStaticHostname: %##s (%s)",param_1 + 0x232c,uVar5);
      }
      puVar4 = (undefined *)mDNS_StartQuery_internal(param_1,param_1 + 0x21d8);
      if (puVar4 == (undefined *)0x0) goto LAB_00412f28;
      pcVar6 = "Error: GetStaticHostname - StartQuery returned error %d";
    }
    LogMsgWithLevel(0,pcVar6,puVar4);
  }
LAB_00412f28:
  if (mDNS_LoggingEnabled != 0) {
    uVar5 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(3,"GetServiceTarget: Returning NULL for %s",uVar5);
  }
  return (undefined4 *)0x0;
}

[ASK_GPT] 6f811d34525cf0aa
