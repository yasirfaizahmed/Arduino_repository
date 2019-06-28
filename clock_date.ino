#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int sc = 0;
int mn;
int hr;
int D = 0;
int M = 0;
int Y = 19;
int d = 1;
const int mv_btn = 6;
const int inc_btn = 7;
int flag = 0;
const int DELAY = 1000;

void setup(){
    lcd.begin(16,2);
    pinMode(mv_btn, INPUT);
    pinMode(inc_btn, INPUT);
  }
  
  void loop(){
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
      if(flag==7) flag = 0;//resetting setting variable
    }
    if(digitalRead(inc_btn)==HIGH){
      if(flag==1) hr++;
      if(flag==2) mn++;
      if(flag==3) D++;
      if(flag==4) M++;
      if(flag==5) Y++;
      if(flag==6) d++;
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
}
