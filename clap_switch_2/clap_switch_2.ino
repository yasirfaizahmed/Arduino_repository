//https://www.youtube.com/user/greatscottlab

const int transistorpin = 3;
int sensorvalue=0;
int eventstatus = 0;
int sensorthresholdhigh = 720;
int sensorthresholdlow = 500;


void setup () {
  pinMode(transistorpin, OUTPUT);
}

void loop() { 
  eventstatus = 0;  
  sensorvalue = analogRead(A2);  
  delay(1);
  
  if(eventstatus==0){
    if(sensorvalue>sensorthresholdhigh){
      eventstatus=1;      
    }
  }
  
    if(eventstatus==1){  
    for(int k =10; k>0;k--){
      delay(10);
      sensorvalue=analogRead(A2);
      if(sensorvalue<sensorthresholdlow){
        eventstatus=2;
        break;
      }      
    }
  }
  
  if(eventstatus==2){
    for(int n=500;n>0;n--){
      delay(1);
      sensorvalue=analogRead(A2);
      if(sensorvalue>sensorthresholdhigh){
        eventstatus=3;
      break;
      }
      
    }
  }
  
  if(eventstatus==3){
    digitalWrite(transistorpin,HIGH);
  }







  eventstatus = 4;  
  sensorvalue = analogRead(A2);  
  delay(1);
  
  if(eventstatus==4){
    if(sensorvalue>sensorthresholdhigh){
      eventstatus=5;      
    }
  }
  
    if(eventstatus==5){  
    for(int k =10; k>0;k--){
      delay(10);
      sensorvalue=analogRead(A2);
      if(sensorvalue<sensorthresholdlow){
        eventstatus=6;
        break;
      }      
    }
  }
  
  if(eventstatus==6){
    for(int n=500;n>0;n--){
      delay(1);
      sensorvalue=analogRead(A2);
      if(sensorvalue>sensorthresholdhigh){
        eventstatus=8;
      break;
      }
      
    }
  }
  if(eventstatus==8){
    digitalWrite(transistorpin,LOW);
}
}
