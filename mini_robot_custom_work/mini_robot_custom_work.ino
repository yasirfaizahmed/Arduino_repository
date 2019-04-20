#include<Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
void setup()
{
  //Serial.begin(9600);
  servo1.attach(11);
  servo2.attach(10);
  servo3.attach(9);
  servo4.attach(6);

  
}
void loop()
{
  int ang1 = random(45, 135);
  int ang2 = random(45, 135);
  int ang3 = random(45, 135);
  int ang4 = random(45, 135);
  //Serial.println(ang1);
  //Serial.println(ang2);
  //Serial.println(ang3);
  //Serial.println(ang4);
  servo1.write(ang1);
  delay(1000);
  servo2.write(ang2);
  delay(1000);
  servo3.write(ang3);
  delay(1000);
  servo4.write(ang4);
  delay(1000);
}

