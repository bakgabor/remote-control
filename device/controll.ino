
// Szervo
// horizintal = map(horizintal, 0, 1023, 0, 180);
//
// Motor
// motorSpeed = map(motorSpeed, 0, 1023, 800, 2300);
// motor.writeMicroseconds(motorSpeed);

#include <Servo.h>

Servo horizintal;
Servo vertical;
Servo motor;

const int horizintalPin = 5;
const int verticalPin = 6;
const int motorPit = 7;

void innitControll() {
  horizintal.attach(horizintalPin);
  vertical.attach(verticalPin);
  motor.attach(motorPit);
  motorEnable();
}

void motorEnable() {
  motor.writeMicroseconds(2300);
  delay(2000);
  motor.writeMicroseconds(800);
  delay(6000);
}

void controllLoop() {
  int motorSpeed = map(getData(2), 0, 255, 800, 2300);
  motor.writeMicroseconds(motorSpeed);
 
  horizintal.write(map(getData(0), 0, 255, 0, 180));
 
  vertical.write(map(getData(1), 0, 255, 0, 180));
 // Serial.println(motorSpeed);
//  getData(2);
}

void reset() {
  motor.writeMicroseconds(800);
}
