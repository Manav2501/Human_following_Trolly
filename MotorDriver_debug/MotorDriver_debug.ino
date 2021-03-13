void setup() {
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
            digitalWrite(4,LOW);
            digitalWrite(6,LOW);
            digitalWrite(5,HIGH);
            digitalWrite(7,HIGH);
            delay(3000);
            digitalWrite(5,LOW);
            digitalWrite(7,LOW);
            digitalWrite(4,HIGH);
            digitalWrite(6,HIGH);
            delay(3000);
            digitalWrite(4,LOW);
            digitalWrite(6,LOW);
            digitalWrite(5,LOW);
            digitalWrite(7,LOW);
            delay(3000);
}
