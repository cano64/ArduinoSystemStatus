/*

Copyright (C) 2015 Michal Canecky
All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

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
