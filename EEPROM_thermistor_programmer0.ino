#include <math.h> 
const int T = A0;
int num = 0;
const int OE = 2;
const int WE = 3;
int Apin[] = {22,24,26,28,30,32,34,36,38,40}; //pins of arduino mega to the EEPROM adress pins.
int Dpin[] = {12,11,10,9,8,7,6,5};
byte data[16];
int val;     
double temp;

double Thermister(int RawADC)
{
double Temp;
Temp = log(((10240000/RawADC) - 10000));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = Temp - 273.15;           
return Temp;
}


void setup(){
  pinMode(T, INPUT);
  for(int i=0;i<10;i++)
    pinMode(Apin[i], OUTPUT);
  for(int i=0;i<7;i++)
    pinMode(Dpin[i], OUTPUT);
  pinMode(OE, OUTPUT);
  digitalWrite(OE, HIGH);
  pinMode(WE, OUTPUT);
    
  Serial.begin(9600);
  for(num=0;num<16;num++){ 
    for(int i=10;i>-1;i--){ 
      if(bitRead(num, i)==1) digitalWrite(Apin[i], HIGH); //bitread returns the ith bit of value num. 
      else digitalWrite(Apin[i], LOW);
    } 
    val=analogRead(T); 
    temp=Thermister(val);
    data[num] = temp;
    
    for(int i=7;i>-1;i--){
      if(bitRead(data[num], i)==1) digitalWrite(Dpin[i], HIGH);
      else digitalWrite(Dpin[i], LOW);
    }
    delay(10);
    digitalWrite(WE, LOW);delay(10); //pulse
    digitalWrite(WE, HIGH);delay(10);
    digitalWrite(WE, LOW);
    for(int i=7;i>-1;i--) digitalWrite(Dpin[i], LOW);
    delay(100);
  }
}


void loop(){
}
