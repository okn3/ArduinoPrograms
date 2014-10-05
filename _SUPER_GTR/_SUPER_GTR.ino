#include <Servo.h>

#define TRIGPIN 8
#define ECHOPIN 9
#define CTM 19

Servo taco;
Servo speed;

int pos = 0;

// 8番ピンをスピーカーに接続する
//const int speaker = 11;

void setup() {
  
  Serial.begin(9600);
  
  //servoの設定
  taco.attach(10);
  speed.attach(11);
  
  //超音波距離センサのセットアップ
  pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
  // スピーカーをつないだピンを出力に設定する
//  pinMode(speaker, OUTPUT);
  //最初のやつ
  
  for ( pos = 180; pos > 0; pos -= 1 ) {
    taco.write( pos );
    delay( 5 );
  }
  
  for ( pos = 0; pos < 180; pos += 1 ) {
    taco.write( pos );
    delay( 5 );
    Serial.println(pos);
  }

}

void loop() {
  //スピーカー鳴らす
//  digitalWrite(speaker, HIGH);
    int dur;
  float dis;
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(CTM);
  digitalWrite(TRIGPIN,LOW);
  dur = pulseIn(ECHOPIN,HIGH);
  dis = (float) dur*0.017;
//  Serial.print(dis);
//  Serial.println("cm");

  //距離からメータの針を移動
  if(dis <= 50){
    dis = map(dis, 10, 60, 0 ,150);
    int dis2 = map(dis, 10, 60, 0 ,180);
    taco.write(dis);
    speed.write(dis2);
    
    
    
    
    
    delay(5);
    Serial.println(dis);
  }else{
    taco.write(150);
    delay(5);
  }

}


