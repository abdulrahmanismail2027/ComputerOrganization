const int ledPin = 6;
const int potentiometerPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  const int potentiometerValue = analogRead(potentiometerPin);
  const int ledValue = map(potentiometerValue, 0, 1023, 0, 255);
  analogWrite(ledPin, ledValue);
}
