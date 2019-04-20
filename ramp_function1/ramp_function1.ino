const int out = A0;
void setup()
{
  pinMode(out,OUTPUT);
}
void loop()
{
  for(int x=0;x<225;x++)
  {
    analogWrite(out,x);
    delay(1);
  }
}

