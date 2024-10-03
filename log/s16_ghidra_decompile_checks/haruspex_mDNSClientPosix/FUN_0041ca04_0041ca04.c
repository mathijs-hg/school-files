
char * FUN_0041ca04(char param_1)

{
  char *pcVar1;
  
  switch(param_1 + -5) {
  case '\0':
    pcVar1 = "RSA_SHA1";
    break;
  case '\x01':
    pcVar1 = "DSA_NSEC3_SHA1";
    break;
  case '\x02':
    pcVar1 = "RSA_NSEC3_SHA1";
    break;
  case '\x03':
    pcVar1 = "RSA_SHA256";
    break;
  default:
[32m    mDNS_snprintf(&DAT_0046e7c8,0x10,"ALG%d");[0m
    pcVar1 = &DAT_0046e7c8;
    break;
  case '\x05':
    pcVar1 = "RSA_SHA512";
  }
  return pcVar1;
}

[ASK_GPT] ed2bf8ac4b4264f4
