// PIR Sensor pin connected to Arduino at pin 2
int PIRsensor = 2;
// Buzzer pin connected to Arduino at pin 13
int buzzerPin = 13;

void setup() {
  pinMode(PIRsensor, INPUT); // using PIR sensor as input
  pinMode(buzzerPin, OUTPUT); // using buzzer as output
  Serial.begin(9600);
}

void loop() {
  int motionDetected = digitalRead(PIRsensor);
  if (motionDetected == HIGH) {
    // If motion is detected
    Serial.println("Motion Detected! Activating Alarm...");
    tone(buzzerPin, 1000); // Activate the buzzer (adjust frequency as needed)
    delay(5000); // Delay before re-checking for motion
    noTone(buzzerPin);
    delay(100);
  }
}
