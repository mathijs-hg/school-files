LuaQ               1Ό      A@    ΐ@@  A@  E   \   Αΐ  Ε   ά  AA  E  \  ΑΑ  Ε  ά  AB  E  \  ΑΒ  DΕ C ά  FΓΔΕ ΑC  AΔ  ΑD  AΕ  Κ F A Ζ Α βE 
 
AF  ΑΖ 	 AG	 	 ΑΗ	 
 AH
 
 ΑΘ
 	 AI  ΑΙ 
 AJ  ΑΚ  AK  ΑΛ  "F d     €F       Γ$          dΗ  €                                  δG       	    	   
          
        ΗG δ    	    Η δΗ      	  	   
          
             ΗΗ δ    $H d       €Θ                δ                       $I      	 $       	    dΙ                   GI d	 G   ?      module !   luci.controller.admin.op_manager    package    seeall    require    luci.model.controller    luci.tools.debug 	   luci.sys    nixio 
   luci.json    ubus    luci.model.sync    luci.model.uci    luci.sys.config    luci.model.subprocess    luci.model.locker    Locker    luci.tools.status 	 <     fs    new_cursor    /var/run/lookup_op    /tmp/getfirm-device-id    /tmp/uci_comp_config *   /tmp/uci_comp_config/uci_show_info_before )   /tmp/uci_comp_config/uci_show_info_after (   /tmp/uci_comp_config/uci_show_info_diff    /etc/config/    dev_id:    read    get    list    getlist    0xc401    0xc402    0xc404    0xc405    0xc406    0xc407    0xc40b    0xc40c    0xc40d    0xc40e    0xc40f    0xc710    0x4040    0x4044    0x4048    0x4049    0x4050    0x4060    0x4070    0x4079    0x4096    0x4080    0x40e0    0xc701    inspect_subconfig    fetch_subconfig    inspect_and_save_subconfig    forward_tmp_request    dispose_opcode    index        F   _     5       @ @  @   @ ΐ  D   K Α Α@ A A \   Αΐ  AΑ ΰΖ ΛΒά Β J  W@Bΐ ΐ  W@W@ W@W@ ΕΓ ΖΔ @άC‘   ό@ίΐψΔ   Λ ΐAA ά@          set_confdir    /etc/profile.d    get_all    opcode-cfg    get    opcode    op 	      lower     pairs    .type    .anonymous    .name    .index    table    insert    /etc/config                     a   ~          Δ    ΐ   @ Β ή ‘  @ώ   Δ   ΐ @ @ Β ή ‘  @ώ             ipairs                             	2         @           @@Δ       @  ΐ  Κ  AA  Α Β β@@    @@Δ        B A @  B @ ΐ  Cΐ  Α ACD  CΐC                 io    open    r    call    nvrammanager    -r    -p 
   device-id    read    *all    close    string    sub    len 	      trim                                 @ @ B  ^  B   ^          0x40e0                           Ν     J    ΑA    D    \ Z   @  ^@EΒ   \ BΑ ΖΑάΒ ΐΑ@  ΐ E  \ H D FCΒ\  ΐ Δ ΐ	B@ΓBΑ C  CCΑ C  CCΑΓ C  CB @  ΐ Δ ΐΓBΑ C  ΐ ΓBΑC C  ΐ E  \@ΔD	 I a  ΐύ E @  ^J    ICΕΕΓ   ά ΓCΕΔ ά ΓCΕCΕΓ CΕCG @G@Κ  DH D FΘ\ βC  ΠΓΗ Ε	 ΖCΙ A	 άΗΓ ΕΓ Ϊ  ΕΓ ΛΓΙDFΚ\ άC  ΕΓ ΛCΚάC @ΔΖΓΒ
 E Δ
 άC ΐ   ήΔ ΖCΓ
A D ΕΔ  ά  E "Dά W ΐΔBAΔ D LE D   @ LE D @Κ  ΙΓΙCΗΙC L KDCΑΔ  @\DKDJ\D ΐ   ή  5   	    	Η     error_code    require    luci.model.mode    upgrade_type_get    is_mem_protect_support 	   tonumber    get_memfree    mobile_mount    print ?   ===memfree less than 15M 1 time, drop cache and try again ====    call "   echo 3 > /proc/sys/vm/drop_caches    sleep 1 .   ===memfree less than 15M 2 times, return ==== %   ===memfree less than 15M, return====    ipairs    get_all     params    change 	   tostring    dev_id    opcode    config_version    data 	   get_role    AP 
   data_file +   /tmp/transmit_subconfig_request-%d-%d.json    os    time    getpid    fp    io    open    w    write    encode    close    open  	    failed!    tmpcli    -o    -I    tmpcli exec failed!     unlink    target_type    connect    sync    send                       U   Β   A    ΓW@@ @ @ΐ    C@     @@@ ΑΑ    ΐ   @    A@     AB BA  Δ ΖΒΑά   DB UKΑΐ   ΓA \   ΑB ΒA   D FΓΑ\   Α  ΥC B@C Γ @  ΐD @ ΥBC B@C  A ΐ  ΐ Γ D@ C ΐ  Ϊ@  ΐDAΓ  UC  E@ C  E@C  E@ C CE@C   ΕΓ   F
   
 ΓF@    @ ΓF@  E FCΗ Ε ΖΗ ά ΜΓ G@  \  Z  @ΓGΐ   ΐA Κ  βC ΠΓC @ @@ΐςCΘC  E@ C  E@C  E@ C CE@C   F W@ΐ@D  Ζ  @\CB  ^   "   	        lower    0    -%s-%d    format    getpid    md5sum /etc/config/* >     os    execute    diff           >     rm -rf %s %s %s &    io    open    r    print (   inspect_subconfig failed to open file:     unlink 
   fork_call    read    *line 	   	      string    find    ^[+-]    sub    len    is_user_config    user config(%s) change!    close                     W  ^          A   @  @@   @    Aΐ    U   @Aΐ  @  ΐ   Uΐ   @Aΐ  @ ΐ           -%d    format    getpid 
   mkdir -p     os    execute    md5sum /etc/config/* >  	                        `  ‘   ·   Β     C   @ @  ΐ   A@ @  Α  ΑΑ@ Δ   ΥΛΑΐ@άA  BΒ@A UB AΐB Β ΐ  @C ΐ UΒB AΐB  Β@  @ @ Β Cΐ C @  Z@   CΑΒ   ΥB Dΐ B DΐB Dΐ B  BDΐB   Δ Γ   E 
    
 ΒEΐ    @ ΒEΐ Ε ΖBΖ  E FΖ\ LC Fΐ  ά  Ϊ  @ ΓF@   ΐΒ   J bC PCC @ @GΐςΗ B Dΐ B DΐB Dΐ B  BDΐB ΐΗ  CΑ B  BHΑ B Δ ΖΒΘ ΛIάB Δ ΖBΙάB ΛGάB ΔΖΙάB Δ ΖΒΙάB   (   	       getpid    -%d    format    md5sum /etc/config/* >     os    execute    diff           >     rm -rf %s %s %s &    io    open    r    print (   inspect_subconfig failed to open file:     unlink 
   fork_call    read    *line 	   	      string    find    ^[+-]    sub    len    is_user_config    user config(%s) change!     close #   inspect user_config change, saving    save_config_version    0    CONFIG_LOCK    lock    reload_user_config 
   uci_apply    sync_boost_uloop                     £  °    	      A@     @  ΐ $       A  @        accountmgnt    cloud_account    foreach        ͺ  ­      F @ H   F@@ H       	   username    shadow                                 ²  Ί       A      U @  @ΐ  Α  @  @ Γ ή  Λ AAA άΛΑά ή          /tmp/sync-server/mesh_ip_    io    open    r    read    *all    trim                     Ό  Υ   0   @  @ C  ^  D      \ Z   ΐ      ^  @  Ε  Ζΐΐ  A άΪ@  @   AΑ KΑΑ\A E  ABΐ  \ @ ΐ  Ε    ά ΐ@ ΒΒ a  ΐό     	      /tmp/sync-server/mesh_dev_list    io    open    r    read    *all    close    pairs    decode 	   tostring    ip                     Ψ  B   Μ   Α   A  J    Γ   @  Β@@  B    
  W A ΐ W A@  Α  A   ^@B UKΑΐ   ΓA E  CBΑ  \  \  Β ΐ ΐ@@@   ΐ ΐ  @ A‘  @ύBC Κ  Ι ΙΙBCD A
  J  	CFCDIΙ  ΙΓ E@C ΐ Ϊ   Ε  ΓEΖΔ C  ΖC  IΖ  ΓFA C   @CG ΑΓ  KF\C A KΑΐ\CHΐC  HΐC    ΓHC   ΓFΑ	 C IΖ  ΓH@ΐ ΓFΑC	   ΔE@  ΥC  @ @ΓH
  ΖΓHΖ Τ ΜΖD  DC   Α   ήΕΓ   ά EF
W@
D FΕΖ
	 ΐ  Ζ	 D  FΖΕ\ E\E A ^@   Fα   ϊΐ ΓFΑ
    ΥC  HΑC
 C IΖ  ΐ  *   %   /tmp/sync-server/forward_tmp_request     	       decode  
   -%s-%d-%s    format    getpid 	   tostring 	   uniqueid 	      ipairs    ,    connect    opcode 
   target_id    load    params    data    io    open    w    write    encode    close    error_code 	      print !   forward_tmp_request write failed    call    sync    request    rm -rf %s &    unlink 
   fork_call    success -   forward_tmp_request sync request inner error )   forward_tmp_request sync request error:  )   forward_tmp_request one RE result error:    ,  )   forward_tmp_request sync request timeout +   ubus call sync detect_re >/dev/null 2>&1 &                     D    	    Α   A  J      @Δ  Ζΐ  ά ΪA    Κ  Wΐ@ ΐ Wΐΐ@ ΐΐ   @ AB BA  Δ ΖΒΑά  D FCΒ \     EΒ  \@  @ a  ΐώD \ ZB  @ ΐ    @    Β 
  FΓΐΐJ    IΓΓ	C  	ΓC ΓCΐ      CD  DFDC C  ΓDC  IAEAC  EΑΓ C ΐFΚ D A Δ ΐ   @E ΐ  @Ζ ΐ βC  Α ΛΑ@ ά DH@ D  H@D   @@     FEZD  D FΕΔ \D IAEAC @ A @ @^  $   %   /tmp/sync-server/forward_tmp_request        decode  	    
   -%s-%d-%s    format    getpid 	   tostring 	   uniqueid 	      ipairs    params    data    io    open    w    write    encode    close    error_code 	      print !   forward_tmp_request write failed    call_output    tmpcli    -s    -o    -u    -U    -P    -I    rm -rf %s &    unlink 
   fork_call -   forward_tmp_request sync request inner error                             Ε     ά @ΐ Τ  ΐ @Δ      @  έ  ή   Δ     @  έ  ή           type    table 	                         ©   (   W @ @  ΐ @ @       ΐ     @@ @      Αΐ  ΐ  A   D FAΑ\   Α Υ Α B@A A @ Υ@Α B@A A     
    	       -%s-%d    format    getpid 
   mkdir -p     os    execute    md5sum /etc/config/* >                      γ  S   «   Α   A  ΑA  
  C@  B  ΓW@@Β  Aΐ C W@ B  Γ  ΐ      B  Γ ΐ    B A WΐA ΑB   ήΔΖΒ ά ΪB   ΑB   ήΔΖΒ ά Ϊ  ΕB ΖΒ AΓ ά ΛCAC ά@ΛCάB ΕΒ  ΖΑ @  άΐ C  CΓ  ΓC@EΓ  FΑ Α \ΐΐ AC   ^EΓ  FΓΓ ΑC  \  ΓD ΔΖΕ  ά @ΖΪ  Δ ά ΐ D  CED  \ΐ@@ ADΐ  ED	BΜAΔa  @ύΑC   ή ΑB   ή@@ΐΐ ΑB   ή@ΐΐ ΑB   ή@@ ΐ Α   ήΑB   ή        /tmp/mix_network_status 	        string    find    TDP 	   get_role    AP    access    io    open    r    read    *all    close    sub    ] 	      {"%s}    format    decode    ipairs 	                       U  V                                          