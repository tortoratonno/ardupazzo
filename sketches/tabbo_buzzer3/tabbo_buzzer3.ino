#include <SevenSegmentDisplay.h>

#include <SwitchButton.h>


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

#include "pitches.h"
// #include "SwitchButton.h"


SwitchButton buzzBtn(A3);
SwitchButton startBtn(A1);
SwitchButton setBtn(A0);  
                            
const int buzzerPin = 2;
bool play = false;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};                                                                // note durations: 4 = quarter note, 8 = eighth note, etc.:

SevenSegmentDisplay<true, QuadriDigit<4, 13, 3, 1> > ss(11, 10, 8, 6, 5, 12, 7, 9);

void setup() {
  //Serial.begin(9600);

}

void loop() {
  
  updateBtn();  

/*
    Serial.println("dopo update");
    Serial.println(buzzBtn.getState());
    Serial.println(startBtn.getState());
    Serial.println(setBtn.getState());
*/
  
  sbuzzerazzizza();

  if (startBtn.getCurrentState() > 700 ) {
    play = true;
    showTime(99);
    finalTheme();
  }

}

void showTime(unsigned i){
  do {
    ss.print(i, 1, 100);
//    sbuzzerazzizza();
    setBtn.updateMe();
    if (setBtn.getCurrentState() > 700){
      play = false;
      delay(50);
        do{
          ss.print(i, 1, 100);
          setBtn.updateMe();
          if (setBtn.getCurrentState() > 700){
            play = true;
            delay(50);
          }
        } while (play == false);       
    }
  } while (i--);
}

void finalTheme(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    tone(buzzerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}

void sbuzzerazzizza(){
  if (buzzBtn.getCurrentState() > 0) {
    int noteDuration = 1000 / noteDurations[1];
    tone(buzzerPin, melody[0], noteDuration);
    }
  else {
    noTone(buzzerPin);
  }
  buzzBtn.updateMe();  
}

void updateBtn() {
  buzzBtn.updateMe();
  startBtn.updateMe();
  setBtn.updateMe();
}

