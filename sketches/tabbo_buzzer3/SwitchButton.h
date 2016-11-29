
//*************************** BUTTONS CONFIG ************************************

#ifndef SwitchButton_h
#define SwitchButton_h
#include "Arduino.h"

class SwitchButton {

  private: 
      short int _state = 0;
      short int _pin; 

  public:
      SwitchButton(short int pin);
      void updateMe();
      short int getState();
    
  };


#endif
  
