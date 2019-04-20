#include <math.h>
#include <dht.h>
//#include<LiquidCrystal.h>
dht DHT;
#define DHT11_PIN 7
const int ThermistorPin = A0;
//LiquidCrystal lcd(12,11,5,4,3,2);
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  //lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  int Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  
    
  int chk = DHT.read11(DHT11_PIN);
  int h = (DHT.humidity);
  int t = (DHT.temperature );
  //lcd.setCursor(0,0);
  //lcd.print("h=");
  //lcd.print(h);
  //lcd.setCursor(4,0);
  //lcd.print("t=");
  //lcd.print(T);
  Serial.println(t);
}
