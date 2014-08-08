#include <Max3421e.h> //ADKを利用するための3つのライブラリを読み込む(1)
#include <Usb.h>
#include <AndroidAccessory.h>

#define LED 2 //LED用のピンを2番に指定
//外部インテントのための指定(2)
AndroidAccessory acc("Dorobook,Socym",          //第1引数:組織名
"AdkLedOnOff",                                 //第2引数:存在しないアプリのタイトル名
"AdkLedOnOff Arduino USB HOST",       //第3引数:ダイアログ表示メッセージ
"1.0",                                               //第4引数:バージョン
"http://accessories.android.com/",                   //第5引数:ジャンプ先URL
"0000000012345678");                                 //第6引数:シリアル番号

void setup() //最初に一度だけ実行される部分
{
  Serial.begin(115200);
  Serial.print("\r\nStart");
  pinMode(LED, OUTPUT); //LED用ピンの出力ポートにする
  //USBホスト機能を有効にする
  acc.powerOn();
}

void loop() //繰り返し実行される部分
{
  byte msg[1]; //Arduinoから受け取るデータ
  if (acc.isConnected()) { //Androidを起動・接続する命令を送る(3)
    //communicate with Android application(4)
    int len = acc.read(msg, sizeof(msg), 1); //ADK接続から読み込み
    
      if (len > 0){//よみこんだでーたがあればしょりする
        if (msg[0] == 0x1) { //独自のプロトコルのコマンドデータが0x1ならば処理する
          digitalWrite(LED, HIGH); //LEDを点灯する
        } else {
          digitalWrite(LED, LOW); //LEDを消灯する
        }
      }
  }else{
    //set the accessory to its default state(5)
    digitalWrite(LED, LOW); //USB接続されてないときは消灯する
  }
  delay(10); //10ミリ秒処理を停止(10ミリ秒おきにloop()を繰り返す) (6)
}
