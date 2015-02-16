/*

*/

#ifndef SystemStatus_H
#define SystemStatus_H


#include "Arduino.h"


class SystemStatus {
  
  public:
    
    uint8_t pin_batt;
    
    SystemStatus(uint8_t apin_batt);
    SystemStatus();
    int getVCC();
    int getVBatt(int vcc);
    int getFreeRAM();
    int getkHz();
    int getMHz();
    int8_t getTemperatureInternal();
    void SleepWakeOnInterrupt(uint8_t i);
    
  private:

}; //end of class SystemStatus

void jebat_cecky();

#endif
