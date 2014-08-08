#include <Ethernet.h>
#include <Dhcp.h>
#include <Twitter.h>

#include <string.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x11, 0x4B };
boolean ipAcquired = false;

int SEPNUM = 1024/5;
char msg[256];

void setup()
{
  Serial.begin(9600);
  //setupDHCP();
}

void setupDHCP()
{
  // GET IP Address!
  Serial.println("getting ip...");


  if(result == 1)
  {
    ipAcquired = true;

    byte buffer[6];
    Serial.println("ip acquired...");

    Dhcp.getMacAddress(buffer);
    Serial.print("mac address: ");
    printArray(&Serial, ":", buffer, 6, 16);

    Dhcp.getLocalIp(buffer);
    Serial.print("ip address: ");
    printArray(&Serial, ".", buffer, 4, 10);

    Dhcp.getSubnetMask(buffer);
    Serial.print("subnet mask: ");
    printArray(&Serial, ".", buffer, 4, 10);

    Dhcp.getGatewayIp(buffer);
    Serial.print("gateway ip: ");
    printArray(&Serial, ".", buffer, 4, 10);

    Dhcp.getDhcpServerIp(buffer);
    Serial.print("dhcp server ip: ");
    printArray(&Serial, ".", buffer, 4, 10);

    Dhcp.getDnsServerIp(buffer);
    Serial.print("dns server ip: ");
    printArray(&Serial, ".", buffer, 4, 10);

    delay(3000);

    Serial.println("connecting...");

  }
  else
    Serial.println("unable to acquire ip address...");

}

void printArray(Print *output, char* delimeter, byte* data, int len, int base)
{
  char buf[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for(int i = 0; i < len; i++)
  {
    if(i != 0)
      output->print(delimeter);

    output->print(itoa(data[i], buf, base));
  }

  output->println();
}

void loop()
{
  setupDHCP();

  Twitter twitter("YourID:Password");

  if(ipAcquired == false){
    delay(3000);
    return;
  }

  int val = analogRead(0);    // read the value from the sensor
  Serial.print("val:");
  Serial.print(val);
  Serial.print(" ");

  strcpy(msg,"[Arduino]部屋の明るさ:");
  char state[256];

  if(val < SEPNUM){
    sprintf(state,"暗い(val:%d)", val);
  }else if(val < SEPNUM*2){
    sprintf(state, "ちょっと暗い(val:%d)", val);
  }else if(val < SEPNUM*3){
    sprintf(state, "ちょっと明るい(val:%d)", val);
  }else if(val < SEPNUM*4){
    sprintf(state, "明るい(val:%d)", val);
  }else{
    sprintf(state, "かなり明るい(val:%d)", val);
  }

  strcat(msg, state);
  strcat(msg, " #Arduino");

  if (twitter.post(msg)) {
    int status = twitter.wait();
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }

  // wait 15min
  unsigned long waitTime = 60000UL*15UL;
  delay(waitTime);

}
