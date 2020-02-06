#include <Audio.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>

#include "chords.h"

// Special thanks to Matthew Rahtz - http://amid.fish/karplus-strong/

AudioSynthKarplusStrong  string1;
AudioSynthKarplusStrong  string2;
AudioSynthKarplusStrong  string3;
AudioSynthKarplusStrong  string4;
AudioSynthKarplusStrong  string5;
AudioSynthKarplusStrong  string6;
AudioMixer4              mixer1;
AudioMixer4              mixer2;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(string1, 0, mixer1, 0);
AudioConnection          patchCord2(string2, 0, mixer1, 1);
AudioConnection          patchCord3(string3, 0, mixer1, 2);
AudioConnection          patchCord4(string4, 0, mixer1, 3);
AudioConnection          patchCord5(mixer1, 0, mixer2, 0);
AudioConnection          patchCord6(string5, 0, mixer2, 1);
AudioConnection          patchCord7(string6, 0, mixer2, 2);
AudioConnection          patchCord8(mixer2, 0, i2s1, 0);
AudioConnection          patchCord9(mixer2, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;

const int finger_delay = 5;
const int hand_delay = 220;

int chordnum=0;


int x,y,z;
int startY;
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
  yDown = analogRead(16) * 1.2;
  yUp = analogRead(16) * 0.8;
}

void strum_up(const float *chord, float velocity);
void strum_dn(const float *chord, float velocity);

void loop() {
  // const float *chord;
  x = analogRead(14);
  z = analogRead(15);
  y = analogRead(16);
  // Serial.println("x:" + x +  "y: " +   y + "z: " + z);
  // Serial.printf("x is %d, y is %d, z is %d", x,y,z);
  Serial.println(y);

  if (y > yDown ){
    Serial.println("DOWN");
  }
  else if (y < yUp ){
    Serial.println("THRESSS");
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
