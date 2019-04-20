const int in = 9;
const int led = 10;
void setup(){
  pinMode(in, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
int data = digitalRead(in);
  if(data==0){
    digitalWrite(led, LOW);
  }
  else if(data==1){
    digitalWrite(led, HIGH);
  }
}

