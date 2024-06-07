
void ubigen_init_vid_hdr(ubigen_info *ui,ubigen_vol_info *vi,ubi_vid_hdr *hdr,int lnum,void *data,
                        int data_size)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t _x;
  
[32m  memset(hdr,0,0x40);[0m
  hdr->magic = 0x21494255;
  hdr->version = (__u8)ui->ubi_ver;
  hdr->vol_type = (__u8)vi->type;
  uVar1 = vi->id;
  hdr->vol_id = uVar1 >> 0x18 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8;
  hdr->lnum = (uint)lnum >> 0x18 | lnum << 0x18 | (lnum & 0xff00U) << 8 | (lnum & 0xff0000U) >> 8;
  uVar1 = vi->data_pad;
  hdr->data_pad = uVar1 >> 0x18 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8;
  hdr->compat = (__u8)vi->compat;
  if (vi->type == 2) {
    hdr->data_size =
         (uint)data_size >> 0x18 | data_size << 0x18 | (data_size & 0xff00U) << 8 |
         (data_size & 0xff0000U) >> 8;
    uVar1 = vi->used_ebs;
    hdr->used_ebs = uVar1 >> 0x18 | uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8;
    uVar2 = mtd_crc32(0xffffffff,data,data_size);
    hdr->data_crc = uVar2 >> 0x18 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8;
  }
  uVar2 = mtd_crc32(0xffffffff,hdr,0x3c);
  hdr->hdr_crc = uVar2 >> 0x18 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00;
  return;
}

[ASK_GPT] 02f454c735cd770b
