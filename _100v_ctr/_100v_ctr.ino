const int ssrPin = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(ssrPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(ssrPin, HIGH);
  delay(5000);
  digitalWrite(ssrPin, LOW);
  delay(5000);  
}
