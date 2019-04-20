const int micPin=A0;
const int outPin=9;
void setup()
{
  pinMode(micPin,INPUT);
  pinMode(outPin,OUTPUT);
  Serial.begin(115200);
}
void loop()
{
  int input=analogRead(micPin);
  Serial.print("input=");
  Serial.print(input);
  delay(30);
}

