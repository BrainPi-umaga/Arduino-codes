// Define the flame sensor pin
const int flameSensorPin = 4;
// Define the buzzer pin
const int buzzerPin = 8;

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  pinMode(flameSensorPin,INPUT);
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the value from the flame sensor
  int sensorValue = digitalRead(flameSensorPin);

  // Print the sensor value to Serial monitor
  Serial.print("Flame sensor value: ");
  Serial.println(sensorValue);

  // Check if the sensor value crosses a certain threshold
  if (sensorValue == 0 ) { // You may need to adjust this threshold value based on your sensor and environment
    // If flame is detected, trigger the alarm
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Fire detected! Alarm activated!");
    delay(1000); // Delay for alarm sound
    digitalWrite(buzzerPin, LOW);
    delay(750); 
  } else {
    // If no flame is detected, turn off the alarm
    digitalWrite(buzzerPin, LOW);
  }

  delay(500); // Adjust the delay as needed for your application
}
