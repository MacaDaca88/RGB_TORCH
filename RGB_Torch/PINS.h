/*/////////////////////Pin Definitions////////////////////

Edit to suit each pin is PWM (RED,GREEN,BLUE)

TOUCH = analog INPUT_PULLUP


////////////////////////////////////////////////////////*/

#if defined(__AVR_ATmega328P__)|| (__AVR_ATmega168__)  // Check if compiling for ATmega328p (e.g., Arduino Nano)

#define RED 9     // PB1 physical pin 15
#define GREEN 10  // PB2 physical pin 16
#define BLUE 11   // PB3 physical pin 17
#define TOUCH A3  // PC3 physical pin 26

#elif defined(__AVR_ATtiny85__)  // Check if compiling for ATtiny85
// Burn Bootloader at 8MHz Internal Clock  For (1000ms = 1sec)

#define RED 1    // PB1 physical pin 6
#define GREEN 0  // PB0 physical pin 5
#define BLUE 4   // PB4 physical pin 3
#define TOUCH 2  // PB2 physical pin 7

#elif defined(ESP8266)  // Check if compiling for ESP8266 (e.g., Wemos D1 R2 & mini)

#define RED 14    // GPIO14 physical pin D5
#define GREEN 12  // GPIO12 physical pin D6
#define BLUE 13   // GPIO13 physical pin D7
#define TOUCH 2   // ADC physical pin A0

#elif defined(ESP32)  // Check if compiling for ESP32  (e.g., ESP32 38pin("ESP32 DEV module"))

#define RED 32    // GPIO32 physical pin 32
#define GREEN 33  // GPIO33 physical pin 33
#define BLUE 26   // GPIO26 physical pin 26
#define TOUCH 27  // GPIO27 physical pin 27

#else
#error "Unsupported board selected"

#endif
