const int digitCount = 4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Please enter the first number:");
  int x = getNumber();
  Serial.println(x);
  flush();

  Serial.println("Please enter the second number:");
  int y = getNumber();
  Serial.println(y);
  flush();

  Serial.println("The result is:");
  Serial.println(x + y);

  Serial.println("———————————————————————————————");
}

int getNumber() {
  char numberString[digitCount];
  int index = 0;
  while (index < digitCount) {
    if (Serial.available()) {
      char ch = Serial.read();
      if (ch == '\n') break;
      numberString[index++] = ch;
    }
  }
  return atoi(numberString);
}

void flush() {
  delay(10); // Wait for the buffer to be filled.
  while (Serial.available()) {
    delay(10); // If another character is read, wait for an additional 10ms.
    Serial.read();
  }
}


