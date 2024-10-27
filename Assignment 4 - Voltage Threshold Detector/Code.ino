const int potentiometerPin = A0;
const int buzzerPin = 12;
const int buzzerFrequency = 1500;
const float voltageRatio = 5.0 / 1023;
const float upperThreshold = 3.0;
const float lowerThreshold = 2.5;

bool isExceeded = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  const float voltage = analogRead(potentiometerPin) * voltageRatio;
  Serial.println(voltage);
  if (voltage > upperThreshold || voltage > lowerThreshold && isExceeded) {
    isExceeded = true;
    tone(buzzerPin, buzzerFrequency);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    isExceeded = false;
    noTone(buzzerPin);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
