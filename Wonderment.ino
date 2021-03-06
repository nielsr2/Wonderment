#include <Audio.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
  #include <CapacitiveSensor.h>

#include "chords.h"

// **********************************************************************


// GUItool: begin automatically generated code
AudioSynthKarplusStrong string1;         //xy=829,379
AudioSynthKarplusStrong string2;         //xy=840,456
AudioSynthKarplusStrong string3;         //xy=841,497
AudioSynthKarplusStrong string4;         //xy=843,542
AudioSynthKarplusStrong string5;         //xy=847,593
AudioSynthKarplusStrong string7;         //xy=848,696
AudioSynthKarplusStrong string6;         //xy=852,629
AudioSynthKarplusStrong string8;         //xy=855,724
AudioSynthKarplusStrong string9;         //xy=899,778
AudioSynthKarplusStrong string10;        //xy=907,847
AudioSynthKarplusStrong string11;        //xy=933,912
AudioSynthKarplusStrong string12;        //xy=971,967
AudioEffectBitcrusher bitcrusher6;       //xy=1027,689
AudioEffectBitcrusher bitcrusher4;       //xy=1038,771
AudioEffectBitcrusher bitcrusher5;       //xy=1047,733
AudioEffectBitcrusher bitcrusher3;       //xy=1072,844
AudioMixer4 mixer1;                      //xy=1075,586
AudioEffectBitcrusher bitcrusher2;       //xy=1083,911
AudioEffectBitcrusher bitcrusher1;       //xy=1109,969
AudioMixer4 mixer2;                      //xy=1217,617
AudioSynthSimpleDrum drum1;              //xy=1290,408
AudioMixer4 mixer3;                      //xy=1305,721
AudioMixer4 mixer4;                      //xy=1468,718
AudioMixer4 mixer5;                      //xy=1558,625
AudioOutputI2S i2s1;                     //xy=1671,538
AudioConnection patchCord1(string1, 0, mixer1, 0);
AudioConnection patchCord2(string2, 0, mixer1, 1);
AudioConnection patchCord3(string3, 0, mixer1, 2);
AudioConnection patchCord4(string4, 0, mixer1, 3);
AudioConnection patchCord5(string5, 0, mixer2, 1);
AudioConnection patchCord6(string7, bitcrusher6);
AudioConnection patchCord7(string6, 0, mixer2, 2);
AudioConnection patchCord8(string8, bitcrusher5);
AudioConnection patchCord9(string9, bitcrusher4);
AudioConnection patchCord10(string10, bitcrusher3);
AudioConnection patchCord11(string11, bitcrusher2);
AudioConnection patchCord12(string12, bitcrusher1);
AudioConnection patchCord13(bitcrusher6, 0, mixer3, 0);
AudioConnection patchCord14(bitcrusher4, 0, mixer3, 2);
AudioConnection patchCord15(bitcrusher5, 0, mixer3, 1);
AudioConnection patchCord16(bitcrusher3, 0, mixer3, 3);
AudioConnection patchCord17(mixer1, 0, mixer2, 0);
AudioConnection patchCord18(bitcrusher2, 0, mixer4, 1);
AudioConnection patchCord19(bitcrusher1, 0, mixer4, 2);
AudioConnection patchCord20(mixer2, 0, mixer5, 2);
AudioConnection patchCord21(drum1, 0, mixer5, 0);
AudioConnection patchCord22(mixer3, 0, mixer4, 0);
AudioConnection patchCord23(mixer4, 0, mixer5, 3);
AudioConnection patchCord24(mixer5, 0, i2s1, 1);
AudioConnection patchCord25(mixer5, 0, i2s1, 0);
AudioControlSGTL5000 sgtl5000_1;         //xy=1056,411
// GUItool: end automatically generated code

// **********************************************************************

// #include <Audio.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>

// GUItool: begin automatically generated code
// AudioSynthKarplusStrong string1;         //xy=147,50
// AudioSynthKarplusStrong string2;         //xy=158,127
// AudioSynthKarplusStrong string3;         //xy=159,168
// AudioSynthKarplusStrong string4;         //xy=161,213
// AudioSynthKarplusStrong string5;         //xy=165,264
// AudioSynthKarplusStrong string7;         //xy=166,367
// AudioSynthKarplusStrong string6;         //xy=170,300
// AudioSynthKarplusStrong string8;         //xy=173,395
// AudioSynthKarplusStrong string9;         //xy=217,449
// AudioSynthKarplusStrong string10;        //xy=225,518
// AudioSynthKarplusStrong string11;        //xy=251,583
// AudioSynthKarplusStrong string12;        //xy=289,638
// AudioEffectBitcrusher bitcrusher6;       //xy=345,360
// AudioEffectBitcrusher bitcrusher4;       //xy=356,442
// AudioEffectBitcrusher bitcrusher5;       //xy=365,404
// AudioEffectBitcrusher bitcrusher3;       //xy=390,515
// AudioMixer4 mixer1;                      //xy=393,257
// AudioEffectBitcrusher bitcrusher2;       //xy=401,582
// AudioEffectBitcrusher bitcrusher1;       //xy=427,640
// AudioMixer4 mixer2;                      //xy=535,288
// AudioMixer4 mixer3;                      //xy=623,392
// AudioMixer4 mixer4;                      //xy=786,389
// AudioMixer4 mixer5;                      //xy=876,296
// AudioOutputI2S i2s1;                     //xy=989,209
// AudioConnection patchCord1(string1, 0, mixer1, 0);
// AudioConnection patchCord2(string2, 0, mixer1, 1);
// AudioConnection patchCord3(string3, 0, mixer1, 2);
// AudioConnection patchCord4(string4, 0, mixer1, 3);
// AudioConnection patchCord5(string5, 0, mixer2, 1);
// AudioConnection patchCord6(string7, bitcrusher6);
// AudioConnection patchCord7(string6, 0, mixer2, 2);
// AudioConnection patchCord8(string8, bitcrusher5);
// AudioConnection patchCord9(string9, bitcrusher4);
// AudioConnection patchCord10(string10, bitcrusher3);
// AudioConnection patchCord11(string11, bitcrusher2);
// AudioConnection patchCord12(string12, bitcrusher1);
// AudioConnection patchCord13(bitcrusher6, 0, mixer3, 0);
// AudioConnection patchCord14(bitcrusher4, 0, mixer3, 2);
// AudioConnection patchCord15(bitcrusher5, 0, mixer3, 1);
// AudioConnection patchCord16(bitcrusher3, 0, mixer3, 3);
// AudioConnection patchCord17(mixer1, 0, mixer2, 0);
// AudioConnection patchCord18(bitcrusher2, 0, mixer4, 1);
// AudioConnection patchCord19(bitcrusher1, 0, mixer4, 2);
// AudioConnection patchCord20(mixer2, 0, mixer5, 2);
// AudioConnection patchCord21(mixer3, 0, mixer4, 0);
// AudioConnection patchCord22(mixer4, 0, mixer5, 3);
// AudioConnection patchCord23(mixer5, 0, i2s1, 1);
// AudioConnection patchCord24(mixer5, 0, i2s1, 0);
// AudioControlSGTL5000 sgtl5000_1;         //xy=374,82
// GUItool: end automatically generated code

// **********************************************************************





// Special thanks to Matthew Rahtz - http://amid.fish/karplus-strong/

// AudioSynthKarplusStrong string1;
// AudioSynthKarplusStrong string2;
// AudioSynthKarplusStrong string3;
// AudioSynthKarplusStrong string4;
// AudioSynthKarplusStrong string5;
// AudioSynthKarplusStrong string6;
// AudioMixer4 mixer1;
// AudioMixer4 mixer2;
// AudioOutputI2S i2s1;
// AudioConnection patchCord1(string1, 0, mixer1, 0);
// AudioConnection patchCord2(string2, 0, mixer1, 1);
// AudioConnection patchCord3(string3, 0, mixer1, 2);
// AudioConnection patchCord4(string4, 0, mixer1, 3);
// AudioConnection patchCord5(mixer1, 0, mixer2, 0);
// AudioConnection patchCord6(string5, 0, mixer2, 1);
// AudioConnection patchCord7(string6, 0, mixer2, 2);
// AudioConnection patchCord8(mixer2, 0, i2s1, 0);
// AudioConnection patchCord9(mixer2, 0, i2s1, 1);
//
// AudioControlSGTL5000 sgtl5000_1;
const int finger_delay = 5;
const int hand_delay = 200;

int chordnum=0;
int sampleSizeForCapacitiveSensor = 1;

CapacitiveSensor button1 = CapacitiveSensor(0, 1);
CapacitiveSensor button2 = CapacitiveSensor(2, 3);
CapacitiveSensor button3 = CapacitiveSensor(4, 5);
CapacitiveSensor button4 = CapacitiveSensor(22,17);
// CapacitiveSensor button5 = CapacitiveSensor(3, 2);


int x,y,z;
int combi, coolNumber2;

int down,up, mid;

// **********************************************************************
// pins
int accelorometerPinX = 14;
int accelorometerPinZ = 15;
int accelorometerPinY = 16;

void setup() {
        AudioMemory(15);
        sgtl5000_1.enable();
        sgtl5000_1.volume(0.6);
        mixer1.gain(0, 0.60);
        mixer1.gain(1, 0.60);
        mixer1.gain(2, 0.60);
        mixer1.gain(3, 0.60);
        mixer2.gain(1, 0.60);
        mixer2.gain(2, 0.60);
        mixer3.gain(1, 0.60);
        mixer3.gain(2, 0.60);
        bitcrusher6.bits(3);
        bitcrusher6.sampleRate(44100/5);

        bitcrusher5.bits(3);
        bitcrusher5.sampleRate(44100/5);

        bitcrusher4.bits(3);
        bitcrusher4.sampleRate(44100/5);

        bitcrusher3.bits(3);
        bitcrusher3.sampleRate(44100/5);

        bitcrusher2.bits(3);
        bitcrusher2.sampleRate(44100/5);

        bitcrusher1.bits(3);
        bitcrusher1.sampleRate(44100/5);

        // x =
        // z = ;
        y = analogRead(accelorometerPinY);
        // combi = sqrt(pow(analogRead(accelorometerPinX),2) + pow(analogRead(accelorometerPinY),2) + pow(analogRead(accelorometerPinZ),2));
        combi = y;
        down = combi * 1.15;
        up = combi * 0.85;
        mid = combi;
        delay(700);
}

// void strum_up(const float *chord, float velocity);
// void strum_dn(const float *chord, float velocity);



boolean crossedMid = true;
boolean direction = true; // direction up = true, down = false
boolean played = false;
boolean tap2play = false;
boolean im = false;
boolean fast = false;

long b1,b2,b3,b4;

int avgbufLen = 20;
int avgbuf[20];
int count = 0;
int avg;


const float *chord;




void strum_up(const float *chord, float velocity)
{
        if (chord[0] > 20.0) string6.noteOn(chord[0], velocity);
        delay(finger_delay);
        if (chord[1] > 20.0) string7.noteOn(chord[1], velocity);
        delay(finger_delay);
        if (chord[2] > 20.0) string8.noteOn(chord[2], velocity);
        delay(finger_delay);
        if (chord[3] > 20.0) string9.noteOn(chord[3], velocity);
        delay(finger_delay);
        if (chord[4] > 20.0) string10.noteOn(chord[4], velocity);
        delay(finger_delay);
        if (chord[5] > 20.0) string12.noteOn(chord[5], velocity);
        delay(finger_delay);
}

void strum_dn(const float *chord, float velocity)
{
        if (chord[5] > 20.0) string1.noteOn(chord[5], velocity);
        delay(finger_delay);
        if (chord[4] > 20.0) string2.noteOn(chord[4], velocity);
        delay(finger_delay);
        if (chord[3] > 20.0) string3.noteOn(chord[3], velocity);
        delay(finger_delay);
        if (chord[2] > 20.0) string4.noteOn(chord[2], velocity);
        delay(finger_delay);
        if (chord[1] > 20.0) string5.noteOn(chord[1], velocity);
        delay(finger_delay);
        if (chord[0] > 20.0) string6.noteOn(chord[0], velocity);
        delay(finger_delay);
}


void strum_power(const float *chord, float velocity)
{
        if (chord[0] > 20.0) string6.noteOn(chord[0], velocity);
        delay(finger_delay);
        if (chord[1] > 20.0) string7.noteOn(chord[1], velocity);
        delay(finger_delay);
        if (chord[2] > 20.0) string8.noteOn(chord[2], velocity);
        delay(finger_delay);
        if (chord[3] > 20.0) string9.noteOn(chord[3], velocity);
        delay(finger_delay);
        if (chord[4] > 20.0) string10.noteOn(chord[4], velocity);
        delay(finger_delay);
        if (chord[5] > 20.0) string11.noteOn(chord[5], velocity);
        delay(finger_delay);

}


// int diffStrum;
// void play() {
//         if (im)
//                 strum_power(chord, 1.);
//         else{
//                 if (diffStrum % 2)
//                         strum_dn(chord, 1.);
//                 else
//                         strum_up(chord, 1.);
//         }
// }


void loop() {



        // **********************************************************************
        // read acc. values
        x = analogRead(accelorometerPinX);
        z = analogRead(accelorometerPinZ);
        y = analogRead(accelorometerPinY);
        // combi = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        combi = y;

        // mid = combi;
        // Serial.printf("x=   %d, y=%d, z=%d", x, y, z);
        // Serial.printf("combi is  %d, D=%d, M=%d U=%d, CHORD= %d", combi, down, mid, up, chord);
        // Serial.println();
        // count = count % bLength;
        // count = (count % avgbufLen);
        // avgbuf[count] = combi;
        // count++;
        // int sum = 0;
        // for (int i = 0; i < avgbufLen; i++) {
        //         sum = sum + avgbuf[i];
        // }
        // avg = sum/avgbufLen;
        // Serial.println(avg);
        // if ()
//         380	576	404	303	342
// 300	428	552	538	504
// 560	462	463	329	570
// 557	570	315	545	353
// 349	373	302	486	515
// 396	416	379	325	340
// 487	372	448	414	493
// 369	307	452	560	495
        // **********************************************************************
        // GET BUTTON SENSORS
        b4 =  button1.capacitiveSensor(sampleSizeForCapacitiveSensor);
        b3 =  button2.capacitiveSensor(sampleSizeForCapacitiveSensor);
        b2 =  button3.capacitiveSensor(sampleSizeForCapacitiveSensor);
        b1 =  button4.capacitiveSensor(sampleSizeForCapacitiveSensor);
        Serial.printf("%d, %d, %d, %d ", b1, b2, b3,b4);
        Serial.println();

        // **********************************************************************
        // IF BUTTONS
        // b1 & b2 & b3 & b4 - swap mode
        if (b1 > 80 && b2 > 80 && b3 > 80 && b4 > 80) {
                drum1.frequency(60);
                drum1.length(300);
                drum1.secondMix(0.0);
                drum1.pitchMod(1.0);
                drum1.noteOn();
                if (im) {
                        im = false;
                }
                else {
                        im = true;
                        Serial.println("SWITCHED MODE :");
                        Serial.println(im);
                }
                delay(200);
        }
        // b2 & b3
        else if (b2 > 80 && b3 > 80) {
                fast = false;
                if (im)
                        chord = Bpow; // IM 1st chord
                else
                        chord = Dsus42; // WW 2nd chord

                if (tap2play)
                { strum_dn(chord, 1.0);
                  delay(hand_delay);}

                // powerDOWN(chord, 1.);

                Serial.println("b2b3");
        }
        else if (b3 > 80 && b4 > 80) {
                fast = true;
                if (im)
                        chord = Gpow; // IM 1st chord
                else
                        chord = A7sus42; // WW 2nd chord

                if (tap2play)
                { strum_dn(chord, 1.0);
                  delay(hand_delay);}

                // powerDOWN(chord, 1.);

                Serial.println("b3 b4");
        }
        // b1
        // b1 & b2
        else if (b1 > 80 && b2 > 80) {
                fast = false;
                if (im)
                        chord = Epow; // IM 1st chord
                // else
                // chord = Bpow; // WW 2nd chord

                if (tap2play)
                { strum_dn(chord, 1.0);
                  delay(hand_delay);}

                // powerDOWN(chord, 1.);

                Serial.println("b1b2");
        }
        // b1
        else if (b1 > 80 ) {
                fast = false;
                if (im)
                        chord = Bpow; // IM 2nd chord
                else
                        chord = em7; // WW 1nd Chord

                if (tap2play)
                { strum_dn(chord, 1.0);
                  delay(hand_delay);}

                // chord = em7;
                // powerDOWN(chord, 1.);
                // strum_dn(chord, 1.0);
                // delay(hand_delay);
                Serial.println("b1");
        }
        // b2
        else if (b2 > 80) {
                fast = false;
                if (im)
                        chord = Dpow; // IM 3rd chord
                else
                        chord = Gmajor; // WW 2nd Chord


                if (tap2play)
                { strum_dn(chord, 1.0);
                  delay(hand_delay);}

                // chord = Gmajor;
                // strum_dn(chord, 1.0);
                // delay(hand_delay);
                Serial.println("b2");

        }
        // b3
        else if (b3 > 80) {
                fast = true;
                if (im)
                        chord = Fspow; // IM 4th chord
                else
                        chord = Dsus4; // WW 3rd Chord


                if (tap2play)
                { strum_dn(chord, 1.0);
                  delay(hand_delay);}
                // strum_dn(chord, 1.0);
                // delay(hand_delay);
                Serial.println("b3");

        }
        // b4
        else if (b4 > 80) {
                fast = true;
                if (im)
                        chord = Gpow; // IM 4th chord
                else
                        chord = A7sus4; // WW 4th Chord


                if (tap2play)
                { strum_dn(chord, 1.0);
                  delay(hand_delay);}
                // strum_dn(chord, 1.0);
                // delay(hand_delay);
                Serial.println("b4");
                //
        }
        // **********************************************************************
        // delay(10);



        // Serial.printf(" : combi is is %d, D=%d, M=%d U=%d,  x is %d, z is %d", combi, down, mid, up);
        // if (played) {
        //         Serial.println("WAITING FOR RESET" + direction);
        //         // Serial.printf("WIATING FOR RESET : combi is is %d, D=%d, M=%d U=%d,  x is %d, z is %d", combi, down, mid, up);
        //         // Serial.println();
        //         if (direction) {
        //                 if (combi > mid) {
        //                         played = false;
        //                         // Serial.println("pLAYED SET TO FALSE");
        //
        //                 }
        //         }
        //         else {
        //                 if (combi < mid) {
        //                         played = false;
        //                         // Serial.println("pLAYED SET TO FALSE");
        //
        //                 }
        //         }
        // }
        // else {
        if (combi > down ) {
                // Serial.println();
                Serial.println("UP");
                // Serial.printf("x is %d, D=%d, M=%d U=%d,  y is %d, z is %d", x, yDown, yMid, yUp, y,z );
                // Serial.println();
                direction = false;
                if (im) {
                        strum_power(chord, 1.0);
                        if (fast) {
                                delay(256);
                        }
                        else
                                delay(400);
                }
                else{
                        strum_dn(chord, 1.0);
                        delay(hand_delay);
                }

                // delay(hand_delay);
                // played = true;
        }
        // else if (combi < up ) {
        //         // Serial.println();
        //         Serial.println("DOWNN");
        //         // Serial.printf("x is %d, D=%d, M=%d U=%d,  y is %d, z is %d", x, yDown, yMid, yUp, y,z );
        //         // Serial.println();
        //         if (im)
        //                 strum_power(chord, 1.0);
        //         else
        //                 strum_dn(chord, 1.0);
        //         direction = true;
        //         delay(hand_delay);
        //         delay(hand_delay);
        //         // played = true;
        // }
        // }
        // Serial.print("Max CPU Usage = ");
        // Serial.print(AudioProcessorUsageMax(), 1);
        // Serial.println("%");

        // **********************************************************************
        // // play stuff
        // if (avg > 612)
        // {
        //         strum_dn(chord, 1.0);
        //         delay(hand_delay);
        // }
        // else if (avg < 412) {
        //         strum_up(chord, 1.0);
        //         delay(hand_delay);
        // }
}
