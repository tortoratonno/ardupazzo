
int LedPins[] = {3, 4, 5, 6, 7, 9, 10, 11, 12, 13};
int x = 0;
char posiz = 'D';  


void setup() {
  Serial.begin(9600);
  
  for (int i=0; i<=9; i++) {
    pinMode(LedPins[i], OUTPUT);
    analogWrite(LedPins[i],255);
    //Serial.println(LedPins[i]);
  }
  delay(200);
  for (int i=0; i<=9; i++) {
    analogWrite(LedPins[i],0);
    //Serial.println(LedPins[i]);
  }
  delay(100);  
}

void loop() {
  //while (posiz = "" || posiz = "DX"){

      
  if (posiz == 'D') {
    Serial.println(x);
    for (int x=0; x<=12; x++) {
      if (x<=9){
        analogWrite(LedPins[x],255);
        analogWrite(LedPins[x-1],150);
        analogWrite(LedPins[x-2],50);
        analogWrite(LedPins[x-3],0);
      }
      if (x==10){
        analogWrite(LedPins[x-1],150);
        analogWrite(LedPins[x-2],50);
        analogWrite(LedPins[x-3],0);
      }
      if (x==11){
        analogWrite(LedPins[x-2],50);
        analogWrite(LedPins[x-3],0);
      }
      if (x==12){
        analogWrite(LedPins[x-3],0);
        Serial.println("END_DX: ");
        delay(200);  
        //strcpy(posiz, "SX");
        posiz = 'S';
      }
  
      delay(200);  
  
      Serial.print("\tLED_DX: ");
      Serial.println(x);
    }
  }
  else if (posiz == 'S') {
//    int x=11;
    Serial.println(x);
    for (int x=11; x>=0; x--) {
      if (x>=3){
        analogWrite(LedPins[x],255);
        analogWrite(LedPins[x+1],150);
        analogWrite(LedPins[x+2],50);
        analogWrite(LedPins[x+3],0);
      }
      if (x==2){
        analogWrite(LedPins[x+1],150);
        analogWrite(LedPins[x+2],50);
        analogWrite(LedPins[x+3],0);
      }
      if (x==1){
        analogWrite(LedPins[x+2],50);
        analogWrite(LedPins[x+3],0);
      }
      if (x==0){
        analogWrite(LedPins[x+3],0);
        Serial.println("END_SX: ");
        delay(200);  
        //strcpy(posiz, "DX");
        posiz = 'S';
      }

      delay(200);  
  
      Serial.print("\tLED_SX: ");
      Serial.println(x);
    }

  }

delay(200);
}
