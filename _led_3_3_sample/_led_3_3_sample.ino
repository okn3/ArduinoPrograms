/*
 * LEDCude
 * created_at:2014_04_14_01:17:05.
 * Last Change:2014_04_22_23:36:42.
 */

// 各pinの設定.定義後配列化しておく
int BASE_0 = 0;
int BASE_1 = 1;
int BASE_2 =  2;
int LED_0  =  3;
int LED_1  =  4;
int LED_2  =  5;
int LED_3  =  6;
int LED_4  =  7;
int LED_5  =  8;
int LED_6  =  9;
int LED_7  = 10;
int LED_8  = 11;
int BASE_LIST[3] = {BASE_0,BASE_1,BASE_2};
int LED_LIST[9] = {LED_0,LED_1,LED_2,LED_3,LED_4,LED_5,LED_6,LED_7,LED_8};

// LEDキューブの状態.HIGH or LOWを格納
int led_state[3][3][3];
int LED_NUM = 27;

int COUNT_MAX = 30;
int count = 0;

void setup(){
    // 各pinのIN/OUT設定
    pinMode(BASE_0,OUTPUT);
    pinMode(BASE_1,OUTPUT);
    pinMode(BASE_2,OUTPUT);
    pinMode(LED_0 ,OUTPUT);
    pinMode(LED_1 ,OUTPUT);
    pinMode(LED_2 ,OUTPUT);
    pinMode(LED_3 ,OUTPUT);
    pinMode(LED_4 ,OUTPUT);
    pinMode(LED_5 ,OUTPUT);
    pinMode(LED_6 ,OUTPUT);
    pinMode(LED_7 ,OUTPUT);
    pinMode(LED_8 ,OUTPUT);

    // LEDキューブの状態初期化
    int i=0,j=0,k=0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
                led_state[i][j][k] = LOW;
            }
        }
    }
    randomSeed(analogRead(0));
}

// openFrameworks風にループ内を分割
void loop(){
    update();
    action();
}

// 状態の更新
void update(){
    if(count >= COUNT_MAX){
        // ランダムに状態変化
        led_toggle(random(LED_NUM));
        count = 0;
    } else {
        count++;
    }
 }

// 状態の反映
void action(){
    blink_cube();
}

// **今回のポイント**
// LEDキューブをダイナミック点灯
void blink_cube(){
    int i=0,j=0,k=0;
    for(i=0; i<3; i++){
        // i番目の段以外はHIGH
        digitalWrite(BASE_0,HIGH);
        digitalWrite(BASE_1,HIGH);
        digitalWrite(BASE_2,HIGH);
        digitalWrite(BASE_LIST[i],LOW);
        
        // 同一段内の9つのLEDを制御
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
                digitalWrite(LED_LIST[j+k*3], led_state[i][j][k]);
            }
        }
        // 気持ち程度delay.なくてもok
        delay(2);
    }
}

// 指定番号のLEDの状態をトグル
void led_toggle(int num){
    int i,j,k;
    i = num / 9;
    j = (num % 9) / 3;
    k = num % 3;
    if(led_state[i][j][k] == HIGH){
        led_state[i][j][k] = LOW;
    } else {
        led_state[i][j][k] = HIGH;
    }
}
