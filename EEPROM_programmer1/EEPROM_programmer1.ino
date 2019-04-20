int CE, OE, WE, a0, a1, a2, a3, a4, a5, a6, a7;
const int D0, D1, D2, D3, D4, D5, D6, D7;
int q = 0;
int bin[8];
int i = 0;
void setup(){
  pinMode(CE, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(WE, OUTPUT);
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(a5, OUTPUT);
  pinMode(a6, OUTPUT);
  pinMode(a7, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  //for(int k=0;k<=10;k++)
  //{
    //q = k;
    while(q>0){
      bin[i] = q%2;
      q = q/2;
      i++;
      delay(300);
    }
    for (int j = i - 1; j >= 0; j--) 
      Serial.print(bin[j]);
    Serial.print("   ");
    delay(1000);
  //}
}

