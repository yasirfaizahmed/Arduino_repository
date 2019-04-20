#include <math.h>
#include <dht.h>
#include<LiquidCrystal.h>
dht DHT;
#define DHT11_PIN 7
const int thermpin = A0;
LiquidCrystal lcd(12,11,5,4,3,2);
double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
//         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 return Temp;
}

void setup() {
  lcd.begin(16,2);
  pinMode(A0,INPUT);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  int h = (DHT.humidity);
  int t = (DHT.temperature );
  lcd.setCursor(0,0);
  lcd.print("t=");
  lcd.print(t);
  lcd.setCursor(4,0);
  lcd.print("h=");
  lcd.print(h);
  delay(100);
}
