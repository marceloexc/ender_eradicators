#include <Servo.h>

Servo firstServoObject, secondServoObject, thirdServoObject, fourthServoObject; 

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

  delay(500);
  firstServoObject.write(0);
  secondServoObject.write(0);
  fourthServoObject.write(100);

  // todo - set pin mode 
  firstServoObject.attach(9); //digital pin 9
  secondServoObject.attach(5);
  thirdServoObject.attach(5);
  fourthServoObject.attach(3);
  delay(2000);
  // sweepServos();

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
  for (int pos = 0; pos <= 95; pos += 1) {
    // delay(100);
    Serial.print("Bringing up enderman at pos: ");
    // delay(200);
    Serial.print(pos);
    Serial.println();
    firstServoObject.write(pos);
  }

  // delay(1000);
  // Serial.println("Waiting....");

  // for (int pos = 95; pos >= 0; pos -= 1) {
  //   // delay(100);
  //   Serial.print("Retracting up enderman at pos: ");
  //   Serial.print(pos);
  //   Serial.println();
  //   firstServoObject.write(pos);
  // }
  // delay(500);
}

void activateEnderDoor() {

  // this is meant to be the sliding door that leads the player into the end dimension
  for (int pos = 100; pos >= 10; pos -= 1) {
    // delay(100);
    Serial.print("Bringing up enderman at pos: ");
    // delay(200);
    Serial.print(pos);
    Serial.println();
    firstServoObject.write(pos);
  }

  delay(1000);
  Serial.println("Waiting....");

  for (int pos = 10; pos <= 100; pos += 1) {
    // delay(100);
    Serial.print("Retracting up enderman at pos: ");
    Serial.print(pos);
    Serial.println();
    firstServoObject.write(pos);
  }
  delay(500);
}

void loop() {
  // Check section 1
  retractEnderman();

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
