#ifndef STARTUP_H
#define STARTUP_H


void startup() {

  pinMode(RED, OUTPUT);          // Sets RED to OUTPUT
  pinMode(GREEN, OUTPUT);        // Sets GREEN to OUTPUT
  pinMode(BLUE, OUTPUT);         // Sets BLUE to OUTPUT
  pinMode(TOUCH, INPUT_PULLUP);  // Sets TOUCH to INPUT_PULLUP
  delay(STARTUP * 2);            // Sets a DELAY OF x2 STARTUP

  // Initialize LED colors during startup
  //Turn RED ON
  analogWrite(RED, ON);     // Turns RED ON
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  analogWrite(BLUE, OFF);   // Turns BLUE OFF
  delay(STARTUP);           // Sets a DELAY OF STARTUP

  //Turn GREEN ON
  analogWrite(GREEN, ON);  // Turns GREEN ON
  analogWrite(RED, OFF);   // Turns RED OFF
  analogWrite(BLUE, OFF);  // Turns BLUE OFF
  delay(STARTUP);          // Sets a DELAY OF STARTUP

  //Turn BLUE ON
  analogWrite(BLUE, ON);    // Turns BLUE ON
  analogWrite(RED, OFF);    // Turns RED OFF
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  delay(STARTUP);           // Sets a DELAY OF STARTUP

  // Turn off all LEDs
  analogWrite(RED, OFF);    // Turns RED OFF
  analogWrite(GREEN, OFF);  // Turns GREEN OFF
  analogWrite(BLUE, OFF);   // Turns BLUE OFF
}
#endif