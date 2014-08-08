#include <SPI.h>
#include <Ethernet.h>
#include <Stewitter.h>

byte mac[] = { 
  0x90, 0xA2, 0xDA, 0x0D, 0x11, 0x4B };
Stewitter twitter("fc5095f75397aed37f3046180d67518d");
char msg[] = "Hello, World! I'm Arduino!";

void setup()
{
  delay(1000);

  Ethernet.begin(mac);

  Serial.begin(9600);
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    int status = twitter.wait();
    if (status == 200) {
      Serial.println(twitter.response());
    } 
    else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } 
  else {
    Serial.println("connection failed.");
  }
}

void loop()
{
}

