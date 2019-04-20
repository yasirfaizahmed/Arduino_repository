#include<math.h>
const int probe = A0;
const int out = 13;
void setup()
{
  pinMode(probe,INPUT);
  pinMode(out,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  for(int ang=0;ang<=360;ang++)
  {
    float rad = ang/57.29577951;
    float val = sin(rad);
    Serial.println(val*1023);
    analogWrite(out,val*1023);
    float analog0 = analogRead(probe);
    Serial.println(analog0);
    delay(1);
  }
}

