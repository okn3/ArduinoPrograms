/*#######################################
#
# カウントくんを動かす 
# servo+スイッチ
#
#######################################:*/

#include <Servo.h> #ヘッダーのインクルード

Servo servo; //サーボのインスタンス

void setup(){
  servo.attach(3); //サーボの信号機を3番ピンに接続
  pinMode(2,INPUT);    //スイッチに接続ピンをデジタル入力に設定
}
 
void loop(){
  servo.write(0);  //サーボを0°の角度に
  
       if (digitalRead(2) == HIGH) {     //スイッチの状態を調べる
            servo.write(180); //サーボを180°の角度に
            delay(100);  //一秒待つ
            servo.write(0);  //サーボを0°の角度に
            delay(100);  //スイッチが押されているならLEDを点灯
     } 
}
