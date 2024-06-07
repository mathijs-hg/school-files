
bool main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined *puVar5;
  undefined *puVar6;
  ulong uVar7;
  uint uVar8;
  int local_90;
  int local_8c;
  uint local_88;
  ulong local_84;
  ulong local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  ulong local_20;
  ulong local_1c;
  ulong local_18;
  uint local_14;
  uint local_10 [2];
  
  switch_init();
  if (param_1 < 2) {
    usage(*param_2);
  }
  else {
    iVar2 = strcmp((char *)param_2[1],"phy2");
    if (iVar2 == 0) {
      if (param_1 < 4) {
        fwrite("usage: switch phy2 port reg [value]\n",1,0x24,stderr);
        return true;
      }
      uVar3 = strtoul((char *)param_2[2],(char **)0x0,0);
      uVar4 = strtoul((char *)param_2[3],(char **)0x0,0);
      if (param_1 < 5) {
        local_30 = 0;
[32m        mii_read(uVar3,uVar4,&local_30);[0m
        printf("port %d reg %d, value %04x\n",uVar3,uVar4,local_30);
      }
      else {
        local_30 = strtoul((char *)param_2[4],(char **)0x0,0);
        mii_write(uVar3,uVar4,local_30);
      }
    }
    else {
      iVar2 = strcmp((char *)param_2[1],"phy_power");
      if (iVar2 == 0) {
        local_2c = 0;
        if (param_1 < 4) {
          fwrite("usage: switch phy_power {on|off}\n",1,0x21,stderr);
          return true;
        }
        uVar3 = strtoul((char *)param_2[2],(char **)0x0,0);
        if (4 < uVar3) {
          fwrite("port range is 0-4\n",1,0x12,stderr);
          return true;
        }
[32m        mii_read(uVar3,0,&local_2c);[0m
        iVar2 = strcmp((char *)param_2[3],"on");
        if (iVar2 == 0) {
          local_2c = local_2c & 0xfffff7ff;
        }
        else {
          iVar2 = strcmp((char *)param_2[3],"off");
          if (iVar2 != 0) {
            fwrite("usage: switch phy_power {on|off}\n",1,0x21,stderr);
            return true;
          }
          local_2c = local_2c | 0x800;
        }
        mii_write(uVar3,0,local_2c);
      }
      else {
        iVar2 = strcmp((char *)param_2[1],"phy_media_type");
        if (iVar2 == 0) {
          local_28 = 0;
          if (param_1 < 3) {
            fwrite("phy_media_type port [auto|1000MFD|1000MHD|100MFD|100MHD|10MFD|10MHD]\n",1,0x45,
                   stderr);
            return true;
          }
          uVar3 = strtoul((char *)param_2[2],(char **)0x0,0);
          if (4 < uVar3) {
            fwrite("port range is 0-4\n",1,0x12,stderr);
            return true;
          }
[32m          mii_read(uVar3,0,&local_28);[0m
          if (param_1 < 4) {
            if ((local_28 & 0x1000) == 0) {
              if ((local_28 & 0x40) == 0) {
                if ((local_28 & 0x2000) == 0) {
                  puVar5 = &UNK_00411d40;
                }
                else {
                  puVar5 = &DAT_00411d38;
                }
              }
              else {
                puVar5 = &UNK_00411d44;
              }
              if ((local_28 & 0x100) == 0) {
                puVar6 = &DAT_00411d50;
              }
              else {
                puVar6 = &DAT_00411d4c;
              }
              printf("%s%s\n",puVar5,puVar6);
            }
            else {
              puts("auto");
            }
          }
          else {
            iVar2 = strcmp((char *)param_2[3],"auto");
            if (iVar2 == 0) {
              local_28 = local_28 | 0x3040;
            }
            else {
              local_28 = local_28 & 0xffffefff;
              iVar2 = strcmp((char *)param_2[3],"1000MFD");
              if (iVar2 == 0) {
                local_28 = local_28 & 0xffffdfff | 0x140;
              }
              else {
                iVar2 = strcmp((char *)param_2[3],"1000MHD");
                if (iVar2 == 0) {
                  local_28 = local_28 & 0xffffdeff | 0x40;
                }
                else {
                  iVar2 = strcmp((char *)param_2[3],"100MFD");
                  if (iVar2 == 0) {
                    local_28 = local_28 & 0xffffffbf | 0x2100;
                  }
                  else {
                    iVar2 = strcmp((char *)param_2[3],"100MHD");
                    if (iVar2 == 0) {
                      local_28 = local_28 & 0xfffffebf | 0x2000;
                    }
                    else {
                      iVar2 = strcmp((char *)param_2[3],"10MFD");
                      if (iVar2 == 0) {
                        local_28 = local_28 & 0xffffdfbf | 0x100;
                      }
                      else {
                        iVar2 = strcmp((char *)param_2[3],"10MHD");
                        if (iVar2 != 0) {
                          fprintf(stderr,"unsupported media type: %s\n",param_2[3]);
                          return true;
                        }
                        local_28 = local_28 & 0xffffdebf;
                      }
                    }
                  }
                }
              }
            }
            mii_write(uVar3,0,local_28);
          }
        }
        else {
          iVar2 = strcmp((char *)param_2[1],"phy_link_status");
          if (iVar2 == 0) {
            local_84 = 0xff;
            local_24 = 0;
            bVar1 = false;
            if (2 < param_1) {
              local_84 = strtoul((char *)param_2[2],(char **)0x0,0);
            }
            for (local_88 = 0; local_88 < 5; local_88 = local_88 + 1) {
              if ((1 << (local_88 & 0x1f) & local_84) != 0) {
[32m                reg_read(local_88 * 0x100 + 0x3008,&local_24);[0m
                printf("port %d ",local_88);
                if ((local_24 & 1) == 0) {
                  puts("Link DOWN");
                }
                else {
                  bVar1 = true;
                  if ((local_24 & 8) == 0) {
                    if ((local_24 & 4) == 0) {
                      puVar5 = &UNK_00411d40;
                    }
                    else {
                      puVar5 = &DAT_00411d38;
                    }
                  }
                  else {
                    puVar5 = &UNK_00411d44;
                  }
                  if ((local_24 & 2) == 0) {
                    puVar6 = &DAT_00411d50;
                  }
                  else {
                    puVar6 = &DAT_00411d4c;
                  }
                  printf("Link UP %s%s\n",puVar5,puVar6);
                }
              }
            }
            switch_fini();
            return !bVar1;
          }
          if (param_1 == 2) {
            iVar2 = strncmp((char *)param_2[1],"dump",5);
            if (iVar2 == 0) {
              table_dump();
            }
            else {
              iVar2 = strncmp((char *)param_2[1],"clear",6);
              if (iVar2 == 0) {
                table_clear();
                puts("done.");
              }
              else {
                iVar2 = strncmp((char *)param_2[1],"phy",4);
                if (iVar2 == 0) {
                  phy_dump(0x20);
                }
                else {
                  usage(*param_2);
                }
              }
            }
          }
          else {
            iVar2 = strncmp((char *)param_2[1],"add",4);
            if (iVar2 == 0) {
              table_add(param_1,param_2);
            }
            else {
              iVar2 = strncmp((char *)param_2[1],"mymac",4);
              if (iVar2 == 0) {
                table_add(param_1,param_2);
              }
              else {
                iVar2 = strncmp((char *)param_2[1],"filt",5);
                if (iVar2 == 0) {
                  table_add(param_1,param_2);
                }
                else {
                  iVar2 = strncmp((char *)param_2[1],"del",4);
                  if (iVar2 == 0) {
                    iVar2 = strncmp((char *)param_2[4],"fid",4);
                    if (iVar2 == 0) {
                      table_del_fid(param_1,param_2);
                    }
                    else {
                      iVar2 = strncmp((char *)param_2[4],"vid",4);
                      if (iVar2 == 0) {
                        table_del_vid(param_1,param_2);
                      }
                      else {
                        usage(*param_2);
                      }
                    }
                  }
                  else {
                    iVar2 = strncmp((char *)param_2[1],"search",7);
                    if (iVar2 == 0) {
                      iVar2 = strncmp((char *)param_2[4],"fid",4);
                      if (iVar2 == 0) {
                        table_search_mac_fid(param_1,param_2);
                      }
                      else {
                        iVar2 = strncmp((char *)param_2[4],"vid",4);
                        if (iVar2 == 0) {
                          table_search_mac_vid(param_1,param_2);
                        }
                        else {
                          usage(*param_2);
                        }
                      }
                    }
                    else {
                      iVar2 = strncmp((char *)param_2[1],"phy",4);
                      if (iVar2 == 0) {
                        if (param_1 == 3) {
                          iVar2 = strncmp((char *)param_2[2],"mt7530",7);
                          if (iVar2 == 0) {
                            dump_gphy();
                          }
                          else {
                            uVar3 = strtoul((char *)param_2[2],(char **)0x0,10);
                            phy_dump(uVar3);
                          }
                        }
                        else {
                          phy_dump(0x20);
                        }
                      }
                      else {
                        iVar2 = strncmp((char *)param_2[1],"sip",5);
                        if (iVar2 == 0) {
                          if (param_1 < 3) {
                            usage(*param_2);
                          }
                          iVar2 = strncmp((char *)param_2[2],"dump",5);
                          if (iVar2 == 0) {
                            sip_dump();
                          }
                          else {
                            iVar2 = strncmp((char *)param_2[2],"add",4);
                            if (iVar2 == 0) {
                              sip_add(param_1,param_2);
                            }
                            else {
                              iVar2 = strncmp((char *)param_2[2],"del",4);
                              if (iVar2 == 0) {
                                sip_del(param_1,param_2);
                              }
                              else {
                                iVar2 = strncmp((char *)param_2[2],"clear",6);
                                if (iVar2 == 0) {
                                  sip_clear();
                                }
                                else {
                                  usage(*param_2);
                                }
                              }
                            }
                          }
                        }
                        else {
                          iVar2 = strncmp((char *)param_2[1],"dip",4);
                          if (iVar2 == 0) {
                            if (param_1 < 3) {
                              usage(*param_2);
                            }
                            iVar2 = strncmp((char *)param_2[2],"dump",5);
                            if (iVar2 == 0) {
                              dip_dump();
                            }
                            else {
                              iVar2 = strncmp((char *)param_2[2],"add",4);
                              if (iVar2 == 0) {
                                dip_add(param_1,param_2);
                              }
                              else {
                                iVar2 = strncmp((char *)param_2[2],"del",4);
                                if (iVar2 == 0) {
                                  dip_del(param_1,param_2);
                                }
                                else {
                                  iVar2 = strncmp((char *)param_2[2],"clear",6);
                                  if (iVar2 == 0) {
                                    dip_clear();
                                  }
                                  else {
                                    usage(*param_2);
                                  }
                                }
                              }
                            }
                          }
                          else {
                            iVar2 = strncmp((char *)param_2[1],"mirror",7);
                            if (iVar2 == 0) {
                              if (param_1 < 3) {
                                usage(*param_2);
                              }
                              iVar2 = strncmp((char *)param_2[2],"monitor",8);
                              if (iVar2 == 0) {
                                set_mirror_to(param_1,param_2);
                              }
                              else {
                                iVar2 = strncmp((char *)param_2[2],"target",7);
                                if (iVar2 == 0) {
                                  set_mirror_from(param_1,param_2);
                                }
                                else {
                                  usage(*param_2);
                                }
                              }
                            }
                            else {
                              iVar2 = strncmp((char *)param_2[1],"acl",4);
                              if (iVar2 == 0) {
                                if (param_1 < 3) {
                                  usage(*param_2);
                                }
                                iVar2 = strncmp((char *)param_2[2],"dip",4);
                                if (iVar2 == 0) {
                                  iVar2 = strncmp((char *)param_2[3],"add",4);
                                  if (iVar2 == 0) {
                                    acl_dip_add(param_1,param_2);
                                  }
                                  else {
                                    iVar2 = strncmp((char *)param_2[3],"modup",6);
                                    if (iVar2 == 0) {
                                      acl_dip_modify(param_1,param_2);
                                    }
                                    else {
                                      iVar2 = strncmp((char *)param_2[3],"pppoe",6);
                                      if (iVar2 == 0) {
                                        acl_dip_pppoe(param_1,param_2);
                                      }
                                      else {
                                        iVar2 = strncmp((char *)param_2[3],"trtcm",4);
                                        if (iVar2 == 0) {
                                          acl_dip_trtcm(param_1,param_2);
                                        }
                                        else {
                                          iVar2 = strncmp((char *)param_2[3],"meter",6);
                                          if (iVar2 == 0) {
                                            acl_dip_meter(param_1,param_2);
                                          }
                                          else {
                                            usage(*param_2);
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                else {
                                  iVar2 = strncmp((char *)param_2[2],"etype",6);
                                  if (iVar2 == 0) {
                                    iVar2 = strncmp((char *)param_2[3],"add",4);
                                    if (iVar2 == 0) {
                                      acl_ethertype(param_1,param_2);
                                    }
                                    else {
                                      usage(*param_2);
                                    }
                                  }
                                  else {
                                    iVar2 = strncmp((char *)param_2[2],"port",5);
                                    if (iVar2 == 0) {
                                      iVar2 = strncmp((char *)param_2[3],"add",4);
                                      if (iVar2 == 0) {
                                        acl_sp_add(param_1,param_2);
                                      }
                                      else {
                                        usage(*param_2);
                                      }
                                    }
                                    else {
                                      iVar2 = strncmp((char *)param_2[2],"L4",5);
                                      if (iVar2 == 0) {
                                        iVar2 = strncmp((char *)param_2[3],"add",4);
                                        if (iVar2 == 0) {
                                          acl_l4_add(param_1,param_2);
                                        }
                                        else {
                                          usage(*param_2);
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              else {
                                iVar2 = strncmp((char *)param_2[1],"vlan",5);
                                if (iVar2 == 0) {
                                  if (param_1 < 3) {
                                    usage(*param_2);
                                  }
                                  iVar2 = strncmp((char *)param_2[2],"dump",5);
                                  if (iVar2 == 0) {
                                    vlan_dump();
                                  }
                                  else {
                                    iVar2 = strncmp((char *)param_2[2],"set",4);
                                    if (iVar2 == 0) {
                                      vlan_set(param_1,param_2);
                                    }
                                    else {
                                      iVar2 = strncmp((char *)param_2[2],"clear",4);
                                      if (iVar2 == 0) {
                                        vlan_clear(param_1,param_2);
                                      }
                                      else {
                                        usage(*param_2);
                                      }
                                    }
                                  }
                                }
                                else {
                                  iVar2 = strncmp((char *)param_2[1],"reg",4);
                                  if (iVar2 == 0) {
                                    local_20 = 0;
                                    if (param_1 < 4) {
                                      usage(*param_2);
                                    }
                                    if (*(char *)param_2[2] == 'r') {
                                      uVar3 = strtoul((char *)param_2[3],(char **)0x0,0x10);
[32m                                      reg_read(uVar3,&local_20);[0m
                                      printf("switch reg read offset=%x, value=%x\n",uVar3,local_20)
                                      ;
                                    }
                                    else if (*(char *)param_2[2] == 'w') {
                                      if (param_1 != 5) {
                                        usage(*param_2);
                                      }
                                      uVar3 = strtoul((char *)param_2[3],(char **)0x0,0x10);
                                      local_20 = strtoul((char *)param_2[4],(char **)0x0,0x10);
                                      printf("switch reg write offset=%x, value=%x\n",uVar3,local_20
                                            );
                                      reg_write(uVar3,local_20);
                                    }
                                    else if (*(char *)param_2[2] == 'd') {
                                      uVar3 = strtoul((char *)param_2[3],(char **)0x0,0x10);
                                      for (local_90 = 0; local_90 < 0x10; local_90 = local_90 + 1) {
                                        printf("0x%08x: ",local_90 * 0x10 + uVar3);
                                        for (local_8c = 0; local_8c < 4; local_8c = local_8c + 1) {
[32m                                          reg_read((local_90 * 4 + local_8c) * 4 + uVar3,&local_20);[0m
                                          printf(" 0x%08x",local_20);
                                        }
                                        putchar(10);
                                      }
                                    }
                                    else {
                                      usage(*param_2);
                                    }
                                  }
                                  else {
                                    iVar2 = strncmp((char *)param_2[1],"TrReg",4);
                                    if (iVar2 == 0) {
                                      local_1c = 0;
                                      local_18 = 0;
                                      if (param_1 < 4) {
                                        usage(*param_2);
                                      }
                                      if (*(char *)param_2[2] == 'r') {
                                        reg_write_tr(0x1f,0x52b5);
                                        uVar3 = strtoul((char *)param_2[3],(char **)0x0,0x10);
                                        uVar4 = strtoul((char *)param_2[4],(char **)0x0,0x10);
                                        uVar7 = strtoul((char *)param_2[5],(char **)0x0,0x10);
                                        printf("ch_addr = %x, node_addr=%x, data_addr=%x\n",uVar3,
                                               uVar4,uVar7);
                                        uVar8 = uVar3 << 0xb | 0xa000 | uVar4 << 7 | uVar7 << 1;
                                        reg_write_tr(0x10,uVar8);
                                        reg_read_tr(0x11,&local_1c);
                                        reg_read_tr(0x12,&local_18);
                                        printf("switch TrReg read Tr_reg_control=%x, value_H=%x, value_L=%x\n"
                                               ,uVar8,local_18,local_1c);
                                      }
                                      else if (*(char *)param_2[2] == 'w') {
                                        reg_write_tr(0x1f,0x52b5);
                                        uVar3 = strtoul((char *)param_2[3],(char **)0x0,0x10);
                                        uVar4 = strtoul((char *)param_2[4],(char **)0x0,0x10);
                                        uVar7 = strtoul((char *)param_2[5],(char **)0x0,0x10);
                                        local_18 = strtoul((char *)param_2[6],(char **)0x0,0x10);
                                        local_1c = strtoul((char *)param_2[7],(char **)0x0,0x10);
                                        printf("ch_addr = %x, node_addr=%x, data_addr=%x\n",uVar3,
                                               uVar4,uVar7);
                                        uVar8 = uVar3 << 0xb | 0x8000 | uVar4 << 7 | uVar7 << 1;
                                        reg_write_tr(0x11,local_1c);
                                        reg_write_tr(0x12,local_18);
                                        reg_write_tr(0x10,uVar8);
                                        printf("switch TrReg Write Tr_reg_control=%x, value_H=%x, value_L=%x\n"
                                               ,uVar8,local_18,local_1c);
                                      }
                                      else {
                                        usage(*param_2);
                                      }
                                    }
                                    else {
                                      iVar2 = strncmp((char *)param_2[1],"ingress-rate",6);
                                      if (iVar2 == 0) {
                                        if (*(char *)(param_2[2] + 1) == 'n') {
                                          uVar3 = strtoul((char *)param_2[3],(char **)0x0,0);
                                          uVar4 = strtoul((char *)param_2[4],(char **)0x0,0);
                                          ingress_rate_set(1,uVar3,uVar4);
                                          printf("switch port=%d, bw=%d\n",uVar3,uVar4);
                                        }
                                        else if (*(char *)(param_2[2] + 1) == 'f') {
                                          if (param_1 != 4) {
                                            usage(*param_2);
                                          }
                                          uVar3 = strtoul((char *)param_2[3],(char **)0x0,0);
                                          ingress_rate_set(0,uVar3,0);
                                          printf("switch port=%d ingress rate limit off\n",uVar3);
                                        }
                                        else {
                                          usage(*param_2);
                                        }
                                      }
                                      else {
                                        iVar2 = strncmp((char *)param_2[1],"egress-rate",6);
                                        if (iVar2 == 0) {
                                          if (*(char *)(param_2[2] + 1) == 'n') {
                                            uVar3 = strtoul((char *)param_2[3],(char **)0x0,0);
                                            uVar4 = strtoul((char *)param_2[4],(char **)0x0,0);
                                            egress_rate_set(1,uVar3,uVar4);
                                            printf("switch port=%d, bw=%d\n",uVar3,uVar4);
                                          }
                                          else if (*(char *)(param_2[2] + 1) == 'f') {
                                            if (param_1 != 4) {
                                              usage(*param_2);
                                            }
                                            uVar3 = strtoul((char *)param_2[3],(char **)0x0,0);
                                            egress_rate_set(0,uVar3,0);
                                            printf("switch port=%d egress rate limit off\n",uVar3);
                                          }
                                          else {
                                            usage(*param_2);
                                          }
                                        }
                                        else {
                                          iVar2 = strncmp((char *)param_2[1],"tag",4);
                                          if (iVar2 == 0) {
                                            local_14 = 0;
                                            uVar3 = strtoul((char *)param_2[3],(char **)0x0,0);
                                            iVar2 = uVar3 * 0x100 + 0x2004;
[32m                                            reg_read(iVar2,&local_14);[0m
                                            if (*(char *)(param_2[2] + 1) == 'n') {
                                              local_14 = local_14 | 0x20000000;
                                              reg_write(iVar2,local_14);
                                              printf("tag vid at port %d\n",uVar3);
                                            }
                                            else if (*(char *)(param_2[2] + 1) == 'f') {
                                              local_14 = local_14 & 0xc0ffffff;
                                              reg_write(iVar2,local_14);
                                              printf("untag vid at port %d\n",uVar3);
                                            }
                                            else {
                                              usage(*param_2);
                                            }
                                          }
                                          else {
                                            iVar2 = strncmp((char *)param_2[1],"pvid",5);
                                            if (iVar2 == 0) {
                                              local_10[0] = 0;
                                              uVar3 = strtoul((char *)param_2[2],(char **)0x0,0);
                                              uVar4 = strtoul((char *)param_2[3],(char **)0x0,0);
                                              iVar2 = uVar3 * 0x100 + 0x2014;
[32m                                              reg_read(iVar2,local_10);[0m
                                              local_10[0] = local_10[0] & 0xfffff000 | uVar4;
                                              reg_write(iVar2,local_10[0]);
                                              printf("Set port %d pvid %d.\n",uVar3,uVar4);
                                            }
                                            else {
                                              iVar2 = strncmp((char *)param_2[1],"igmpsnoop",10);
                                              if (iVar2 == 0) {
                                                if (param_1 < 3) {
                                                  usage(*param_2);
                                                }
                                                iVar2 = strncmp((char *)param_2[2],"on",3);
                                                if (iVar2 == 0) {
                                                  igmp_on(param_1,param_2);
                                                }
                                                else {
                                                  iVar2 = strncmp((char *)param_2[2],"off",4);
                                                  if (iVar2 == 0) {
                                                    igmp_off();
                                                  }
                                                  else {
                                                    iVar2 = strncmp((char *)param_2[2],"enable",7);
                                                    if (iVar2 == 0) {
                                                      igmp_enable(param_1,param_2);
                                                    }
                                                    else {
                                                      iVar2 = strncmp((char *)param_2[2],"disable",8
                                                                     );
                                                      if (iVar2 == 0) {
                                                        igmp_disable(param_1,param_2);
                                                      }
                                                      else {
                                                        usage(*param_2);
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                              else {
                                                iVar2 = strncmp((char *)param_2[1],"crossover",10);
                                                if (iVar2 == 0) {
                                                  if (param_1 < 4) {
                                                    usage(*param_2);
                                                  }
                                                  else {
                                                    phy_crossover(param_1,param_2);
                                                  }
                                                }
                                                else {
                                                  usage(*param_2);
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  switch_fini();
  return false;
}

[ASK_GPT] 07bb861d99403546
