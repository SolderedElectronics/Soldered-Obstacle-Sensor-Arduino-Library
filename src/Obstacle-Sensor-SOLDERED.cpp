/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for Soldered.com
 ***************************************************/


#include "Obstacle-Sensor-SOLDERED.h"

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
// Obstacle_Sensor::Obstacle_Sensor(int _pin)
// {
//     pin = _pin;
//     native = 1;
// }

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
// void Obstacle_Sensor::initializeNative()
// {
//     pinMode(pin, INPUT);
// }

/**
 * @brief                   Returns digital value of sensor.
 *
 * @return bool             Digital value of sensor.
 */
bool Obstacle_Sensor::digitalRead()
{
    char c[2];
    readRegister(0, c, 2);

    return c[0] == 1;
}

/**
 * @brief                   Returns analog value of sensor.
 *
 * @return int              Analog value of sensor.
 */
int Obstacle_Sensor::analogRead()
{
    char c[2];
    readRegister(1, c, 2);

    return c[0] << 8 | c[1];
}
