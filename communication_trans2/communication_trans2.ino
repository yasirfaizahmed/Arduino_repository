int OUT = 10;
int tx = 11;
int rx = 9;

int x[] = {1,0,1,0,1,0,1,0};
int loo = 1;
void setup(){
  pinMode(OUT, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  Serial.begin(9600);
}

void loop(){
  int flag = digitalRead(rx); 
  for(int i=0;i<=7;i++){
    if(flag==1){
    digitalWrite(tx, HIGH);
    
    if(x[i]==0){
      digitalWrite(OUT, LOW);//sending 0
      Serial.print("0");
    }
    if(x[i]==1){
      digitalWrite(OUT, HIGH);//sending 1
      Serial.print("1");
    }
    digitalWrite(tx, LOW);
    loo = 1;
    while(loo==1){
      flag = digitalRead(rx);
      if(flag==1)
      loo = 0;
    }
    //digitalWrite(tx, LOW);
    }
  }
  Serial.print("  ");
}

