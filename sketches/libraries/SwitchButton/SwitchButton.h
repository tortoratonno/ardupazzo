
/*
 * 
 * switch button mangement
 * 
 */
 
#ifndef SwitchButton_h
#define SwitchButton_h

#define THRESHOLD 300

#include "Arduino.h"

class SwitchButton {

  private: 
      short int _lastState;
      short int _currentState;
      short int _pin;
      bool _pressed = false;

  public:
      SwitchButton(short int pin);
      void updateMe();
      short int getCurrentState();
      void changePin(short int pin);
	  bool pressed();
  };

#endif
  
