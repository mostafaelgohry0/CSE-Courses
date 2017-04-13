int trigPin=12;

int echoPin=13;

 long duration ,distance,oldDistance=0;
 long v ;


void setup(){
  
  Serial.begin (9600);
 
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    
}

void loop (){
  
   //digitalWrite(trigPin,LOW);
    //delayMicroseconds(2);
  
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
     digitalWrite(trigPin,LOW);
     
    
  
  duration =  pulseIn (echoPin ,HIGH)  ;
    
  
  
  distance = duration/58 ;
  
  v=distance-oldDistance;
  
  oldDistance=distance;
  
  //Serial.print("  the time is : ");
  //Serial.print(duration);
  
  
  if(distance<200){
    
  Serial.print("  the distane is : ");
  
  
  Serial.print(distance);
  
  Serial.print("\n");
  
  }
  else
   Serial.print(" out of range  ");
  
  Serial.print("  the volicty  is : ");
  
  Serial.print(distance);
  
  Serial.print("\n\n");
  
  delay(700);
  
  
}
  
  
  
  
