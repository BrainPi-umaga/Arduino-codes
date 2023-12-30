const int irSensorPin = 2; // IR sensor output pin
const int buzzerPin = 3; // Buzzer pin

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int irSensorValue = digitalRead(irSensorPin);
  // digitalWrite(buzzerPin, LOW);


  if (irSensorValue == HIGH) {
    // IR sensor detects an obstacle (your hand or face)
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    delay(100); // Sound the alarm for 1 second
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    delay(200); 
  } else if (irSensorValue == LOW) {
    // IR sensor does not detect an obstacle (eyes open)
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  }
  delay(100);
}
