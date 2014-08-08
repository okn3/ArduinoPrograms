
// センサに接続したアナログピンの番号
int sensorPin = 0;


void setup() {
  // LCDの桁数と行数をセットする
  Serial.begin(9600);
}

void loop() {
  // LCDの表示をクリアする


  // 温度センサの値を読み取る
  int value = analogRead(sensorPin);

  // 読み取った値を温度に変換する
  int temperature = map(value, 0, 205, 0, 100);

  // LCDに現在の温度を表示する
  Serial.print("Temperature: ");
  Serial.println(temperature);

  // 次のループ開始まで1 秒間待つ
  delay(1000);
}

