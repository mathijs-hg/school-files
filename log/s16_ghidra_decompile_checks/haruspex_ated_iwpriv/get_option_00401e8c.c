
undefined4 get_option(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  l_port = 0;
  do {
    while( true ) {
      local_c = 0;
[32m      iVar1 = getopt_long(param_1,param_2,&DAT_0040e8a8,arg_options_4160,&local_c);[0m
      if (iVar1 == -1) {
        if (l_port == 0) {
          printf("use default port %d\n",5000);
          l_port = 5000;
        }
        return 0;
      }
      if (iVar1 == 0x68) {
        usage();
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      if (iVar1 == 0x70) break;
      if (iVar1 != 100) goto LAB_0040204c;
      l_debug = 1;
    }
[32m    iVar1 = sscanf(optarg,"%hd",&l_port);[0m
  } while (iVar1 == 1);
LAB_0040204c:
  perror("input parameter wrong!\n");
  usage();
                    /* WARNING: Subroutine does not return */
  exit(-1);
}

[ASK_GPT] cc6c414c4f51e02b
