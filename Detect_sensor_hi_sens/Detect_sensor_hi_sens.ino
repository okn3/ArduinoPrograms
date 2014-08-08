int ledPin=9;
int senser=3;
int tmp=0;
int det = 0;

void setup ()
  {
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
  }

void loop()
  {
    int value;

    value = analogRead(senser);
//    Serial.println(value);
  if (tmp > 2 )
  {
    if (det < 10)
    {
      digitalWrite(ledPin,HIGH);
    }
    else {
      digitalWrite(ledPin,LOW);
    }
     Serial.println(det);
    tmp = 0;
    det = 0;
  }
    delay (300); //0.2秒
    tmp = tmp + 1;
    det = det + value;
   
  }
