#include <Servo.h>
Servo servo1;
Servo servo2;

void setup()
{
  servo1.attach(13);
  servo2.attach(12);
  Serial.begin(9600);
  
  pinMode(6,OUTPUT);
}
void loop()
{
  int y,x;
  for(x=0;x<180;x=x+16)
  {
    servo2.write(x);
    delay(16); 
    
    for(y=0;y<180;y++)
    {
      servo1.write(y);
      digitalWrite(6,HIGH);
      delay(16);
      digitalWrite(6,LOW);   
    }
    for(y=180;y>0;y--)
    {
      servo1.write(y);
      delay(16);
      digitalWrite(6,HIGH);
     delay(16);
    digitalWrite(6,LOW);
         
    }
  }
  for(x=180;x>0;x=x-16)
  {
    servo2.write(x);
    delay(16);   
  }
       
    for(y=0;y<180;y++)
    {
      servo1.write(y);
      digitalWrite(6,HIGH);
      delay(16);
      digitalWrite(6,LOW);
         
    }
    for(y=180;y>0;y--)
    {
      servo1.write(y);
      digitalWrite(6,HIGH);
      delay(16);
      digitalWrite(6,LOW);
    } 
    
}
