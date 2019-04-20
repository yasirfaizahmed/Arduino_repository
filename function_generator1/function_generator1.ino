#include<math.h>
#include<Wire.h>
const int outPin = A1;
const int selectPin = 2;
const int freqPin = A2;
void setup()
{
  pinMode(10,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int res = analogRead(freqPin);
  int freq = map(res,0,1023,10,1000);
  for(int i=0;i<360;i++)
  { 
    float radian = (3.14159/180)*(i);
    float val = sin(radian);
    val = val*1000;
    Serial.println(val);
    analogWrite(outPin,val);
  }
}

