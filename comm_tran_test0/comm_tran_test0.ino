const int D_pin = 4;
const int C_pin = 3;
const char text[] = "MassEnergySpaceTime";
void setup(){
  pinMode(D_pin, OUTPUT);
  pinMode(C_pin, OUTPUT);
  Serial.begin(9600);
  for(int byte_idx=0;byte_idx<strlen(text);byte_idx++){
      Serial.print(text[byte_idx]);
      Serial.print(" ");
      byte let = text[byte_idx];
      for(int bit_idx=0;bit_idx<8;bit_idx++){
        bool let_bit = (let & (0x80 >> bit_idx));
        digitalWrite(D_pin, let_bit);
        Serial.print(let_bit);
        delay(50);
      }
      Serial.println("   ");
      digitalWrite(C_pin, LOW);
      delay(100);
      digitalWrite(C_pin, HIGH);
      delay(100);
      Serial.println("__--__");
      digitalWrite(C_pin, LOW);
  }
}
void loop(){
  
}
