
#include "Arduino.h"
#include "SwitchButton.h"

SwitchButton::SwitchButton(short int pin) {
        _lastState = 1023;
		_currentState = 0;
        _pin = pin;
        pinMode(_pin, INPUT);
}

void SwitchButton::updateMe() {
	  _currentState = analogRead(_pin);
}

short int SwitchButton::getCurrentState() {
      return _currentState;
}

void SwitchButton::changePin(short int pin) {
      _pin = pin;
      pinMode(_pin, INPUT);
}

bool SwitchButton::pressed() {
      updateMe();
	  if (_currentState - _lastState > THRESHOLD) {
		  _pressed = true;
	  } else {
		  _pressed = false;
	  }
	  _lastState = _currentState;
	  return _pressed;
}