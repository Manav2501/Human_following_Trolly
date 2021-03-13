#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 13 //attach pin D3 Arduino to pin Trig of HC-SR04
#define RechoPin 8 // attach pin D2 Arduino to pin Echo of HC-SR04
#define RtrigPin 9 //attach pin D3 Arduino to pin Trig of HC-SR04
#define LechoPin 10 // attach pin D2 Arduino to pin Echo of HC-SR04
#define LtrigPin 11 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration,Rduration,Lduration; // variable for the duration of sound wave travel
int distance,Rdistance,Ldistance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(RtrigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(RechoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(LtrigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(LechoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);
  
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm \t");
  ///////////////////////////////2nd///////////////////////////
  digitalWrite(RtrigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(RtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(RtrigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  Rduration = pulseIn(RechoPin, HIGH);
  // Calculating the distance
  Rdistance = Rduration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("RDistance: ");
  Serial.print(Rdistance);
  Serial.print(" cm \t");
  /////////////////////////////3rd//////////////////////////////
  digitalWrite(LtrigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(LtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(LtrigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  Lduration = pulseIn(LechoPin, HIGH);
  // Calculating the distance
  Ldistance = Lduration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("LDistance: ");
  Serial.print(Ldistance);
  Serial.println(" cm");
}
