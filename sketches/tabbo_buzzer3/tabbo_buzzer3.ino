#include <SevenSegmentDisplay.h>
#include "pitches.h"
#include <SwitchButton.h>


/*
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

char strMenu[4] = {'m','e','n','u'};
char strTime[4] = {'t','i','m','e'};
char strMelody[4] = {'s','o','n','g'};
char strBuzz[4] = {'b','u','z','z'};

SwitchButton buzzBtn(A0);
SwitchButton startBtn(A1);
SwitchButton setBtn(A2);  
//SwitchButton pulsanto(A2);  

const int buzzerPin = 2;

bool play = false;
short int durataShow;

short int cnt = 0;
int serpeLength = 7;
//char serpe[4] = {'_','-','^','-'};
char serpe[7] = {'p','u','p','p','a',' '};
char buffy[4];
int counter = 0;


// IMPERIAL MARCH START

int melodyImperial[] = {
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_DS3, NOTE_AS4, NOTE_G3, NOTE_DS3, NOTE_AS4, NOTE_G3
};

int noteDurationsImperial[] = {
  2, 2, 2, 3, 8, 2, 3, 8, 2
};                                                                // note durations: 4 = quarter note, 8 = eighth note, etc.:

                                            
// IMPERIAL MARCH END

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};                                                                // note durations: 4 = quarter note, 8 = eighth note, etc.:

SevenSegmentDisplay<true, QuadriDigit<4, 13, 3, 1> > ss(11, 10, 8, 6, 5, 12, 7, 9);

void setup() {
  // Serial.begin(9600);
  durataShow = 99;
}

void loop() {

  updateBtn();  
  sbuzzerazzizza();
  

  
  if (startBtn.pressed() == true) {
    play = true;
    showTime(durataShow);
    finalTheme(melodyImperial, noteDurationsImperial);
  } 
  else if (setBtn.pressed() == true) {
    menu();
  } 
  else {
    serpentizza();
  }
}





/*
    Serial.println("dopo update");
    Serial.println(buzzBtn.getState());
    Serial.println(startBtn.getState());
    Serial.println(setBtn.getState());
*/


void updateBtn() {
  buzzBtn.updateMe();
  startBtn.updateMe();
  setBtn.updateMe();
  //pulsanto.updateMe();
}


void showTimeII(unsigned i){
  do {
    ss.print(i, 100);
  } while (i--);
}




void showTime(unsigned i){
  do {
    ss.print(i, 1, 100);
    sbuzzerazzizza();
    if (startBtn.pressed() == true){
      play = false;
        do{
          ss.print(i, 1, 100);
          if (startBtn.pressed() == true){
            play = true;
          }
        } while (play == false);       
    }
  } while (i--);
  ss.clear();
}

void finalTheme(int melodyArg[], int noteDurationsArg[]){
  for (int thisNote = 0; thisNote < 9; thisNote++) {
    
    char c[4] = {'H','E','L','L'};
    
    
    int noteDuration = 1000 / noteDurationsArg[thisNote];          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    tone(buzzerPin, melodyArg[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.25;                  //1.30
    ss.print(c, -1, 27);
    ss.clear();
    delay(pauseBetweenNotes);
  }
}
void finalThemeORIG(int melodyArg[], int noteDurationsArg[]){
  for (int thisNote = 0; thisNote < 9; thisNote++) {
    ss.print(8888, 2, 10);
    ss.clear();
    int noteDuration = 1000 / noteDurationsArg[thisNote];          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    tone(buzzerPin, melodyArg[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}

void sbuzzerazzizza(){
  if (buzzBtn.getCurrentState() > 300) {
    int noteDuration = 1000 / noteDurations[1];
    tone(buzzerPin, melody[0], noteDuration);
    }
  else {
    noTone(buzzerPin);
  }
  buzzBtn.updateMe();  
}

void serpentizza(){
  for (int j=0; j<=3; j++) {
    buffy[j] = serpe[(j+cnt)%(serpeLength-1)];
  }
  ss.print(buffy, -1, 10);
  counter += 1;
  if (counter >= 15) {
    cnt=(cnt+1)%(serpeLength-1);
    counter = 0;
  }
}

void menu() {
    int cntMenu = 0;
    char buff[4];
    simpleFillBuff(buff, strMenu);
    while (!buzzBtn.pressed()) {
      ss.print(buff, -1, 10); 

      if (startBtn.pressed() == true) {
        cntMenu = (cntMenu + 1)%3+1;
        switch(cntMenu)
          {
            case (1):
                simpleFillBuff(buff, strTime);
                break;
                           
            case (2):
               simpleFillBuff(buff, strMelody);
                break;
         
            case (3):
                simpleFillBuff(buff, strBuzz);
                break;
          }
      } 
      else if (setBtn.pressed() == true) {

        switch(cntMenu)
          {
            case (1):
                setTime();
                break;
                           
            case (2):
                setMelody();
                break;
         
            case (3):
                setBuzzer();
                break;
          }
      } 
    }
    
    ss.clear();
    delay(300);
}

void setTime() {
  while (!buzzBtn.pressed()) {
  char c[4] = {'X','I','M','X'};
  ss.print(c, -1, 10); 
  }
}

void setMelody() {
  while (!buzzBtn.pressed()) {
  char c[4] = {'X','O','N','X'};
  ss.print(c, -1, 10); 
  }
}
void setBuzzer() {
  while (!buzzBtn.pressed()) {
  char c[4] = {'X','U','Z','X'};
  ss.print(c, -1, 10); 
  }
}

void simpleFillBuff(char *buff, char *strMenu) {
  for (int j=0; j<=3; j++) {
    buff[j] = strMenu[j];
  }
}
