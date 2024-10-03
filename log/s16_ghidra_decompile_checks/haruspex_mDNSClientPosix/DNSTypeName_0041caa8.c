
char * DNSTypeName(ushort param_1)

{
  if (param_1 == 0x21) {
    return "SRV";
  }
  if (param_1 < 0x22) {
    if (param_1 == 10) {
      return "NULL";
    }
    if (param_1 < 0xb) {
      if (param_1 == 2) {
        return "NS";
      }
      if (param_1 < 3) {
        if (param_1 == 1) {
          return "Addr";
        }
      }
      else {
        if (param_1 == 5) {
          return "CNAME";
        }
        if (param_1 == 6) {
          return "SOA";
        }
      }
    }
    else {
      if (param_1 == 0xd) {
        return "HINFO";
      }
      if (param_1 < 0xe) {
        if (param_1 == 0xc) {
          return "PTR";
        }
      }
      else {
        if (param_1 == 0x10) {
          return "TXT";
        }
        if (param_1 == 0x1c) {
          return "AAAA";
        }
      }
    }
  }
  else {
    if (param_1 == 0x30) {
      return "DNSKEY";
    }
    if (param_1 < 0x31) {
      if (param_1 == 0x2b) {
        return "DS";
      }
      if (param_1 < 0x2c) {
        if (param_1 == 0x29) {
          return "OPT";
        }
      }
      else {
        if (param_1 == 0x2e) {
          return "RRSIG";
        }
        if (param_1 == 0x2f) {
          return "NSEC";
        }
      }
    }
    else {
      if (param_1 == 0x33) {
        return "NSEC3PARAM";
      }
      if (param_1 < 0x34) {
        if (param_1 == 0x32) {
          return "NSEC3";
        }
      }
      else {
        if (param_1 == 0xfa) {
          return "TSIG";
        }
        if (param_1 == 0xff) {
          return "ANY";
        }
      }
    }
  }
[32m  mDNS_snprintf(&DAT_0046e7e8,0x10,"TYPE%d");[0m
  return &DAT_0046e7e8;
}

[ASK_GPT] 562b8a3482f8bbd6
