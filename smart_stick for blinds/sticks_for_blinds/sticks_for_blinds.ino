// Define the pins for ultrasonic sensor
#define trigPin 7
#define echoPin 6
// Define the pin for the buzzer
#define buzzerPin 3

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // First sensor at 2 meters
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;


  // Sound the buzzer based on distances
  if ( distance <= 50) {
    digitalWrite(buzzerPin, HIGH); // Buzzer sound when an obstacle is detected
    delay(250);
    digitalWrite(buzzerPin, LOW);
    delay(250); 
  } 
  else if( distance <= 100) {
    digitalWrite(buzzerPin, HIGH); // Buzzer sound when an obstacle is detected
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500); 
  }
  else if( distance <= 200) {
    digitalWrite(buzzerPin, HIGH); // Buzzer sound when an obstacle is detected
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    delay(1000); 
  }
  else{
    digitalWrite(buzzerPin, LOW);
  }
}
