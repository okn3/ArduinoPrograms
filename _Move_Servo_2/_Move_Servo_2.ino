#include <Servo.h>

// 可変抵抗器に接続したアナログピンの番号
const int potentiometerPin = 0;
const int potentiometerPin2 = 1;

// サーボ
Servo servo;
Servo servo2;

void setup() {
  // サーボを使用するピンとしてデジタルピンの9 番をセット
  servo.attach(9);
  servo2.attach(8);
}

void loop() {
  // 可変抵抗器の値を読み取る
  int value = analogRead(potentiometerPin);
  int value2 = analogRead(potentiometerPin2);

  // 読み取った値を0から179までにスケーリング
  int angle = map(value, 0, 1023, 0, 179);
  int angle2 = map(value2, 0, 1023, 0, 179);

  // サーボの角度をセット
  servo.write(angle);
  servo2.write(angle2);

  // サーボが指定した角度まで動く間待つ
  delay(15);
}

