/*/////////////Color Defintions/////////////

Add New Colors here to call from anywhere


//////////////////////////////////////////*/

#ifndef RGB_Torch_h
#define RGB_Torch_h
#include "PINS.h"
#include "SolidColor.h"

void Red() {

  // Turn RED led ON
  analogWrite(RED, ON);     // Turns RED ON
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  analogWrite(BLUE, OFF);   // Turns BLUE OFF
}

void Green() {
  // Turn GREEN led ON

  analogWrite(RED, OFF);   // Turns RED OFF
  analogWrite(GREEN, ON);  // Turns GREEN ON
  analogWrite(BLUE, OFF);  // Turns BLUE OFF
}

void Blue() {
  // Turn BLUE led ON

  analogWrite(RED, OFF);    // Turns RED OFF
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  analogWrite(BLUE, ON);    // Turns BLUE ON
}

void White() {
  // Turn ALL led ON to create WHITE

  analogWrite(RED, ON);    // Turns RED ON
  analogWrite(GREEN, ON);  // Turns GREEN ON
  analogWrite(BLUE, ON);   // Turns BLUE ON
}
void Off() {
  analogWrite(RED, OFF);    // Turns RED OFF
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  analogWrite(BLUE, OFF);   // Turns BLUE OFF
}
#endif
