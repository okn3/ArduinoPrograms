/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 9 Trig to Arduino pin 8
 More info at: http://goo.gl/kJ8Gl
 */
#include <Servo.h>
#define trigPin 8
#define echoPin 9
const int speakerPin = 11;
int tmp, gap;
Servo servo;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  servo.attach(3);
}

void loop() {
  int duration, distance;
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  //読み込み
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  //処理
  servo.write(0); //戻す
  gap = abs(tmp - distance); //絶対値
  
  Serial.print("gap:"); 
    Serial.print(gap);
    Serial.println(" cm");

//差分検出
  if(gap >= 15){
//    tone(speakerPin, 500, 100);
    servo.write(90);//動かす
    delay(500);
  }
  
//例外処理
  if (distance >= 400 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("distance:"); 
    Serial.print(distance);
    Serial.println(" cm");
    tmp = distance;
  }
 Serial.println("----------------------");
  delay(500);
}
