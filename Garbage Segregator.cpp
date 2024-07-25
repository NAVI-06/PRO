
#include <Servo.h>
Servo servo1;
int trigPin = 12;    
int echoPin = 11;
long duration,distance;
 
void setup() 
{
  Serial.begin(9600);
  servo1.attach(8);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(6,OUTPUT);
  
}
void loop() {
  int sensorValue = analogRead(A0);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance=0.0343*duration/2;
  Serial.print("distance =");
  Serial.print(distance);
  Serial.println("cm");
  Serial.println(sensorValue);
  delay(1000);
  if(distance <10)
  {
   digitalWrite(6 , HIGH); 
    if( sensorValue > 500 && sensorValue < 1000)
  {
    servo1.write(180);
      delay(1000);
  }
  if(sensorValue >300 && sensorValue <500)
  {
    servo1.write(0);
    delay(1000);
  }
  }
  else
  {
    digitalWrite(6, LOW);
    servo1.write(90);
  }
}