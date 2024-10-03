var languageNum = new Array("en","sc","tc");
var item_name = new Array("韌體更新", "韌體資訊", "目前韌體版本",
"韌體更新",
"檔案路徑",
"上傳",
"升級", 
"韌體更新完成。", 
"裝置正在執行韌體更新中。",
"檔案無效！",
"裝置正在執行韌體更新中，請稍待，可能最多需要 240 秒的時間完成作業。",
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
"攝影機可能會有新的韌體升級版可用。建議您不斷更新攝影機的韌體成最新版，以獲得功能改善並維持網路攝影機的效能。 \
請按此處 <A HREF=\"http://www.dlink.com/\"><u>D-Link</u></A> 支援網站檢查是否有最新的韌體版本。<br><br> \
若要升級 IP 攝影機的韌體，請從 D-Link 支援網站下載最新版的韌體，並儲存到電腦硬碟上。 \
請按瀏覽按鈕找出硬碟上的韌體檔。用瀏覽按鈕找出檔案後，請按<b>上傳</b>按鈕開始韌體升級。",
"<b>說明項目..</b><br><br>韌體更新會定期釋出，以改善 IP 攝影機的現有功能，並提供新功能。 \
若 IP 攝影機的特定功能發生問題，請按<a href=\"http://www.dlink.com/\"><u>此處</u></A> \
檢查本公司支援網站，看看是否有 IP 攝影機的韌體更新。",
""
);

var D_FWUP_INFO = 0;
var D_HELP_INFO = 1;
