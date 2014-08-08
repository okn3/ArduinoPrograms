int ledPin=9;
int senser=3;
void setup ()
{
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}
void loop()
{

int value;
value = analogRead(senser);
Serial.println(value);

if (value < 10)
{
digitalWrite(ledPin,HIGH);
}
else {
digitalWrite(ledPin,LOW);
}
delay (200); //0.2秒
}

