//declare the variable
float cour1 = 0;


void setup(){
  Serial.begin(9600);  //initialise the serial communication
  pinMode(A7,INPUT);   //Define the port as an INPUT to read the current value at this position
}

void loop(){
    cour1 = courant_1();  //call the courant_1() function that calculates the current
Serial.println(cour1);    //print the current value
}

//current function
float courant_1() {
  unsigned int x = 0;
  float AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0, AcsValueF = 0.0;

  for (int x = 0; x < 150; x++) { //loop to take 150 samples to do the mean and have a better value
    AcsValue = analogRead(A7);     //read the value from the analog pin
    Samples = Samples + AcsValue;  //sum the reading values
    delay (3);  //wait 3 milliseconds
  }
  AvgAcs = Samples / 150.0; //divide to have the arithmetic mean
  AcsValueF = ((AvgAcs * (5.0 / 1024.0))) / 0.66;  //conversion to have the real value of the current sensor
  delay(50);  //wait 50 milliseconds
  return abs(AcsValueF); //return the current value
}
