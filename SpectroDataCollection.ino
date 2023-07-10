#include "SparkFun_AS7265X.h"
AS7265X sensor;

#include <Wire.h>
//#include <Keyboard.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("AS7265x Spectral Triad Example");

  Serial.println("Point the Triad away...");

  if (sensor.begin() == false)
  {
    Serial.println("Sensor does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }

  sensor.disableIndicator(); //Turn off the blue status LED

  Serial.println("A,B,C,D,E,F,G,H,R,I,S,J,T,U,V,W,K,L");

  // Wait for the computer to recognize the keyboard
  delay(2000);
}

void loop()
{
  sensor.takeMeasurementsWithBulb(); //This is a hard wait while all 18 channels are measured

  // Prepare the CSV data string
  String csvData = String(sensor.getCalibratedA()) + "," +
                   String(sensor.getCalibratedB()) + "," +
                   String(sensor.getCalibratedC()) + "," +
                   String(sensor.getCalibratedD()) + "," +
                   String(sensor.getCalibratedE()) + "," +
                   String(sensor.getCalibratedF()) + "," +
                   String(sensor.getCalibratedG()) + "," +
                   String(sensor.getCalibratedH()) + "," +
                   String(sensor.getCalibratedR()) + "," +
                   String(sensor.getCalibratedI()) + "," +
                   String(sensor.getCalibratedS()) + "," +
                   String(sensor.getCalibratedJ()) + "," +
                   String(sensor.getCalibratedT()) + "," +
                   String(sensor.getCalibratedU()) + "," +
                   String(sensor.getCalibratedV()) + "," +
                   String(sensor.getCalibratedW()) + "," +
                   String(sensor.getCalibratedK()) + "," +
                   String(sensor.getCalibratedL()) + "\n";

  // Write the data to the computer as keyboard input
  //Keyboard.print(csvData);

  // Print the data to the Arduino's serial monitor
  Serial.print(csvData);

  delay(1000); // Delay between measurements
}
