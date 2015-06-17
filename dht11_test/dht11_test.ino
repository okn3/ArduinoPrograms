#include <dht11.h>

dht11 DHT11;

void setup()
{
  DHT11.attach(A2); //デジタルでも可
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
}

void loop()
{
  Serial.println("\n");

  int chk = DHT11.read();

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case 0: Serial.println("OK"); break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((int)DHT11.humidity, DEC);

  Serial.print("Temperature (C): ");
  Serial.println((int)DHT11.temperature, DEC);

  delay(2000);
}
