// Load Cell Test Code
// Written by: Jonathan Lane
// ECET 38001 - Senior Capstone Prep
// Code Description: 
//    -This code is designed to read the load cell's data and output it to the serial monitor.

#define DOUT  3
#define CLK  2 

void setup() {
  // Pin Definitions: 
  pinMode(A0, INPUT);   // sets the analog pin A0 as input
}

void loop() {
  Serial.begin(9600);

  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  delay(300);
}
