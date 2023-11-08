#if defined(__AVR_ATmega328P__)  // Check if compiling for ATmega328p (e.g., Arduino Nano)

#define RED 9     //  physical pin 13
#define GREEN 10  //  physical pin 14
#define BLUE 11   //  physical pin 15
#define TOUCH A3  //  physical pin 26

#elif defined(__AVR_ATtiny85__)  // Check if compiling for ATtiny85

#define RED 1    // PB1 physical pin 6
#define GREEN 0  // PB0 physical pin 5
#define BLUE 4   // PB4 physical pin 3
#define TOUCH 2  // PB2 physical pin 7
#elif defined(_ESP8266_)

#define RED 1    // PB1 physical pin 6
#define GREEN 0  // PB0 physical pin 5
#define BLUE 4   // PB4 physical pin 3
#define TOUCH 2  // PB2 physical pin 7
#else
#error "Unsupported board selected"

#endif
