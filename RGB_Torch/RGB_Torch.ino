////////////////////////RGB TORCH////////////////////////
/*   Created by MacaDaca88

FreeUse licence 

Keep me here Dont be a Copy Kat ;(
Read Edit Learn   SHARE...............
*/
/////////////////////////////////////////////////////

#include "PINS.h"



// Fade Speed
#define FADE 10  // fade time

// Counter limits
#define MAX 5      // Max counter
#define ModeMax 5  // Max counter

// Reverse Logic for Common Anode
#define ON 0     // Reverse logic for RGB (LOW = ON)
#define OFF 255  // Reverse logic for RGB (HIGH = OFF)

// Delays
#define STARTUP 1000  // Delay for startup LED test
#define DEBUG 500
#define HOLD 1000  // Delay for button hold function

// Variables
int brightness = 0;         // Initial brightness
int fade = 5;               // Fade by 5 points (0-255)
unsigned long oldTime = 0;  // Store old time
int touch = 0;              // Touch state variable
int longTouch = 0;          // Touch state variable
int oldLongTouch = 0;

int oldTouch = 0;
int counter = 0;
int modeCounter = 0;
int FadeShow = 0;
int ModeSelect = 0;

#include "StartUp.h"
#include "ColorShift.h"
#include "SolidColor.h"
#include "DEBUG.h"

void setup() {
  // Initialize serial communication if availible
#if defined(ESP8266) || (ESP32) || (__AVR_ATmega328P__)||(__AVR_ATmega168__)
  Serial.begin(115200);  // Set the baud rate as needed
#endif
  startup();
}

void input() {

  // Decect TOUCH press long or short

  unsigned long time = millis();
  touch = digitalRead(TOUCH);
  longTouch = digitalRead(TOUCH);


  if (touch != oldTouch) {
    if (touch == HIGH) {  // if TOUCH is touched
      counter++;          //+1 to counter
    }
    counter %= MAX;
    if (longTouch != oldLongTouch) {
      if (longTouch == HIGH) {         // if TOUCH is longTouch
        if (time - oldTime >= HOLD) {  // If Touch HIGH >= 1000ms (hold)
          oldTime = time;              // reset time to 0
          modeCounter++;               // +1 to modeCOunter
          Fader();                     // Enter Fader() Loop
        }
        modeCounter %= ModeMax;
      }
    } else {
      Mode();  // Enter Mode() Loop
    }
  }
  oldTouch = touch;
  oldLongTouch = longTouch;
}
void Mode() {
  ModeSelect = counter;

  switch (ModeSelect) {
    case 0:
      White();
      break;
    case 1:
      Red();
      break;
    case 2:
      Green();
      break;
    case 3:
      Blue();
      break;
    case 4:
      Off();
      break;
  }
}
void Fader() {
  FadeShow = modeCounter;

  switch (FadeShow) {

    case 0:
      RedBrightness();
      break;
    case 1:
      GreenBrightness();
      break;
    case 2:
      BlueBrightness();
      break;
    case 3:
      WhiteBrightness();
      break;
  }
}

void loop() {
  input();  // Checks if TOUCH is active
  debug();
}
