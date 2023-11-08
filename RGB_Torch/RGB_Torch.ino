#define RED 1    // PB1 physical pin 6
#define GREEN 0  // PB0 physical pin 7
#define BLUE 4   // PB4 physical pin 3
#define TOUCH 2  // PB2 physical pin 7

#define STARTUP 1000  // Delay for startup LED test
#define FADE 10       // fade time
#define MAX 5         // Max counter
#define ModeMax 5     // Max counter

#define ON 0     // Reverse logic for RGB (LOW = ON)
#define OFF 255  // Reverse logic for RGB (HIGH = OFF)

// Delays
const long hold = 1000;  // Delay for button hold function

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


void setup() {
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

void RedBrightness() {
  // Set RED to fade  255-0
  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, brightness);
    analogWrite(GREEN, OFF);  // Turns GREEN OFF
    analogWrite(BLUE, OFF);   // Turns BLUE OFF
    delay(FADE);              // Adjust the delay for the fading speed
  }
  // Set RED to fade 0-255 

  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, brightness);
    analogWrite(GREEN, OFF);  // Turns GREEN OFF
    analogWrite(BLUE, OFF);   // Turns BLUE OFF
    delay(FADE);              // Adjust the delay for the fading speed
  }
}
void GreenBrightness() {
  // Set GREEN to fade 255-0

  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, OFF);  // Turns RED OFF
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, OFF);  // Turns BLUE OFF
    delay(FADE);             // Adjust the delay for the fading speed
  }
  // Set GREEN to fade 0-255

  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, OFF);  // Turns RED OFF
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, OFF);  // Turns BLUE OFF
    delay(FADE);             // Adjust the delay for the fading speed
  }
}
void BlueBrightness() {
  // Set BLUE to fade 255-0

  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, OFF);    // Turns RED OFF
    analogWrite(GREEN, OFF);  // Turns GREEN OFF
    analogWrite(BLUE, brightness);
    delay(FADE);  // Adjust the delay for the fading speed
  }
  // Set BLUE to fade 0-255 

  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, OFF);    // Turns RED OFF
    analogWrite(GREEN, OFF);  // Turns GREEN OFF
    analogWrite(BLUE, brightness);
    delay(FADE);  // Adjust the delay for the fading speed
  }
}
void WhiteBrightness() {
  // Set WHITE to fade  255-0

  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, brightness);    // Set RED to fade 0-255 255-0
    analogWrite(GREEN, brightness);  // Set GREEN to fade 0-255 255-0
    analogWrite(BLUE, brightness);   // Set BLUE to fade 0-255 255-0
    delay(FADE);                     // Adjust the delay for the fading speed
  }
  // Set WHITE to fade 0-255 

  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, brightness);    // Set RED to fade 0-255 255-0
    analogWrite(GREEN, brightness);  // Set GREEN to fade 0-255 255-0
    analogWrite(BLUE, brightness);   // Set BLUE to fade 0-255 255-0
    delay(FADE);                     // Adjust the delay for the fading speed
  }
}
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
void input() {

  // Decect TOUCH press long or short

  unsigned long time = millis();
  touch = digitalRead(TOUCH);
  longTouch = digitalRead(TOUCH);


  if (touch != oldTouch) {
    if (touch == HIGH) {  // if TOUCH is touched
      counter++;          //+1 to counter
    }
    if (longTouch != oldLongTouch) {
      if (longTouch == HIGH) {         // if TOUCH is longTouch
        if (time - oldTime >= hold) {  // If Touch HIGH >= 1000ms (hold)
          oldTime = time;              // reset time to 0
          modeCounter++;               // +1 to modeCOunter
          Fader();                     // Enter Fader() Loop
        }
        if (modeCounter >= ModeMax) {  // Check if modeCounter >= ModeMax(5)
          modeCounter = 0;             // Reset modeCounter to 0
        }
      }
    }
    if (counter >= MAX) {  // Check if counter >= MAX(5)
      counter = 0;         // Reset counter to 0
    } else {
      Mode();  // Enter Mode() Loop
    }
  }
  oldTouch = touch;
  oldLongTouch = longTouch;
}
void Mode() {
  int ModeSelect = counter;

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
  int FadeShow = modeCounter;

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
}
