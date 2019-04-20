#include <LiquidCrystal.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const int rs = 10, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
    lcd.begin(16, 2);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
    char text[10];
   if(radio.available())
   {
    radio.read(&text,sizeof(text));
    lcd.setCursor(0, 0);
    lcd.print(text[1]);
    delay(100);
    lcd.setCursor(4, 0);
    lcd.print(text[2]);
    delay(100);
    exit(0);
   }
  
  }
  
