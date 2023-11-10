#ifndef OUTPUT_H
#define OUTPUT_H

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
#endif