
int mDNS_Init(undefined4 *param_1,undefined4 param_2,int *param_3,uint param_4,undefined param_5,
             undefined4 param_6,undefined4 param_7)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar10 = 0;
  if (param_3 != (int *)0x0) {
    uVar10 = param_4;
  }
  *param_1 = param_2;
  *(undefined *)((int)param_1 + 9) = param_5;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  param_1[1] = 0;
  *(undefined *)(param_1 + 2) = 0;
  *(undefined *)((int)param_1 + 10) = 0;
  param_1[3] = 1;
  *(undefined2 *)(param_1 + 4) = 0;
[32m[32m  memcpy(param_1 + 5,&zeroEthAddr,6);[0m[0m
  param_1[7] = param_6;
  param_1[8] = param_7;
  *(undefined *)(param_1 + 0x1feb) = 0;
  param_1[0x1ff5] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0x90] = 0;
  *(undefined *)(param_1 + 0xb) = 0;
  *(undefined *)((int)param_1 + 0x2d) = 0;
  *(undefined *)((int)param_1 + 0x2e) = 0;
  iVar2 = mDNSPlatformTimeInit();
  if (iVar2 == 0) {
    uVar3 = mDNSRandom(0xffffffff);
    param_1[0x8c] = uVar3;
    iVar4 = mDNSPlatformRawTime();
    iVar4 = iVar4 + param_1[0x8c];
    iVar5 = 0;
    iVar9 = iVar4 + 0x78000000;
    param_1[0x8d] = 0;
    param_1[0x8e] = iVar4;
    param_1[0x8f] = iVar4;
    param_1[0x91] = iVar4;
    param_1[0x92] = iVar9;
    param_1[0x93] = iVar9;
    param_1[0x94] = iVar9;
    param_1[0x95] = iVar9;
    param_1[0x96] = iVar9;
    param_1[0x97] = iVar9;
    param_1[0x98] = iVar9;
    param_1[0xaa] = iVar9;
    param_1[0x99] = 0;
    param_1[0x9a] = 0;
    param_1[0x9b] = 0;
    param_1[0x9c] = 0;
    *(undefined *)(param_1 + 0x9d) = 0;
    *(undefined *)((int)param_1 + 0x275) = 0;
    *(undefined *)((int)param_1 + 0x276) = 0;
    *(undefined *)((int)param_1 + 0x277) = 0;
    iVar2 = mDNSPlatformOneSecond;
    param_1[0xa0] = 0;
    param_1[0xa1] = 0;
    param_1[0xab] = 0;
    param_1[0xac] = 0;
    param_1[0xad] = 0;
    param_1[0xae] = 0;
    iVar2 = iVar4 + iVar2 * 0x3c;
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    param_1[0x9f] = iVar2;
    param_1[0xaf] = 0;
    param_1[0xb0] = 0;
    param_1[0xb1] = 0;
    param_1[0xb2] = 0;
    param_1[0xb3] = 0;
    param_1[0xb6] = 10;
    param_1[0xb5] = 0;
    param_1[0xb7] = 0;
    puVar7 = param_1;
    do {
      iVar5 = iVar5 + 1;
      puVar7[0xb8] = 0;
      puVar7[0x2ab] = iVar9;
      puVar7 = puVar7 + 1;
    } while (iVar5 != 499);
    if ((param_3 != (int *)0x0) && (uVar10 != 0)) {
      uVar8 = 0;
      piVar6 = param_3;
      while( true ) {
        bVar1 = uVar10 <= uVar8;
        uVar8 = uVar8 + 1;
        if (bVar1) break;
        *piVar6 = (int)(piVar6 + 0x2e);
        piVar6 = piVar6 + 0x2e;
      }
      param_3[(uVar10 - 1) * 0x2e] = param_1[0xb7];
      param_1[0xb7] = param_3;
      param_1[0xb2] = param_1[0xb2] + uVar10;
    }
    param_1[0x4a2] = 0;
    iVar2 = 0;
    do {
      iVar5 = iVar2 + 4;
      *(undefined4 *)((int)param_1 + iVar2 + 0x128c) = 0;
      iVar2 = iVar5;
    } while (iVar5 != 0x7cc);
    if (*(char *)(param_1 + 0x6b6) == '\0') {
      *(undefined *)(param_1 + 0x6a6) = 0;
    }
    param_1[0x862] = iVar9;
    param_1[0x863] = iVar9;
    *(undefined *)(param_1 + 0x696) = 0;
    *(undefined *)((int)param_1 + 0x1ad9) = 0;
    *(undefined *)((int)param_1 + 0x1bd9) = 0;
    *(undefined *)((int)param_1 + 0x1cd9) = 0;
    param_1[0x858] = 0;
    param_1[0x859] = 0;
    param_1[0x85a] = 0;
    *(undefined *)(param_1 + 0x85c) = 0;
    param_1[0x85b] = 0;
    param_1[0x85d] = 0;
    param_1[0x85e] = 0;
    param_1[0x85f] = 0;
    param_1[0x860] = 0;
    param_1[0x864] = 0;
[32m[32m    memcpy(param_1 + 0x866,zeroAddr,0x14);[0m[0m
[32m[32m    memcpy(param_1 + 0x86b,zeroAddr,0x14);[0m[0m
[32m[32m    memcpy(param_1 + 0x870,zeroAddr,0x14);[0m[0m
    param_1[0x87a] = 0xffffffff;
    param_1[0xa71] = iVar9;
    param_1[0xa72] = 0;
    param_1[0xe44] = 1;
    param_1[0x875] = 0;
    *(undefined *)(param_1 + 0x9be) = 0;
    *(undefined *)(param_1 + 0x9fe) = 0;
    param_1[0xa3e] = 0;
    param_1[0xa50] = 0;
    param_1[0xa55] = 0;
    param_1[0xa56] = 0;
    param_1[0xa57] = 0;
    param_1[0xe42] = 1;
    param_1[0xe43] = 1;
    param_1[0xa6c] = 0;
    param_1[0xa6d] = 0;
    param_1[0xa6e] = 0;
    param_1[0xa6f] = 0;
    param_1[0xa70] = 0;
    uVar3 = mDNSRandom(0xffffffff);
    param_1[0xa73] = uVar3;
    uVar3 = mDNSRandom(0xffffffff);
    param_1[0xa74] = uVar3;
    uVar3 = mDNSRandom(0xffffffff);
    param_1[0xa75] = uVar3;
    param_1[0xa78] = iVar4;
    *(undefined2 *)(param_1 + 0xaa0) = 0;
    *(undefined2 *)((int)param_1 + 0x2a7e) = 0;
    param_1[0xa76] = 0;
    param_1[0xa77] = 0;
    *(undefined2 *)(param_1 + 0xa79) = 0;
    param_1[0xa9d] = 0;
    param_1[0xa9e] = 0;
    *(undefined *)(param_1 + 0xa9f) = 0;
    param_1[0xaa1] = 0;
    *(undefined *)(param_1 + 0xaa2) = 0;
    param_1[0xaa3] = 0;
    param_1[0xaa4] = 0;
    param_1[0xaa5] = 0;
    *(undefined *)(param_1 + 0xaa7) = 0;
    *(undefined *)((int)param_1 + 0x2a9d) = 0;
    *(undefined *)((int)param_1 + 0x2a9e) = 0;
    *(undefined *)((int)param_1 + 0x2a9f) = 0;
    *(undefined *)(param_1 + 0xaa8) = 0;
    *(undefined *)((int)param_1 + 0x2aa1) = 0;
    param_1[0xaa9] = 0;
    param_1[0xaaa] = 0;
    param_1[0xe37] = 0;
    param_1[0xe38] = 0;
    iVar2 = mDNSPlatformInit(param_1);
    FUN_00436018(param_1);
  }
  return iVar2;
}

[ASK_GPT] 442776d22f7119b8
