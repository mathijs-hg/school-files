LuaQ               6     A@    À@@  A@  E   \   ÁÀ  Å   Ü  AA  E  \  ÁÁ  Å  Ü  AB  E  \  ÁÂ  Å  Ü  AC  E  \  ÁÃ  ÆEÜ D A Ä Á E d    G dE  ¤  äÅ    
         $   dF   ¤            	     äÆ    ÇÆ ä        
                 $G                   
              d ¤Ç ä            	$H     d     ¤È     ä      $I                d    ¤É    ä	                   $J d                           
¤Ê                              
   ä
                    $K    d          ¤Ë    ä   Ç äK   ÇK ä               Ç äË   $           dL                                    ÊL  
M  	ÉÌÊL  
M  	ÍÉÌÊ  
M  	ÍÉ
M  	MÉÌÊ 
M  	É
M  	ÍÉ
M  	É
M  EÍ 	MÉÌÊ  
M  	MÉ
M  	ÉÌÊL  
M  	ÉÌÊ  
M  	ÍÉ
M  	ÉÌÊ  
M  	MÉ
M  	MÉÌä    Ç   1      module -   luci.controller.admin.mobile_app.quick_setup    package    seeall    require    ubus    nixio    luci.model.uci 	   luci.sys 
   luci.json    luci.tools.debug    luci.model.sync    luci.model.tipc_config    luci.model.tmp_decrypt    luci.model.accountmgnt    luci.model.getfirm    luci.model.mode    luci.model.app_sysmode %   luci.controller.admin.mobile_app.nat    luci.model.wireless_common    cursor    /tmp/wifi_scan_result_2g    /tmp/wifi_scan_result_5g    /tmp/wifi_scan_result_5g_2    HOMEWIFISYSTEM 	È      _print_tbl    preconf_check    has_all_device_binded    pre_config_kick_mac    pre_config_add_re 	   newgroup    write    cb 
   newdevice    batchdevices    read    preconf    preconf_read    preconf_write    preconf_add 
   heartbeat    sync    eponymous_detect 
   bluetooth    dcmp_pre_config    pre_config_write    save_pre_config 	   dispatch #       &   /       E      \ @À E     \    Á@À  EB  \ ÕAA   Æ  @@  Æ A a   û        type    table    pairs    print     =  	   tostring    _print_tbl                     1   5        @       B      ^         invalid args                     7   =        A   @@ U   À   À@À           "   luci.controller.admin.mobile_app.    module    require 	   dispatch                     ?   c    {       F @ Z@   D   ]  ^   D  F@À   \@ F @ FÀÀ  Á À  @A  A Á  ÁÁ @   Â À  @A  A Á  ÁA @  ÁÀ  Æ CÜ  Á Æ@CÜ  Â Å  Ü  DFÁÃ \ KAÄ\ Ä    AAÂ A  ÆBEA  EÂ A AAÂ AÂ  ÀA A Å  ÂFA  Ü  ÁÄ B @ À ÂÜA Ä ËAÁAÂ Â ÁÂ   ÜA Ä ËAÁAÂ Â Á ÃCAC  CD ÜA  Ä ËÅAÂ ÜA           E        "   
   bluetooth    print    recv bt_mode_set    enable    set 	   settings    on     off    require    luci.model.mode    is_iot_support    is_iot_wifionly    luci.model.iot_ble    getfirm_cached    DEV_ID    trim    create_mesh_network    ble_network    key    nwkey    commit    zigbee_network_sync    co_device_id    0x 	   tostring 	   uniqueid 	      Create coordinator:  
   , panID:     panID    model    MODEL                     e   r        
   D   K À Á@    AÁ  \   	 Á  @@ @Á@ @@ Á          get 
   bluetooth 	   settings    enable    on                      t   z       D   F À @  \@ D   FÀ À  \@    @ W A À D   FÀ @ \@         exec    echo 1 >> /tmp/binding_over  
   fork_call     /etc/init.d/cloud_brd restart &    RE    /usr/sbin/handheld_radar &                     |   Ì       E   @  \ @    @ÆÀ@Ú    ÆÀ@ Á Á@  Þ Ä   ÆÀÁÆ ÂÁ@Ü Ú@   A AA   J  Á  Ä ÁÄ ÁÄÁÅA   ÜÀ ÃCF    KCDÁ \  ËÃDÜC Ä ÆÅ @ÜÆCEÅ@ÆÃEW Æ AEÆÃEIÁá  @øÅ  B Ü Æ J    ÁB  ÆÂF Ü ÃFAC  FÃF \  EÀ ÆÃFÄ Ü ÄËÈAD  ä              ÜC  ÀZ  @Ä ÆÃÈ @Ü Å@ ÀÄ ÆÉ @ÜÅ   Ê  
D  	   &      require    luci.model.subprocess    user_network    ssid     	ïØÿÿ   invaild user network    bin 
   b64decode    invaild user network ssid    band2_4    band5_1    band5_2    pairs    io    open    r    read    *a    close    ssid_exist    exist    channel 	       luci.model.mode    is_band_6g_support    get_radio_device_name 	   radio_2g 	   radio_5g    radio_5g_2 	   radio_6g    foreach 	   wireless    wifi-iface    scan_special_ssid    scan_user_ssid    eponymous_network_exist        «   ·    &   F @ @À @F@ ÀÀ F A     À D  A IF A    À D  A IF A   À D  A I F A     D  A I  
      mode    ap 	   disabled    0    device    band2_4    .name    band5_1    band5_2    band6                                 Î   Ù          @F @ Z    F@@ Z@   B     ^ D   FÀÀ @@ \  Á  B   @ ^ D   FÁ  @ ]  ^           key    gid    invalid input    __check_group_gid_valid     gid check failed    __check_group_key_valid                     Û     	    D     @@À     \@ @  À D    ]  ^   FÀ@ Z   @ Á      Á @A  ÁÀ    B    @Æ@BÚ    ÆBÚ@   Á Á Þ Ä  Æ ÃA Ü ËÃÜ ÁCFÁ  C I ÁCFÄ  C I 
  J  	AFAD  IFADIAFADBIFADABID KAÅÁ Â A \ZA    AA ADÄÆÁÆÆÇ Ü ÁADÁ	ÁG	AH	ÁH À  	 	   À 	 AIWI   Ä ÆAÀ	 Ü ÐÁA 
 Å	 Ú  À Å	 ÆAÊÚA    Á
 Á
 Á  AK ËKÜ ÂK D   B@À  \B JB BIBBIIÂIÂI^   3      isp_onboarding:%s    encode    params not found    cloud_account 	   username     	üÿÿ   invalid cloud_account args    read_group_info    key    gid    group-info invaild    getfirm_cached    DEV_ID    trim    tmp_handle_string 	   password    params 	   nickname 	   group_id 
   group_key    get    wifi    ap    ssid    TP-LINK    group_name    bin 
   b64encode    master_device_id    module    cloud    form    group 
   operation    create    res    error_code 	       res:%s 	
üÿÿ   msg    set cloud account failed    require    luci.model.app_wifi    Wifi    get_backhaul_channel    get_preconf_pack    pack is %s 	   backhaul    suit_count                          /     Á@   Æ@Ü Ú@   ÁÀ   Þ @   Á@  Þ ÆÀA B FAB   ÁA   Z   ÆÂÚ  @ÆÁÂÚ   ÆÂ ÃÀÆACÜ Ú   Ä     Ý Þ   Á Â ÞÆD Ú  @BÄ   BÄ C  AÂ  EFBÄ BE É EFÂÂ BE ÉE   @FÂEZ   FFZB   AB  ^D FÂÆ \ KBÅ\ BG   ÆGÚ  À Ä Ã FGÜBÄÆÈÜ Ú   Ç  @CÈ   @   @ ÃHA	 C À CI  IC Ú   À)
  J  	CFÃIIÃ	CJ	ÃJ	CKD \ @ Z    FË WÀËDFÌ\C AC Z    Ì C    Ã ^FÍZ  J  ÍCMI Å   Ü DÍWÀMÀÍN  À ÍN@N@IÃÍIÃNIÃNIÃKIÏ@DÍO ÍNIÍNIÍOIÍDOI@ ÄHAÄ D LD     ÍPO	IO ÍDPI ÍPI¡ÍÄPI¡ÍQI¢ÍDQI¢DÑ   DÑQ   Ä FDÑFÑÀFR
Z  À FR
T
ÀË
  	E¤!  @ý  IÃM DÒ@  WO@LD     FÒZ  @J  ÒCMOÀIÏÒÃRI¥ÒSI¦  IÃÍ  Á  ÆCS Ü ÀÍÀ ÄHA D ÃS WÀN ÃS  T  ÃHAC C 
  	ÃT©	OªE   \   Ê  ÃÆÃIÉCJÃJCKÄ  Ü @ Z    ÆË WÀËÄÆÌÜC ÁC Z    Ì D    Ä ÞÊ  ÉÃÍ ÉÃNÉÃNÉÃKÉÏÉÃM FDÒ\  WO@DFÌ\D D ] ^  J  IÄÍDÓÀ ÀM	À Ä ÆÄÈ	 ÜD CU    
U   @	  AÃ  FU FÖZ  FU FCÖZ  FU FCÖÖFÃVU \  À W@W  ÁÃ D FÃÈ \C FXU \ @Ø  ÁÃ 
  	ØDFÃØFÙÂ\ 	CDFÃØFÙÃÂ\ 	CFBZ   FÃBZC  @DFÌ\C AC C ^E   \ FÃÙ\ Ú  CCÚDHCÚ C  @ÄÆÌÜC ÁÃ  ÞÊ  ÉÉC[É[ÉCK@ @  Z    Ë WÀKLD Ä Z    FÌ ZD    A 
  J  	DFÄIIFÄIIÄFÄIGI¸FÄIDHI¹Z  FÂZ  À FÄIÂI¹@DFÝ\ ÄIÆÂÄ¹FÄIIDº	]	Ä]	^D \ @ Z    FË WÀËDFÌ\D AD Z    Ì D     ^DFÄÞGÆDH \D J   ÄF	ÁD  DE	 I¦I_¿BV	À ÆÄ_Ú    Ä_IÅD    Å`
 Ü  IÄÀÄÆá	ÆDá	! Ü ÚD     ÆÄ`Ú  À ÅD  Å`Ü IÄÀÄÆÄÆ	" Ü IÄÃÄÆDâ	Ü Ú   W Ã	  IÄÅÅb
@E c
E# Á# F AÆ# E  Z
E# Ed O
 Ed ÀM
   A$  C
 ÅFÁ  EE ÆÅd
Ü @Ä ËãA% # ÁF Gå
ÜE Ä ËÚA% ÜEÄ ËãA% % ÁÆ%   ÜE Á& F  DFFæ& \   Õ AÆ&  Á'  UF  c% Á% G' @F  c% Á% ' D FÇÆ" \ KGÅ\ F   Z% F c
Å' Á( F AF( E h
AÅ( E  Z
Å' E i
E E L
E Eé DFé
\  ÅHÁÅ) F  @
 ÕE   ÆEUÜ Ú  @Ê  ÉÅNÔÆS   ÀÆS W@j@ÆS Wj ÆS  TÀ ÆS ÉÔ  ÉTÔêWÀN  Æj@F À
Å  + Ü ÆS  _@	 cF+ Á+ Ç+ Fl
FGìF  cF+ Á+ , A F  cF+ Á+ Ç, A F  ZF+ F  A-  FFm- \F J  I_ÔÆêÀF îÛÆGÅ¸ÆEHÅ¹EºÜEÝ   »      require    luci.model.mode    is_set_newgateway_support 	üÿÿ    Not support to create new group 	üÿÿ   params not found    wan 	   nickname 	   wireless    ssid 	   password        is_isp_onboarding 	üÿÿ   invalid wireless args    cloud_account 	   username 	üÿÿ   invalid cloud_account args    tmp_handle_string    trim 
   date_time 	   timezone 
   tz_region 	üÿÿ   invalid date_time args    getfirm_cached    DEV_ID    read_group_info    gid    Warning: overwriting group     read_preconf_group_info    key    preconf_check    print '   set master: use preconf_group as group    create_group    set_create_group_flag    params    module    network    form 	   wan_ipv4 
   operation    write    error_code 	       clear_create_group_flag 	üÿÿ   msg    set wan failed    vlan    enable    luci.model.app_network     id 	ÿÿÿÿ	   isp_name  	   priority    tag_802_1q    unknown vlan status.    iptv_enable 
   iptv_mode    iptv_isp_name    iptv_id    iptv_priority 
   iptv_port    ports    ipairs 
   device_id 	   set_vlan 
   mac_clone    clone_mode    mac    set_mac_clone    set wan mac_clone fail.    operation_mode    Router    make default wan config!!! 
   dial_type    dynamic_ip    enable_auto_dns    is_mobile_device    mobile_cpe 0   luci.controller.admin.mobile_app.network_mobile    profile_id    profile_type    custom    modify_profile    type    boolean 	ïØÿÿ   set internet info failed    set_active_profile 	      1    bin 
   b64decode    invalid args    luci.model.app_wifi    Wifi    set_ap    set_backhaul    commit 	üÿÿ   set wifi failed.    device    timesetting 	üÿÿ   set time failed 	   group_id 
   group_key    group_name    get_wireless_spec    master_device_id    cloud    group    create 	
üÿÿ   set cloud account failed    join_group    AP    MAC    role    custom_nickname 	   bindtime 	   tostring    os    time    fs    access    /tmp/run/ntpd.uptime    device_model    MODEL    get_pregroup_md5    preconf_id    add_bind_device    set 
   bluetooth 	   settings    off    is_iot_support    is_iot_wifionly    luci.model.iot_ble    create_mesh_network    ble_network    nwkey    zigbee_network_sync    co_device_id    0x 	   uniqueid 	      Create coordinator:  
   , panID:     panID    model    wifi    default    0    exec 3   echo "wifi.default.enable='1'" >> /var/state/wifi     set_tipc_config    get_backhaul_channel    get_preconf_pack 	   pack is     mode    LTE 
   Mobile_5G    set_sys_mode    luci.model.app_sysmode    system    ap_onboarding    channel_5G    band5_1    channel    onboarding_boot    need_set_wan    luci.sys.config    saveconfig    device-config    reboot_time 	Z   	   backhaul    suit_count                           	   E   @  \ À ÁÀ  @             require    luci.model.radar    send_transaction_to_other    update                           	   E   @  \ À ÁÀ  @             require    luci.model.radar    send_request_to_local    update                       Õ   X   J      Á@   Æ@Ü Á  Ú      D  FAÁ\ ÁÂ A   Ä ËAÂA ÜÂÂB $    D FÃ\B J  B À À
ÆC
  WÀÃ  	FDKDÄÁ Å \ KÅ\  À     @	D	D	ÄE	F	DF  @ 	ÄF  	G  ÆDGÚ   ÆDGÄ	ÔÌÄÇ	I	  Àô¡  @ôI IÈB    I^    $      require    luci.model.app_cloudfirm    get_online_status    offline    online    connect    call    sync    list    get_all    bind_device_list    close    sync_boost    pairs    role    UNBIND    mac    gsub    :    -    upper 
   device_id    device_type    device_model    signal_level    iptv_extend    enable_iptv_port     nickname_category    extra_info 	      inet_status    max_discover_time 	F      device_list        ¡  «      D   Z@  @ B   ^  E      \  AÀ  @   a   þB   ^          pairs    mac                                 ×  ç          A@   A    ÁÀ  À Æ A   Ü Ú@  À Æ@A   B Ü@Ê    â@ ÐÀ   ÁA@A  BAA A     
      require    luci.fs    /tmp/quick_setup/    add_device_done    isdirectory    mkdir 
   touch %s     call    print    set_add_device_flag                     é  ÷      @      A     À   À Ê    â@ ÐÀ  @@A  Á@A A        
   /var/run/ 
   touch %s     call    print    set_pre_add_flag                     ù        @      A     À   À Ê    â@ ÐÀ  @@A  Á@A A        
   /var/run/    rm %s     call    print    del_pre_add_flag                             @      D   F À @  \@ A    À   À Ä  ÆÀÀÆ Á  Ü Ú   @ Â  Þ  Â   Þ          print    check_pre_add_flag 
   /var/run/    fs    access                       U          @Á@  @   ÆÀ ÁÀ    FÁ AÁ A  Ä  ÆÀ ÜA Ä ÆÂÂÁÜ ËAÂÜ IÁÄ ÆÂÂÜ ËAÂÜ IÁÀ Ä  ÆÀÂ ÜA Ê  
  ÉÃ	Â Ã	BÃFBÃ 	BÃFÃ 	BÃFD	BÃFBÄ 	BÉÁDÉAEÉÁE @       FW@F 
     FÂFZB    A ÀFÀ  @ÁA A ÇÀ ÁÇ    FÁÇZ    @Á B @ ÕA HÂ A	 B	 ÀA IÂ ADKÈÁÁ	 
 AB
 
 \A DKÉÁÁ	 \AD \A DFÁÊ\A E A \ ÁË  LA      1      print    do_add_m5_device start 	   nickname    front_wireless    cloud_account    is_base     cloud is not valid, do transfer 	   username    tmp_handle_string    trim 	   password     cloud is valid, do not transfer    params 	   group_id 
   group_key    group_name    ssid    master_device_id    module    cloud    form    group 
   operation    add    error_code 	    	
üÿÿ   msg    set cloud account failed $   not bind cloud, but modify location    custom    custom_nickname 	   location 	   tostring    set    cloud_config    info    alias    commit 
   bluetooth 	   settings    enable    off    sync_boost    require    luci.model.mode    is_emmc_support    sync_boost_emmc                     W  Y      D     À   ] ^                             [  ]      D      À   ] ^                             _  »   Ó   E   @  \   Ä   ÆÀÁ  Ü@ @   Á  A Þ ÆA Ú   @ÆÀA Ú    ÆA  Â Á@  Þ ÆÀB Ú    ÆÀB  Â Á  A Þ ÆC ÀÃ Æ D Ú    Æ D  Â Á  A Þ Ä  ÆÄA FÁA Á Ü@ Ä  Ë ÅAÁ A Á D Ü@ Ä  ËÅAÁ Ü@Ä  ÆÀÅÜ@ Å    Ü AÆ FFÀÆÀ G    FGA  Ä ÆÇÂ Ü ËÈÜ ÁÄ ÆÇ Ü ËÈÜ ÁÄ ÆÇ	 Ü ÁÁÄÆÁÉ Ü ÁA ÆF J    FAJZ  @FJZ   FAJ Â AÁ
  ^FAK Z  @Ë   Ë B Á Á  AL   ÆLÚ  À Ä  Â FLÜAÄ ÆÄA FÂA Â ÜA ÄÆÍÜ @Í @  B  ÂMA B ÆÀFÀ FÇZ    ÇD\B D  FÀB \B D FÎ\  Â  CÂ Ä ÆÇÃ Ü ËÈÜ ÂÄ ÆÇ Ü ËÈÜ ÂÄ ÆÇ	 Ü ÂÂÄÆÂÉ Ü ÂB   <      require    luci.model.mode    print    add_m5_device start 	üÿÿ   params not found 	   group_id 
   group_key     	üÿÿ   invalid group args    master_device_id 	üÿÿ   invalid master_device_id 
   generator    sync    sync_version    invalid sync_version    join_group    RE    set    config    commit    sync_boost    luci.model.app_cloudfirm    get_nickname 	   nickname    custom    custom_nickname    slave_device_id    getfirm_cached    DEV_ID    trim    mac    MAC    device_model    MODEL    role    product_level    get_product_level    front_wireless    ssid 	   password 	üÿÿ   invalid front_wireless args    cloud_account 	   username 	üÿÿ   invalid cloud_account args    read_group_info    gid    Warning: overwriting group     fork 	       os    exit 	      add_m5_device: end    get_pregroup_md5    preconf_id                     ½  Ä       A   @  @À  Á      Ë A@  Ü@Ë@AÜ@         /tmp/re_product_level    io    open    w    write    close                     Æ    	 ,e  D   F À @  \@ D  FÀ À  \ K Á \   @A Ä  ÆÁÜ 
  AÁ Â C B Ú    BÂB    ÁÂ  ÆC CC Ã@D FÃÃ\ B  @A  ^@FCD ZC  @   @FDZ   FDÀÄ A C ^DKÅÁÃ  \   Ä ÆÆÆÃÆDÆÜ ÃÄ ÆÆÆÃÆÇÜ ÃÄ ÆCÇÜC ÄÆÇÜ ÄÇ Á 
  DKÅÁD \¤    äD     
  J  H ÅÅ 	 Ü FÉ 	ÅIE
  \@7Ê  HJÉJÉ  	FÊ H   3
  	È		H FHÂ	HFÈË	HFL	H	@	HJ\ Ì   ÀL  	HCHCÈÌÀ  @  	 MÆD A   MÆG A À HCHCÈÂ   	  @HJ  @HJHM  À HJFBM  AÂ   @Á H   Å I Ü ÈÆHJÈÊ  ÉÈ	  	@AI 	OÀ	  UI ÉÇ ÁÉ  
 	   F	PZI  @D	  F	ÀI \I ÉÇL¡F	PÀÁ@D	  F	ÀÉ \I ÉÇL¡@D	  F	À	 Ä	ÆÏ 
 Ü É	\I F	OZI  @ ÉÇL¡ÀÐWÀA@Ä	  Æ	ÀJ ÜI ÉÇL¡Ê	  ÑÊQJ    
  
 D
  F
À
 \J 	ERFÑFÊÉI
FÑFÒÉI
¥FÑF
ÌÉI
FÑFÊÒÉI¥EJ  ÊS
 \  ÉI
¦ÉIFÑF
ÔZ
  FÑF
ÔWÀÄ FÑF
ÔÉI
¨WÃ@D
 FJÔÑTÀ
\JD
 FÊÔ\J À FÑFÔ	ÁLÁÌFÑFÊÉG
ÉÇA¡ ÊÉÉÇA¡
ÈLIÅa  ÀÇKÕ\F @À D FFÕ \F 	ED FÕ\F D  FÀÆ ÄÆÏ  
Ü Æ\F    X      print    add_m5_device_list: start    getfirm_cached    DEV_ID    trim 	   get_role    read_group_info 	       AP    gid 	üÿÿ   invalid my role or invaild gid 
   generator    cloud_account    sync    get_sync_version    invalid sync version    from 	   username     	üÿÿ   invalid cloud_account args    get_all    wifi    ap    ssid    bin 
   b64encode 	   password    set_binding_flag    connect    call    list    bind_device_list    device_list    require    luci.model.mode    get_product_level    is_master_qualified    ipairs 
   device_id    mac    sync_version    master_device_id 	   group_id 
   group_key    key 	   nickname    front_wireless  	      tmp_handle_string    oui_version    AP: bind other M5    opcode 	   tonumber 	!@  
   target_id    params    data    args:     encode    request    success    sync request error    error_code    sync request error. 	   result:     request error.    result    product_level )   ====== is master qualified is false ====     role    device_model 	   bindtime 	   tostring    os    time    preconf_id    add_bind_device    slave_device_id    update_network_oui    close    add_local_device_list    clear_binding_flag    add_m5_device_list res:         í  ÷      D   Z@  @ B   ^  E      \  AÀ  @   a   þB   ^          pairs    mac                     ù        D   Z@  @ C  ^  E      \ À   @ AÀ a  @þC  ^          pairs    qs_version                                      -  D   F À @  \@ D  FÀ À  \ K Á \   @A Ä  ÆÁÜ 
  AÁ  B Ú    AÂA    ÁÁ C   @ÆACÚ   ÆACÃ Ê  ÀÄ ÆÁÃÆÄBCÜ ÁÄ ÆÁÃÆÄBDÜ ÁÄËÄAÂ  Ü 
  D FÂÃFÄBÅ\ 	BD FÂÃFÄBÄ\ 	BD FÅ\B D FÂÅ\ ÆC A   ÄËÄAÃ Ü$    FG C Á  ÆÃGÜ H J  DÈIÈI ÆÈ D  @#  @ÅD    @     ÅD D   DÆDÂÄÆÉÄÆÄÉÄJ  JÄ  ÆÀ	Å
 ÜD Ê  E A  ÉEÈÉ
  	ÉD  FÀ
 ÄÆÅÌ 	Ü Å\E KÆÁE  @	\Z   EÍ
E  @  @Á E IÎ@EÍ
ÀA@  @ÁE E IÎ   @Á ÆL@
 ÕE EÌ
E  @ IÎÆÅMWÀÁ   @AÆ F 
  FOFFÏZF    D @@  @Á F Æ FP OH	OP	¡OÆI	OÆP	¡F Å ÆÆÑÜ   	¢OR  ORWC OR	¤OFR	LÎÒD    ÅD D @À  ÄR	À D  S	D J@ DS	 ÀA	 ÅD  Ü ÅÓ	E Ô	E EÔ	E  T
AÅ E @ÀD ÁÄ  U	 ËDU	B  ÈÜ   @      V      print    preconf_add_m5_device: start    getfirm_cached    DEV_ID    trim 	   get_role    read_group_info 	       AP    gid 	üÿÿ   invalid my role or invaild gid    get_device_account_temporary 	   username        bin 
   b64encode 	   password    get_all    wifi    ap    ssid    set_binding_flag    connect    call    sync    list    bind_device_list    device    require    luci.model.mode    get_product_level    is_pre_config 
   device_id    mac    master_device_id 	   group_id 
   group_key    key 	   nickname    front_wireless    cloud_account    AP: bind other M5    opcode 	   tonumber 	fÄ  
   target_id    params    data    args:     encode    request    success    sync request error    error_code 	      sync request error. 	   result:     request error.    result    product_level )   ====== is master qualified is false ====    res    is_master_qualified     role    device_model 	   bindtime 	   tostring    os    time    preconf_id    slave_device_id    close    add_local_device_list    clear_binding_flag    fork    cloud.tp_apps.dcmp    check_bind_event    check_upgrade_event    check_internet_event    exit    luci.model.message_center 
   Msgcenter    add_auto_pair        £  ­      D   Z@  @ B   ^  E      \  AÀ  @   a   þB   ^          pairs    mac                                   d      E   @  \   Â    @AÁ  A @    AA A   @ÁA    A  B A A ÁB    ÁB  B  AA C FÁC Z   Ä  @AÄ   Ä B  ÁÁ E   @ÆAEÚ   ÆAE Â Ä  ÆÀ ÜA Â   Ä ÆÁÅÜ Ú  Æ  À   AB ÆB FFA ÂA ÁÂ B  G @G@E FÂÇ \B Ú    	ÈD  \B  D   \B E FÂÈ	 \B FC@ÉÀ I    FIB   @ÁÂ	 B  J  B   ÊÂ  JAÃ
  K É JA  K É JA  ÉÉÂÆÃÌ  ÉÉÉBÞ   5      require    luci.model.mode    print    preconf_write_m5_devicestart 	üÿÿ   params not found 	   group_id 
   group_key     	üÿÿ   invalid group args    master_device_id 	üÿÿ   invalid master_device_id 	   nickname    front_wireless    ssid 	   password 	üÿÿ   invalid front_wireless args    cloud_account 	   username !   add device without cloud_account    read_group_info    gid    Warning: overwriting group     join_group    RE    fork 	       os    execute *   ubus call leds init '{"state":"binding"}'    is_base    exit 	      custom    custom_nickname    preconf_write_m5_device: end    get_pregroup_md5    slave_device_id    getfirm_cached    DEV_ID    trim    mac    MAC    device_model    MODEL    role    product_level    get_product_level    preconf_id                     g  z      D   F À \    @@ Ä   ÆÀÜ 
  Z     	A     	 Ú   À E \ 	A         get_preconf_gid    get_preconf_key    get_preconf_pack    gid    key    pack 	   tonumber                     |  ¼   v    @     F@@ @ Z   @ÆÀÀ Ú   Ä   Ë ÁAA  ÁÁ  ÂÀ Ü@ Z   @ÆÀÁ Ú   Ä   Ë ÁAA  Á ÂÁ Ü@ Z   ÀÆ@Â Ú    Ä  ÆÂ ÁB@   Ü@  Æ@Â Ã@C@ ÉC  ÉÀC  AA Á B @A    ÀÄ   Ë ÄAA A ä        Ü@Ä ÆÄÁ Ü Ë ÅÜ A A  EÁ  \   À BFÂC@ ÂFCÆBG
 A "C @ÜËÂÇA ÜÂÄ  ËÁAC C À  ÜB a   ùÄ   Ë@ÈAA ÜÈ Á DFÉ\A Þ    &       config    device_list 	   internet    section    preconfig_device_list    pre_config 	   wireless    wifi    sip_alg    print    encode    enable    1    0    foreach    device    exec    getfirm DEV_ID    trim    require    luci.model.subprocess    ipairs    role    AP 
   need_bind    RE    device_id_md5    call_output    md5sum    match    %x+    commit 	    !   /var/run/preconfig_finished_flag    call    echo 1 > %s          ¢      A   @  Ä     Æ@ @ AÀ  @ ¡   þ À     AA F@ @      	      ipairs    .name 	       delete    preconfig_device_list                                 ¾  Ñ   *   J      Ã A  A      ÀKÁ@ Á B \ KÁ\ ÁAÀB ÆBÚ  ÆABÚ  ÀÁ Â FB EÂ BB\ @D  FÃFAÃ \ À IÀCIÀ ^          Deco    require 
   luci.util    gsub    :    -    upper    split 	   	      Deco_ 	   tostring    bin 
   b64encode 	   nickname    custom    custom_nickname                     Ó  Þ         D   K À Á@    d         \@          foreach    preconfig_device_list    device        Ö  Û      D   K À Á@  @ AÁ  \ Á @              get    bind_device_list    .name 	   bindtime                                  à  ë   *      @ Z@         Á@   Æ@Á  Ü ÁA Á Â A     KÁÁA  AB \ZA    A Á À  @  B ÁÂ  A  Ä  ÆÃ  ÜA         require    luci.model.uci    cursor    /etc/profile.d    get 	   isp_info    pre_config 	   iface_2G    ath06 	   iface_5G    ath16    iwpriv  
    kickmac     ; 
   fork_call                     í     L   @   Z@         Ä     Ü  Ê   
  JÁ  I IAI É@É@A AÁÁ  B@ ÕA 	Â	Ã	Á	ÁCÀ  Ä ÆÁ EB  \ BÜA Ä ÆÁ D FÂ \ BÜA    ÆDÀÄÀÿÄ ÆÅÜ ÀÄ B A  FÂE\B FF\B FBF\B E FÂÆÂ \B       
   device_id    mac 	   nickname    device    is_pre_config    print    !!!!!!params =     encode    form    preconf 
   operation    preconf_add    params    module    quick_setup    add_prv result: 	   tostring    error_code 	       fork    require    cloud.tp_apps.dcmp    check_bind_event    check_upgrade_event    check_internet_event    os    exit                       .    '      A    A  A   FÁ@ \ Z  @E FAÁ Á \ @  À D  Á \A   KBÁA \À KB\A Ú   @EÁ \  Ã              /tmp/onboarding    require 	   nixio.fs    access    io    open    r )   open onboarding file with unexpect error    read    *line    close 	   tostring    1                     0  G   9   D   F À @  \@ @     D  FÀÀ   \@ J      I@Á   À Å  A Ü  A  FÁB À \AA   @ÁA  C@  ÕA ÁÀÊÂ A B Á   âA @ ÁDEÀ A @Å  B ^         print    !!!sys_mode_set begin     call 	   sleep 15    params    mode    /tmp/pre_config_mode    require    luci.model.subprocess    luci.model.app_clientmgmt    write_to_file 	ÿÿÿÿ   !!!!!!!!change_mode :    encode    tmpcli    -o    0x40a1    -I    fs    unlink 	                        I  ù   Ê  D   F À @  \@    @F@ ÀÀ  F A ÀÀ @ B   ^     @F@A Z    D     \@ D  FÁ \ Z    ÀÁ    @ÀÁ W B     @     @    @Á@ @       B @  @ Ã  ÁBA  AC ÁÁ  D  \ DÁA  D Ä ÆÁÄÜA    ÀÆEÚ   ÆE
  FBÅ	BFBEÅ J  	BFÂEÆIFÂEBÆI@FBEWÆ FBEÀÆÀJ  	BFÂEÆIFÂEBÆIFÂEÇI	ÇFÂÇÀÀ FÈWÀÀÀFÂÇT@È@FÈT@È@ 	ÂH 	IJ  	BFBIÂÇIFBIÈIJ    IÉIBJIÂJIBK À À  Ú    ËWÀK   @Á CL@ ÕB Å Â Ü ÆÍÜ     BM  @
  	ÂMD FBÎFÎBMN\ ZB  @ FBMFÎ	BD FBÎFÎBMBF\ ZB  @ FBMFBÆ	BFNZ  FBFZ  ÀKÂÎÀ \BD  FÀ ÄÆBÌ  Ü Â\B KBÏÆÏ \BKÂÏ\ ZB     @Á CL@ ÕB  BPFÂÁ Ï Á B    ÂP  À QFÂPB 
  DFÄ \ KÄ\ 	B¢	Ð£FÒ@ÒÀ Ò    FÒ	B¤ ÅB ÆÓÜ   	¥ ÂBÁ  	§ BTÀ   B  @Á B Z    @ÁÂ  @ ÕB  UC A Ã ÀB  ÂOC B U AC  Á B  ÂO B ÁÂ  ÆWÜ ÀÈ ÆBWÜ  É Å  Ü  DFÄC \ KÄ\ Ã×    U AD  ÆDXC  ÃO C U A Ä ÀC  Å DYA  Ü  ÃÄ  Ä @ À ÄÜC Ä ËÕA  ÁD   ÜC Ä ËÕA  Á D
AÅ  D
 ÜC  Ä ËÃÏA ÜCÄ ËÕA C Á  ÜB ÄÆÄÃ ÜB Ä ËÂÏA ÜBÄ ÆÜÜ ÀËÀC\C  C  \C ÃÜ D  FÀ \C F@ FCÝ ]Ä AÄ  C    C W@ÀÄ ÆÜÜ ÀË @D Ê ÄÁ É½Ï É½É¾É¾Þ   ~      print    dcmp_pre_config_set begin    config     device_list    dcmp_cause    read_group_info    gid     7   in onboarding status, do not bind isp preconfig device    create_group    getfirm_cached    MAC    gsub    -    :    exec    getfirm DEV_ID    trim    set_create_group_flag 	   internet 
   dial_type    pppoe 
   user_info 	   username 	   password    l2tp    pptp    vpn_server    secondary_connection    dynamic_ip    dns1    dns2 	      enable_auto_dns     ip_info    params    wan    module    network    form 	   wan_ipv4 
   operation    write    error_code 	       !!!dcmp_pre_config_set res:    encode    require    luci.model.app_wifi    Wifi 	   wireless    enable    1    ssid    bin 
   b64decode    set_ap    [PRE-CONFIG] group:    set_backhaul    key    commit *   !!!!!!dcmp_pre_config_set set wifi error:    join_group    AP    sip_alg    set_sip_alg_common    mac    getfirm MAC    role 	   nickname    custom    custom_nickname 	   bindtime 	   tostring    os    time    device_model    MODEL    add_bind_device $   not bind cloud, but modify location 	   location    set    cloud_config    info    alias 
   bluetooth 	   settings    off    luci.model.mode    is_iot_support    is_iot_wifionly    luci.model.iot_ble    create_mesh_network    ble_network    nwkey    zigbee_network_sync    co_device_id    0x 	   uniqueid 	      Create coordinator:  
   , panID:     panID    model    getfirm MODEL    wifi    default    0 3   echo "wifi.default.enable='1'" >> /var/state/wifi     fork    set_tipc_config    clear_create_group_flag    get_backhaul_channel    dcmp_pre_config_set end    operation_mode    get    sysmode    mode    Router 	   group_id 
   group_key    master_device_id 	   backhaul                       "   	   E   @  \ À Ä                  require    luci.model.controller    simple_dispatch                             