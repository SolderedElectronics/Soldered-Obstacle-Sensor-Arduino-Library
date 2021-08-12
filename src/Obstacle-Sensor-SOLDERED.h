/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for Soldered.com
 ***************************************************/

#ifndef __OBSTACLE_SENSOR_SOLDERED__
#define __OBSTACLE_SENSOR_SOLDERED__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.h"

class Obstacle_Sensor : public OBSTACLE_SOLDERED_LIBS::EasyC
{
  public:
    // Obstacle_Sensor(int _pin);

    bool digitalRead();
    int analogRead();

  protected:
    void initializeNative(){};

  private:
    int pin;
};

#endif
