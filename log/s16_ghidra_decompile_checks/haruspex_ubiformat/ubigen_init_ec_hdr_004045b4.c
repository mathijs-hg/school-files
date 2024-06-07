
void ubigen_init_ec_hdr(ubigen_info *ui,ubi_ec_hdr *hdr,longlong ec)

{
  uint uVar1;
  uint32_t uVar2;
  uint in_a2;
  uint in_a3;
  
[32m  memset(hdr,0,0x40);[0m
  hdr->magic = 0x23494255;
  hdr->version = (__u8)ui->ubi_ver;
  *(uint *)&hdr->ec =
       in_a3 >> 0x18 | in_a3 << 0x18 | (in_a3 & 0xff00) << 8 | (in_a3 & 0xff0000) >> 8;
  *(uint *)((int)&hdr->ec + 4) =
       in_a2 >> 0x18 | in_a2 << 0x18 | (in_a2 & 0xff00) << 8 | (in_a2 & 0xff0000) >> 8;
  uVar1 = ui->vid_hdr_offs;
  hdr->vid_hdr_offset =
       uVar1 >> 0x18 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8;
  uVar1 = ui->data_offs;
  hdr->data_offset = uVar1 >> 0x18 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8
  ;
  uVar1 = ui->image_seq;
  hdr->image_seq = uVar1 >> 0x18 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8;
  uVar2 = mtd_crc32(0xffffffff,hdr,0x3c);
  hdr->hdr_crc = uVar2 >> 0x18 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8;
  return;
}

[ASK_GPT] aa0d5cc31200a0f5
