#include <dht11.h>
#include <I2CLiquidCrystal.h>
#include <Wire.h>
 
dht11 DHT11;
int val=0;

I2CLiquidCrystal lcd(20, (bool)true);

//tempright-setting-
float a_in_lm35;          // アナログ入力値(0〜203)
int a_in_cds;          // アナログ入力値
int temp_c = 0;  // 摂氏値( ℃ )
int dataCount=0; 
char trans[20];

int PinFlag;
char *json = &trans[0];

void HumidTemp(){
  int chk = DHT11.read(); 
  delay(100);
  int humi = (int)DHT11.humidity;
  int temp = (int)DHT11.temperature;
  //不快指数の計算
  float fukai = 0.81*temp+0.01*humi*(0.99*temp-14.3)+46.3;
  lcd.setCursor(0, 0);
  if(fukai>85){
    lcd.print(">_<; hot");
  }else if(fukai>80){
    lcd.print("~_~; hot");
  }else if(fukai>75){
    lcd.print("-_- hot");
  }else if(fukai>70){
    lcd.print("^-^ good");
  }else if(fukai>65){
    lcd.print("^o^ best");
  }else if(fukai>60){
    lcd.print("-_- good");
  }else if(fukai>55){
    lcd.print("~_~:cool");
  }else{
    lcd.print(">_<:cool");
  }
    

  // LCDに温度表示
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.print("c ");
    lcd.print(humi);
    lcd.print("%");
  sprintf(json, "\"humid\":%d,\"temp_weak\":%d,",(int)DHT11.humidity,(int)DHT11.temperature);
    Serial.print(json);
}

void TGS2450(){
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
    val-=2800;//調整
    if(val<0){
      val = 0;
    }
  //json
    sprintf(json, "\"gas\":%d,",val);
    Serial.print(json);
}

void cdsLM35(){
  char *json = &trans[0];
    // アナログピンから計測値を取得(0〜203)
    a_in_lm35 = analogRead(0);
    a_in_cds = analogRead(1);
    
    // 入力値を摂氏に換算
    temp_c = ((5 * a_in_lm35) / 1024) * 100;
    
    //jsonで書き出し
    sprintf(json, "\"temp\":%d,\"bright\":%d,",temp_c, a_in_cds);
    Serial.print(json);
}

void InterPin()
{
     PinFlag = 1;                         // 割込み有ればＯＮ
}

//デジタル変換しきい値超えたら反応
void SoundDetect(){
  if(PinFlag == 1) {
          digitalWrite(13,HIGH);          // LEDを点灯
          delay(1000);
          digitalWrite(13,LOW);
     }
    sprintf(json, "\"noise\":%d",PinFlag);
    Serial.print(json);
    PinFlag = 0;
}
//生データ
void SoundRaw(){
   sprintf(json, "\"noise\":%d",analogRead(5));
    Serial.print(json);
    delay(500);
}

void ledFlash(){
  digitalWrite(13,HIGH); 
  delay(50);
  digitalWrite(13,LOW);
}

//void monitorView(){
//  lcd.setCursor(0, 1);
//  lcd.print(a);
//}

void setup()
{
  DHT11.attach(A2); //デジタルでも可
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(13,OUTPUT) ;                  // 13番ピン付属LED出力
  attachInterrupt(0,InterPin, RISING) ; // ２番ピンの割込みを指定(立上がりで割込み)
  PinFlag = 0 ;
    // set up LCD
  lcd.begin(8, 2);
  lcd.print("monitor!");
}
 
void loop()
{
  Serial.print("{");
  TGS2450();
  cdsLM35();
  HumidTemp();
 SoundDetect();
//  SoundRaw();
  Serial.println("}");
  ledFlash();
  delay(500);
}


