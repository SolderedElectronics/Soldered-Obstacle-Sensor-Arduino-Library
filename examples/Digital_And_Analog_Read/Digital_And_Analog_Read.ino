/**
 **************************************************
 *
 * @file        Digital_And_Analog_Read.ino
 * @brief       Example for using the digital and analog read functions for www.solde.red/333004
 *
 *
 *
 * @authors     Zvonimir Haramustek for Soldered.com
 ***************************************************/

#include "Obstacle-Sensor-SOLDERED.h"

// Declare the sensor object
Obstacle_Sensor obstacle_sensor;

// Wiring diagram is not needed here, you just
// plug easyC cable in microcontroller and breakout
// board and you are ready to upload this sketch
// You can find more info about easyC on this link
// https://soldered.com/easyC

void setup()
{
    // Start serial communication with PC via UART
    Serial.begin(115200);

    // Initialize the sensor
    obstacle_sensor.begin();

    // Set treshold for onboard LED and digital read
    obstacle_sensor.setTreshold(128);
}

void loop()
{
  if(obstacle_sensor.available())
  {
    // Read the digital sensor value
    Serial.print("Obstacle digital: ");
    Serial.println(obstacle_sensor.digitalRead());

    // Read the analog sensor value
    Serial.print("Obstacle analog: ");
    Serial.println(obstacle_sensor.analogRead());
  }
  else
  {
    Serial.println("Communication error!");
  }
    delay(1000);
}
