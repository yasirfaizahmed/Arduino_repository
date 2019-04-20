const int in = 10;
const int in_ready = 11;
void setup(){
  pinMode(in, INPUT);
  Serial.begin(9600);
}

void loop(){
  int en = digitalRead(in_ready);
  if(en==1){
  for(int i=0;i<=7;i++){
int d = digitalRead(in);
  if(d==0)
  Serial.write("0");

  if(d==1)
  Serial.write("1");
}
Serial.print("  ");
}
}

