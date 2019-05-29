const int a0 = 12;
const int a1 = 11;
const int a2 = 10;
const int a3 = 9;

void setup(){
  pinMode(a3, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a0, OUTPUT);  
}
void loop(){
  
    for(int i=0;i<=15;i++){
      switch(i){
        case 0:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 1:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(500);break;

        case 2:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 3:
        digitalWrite(a3,LOW);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(500);break;

        case 4:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 5:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(500);break;

        case 6:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 7:
        digitalWrite(a3,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(500);break;

        case 8:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 9:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(500);break;

        case 10:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 11:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(500);break;

        case 12:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 13:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,LOW);
        digitalWrite(a0,HIGH);
        delay(500);break;

        case 14:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,LOW);
        delay(500);break;

        case 15:
        digitalWrite(a3,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(a1,HIGH);
        digitalWrite(a0,HIGH);
        delay(500);break;
      }
    }
  }
