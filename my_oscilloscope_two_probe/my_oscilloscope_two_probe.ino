const int probe0 = A0;
const int probe1 = A1;
const int probe2 = A2;
float val0, val1, val2;
void setup()
{
  Serial.begin(9600);
  pinMode(probe0, INPUT);
  pinMode(probe1, INPUT);
  pinMode(probe2, INPUT);
  
}
void loop()
{
  val0 = analogRead(probe0);
 val1 = analogRead(probe1);
 val2 = analogRead(probe2);
  Serial.print("X: "); Serial.print(val0); Serial.print("  ");
 Serial.print("Y: "); Serial.print(val1); Serial.print("  ");
  Serial.print("Z: "); Serial.print(val2); Serial.print("  ");
  Serial.println("uT");
}

