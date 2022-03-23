/**
 **************************************************
 *
 * @file        Template for attiny_firmware
 * @brief       Fill in sensor specific code.
 *

 *
 * @authors     Zvonimir Haramustek for Soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;
uint16_t treshold = 127;

void setup()
{
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);
    pinMode(PA4, OUTPUT);
}

void loop()
{
  digitalWrite(PA4,(treshold < analogRead(PA5)) ? LOW : HIGH);
  delay(1);
}

uint8_t lastEvent, pLastEvent;

void receiveEvent(int howMany)
{
    pLastEvent = lastEvent;
    lastEvent = Wire.read();
    if(Wire.available() && lastEvent == 0x02)
    {   
        treshold = Wire.read() << 2;
    }
    if (pLastEvent == 0x02 && lastEvent > 0x04)
    {
        treshold = lastEvent << 2; 
    }
}

void requestEvent()
{   
    if(lastEvent == 0)
    {
        int c = 0;
        char a[2];
        c = analogRead(PA5);
        a[0] = c >> 8;
        a[1] = c & 0xFF;
        Wire.write(a, 2);
    } 
}
