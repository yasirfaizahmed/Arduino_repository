int C_I_Pin = 2;  //clk pin with highest priority
int D_I_Pin = 3;  //data pin
volatile bool recieve = false;  //boolian flag for the interrupt
bool flag = true;
const int sec = 50;  //time constant(should be same for both transmitter and reciever)

void setup(){
  pinMode(D_I_Pin, INPUT);
  pinMode(C_I_Pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(C_I_Pin), clk, RISING);  //Interrupt for clk 
  Serial.begin(9600);
}

void loop(){
  if(recieve == true){
    if(flag == false) delay(sec);  //giving some delay so that reciever synchronyzes with transmitter
    if(flag == true){
      delay(2*sec);
      flag = false;
    }
    for(int bit_idx=0;bit_idx<8;bit_idx++){  //for ecery 8bits
      recieve = false;
      bool let_bit = digitalRead(3);
      if(let_bit == false) Serial.print("0");
      else if(let_bit == true) Serial.print("1");
      delay(sec);
    }
    Serial.println("  ");
  }
}
void clk(){  //ISR
  recieve  = true;
}

void data(){
  
}
