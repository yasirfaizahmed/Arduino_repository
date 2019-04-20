const int probe = A0;
void setup()
{
  pinMode(probe,INPUT);
  Serial.begin(9600);
}
void loop()
{
  float analog0 = analogRead(probe);
  Serial.println(analog0);
  delay(1);
}

