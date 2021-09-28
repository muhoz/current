#include <Filters.h>

float cour;
float cour1 = 0;


void setup(){
  Serial.begin(9600);
  pinMode(A7,INPUT);
}

void loop(){
    cour1 = courant_1();
Serial.println(cour1);
}


float courant_1() {
  unsigned int x = 0;
  float AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0, AcsValueF = 0.0;

  for (int x = 0; x < 150; x++) { 
    AcsValue = analogRead(A7);     
    Samples = Samples + AcsValue;  
    delay (3);
  }
  AvgAcs = Samples / 150.0; 
  AcsValueF = ((AvgAcs * (5.0 / 1024.0))) / 0.66;
  delay(50);
  return abs(AcsValueF);
}
