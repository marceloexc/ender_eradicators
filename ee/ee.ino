#include <Servo.h>

Servo myServo; 

bool firstSectionCrossed = false;
bool secondSectionCrossed = false;
bool thirdSectionCrossed = false;


int previousState1 = 0;
int previousState2 = 0;
int previousState3 = 0;
int currentState1;
int currentState2;
int currentState3;
bool section1Done = false;
bool section2Done = false;
bool section3Done = false;


void setup() {
  Serial.begin(9600);
  Serial.println("Ender Eradicators!");


  // todo - set pin mode 
  myServo.attach(9); //digital pin 9
}

void loop() {
  // Check section 1
  currentState1 = digitalRead(8);
  if (currentState1 != previousState1 && !section1Done) {
    Serial.println("First section crossed");
    section1Done = true;
    previousState1 = currentState1;
  }

  // Check section 2 if section 1 is done
  if (section1Done) {
    currentState2 = digitalRead(7);
    if (currentState2 != previousState2 && !section2Done) {
      Serial.println("Second section crossed");
      section2Done = true;
      previousState2 = currentState2;
    }
  }

  // Check section 3 if section 2 is done
  if (section2Done) {
    currentState3 = digitalRead(4);
    if (currentState3 != previousState3 && !section3Done) {
      Serial.println("Third section crossed");
      section3Done = true;
      previousState3 = currentState3;
    }
  }
}
