
undefined4 init_debug(void)

{
  if (l_debug != 0) {
[32m    l_debugStream = fopen("/dev/console","a");[0m
    if (l_debugStream == (FILE *)0x0) {
      perror("debug stream open error, quit!\n");
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
  }
  return 0;
}

[ASK_GPT] e2463fefd3285505
