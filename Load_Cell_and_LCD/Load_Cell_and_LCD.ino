// Load Cell & LCD Test Code
// Written by: Jonathan Lane
// ECET 38001 - Senior Capstone Prep
// Code Description: 
//    -This code is designed to print the load cell's data and output it to the serial lcd.
//    -This code is designed to function with the ATmega 328p (Arduino Uno) - NOT the 2560 (Arduino Mega).

/* External Hardware Connections:
    LCD:
      -5V -> 5V
      -GND -> GND
      -Arduino Pin 1 (TX) -> Logic Converter HV4
    Load Cell Amplifier:
      -VCC -> 5V
      -GND -> GND
      -SCK -> Arduino Pin 5
      -DT -> Arduino Pin 6

*/
#include "HX711.h"    //You must have this library in your arduino library folder.
#include <SerLCD.h>   //Click here to get the library: http://librarymanager/All#SparkFun_SerLCD.

const int LOADCELL_DOUT_PIN = 6;
const int LOADCELL_SCK_PIN = 5;

#define DOUT  4
#define CLK  5

HX711 scale;
SerLCD lcd; // Initialize the library with default I2C address 0x72
float calibration_factor = 60;  // This calibration factor is adjusted according to my load cell.
float units;

void setup() 
{
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  scale.tare(); //Reset the scale to 0

  lcd.begin(Serial);    // Sets up the LCD for Serial communication at 9600bps.
  lcd.setBacklight(255, 255, 255);  // Sets backlight to bright white.
  lcd.setContrast(5);   // Set contrast. Lower to 0 for higher contrast.
}

void loop() 
{
  scale.set_scale(calibration_factor);
  units = scale.get_units(), 5;
  if (units < 0)
  {
    units = 0.00;
  }
  lcd.clear();    // Clears the display - this moves the cursor to home position as well.
  lcd.print("Weight: ");
  lcd.print(units);
  lcd.print(" g");
  delay(500);
}
