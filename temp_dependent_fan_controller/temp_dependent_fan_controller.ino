#include <math.h> 
#include<LiquidCrystal.h>

const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal
lcd(rs,en,d4,d5,d6,d7);
const int motorPin=6;

byte degree[8]=
{
0b00011,
0b00011,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000
};

void setup()
{  
lcd.begin(16,2);
lcd.print("feeling hot?");
delay(3000);
lcd.createChar(1,degree);
}


double Thermister(int RawADC)
{
double Temp;
Temp = log(((10240000/RawADC) - 10000));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = Temp - 273.15;           
return Temp;
}

void loop()
{     
int val;     
double temp;   
val=analogRead(0); 
temp=Thermister(val);
lcd.setCursor(0,0);
lcd.print("temp=");
lcd.print(temp);
lcd.write(1);
lcd.print("C");
lcd.setCursor(0,1);

int flag = temp*100;
int speede = map(flag, 2700, 2900, 170, 255);
if(speede>=255)
speede = 255;
analogWrite(motorPin, speede);
if(temp>=29)
analogWrite(motorPin, 255);

lcd.setCursor(0,1);
lcd.print("Speed =");

lcd.print(speede*0.392);
lcd.print("%");

           
}


