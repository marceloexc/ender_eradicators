#include <Servo.h>

Servo myServo; 

bool firstSectionCrossed = false;
bool secondSectionCrossed = false;
bool thirdSectionCrossed = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Ender Eradicators!");


  // todo - set pin mode 
  myServo.attach(9); //digital pin 9
}

void loop() {

  if (digitalRead(8) == 1) {
    firstSectionCrossed = true;
  }

  if (firstSectionCrossed) {
    Serial.println("First section crossed!");

    if (digitalRead(7) == 1) {
      secondSectionCrossed = true;
    }

      if (secondSectionCrossed) {
      Serial.println("Second section crossed!");

        if (digitalRead(4) == 1) {
          thirdSectionCrossed = true;
        }

        if (thirdSectionCrossed) {
        Serial.println("Third section crossed!");
      }
    }
  }
}