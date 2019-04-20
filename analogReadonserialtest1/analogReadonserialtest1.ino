const int sensorPin=A3;
int flag=0;
int value=0;
int value1=0;
void setup()
{
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int value=analogRead(sensorPin);
  if(value>=500)
  {
    for(int i=0;i<300;i++)
    {
      int value1=analogRead(sensorPin);
      delay(50);
      if(value>=500)
      break;
    }
    flag=1;
  }
  Serial.println(value);
  Serial.println(value1);
  if(flag==1)
  {
    digitalWrite(3,HIGH);
  }
}

