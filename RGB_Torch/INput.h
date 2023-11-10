#ifndef INPUT_H
#define INPUT_H


bool Solid = false;
bool Fade = false;

void input() {

  // Decect TOUCH press long or short

  unsigned long time = millis();
  touch = digitalRead(TOUCH);
  longTouch = digitalRead(TOUCH);


  if (touch != oldTouch) {
    if (touch == HIGH) {  // if TOUCH is touched
      counter++;          //+1 to counter
      Solid = true;
    }
    counter %= MAX;
  }
  if (longTouch != oldLongTouch) {
    if (longTouch == HIGH) {         // if TOUCH is longTouch
      if (time - oldTime >= HOLD) {  // If Touch HIGH >= 1000ms (hold)
        oldTime = time;              // reset time to 0
        modeCounter++;               // +1 to modeCOunter
        Fade = true;
        Fader();  // Enter Fader() Loop
      }
      modeCounter %= ModeMax;
    } else {
      Mode();  // Enter Mode() Loop
    }
  }
  oldTouch = touch;
  oldLongTouch = longTouch;
}
#endif