#include<LiquidCrystal.h>
#include <dht.h>
#include <math.h>
//const int T = A0;
const int alarm_out = 4;
const int mv_btn = 6;
const int inc_btn = 7;
dht DHT; 
#define DHT11_PIN 5
const int rs = 8, en = 13, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int sc = 0;
int mn;
int Am;
int Ah = 6;
int hr;
int D = 0;
int M = 0;
int Y = 19;
int d = 1;
int flag = 0;
const int DELAY = 687.5;//for 11Mhz occilator, change it to 1000 if u have 16Mhz oscillator

void setup(){
    lcd.begin(16,2);
    pinMode(mv_btn, INPUT);
    pinMode(inc_btn, INPUT);
    //pinMode(T, INPUT);
    pinMode(alarm_out, OUTPUT);
  }

/*double Thermister(int RawADC)
{
double Temp;
Temp = log(((10240000/RawADC) - 10000));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = Temp - 273.15;           
return Temp;
}*/
  
  void loop(){
    int chk = DHT.read11(DHT11_PIN);
    int h = (DHT.humidity);
    //int val;     
    int t = (DHT.temperature);   
    //val=analogRead(T); 
    //t = Thermister(val);
    sc++;
    delay(DELAY);
    lcd.clear();
  
    //auto_clock
    if(sc==60){
      sc = 0;
      mn++;
    }
    if(mn==60){
      mn = 0;
      sc = 0;
      hr++;
    }
    if(hr==24){
    hr = 0;
    sc = 0;
    mn = 0;
    D++;
    d++;
    }
    if(D==31){
      D = 1;
      M++;
    }
    if(M==13){
      D = 1;
      M = 1;
      Y++;
    }
    if(d==8) d = 1;
    if(Ah==24) Ah = 0;
    if(Am==60) Am = 0;
  
    //manual_time_setting
    if(digitalRead(mv_btn)==HIGH){
      flag++;
      if(flag==1){//hr_increment
        lcd.setCursor(8,0);
        lcd.print("h");
      }
      if(flag==2){//min_increment
        lcd.setCursor(8,0);
        lcd.print("m");
      }
      if(flag==3){
        lcd.setCursor(8,0);
        lcd.print("D");
      }
      if(flag==4){
        lcd.setCursor(8,0);
        lcd.print("M");
      }
      if(flag==5){
        lcd.setCursor(8,0);
        lcd.print("Y");
      }
      if(flag==6){
        lcd.setCursor(8,0);
        lcd.print("d");
      }
      if(flag==7){
        lcd.setCursor(8,0);
        lcd.print("Ah");
      }
      if(flag==8){
        lcd.setCursor(8,0);
        lcd.print("Am");
      }
      if(flag==9) flag = 0;//resetting setting variable
    }
    if(digitalRead(inc_btn)==HIGH){
      if(flag==1) hr++;
      if(flag==2) mn++;
      if(flag==3) D++;
      if(flag==4) M++;
      if(flag==5) Y++;
      if(flag==6) d++;
      if(flag==7) Ah++;
      if(flag==8) Am++;
    }

    //time_placements
    lcd.setCursor(0,0);
    lcd.print(hr);
    
    lcd.setCursor(2,0);
    lcd.print(":");
    lcd.setCursor(3,0);
    lcd.print(mn);
    
    lcd.setCursor(5,0);
    lcd.print(":");
    lcd.setCursor(6,0);
    lcd.print(sc);

    //data_placements
    lcd.setCursor(0,1);
    lcd.print(D);
    
    lcd.setCursor(2,1);
    lcd.print("/");
    lcd.setCursor(3,1);
    lcd.print(M);
    
    lcd.setCursor(5,1);
    lcd.print("/");
    lcd.setCursor(6,1);
    lcd.print(Y);

    lcd.setCursor(8,1);
    switch(d){
      case 1: lcd.print("MN");break;
      case 2: lcd.print("TU");break;
      case 3: lcd.print("WE");break;
      case 4: lcd.print("TH");break;
      case 5: lcd.print("FR");break;
      case 6: lcd.print("SA");break;
      case 7: lcd.print("SU");break;
      default : lcd.print("MN");break;
    }
    if((flag==7)|(flag==8))
    {
        lcd.setCursor(11, 0);
        lcd.print(Ah);
        lcd.setCursor(13,0);
        lcd.print(":");
        lcd.setCursor(14,0);
        lcd.print(Am);
    }
    else{
      lcd.setCursor(12,0);
      lcd.print(t);
      lcd.print("C");
      lcd.setCursor(12,1);
      lcd.print(h);
      lcd.print("%");
    }
    if((hr==Ah)&(mn==Am)) digitalWrite(alarm_out, HIGH);
    else digitalWrite(alarm_out, LOW);
}
