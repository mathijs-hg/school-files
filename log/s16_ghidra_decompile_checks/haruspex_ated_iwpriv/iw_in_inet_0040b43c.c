
undefined4 iw_in_inet(char *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  netent *pnVar3;
  uint32_t uVar4;
  hostent *phVar5;
  int *piVar6;
  int *piVar7;
  
  *param_2 = 2;
  param_2[1] = 0;
  iVar1 = strcmp(param_1,"default");
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 2) = 0;
    uVar2 = 1;
  }
  else {
    pnVar3 = getnetbyname(param_1);
    if (pnVar3 == (netent *)0x0) {
      phVar5 = gethostbyname(param_1);
      if (phVar5 == (hostent *)0x0) {
        piVar6 = __errno_location();
        piVar7 = __h_errno_location();
        *piVar6 = *piVar7;
        uVar2 = 0xffffffff;
      }
      else {
[32m        memcpy(param_2 + 2,*phVar5->h_addr_list,phVar5->h_length);[0m
[32m[32m        strcpy(param_1,phVar5->h_name);[0m[0m
        uVar2 = 0;
      }
    }
    else {
      uVar4 = htonl(pnVar3->n_net);
      *(uint32_t *)(param_2 + 2) = uVar4;
[32m[32m      strcpy(param_1,pnVar3->n_name);[0m[0m
      uVar2 = 1;
    }
  }
  return uVar2;
}

[ASK_GPT] 346def76a144220c
