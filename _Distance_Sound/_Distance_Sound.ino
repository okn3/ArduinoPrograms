/*
衝突防止プラグラム
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 9 Trig to Arduino pin 8
 More info at: http://goo.gl/kJ8Gl
 */
const int speakerPin = 11;
#define trigPin 8
#define echoPin 9

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  //範囲外
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  //50~100cm
  else if(50 <= distance && distance < 100) { 
    tone(speakerPin, 1000, 100);
    Serial.print(distance);
    Serial.println(" cm");
    }
   //30~50cm
  else if(30 <= distance && distance < 50) { 
    tone(speakerPin, 1000, 300);
    Serial.print(distance);
    Serial.println(" cm");
    }  
    //~30cm
   else if(distance < 30) { 
    tone(speakerPin, 1000, 1000);
    Serial.print(distance);
    Serial.println(" cm");
  }
  else { 
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
