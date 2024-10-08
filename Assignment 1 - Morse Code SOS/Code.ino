const unsigned long TIME_UNIT = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  pulses(3, 1);
  delay(3 * TIME_UNIT);

  pulses(3, 3);
  delay(3 * TIME_UNIT);

  pulses(3, 1);
  delay(7 * TIME_UNIT);
  
}

void signal(unsigned long factor) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(factor * TIME_UNIT);
  digitalWrite(LED_BUILTIN, LOW);
}

void pulses(int n, unsigned long duration) {
  for (int i = 0; i < n; i++) {
    signal(duration);
    if (i != n - 1) delay(TIME_UNIT);
  }
}