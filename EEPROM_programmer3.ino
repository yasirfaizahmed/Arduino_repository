int num;
const int OE = 2;
const int WE = 3;
int Apin[] = {22,24,26,28,30,32,34,36,38,40}; //pins of arduino mega to the EEPROM adress pins.
int Dpin[] = {12,11,10,9,8,7,6,5};
//String data[] = {"10000000","01000000","00100000","00010000","00001000","00000100","00000010","00000001","00000010","00000100","00001000","00010000","00100000","01000000","10000000","01000000"};
byte data[] = {3,5,7,2,4,1,0,9,8,3,5,4,6,9,8,10};

void setup(){
  for(int i=0;i<10;i++)
    pinMode(Apin[i], OUTPUT);
  for(int i=0;i<7;i++)
    pinMode(Dpin[i], OUTPUT);
  pinMode(OE, OUTPUT);
  //digitalWrite(OE, HIGH);
  pinMode(WE, OUTPUT);
    
  Serial.begin(9600);
  for(num=0;num<16;num++){ //go to address till 1024.
    for(int i=10;i>-1;i--){ //for 10_bit binary values.
      if(bitRead(num, i)==1) digitalWrite(Apin[i], HIGH); //bitread returns the ith bit of value num. 
      else digitalWrite(Apin[i], LOW);
    } 
    delay(100);
    digitalWrite(WE, LOW);delay(50); //pulse
    digitalWrite(WE, HIGH);delay(50);
    digitalWrite(WE, LOW);

    for(int i=8;i>-1;i--){
      if(bitRead(data[num], i)==1) digitalWrite(Dpin[i], HIGH);
      else digitalWrite(Dpin[i], LOW);
    }
    
  }
}


void loop(){
}
