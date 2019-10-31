int C_I_Pin = 2;  //clk pin  //highest priority
volatile bool recieve = false;
volatile byte rx_byte = 0;
bool flag = true;
const int sec = 50;

void setup(){
  //pinMode(D_I_Pin, INPUT);
  pinMode(3, INPUT);
  pinMode(C_I_Pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(C_I_Pin), clk, RISING);  //Interrupt for clk
  //attachInterrupt(digitalPinToInterrupt(D_I_Pin), data, CHANGE);  //Interrupt for data  
  Serial.begin(9600);
}

void loop(){
  if(recieve == true){
    if(flag == false) delay(sec);
    if(flag == true){
      delay(2*sec);
      flag = false;
    }
    for(int bit_idx=0;bit_idx<8;bit_idx++){
      recieve = false;
      bool let_bit = digitalRead(3);
      //Serial.print(let_bit);
      //if(let_bit == false) Serial.print("0");
      if(let_bit == true) {
        //Serial.print("1");
        rx_byte |= (0x80 >> bit_idx);
      }
      delay(sec);
    }
    //Serial.print(" ");
    Serial.print(char(rx_byte));
    rx_byte = 0;
  }
}
void clk(){
  recieve  = true;
}

void data(){
  
}
