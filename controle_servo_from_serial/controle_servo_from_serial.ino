#include <Servo.h>
Servo servo1,servo2,servo3,servo4;
void setup()
{
  Serial.begin(9600);
  servo1.attach(12);
  servo2.attach(11);
  servo3.attach(10);
  servo4.attach(9);
  pinMode(13,OUTPUT);
  servo1.write(75);
}
void loop()
{
  if (Serial.available()>0)
  {
   int value=Serial.parseInt();
    servo1.write(value);
    Serial.print(value);
    delay(1000);
  }
  int novalue=Serial.read();
  if(novalue!=0)
  {
    int angle=servo1.read();
    servo1.write(angle);
  }
}
