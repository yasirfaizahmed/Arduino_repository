#include<Servo.h>
Servo servo;
void setup()
{
  pinMode(10,OUTPUT);
  servo.attach(9);
  Serial.begin(9600);
  servo.write(80);
}
void loop()
{
  //int angle = servo.read();
  //Serial.println(angle);
  delay(600);
  servo.write(93);
  delay(200);
  servo.write(93+35);
}
