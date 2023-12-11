#include <Servo.h>  //include servo library
//set up of variables and pins

Servo myservo;
int open = 90;
const int trigPin = 10;
const int echoPin = 11;
long duration;
float distance;

// set up of input and output
void setup() {
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.write(0);
}


void loop() {

  digitalWrite(trigPin, LOW); 
  delay(2);
  digitalWrite(trigPin, HIGH);  //sends signal for 10 microseconds 
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = 0.034 * (duration / 2); //expression will calculate the distance in cm.

//conditional statemnts 
  if (distance < 30) {

    myservo.write(open);  //lid gets open at 90 degree 
    delay(2000); 
  } 
  
  else {
    myservo.write(0);
  }
  
}
