/**
 **************************************************

    @file        attiny_firmware.ino
    @brief       ATTINY firmware for obstacle detector



    @authors     Zvonimir Haramustek for Soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;
uint16_t treshold = 127, reading = 0;
bool state = 0;

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
    reading = analogRead(PA5);
    state = treshold > reading;
    digitalWrite(PA4, state);
    delay(10);
}

uint8_t lastEvent, pLastEvent;

void receiveEvent(int howMany)
{
    while (Wire.available())
    {
        if (Wire.peek() == 0x02)
        {
            digitalWrite(PA4, HIGH);
            lastEvent = Wire.read();
            treshold = 0x0000;
            treshold |= Wire.read() << 8;
            treshold |= Wire.read();
        }
        else
            lastEvent = Wire.read();
    }
}

void requestEvent()
{
    if (lastEvent == 0)
    {
        char a[2];
        a[1] = reading & 0xFF;
        a[0] = ((reading & 0xFF00) >> 8) & 0xFF;
        Wire.write(a, 2);
    }
}
