
undefined4 FUN_00405e2c(char *param_1,undefined2 *param_2)

{
  int iVar1;
  netent *pnVar2;
  hostent *phVar3;
  int *piVar4;
  int *piVar5;
  
  *param_2 = 2;
  param_2[1] = 0;
  iVar1 = strcmp(param_1,"default");
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 2) = 0;
  }
  else {
    pnVar2 = getnetbyname(param_1);
    if (pnVar2 == (netent *)0x0) {
      phVar3 = gethostbyname(param_1);
      if (phVar3 == (hostent *)0x0) {
        piVar4 = __errno_location();
        piVar5 = __h_errno_location();
        *piVar4 = *piVar5;
        return 0xffffffff;
      }
[32m      memcpy(param_2 + 2,*phVar3->h_addr_list,phVar3->h_length);[0m
[32m[32m      strcpy(param_1,phVar3->h_name);[0m[0m
      return 0;
    }
    *(uint32_t *)(param_2 + 2) = pnVar2->n_net;
[32m[32m    strcpy(param_1,pnVar2->n_name);[0m[0m
  }
  return 1;
}

[ASK_GPT] 4dcd334c057bcda9
