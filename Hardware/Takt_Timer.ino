const char compile_date[] = __DATE__ " " __TIME__;
const char heartbeat[] = "Heartbeat";
uint8_t switch1 = 2;
uint8_t switch2 = 3;
uint8_t heartbeatLen;


void setup() {

//Initiate Serial
Serial.begin(9600);
Serial.print("Takt Timer");
Serial.println(compile_date);

// Define Pin Maps
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
pinMode(LED_BUILTIN,  OUTPUT);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);

digitalWrite(12, HIGH); //debug setup

attachInterrupt(digitalPinToInterrupt(switch1),trigger_1,RISING);
attachInterrupt(digitalPinToInterrupt(switch2),trigger_2,RISING);

heartbeatLen = strlen(heartbeat);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.availableForWrite() > heartbeatLen){
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(11, HIGH); //debug main
    Serial.println(heartbeat);
    delay(1000);
    digitalWrite(12, LOW);  //debug setup
    digitalWrite(11, LOW);  //debug main
    digitalWrite(10, LOW);  //debug trigger_1
    digitalWrite(9, LOW);   //debug trigger_2
  }

  else{

    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void trigger_1() {
  delayMicroseconds(1000);
  Serial.println("Trigger 1");
  digitalWrite(12, LOW);  //debug setup
  digitalWrite(11, LOW);  //debug main
  digitalWrite(10, HIGH); //debug trigger
  return;
}

void trigger_2() {

  Serial.println("Trigger 2");
  digitalWrite(12, LOW);  //debug setup
  digitalWrite(11, LOW);  //debug main 
  digitalWrite(9, HIGH);  //debug trigger
}
