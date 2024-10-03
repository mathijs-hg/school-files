
void FUN_0042989c(int param_1,char param_2,uint param_3,int param_4,int *param_5,void *param_6,
                 undefined4 *param_7,int param_8)

{
  undefined4 uVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 *__dest;
  int iVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined4 local_60;
  undefined2 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined local_39;
  undefined4 *local_38;
  int local_34;
  uint local_30;
  undefined4 *local_2c;
  
  local_38 = &local_48;
  if (param_2 != -0x79) {
    local_38 = param_7;
  }
  local_3b = *(undefined *)((int)param_7 + 0xd);
  local_3a = *(undefined *)((int)param_7 + 0xe);
  local_3c = 0xff;
  local_39 = *(undefined *)((int)param_7 + 0xf);
  local_40 = 1;
  local_44 = 0;
  local_48 = 0xff020000;
  iVar6 = *(int *)(param_4 + 0x1c);
  puVar7 = *(undefined4 **)(param_1 + 0x2174);
  param_3 = param_3 & 0xff;
  while( true ) {
    if (puVar7 == (undefined4 *)0x0) {
      uVar1 = GetRRDisplayString_rdb(param_4 + 4,*(int *)(param_4 + 0x24) + 4,param_1 + 0x2f);
      LogMsgWithLevel(0,"SendNDP: No interface with InterfaceID %p found %s",iVar6,uVar1);
      return;
    }
    puVar8 = (undefined *)(param_1 + 0x5cbc);
    if (puVar7[0x548] == iVar6) break;
    puVar7 = (undefined4 *)*puVar7;
  }
  iVar6 = 0;
  puVar3 = puVar8;
  do {
    puVar5 = (undefined *)(param_8 + iVar6);
    iVar6 = iVar6 + 1;
    *puVar3 = *puVar5;
    puVar3 = puVar3 + 1;
  } while (iVar6 != 6);
  iVar6 = 0;
  __dest = &local_60;
  do {
    if (param_6 == (void *)0x0) {
      local_60 = puVar7[0x553];
      local_5c = *(undefined2 *)(puVar7 + 0x554);
      puVar3 = (undefined *)((int)__dest + iVar6);
      iVar4 = iVar6;
    }
    else {
      local_34 = iVar6;
      local_30 = param_3;
      local_2c = __dest;
[32m[32m      memcpy(__dest,param_6,6);[0m[0m
      puVar3 = (undefined *)((int)local_2c + local_34);
      iVar4 = local_34;
      __dest = local_2c;
      param_3 = local_30;
    }
    iVar6 = iVar4 + 1;
    puVar8[iVar4 + 6] = *puVar3;
  } while (iVar6 != 6);
  *(undefined *)(param_1 + 0x5cca) = 0x60;
  *(undefined *)(param_1 + 0x5ccf) = 0x20;
  *(undefined *)(param_1 + 0x5cd0) = 0x3a;
  *(undefined *)(param_1 + 0x5cc8) = 0x86;
  *(undefined *)(param_1 + 0x5cc9) = 0xdd;
  *(undefined *)(param_1 + 0x5cd1) = 0xff;
  *(undefined *)(param_1 + 0x5ccb) = 0;
  *(undefined *)(param_1 + 0x5ccc) = 0;
  *(undefined *)(param_1 + 0x5ccd) = 0;
  *(undefined *)(param_1 + 0x5cce) = 0;
  iVar6 = 0;
  do {
    iVar4 = iVar6 + 1;
    puVar8[iVar6 + 0x16] = *(undefined *)((int)param_5 + iVar6);
    iVar6 = iVar4;
  } while (iVar4 != 0x10);
  iVar6 = 0;
  do {
    iVar4 = iVar6 + 1;
    puVar8[iVar6 + 0x26] = *(undefined *)((int)local_38 + iVar6);
    iVar6 = iVar4;
  } while (iVar4 != 0x10);
  *(char *)(param_1 + 0x5cf6) = (char)param_3;
  *(char *)(param_1 + 0x5cf2) = param_2;
  *(undefined *)(param_1 + 0x5cf3) = 0;
  *(undefined *)(param_1 + 0x5cf4) = 0;
  *(undefined *)(param_1 + 0x5cf5) = 0;
  *(undefined *)(param_1 + 0x5cf7) = 0;
  *(undefined *)(param_1 + 0x5cf8) = 0;
  *(undefined *)(param_1 + 0x5cf9) = 0;
  iVar6 = 0;
  if (param_2 == -0x79) {
    iVar6 = 0;
    do {
      iVar4 = iVar6 + 1;
      puVar8[iVar6 + 0x3e] = *(undefined *)((int)param_7 + iVar6);
      iVar6 = iVar4;
    } while (iVar4 != 0x10);
    iVar6 = param_1 + 0x5d0a;
    if ((((param_5[1] != 0) || (*param_5 != 0)) || (param_5[2] != 0)) || (param_5[3] != 0)) {
      *(undefined *)(param_1 + 0x5d0a) = 1;
      *(undefined *)(param_1 + 0x5d0b) = 1;
      iVar6 = 0;
      do {
        if (param_6 == (void *)0x0) {
          local_58 = puVar7[0x553];
          local_54 = *(undefined2 *)(puVar7 + 0x554);
        }
        else {
[32m[32m          memcpy(&local_58,param_6,6);[0m[0m
        }
        iVar4 = iVar6 + 1;
        puVar8[iVar6 + 0x50] = *(undefined *)((int)&local_58 + iVar6);
        iVar6 = iVar4;
      } while (iVar4 != 6);
      iVar6 = param_1 + 0x5d12;
    }
  }
  else {
    do {
      iVar4 = iVar6 + 1;
      puVar8[iVar6 + 0x3e] = *(undefined *)((int)param_5 + iVar6);
      iVar6 = iVar4;
    } while (iVar4 != 0x10);
    *(undefined *)(param_1 + 0x5d0a) = 2;
    *(undefined *)(param_1 + 0x5d0b) = 1;
    iVar6 = 0;
    do {
      if (param_6 == (void *)0x0) {
        local_50 = puVar7[0x553];
        local_4c = *(undefined2 *)(puVar7 + 0x554);
      }
      else {
[32m[32m        memcpy(&local_50,param_6,6);[0m[0m
      }
      iVar4 = iVar6 + 1;
      puVar8[iVar6 + 0x50] = *(undefined *)((int)&local_50 + iVar6);
      iVar6 = iVar4;
    } while (iVar4 != 6);
    iVar6 = param_1 + 0x5d12;
  }
  uVar2 = iVar6 - (param_1 + 0x5cf2) & 0xff;
  *(char *)(param_1 + 0x5ccf) = (char)uVar2;
  uVar2 = FUN_004262ac(param_5,local_38,0x3a,param_1 + 0x5cf2,uVar2);
  *(char *)(param_1 + 0x5cf5) = (char)~uVar2;
  *(char *)(param_1 + 0x5cf4) = (char)(~uVar2 >> 8);
  mDNSPlatformSendRawPacket(param_1 + 0x5cbc,iVar6,*(undefined4 *)(param_4 + 0x1c));
  return;
}

[ASK_GPT] 398edbf874ec1dbb
