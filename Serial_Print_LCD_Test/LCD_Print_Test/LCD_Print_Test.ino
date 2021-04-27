// LCD Print Test Code
// Written by: Jonathan Lane
// ECET 38001 - Senior Capstone Prep
// Code Description: 
//    -This code is designed to print the load cell's data and output it to the serial lcd.

#include <SerLCD.h> //Click here to get the library: http://librarymanager/All#SparkFun_SerLCD
SerLCD lcd; // Initialize the library with default I2C address 0x72

void setup() {
  Serial.begin(9600);    // Sets up serial communication for 9600 baud.
  
  lcd.begin(Serial);    // Sets up the LCD for Serial communication at 9600bps.

  lcd.setBacklight(255, 255, 255);  // Sets backlight to bright white.
  lcd.setContrast(5);   // Set contrast. Lower to 0 for higher contrast.

  lcd.clear();    // Clears the display - this moves the cursor to home position as well.
  lcd.print("Hello World!");
}

void loop() {
  // Set the cursor to column 0, line 1.
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // Print the number of seconds since reset:
  lcd.print(millis() / 1000);

}
