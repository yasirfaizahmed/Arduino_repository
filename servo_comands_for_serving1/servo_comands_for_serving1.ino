#include <Servo.h>
#include<math.h>
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
void setup()
{
  
  pinMode(11,OUTPUT);
  servo0.attach(11);
  

  pinMode(10,OUTPUT);
  servo1.attach(10);
  
  pinMode(9,OUTPUT);
  servo2.attach(9);
  
  pinMode(6,OUTPUT);
  servo3.attach(6);
}

void loop()
{
  for(int i=0;i<=359;i++)
  {
    float rad0=i*(3.14159/180);
    float val0=sin(rad0);
    float newval0=val0*1000;
    int angle0=map(newval0,-1000,1000,30,150);
    servo0.write(angle0);
    servo1.write(angle0);
    servo2.write(angle0);
    servo3.write(angle0);
    delay(5);
  }
}
