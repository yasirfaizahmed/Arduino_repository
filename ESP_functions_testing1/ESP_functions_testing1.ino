#include<ESP8266WiFi.h>
void setup(){
  WiFi.begin("yasir","1234567890");
  Serial.begin(9600);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  
  Serial.print("Local IP:");
  Serial.print(WiFi.localIP());
}

void loop(){
}
