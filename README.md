SystemStatus
==========

SystemStatus is Arduino library to get information about VCC voltage, Free RAM etc...

Supported functions:

##### getVCC();
Returns voltage on the power pin in mV. Normally it should be 5000mV or what ever the voltage regulator is outputing. 
If you are powering the microcontroller directly from the battery you will get the battery voltage without using any additional pin.


##### getVBatt(int vcc);
Use either as ```getVBatt(5000)``` or ```getVBatt(getVCC())``` or similar. Returns voltage level on the battery sense pin in mV. 
Battery sense pin is provided in the constructor. The battery level must be lower than VCC. This works only if a step up
converter is used to step up battery voltage to VCC. Get [tinyBoost, small DC to DC step up converter for your Arduino project](https://www.tindie.com/products/FemtoCow/tinyboost-dc-to-dc-step-up-boost-converter-to-220/)


##### getFreeRAM();
Returns available RAM in Bytes


##### getTemperatureInternal();
Returns internal temperature of the microcontroller in C. Some AVR microcontrollers have build in temperature sensor inside.
It's very innacurate, but if you calibrate it, you may be able to detect if the board is overheating (if you have additional components on the board)


##### SleepWakeOnInterrupt();
Enters power down mode. In this mode the program is not running and the RAM is preserved. Power consumption is very low in this mode
and the batteries can last for many years. You can wake up from this mode by applying 0V (using a button) to the INT0 pin (which needs to be held high during sleep)
INT0 pin is pin2 on Arduino. Program will just resume running from that point.

#### Support
* ATMega328
* ATTiny84
* ATTiny85




