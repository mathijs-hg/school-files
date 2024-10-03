
void ILibAddRequest_DirectEx
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  undefined *puVar7;
  
[32m[32m[32m  puVar2 = (undefined4 *)malloc(0x34);[0m[0m[0m
  puVar2[2] = param_3;
  *puVar2 = param_2;
  puVar2[3] = param_5;
  puVar2[1] = param_4;
  puVar2[8] = param_8;
  puVar2[9] = param_9;
  puVar2[10] = param_7;
  puVar2[0xb] = 0;
  if (param_6 != 0) {
    uVar1 = *(undefined2 *)(param_6 + 2);
    uVar4 = *(undefined4 *)(param_6 + 4);
    puVar2[7] = 0;
    puVar2[6] = 0;
    *(undefined2 *)(puVar2 + 4) = 2;
    puVar2[5] = uVar4;
    *(undefined2 *)((int)puVar2 + 0x12) = uVar1;
  }
  sem_wait((sem_t *)(param_1 + 0x10));
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  iVar5 = *(int *)(param_1 + 0x34);
  if (*(int *)(param_1 + 0x34) == 0) {
    puVar2[0xc] = 0;
    *(undefined4 **)(param_1 + 0x34) = puVar2;
  }
  else {
    do {
      iVar3 = iVar5;
      iVar5 = *(int *)(iVar3 + 0x2c);
    } while (*(int *)(iVar3 + 0x2c) != 0);
    *(undefined4 **)(iVar3 + 0x2c) = puVar2;
    puVar2[0xc] = iVar3;
  }
  sem_post((sem_t *)(param_1 + 0x10));
  sem_post((sem_t *)(param_1 + 0x20));
  iVar5 = *(int *)(param_1 + 0xc);
  puVar7 = &_gp;
  sem_wait((sem_t *)&DAT_00427688);
  uVar4 = *(undefined4 *)(iVar5 + 4);
  pcVar6 = *(code **)(puVar7 + -0x7fc0);
  *(undefined4 *)(iVar5 + 4) = 0xffffffff;
  (*pcVar6)(uVar4);
                    /* WARNING: Could not recover jumptable at 0x004140e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(puVar7 + -0x7e68))(&DAT_00427688);
  return;
}

[ASK_GPT] f4951204f170e816
