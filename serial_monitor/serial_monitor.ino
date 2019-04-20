const int inputPin=A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(inputPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int value=analogRead(inputPin);
Serial.println(value);
Serial.print("  ");
delay(50);
}
