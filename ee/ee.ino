#include <Servo.h>

Servo myServo; 

void setup() {
  Serial.begin(9600);
  Serial.println("Ender Eradicators!");


  // todo - set pin mode 
  myServo.attach(9); //digital pin 9
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) { 
    Serial.print("Setting pos as: ");
    Serial.print(pos);
    Serial.println();
    myServo.write(pos);
    delay(200);                       // Waits 15ms 
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    Serial.print("Setting pos as: ");
    Serial.print(pos);
    Serial.println();
    myServo.write(pos);             
    delay(200);                      
  }
}