焦電センサで人検知（成功）
[ ]http://d.hatena.ne.jp/futaya/20110610/1307699308 
→Detect_sensor
高精度バージョン
→Detect_sensor_hi_sens
ピエゾスピーカーで電子音を鳴らす（PL-P356）
→PlaySounds
人検知連携
→Detect_sound

[ ]サーボを可変抵抗で動かす→move_servo
可変抵抗の緑をA0につなぐ

[ ]人検知&サーボ→_furimuki
動作不安定

[ ]超音波距離センサで距離の取得（http://bit.ly/PRfrKn）（http://bit.ly/PRfsOt）
プログラム：_UltraSonic_Distance     
（配線）
    Gnd - Gnd
    Echo - D8
    Trig - D9
    Vcc - 3.3v

[応用プログラム]
                    _Distance_Sound：距離検知、距離で判断して音を鳴らす
                    _Distance_Move_Detect:動体検知っぽいやつ
                    _Distance_Move_Servo:動体検知でポテトヘッドか振り向く
