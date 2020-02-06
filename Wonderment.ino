#include <Audio.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>

#include "chords.h"
// **********************************************************************


// GUItool: begin automatically generated code
// AudioSynthKarplusStrong  string7;        //xy=294,456
// AudioSynthKarplusStrong  string9;        //xy=323,556
// AudioSynthKarplusStrong  string8;        //xy=325,502
// AudioSynthKarplusStrong  string10;       //xy=350,611
// AudioSynthKarplusStrong  string11;       //xy=387,669
// AudioSynthKarplusStrong  string12;       //xy=429,731
// AudioEffectBitcrusher    bitcrusher1;    //xy=521,431
// AudioEffectBitcrusher    bitcrusher2;    //xy=549,463
// AudioEffectBitcrusher    bitcrusher3;    //xy=578,504
// AudioMixer4              mixer3;         //xy=612,344
// AudioEffectBitcrusher    bitcrusher4;    //xy=621,545
// AudioEffectBitcrusher    bitcrusher5;    //xy=657,574
// AudioEffectBitcrusher    bitcrusher6;    //xy=700,609
// AudioMixer4              mixer4;         //xy=756,434
// AudioOutputI2S           i2s2;           //xy=840,275
// AudioConnection          patchCord12(string7, bitcrusher1);
// AudioConnection          patchCord22(string9, bitcrusher3);
// AudioConnection          patchCord32(string8, bitcrusher2);
// AudioConnection          patchCord42(string10, bitcrusher4);
// AudioConnection          patchCord52(string11, bitcrusher5);
// AudioConnection          patchCord62(string12, bitcrusher6);
// AudioConnection          patchCord72(bitcrusher1, 0, mixer3, 0);
// AudioConnection          patchCord82(bitcrusher2, 0, mixer3, 1);
// AudioConnection          patchCord92(bitcrusher3, 0, mixer3, 2);
// AudioConnection          patchCord102(mixer3, 0, mixer4, 0);
// AudioConnection          patchCord112(bitcrusher4, 0, mixer3, 3);
// AudioConnection          patchCord122(bitcrusher5, 0, mixer4, 1);
// AudioConnection          patchCord132(bitcrusher6, 0, mixer4, 3);
// AudioConnection          patchCord142(mixer4, 0, i2s2, 0);
// AudioConnection          patchCord152(mixer4, 0, i2s2, 1);
// AudioControlSGTL5000     sgtl5000_1;     //xy=1023,236
// GUItool: end automatically generated code
// **********************************************************************





// Special thanks to Matthew Rahtz - http://amid.fish/karplus-strong/

AudioSynthKarplusStrong string1;
AudioSynthKarplusStrong string2;
AudioSynthKarplusStrong string3;
AudioSynthKarplusStrong string4;
AudioSynthKarplusStrong string5;
AudioSynthKarplusStrong string6;
AudioMixer4 mixer1;
AudioMixer4 mixer2;
AudioOutputI2S i2s1;
AudioConnection patchCord1(string1, 0, mixer1, 0);
AudioConnection patchCord2(string2, 0, mixer1, 1);
AudioConnection patchCord3(string3, 0, mixer1, 2);
AudioConnection patchCord4(string4, 0, mixer1, 3);
AudioConnection patchCord5(mixer1, 0, mixer2, 0);
AudioConnection patchCord6(string5, 0, mixer2, 1);
AudioConnection patchCord7(string6, 0, mixer2, 2);
AudioConnection patchCord8(mixer2, 0, i2s1, 0);
AudioConnection patchCord9(mixer2, 0, i2s1, 1);
// AudioEffectBitcrusher bitcrusher1, bitcrusher2, bitcrusher3, bitcrusher4, bitcrusher5, bitcrusher6;       //xy=631,269
AudioControlSGTL5000 sgtl5000_1;
// AudioConnection          patchCord10(bitcrusher1, 0, mixer2, 3);
// AudioConnection          patchCord3(string6, bitcrusher1);
const int finger_delay = 5;
const int hand_delay = 100;

int chordnum=0;


int x,y,z;
int coolNumber;
int yDown, yUp, yMid;
void setup() {
        AudioMemory(15);
        sgtl5000_1.enable();
        sgtl5000_1.volume(0.6);
        mixer1.gain(0, 0.15);
        mixer1.gain(1, 0.15);
        mixer1.gain(2, 0.15);
        mixer1.gain(3, 0.15);
        mixer2.gain(1, 0.15);
        mixer2.gain(2, 0.15);
        delay(700);
        x = analogRead(14);
        z = analogRead(15);
        y = analogRead(16);
        coolNumber = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        yDown = coolNumber * 1.1;
        yUp =   coolNumber * 0.9;
        yMid =  coolNumber;
}

void strum_up(const float *chord, float velocity);
void strum_dn(const float *chord, float velocity);


int yList[10];
int counter;

boolean crossedMid = true;
boolean direction = true; // direction up = true, down = false
boolean played = false;
void loop() {
        const float *chord;
        x = analogRead(14);
        z = analogRead(15);
        y = analogRead(16);
        coolNumber = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        // Serial.println("x:" + x +  "y: " +   y + "z: " + z);
        Serial.println(coolNumber);

        // Serial.printf("y is %d, down is %d, up is %d",x, yDown, yUp);
        // Serial.println();
        // Serial.clear();
        // Serial.println(y);
        chord = em7;
        // if (counter >= 9){
        //   yList[counter] = y;
        //   counter++;
        //   Serial.println(yList);
        // }
        // strum_up(chord, 1.0);
        // if (x)
        if (played) {
          // Serial.println("WAITING FOR RESET" + direction);
          // Serial.printf("WIATING FOR RESET : y is %d, D=%d, M=%d U=%d,  x is %d, z is %d", y, yDown, yMid, yUp, x,z );
          // Serial.println();
                if (direction) {
                        if (y > yMid) {
                            played = false;
                            // Serial.println("pLAYED SET TO FALSE");

                        }
                }
                else {
                  if (y < yMid) {
                      played = false;
                      // Serial.println("pLAYED SET TO FALSE");

                  }
                }
        }
        else {
                if (y > yDown ) {
                                              Serial.println();
                        Serial.println("UP");
                        // Serial.printf("x is %d, D=%d, M=%d U=%d,  y is %d, z is %d", x, yDown, yMid, yUp, y,z );
                        // Serial.println();
                        direction = false;
                        strum_up(chord, 1.0);
                        delay(hand_delay);
                        delay(hand_delay);
                        played = true;
                }
                else if (y < yUp ) {
                                              Serial.println();
                        Serial.println("DOWNN");
                        // Serial.printf("x is %d, D=%d, M=%d U=%d,  y is %d, z is %d", x, yDown, yMid, yUp, y,z );
                        // Serial.println();
                        strum_dn(chord, 1.0);
                        direction = true;
                        delay(hand_delay);
                        delay(hand_delay);
                        played = true;
                }
        }
        // Serial.clear();
        // Serial.println(y);
        // Serial.println(z);

        // each time through the loop, play a different chord
        // if (chordnum == 0) {
        //   chord = em7;
        //   Serial.println("em7");
        //   chordnum = 1;
        // } else if (chordnum == 1) {
        //   chord = Gmajor;
        //   Serial.println("G major");
        //   chordnum = 2;
        // } else if (chordnum == 2) {
        //   chord = Dsus4;
        //   Serial.println("Dsus4");
        //   chordnum = 3;
        // } else {
        //   chord = A7sus4;
        //   Serial.println("A7sus4");
        //   chordnum = 0;
        // }
        //
        // // then strum the 6 string several times
        // strum_up(chord, 1.0);
        // delay(hand_delay);
        // delay(hand_delay);
        // strum_up(chord, 1.0);
        // delay(hand_delay);
        // strum_dn(chord, 0.8);
        // delay(hand_delay);
        // delay(hand_delay);
        // strum_dn(chord, 0.8);
        // delay(hand_delay);
        // strum_up(chord, 1.0);
        // delay(hand_delay);
        // strum_dn(chord, 0.8);
        // delay(hand_delay);
        // strum_up(chord, 1.0);
        // delay(hand_delay);
        // delay(hand_delay);
        // strum_up(chord, 1.0);
        // delay(hand_delay);
        // strum_dn(chord, 0.7);
        // delay(hand_delay);
        // delay(hand_delay);
        // strum_dn(chord, 0.7);
        // delay(hand_delay);
        // strum_up(chord, 1.0);
        // delay(hand_delay);
        // strum_dn(chord, 0.7);
        // delay(hand_delay);
        //
        // Serial.print("Max CPU Usage = ");
        // Serial.print(AudioProcessorUsageMax(), 1);
        // Serial.println("%");
}



void powerDOWN(const float *chord, float velocity){
  if (chord[0] > 20.0) string1.noteOn(chord[0], velocity);
  if (chord[1] > 20.0) string2.noteOn(chord[1], velocity);
  if (chord[2] > 20.0) string3.noteOn(chord[2], velocity);
  if (chord[3] > 20.0) string4.noteOn(chord[3], velocity);
  if (chord[4] > 20.0) string5.noteOn(chord[4], velocity);
  if (chord[5] > 20.0) string6.noteOn(chord[5], velocity);
}



void strum_up(const float *chord, float velocity)
{
        if (chord[0] > 20.0) string1.noteOn(chord[0], velocity);
        delay(finger_delay);
        if (chord[1] > 20.0) string2.noteOn(chord[1], velocity);
        delay(finger_delay);
        if (chord[2] > 20.0) string3.noteOn(chord[2], velocity);
        delay(finger_delay);
        if (chord[3] > 20.0) string4.noteOn(chord[3], velocity);
        delay(finger_delay);
        if (chord[4] > 20.0) string5.noteOn(chord[4], velocity);
        delay(finger_delay);
        if (chord[5] > 20.0) string6.noteOn(chord[5], velocity);
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
