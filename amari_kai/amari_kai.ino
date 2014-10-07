#include <Servo.h>

#define TRIGPIN 8
#define ECHOPIN 9
#define CTM 19

Servo myservo;

int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(10);
    pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
//  myservo.write(0);
}

void loop() {
  
    int dur;
  float dis;
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(CTM);
  digitalWrite(TRIGPIN,LOW);
  dur = pulseIn(ECHOPIN,HIGH);
  dis = (float) dur*0.017;
//  Serial.print(dis);
//  Serial.println("cm");
  
  delay(10);
  
//  for ( pos = 0; pos < 180; pos += 5 ) {
  if(dis <= 50){
    dis = map(dis, 0, 50, 0 ,180);
    myservo.write(dis);
    delay(10);
    Serial.println(dis);
  }else{
    myservo.write(180);
  }
//  for ( pos = 180; pos > 0; pos -= 5 ) {
//    myservo.write( pos );
//    delay( 5 );
//  }
//  Serial.println(pos);
}
