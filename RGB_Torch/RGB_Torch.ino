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
int longTouch = 0;              // Touch state variable
int oldLongTouch = 0;

int oldTouch = 0;
int counter = 0;
int modeCounter = 0;


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(TOUCH, INPUT_PULLUP);
  delay(STARTUP * 2);

  // Initialize LED colors during startup
  analogWrite(RED, ON);
  analogWrite(GREEN, OFF);
  analogWrite(BLUE, OFF);
  delay(STARTUP);

  analogWrite(GREEN, ON);
  analogWrite(RED, OFF);
  analogWrite(BLUE, OFF);
  delay(STARTUP);

  analogWrite(BLUE, ON);
  analogWrite(RED, OFF);
  analogWrite(GREEN, OFF);
  delay(STARTUP);

  // Turn off all LEDs
  analogWrite(RED, OFF);
  analogWrite(GREEN, OFF);
  analogWrite(BLUE, OFF);
}

void RedBrightness() {
  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, brightness);
    analogWrite(GREEN, OFF);
    analogWrite(BLUE, OFF);
    delay(FADE);  // Adjust the delay for the fading speed
  }
  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, brightness);
    analogWrite(GREEN, OFF);
    analogWrite(BLUE, OFF);
    delay(FADE);  // Adjust the delay for the fading speed
  }
}
void GreenBrightness() {
  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, OFF);
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, OFF);
    delay(FADE);  // Adjust the delay for the fading speed
  }
  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, OFF);
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, OFF);
    delay(FADE);  // Adjust the delay for the fading speed
  }
}
void BlueBrightness() {
  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, OFF);
    analogWrite(GREEN, OFF);
    analogWrite(BLUE, brightness);
    delay(FADE);  // Adjust the delay for the fading speed
  }
  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, OFF);
    analogWrite(GREEN, OFF);
    analogWrite(BLUE, brightness);
    delay(FADE);  // Adjust the delay for the fading speed
  }
}
void WhiteBrightness() {
  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(RED, brightness);
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, brightness);
    delay(FADE);  // Adjust the delay for the fading speed
  }
  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(RED, brightness);
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, brightness);
    delay(FADE);  // Adjust the delay for the fading speed
  }
}
void Red() {
  analogWrite(RED, ON);
  analogWrite(GREEN, OFF);
  analogWrite(BLUE, OFF);
}

void Green() {
  analogWrite(RED, OFF);
  analogWrite(GREEN, ON);
  analogWrite(BLUE, OFF);
}

void Blue() {
  analogWrite(RED, OFF);
  analogWrite(GREEN, OFF);
  analogWrite(BLUE, ON);
}

void White() {
  analogWrite(RED, ON);
  analogWrite(GREEN, ON);
  analogWrite(BLUE, ON);
}
void Off() {
  analogWrite(RED, OFF);
  analogWrite(GREEN, OFF);
  analogWrite(BLUE, OFF);
}
void input() {
  unsigned long time = millis();
  touch = digitalRead(TOUCH);
  longTouch = digitalRead(TOUCH);


  if (touch != oldTouch) {
    if (touch == HIGH) {
      counter++;
    }
    if (longTouch != oldLongTouch) {
      if (longTouch == HIGH) {
        if (time - oldTime >= hold) {
          oldTime = time;
          modeCounter++;
          Fader();
        }
        if (modeCounter >= ModeMax) {
          modeCounter = 0;
        }
      }
    }
    if (counter >= MAX) {
      counter = 0;
    } else {
      Mode();
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
  input();
}
