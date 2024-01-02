const int pump =3;
const int soil_sensor =6;
int water; 
void setup() {
  pinMode(pump,OUTPUT); //output pin for relay board, this will sent signal to the relay
  pinMode(soil_sensor,INPUT); //input pin coming from soil sensor
  Serial.begin(9600);
}

void loop() { 
  water = digitalRead(soil_sensor);  // reading the coming signal from the soil sensor
  if(water == HIGH) // if water level is full then cut the relay 
  {
  digitalWrite(pump,HIGH); // low is to cut the relay
  Serial.println("the water pump is on");
  }
  else
  {
  digitalWrite(pump,LOW); //high to continue proving signal and water supply
  Serial.println("the water pump is off");
  }
  delay(4000); 
}
