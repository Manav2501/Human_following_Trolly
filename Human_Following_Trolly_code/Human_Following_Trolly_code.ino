#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);  // Rx,Tx
#define trigPin 13
#define echoPin 12
#define trigPinR 9
#define echoPinR 8
#define trigPinL 11
#define echoPinL 10

String msg = "";
long duration, distance, durationR, distanceR, durationL, distanceL;
int x;
int state = 7;
void setup() {
  
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(1,OUTPUT);
  digitalWrite(1,HIGH);
}

void loop() {
  if(state == 6){
        autoMode();
  }
  if(BTSerial.available()>0){ 
      msg = BTSerial.read();
      Serial.println(msg);
      if(state == 6){
        autoMode();
      }
      if(msg.equals("6")){    // auto mode
        state = 6;
        autoMode();
      }
      else if(msg.equals("7")){  // control mode
        state = 7;
      }
      else if(msg.equals("9")){  // Auto mode stop signal
        if(state == 6){
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(4,LOW);
          digitalWrite(7,LOW);
          delay(5000);
        }
      }
      else if(msg.equals("1")){  // Forward
        if(state == 7){
          digitalWrite(4,LOW);
          digitalWrite(6,LOW);
          digitalWrite(5,HIGH);
          digitalWrite(7,HIGH);
          delay(500);           // change delay acording to motor speed
        }
        else{
          if(state == 6){
            autoMode();
          }
        }
      }
      else if(msg.equals("2")){  // backward
        if(state == 7){
          digitalWrite(7,LOW);
          digitalWrite(5,LOW);
          digitalWrite(4,HIGH);
          digitalWrite(6,HIGH);
          delay(500);          // change delay acording to motor speed
        }
        else{
          if(state == 6){
            autoMode();
          }
        }
      }
      else if(msg.equals("3")){  // Left
        if(state == 7){
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(4,HIGH);
          digitalWrite(7,HIGH);
          delay(500);            // change delay acording to motor speed
        }
        else{
          if(state == 6){
            autoMode();
          }
        }
      }
      else if(msg.equals("4")){  // Right
        if(state == 7){
          digitalWrite(4,LOW);
          digitalWrite(7,LOW);
          digitalWrite(5,HIGH);
          digitalWrite(6,HIGH);
          delay(500);            // change delay acording to motor speed
        }
        else{
          if(state == 6){
            autoMode();
          }
        }
      }
      else if(msg.equals("5")){  // stop
        if(state == 7){
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(4,LOW);
          digitalWrite(7,LOW);
          delay(2000);            // change delay acording to motor speed
        }
        else{
          if(state == 6){
            autoMode();
          }
        }
      }
      else{
        if(state == 6){
          autoMode();
        }
      }
      
  }
}

void autoMode(){
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm center");
  if(distance > 30 && distance <= 80)       // forward
   {
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(7,HIGH);
    delay(200);
   }
  else if(distance <= 30 && distance >= 20)    // stop
   {
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(7,LOW);
    delay(200);
   }
  else if(distance < 20)                      // back
   {
    digitalWrite(5,LOW);
    digitalWrite(7,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    delay(200);
   }
  else if(distance > 80)
   {
      digitalWrite(trigPinR, LOW);  // Added this line
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPinR, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPinR, LOW);
      durationR = pulseIn(echoPinR, HIGH);
      distanceR = (durationR/2) / 29.1;
      Serial.print(distanceR);
      Serial.println(" cm right");
      if(distanceR < 50){       // Right
        digitalWrite(4,LOW);
        digitalWrite(7,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        delay(200);
      }
      else{
          digitalWrite(trigPinL, LOW);  // Added this line
          delayMicroseconds(10); // Added this line
          digitalWrite(trigPinL, HIGH);
          delayMicroseconds(10); // Added this line
          digitalWrite(trigPinL, LOW);
          durationL = pulseIn(echoPinL, HIGH);
          distanceL = (durationL/2) / 29.1;
          Serial.print(distanceL);
          Serial.println(" cm left");
          if(distanceL < 50){
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            digitalWrite(4,HIGH);
            digitalWrite(7,HIGH);
            delay(200);
        }
      }
   }
   else{
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      delay(1000);
    }
}
