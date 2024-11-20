#include <Servo.h>

Servo firstServoObject, secondServoObject, thirdServoObject, fourthServoObject, fifthServoObject; 

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
int currentstate5;
bool section1Done = false;
bool section2Done = false;
bool section3Done = false;
bool section4Done = false;

void setup() {
  // Serial.begin(19200);
  Serial.println("Ender Eradicators!");

  delay(500);

  // 90-ish to get the diamond block
  // 130 to hide the view of the enderman
  firstServoObject.write(70);
  secondServoObject.write(0);
  thirdServoObject.write(145);
  fourthServoObject.write(100);
  fifthServoObject.write(0);

  // todo - set pin mode 
  firstServoObject.attach(6); //digital pin 9
  secondServoObject.attach(9);
  thirdServoObject.attach(5);
  fourthServoObject.attach(3);
  fifthServoObject.attach(10);
  delay(2000);
  // sweepServos();

}

void retractEnderman() {

  // bring up enderman cutout



  // TODO - this probably wont use the full 180 ROM
  for (int pos = 70; pos >= 0; pos -= 1) {
    Serial.print("Bringing up enderman at pos: ");
    Serial.print(pos);
    Serial.println();
    firstServoObject.write(pos);
  }

  delay(2000);
  // Serial.println("Waiting....");

  for (int pos = 0; pos <= 130; pos += 1) {
    // delay(50);
    Serial.print("Retracting up enderman at pos: ");
    Serial.print(pos);
    Serial.println();
    firstServoObject.write(pos);
  }
  delay(500);
}

void activateFirstTrapdoor() {

  // trapdoor into the mines
  for (int pos = 0; pos <= 76; pos += 1) {
    // delay(100);
    Serial.print("Bringing up enderman at pos: ");
    // delay(200);
    Serial.print(pos);
    Serial.println();
    secondServoObject.write(pos);
  }
}

void slideEnderDoor() {

  // bring up enderman cutout

  // TODO - this probably wont use the full 180 ROM
  for (int pos = 145; pos >= 50; pos -= 1) {
    // delay(100);
    Serial.print("Bringing up enderman at pos: ");
    // delay(200);
    Serial.print(pos);
    Serial.println();
    thirdServoObject.write(pos);
  }
}

void activateEnderTrapDoor() {

  // this is meant to be the sliding door that leads the player into the end dimension
  for (int pos = 100; pos >= 10; pos -= 1) {
    // delay(100);
    Serial.print("Bringing up enderman at pos: ");
    // delay(200);
    Serial.print(pos);
    Serial.println();
    fourthServoObject.write(pos);
  }
}

void killEnderDragon() {
    for (int pos = 0; pos <= 85; pos += 1) {
    // delay(100);
    Serial.print("Bringing up enderman at pos: ");
    // delay(200);
    Serial.print(pos);
    Serial.println();
    fifthServoObject.write(pos);
  }
}

void loop() {
  // Check section 1

  currentState1 = digitalRead(7);
  if (currentState1 != previousState1 && !section1Done) {
    Serial.println("First section crossed");
    retractEnderman();
    section1Done = true;
    previousState1 = currentState1;
  }

  // Check section 2 if section 1 is done
  if (section1Done) {
    currentState2 = digitalRead(8);
    if (currentState2 != previousState2 && !section2Done) {
      Serial.println("Second section crossed");
      activateFirstTrapdoor();
      section2Done = true;
      previousState2 = currentState2;
    }
  }

  // Check section 3 if section 2 is done
  if (section2Done) {
    currentState3 = digitalRead(4);
    if (currentState3 != previousState3 && !section3Done) {
      Serial.println("Third section crossed");
      slideEnderDoor();
      section3Done = true;
      previousState3 = currentState3;
    }
  }

  if (section3Done) {
    currentState4 = digitalRead(2);
    if (currentState4 != previousState4 && !section4Done) {
      Serial.println("Fourth section crossed");
      activateEnderTrapDoor();
      section4Done = true;
      previousState4 = currentState4;
    }
  }


  Serial.println(digitalRead(12));
  if (digitalRead(12)) {
    killEnderDragon();
  }



  // if (section4Done) {
  //   if (digitalRead(13)) {
  //     killEnderDragon();
  //   }
  // }

  // if (section1Done && section4Done) {
  //   // realistically we only need to check sections 1 and two to know that the 
  //   // game is done

  //   return;
  
}
