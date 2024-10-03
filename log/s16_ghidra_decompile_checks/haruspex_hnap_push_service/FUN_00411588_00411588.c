
undefined4 FUN_00411588(char *param_1,char *param_2)

{
  hostent *phVar1;
  undefined4 uVar2;
  char *__src;
  
  phVar1 = gethostbyname(param_1);
  if (phVar1 == (hostent *)0x0) {
    fprintf(stderr,"[hnap_push_service][%s] gethostbyname failed\n","gethostnameip");
    uVar2 = 0xffffffff;
  }
  else {
    __src = inet_ntoa((in_addr)*(in_addr_t *)*phVar1->h_addr_list);
[32m[32m    strcpy(param_2,__src);[0m[0m
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] 96b48db484834c04
