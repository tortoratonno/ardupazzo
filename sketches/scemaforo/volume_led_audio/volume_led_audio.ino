/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
//const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int AUDIO = 8;
const int green = 9;
const int yellow = 10;
const int red = 6;      // !!! su pin 11 non trimmera il led rosso con audio !!!

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int gled = 0;
int yled = 0;
int rled = 0;
int tonoAudio = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // print the results to the serial monitor:
  Serial.print("\tsensor = ");
  Serial.print(sensorValue);
  Serial.print("\toutput = ");
  Serial.print(outputValue);
  Serial.print("\tGREEN = ");
  Serial.print(gled);
  Serial.print("\tYELLOW = ");
  Serial.print(yled);
  Serial.print("\tRED = ");
  Serial.print(rled);
  Serial.print("\tAUDIO = ");
  Serial.println(tonoAudio);


//341
  if (sensorValue == 0) {
    Serial.print("FASE 0");
    analogWrite(green, 0);
    analogWrite(yellow, 0);
    analogWrite(red, 0);
    tone(AUDIO, 0, 1000);
  }    
  else if (sensorValue>=1 && sensorValue<341) {
    Serial.print("FASE 1");
    
    gled = map(sensorValue, 1, 341, 0, 255);
    analogWrite(green, gled);
    analogWrite(yellow, 0);
    analogWrite(red, 0);
    suona();
  }  
  else if (sensorValue>=341 && sensorValue<682) {
    Serial.print("FASE 2");
    yled = map(sensorValue, 341, 682, 0, 255);
    analogWrite(green, 255);
    analogWrite(yellow, yled);
    analogWrite(red, 0);
    suona();
  }
  else if (sensorValue>=682 && sensorValue<1024) {
    Serial.print("FASE 3");
    rled = map(sensorValue, 682, 1023, 0, 255);
    analogWrite(green, 255);
    analogWrite(yellow, 255);
    analogWrite(red, rled);
    suona();
  }


  
  
  // wait 2 milliseconds before the    next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}


void suona (){

    int lower = 31;       //31
    int higher = 1976;      //1976 (NOTE_B6) //3951 (NOTE_B7) //4978 (NOTE_DS8)
    int duration = 100;
    
    tonoAudio = map(sensorValue, 0, 1023, lower, higher);
    tone(AUDIO, tonoAudio, duration);


}

