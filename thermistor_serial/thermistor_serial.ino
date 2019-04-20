#include <math.h> 
void setup(){
  Serial.begin(9600);
}

double Thermister(int RawADC)
{
double Temp;
Temp = log(((10240000/RawADC) - 10000));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = Temp - 273.15;           
return Temp;
}

void loop(){
int val;     
double temp;   
val=analogRead(0); 
temp=Thermister(val);
Serial.println(temp);
Serial.print("  ");
delay(100);
}
