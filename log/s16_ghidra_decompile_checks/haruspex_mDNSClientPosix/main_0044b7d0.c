
undefined4 main(int param_1,char **param_2)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  undefined *puVar4;
  undefined4 uVar5;
  char *__s;
  char acStack_4c0 [256];
  undefined auStack_3c0 [256];
  undefined auStack_2c0 [656];
  char *local_30;
  
  __s = *param_2;
  pcVar1 = strrchr(__s,0x2f);
  PTR_ProgramName_0046e0d8 = __s;
  if (pcVar1 != (char *)0x0) {
    PTR_ProgramName_0046e0d8 = pcVar1 + 1;
  }
  do {
[32m    iVar2 = getopt(param_1,param_2,"v:t:d:s:f:p:");[0m
    if (iVar2 == -1) {
      if (optind == param_1) {
        iVar2 = mDNS_Init(&DAT_0046e840,&DAT_0047895c,&DAT_00478964,500,0,0,0);
        if (iVar2 == 0) {
          if (DAT_0046e834 != (char *)0x0) {
[32m            DAT_0046e830 = fopen(DAT_0046e834,"w");[0m
            if (DAT_0046e830 == (FILE *)0x0) {
              fprintf(stderr,"create output file [%s] failed\n",DAT_0046e834);
            }
            fwrite("<root>\n",1,7,DAT_0046e830);
          }
          local_30 = acStack_4c0;
          MakeDomainNameFromDNSNameString(local_30,PTR_s__afpovertcp__tcp_0046e0d0);
          MakeDomainNameFromDNSNameString(auStack_3c0,PTR_s_local__0046e0d4);
          iVar2 = mDNS_StartBrowse(&DAT_0046e840,auStack_2c0,local_30,auStack_3c0,0,0,0,0,0,
                                   FUN_0044be14,0);
          if (iVar2 != 0) goto LAB_0044bd68;
          fputs("Hit ^C when you\'re bored waiting for responses.\n",stderr);
          if (0 < DAT_0046e838) {
            setTimer();
          }
          ExampleClientEventLoop(&DAT_0046e840);
          mDNS_StopQuery(&DAT_0046e840,auStack_2c0);
          mDNS_StartExit(&DAT_0046e840);
          mDNS_FinalExit(&DAT_0046e840);
          uVar5 = 0;
          if ((int)gMDNSPlatformPosixVerboseLevel < 1) goto LAB_0044bd98;
        }
        else {
LAB_0044bd68:
          uVar5 = 2;
        }
        fprintf(stderr,"%s: Finished with status %d, result %d\n",PTR_ProgramName_0046e0d8,iVar2,
                uVar5);
LAB_0044bd98:
        setTimer(0);
        if (DAT_0046e830 != (FILE *)0x0) {
          fwrite("</root>\n",1,8,DAT_0046e830);
          fclose(DAT_0046e830);
        }
        return 0;
      }
      fprintf(stderr,"%s: Unexpected argument \'%s\'\n",PTR_ProgramName_0046e0d8,param_2[optind]);
      goto LAB_0044b968;
    }
    switch(iVar2) {
    case 100:
      PTR_s_local__0046e0d4 = optarg;
      break;
    default:
      fprintf(stderr,
              "Usage: %s [-v level] [-t type] [-d domain] [-s running time] [-p write discovery result file path] [-f discovery file format]\n"
              ,PTR_ProgramName_0046e0d8);
      fputs("          -v verbose mode, level is a number from 0 to 2\n",stderr);
      fputs("             0 = no debugging info (default)\n",stderr);
      fputs("             1 = standard debugging info\n",stderr);
      fputs("             2 = intense debugging info\n",stderr);
      fprintf(stderr,"          -t uses \'type\' as the service type (default is \'%s\')\n",
              "_afpovertcp._tcp");
      fprintf(stderr,"          -d uses \'domain\' as the domain to browse (default is \'%s\')\n",
              "local.");
      fputs("          -p write discovery result file path\n",stderr);
      fputs("          -f write discovery result file format\n",stderr);
      fputs("             0 = xml format\n",stderr);
      fputs("             1 = ini format\n",stderr);
      fputs("          -s discovery timeout\n",stderr);
      goto LAB_0044b968;
    case 0x66:
      puVar4 = (undefined *)atoi(optarg);
      DAT_0046e83c = puVar4;
      if ((undefined *)0x1 < puVar4) {
        pcVar1 = "%d: file format must be 0 and 1 - 0: xml format, 1: ini format\n";
        goto LAB_0044b9fc;
      }
      break;
    case 0x70:
      fprintf(stderr,"%s\n",optarg);
      DAT_0046e834 = optarg;
      break;
    case 0x73:
      DAT_0046e838 = atoi(optarg);
      break;
    case 0x74:
      PTR_s__afpovertcp__tcp_0046e0d0 = optarg;
      local_30 = PTR_s__afpovertcp__tcp_0046e0d0;
      sVar3 = strlen(optarg);
      if (sVar3 < 0x40) {
        if (*local_30 != '\0') break;
        pcVar1 = "%s: Service type specified by -t can\'t be empty\n";
      }
      else {
        pcVar1 = "%s: Service type specified by -t is too long (must be 63 characters or less)\n";
      }
[32m      fprintf(stderr,pcVar1,PTR_ProgramName_0046e0d8);[0m
      goto LAB_0044b968;
    case 0x76:
      gMDNSPlatformPosixVerboseLevel = atoi(optarg);
      if (2 < gMDNSPlatformPosixVerboseLevel) {
        pcVar1 = "%s: Verbose mode must be in the range 0..2\n";
        puVar4 = PTR_ProgramName_0046e0d8;
LAB_0044b9fc:
[32m        fprintf(stderr,pcVar1,puVar4);[0m
LAB_0044b968:
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    }
  } while( true );
}

[ASK_GPT] 222e19019244aad7
