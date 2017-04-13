

int trigPin=13;

int echoPin=12;

 long duration ,distance;


void setup(){
  
  Serial.begin (9600);
 
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    
}

void loop (){
  
     digitalWrite(trigPin,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin,LOW);
    
  
  duration =  pulseIn (echoPin ,HIGH)  ;
  
  distance = duration/50 ;
  
  //Serial.print("  the time is : ");
  //Serial.print(duration);
  
  Serial.print("  the distane is : ");
  Serial.print(distance);
  
  Serial.print("\n");
  
  delay(700);
  
  
}
  
