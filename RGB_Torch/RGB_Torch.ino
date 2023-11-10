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
#define ModeMax 4  // Max modeCounter

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
#include "INput.h"

#include "ColorShift.h"
#include "SolidColor.h"
#include "OUTput.h"
#include "DEBUG.h"

void setup() {
  // Initialize serial communication if availible
#if defined(ESP8266) || (ESP32) || (__AVR_ATmega328P__) || (__AVR_ATmega168__)
  Serial.begin(115200);  // Set the baud rate as needed
#endif
  startup();
}

void loop() {
  input();  // Checks if TOUCH is active
  debug();
}
