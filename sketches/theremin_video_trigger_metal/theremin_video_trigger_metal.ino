#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

int pitch;

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  Serial.begin(9600);
}

void loop() {

  lcd.clear();
  sensorValue = analogRead(A0);

 
  while (millis() < 5000 ) {
    calibrate();
    } 
  
  

  pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 1000);

  printInfo();  
  
  delay(150);
}



void calibrate(){
  
  sensorValue = analogRead(A0);
  
  lcd.setCursor(0, 0);
  lcd.print("calibrating...");

  if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
  if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  
  }



void printInfo (){
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A0));
  
  Serial.print(analogRead(A0));
  Serial.print("\tmin: ");
  Serial.print(sensorLow);
  Serial.print("\tMAX: ");
  Serial.print(sensorHigh);
  Serial.print("\tpitch: ");
  Serial.println(pitch);
}

