

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initTransfer();
}

void loop() {
  readButtons();
  sendData();
  delay(10);
}
