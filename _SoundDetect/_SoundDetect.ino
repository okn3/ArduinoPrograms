#include <dht11.h>
 
dht11 DHT11;
int val=0;
void setup()
{
  DHT11.attach(A2); //デジタルでも可
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}
 
void loop()
{
 Serial.println("----------------------");
 gasDetect();
 HumidTemp();
//  delay(1000);
}

void HumidTemp(){
  int chk = DHT11.read(); 
  Serial.print("Humidity (%): ");
  Serial.println((int)DHT11.humidity, DEC);
  Serial.print("Temperature (C): ");
  Serial.println((int)DHT11.temperature, DEC);
}

void gasDetect(){
     for (int i = 0; i <= 3; i++){
        delay(242);
        digitalWrite(5,HIGH);
        delay(8);
        digitalWrite(5,LOW); 
    }
    delay(237);
    digitalWrite(3,HIGH);
    delay(3);
    val = analogRead(5);
    delay(2);
    digitalWrite(3,LOW);
    digitalWrite(5,HIGH);
    delay(8);
    digitalWrite(5,LOW); 
    val = 1023 - val;
    val = val * 5;
    val-=2500;//調整
    Serial.print("gas: ");
    Serial.println(val);
}
