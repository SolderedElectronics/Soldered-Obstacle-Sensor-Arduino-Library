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

void setup()
{
    // Start serial communication with PC via UART
    Serial.begin(115200);

    // Initialize the sensor
    obstacle_sensor.begin();

    // Set treshold for onboard LED
    obstacle_sensor.setTreshold(255);
}

void loop()
{
    // Read the digital sensor value
    Serial.print("Obstacle digital: ");
    Serial.println(obstacle_sensor.digitalRead());

    delay(1000);

    // Read the analog sensor value
    Serial.print("Obstacle analog: ");
    Serial.println(obstacle_sensor.analogRead());
    
    delay(1000);
}
