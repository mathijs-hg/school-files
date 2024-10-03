
void FUN_004474d0(int param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint __n;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char local_70 [80];
  
  if (*(int *)(param_1 + 0x3908) == 0) {
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"AdvertiseInterface: Returning due to AutoTargetServices zero for %s",
                      (int)param_2 + 0x1552);
    }
  }
  else {
    for (puVar4 = *(undefined4 **)(param_1 + 0x2174);
        (puVar5 = param_2, puVar4 != (undefined4 *)0x0 &&
        (puVar5 = puVar4, *(char *)((int)puVar4 + 0x1592) == '\0')); puVar4 = (undefined4 *)*puVar4)
    {
    }
    uVar2 = 2;
    if ((*(char *)(param_2 + 0x566) != '\0') && (uVar2 = 0x20, mDNS_LoggingEnabled != 0)) {
      LogMsgWithLevel(3,
                      "AdvertiseInterface: Marking address record as kDNSRecordTypeKnownUnique for %s"
                      ,(int)param_2 + 0x1552);
      uVar2 = 0x20;
    }
    mDNS_SetupResourceRecord(param_2 + 0x2a5,0,param_2[0x548],1,0x78,uVar2,0,FUN_00447a20,param_2);
    mDNS_SetupResourceRecord(param_2 + 0x386,0,param_2[0x548],0xc,0x78,0x20,0,0,0);
    mDNS_SetupResourceRecord(param_2 + 0x467,0,param_2[0x548],0xd,0x78,2,0,0,0);
    __n = DomainNameLengthLimit((void *)(param_1 + 0x1ad9),param_1 + 0x1bd9);
    if (__n < 0x101) {
      mDNSPlatformMemCopy(param_2 + 0x303,(void *)(param_1 + 0x1ad9),__n);
    }
    else {
      *(undefined *)(param_2 + 0x303) = 0;
    }
    if (param_2[0x549] == 4) {
      *(undefined2 *)((int)param_2 + 0xa9a) = 1;
      *(undefined4 *)(param_2[0x2ae] + 4) = param_2[0x54a];
      mDNS_snprintf(local_70,0x4a,"%d.%d.%d.%d.in-addr.arpa.",*(undefined *)((int)param_2 + 0x152b),
                    *(undefined *)((int)param_2 + 0x152a),*(undefined *)((int)param_2 + 0x1529),
[32m                    *(undefined *)(param_2 + 0x54a));[0m
    }
    else if (param_2[0x549] == 6) {
      *(undefined2 *)((int)param_2 + 0xa9a) = 0x1c;
[32m[32m      memcpy((void *)(param_2[0x2ae] + 4),param_2 + 0x54a,0x10);[0m[0m
      pcVar3 = local_70;
      puVar4 = param_2;
      do {
        bVar1 = *(byte *)((int)puVar4 + 0x1537);
        pcVar3[1] = '.';
        *pcVar3 = "0123456789ABCDEF"[bVar1 & 0xf];
        bVar1 = *(byte *)((int)puVar4 + 0x1537);
        pcVar3[3] = '.';
        pcVar3[2] = "0123456789ABCDEF"[bVar1 >> 4];
        pcVar3 = pcVar3 + 4;
        puVar4 = (undefined4 *)((int)puVar4 + -1);
      } while (pcVar3 != local_70 + 0x40);
[32m      mDNS_snprintf(local_70 + 0x40,10,"ip6.arpa.");[0m
    }
    MakeDomainNameFromDNSNameString(param_2 + 0x3e4,local_70);
    *(undefined *)((int)param_2 + 0xe62) = 1;
    param_2[0x2b4] = puVar5 + 0x2a5;
    *(undefined *)(param_2 + 0x398) = 1;
    mDNS_Register_internal(param_1,param_2 + 0x2a5);
    mDNS_Register_internal(param_1,param_2 + 0x386);
    *(undefined *)(param_2 + 0x468) = 0;
  }
  return;
}

[ASK_GPT] b7e4ad8f1f1f2fa8
