LuaQ                     A@    À@@  A@ @ @ A E  À \ @Â             À  @ ¤   ä@      $      dÁ         ¤ äA $ dÂ     GÂ d     G EÂ GB E G dB    GÂ d    G dÂ       GB FÂÅ \ G E ¤ IE ¤B IE ¤ IE ¤Â IE ¤ IE ¤B     IE ¤        IE ¤Â IE ¤ IE ¤B IE ¤     IE ¤Â              IE ¤       IE ¤B          IE ¤             IE ¤Â IE ¤      IE ¤B      IE ¤   IE ¤Â               I  ,      module    luci.ip    package    seeall    require    nixio    bit 
   luci.util    LITTLE_ENDIAN 
   bigendian    BIG_ENDIAN    FAMILY_INET4 	      FAMILY_INET6 	      htons    htonl    ntohs    ntohl    IPv4    IPv6    Hex    cidr    class    is4    is4rfc1918    is4linklocal    is6    is6linklocal    string 	   zcstring    lower    higher    equal    prefix    network    host    mask 
   broadcast 	   contains    add    sub    minhost    maxhost         %   1         E      Ê   Á@AÉ   Á@AAÉ   Á@ABÉ   Á@ABÉ   Á@ACÉ $  É ] ^           setmetatable    __index    luci    ip    cidr    __add    add    __sub    sub    __lt    lower    __eq    equal    __le        -   /        E   F@À FÀ FÀÀ ¥   \  Z@  @E   F@À FÀ F Á ¥   \  ^          luci    ip    cidr    equal    lower                                 3   K    a   Å      Ü @À@Ê    @@  Á  D  FÁ  ÁA \â@   ÀÅ      Ü ÁËÀA A ÜÚ    Å@    Ü   À Å    Ü      ÅÀ C W@   A   AA Ü@Ê    FÁC  â@   ÀÅ      Ü  ÄÀÅ   ÁC Ü  ÄÅÀ C W@   A   AA Ü@Ê    FÁC  â@   Å      Ü  Ä@Ê    @   â@   ÅÀ   AA Ü@          type    number    rshift 	      band 	ÿÿ     string    find    :    IPv6    IPv4    assert 	   "   Can't mix IPv4 and IPv6 addresses    unpack 	      table    Invalid operand                     M   O       D   F À    @@Á  Á@ ÐÀ@ ÍÀ] ^           lshift    rshift 	ÿÿ  	                       Q   S       D   F À    @@Ä     Ü    Á  ] ^           band    bnot 	ÿÿ                      U   W     	   E   @   A@  Z@    A  ^          FAMILY_INET4 	    	                       Y   [     	   E   @   A@  Z@    A  ^          FAMILY_INET4 	   	                       ^        
S     A  @ÀÀA @ @     À @   Ú    @ À    LÁÀ@ú   @Ú   À À@   AÁ   AAÁ B @  LÁÀ@ÀÀ    Ú   X@ @À Å ÆAÁÂ FB ÜUÀ@A  À Á UÀ  Å ÆAÁÂ FB ÜUÀLÁÀ@÷Ú    @Â  Á UÀ^    
   	   		   	    	      string    format    %X    :%X    : 	                          ¤       E   Z   D   F@À    @À   Á  Ä   Æ Á  AA@  Á  A Ü ]   ^               LITTLE_ENDIAN    bor    rshift 	      band    lshift 	 ÿ                      «   ´       E   Z   D   F@À    @ÅÀ    A@  A Ü   ÅÀ    ÁA@   Ü   ]   ^               LITTLE_ENDIAN    bor    lshift    htons    band 	ÿÿ  	      rshift                     Ó   ÷    i   @          Ê  A  â@  Ê   @ Á  KA ÁA  \   KA ÁÁ  \ KAÂ\ KÁÁ  \   Z    KÁBÀ \ À   E  \    À X@C@  À C^    K@ ÁÁ \AE \ @E  \ E \ ÀE  \  Z  À Ä@  À D@Ú  À Ä@  À D@  ÀEB FÄ Ê ÃÄNÃÄLâB \BEB FÄ À \B       
   0.0.0.0/0    FAMILY_INET4    match    /(.+)    gsub    /.+        ^%[(.*)%]$    %1    upper 	   ^::FFFF:    prefix 	   tonumber 	    	       ^(%d+)%.(%d+)%.(%d+)%.(%d+)$ 	ÿ      table    insert 	                         Q   Ü   @          Ê  A  â@  Ê   @ Á  KA ÁA  \   KA ÁÁ  \   Z    KABÀ \ À   E  \    À XÀB@  À C^    KAC Á  \ ÀÃ A ZA    A  Ô  À@ ÃÞ ËD AÃ Â ÜA     Å CC ÍC AÃ Ü@Z  @ ÅÀ ÔÌÃÉ@ ÚA   ÍBÀ@ ÃÞ ÔÌÃLCÔ@Å@öËBC @Ü Ô À@Ô ÅÅ   AÃ Ü@Z  @ @@ ÃÞ ÔÌÃÉ@@Ô ÀÔW@Å Ô À@ ÃÞ A Á  A àËDA Â ÜA  À E@ ÃÞ     CÅ DCÀ  Ü  @Z  @ @@ ÃÞ WC@ F ÔÌÃÄÆÉ  ÔDÉ [   LDßBôÚ  Ô Ç@ ÃÞ Ô ÇÅB ÆÇ @Ã ÜB @ýÔ Ç   ÅB ÆÇ  @ÜBÅB ÆÇ  @ ÜB          ::/0    FAMILY_INET6    match    /(.+)    gsub    /.+        ^%[(.*)%]$    %1    prefix 	   tonumber 	    	      sub 	      : 	   	-      find 	   	ÿÿ  	   	   	      . 	ÿ   	   	   	      table    insert                     \  z   R   W @@ @    @   À  Û@ ÀÿZ@  À   @  @    @  A    ÃÂ  OA  MÂ     AC UAÂþÚ      À  AÂ  Â  B KB ÍÃÀ \ UAþ  @  UA  Â  OA  C KB ÀÂ\ Ã   À T LÃÀ@ C^ Âû J À   bB            FAMILY_INET4     	   	      0    LITTLE_ENDIAN 	þÿÿÿ   sub 	   tonumber 	   	                                F @ @  W   B@  B  ^       	      FAMILY_INET4                              F @ @   F@ F À @À F@ F À Y Á  F@ F À @À F@ F À YÁ  F@ F À WÀÁ   B@  B  ^  B   ^       	      FAMILY_INET4 	   	 
  	ÿ
  	¬  	¬  	¨À                               F @ @   F@ F À WÀÀ   B@  B  ^  B   ^       	      FAMILY_INET4 	   	þ©                      ¡  £       F @ @  W   B@  B  ^       	      FAMILY_INET6                     §  ¬       F @ @   F@ F À @À F@ F À Y Á   B@  B  ^  B   ^       	      FAMILY_INET6 	   	þ  	¿þ                      ²  Ä   
>    @      	@  @ÁÀ    AFAA FÁÁ D  FÂAA AÁA \  AÆAA ÆAÁÂ Ä  ÆÂBA BAAB Ü  @  B ÀBÀ  Á  B U @C     @  @Á Á FAA    @  B  DÀ   Á  B U ^          is4    string    format    %d.%d.%d.%d    rshift 	   	   	      band 	ÿ   	   	       /    is6    %X:%X:%X:%X:%X:%X:%X:%X    unpack 	                       Ë  Þ   
:    @      	@  @ÁÀ    AFAA FÁÁ D  FÂAA AÁA \  AÆAA ÆAÁÂ Ä  ÆÂBA BAAB Ü  @  B ÀBÀ  Á  B U @C       Æ@A  @  B CÀ   Á  B U ^          is4    string    format    %d.%d.%d.%d    rshift 	   	   	      band 	ÿ   	   	       /    is6 	                       ç  ð    	"      Æ@@ AÀ W   Â@  Â    @  Á@  Á@  AA  àÆÁ@ ÆÂÀ W  ÆÁ@ ÆÂÀ X   ÂA  Â Þ ßÀûÂ   Þ          assert 	   &   Can't compare IPv4 and IPv6 addresses 	                       ù      	"      Æ@@ AÀ W   Â@  Â    @  Á@  Á@  AA  àÆÁ@ ÆÂÀ W  ÆÁ@ ÆÂÀ XÀ  ÂA  Â Þ ßÀûÂ   Þ          assert 	   &   Can't compare IPv4 and IPv6 addresses 	                             	      Æ@@ AÀ W   Â@  Â    @  Á@  Á@  AA  àÀÆÁ@ ÆÂÀ W @ Â  Þ ßýÂ  Þ          assert 	   &   Can't compare IPv4 and IPv6 addresses 	                         6   @    @ Z   @  Â     @  WÀ@@A     A @  A  @ @  A      A  @ C^ C ÅÁ BÜ@@Â@ B@  ÃBA C D  FÃÀ \ À CD  FÃÂ ÐBÍÃ\ Àû@ á  Àø       	   	       type    table    is4    IPv4    IPv6    ipairs 	   	ÿÿ  	      lshift 	   	      band                     ?  Q   
9      Z@    F @ Ã A  E  FÁÀÁ \ A    B@FBA FÂ@Aþ FAA T@ A@D  FÁAA Ô ÌÁÁÄ   Ü \  @ A@FAA TA     B@ÀAÁþ J A@ À FB@  bA          	   	      math    floor 	   	      band 	                        Y  [      D     Æ @ A@ D @ \ ¢@  ]  ^        	   	                       c  t   	/      Z@    F @ Á@    Á@OÁ  AA  à Ô ÌAÀ@ÁßÀþÔ  A   ÀÔ  Ì@À  @   Ô  Ì@ÀA  AA  à Ô ÌAÀÀÁßÀþÄ  
 FA@  Ä B@ Ü "A  Ý  Þ        	   	      math    floor 	   	ÿÿ  	   	                        {     	+   F @ @   @	J     ÆÀ@   b@    @AÆA ÏÀÁ  @Ô  À ÀÄ   Æ Â D A \ Ü  IÀ Ì @ A  à  I@Bß@ÿÄ  
 F@  Ä@ Ü "A  Ý  Þ     
   	      FAMILY_INET4    unpack 	      math    floor 	   	      bor 	ÿÿ                                  Æ@@ AÀ W   Â@  Â    @À@  ËÀÀ Ü À  A  Ë Á KÁ@ \ Ü  WÀ   @                   assert 	   &   Can't compare IPv4 and IPv6 addresses    prefix    network                       µ   ?   
  E  A@ \ "A  D   Æ@ \ Á  Â   B AÀB     ÆBÌÀ ÆBÌÐÂÁ	Á@ÀÍÀÀFCMCC	@ÃÞ  ÆBÌ	ÁÁö    	   À Ê@ @ B âA     	      unpack 	   	   	ÿÿÿÿ	       table    remove 	ÿÿ  	                       ¼  Õ   ?   
  E  A@ \ "A  D   Æ@ \ Á  Â   B AÀB     ÆBÍ Á ÆBÍÂÐÂÁ	Á@ÀÍÀÀFCLCC	@ÃÞ  ÆBÍ	ÁÁö    	   À Ê@ @ B âA     	      unpack 	   	   	ÿÿÿÿ	       table    remove 	ÿÿ  	                       Ú  ß      F @    Æ@@   K@ \ KÀÀ Á@   ]  ^        	   	      network    add                     ä  ó   
4   F @    Æ@@    C     Å  Á@ Ü  ¢@  Å  Æ@Á@ AÜ Ì@À ÁAFÁ  Æ@     AÀT A     ÂAÿJ A@ À  FB@  bA     A@EA @À BA  Â A        	   	      unpack 	      math    floor 	      bor 	ÿÿ     FAMILY_INET4    sub                             