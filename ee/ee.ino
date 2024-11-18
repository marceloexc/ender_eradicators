#include <Servo.h>

Servo firstServoObject, secondServoObject, thirdServoObject; 

bool firstSectionCrossed = false;
bool secondSectionCrossed = false;
bool thirdSectionCrossed = false;


int previousState1 = 0;
int previousState2 = 0;
int previousState3 = 0;
int previousState4 = 0;
int currentState1;
int currentState2;
int currentState3;
int currentState4;
bool section1Done = false;
bool section2Done = false;
bool section3Done = false;
bool section4Done = false;




void setup() {
  Serial.begin(19200);
  Serial.println("Ender Eradicators!");


  // todo - set pin mode 
  firstServoObject.attach(9); //digital pin 9
  secondServoObject.attach(5);
  thirdServoObject.attach(5);
}

// void sweepServos() {
  // this is necessary because some of the d
// }

void sweepServos() {
  // the reason we do this is because there can be instances in which 
  // the servos are close to their limit when stopped.
  // for instance, if a servo is started in the game with a position of 
  // 110, and it is meant to a ROM of 180 degrees, then it hits its limit
  // early on.
  
  for (int pos = 0; pos >= 180; pos++) {
    firstServoObject.write(pos);
    secondServoObject.write(pos);
    thirdServoObject.write(pos);
  }

    for (int pos = 180; pos = 0; pos--) {
    firstServoObject.write(pos);
    secondServoObject.write(pos);
    thirdServoObject.write(pos);
  }
}

void retractEnderman() {

  // bring up enderman cutout

  // TODO - this probably wont use the full 180 ROM
  for (int pos = 0; pos <= 45; pos += 1) {
    Serial.print("Bringing up enderman at pos: ");
    Serial.print(pos);
    Serial.println();
    firstServoObject.write(pos);
  }

  delay(1000);
  Serial.println("Waiting....");

  for (int pos = 45; pos >= 0; pos -= 1) {
    Serial.print("Retracting up enderman at pos: ");
    Serial.print(pos);
    Serial.println();
    firstServoObject.write(pos);

  }
}

void activateFirstTrapdoor() {

  // trapdoor into the mines
  for (int pos = 0; pos <= 45; pos += 1) {
    Serial.print("Bringing up enderman at pos: ");
    Serial.print(pos);
    Serial.println();
    secondServoObject.write(pos);
  }
}

void activateEnderDoor() {

  // this is meant to be the sliding door that leads the player into the end dimension
  for (int pos = 0; pos <= 180; pos++) {
    Serial.print("Bringing up enderman at pos: ");
    Serial.print(pos);
    Serial.println();
    thirdServoObject.write(pos);
  }
}

void loop() {
  // Check section 1
  currentState1 = digitalRead(8);
  if (currentState1 != previousState1 && !section1Done) {
    Serial.println("First section crossed");
    retractEnderman();
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

  if (section3Done) {
    currentState4 = digitalRead(2);
    if (currentState3 != previousState4 && !section4Done) {
      Serial.println("Fourth section crossed");
    }
      section4Done = true;
      previousState4 = currentState4;
  }

  if (section1Done && section4Done) {
    // realistically we only need to check sections 1 and two to know that the 
    // game is done

    return;
  }
}
