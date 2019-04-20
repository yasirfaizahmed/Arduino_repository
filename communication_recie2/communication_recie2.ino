int IN = 10;
int rx = 11;
int tx = 9;
int loo;
int flag;
void setup(){
  pinMode(IN, INPUT);
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
  Serial.begin(9600);
}

void loop(){
    digitalWrite(tx, HIGH);
    for(int i=0;i<=7;i++){
      delay(10);
      loo = 1;
      while(loo==1){
        flag = digitalRead(rx);
        if(flag==1)
        loo = 0;
      }
      
      if(flag==1){
      int data = digitalRead(IN);
      
      if(data==0){
        Serial.write("0");
      }
      if(data==1){
        Serial.write("1");
      }
    }
    digitalWrite(tx, LOW);
  }
}

