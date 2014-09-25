#define NOTE_A 440
#define NOTE_B 493
#define NOTE_Cis 554
#define NOTE_D 587
#define NOTE_E 659
#define NOTE_Fis 739
#define NOTE_Gis 830
#define NOTE_A2 880

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.625

// notes in the melody:
int tune[] =
{
    NOTE_Fis, NOTE_D, NOTE_A, NOTE_D, NOTE_E, NOTE_A2,
    NOTE_E, NOTE_Fis, NOTE_E, NOTE_A, NOTE_D
};                                    
/* note durations: 1 = one note*/

float duration[]=
{1,1,1,1,1,3,
 1,1,1,1,4};
int length;   
int tonePin=11;                // buzzer pin
void setup()
{ Serial.begin(9600);
    pinMode(tonePin,OUTPUT);   //  initialize the digital pin as an output
    length = sizeof(tune)/sizeof(tune[0]);
}
void loop()
{
    for(int x=0;x<length;x++)
    {tone(tonePin,tune[x]);
        delay(300*duration[(x%100)]);    // to distinguish the notes, set a minimum time between them.

        noTone(tonePin); // stop the tone playing:
    }
}
