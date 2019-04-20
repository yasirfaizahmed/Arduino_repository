#include<Servo.h>
Servo servo1;
Servo servo2;
const int trigPin = 11;
const int echoPin = 10;
void setup()
{
  servo1.attach(13);
  servo2.attach(12);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int x;
  int y;
  float dista;
  for(y=0;y<180;y=y+10)
  {
    for(x=0;x<180;x++)
    {
      servo1.write(x);
      dista = calculateDistance();
      Serial.print(dista);
      delay(3);
    }
    for(x=180;x>0;x--)
    {
      servo1.write(x);
      dista = calculateDistance();
      Serial.print(dista);
      delay(3);
    }
    servo2.write(y);
    delay(3);
  }
  for(y=180;y>0;y=y-10)
  {
    for(x=0;x<180;x++)
    {
      servo1.write(x);
      dista = calculateDistance();
      Serial.print(dista);
      delay(3);
    }
    for(x=180;x>0;x--)
    {
      servo1.write(x);
      dista = calculateDistance();
      Serial.print(dista);
      delay(3);
    }
    servo2.write(y);
    delay(3);
  }
}
int calculateDistance()
{
  float duration;
  float distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}

