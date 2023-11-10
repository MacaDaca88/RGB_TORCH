
#ifndef COLORSHIFT_H
#define COLORSHIFT_H


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
#endif