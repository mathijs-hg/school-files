LuaQ               	+      A@  ��  ��@@�  A@ � E  �� \� �  �� �� �   ܀ A��� A� �� � $              �B $B              �� $�       �   �   � $�    �       module    cloud_req.cloud_https    package    seeall    require 
   luci.json 	   luci.sys    luci.tools.debug    ubus    connect    cloud_https    /tmp/cloud/downloaded_file "   /etc/certificate/2048_newroot.cer    cloud_https_post    cloud_https_get    cloud_https_download    downloadurl_escape           #    1   �   �   � �A  D� F���  \ �@  �   � ��  @� �@�� � ƀ�   ܀ �� ��@���  ˀ�D��� � ܀� �@ �A    @A� ���A��� C� �  @FA�A ��D� F���A�\    �       print    https req:    encode    https url:    cloud_request_data    cloud_request_url    call    cloud_https_post  	���   re:    re 	    	   response    decode                     %   @    6   J   �  �   � �A  @  �@�� � ���
  ܀ I� �I  ��@ � AA � �� ���D�� �� ܁�� ��   � ��AB��  �  ��@��B@ ��  �  �   � �A FAB�@��@B��� ��   � ��C�@ �@B� �CF�C �    �       print    https get url:    cloud_request_data    encode    cloud_request_url 	   	      call    cloud_https_get    re 	     	���   re: 	   response    decode                     B   W    "   �   � @�@     �@���  ��  �  � ��� �A�� D��  �A������� @  ��   �  ��@��� @ ��  �  �   � @�@  � �@�^   � 
      print    https download url: 	   	   
   fork_call E   curl --connect-timeout 20 -m 1000 -Y 1 -y 100 --cacert %s -o %s "%s" 	     	���   re:                     Y   `        A@  G   E�  F � �   �   $  \� G�  E�  ^   �       pattern    [%`%#%$%;]    s    string    gsub        [   ^     
   E   F@� ��  �   ���   �  \�  ^   �       string    format    %%%02X    byte                                         