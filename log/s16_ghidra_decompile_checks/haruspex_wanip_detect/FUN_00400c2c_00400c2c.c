
void FUN_00400c2c(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  printf("[%s] check WAN IP...","wanip_detect");
[32m  system("/usr/sbin/ddns checkip");[0m
  SIReadBin(5,&new_addr,4);
  iVar1 = memcmp(&old_addr,&new_addr,4);
  if (iVar1 == 0) {
    pcVar2 = inet_ntoa(old_addr);
    printf(" no changed(%s)\n",pcVar2);
  }
  else {
    pcVar2 = inet_ntoa(old_addr);
    pcVar3 = inet_ntoa(new_addr);
    printf(" changed: %s -> %s\n",pcVar2,pcVar3);
    old_addr = new_addr;
[32m    system("/usr/sbin/msger eventd 0 estatusnotify 0 3");[0m
  }
  return;
}

[ASK_GPT] caa59516c9ce0ff1
