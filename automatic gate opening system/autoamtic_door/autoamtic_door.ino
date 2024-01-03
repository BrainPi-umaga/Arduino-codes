#include <Servo.h>  // servo library to run servo

Servo door_Servo;  //declaration ofservo variable

// IR Sensor pin connected to Arduino
int IRsensor = 2;

void setup() {
  door_Servo.attach(9);       // Attach servo to pin 9
  pinMode(IRsensor, INPUT);  //using ir sensor as input
  Serial.begin(9600);
}

void loop() {
  int IRValue = digitalRead(IRsensor);
  if (IRValue == HIGH) {
    // If IR sensor detects an object
    Serial.println("Object Detected! Gate Opening...");
    door_Servo.write(90);  // Open door  (servo angle adjustment may vary)
    delay(5000);          // Delay for door opening time


  } else if (IRValue == LOW) {
    //if ir sensor don't find anyobject 
    door_Servo.write(0);  // Close door (servo angle adjustment may vary)
    Serial.println("Gate Closed.");
  }
}
