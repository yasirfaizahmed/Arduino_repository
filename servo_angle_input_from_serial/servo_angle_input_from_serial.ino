#include <Servo.h>
#include<math.h>
String readString;
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
int angle0;
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
  Serial.begin(9600);
}

void loop()
{   
    angle0 = readString.toInt(); 
    angle0=Serial.read();
    servo0.write(angle0);
    delay(1000);
}

