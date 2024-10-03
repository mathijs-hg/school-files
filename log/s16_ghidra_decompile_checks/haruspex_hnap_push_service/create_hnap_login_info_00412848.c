
undefined4 create_hnap_login_info(void)

{
  char *__s;
  undefined uStack_148c0;
  undefined auStack_148bf [23];
  undefined uStack_148a8;
  undefined auStack_148a7 [23];
  undefined auStack_14890 [16];
  char acStack_14880 [36];
  char acStack_1485c [36];
  char acStack_14838 [12000];
  char acStack_11958 [72000];
  
  uStack_148c0 = 0;
[32m  memset(auStack_148bf,0,0x14);[0m
  uStack_148a8 = 0;
[32m  memset(auStack_148a7,0,0x14);[0m
[32m  memset(acStack_14880,0,0x14868);[0m
  SIReadBin(0x3f,acStack_14880,0x14868);
  random_hash(&uStack_148c0,0x14);
  random_hash(&uStack_148a8,0x14);
[32m[32m  snprintf(acStack_14880,0x23,"%s",&uStack_148c0);[0m[0m
[32m[32m  snprintf(acStack_1485c,0x23,"%s",&uStack_148a8);[0m[0m
  __s = acStack_14838;
  do {
    random_hash(auStack_14890,10);
[32m[32m    snprintf(__s,0xb,"%s",auStack_14890);[0m[0m
    __s = __s + 0xc;
  } while (__s != acStack_11958);
  SIWriteBin(0x3f,acStack_14880,0x14868);
  return 0;
}

[ASK_GPT] b20d07694573af2b
