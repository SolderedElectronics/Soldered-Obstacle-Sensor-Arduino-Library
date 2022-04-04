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
uint16_t treshold = 127, reading = 0;
bool state = 0, prev_state = 0;

void setup()
{
  
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);
    pinMode(PA4, OUTPUT);
    Serial.begin(115200);
}

void loop()
{ 
  prev_state = state;
  reading = analogRead(PA5);
  state = treshold > reading;
  if(state != prev_state)
  {
      digitalWrite(PA4,state);
  }
  delay(1);
}

uint8_t lastEvent, pLastEvent;

void receiveEvent(int howMany)
{
    Serial.print("Avail is: ");
    Serial.println(Wire.available());
    while(Wire.available())
    {
      if(Wire.peek() == 0x02)
      {
          digitalWrite(PA4,HIGH);
          Serial.println(Wire.peek());
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
    if(lastEvent == 0)
    {
        char a[2];
        a[0] = reading >> 8;
        a[1] = reading  & 0xFF;
        Wire.write(a, 2);
    } 
}
