//https://www.youtube.com/user/greatscottlab

const int transistorpin = 3;
int sensorvalue=0;
int eventstatus = 0;
int sensorthresholdhigh = 870;
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
    digitalWrite(transistorpin, !digitalRead(transistorpin));
  }
}
