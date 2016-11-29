#include "pitches.h"

const int buzzerPin = 2;
const int buttonPin = A0;
int buttonState = 0;
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};                                                                // note durations: 4 = quarter note, 8 = eighth note, etc.:


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

}

void loop() {
    
   //buttonState = digitalRead(buttonPin);
    buttonState = analogRead(buttonPin);
  Serial.print("button: ");
  Serial.println(buttonState);


//  if (buttonState == HIGH) {
  if (buttonState >0) {
    int noteDuration = 1000 / noteDurations[1];
    tone(buzzerPin, melody[0], noteDuration);
    /*for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      tone(buzzerPin, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }*/
  } 
  else {
        noTone(buzzerPin);
  }    
//  delay(3000);
}
