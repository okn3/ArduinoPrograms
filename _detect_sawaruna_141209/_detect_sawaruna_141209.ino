/*
 グフ用 触るな！！！！
 */

#define trigPin 8
#define echoPin 9

int tmp;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  //読み込み
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  String s = String(distance);

  
//例外処理
  if(distance <= 100){
    for (int i = 0;i<5;i++){
    digitalWrite(trigPin, HIGH);
    delay(100);
    digitalWrite(trigPin, LOW);
    delay(100);
    }
    digitalWrite(trigPin, HIGH);
    delay(500);
  }
  delay(500);
}
