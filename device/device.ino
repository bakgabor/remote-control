

void setup() {
  Serial.begin(9600); 
  Serial.println("start");
  initTransfer();
  Serial.println("init trans");
  innitControll();
  Serial.println("init controller");
}

void loop() {
  transferLoop();
  controllLoop();
}
