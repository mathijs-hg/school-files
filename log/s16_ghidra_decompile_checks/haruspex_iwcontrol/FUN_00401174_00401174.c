
void FUN_00401174(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = &_gp;
  while( true ) {
[32m    iVar1 = open(param_2,1,0,param_4,puVar2);[0m
    *param_1 = iVar1;
    if (-1 < iVar1) break;
    iw_message(0x14,"wait %s to create",param_2);
    sleep(1);
  }
  return;
}

[ASK_GPT] 17d2df844fc06554
