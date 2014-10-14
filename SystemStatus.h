/*

*/

#ifndef SystemStatus_H
#define SystemStatus_H


#include "Arduino.h"


class SystemStatus {
  
  public:
    
    uint8_t pin_batt;
    
    SystemStatus(uint8_t apin_batt);
    int getVCC();
    int getVBatt(int vcc);
    int getFreeRAM();
    int getkHz();
    int getMHz();
    
  private:

}; //end of class SystemStatus



#endif
