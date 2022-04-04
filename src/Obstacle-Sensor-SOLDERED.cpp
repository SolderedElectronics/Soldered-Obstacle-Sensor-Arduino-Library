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
    return analogRead() < treshold;
}

/**
 * @brief                   Returns analog value of sensor.
 *
 * @return int              Analog value of sensor.
 */
int Obstacle_Sensor::analogRead()
{
    if(available())
    {
        char c[2];
        readRegister(0, c, 2);

        val = c[0] << 8 | c[1];
        return val;
    }
    else 
    {
        return 0;
    }

}


/**
 * @brief                   Sets treshold for turning on integrated L0 LED on breakout
 *
 *
 */
void Obstacle_Sensor::setTreshold(uint16_t value)
{
    if(available())
    {   
        char a[3];
        a[0] = 0x02;
        if(value < 1023 && value > 0)
        {
            a[1] = (value  & 0xFF00) >> 8;
            a[2] = value & 0xFF;
        }
        else
        {
            a[1] = 0;
            a[2] = 127;
        }
        sendData((const uint8_t *)a, 3);
        treshold = value;
    }
}

/**
 * @brief                   Sets treshold for turning on integrated L0 LED on breakout
 *
 *
 */
uint16_t Obstacle_Sensor::getTreshold()
{
    return treshold;
}

/**
 * @brief                   Function which checks if I2C device is responding
 *
 * @return                  1 if device is responding, 0 if not
 */
bool Obstacle_Sensor::available()
{
    return !(sendAddress(0x00)); // checking if address is succesfully sent, if
                                        // not device is not ready to communicate
}
