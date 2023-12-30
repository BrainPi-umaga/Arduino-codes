#include <Servo.h>
const int rain_module = 7;
const int buzzer = 2;

Servo my_servo;

void setup() {
  pinMode(rain_module, INPUT);
  pinMode(buzzer, OUTPUT);
  my_servo.attach(9);

  
}

void loop() {
  // Read the value from the rain sensor
  int sensorValue = digitalRead(rain_module);

  // Convert the analog sensor value to a voltage value (0-5V)


  // Check if it's raining based on the sensor value
  if (sensorValue == 1) {
    digitalWrite(buzzer, HIGH);

    // If it's raining, move the servo motor
    my_servo.write(85);  // Rotate the servo to 0 degrees position

   
  } else {
    my_servo.write(0);
  }

  delay(500);  // Add a small delay between sensor readings
}