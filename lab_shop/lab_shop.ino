int item_num = 0;
char trans[20];
char *json = &trans[0];


void setup() {
  Serial.begin(9600);
     pinMode(2,INPUT) ;    //スイッチに接続ピンをデジタル入力に設定
     pinMode(3,INPUT) ; 
     pinMode(4,INPUT) ;    
     pinMode(22,OUTPUT) ;  //ＬＥＤに接続ピンをデジタル出力に設定
     pinMode(23,OUTPUT) ;
     pinMode(24,OUTPUT) ;
     pinMode(26,OUTPUT) ;  
     pinMode(31, OUTPUT);
}
void loop() {
     if (digitalRead(2) == HIGH) {
          item_num = 1;
          digitalWrite(22,HIGH);
          Sound();
          delay(1000);
          digitalWrite(22,LOW);
     }
     if (digitalRead(3) == HIGH) {
         item_num = 2;
         digitalWrite(24,HIGH) ;
          Sound();
          delay(1000);
          digitalWrite(24,LOW) ;
     }
     if (digitalRead(4) == HIGH) {
          item_num = 3;
          digitalWrite(26,HIGH) ;
          Sound();
          delay(1000);
          digitalWrite(26,LOW) ;
     }
     if (item_num != 0){
       sprintf(json, "{\"item\":%d}", item_num);
      Serial.println(json);
     }
     Standby();
     item_num = 0;

}

void Sound(){
            for(int i=0;i<1000;i++){
            digitalWrite(31, HIGH);
            delayMicroseconds(100);
            digitalWrite(31, LOW);
            delayMicroseconds(100);
          }
}

void Standby(){
     digitalWrite(23,HIGH);
     delay(100);
     digitalWrite(23,LOW);
     delay(10);
}
