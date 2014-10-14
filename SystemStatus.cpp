/*

*/


#include "SystemStatus.h"


SystemStatus::SystemStatus(uint8_t apin_batt) : pin_batt(apin_batt) {

}


int SystemStatus::getVCC() {
  //reads internal 1V1 reference against VCC
  #if defined(__AVR_ATtiny84__)
    ADMUX = _BV(MUX5) | _BV(MUX0); // For ATtiny84
  #elif defined(__AVR_ATtiny85__)
    ADMUX = _BV(MUX3) | _BV(MUX2); // For ATtiny85
  #elif defined(__AVR_ATmega1284P__)
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);  // For ATmega1284
  #else
    ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);  // For ATmega328
  #endif
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA, ADSC));
  uint8_t low = ADCL;
  unsigned int val = (ADCH << 8) | low;
  //discard previous result
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA, ADSC));
  low = ADCL;
  val = (ADCH << 8) | low;
  
  return ((long)1024 * 1100) / val;  
}


int SystemStatus::getVBatt(int vcc) {
  unsigned int a = analogRead(this->pin_batt); //discard first reading
  a = analogRead(this->pin_batt);
  return (long)vcc * (long)a / 1024;
}


int SystemStatus::getFreeRAM() {
  extern int  __bss_end;
  extern int  *__brkval;
  int free_memory;
  if((int)__brkval == 0) {
    free_memory = ((int)&free_memory) - ((int)&__bss_end);
  }
  else {
    free_memory = ((int)&free_memory) - ((int)__brkval);
  }
  return free_memory;
}


int SystemStatus::getkHz() {
  return F_CPU / 1000;
}


int SystemStatus::getMHz() {
  return F_CPU / 1000000;
}





//