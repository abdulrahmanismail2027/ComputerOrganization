const int TEMP_SENSOR_PIN = A0;
const int LED_PIN = 7;
const int BUZZER_PIN = 8;

const int TEMP_LIMIT = 30;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  const int tempSensorPinValue = analogRead(TEMP_SENSOR_PIN);
  const float tempSensorValue = (((tempSensorPinValue / 1023.0) * 5) - 0.5) * 100;
  
  Serial.print("Temperature: ");
  Serial.print(tempSensorValue);
  Serial.println(" degree Celsius");


  if (tempSensorValue > TEMP_LIMIT) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 500, 500);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
