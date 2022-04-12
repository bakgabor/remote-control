
const int horizintalPin = 1;
const int verticalPin = 2;
const int torquePin = 0;

int horizintal;
int vertical;
int torque;

void readButtons() {
  horizintal = analogRead(horizintalPin);
  setData(0, map(horizintal, 0, 1023, 0, 255));

  vertical = analogRead(verticalPin);
  setData(1, map(vertical, 0, 1023, 0, 255));

  torque = analogRead(torquePin);
  setData(2, map(torque, 0, 1023, 0, 255));
  Serial.println(map(torque, 0, 1023, 0, 255));
  
}
