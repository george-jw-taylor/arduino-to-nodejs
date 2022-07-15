uint8_t VersionNo = 1;

uint8_t switch1 = 2;
uint8_t switch2 = 3;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("Takt Timer - v");
Serial.print(VersionNo);

pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);

attachInterrupt(digitalPinToInterrupt(switch1),trigger_1,RISING);
attachInterrupt(digitalPinToInterrupt(switch2),trigger_2,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("heartbeat");
  delay(1000);
}

void trigger_1() {

  Serial.println("Trigger 1");
}

void trigger_2() {

  Serial.println("Trigger 2");
}
