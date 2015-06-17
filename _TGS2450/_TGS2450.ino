int PinFlag ;

void InterPin()
{
     PinFlag = 1;                         // 割込み有ればＯＮ
}

void setup()
{
     Serial.begin(9600);
     pinMode(13,OUTPUT) ;                  // 13番ピン付属LED出力
     attachInterrupt(0,InterPin, RISING) ; // ２番ピンの割込みを指定(立上がりで割込み)
     PinFlag = 0 ;
}
void loop()
{
//  Serial.println(PinFlag);
     while(PinFlag == 1) {
          digitalWrite(13,HIGH);          // LEDを点灯
          delay(1000);
          Serial.println("==SoundDetect==");
          digitalWrite(13,LOW);
          PinFlag = 0;
     }
}
