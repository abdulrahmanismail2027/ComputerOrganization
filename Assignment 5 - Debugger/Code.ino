const int latchPin = 12;

int previousState, currentState;
int x;

void setup() {
	Serial.begin(115200);
	pinMode(latchPin, INPUT_PULLUP);
	pinMode(LED_BUILTIN, OUTPUT);
	previousState = currentState = digitalRead(latchPin);
	x = 20;
}

void loop() {
	previousState = currentState;
	currentState = digitalRead(latchPin);
	Serial.print("Latch is ");
	Serial.println((currentState) ? "pulled up" : "pushed down");
	digitalWrite(LED_BUILTIN, !currentState);
	x++;
	delay(1000);
}
