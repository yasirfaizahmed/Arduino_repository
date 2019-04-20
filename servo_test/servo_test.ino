#include <Servo.h>
Servo myservo1;
void setup() {
  // put your setup code here, to run once:
myservo1.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
myservo1.write(35);
delay(1000);
myservo1.write(175);
delay(1000);
myservo1.write(35);
}
