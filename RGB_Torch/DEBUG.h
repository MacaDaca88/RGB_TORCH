/*///////////////DEBUG///////////////////////

Try Keep DEBUG lines here for easy READ and calling

///////////////////////////////////////////*/

#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

void debug() {
#if defined(ESP8266) || (ESP32) || (__AVR_ATmega328P__) || (__AVR_ATmega168__)

  // Add your debug prints here for the ATmega328P
  Serial.print("Debug message for  ");
  Serial.println(Name);
  Serial.print("counter  ==  ");
  Serial.println(counter);
  Serial.print("modeCounter  ==  ");
  Serial.println(modeCounter);
  if (red == true) {
    Serial.println("Red On");
  } else {
    red = false;
  }
  if (green == true) {
    Serial.println("Green On");
  } else {
    green = false;
  }
  if (blue == true) {
    Serial.println("Blue On");
  } else {
    blue = false;
  }
  delay(DEBUG);
#endif
}
#endif