#include<math.h>
const int out = A0;
void setup()
{
  pinMode(out,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  for(int ang=0;ang<=360;ang++)
  {
    float rad = ang/57.29577951;
    float val = sin(rad);
    analogWrite(out,val*1023);
    Serial.println(val*1023);
    delay(10);
  }
}

