/*/////////////Color Defintions/////////////

Add New Colors here to call from anywhere


//////////////////////////////////////////*/

#ifndef SOLIDCOLOR_H
#define SOLIDCOLOR_H

bool red = false;
bool green = false;
bool blue = false;

void Red() {

  // Turn RED led ON
  analogWrite(RED, ON);     // Turns RED ON
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  analogWrite(BLUE, OFF);   // Turns BLUE OFF
  red = true;
}

void Green() {
  // Turn GREEN led ON

  analogWrite(RED, OFF);   // Turns RED OFF
  analogWrite(GREEN, ON);  // Turns GREEN ON
  analogWrite(BLUE, OFF);  // Turns BLUE OFF
  green = true;
}

void Blue() {
  // Turn BLUE led ON

  analogWrite(RED, OFF);    // Turns RED OFF
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  analogWrite(BLUE, ON);    // Turns BLUE ON
  blue = true;
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