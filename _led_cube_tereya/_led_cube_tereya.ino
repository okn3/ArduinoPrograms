//LEDキューブと超音波距離センサの連携

/*距離センサの設定*/
#define TRIGPIN 12
#define ECHOPIN 13
#define CTM 19

int dur;
float dis;
  
/* led num */
int ledNum = 3;

/* pins for gnd */
int gnd[3] = {0, 1, 2};

/* pins for vs */
int vs1[3] = {3, 4, 5};
int vs2[3] = {6, 7, 8};
int vs3[3] = {9, 10, 11};
int vs[3][3] = {
  {vs1[0],vs1[1],vs1[2]},
  {vs2[0],vs2[1],vs2[2]},
  {vs3[0],vs3[1],vs3[2]}
};

/* blink per second */
int bps = 3;

/* flame per second */
int fps = 100;

/* 乱数の設定 */
long rand1;
long rand2;
long randGND;


void setup() {
  
  Serial.begin(9600);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
  
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      pinMode(vs[i][j], OUTPUT);
    }
    pinMode(gnd[i], OUTPUT);
  }

}

//パターンの選択
void loop() {
  sensing();
//  if (dis < 10 ){
//      pattern3(); //階段
//  }else if(dis >= 10 && dis < 30){
//      pattern2(); //ぐるぐる
//  }else{
//  pattern4();
//  }
    
 //  pattern1(); // ピカピカ
//   pattern2(); //ぐるぐる
 //  pattern3(); //階段
pattern4(); //ランダム
//   pattern5(); //自作
}

void pattern1() {
  all();

  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[2], HIGH);
  delay(fps);
  digitalWrite(gnd[1], LOW);
  digitalWrite(gnd[0], HIGH);
  delay(fps);
  digitalWrite(gnd[2], LOW);
  digitalWrite(gnd[1], HIGH);
  delay(fps);
}

void pattern2() {
  cls();

  for(int i=2; i>=0; i--){
    if(i == 2){
      digitalWrite(gnd[i], LOW);
    }else{
      digitalWrite(gnd[i+1], HIGH);
      digitalWrite(gnd[i], LOW);
    }

    digitalWrite(vs[2][2], HIGH);
    delay(fps);

    digitalWrite(vs[2][2], LOW);
    digitalWrite(vs[2][1], HIGH);
    delay(fps);

    digitalWrite(vs[2][1], LOW);
    digitalWrite(vs[2][0], HIGH);
    delay(fps);

    digitalWrite(vs[2][0], LOW);
    digitalWrite(vs[1][0], HIGH);
    delay(fps);

    digitalWrite(vs[1][0], LOW);
    digitalWrite(vs[0][0], HIGH);
    delay(fps);

    digitalWrite(vs[0][0], LOW);
    digitalWrite(vs[0][1], HIGH);
    delay(fps);

    digitalWrite(vs[0][1], LOW);
    digitalWrite(vs[0][2], HIGH);
    delay(fps);


    digitalWrite(vs[0][2], LOW);
    digitalWrite(vs[1][2], HIGH);
    delay(fps);

    digitalWrite(vs[1][2], LOW);
  }
}

void pattern3() {
  all();

  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[2], HIGH);
  digitalWrite(gnd[1], HIGH);
  delay(500);
  digitalWrite(gnd[1], LOW);
  digitalWrite(gnd[0], HIGH);
  delay(500);
  digitalWrite(gnd[2], LOW);
  digitalWrite(gnd[1], HIGH);
  delay(500);  
//  digitalWrite(gnd[2], HIGH);
//  delay(500);
//  digitalWrite(gnd[2], LOW);
//  delay(500);
  digitalWrite(gnd[1], LOW);
  digitalWrite(gnd[2], HIGH);
  delay(500);
  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[1], HIGH);
//  delay(500);
//  digitalWrite(gnd[0], HIGH);
//  delay(500);
}

//ランダムで光らす
void pattern4() {
  randGND=random(3);
  rand1=random(3);
  rand2=random(3);
  
  cls();

    digitalWrite(gnd[randGND], LOW);

    digitalWrite(vs[rand1][rand2], HIGH);
    delay(dis);
    digitalWrite(vs[rand1][rand2], LOW);
    delay(dis+100);
}

//近づいたら早くする
void pattern5() {
  cls();

  for(int i=2; i>=0; i--){
    if(i == 2){
      digitalWrite(gnd[i], LOW);
    }else{
      digitalWrite(gnd[i+1], HIGH);
      digitalWrite(gnd[i], LOW);
    }

    digitalWrite(vs[2][2], HIGH);
    delay(fps);

    digitalWrite(vs[2][2], LOW);
    digitalWrite(vs[2][1], HIGH);
    delay(fps);

    digitalWrite(vs[2][1], LOW);
    digitalWrite(vs[2][0], HIGH);
    delay(fps);

    digitalWrite(vs[2][0], LOW);
    digitalWrite(vs[1][0], HIGH);
    delay(fps);

    digitalWrite(vs[1][0], LOW);
    digitalWrite(vs[0][0], HIGH);
    delay(fps);

    digitalWrite(vs[0][0], LOW);
    digitalWrite(vs[0][1], HIGH);
    delay(fps);

    digitalWrite(vs[0][1], LOW);
    digitalWrite(vs[0][2], HIGH);
    delay(fps);


    digitalWrite(vs[0][2], LOW);
    digitalWrite(vs[1][2], HIGH);
    delay(fps);

    digitalWrite(vs[1][2], LOW);
  }
}




void all() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      digitalWrite(vs[i][j], HIGH);
    }
    digitalWrite(gnd[i], LOW);
  }
}

void cls() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      digitalWrite(vs[i][j], LOW);
    }
    digitalWrite(gnd[i], HIGH);
  }
}
void sensing(){

  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(CTM);
  digitalWrite(TRIGPIN,LOW);
  dur = pulseIn(ECHOPIN,HIGH);
  dis = (float) dur*0.017;
//  Serial.print(dis);
//  Serial.println("cm");
  
  if (dis <= 100){
    dis = map(dis,0,100,10,200);
    Serial.println(dis);
  }else{
    dis = 300;
  }
//  delay(500);
}
