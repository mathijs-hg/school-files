
/* WARNING: Could not reconcile some variable overlaps */

undefined4 iw_in_addr(int param_1,char *param_2,char *param_3,int *param_4)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  char acStack_24 [20];
  
  pcVar1 = strchr(param_3,0x3a);
  if (pcVar1 == (char *)0x0) {
    iVar2 = iw_check_if_addr_type(param_1,param_2);
    if (iVar2 < 0) {
      fprintf(stderr,"%-8.16s  Interface doesn\'t support IP addresses\n",param_2);
      return 0xffffffff;
    }
    iVar2 = iw_in_inet(param_3,&local_68);
    if (iVar2 < 0) {
      fprintf(stderr,"Invalid interface address %s\n",param_3);
      return 0xffffffff;
    }
    local_58 = local_68;
    local_54 = local_64;
    local_50 = local_60;
    local_4c = local_5c;
    local_48 = (uint)local_48._2_2_ << 0x10;
    local_38 = 0;
[32m[32m[32m    strncpy(acStack_24,param_2,0x10);[0m[0m[0m
    iVar2 = ioctl(param_1,0x8954,&local_58);
    __stream = stderr;
    if ((iVar2 < 0) || ((local_38 & 2) == 0)) {
      piVar3 = __errno_location();
      fprintf(__stream,
              "Arp failed for %s on %s... (%d)\nTry to ping the address before setting it.\n",
              param_3,param_2,*piVar3);
      return 0xffffffff;
    }
    *param_4 = local_48;
    param_4[1] = local_44;
    param_4[2] = local_40;
    param_4[3] = local_3c;
  }
  else {
    iVar2 = iw_check_mac_addr_type(param_1,param_2);
    if (iVar2 < 0) {
      fprintf(stderr,"%-8.16s  Interface doesn\'t support MAC addresses\n",param_2);
      return 0xffffffff;
    }
    *(undefined2 *)param_4 = 1;
    iVar2 = iw_ether_aton(param_3,(undefined2 *)((int)param_4 + 2));
    if (iVar2 == 0) {
      fprintf(stderr,"Invalid hardware address %s\n",param_3);
      return 0xffffffff;
    }
  }
  return 0;
}

[ASK_GPT] 5c39170d0c6aa9dd
