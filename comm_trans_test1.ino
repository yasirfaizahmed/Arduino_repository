const int D_pin = 3;  //data pin
const int C_pin = 2;   //clock pin
const char text[] = "MassEnergySpaceTime";  //out data 
const int sec = 50;  //just a time constant
void setup(){
  pinMode(D_pin, OUTPUT);
  pinMode(C_pin, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(C_pin, HIGH);
  delay(sec);  //clock pulse
  digitalWrite(C_pin, LOW);
  
  for(int byte_idx=0;byte_idx<strlen(text);byte_idx++){  //going through each charecter from data
      byte let = text[byte_idx];  //equating each charecter as byte for bit operations
      for(int bit_idx=0;bit_idx<8;bit_idx++){  //going through each bit
        bool let_bit = (let & (0x80 >> bit_idx));  
        digitalWrite(D_pin, let_bit);
        Serial.print(let_bit);
        delay(sec);
      }
      Serial.println(" ");
      digitalWrite(C_pin, HIGH);
      delay(sec);  //clock pulse
      digitalWrite(C_pin, LOW);
   }
}
void loop(){
  
}
