
void phy_crossover(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  int iVar2;
  uint local_10;
  
  uVar1 = strtoul((char *)param_2[2],(char **)0x0,10);
  if (((int)uVar1 < 0) || (4 < (int)uVar1)) {
    usage(*param_2);
  }
  else {
[32m    local_10 = mii_mgr_cl45_read(uVar1,0x1e,0x145);[0m
    printf("mii_mgr_cl45:");
    printf("Read:  port#=%d, device=0x%x, reg=0x%x, value=0x%x\n",uVar1,0x1e,0x145,local_10);
    iVar2 = strncmp((char *)param_2[3],"auto",5);
    if (iVar2 == 0) {
      local_10 = local_10 & 0xffffffe7;
    }
    else {
      iVar2 = strncmp((char *)param_2[3],"mdi",4);
      if (iVar2 == 0) {
        local_10 = local_10 & 0xffffffe7 | 0x10;
      }
      else {
        iVar2 = strncmp((char *)param_2[3],"mdix",5);
        if (iVar2 != 0) {
          usage(*param_2);
          return;
        }
        local_10 = local_10 | 0x18;
      }
    }
    printf("Write: port#=%d, device=0x%x, reg=0x%x. value=0x%x\n",uVar1,0x1e,0x145,local_10);
    mii_mgr_cl45_write(uVar1,0x1e,0x145,local_10);
  }
  return;
}

[ASK_GPT] 5b98510e4ea38e57
