int WE = 2;
int OE = 3;
const int a0 = 12;
const int a1 = 11;
const int a2 = 10;
const int a3 = 9;
int d0=31,d1=33,d2=35,d3=37,d4=39,d5=41,d6=43,d7=45;
String data[] = {"00000000","00000001","00000010","00000011","00000100","00000101","00000110","00000111","00001000","00001001","00001010","00001011","00001100","00001101","00001110","00001111"};

void pulse(){
  digitalWrite(WE,LOW);delay(50);
  digitalWrite(WE, HIGH);
  Clear();
  digitalWrite(OE,LOW);//
}

void Clear(){
  digitalWrite(d0, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  digitalWrite(d5, LOW);
  digitalWrite(d6, LOW);
  digitalWrite(d7, LOW);
}

int Write(String d){
  digitalWrite(OE,HIGH);//
  for(int i=0;i<=7;i++){
    switch(i){
    case 0: if(d[i]=='1') digitalWrite(d0,HIGH);
    else digitalWrite(d0,LOW);break;

    case 1: if(d[i]=='1') digitalWrite(d1,HIGH);
    else digitalWrite(d1,LOW);break;

    case 2: if(d[i]=='1') digitalWrite(d2,HIGH);
    else digitalWrite(d2,LOW);break;

    case 3: if(d[i]=='1') digitalWrite(d3,HIGH);
    else digitalWrite(d3,LOW);break;

    case 4: if(d[i]=='1') digitalWrite(d4,HIGH);
    else digitalWrite(d4,LOW);break;

    case 5: if(d[i]=='1') digitalWrite(d5,HIGH);
    else digitalWrite(d5,LOW);break;

    case 6: if(d[i]=='1') digitalWrite(d6,HIGH);
    else digitalWrite(d6,LOW);break;

    case 7: if(d[i]=='1') digitalWrite(d7,HIGH);
    else digitalWrite(d7,LOW);break;

    default: break;
    }
  }
}

void setup(){
  pinMode(a3, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a0, OUTPUT);
  
  pinMode(d0, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(d5, OUTPUT);
  pinMode(d6, OUTPUT);
  pinMode(d7, OUTPUT);  

  pinMode(OE, OUTPUT);
  pinMode(WE, OUTPUT);
}
void loop(){
  
    for(int i=0;i<=15;i++){
      switch(i){
        case 0:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 1:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 2:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 3:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 4:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 5:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 6:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 7:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 8:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 9:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 10:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 11:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 12:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 13:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 14:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(50);
        Write(data[i]);
        pulse();
        break;

        case 15:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(50);
        Write(data[i]);
        pulse();
        break;
      }
    }
  }
