#include <math.h>
#include <dht.h>
dht DHT;
#define DHT11_PIN 7
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //int Vo = analogRead(ThermistorPin);
  //R2 = R1 * (1023.0 / (float)Vo - 1.0);
  //logR2 = log(R2);
  //T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  //T = T - 273.15;
  
  int chk = DHT.read11(DHT11_PIN);
  int h = (DHT.humidity);
  int t = (DHT.temperature );
  Serial.println("t = ");
  Serial.println(t);
  Serial.println("  ");

  Serial.println("h = ");
  Serial.println(h);
  Serial.println("  ");
  }
