const int probe = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(probe,INPUT);
}
void loop()
{
  float val = analogRead(probe);
  Serial.println(val);
  delay(50);
}

