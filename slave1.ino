#include<LiquidCrystal.h>
const int trigger = 13;
const int echo = 10;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
 
  
}
void loop()
{
  int state = digitalRead(9);

  if(state == HIGH)
  {
    digitalWrite(13, HIGH);
    xD();
  }

  else
  digitalWrite(13, LOW);
}
void xD ()
{
  lcd.setCursor(0,0);
  float timee;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  timee = pulseIn(echo, HIGH);
  int distance = timee * 340/20000;
  if(distance>250)
  {
  lcd.setCursor(0,0);
    distance = 250;
  }
  Serial.println(distance);
  lcd.print("distance = ");
  lcd.print(distance);
  lcd.setCursor(14,0);
  lcd.print("cm");
   lcd.setCursor(5,1);
  lcd.print("SONAR");
  delay(100);
  lcd.clear();
}
