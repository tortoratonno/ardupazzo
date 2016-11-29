
#include "Arduino.h"
#include "SwitchButton.h"


SwitchButton::SwitchButton(short int pin) {
        _state = 0;
        _pin = pin;
        pinMode(_pin, INPUT);
}

void SwitchButton::updateMe () {
      _state = analogRead(_pin);
}

short int SwitchButton::getState() {
      return _state;
}


