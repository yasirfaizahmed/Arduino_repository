#include <dht.h>
#include<LiquidCrystal.h>
#include<math.h>
dht DHT;
#define DHT11_PIN 7
const int thermpin = A0;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(A0,INPUT);
}
double thermistor(int RawADC)
{
  double Temp;
  Temp = log(((10240000/RawADC)-10000));
  Temp = 1/(0.001129148+(0.000234125+(0.0000000876741*Temp*Temp))*Temp);
  Temp = Temp-273.15;
  return Temp;
}

void loop()
{ 
  int val;
  double temp;
  val = analogRead(A0);
  temp = thermistor(val);\
  int chk = DHT.read11(DHT11_PIN);
  float h = (DHT.humidity);
  float t = (DHT.temperature );
  lcd.setCursor(0,0);
  lcd.print("h=");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("t=");
  lcd.print((t+temp)/2);
  Serial.println(temp);
  delay(200);
}
