LuaQ               
X      A@    ΐ@@  A@  E   \   Αΐ  Κ  Ι@BΙΐB
  	C	ACJ  ICIΑC  DADΚ 
  		BEΙ
  	Β	ΒEΙ
  	Β	BFΙ
  	Β	ΒFΙ
  		BGΙ
  	Β	ΒGΙ
  		BHΙ
  	B	ΒHΙ
  	Β	BIΙ
  	Β	ΒIΙ$  dB       G
 d    GB
 dΒ  G
 d GΒ
 dB G d GB dΒ      G   /      module    luci.model.product    package    seeall    require    luci.tools.debug 	   luci.sys    luci.model.subprocess 
   partition    product-info    cache    /tmp/productinfo    soft-version    /tmp/softversion    default-mac    /tmp/default-mac 
   device-id    /tmp/getfirm-device-id    DEV_ID    fs_info    pattern    dev_id:(%w+)$    MODEL    product_name:(%S+)$    HW_ID    hw_id:(%S+)$    OEM_ID    oem_id:(%S+)$    SOFTVERSION    soft_ver:(.*)$    HARDVERSION    product_ver:(.*)$    FW_ID    fw_id:(.*)$    MAC 
   MAC:(.*)$    DEVICE_TYPE    product_type:(%S+)$    HW_VER    hw_ver:(.*)$ 	   get_firm    get_all    get_mac    search_device_id    search_device_mac    get_eth_port_num    set_productinfo        R   `     	(      @F @ Z    F@@ Z@   C    ^ Eΐ  F Α  @ Α@ \Α ΐΐ Κ  AA @ Α B@ β@ WΐB Γ  ή Εΐ  Ζ Α@ AA ά@ ^          cache 
   partition    invalid parameter    io    open    r     call    nvrammanager    -r    -p 	       read flash failed                     b       2   @   C     ^ D   F  Z   @@ΐ     ΐ @     Αΐ     Ζ@ΐ ΐ @    @ KA\ EB FΑ Ζΐ \     @ aA   ύKΑA\A A   C ^   	      name is nil    fs_info    pattern    not support this info    lines    string    match    close    match failed                                
   E      \ ΐ A  ΐ  	a  @ώ          pairs 	   get_firm                                    A@   K@ Αΐ   \ K@Α ]  ^        	   get_firm    MAC    gsub    -        upper                              	   @  @ C  ^  E   @  \ ΐ  Γ Α@ ΑA $        Aή          require    luci.model.uci    cursor    foreach    bind_device_list    device                  F@@ Kΐ Αΐ   \ K@Α \ G   E       @ FA H       	   bind_mac    mac    gsub    -        upper    .name                                 ’   ²     	   @  @ C  ^  E   @  \ ΐ  Γ Α@ ΑA $        Aή          require    luci.model.uci    cursor    foreach    bind_device_list    device        «   ―       F @     F@@ Z   ΐF@@ Kΐ Αΐ   \ K@Α \ H          .name    mac    gsub    -        upper                                 ΄   Ώ            A@   F@ ΐ  \   Λ@Α A Α δ     ά@          require    luci.model.uci    cursor    /etc/profile.d 	      foreach    profile    DEVINFO        Ή   ½       F @ Z   ΐ E@   @ \ H           eth_port_num 	   tonumber                                 Α   Σ    7   D   F ΐ Z   @@ΐ     ΐ @     Αΐ     Α    Ε@ ΖΑΑ A άA AAA  KΑΒΑ \A CΐΒ @ BAΒ D UΑ BD BB D@B B D@ B  ΒDA B         HW_VER    fs_info    pattern    not support this info 	   get_firm    io    open    /tmp/productinfo    a+    /tmp/productinfo-tmp    w    read    *a    string    gsub    hw_ver:    value    write    close    call 5   nvrammanager -w /tmp/productinfo-tmp -p product-info                             