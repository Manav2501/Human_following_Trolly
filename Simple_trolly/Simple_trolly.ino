#define trigPin 13
#define echoPin 12
long duration, distance;
int x;
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}
void loop()
{
  y:
  {
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print(distance);
    Serial.println(" cm");
    if(distance > 20 && distance <= 60)
     {
      digitalWrite(4,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(7,HIGH);
      delay(100);
     }
    else if(distance <= 20 && distance >= 10)
     {
      digitalWrite(4,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(7,LOW);
      delay(500);
     }
    else if(distance < 10)
     {
      digitalWrite(5,LOW);
      digitalWrite(7,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(6,HIGH);
      delay(100);
     }
    if(distance > 60)
     {
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      delay(500);
      goto y;
     }
}
}
