// 傾きセンサに接続したピンの番号
const int sensorPin = 8;

// LEDに接続したピンの番号
const int ledPin = 13;

void setup() {
  // 傾きセンサに接続したピンのモードを入力に
  pinMode(sensorPin, INPUT);

  // LEDに接続したピンのモードを出力に
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // センサの状態を読み取る
  int sensorState = digitalRead(sensorPin);
  
  // 読み取った値をLEDにセット
//  digitalWrite(ledPin, sensorState);
  Serial.println(sensorState);
  if (sensorState == 0){
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay(100);               // wait for a second
  }else {
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay(50);               // wait for a second
  }
  // 次のループ開始までに10ms待つ
  delay(10);
}

