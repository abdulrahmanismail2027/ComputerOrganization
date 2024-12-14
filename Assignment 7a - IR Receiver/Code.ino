#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 3;
const int LED_PIN = 7;
unsigned long blinkRate;

unsigned long lastBlinkTime;
bool ledState;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(LED_PIN, OUTPUT);
  lastBlinkTime = 0;
  ledState = HIGH;
  blinkRate = 100;
}

void loop(){

  if (IrReceiver.decode()) 
  {
    const IRRawDataType IRSensorValue = IrReceiver.decodedIRData.decodedRawData;

    switch (IRSensorValue) {
      case 0xBA45FF00:
        blinkRate = 100;
        break;

      case 0xB946FF00:
        blinkRate = 200;
        break;

      case 0xB847FF00:
        blinkRate = 300;
        break;

      case 0xBB44FF00:
        blinkRate = 400;
        break;

      case 0xBF40FF00:
        blinkRate = 500;
        break;

      case 0xBC43FF00:
        blinkRate = 600;
        break;

      case 0xF807FF00:
        blinkRate = 700;
        break;

      case 0xEA15FF00:
        blinkRate = 800;
        break;

      case 0xF609FF00:
        blinkRate = 900;
        break;

      case 0xE619FF00:
        blinkRate = 0;
        break;

      case 0:
        Serial.println("Button is pushed down.");
        break;

      default:
        Serial.println("Unknown button pressed.");
    
    }
    IrReceiver.resume();
  }

  if (millis() - lastBlinkTime >= blinkRate) {
    ledState = !ledState;
    lastBlinkTime = millis();
  }

  digitalWrite(LED_PIN, ledState);
}