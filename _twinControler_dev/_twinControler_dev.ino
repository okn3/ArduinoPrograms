/************************
sagamihara festival 2015

with shimoyan

unity shooting game

*************************/
#include <Servo.h>
Servo myservo;
int val;
const int stickRight = 2;     // the number of the pushbutton pin
const int stickLeft = 3;
const int buttonTrigger = 4;
const int ledPin =  13;      // the number of the LED pin
const int ledPin2 =  12;
int stickState_r = 0;
int stickState_l = 0;
int triggetState = 0;


void setup() {
  Serial.begin(9800);
  myservo.attach(9);
  pinMode(ledPin, OUTPUT);      
  pinMode(stickRight, INPUT);
  pinMode(stickLeft, INPUT);
  pinMode(buttonTrigger, INPUT);  
}

void loop(){
  stickState_r = digitalRead(stickRight);
  stickState_l = digitalRead(stickLeft);
  triggerState = digitalRead(buttonTrigger);

  if (stickState_r == LOW) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);
    myservo.write(0);
    Serial.println("move stick right!");
  } 
  else if(stickState_l == LOW){
    digitalWrite(ledPin2, HIGH);
    myservo.write(180);
    Serial.println("move stick left!");
  }
  else if(triggerState == LOW){
    Serial.println("trigger pushed!");
  }
  else {
    // turn LED off:
    myservo.write(90);
    digitalWrite(ledPin, LOW); 
    digitalWrite(ledPin2, LOW); 
  }
}
