LuaQ                    A@   E     \    ÁÀ   Å    Ü   AA  E   \   Å   Ü ÁÅ   Ü ÁÅÁ  EB  ÅÂ  EC   Å Ä A D $     D $D     $    Ä $Ä     ÄADFD $        ÄÆÄ $D         $           D $Ä    $    Ä $D            $    D $Ä     $      Ä $D   	 
  D	 D	 d        	D$Ä                      ED	 ¤      IED	 ¤D      IED	 ¤      IED	 ¤Ä        IED	 ¤ IED	 ¤D    IED	 ¤      IED	 ¤Ä      IED	 ¤ IED	 ¤D          IED	 ¤             IED	 ¤Ä    IJ  GÄ EÄ ¤   IEÄ ¤D      IEÄ ¤   IEÄ ¤Ä   IEÄ DÎIJ  G E ÏIE ¤   IE ¤D   IE ¤    IJ  G E ¤Ä             I J  G E IÑ¡E ¤	    I¢E ¤D	    I£d	     äÄ	   Ä£ ä
   Ä¤ äD
   Ä¤ ä
   Ä¥ äÄ
   Ä¥¤            M      require    io    os    table    nixio 	   nixio.fs    luci.model.uci    util 
   luci.util    ip    luci.ip 	   tonumber    ipairs    pairs    pcall    type    next    setmetatable    select    module 	   luci.sys    call 
   fork_exec 
   fork_call    ltn12_popen    exec    mounts    getenv 	   hostname    httpget    loadavg    reboot    sysinfo    syslog    dmesg 	   uniqueid    uptime    net 	   arptable 
   mac_hints    ipv4_hints    ipv6_hints 
   conntrack    defaultroute    defaultroute6    devices    deviceinfo    ip4mac    routes    routes6 	   pingtest    process    info    list 	   setgroup    setuser    signal    kill    user    getuser    getpw 
   getpasswd    checkpasswd 
   setpasswd    wifi 
   getiwinfo    init    dir    /etc/init.d/    names    index    enabled    enable    disable    start    stop    _parse_mixed_record -       3   5       D   F À ¥   \  O@À ^          execute 	                       =   T    6   D   F À \ @À    @ÁÀ  @    @ÁÀ  @     AÁ@     ÀÄ   ÆÀÁ  D  FÂÜ@Ä   ÆÀÁ  D  FAÂÜ@Ä   ÆÀÁ  D  FÂÜ@ËÀBÜ À @ Ë@CÜ@ Ä   ÆÃÁ A ¥  Ý   Þ               fork 	       chdir    /    open 
   /dev/null    w+    dup    stderr    stdout    stdin    fileno 	      close    exec    /bin/sh    -c                     [   s    9   D   F À \ @À 	   @ÁÀ      ÀÄ   Æ@Á  D  FÁÜ@Ä   Æ@Á  D  FÁÁÜ@Ä   Æ@Á  D  FÂÜ@Ë@BÜ À @ ËÀBÜ@ Ä   Æ ÃA A ¥  Ý   Þ   À@@   ÀCÀ    Ä@  @ C^         fork 	       open 
   /dev/null    w+    dup    stderr    stdout    stdin    fileno 	      close    exec    /bin/sh    -c    waitpid    exited                     z   «    U       @À Z      @Á @    A@ ÀZ   ËÁÀ@ ÜAËAÜA ËÁÜA ËÁÜA Ã$              ã  À@@ËAÜA Z   @ ËÁÜA ËAÁÜ   ABA W ÀÄ  ÆÁÁ D  FÁÜAËÁÜA Z   ÀËAAÜ   BBA W ÀÄ  ÆÁÁ  D  FÂÜAËAÜA Ä  ÆAÂ AÂ   ÜA         pipe    fork 	       write    close    fileno    stdout    dup    stdin    exec    /bin/sh    -c               %   @       D   K@À À   \  @Ä  Á  ÀA  @   À  Á@  Z      @ ^  À     AA        	      read    waitpid    nohang    exited 	       close                                 ¶   á     @   
   J     Á@    AÁ   ÁA b@    AÀAÁ   @  @   @ À  Ü@ À   	Ê  B KBÁÂ \ F ÉBBaB  þFBÂ FBZ  @FÃ FBZB    @ \ KBÁÂ \ F ÉBBaB  þD FBÃ  À\Bá@   ö          fs    blocks    used 
   available    percent    mountpoint    util    execi    df 	      gmatch    [^%s]+ 	      insert                     ñ   ø       D      \  À @T   @D  FÀ À  À   \@   D  F Á \ F@Á ^          string 	    
   writefile    /proc/sys/kernel/hostname    uname 	   nodename                     ÿ      
&   @  ÀZ   À Ä   Æ ÀÚ@   Ä  Æ@ÀÆÀ AÁ  A B A  ÁA UÁ   Ä  ÆÀÁ
 KAÁA  \ A B A  "A  Ý  Þ     	      popen    util    exec    wget -qO- '    gsub    '        execute    wget -qO '%s' '%s'                                  @  F@@ FÀ @@ À@Æ@@ Æ Á^          sysinfo    loads 	   	   	                                    @ A@               execute    reboot >/dev/null 2>&1                        ;    q       @ A@   D   F À   \   ËÀÀ A Ü   Ä  ÁÀ A Ü   KÁÀ Á \  D ÁÀ Â \   ËÁ@ A Ü  A    A Ä ÂÀ  Ü   KÂÀ ÁÂ \  D ÂÀ  \  Â@ C B  ÀÂ@  B   Â@ Ã Ä ÆÄÆBÄ  @A  Ü  ÚB  ËÂ@ AÃ ÜÚB  @ËÂ@ A ÜÚB   Ä ÆÄÆBÄ  @AC  Ü  ÚB  ÄÆÅÜ ÆÂÅÚB    À   @ À @  À  @     	   readfile    /proc/cpuinfo    /proc/meminfo    match    MemTotal:%s*(%d+)    
Cached:%s*(%d+)    MemFree:%s*(%d+)    Buffers:%s*(%d+) #   [Bb]ogo[Mm][Ii][Pp][Ss].-: ([^
]+) 	       SwapTotal:%s*(%d+)    SwapCached:%s*(%d+)    SwapFree:%s*(%d+)    system type	+: ([^
]+)    Processor	+: ([^
]+)    model name	+: ([^
]+)    util    pcdata    /tmp/sysinfo/model    machine	+: ([^
]+)    Hardware	+: ([^
]+)    /proc/diag/model    uname    machine                     ?  A           @ @@ A               util    exec    logread                     E  G           @ @@ A               util    exec    dmesg                     L  O      D   F À @  À   \     @À@À          	   readfile    /dev/urandom    bin    hexlify                     S  U           @  @@           sysinfo    uptime                     a  ~   7   D  FÀA  \ Z  D FÀA  \À	J   Â@  CAIB¡B  þBÁWA@ ÆBÁÂÆBÂÂÆÂÂÂÆBÃÂÆÂÃÂÆBÄÂ   À À    ÜB Z@  @ Ê  @ Ô ÌBÁIaA  @õ^          access    /proc/net/arp    lines    gmatch    %S+ 	      IP    IP address    HW type 	      Flags 	      HW address 	      Mask 	      Device 	                         É   Å     @ J    ä        C@A     Ã@A  ÀÁD Ä@    Z   @  Á À 
D !C  @û C@AÃ    Ã@AÃ ÀÁ Ä@ Z      @  Á À 
D !C  @û C@AC    @Ã@AC Á À 	@ Z      @  Á À  
WÀÂ@ @@ BE  B D !C  ùCC Á $D          CD FÃÃ\  @
FDW@Ä	FDDD      IFDÀÄ@FEZ  FET@ÅFDFDEA	 IFDÀÅ FDFDEIFD@ÆÀ FDFDEI!  Àô@ÀF Z   FFZD   FFZ  @  ÆEFFFÅF\D !  @û GCG@ @@ EÆFFFÅF\D!  Àý        cursor    access    /proc/net/arp    lines    match ,   ^([%d%.]+)%s+%S+%s+%S+%s+([a-fA-F0-9:]+)%s+    upper    /etc/ethers    ^([a-f0-9]%S+) (%S+)    /var/dhcp.leases    ^%d+ (%S+) (%S+) (%S+)    *    foreach    dhcp    host    getifaddrs    name    lo    family    packet    addr 	   	      inet 	      inet6 	   	      util    kspairs            >      À   %       Ä  ÆÚ@   Ä  
  É Ä  Æ  A  ¥    A     @É Ä  Æ  AA  ¥    A     A@É Ä  Æ  A  ¥    A     @É Ä  Æ  AÁ  ¥    A     Á@É      	   	   	   	                       ­  ±      D   F À F@À @ \ ÀD  ËÁ@Ü A CBA \A a@  @ý        util    imatch    mac    upper    ip    name                                 Ï  á         D      ä         \@ J      Á   $A       @^  c        	          Ñ  Ö   
"   Ú@    @[A   @  ÁA   Û@   À  Ú   @W À @  A  @ÛA   À  AB   A     A        getnameinfo 	d                       Ù  Þ   '   Ú@    @[A   @  ÁA   Û@   À  Ú   W   D TLÀ À  B  @[B   @  ÁB   B      ¢A 	        getnameinfo 	d   	                                   ç  ù         D      ä         \@ J      Á   $A       @^  c        	          é  î      Ú@     @@  ÁA   Û@   À   Ú   @W@À  @ A        getnameinfo 	d                       ñ  ö   	   Ú@     @@  ÁA   Û@   À   Ú   W@  D TLÀ À  ¢A 	        getnameinfo 	d   	                                   ÿ           D      ä         \@ J      Á   $A       @^  c        	                  Ú@     @@  ÁA   Û@   À   Ú   @WÀ  @ A        getnameinfo 	d                       	     	   Ú@     @@  ÁA   Û@   À   Ú   W  D TLÀ À  ¢A 	        getnameinfo 	d   	                                     ?   ^   J       @Á@       @	  À@Á@   @ÁB @  ÀÂ ÁÂW@BÂÂBÃÂ T Â   ÃBÿ   À    @ B   ÂBI¡@  À÷@    @ÁÀ       	  À@ÁÀ   ÁB @  ÀÂ ÁÄW@B@ADÂÂÂ T Â   ÃBÿ   À    @ B   ÂBI¡@   ø@     ^          access    /proc/net/nf_conntrack    r    lines    match    ^(.-( [^ =]+=).-)%2    _parse_mixed_record     + 	   
   TIME_WAIT    layer3 	      layer4 	       /proc/net/ip_conntrack 	      ipv4                     G  Q        E   F@À ¤       \@           net    routes        J  N      F @ K@À \ À  D   Z    D   FÀÀ À@ @              dest    prefix 	       metric                                 Y  p       E   F@À ¤       \@ @  ÀD   FÀ FÀÀ   \    @@ä@         @ c             net    routes6    ip    IPv6 	   2000::/3        \  b      F @ K@À \ À ÀFÀ@ W Á  D   Z    D   F@Á @A @              dest    prefix 	       device    lo    metric                     f  l      F @ K@À Ä   \Z    D  Z    D  FÀ @ @             dest    equal    metric                                 t  |       
   D      @  \  AÀ@À   Á@ÆÁ	Àa  ý          getifaddrs    family    packet 	      name                           +   
   D      @  \  ÀAÀ@ ÁÀÆAAÁÆÁAÁÆABÁÆÁBÁACACAÃÆADÁÆÁDÁÆAEÁÆÁEÁÆAFÁACÆGÁAÃACÆÁÇ	a  @÷           getifaddrs    family    packet    data 	   	   rx_bytes 	      rx_packets 	   
   rx_errors 	      rx_dropped 	   	    	   	   	   
   multicast 		   	   tx_bytes 	
      tx_packets 	   
   tx_errors 	      tx_dropped 	   	      collisions 	   	      name                        ¨          @@ä          @ ^          net 	   arptable        ¢  ¦      F @     @ F@@ H          IP address    HW address                                 ¯  ×   [   J       @Á@    ÀÂ  A B  @D FDÁFÁ ÁÄ  EA
B
\  D FDÁFÁÁÄ  EA
B
\ @D FDÁFÁËDÂ@Ü EA
B
\ ÀJ IÄI À  I À  I À I À  I Å  I À  I ÀÅ II   À   ÀD   DE	I@	¡@   ë^          lines    /proc/net/route    match .   ([^%s]+)	([A-F0-9]+)	([A-F0-9]+)	([A-F0-9]+)	 0   (%d+)	(%d+)	(%d+)	([A-F0-9]+)	(%d+)	(%d+)	(%d+)    ip    Hex 	       FAMILY_INET4    prefix    dest    gateway    metric 	   refcount 	   usecount    mtu    window    irtt    flags 	      device 	                       Þ     w   D   F À @  Á  \Z   J     À@Á@   @ÁB AB B ÁB  Á  ÀÚ  @  ÀZ  @  ÀÚ  @  ÀZ  @  ÀÚ  @ ÄAB@ ÀE Ä ÆÄÁ	ÆÂ	     ÄAB@ ÀE Ä ÆÄÁ	ÆÂ	    ÄAB@ Ä Ä ÆÄÁ	ÆÂ	   
D 			DÁD \	DD ÁD \	DDÁD \	DD ÁD \	D	Ä	Ä   À @   \D  T LDÅI ¡@  Àå^          access    /proc/net/ipv6_route    r    lines    match    ([a-f0-9]+) ([a-f0-9]+)     ([a-f0-9]+) +([^%s]+)    ip    Hex 	      FAMILY_INET6 	      source    dest    nexthop    metric 	   refcount 	   usecount    flags    device    metric_raw 	                               D   F À @  Ë@ AÁ   Ü A  ]  ^           execute    ping -c1 '    gsub    '        ' >/dev/null 2>&1                     )  ,      J     @@ I    À@ I @  @ @               uid    getuid    gid    getgid                     0  N    #   
   C      @@@Á   @      À  @ËÁ@A ÜAÄ  Ü Ú  @
 	Ä		D		Ä		D		 á@  Àú          util    execi    /bin/busybox top -bn1    match N   ^ *(%d+) +(%d+) +(%S.-%S) +([RSDZTW][W ][<N ]) +(%d+) +(%d+%%) +(%d+%%) +(.+)    PID    PPID    USER    STAT    VSZ    %MEM    %CPU    COMMAND                     U  W      D   F À    ]  ^           setgid                     ^  `      D   F À    ]  ^           setuid                     }     %   D   F À Z   @D   F À    \ Z@  À D   F@À    \   À À @    ÀÀ    Ô  X ÁÀ W@A@ AÀ Ã   Þ  À    Þ         getsp    getpw    pwdp    passwd 	      !    x                                @@À   À Ú   ÀW@À  Á@@  W   A               user 
   getpasswd     crypt                       ¤      Z     À A  A   @       @ A  A         À@Á    AA  Á Â @   Õ       	      gsub    '    '"'"'    execute    (echo '    '; sleep 1; echo '    ') |  	   passwd '    ' >/dev/null 2>&1                     ¯  Ù   B   D     Á   \À   Á@   @ KÁ@ Á \ÁZ       Ä  Ü ËAAA Â ä             ÜAÀËBA   Ü @Â@ËAAA Â äB      ÜAÛ  ÆB   Ü Ú   ÂB    
  D   ÊB  $         É]^  ã           iwinfo 	       cursor_state    match    ^(%w+)%.network(%d+)    foreach 	   wireless    wifi-iface    get    wifi-device    type    __index        º  Â      F @     @D  L@À H  D     F@ Z@    F @ H B   ^          device 	      ifname                     Å  Ê      F @     F@@ Z   À F@@ H   B   ^          device    ifname                     Ð  Ö       À          @       @ Ä                ifname                                 ä  ê       
   D   F À @  @ÁÀ  À \ T  LÁ  AAÀ  	a@  ý          glob    init    dir    * 	   	   basename                     ï  ô      D   F À @  @À   À \ Z    EÀ    Å@  ÆÀ   ¢@  ]  ^           access    init    dir    call B   env -i sh -c 'source %s%s enabled; exit ${START:-255}' >/dev/null                     ö  ú          @Å@  ÆÀ  Õ     @À  Ê A  @@   â@ÐÀ              access    init    dir    call    env -i %s%s %s >/dev/null                     ÿ     
   D      À   \W@À   B@  B  ^          enabled 	                             
   D      À   \W@À   B@  B  ^          enable 	                            
   D      À   \W@À   B@  B  ^          disable 	                             
   D      À   \W@À   B@  B  ^          start 	                             
   D      À   \W@À   B@  B  ^          stop 	                        "  6   7   Z@    A      Ê     D FAÀFÀ A@Á@À   Á \ D   B@@Ä ÆBÀÆÂÀ  Ü   C \ @CÁ    ÀÁ@D FÂÀ \D   a  Àû!  ÷  @  	            util    split    trim    
    match %   ([^%s][^:=]*) *([:=]*) *"*([^
"]*)"*        insert                             