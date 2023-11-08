#ifndef DEBUG_h
#define DEBUG_h

#include "PINS.h"

void debug() {

#if defined(__AVR_ATmega328P__)
  // Add your debug prints here for the ATmega328P
  Serial.println("Debug message for ATmega328P");
  Serial.print("counter  ==  ");
  Serial.println(counter);
  Serial.print("modeCounter  ==  ");
  Serial.println(modeCounter);
  delay(DEBUG);
#endif
}

#endif
