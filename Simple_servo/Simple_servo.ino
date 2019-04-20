#include<Servo.h>
Servo hahaservo;

void setup(){
  hahaservo.attach(9);
  Serial.begin(9600);
}
void loop(){
  int val = Serial.read();
  delay(1000);
  hahaservo.write(val);
}
