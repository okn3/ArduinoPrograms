/*

 LM35Dをつないで温度計

 LM35は最大で1.5V(150℃)の出力を出します。
 そんなに高温は必要ないのと、初期値のA/D分解能では
 精度がよろしくない（0.5℃きざみ）ので、
 arefの電圧を1Vぐらいになるように設定します。
 そうすると0.1度刻みにできるのでそこそこ高精度になります。
 

 抵抗分圧などで1Vぐらいにします。ただし、使用する抵抗は5kΩ以上にしてください。
 (リファレンスより）
 //例
 5V - 40kΩ -+-10kΩ- GND
 ************AREF*********

 
 */

const float vrefmV=664;//実測値。ミリボルト単位。各自変更してください。
const float vres=vrefmV/1024;//分解能。
const float mVper1dc=10;//10mV/1℃ここもICにあわせて変更してください。



void setup() {
  //シリアル通信の初期化
  Serial.begin(9600); 
  analogReference(EXTERNAL);

}
//渡されたアナログ値と１度あたり何ミリボルトかをもとに
//温度を計算
float analogValueToTemp(int analogValue,
float mvPer1dc)
{
  float temp=0;
  if(0<mvPer1dc)
  {
    return analogValue*vres/mvPer1dc;
  }
  else
  {
    return -1;
  }

}

float readTemp(int pinNo)
{
  int val=analogRead(pinNo);
  return analogValueToTemp(val,mVper1dc);
}

void loop() {
  int i=0;
  float total=0;
  float temp=0;
  
//センサ５個つけた場合。
for (i=0;i<5;i++)
  {
    temp=readTemp(i);
    Serial.print(temp);
    Serial.print(" ");
    total=total+temp;
  } 

  Serial.print(" average=");
  Serial.println(total/5);

  delay(1000);
}






