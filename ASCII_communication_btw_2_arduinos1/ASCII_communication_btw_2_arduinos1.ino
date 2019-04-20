const int out = 9;

void setup(){
  pinMode(out, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int x[] = {1,0,0,1,0,0,1,1};//d147
  for (int i=0;i<=7;i++){
    if(x[i]==1){
      digitalWrite(out, HIGH);
      Serial.print(x[i]);
      delay(1000);
    }
    else if(x[i]==0){
      digitalWrite(out, LOW);
      Serial.print(x[i]);
      delay(1000);
    }
  }
  Serial.print("  ");
}

