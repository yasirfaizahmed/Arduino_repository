int a_pin[] = {22,24,26,28,30,32,34,36,38,40};
int d_pin[] = {5,6,7,8,9,10,11,12};
int disp[10] = {126,48,109,121,51,91,31,112,127,115};
const byte WE = 3;  //write enable
const int d = 100;

void setup(){ 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  for(int i=0;i<13;i++) pinMode(a_pin[i], OUTPUT);  //address pins
  for(int i=0;i<10;i++) pinMode(d_pin[i], OUTPUT);  //data pins
  pinMode(WE, OUTPUT);
  Serial.begin(9600);
  
  for(int addr=0;addr<256;addr++){  //go till address 255
    for(int addr_bit=7;addr_bit>-1;addr_bit--){  //we need 8 bit address to represent till 255(MSB first)
      if(bitRead(addr, addr_bit)  == 1) digitalWrite(a_pin[addr_bit], HIGH);
      else digitalWrite(a_pin[addr_bit], LOW);
    }
    
    for(int data_bit=7;data_bit>-1;data_bit--){
      if(bitRead(disp[addr%10], data_bit)  == 1) digitalWrite(d_pin[data_bit], HIGH);  //LS display
      else digitalWrite(d_pin[data_bit], LOW);
    }
    Serial.print(addr%10);
    Serial.print("  ");
    digitalWrite(WE, LOW);delayMicroseconds(1); //pulse
    digitalWrite(WE, HIGH);
    delay(d);
  }
  
void loop(){
}
