
//  check  button 



int button=9;
int led=12;
int state;

void setup(){
  
   pinMode(led,OUTPUT);
   pinMode(button,INPUT);
}



void loop(){
  
  state=digitalRead(button);
  
  if(state==1){
    delay(2000);
      digitalWrite(led,HIGH);
      delay(3000);
  }
      
      
      else{
        digitalWrite(led,LOW);
  
      }      

 
 
  
}
