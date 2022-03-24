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
#include "libs/Generic-easyC/easyC.hpp"

class Obstacle_Sensor : public EasyC
{
  public:
    // Obstacle_Sensor(int _pin);

    bool digitalRead();
    int analogRead();
    void setTreshold(uint16_t value);
    uint16_t getTreshold(void);
    bool available();

  protected:
    void initializeNative(){};

  private:
    int pin;
    uint16_t val;
    uint16_t treshold = 127;
};

#endif
