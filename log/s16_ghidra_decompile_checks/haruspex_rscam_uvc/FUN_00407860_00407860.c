
__blkcnt_t FUN_00407860(char *param_1)

{
  stat sStack_a0;
  
[32m  memset(&sStack_a0,0,0x98);[0m
[32m[32m  stat(param_1,&sStack_a0);[0m[0m
  return sStack_a0.st_blocks;
}

[ASK_GPT] 1ba09a754e490f0e
