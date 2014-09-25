/****************************
バイクの音を再現
arduino+ピエゾスピーカー

****************************/


//スピーカーのピンを９ピンにする
int speakerPin = 9;


void setup(){

  //スピーカーのピンを出力モードに  
  pinMode(speakerPin, OUTPUT);

  Serial.begin(9800);


}


void loop(){
   
int cnt = 0;
int hensoku = 0;
  for(int delayTime=600; delayTime>350; delayTime--){

    for(int i=0; i<10; i++){

      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(delayTime);

      digitalWrite(speakerPin, LOW);
      delayMicroseconds(delayTime);

    }
    
    cnt += 1;
    if (cnt == 130){
      delayTime+=180;
      hensoku += 1;
      cnt = 0; 
      if (hensoku == 4){
        delayTime=600;
        hensoku = 0;
      }
    }
    Serial.println(cnt);
  }
}


