
void FUN_0042a238(int param_1,int param_2,int **param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  for (; param_2 != 0; param_2 = *(int *)(param_2 + 0xb0)) {
    iVar2 = *(int *)(param_2 + 0x30);
    if ((((iVar2 != 0) && ((*(byte *)(iVar2 + 4) & 0x3c) != 0)) &&
        ((*(int *)(iVar2 + 0x30) == 0 || ((*(byte *)(*(int *)(iVar2 + 0x30) + 4) & 0x3c) != 0)))) &&
       ((((*(int *)(iVar2 + 0x34) == 0 || ((*(byte *)(*(int *)(iVar2 + 0x34) + 4) & 0x3c) != 0)) &&
         ((*(int *)(iVar2 + 0x38) == 0 || ((*(byte *)(*(int *)(iVar2 + 0x38) + 4) & 0x3c) != 0))))
        && ((((*(int *)(iVar2 + 0x1c) == 0 || (*(int *)(iVar2 + 0x1c) == param_4)) &&
             (*(int *)(iVar2 + 0xb0) == 0)) && (*param_3 != (int *)(iVar2 + 0xb0))))))) {
      **param_3 = iVar2;
      iVar3 = *(int *)(param_2 + 0xb8);
      if (*(int *)(param_2 + 0xb8) == 0) {
        iVar3 = param_2;
      }
      *(int *)(iVar2 + 0xb8) = iVar3;
      *param_3 = (int *)(iVar2 + 0xb0);
    }
    iVar2 = *(int *)(param_2 + 0x34);
    if ((((((iVar2 != 0) && ((*(byte *)(iVar2 + 4) & 0x3c) != 0)) &&
          ((*(int *)(iVar2 + 0x30) == 0 || ((*(byte *)(*(int *)(iVar2 + 0x30) + 4) & 0x3c) != 0))))
         && ((*(int *)(iVar2 + 0x34) == 0 || ((*(byte *)(*(int *)(iVar2 + 0x34) + 4) & 0x3c) != 0)))
         ) && ((*(int *)(iVar2 + 0x38) == 0 || ((*(byte *)(*(int *)(iVar2 + 0x38) + 4) & 0x3c) != 0)
               ))) &&
       ((((*(int *)(iVar2 + 0x1c) == 0 || (*(int *)(iVar2 + 0x1c) == param_4)) &&
         (*(int *)(iVar2 + 0xb0) == 0)) && (*param_3 != (int *)(iVar2 + 0xb0))))) {
      **param_3 = iVar2;
      iVar3 = *(int *)(param_2 + 0xb8);
      if (*(int *)(param_2 + 0xb8) == 0) {
        iVar3 = param_2;
      }
      *(int *)(iVar2 + 0xb8) = iVar3;
      *param_3 = (int *)(iVar2 + 0xb0);
    }
[32m    sVar1 = *(short *)(param_2 + 6);[0m
    if (sVar1 == 0x21) {
      for (puVar4 = *(undefined4 **)(param_1 + 0x2160); puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        if (((((*(short *)((int)puVar4 + 6) == 1) || (*(short *)((int)puVar4 + 6) == 0x1c)) &&
             (((*(byte *)(puVar4 + 1) & 0x3c) != 0 &&
              ((puVar4[0xc] == 0 || ((*(byte *)(puVar4[0xc] + 4) & 0x3c) != 0)))))) &&
            ((puVar4[0xd] == 0 || ((*(byte *)(puVar4[0xd] + 4) & 0x3c) != 0)))) &&
           (((puVar4[0xe] == 0 || ((*(byte *)(puVar4[0xe] + 4) & 0x3c) != 0)) &&
            (((puVar4[7] == 0 || (puVar4[7] == param_4)) &&
             ((((*(int *)(param_2 + 0x18) == puVar4[5] &&
                (iVar2 = SameDomainName(*(int *)(param_2 + 0x24) + 10,puVar4[8]), iVar2 != 0)) &&
               (puVar4[0x2c] == 0)) && (*param_3 != puVar4 + 0x2c)))))))) {
          **param_3 = (int)puVar4;
          iVar2 = *(int *)(param_2 + 0xb8);
          if (*(int *)(param_2 + 0xb8) == 0) {
            iVar2 = param_2;
          }
          puVar4[0x2e] = iVar2;
          *param_3 = puVar4 + 0x2c;
        }
      }
    }
    else if ((sVar1 == 1) || (sVar1 == 0x1c)) {
      for (puVar4 = *(undefined4 **)(param_1 + 0x2160); puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        if ((((((*(short *)((int)puVar4 + 6) == 1) || (*(short *)((int)puVar4 + 6) == 0x1c)) &&
              (((*(byte *)(puVar4 + 1) & 0x3c) != 0 &&
               ((puVar4[0xc] == 0 || ((*(byte *)(puVar4[0xc] + 4) & 0x3c) != 0)))))) &&
             ((puVar4[0xd] == 0 || ((*(byte *)(puVar4[0xd] + 4) & 0x3c) != 0)))) &&
            (((puVar4[0xe] == 0 || ((*(byte *)(puVar4[0xe] + 4) & 0x3c) != 0)) &&
             ((puVar4[7] == 0 || (puVar4[7] == param_4)))))) &&
           ((((*(int *)(param_2 + 0x14) == puVar4[5] &&
              (iVar2 = SameDomainName(*(undefined4 *)(param_2 + 0x20),puVar4[8]), iVar2 != 0)) &&
             (puVar4[0x2c] == 0)) && (*param_3 != puVar4 + 0x2c)))) {
          **param_3 = (int)puVar4;
          iVar2 = *(int *)(param_2 + 0xb8);
          if (*(int *)(param_2 + 0xb8) == 0) {
            iVar2 = param_2;
          }
          puVar4[0x2e] = iVar2;
          *param_3 = puVar4 + 0x2c;
        }
      }
    }
    else if ((((sVar1 == 0xc) && ((*(byte *)(param_1 + 0x1de0) & 0x3c) != 0)) &&
             ((*(int *)(param_1 + 0x1e0c) == 0 ||
              ((*(byte *)(*(int *)(param_1 + 0x1e0c) + 4) & 0x3c) != 0)))) &&
            ((((*(int *)(param_1 + 0x1e10) == 0 ||
               ((*(byte *)(*(int *)(param_1 + 0x1e10) + 4) & 0x3c) != 0)) &&
              ((*(int *)(param_1 + 0x1e14) == 0 ||
               ((*(byte *)(*(int *)(param_1 + 0x1e14) + 4) & 0x3c) != 0)))) &&
             ((((*(int *)(param_1 + 0x1df8) == 0 || (*(int *)(param_1 + 0x1df8) == param_4)) &&
               (iVar2 = SameDomainLabel(*(int *)(param_2 + 0x24) + 4,
                                        *(undefined4 *)(param_1 + 0x1dfc)), iVar2 != 0)) &&
              ((*(int *)(param_1 + 0x1e8c) == 0 && (*param_3 != (int *)(param_1 + 0x1e8c))))))))) {
      **param_3 = param_1 + 0x1ddc;
      iVar2 = *(int *)(param_2 + 0xb8);
      if (*(int *)(param_2 + 0xb8) == 0) {
        iVar2 = param_2;
      }
      *(int *)(param_1 + 0x1e94) = iVar2;
      *param_3 = (int *)(param_1 + 0x1e8c);
    }
  }
  return;
}

[ASK_GPT] 757d2f41c5f1eece
