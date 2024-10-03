
undefined4
fillEventMessageContent(int param_1,undefined4 param_2,char *param_3,void *param_4,size_t param_5)

{
  char *pcVar1;
  size_t sVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  short *psVar7;
  uint uVar8;
  short *psVar9;
  undefined *puVar10;
  undefined4 local_90 [13];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_50;
  char local_4c;
  undefined auStack_4b [35];
  
  pcVar1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><MultiReport>";
  puVar3 = local_90;
  do {
    uVar6 = *(undefined4 *)((int)pcVar1 + 4);
    uVar5 = *(undefined4 *)((int)pcVar1 + 8);
    uVar4 = *(undefined4 *)((int)pcVar1 + 0xc);
    *puVar3 = *(undefined4 *)pcVar1;
    puVar3[1] = uVar6;
    puVar3[2] = uVar5;
    puVar3[3] = uVar4;
    pcVar1 = (char *)((int)pcVar1 + 0x10);
    puVar3 = puVar3 + 4;
  } while ((undefined4 *)pcVar1 != (undefined4 *)0x416fa4);
  *puVar3 = 0x72743e00;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  if (param_1 != 0) {
    if (param_4 == (void *)0x0) {
      return 0xffffffff;
    }
[32m    if ((int)param_5 < 0) {[0m
      return 0xffffffff;
    }
    if (param_3 == (char *)0x0) {
      return 0xffffffff;
    }
    psVar9 = (short *)(param_1 + 0x10);
    psVar7 = psVar9;
    if (*(short *)(param_1 + 0xe) == 0) {
      local_4c = '\0';
[32m      memset(auStack_4b,0,0x1f);[0m
      local_50 = 0x60e;
      *(undefined *)psVar9 = 0;
      *(undefined *)(param_1 + 0x11) = 0x24;
      *(undefined *)(param_1 + 0x12) = 0;
      *(undefined *)(param_1 + 0x13) = 2;
      *(undefined *)(param_1 + 0x14) = 6;
      *(undefined *)(param_1 + 0x15) = 0xe;
      uVar8 = (uint)*(ushort *)(param_1 + 0xe) + (uint)*(ushort *)(param_1 + 0x12) + 4 & 0xffff;
      *(char *)(param_1 + 0xe) = (char)(uVar8 >> 8);
      *(char *)(param_1 + 0xf) = (char)uVar8;
      puVar10 = (undefined *)((int)psVar9 + uVar8);
      sVar2 = strlen(param_3);
      *puVar10 = 8;
      puVar10[1] = 0;
      puVar10[2] = (char)((sVar2 & 0xffff) >> 8);
      puVar10[3] = (char)(sVar2 & 0xffff);
[32m      memcpy(puVar10 + 4,param_3,sVar2);[0m
      uVar8 = (uint)*(ushort *)(param_1 + 0xe) + (uint)*(ushort *)(puVar10 + 2) + 4 & 0xffff;
      *(char *)(param_1 + 0xe) = (char)(uVar8 >> 8);
      *(char *)(param_1 + 0xf) = (char)uVar8;
      puVar10 = (undefined *)((int)psVar9 + uVar8);
[32m      sprintf(&local_4c,"%d",param_2);[0m
      *puVar10 = 8;
      puVar10[1] = 1;
      sVar2 = strlen(&local_4c);
      puVar10[2] = (char)((sVar2 & 0xffff) >> 8);
      puVar10[3] = (char)(sVar2 & 0xffff);
      sVar2 = strlen(&local_4c);
[32m      memcpy(puVar10 + 4,&local_4c,sVar2);[0m
      uVar8 = (uint)*(ushort *)(param_1 + 0xe) + (uint)*(ushort *)(puVar10 + 2) + 4 & 0xffff;
      *(char *)(param_1 + 0xe) = (char)(uVar8 >> 8);
      *(char *)(param_1 + 0xf) = (char)uVar8;
      psVar7 = (short *)((int)psVar9 + uVar8);
    }
    do {
      if (*psVar7 == 0x29) {
        if ((short *)(param_1 + 0x200100) <= psVar7 + (param_5 + (ushort)psVar7[1]) * 2) {
          return 0xffffffff;
        }
[32m        memcpy((undefined *)((int)psVar7 + (ushort)psVar7[1] + 4),param_4,param_5);[0m
        uVar8 = (param_5 & 0xffff) + (uint)(ushort)psVar7[1] & 0xffff;
        *(char *)(psVar7 + 1) = (char)(uVar8 >> 8);
        *(char *)((int)psVar7 + 3) = (char)uVar8;
        uVar8 = (param_5 & 0xffff) + (uint)*(ushort *)(param_1 + 0xe) & 0xffff;
        *(char *)(param_1 + 0xe) = (char)(uVar8 >> 8);
        *(char *)(param_1 + 0xf) = (char)uVar8;
        return 0;
      }
      psVar7 = (short *)((int)psVar7 + (ushort)psVar7[1] + 4);
    } while (psVar7 < (short *)((int)psVar9 + (uint)*(ushort *)(param_1 + 0xe)));
    puVar10 = (undefined *)((int)psVar9 + (uint)*(ushort *)(param_1 + 0xe));
    sVar2 = strlen((char *)local_90);
    if (puVar10 + (param_5 + 4 + sVar2) * 4 < (undefined *)(param_1 + 0x200100)) {
      *puVar10 = 0;
      puVar10[1] = 0x29;
      sVar2 = strlen((char *)local_90);
[32m      memcpy(puVar10 + 4,local_90,sVar2);[0m
      sVar2 = strlen((char *)local_90);
[32m      memcpy(puVar10 + 4 + sVar2,param_4,param_5);[0m
      sVar2 = strlen((char *)local_90);
      uVar8 = sVar2 + param_5 & 0xffff;
      puVar10[2] = (char)(uVar8 >> 8);
      puVar10[3] = (char)uVar8;
      uVar8 = uVar8 + *(ushort *)(param_1 + 0xe) + 4 & 0xffff;
      *(char *)(param_1 + 0xe) = (char)(uVar8 >> 8);
      *(char *)(param_1 + 0xf) = (char)uVar8;
      return 0;
    }
  }
  return 0xffffffff;
}

[ASK_GPT] 26cdcc6e65bd79b5
