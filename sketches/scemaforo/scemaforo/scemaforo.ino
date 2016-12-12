
int red = 9;           // vgr the PWM pin the LED is attached to
int yellow = 10;           // vgr the PWM pin the LED is attached to
int green = 11;           // vgr the PWM pin the LED is attached to

int button =  2; // switch is on pin 2
int buttonValue = LOW; // switch defaults to 0 or LOW
  
// the setup routine runs once when you press reset:
void setup() {
  pinMode(button,INPUT);
  // declare pin 9 to be an output:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
      
    digitalWrite(red, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellow, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(green, LOW);   
buttonValue = digitalRead(button);

  if (buttonValue == HIGH) {
    digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellow, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(green, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(5000);              // wait for a second
    digitalWrite(red, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellow, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(5000);              // wait for a second
    digitalWrite(red, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(2000);              // wait for a second
    
  }
}
