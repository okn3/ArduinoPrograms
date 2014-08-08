#include <Max3421e.h> //ADKを利用するための3つのライブラリを読み込む(1)
#include <Usb.h>
#include <AndroidAccessory.h>
//外部インテントのための指定(2)
AndroidAccessory acc("ADKstudyGroupTokyo ",          //第1引数:組織名
"AdkNoSuchAppTitle",                                 //第2引数:存在しないアプリのタイトル名
"このAndroidはADKが使えます ADK Connection Test",       //第3引数:ダイアログ表示メッセージ
"1.0",                                               //第4引数:バージョン
"http://accessories.android.com/",                   //第5引数:ジャンプ先URL
"0000000012345678");                                 //第6引数:シリアル番号

void setup() //最初に一度だけ実行される部分
{
  Serial.begin(115200);
  Serial.print("\r\nStart");
  //USBホスト機能を有効にする
  acc.powerOn();
}

void loop() //繰り返し実行される部分
{
  if (acc.isConnected()) { //Androidを起動・接続する命令を送る(3)
    //communicate with Android application(4)
  } else {
    //set the accessory to its default state(5)
  }
  delay(10); //10ミリ秒処理を停止(10ミリ秒おきにloop()を繰り返す) (6)
}
