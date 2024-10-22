const double stepSize = 0.1;
double x = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(sin(x));
  x += stepSize;
}
