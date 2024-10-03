
void uDNS_ReceiveNATPacket(int param_1,undefined4 param_2,byte *param_3,ushort param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  byte *pbVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint in_stack_ffffffa8;
  short sVar15;
  uint in_stack_ffffffac;
  int local_40 [2];
  byte *local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
  if (param_4 == 0) {
    LogMsgWithLevel(0,"uDNS_ReceiveNATPacket: zero length packet");
    return;
  }
  uVar7 = (ushort)*param_3;
  uVar8 = param_4;
  if (uVar7 == 2) {
    uVar7 = 0;
    uVar11 = 0;
    local_40[0] = 0;
    pbVar9 = *(byte **)(param_1 + 0x29dc);
    if (param_4 < 0x18) {
      pcVar5 = "uDNS_ReceivePCPPacket: message too short (%d bytes)";
    }
    else {
      bVar10 = param_3[1];
      if (((char)bVar10 < '\0') && ((bVar10 & 0x7f) < 2)) {
        *(uint *)(param_3 + 4) =
             (uint)param_3[4] << 0x18 | (uint)param_3[5] << 0x10 | (uint)param_3[7] |
             (uint)param_3[6] << 8;
        uVar12 = (uint)param_3[8] << 0x18 | (uint)param_3[9] << 0x10 | (uint)param_3[0xb] |
                 (uint)param_3[10] << 8;
        *(uint *)(param_3 + 8) = uVar12;
        iVar3 = mDNSPlatformOneSecond;
        uVar14 = 1;
        if (uVar12 != 0) {
          uVar14 = uVar12;
        }
        iVar1 = *(int *)(param_1 + 0x234);
        iVar6 = *(int *)(param_1 + 0x29e0);
        iVar4 = *(int *)(param_1 + 0x29dc);
        *(int *)(param_1 + 0x29e0) = iVar1;
        *(uint *)(param_1 + 0x29dc) = uVar14;
        if (*(int *)(param_1 + 0x2a78) != 0) {
          local_38 = pbVar9;
          local_34 = iVar6;
          local_30 = iVar4;
          local_2c = iVar1;
          mDNSPlatformUDPClose();
          *(undefined4 *)(param_1 + 0x2a78) = 0;
          iVar1 = local_2c;
          iVar4 = local_30;
          iVar6 = local_34;
          pbVar9 = local_38;
        }
        if (pbVar9 != (byte *)0x0) {
          uVar12 = uVar12 - iVar4;
          uVar14 = (iVar1 - iVar6) / iVar3;
          if (iVar3 == 0) {
            trap(0x1c00);
          }
          if ((uVar14 + 2 < uVar12 - (uVar12 >> 4)) || (uVar12 + 2 < uVar14 - (uVar14 >> 4))) {
            uVar2 = 0;
            if ((bVar10 & 0x7f) == 0) {
              uVar2 = mDNSRandom(mDNSPlatformOneSecond * 5);
            }
            local_2c = uVar2;
            LogMsgWithLevel(0,
                            "uDNS_ReceivePCPPacket: Epoch invalid, %#a likely rebooted, waiting %u ticks"
                            ,param_1 + 0x2198,uVar2);
            RecreateNATMappings(param_1,local_2c);
            return;
          }
        }
        if ((bVar10 & 0x7f) == 0) {
          return;
        }
        *(ushort *)(param_1 + 0x29e4) = (ushort)param_3[3];
        if (param_3[3] == 0) {
          if (param_4 < 0x3c) {
            pcVar5 = "uDNS_ReceivePCPPacket: mapping response too short (%d bytes)";
            goto LAB_004118d4;
          }
          if (((*(int *)(param_3 + 0x18) != *(int *)(param_1 + 0x29cc)) ||
              (*(int *)(param_3 + 0x1c) != *(int *)(param_1 + 0x29d0))) ||
             (*(int *)(param_3 + 0x20) != *(int *)(param_1 + 0x29d4))) {
            uVar11 = (uint)(param_3 + 0x1c) & 3;
            uVar14 = (uint)(param_3 + 0x1f) & 3;
            LogMsgWithLevel(0,
                            "uDNS_ReceivePCPPacket: invalid nonce, ignoring. received { %x %x %x } expected { %x %x %x }"
                            ,*(int *)(param_3 + 0x18),
                            *(int *)(param_3 + 0x1c + -uVar11) << uVar11 * 8 &
                            -1 << (uVar14 + 1) * 8 |
                            *(uint *)(param_3 + 0x1f + -uVar14) >> (3 - uVar14) * 8,
                            *(undefined4 *)(param_3 + 0x20),*(int *)(param_1 + 0x29cc),
                            *(undefined4 *)(param_1 + 0x29d0),*(undefined4 *)(param_1 + 0x29d4));
            return;
          }
          local_38 = param_3 + 0x2c;
          uVar7 = *(ushort *)(param_3 + 0x2a);
          uVar11 = (uint)*(ushort *)(param_3 + 0x28);
          uVar14 = (uint)param_3[0x24];
          iVar3 = mDNSAddrIPv4FromMappedIPv6(local_38,local_40);
          if (iVar3 == 0) {
            LogMsgWithLevel(0,"uDNS_ReceivePCPPacket: unexpected external address: %.16a",local_38);
          }
          else if (local_40[0] != 0) goto LAB_00411520;
          param_3[3] = 3;
        }
        else {
          if (mDNS_LoggingEnabled != 0) {
            in_stack_ffffffac = *(uint *)(param_3 + 8);
            LogMsgWithLevel(3,
                            "uDNS_ReceivePCPPacket: error received from server. opcode %X result %X lifetime %X epoch %X"
                            ,param_3[1],param_3[3],*(undefined4 *)(param_3 + 4),in_stack_ffffffac);
          }
          uVar14 = 0;
          if (0x3b < param_4) {
            uVar14 = (uint)param_3[0x24];
            uVar11 = (uint)*(ushort *)(param_3 + 0x28);
          }
        }
LAB_00411520:
        local_30 = 0x11;
        local_2c = 9;
        for (puVar13 = *(undefined4 **)(param_1 + 0x29b8); puVar13 != (undefined4 *)0x0;
            puVar13 = (undefined4 *)*puVar13) {
          uVar12 = local_30;
          if ((*(byte *)(puVar13 + 0xd) & 2) != 0) {
            uVar12 = 6;
          }
          if (((uVar14 == uVar12) && (*(ushort *)((int)puVar13 + 0x36) == uVar11)) ||
             ((*(byte *)(puVar13 + 0xd) == 0 && ((uVar14 == 6 && (local_2c == uVar11)))))) {
            uVar2 = 0;
            if (param_3[3] != 0) {
              uVar2 = 3;
            }
            in_stack_ffffffac = in_stack_ffffffac & 0xffff | (uint)uVar7 << 0x10;
            FUN_0040b388(param_1,puVar13,param_2,uVar2,local_40[0],in_stack_ffffffac,
                         *(undefined4 *)(param_3 + 4),3);
          }
        }
        return;
      }
      pcVar5 = "uDNS_ReceivePCPPacket: unhandled opCode %u";
      uVar8 = (ushort)bVar10;
    }
    goto LAB_004118d4;
  }
  if (uVar7 != 0) {
    pcVar5 = "uDNS_ReceiveNATPacket: packet with version %u (expected %u or %u)";
[32m    sVar15 = 0;[0m
    bVar10 = 2;
LAB_00411918:
    LogMsgWithLevel(0,pcVar5,uVar7,bVar10,sVar15);
    return;
  }
  if (param_4 < 4) {
    pcVar5 = "NAT-PMP message too short (%d bytes)";
    goto LAB_004118d4;
  }
[32m  sVar15 = *(short *)(param_3 + 2);[0m
  param_3[3] = (byte)sVar15;
  param_3[2] = (byte)((ushort)sVar15 >> 8);
  if (sVar15 == 1) {
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"NAT-PMP version unsupported message received");
    }
    for (puVar13 = *(undefined4 **)(param_1 + 0x29b8); puVar13 != (undefined4 *)0x0;
        puVar13 = (undefined4 *)*puVar13) {
      FUN_0040efd0(param_1,puVar13,0);
    }
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x234);
    return;
  }
  if (param_4 < 8) {
    bVar10 = param_3[1];
    pcVar5 = "NAT-PMP message too short (%d bytes) 0x%X 0x%X";
    uVar7 = param_4;
    goto LAB_00411918;
  }
  uVar11 = (uint)param_3[4] << 0x18 | (uint)param_3[5] << 0x10 | (uint)param_3[7] |
           (uint)param_3[6] << 8;
  *(uint *)(param_3 + 4) = uVar11;
  if (uVar11 < *(uint *)(param_1 + 0x29dc)) {
LAB_00411720:
    LogMsgWithLevel(0,"NAT-PMP epoch time check failed: assuming NAT gateway %#a rebooted",
                    param_1 + 0x2198);
    RecreateNATMappings(param_1,0);
  }
  else {
    uVar14 = (*(int *)(param_1 + 0x234) - *(int *)(param_1 + 0x29e0)) / mDNSPlatformOneSecond;
    if (mDNSPlatformOneSecond == 0) {
      trap(0x1c00);
    }
    if ((2 - *(uint *)(param_1 + 0x29dc)) + uVar11 < uVar14 - (uVar14 >> 3)) goto LAB_00411720;
  }
  uVar2 = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(param_1 + 0x29e0) = *(undefined4 *)(param_1 + 0x234);
  *(undefined4 *)(param_1 + 0x29dc) = uVar2;
  uVar8 = (ushort)param_3[1];
  if (uVar8 == 0x80) {
    if ((*(short *)(param_3 + 2) != 0) || (0xb < param_4)) {
      FUN_0040e998(param_1,*(short *)(param_3 + 2),*(undefined4 *)(param_3 + 8));
LAB_004118e4:
      if (*(int *)(param_1 + 0x2a78) == 0) {
        return;
      }
      mDNSPlatformUDPClose();
      *(undefined4 *)(param_1 + 0x2a78) = 0;
      return;
    }
    pcVar5 = "NAT-PMP AddrResponse message too short (%d bytes)";
    uVar8 = param_4;
  }
  else {
    if ((uVar8 + 0x7f & 0xff) < 2) {
      if (*(short *)(param_3 + 2) == 0) {
        if (param_4 < 0x10) {
          pcVar5 = "NAT-PMP PortMapReply message too short (%d bytes)";
          uVar8 = param_4;
          goto LAB_004118d4;
        }
        *(uint *)(param_3 + 0xc) =
             (uint)param_3[0xc] << 0x18 | (uint)param_3[0xd] << 0x10 | (uint)param_3[0xf] |
             (uint)param_3[0xe] << 8;
      }
      puVar13 = *(undefined4 **)(param_1 + 0x29b8);
      *(undefined2 *)(param_1 + 0x29e4) = *(undefined2 *)(param_3 + 2);
      for (; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {
        if (((ushort)*(byte *)(puVar13 + 0xd) == (uVar8 & 0x7f)) &&
           ((uint)*(ushort *)((int)puVar13 + 0x36) == (uint)*(ushort *)(param_3 + 8))) {
          uVar11 = (uint)(param_3 + 0xc) & 3;
          uVar14 = (uint)(param_3 + 0xf) & 3;
          in_stack_ffffffa8 = in_stack_ffffffa8 & 0xffff | (uint)*(ushort *)(param_3 + 10) << 0x10;
          FUN_0040b678(param_1,puVar13,param_2,*(undefined2 *)(param_3 + 2),in_stack_ffffffa8,
                       (*(int *)(param_3 + 0xc + -uVar11) << uVar11 * 8 |
                       (uint)*(ushort *)(param_3 + 8) & 0xffffffffU >> (4 - uVar11) * 8) &
                       -1 << (uVar14 + 1) * 8 |
                       *(uint *)(param_3 + 0xf + -uVar14) >> (3 - uVar14) * 8,1);
        }
      }
      goto LAB_004118e4;
    }
    pcVar5 = "Received NAT-PMP response with unknown opcode 0x%X";
  }
LAB_004118d4:
  LogMsgWithLevel(0,pcVar5,uVar8);
  return;
}

[ASK_GPT] 801de47011808c43
