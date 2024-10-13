const int greenLED = 3;
const int redLED = 4;
const int button = 2;

const int debounceFactor = 10;

int state = 0;
int isRed = HIGH;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int buttonState = !debounceDigitalRead(button);
  if (buttonState == HIGH && state % 2 == 0 || buttonState == LOW && state % 2 != 0) {
    state = (state + 1) % 4;
  }
  isRed = (state == 1)? LOW : ((state == 3)? HIGH : isRed);
  digitalWrite(redLED, isRed);
  digitalWrite(greenLED, !isRed);
}

int debounceDigitalRead(int pin) {
  int previousButtonState = digitalRead(button), currentButtonState;
  for (int i = 0; i < debounceFactor; i++) {
    currentButtonState = digitalRead(button);
    if (previousButtonState != currentButtonState) {
      i = 0;
    }
    previousButtonState = currentButtonState;
  }
  return currentButtonState;
}
