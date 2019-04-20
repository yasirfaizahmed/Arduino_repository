const int out = 10;
const int out_ready = 11;
int x[] = {1,0,1,0,1,0,1,0};
void setup(){
  pinMode(out, OUTPUT);
  pinMode(out_ready, OUTPUT);
}

void loop(){
  delay(2000);
  digitalWrite(out_ready, HIGH);
  for(int i=0;i<=7;i++){
    if(x[i]==0){
      delay(1);
    digitalWrite(out, LOW);
    }
    if(x[i]==1){
      delay(1);
    digitalWrite(out, HIGH);
    }
  }
  digitalWrite(out_ready, LOW);
}

