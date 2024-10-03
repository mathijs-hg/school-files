
/* WARNING: Removing unreachable block (ram,0x00414160) */

void ILibLifeTime_AddEx(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  timeval local_28;
  int local_20;
  uint local_1c;
  
  local_20 = param_3;
  local_1c = param_4;
[32m[32m  puVar2 = (uint *)malloc(0x18);[0m[0m
  gettimeofday(&local_28,(__timezone_ptr_t)0x0);
  puVar2[3] = param_5;
  puVar2[1] = param_2;
  puVar2[2] = local_1c;
  puVar2[5] = 0;
  puVar2[4] = 0;
  *puVar2 = local_28.tv_usec / 1000 + local_28.tv_sec * 1000 + local_20;
  sem_wait((sem_t *)(param_1 + 0x18));
  if (*(uint **)(param_1 + 0xc) == (uint *)0x0) {
    *(uint **)(param_1 + 0xc) = puVar2;
LAB_0041422c:
    ILibForceUnBlockChain(*(undefined4 *)(param_1 + 0x10));
  }
  else {
    puVar1 = *(uint **)(param_1 + 0xc);
    do {
      puVar3 = puVar1;
      if (*puVar2 <= *puVar3) {
        puVar2[5] = (uint)puVar3;
        if (puVar3[4] == 0) {
          *(uint **)(param_1 + 0xc) = puVar2;
          puVar3[4] = (uint)puVar2;
          goto LAB_0041422c;
        }
        puVar2[4] = puVar3[4];
        *(uint **)(puVar3[4] + 0x14) = puVar2;
        puVar3[4] = (uint)puVar2;
        goto LAB_0041423c;
      }
      puVar1 = (uint *)puVar3[5];
    } while ((uint *)puVar3[5] != (uint *)0x0);
    puVar2[5] = 0;
    puVar2[4] = (uint)puVar3;
    puVar3[5] = (uint)puVar2;
  }
LAB_0041423c:
  sem_post((sem_t *)(param_1 + 0x18));
  return;
}

[ASK_GPT] c4a9f43d0f33b50f
