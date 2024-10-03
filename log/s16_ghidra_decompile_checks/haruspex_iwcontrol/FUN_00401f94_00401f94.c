
void FUN_00401f94(void)

{
  int iVar1;
  
[32m  iVar1 = sockets_open();[0m
  if (iVar1 < 0) {
    perror("socket");
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  return;
}

[ASK_GPT] b35b8a2ac8137832
