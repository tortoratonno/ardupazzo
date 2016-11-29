/*!
 * \file QuadriDigit.ino
 * \brief demo for four 7-segement displays with common cathode.
 * \author Like Ma <likemartinma@gmail.com>
 * 
 * This sketch counts down from 9999 to 0, while each value keeps displaying for 2 seconds.

 * The circuit:
 *   - Pin d1 to digital pin  4
 *   - Pin d2 to digital pin 13
 *   - Pin d3 to digital pin  3
 *   - Pin d4 to digital pin  1
 *   - Pin a  to digital pin 11
 *   - Pin b  to digital pin 10
 *   - Pin c  to digital pin  8
 *   - Pin d  to digital pin  6
 *   - Pin e  to digital pin  5
 *   - Pin f  to digital pin 12
 *   - Pin g  to digital pin  7
 *   - Pin dp to digital pin  9
 */

#include <SevenSegmentDisplay.h>
#include "pitches.h"

const int buzzerPin = 2;
int buttonState = 0;
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};                                                                // note durations: 4 = quarter note, 8 = eighth note, etc.:

SevenSegmentDisplay<true, QuadriDigit<4, 13, 3, 1> > ss(11, 10, 8, 6, 5, 12, 7, 9);

void setup() {
}

void loop() {

  unsigned i =99;
  do {
    ss.print(i, 1, 100);
  } while (i--);
  
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    tone(buzzerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}
