#include <Thread.h>
#include <ThreadController.h>

/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_A3, NOTE_A3, NOTE_A3, 0, NOTE_A3, NOTE_A3, NOTE_A3, 0, NOTE_A3, NOTE_C4, NOTE_F3, NOTE_G3, NOTE_A3
};

//int bass[] = {
//  NOTE_F3, NOTE_F3, NOTE_F3, 0, NOTE_E3, NOTE_E3, NOTE_E3, 0, NOTE_D3, NOTE_D3, NOTE_D3, 0, NOTE_C3, NOTE_C3, NOTE_C3, 0
//};

int bass[] = {
    NOTE_A2, NOTE_A2, NOTE_A2, 0, NOTE_A2, NOTE_A2, NOTE_A2, 0, NOTE_A2, NOTE_C3, NOTE_F2, NOTE_G2, NOTE_A2
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurationsMelody[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1
};
int noteDurationsBass[] = {
  //4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1
};

ThreadController controller = ThreadController();

Thread myThreadMelody = Thread();
Thread myThreadBass = Thread();

int pinMelody= 2;
int pinBass=4;

void setup() {

myThreadMelody.enabled = true;
myThreadBass.enabled = true;

myThreadMelody.setInterval(10);
myThreadBass.setInterval(10);

myThreadMelody.onRun(playMelody);
myThreadBass.onRun(playBass);

controller.add(&myThreadMelody);
controller.add(&myThreadBass);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  
  delay(500);
  
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  delay(1000);
  
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  
  // iterate over the notes of the melody:
    
controller.run();

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  delay(1000);
  
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
    }

void loop() {


}

void playMelody(){
    for (int thisNote = 0; thisNote < sizeof(noteDurationsMelody); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurationsMelody[thisNote];
    tone(pinMelody, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    // int pauseBetweenNotes = noteDuration * 1.30;
    // delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pinMelody);
  }
  }


  void playBass(){
    for (int thisNote = 0; thisNote < sizeof(noteDurationsBass); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurationsBass[thisNote];
    tone(pinBass, bass[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    // int pauseBetweenNotes = noteDuration * 1.30;
    // delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pinBass);
  }
  }
