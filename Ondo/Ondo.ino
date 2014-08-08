/* 
  温度計測（0℃〜100℃）
*/

int   A_inPin = 0;  // アナログ入力ピン番号
float A_val;        // アナログ入力値(0〜203)
float tempC   = 0;  // 摂氏値( ℃ )

void setup()
{
  // シリアル通信速度
  Serial.begin(9600);
}

void loop()
{
  // アナログピンから計測値を取得(0〜203)
  A_val = analogRead( A_inPin );

  // 摂氏に換算
  tempC = ((5 * A_val) / 1024) * 100;

  // 改行しながら出力
  Serial.println( tempC );

  // 1秒停止
  delay(1000);
}
