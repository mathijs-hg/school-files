var languageNum = new Array("en","sc","tc");
var item_name = new Array("固件升级", "固件信息", "当前固件版本",
"固件升级",
"文件路径",
"上传",
"升级", 
"固件升级完成。", 
"固件升级在设备上正在运行。",
"无效文件！",
"固件升级在设备上正在运行，请等待，可能会需要240秒完成此过程。",
"秒",
""
);
var I_FIRMWARE_UPGRADE = 0;
var I_FIRMWARE_INFO = 1;
var I_CURRENT_FW_INFO = 2;
var I_FIRMWARE_UPGRADE_TITLE = 3;
var I_FILE_PATH = 4;
var I_UPLOAD = 5;
var I_UPGRADE = 6;
var I_FIRMWARE_UPGRADE_OK = 7;
var I_FIRMWARE_IS_RUNNING = 8;
var I_FILE_INVALID = 9;
var I_WAIT_FW_RUNNING = 10;
var I_SEC = 11;

var des_item_name = new Array (
"摄像机可能有的新固件升级。推荐您保持摄像机最新固件，维持和提升Internet摄像机的功能与性能。\
单击此处<A HREF=http://www.dlink.com/><u>D-Link支持页面</u></A>检查可用的最新固件版本。<br><br>\
要升级IP摄像机的固件，请先从D-Link支持页面下载和保存最新固件版本到本地硬盘。\
单击浏览按钮查找在本地硬盘上的文件。一旦用浏览按钮找到和打开了文件，单击 <b>上传</b> 按钮开始固件升级。",
"<b>帮助提示..</b><br><br>固件升级周期性的发布以提高IP摄像机的功能并添加某些新特性。\
如果遇到IP摄像机特定功能的问题，单击<A HREF=\"http://www.dlink.com/\"><u>此处</u></A>\
进入D-Link支持站点并查看是否有可用的IP摄像机升级固件。",
""
);

var D_FWUP_INFO = 0;
var D_HELP_INFO = 1;
