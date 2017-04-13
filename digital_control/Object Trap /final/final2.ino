
#include<Servo.h>
#include<math.h>

///pins for ultrasonic

int trigPin=13;
int echoPin=12;

long duration, velocity ;
long distance,oldDistance=0; 
 
//int objectNum=0;
long x,y;
double xRad,yRad;


///leds

int redLed=9;
int yellowLed=10;
int greenLed=11;
int buzzer=8;

// servo 

Servo myservo;    // object for the servo
int servoPosition=0;
int servoPin=7;



///// car motion 

int dir1 = 2;
int dir2 = 4;


void setup(){


    Serial.begin(9600);

    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    


/// led 
     pinMode(redLed,OUTPUT);
      pinMode(yellowLed,OUTPUT);
       pinMode(greenLed,OUTPUT);
        pinMode(buzzer,OUTPUT);






/// car
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);

 

    myservo.attach(servoPin); 

}




void loop(){
  
     delay(2000);

      // intial 
	
  for(servoPosition=0;servoPosition<180;servoPosition+=1){
	
    
    
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
  

        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
   
    
	duration = pulseIn (echoPin ,HIGH)  ;
  
	distance = duration/58;


  ///  calculte ths  velocity 
  
    velocity=distance-oldDistance;
  
       oldDistance=distance;
    
   if (distance <= 20 && distance!=0){
	
	
        
         servoPosition--;
         
        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print(" the servoPosition is : ");
        Serial.print(servoPosition);
        Serial.print("\n");
   
     Serial.print(" the    velocity  is : ");
        Serial.print(velocity);
        Serial.print("\n");
        
       
     ///  calculate the X and Y  of object 

      xRad=(servoPosition*3.14)/180;
      yRad=(servoPosition*3.14)/180;


        x=distance*cos(xRad);
        y=distance*sin(yRad);

      
  	Serial.print(" the distance in  X: ");
   Serial.print(x);
        Serial.print("\n");
        
  	Serial.print(" the distance  in Y: ");
   Serial.print(y);
        Serial.print("\n");
        
       

    }

  else if (distance>20 || distance==0)
	{
  Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
        
     Serial.print(" the    velocity  is : ");
        Serial.print(velocity);
        Serial.print("\n");
        
        
	Serial.print("NO objects ");

        Serial.print("\n");
}
        


staysafe();



if (distance<=20 && distance!=0)
  red();
 
 else if (distance>20&& distance <=50)
   yellow();
   
   else 
    green();

  
  
////  servo motion 

	myservo.write(servoPosition);      
        delay(200); 
    
    


	}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    delay(2000);




 for(servoPosition=180;servoPosition>=0;servoPosition-=1){
	
    
    
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
  

        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
   
    
	duration = pulseIn (echoPin ,HIGH)  ;
  
	distance = duration/58;
    
   if (distance <= 20 && distance!=0){
	
	//objectNum++;
        
         servoPosition++;
        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print(" the servoPosition is : ");
        Serial.print(servoPosition);
        Serial.print("\n");
   
       
     ///  calculate the X and Y  of object 

      xRad=(servoPosition*3.14)/180;
      yRad=(servoPosition*3.14)/180;


        x=distance*cos(xRad);
        y=distance*sin(yRad);

      
  	Serial.print(" the distance  of object from X: ");
   Serial.print(x);
        Serial.print("\n");
        
  	Serial.print(" the distance  of object from Y: ");
   Serial.print(y);
        Serial.print("\n");
        
       

    }

  else if (distance>20|| distance==0)
	{
  Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print("NO objects ");

        Serial.print("\n");
}
        



staysafe();



if (distance<=20 && distance!=0)
  red();
 
 else if (distance>20&& distance <=50)
   yellow();
   
   else 
    green();

////  servo motion 

	myservo.write(servoPosition);      
        delay(200); 
    
    


	}






//delay(5000);
}




void red(){
  
 digitalWrite(redLed,HIGH);
  digitalWrite(yellowLed,LOW);
   digitalWrite(greenLed,LOW);
    digitalWrite(buzzer,HIGH);
 
  
}

void yellow(){
  
 digitalWrite(redLed,LOW);
  digitalWrite(yellowLed,HIGH);
   digitalWrite(greenLed,LOW);
    digitalWrite(buzzer,HIGH);
     delay(700);
      digitalWrite(buzzer,LOW);
 
  
}


void green(){
  
 digitalWrite(redLed,LOW);
  digitalWrite(yellowLed,LOW);
   digitalWrite(greenLed,HIGH);
    digitalWrite(buzzer,LOW);
 
  
}






void staysafe(){



/// object  close to me   -ve velocity >>  move back         

/// object  move away from me     >>   +ve velocity  >> moveforward 

if(distance<30 && velocity < 0)
	move_back();

else if (distance<30 && velocity > 0)
    move_forward();


else if (distance>60 && distance<100 && velocity > 0)
    move_forward();

else if (distance>60 && distance<100 && velocity < 0)
    move_back();


else if (distance>=30 && distance<=60)
stop_motion();

else if (distance==0 || distance> 100)
	stop_motion();

else 
stop_motion();


}





void move_back(){


	 digitalWrite(dir1,HIGH);
     	 digitalWrite(dir2,LOW);


}



void move_forward(){

	digitalWrite(dir2,HIGH);
    	digitalWrite(dir1,LOW);


}




void stop_motion(){


	digitalWrite(dir2,LOW);
    	digitalWrite(dir1,LOW);



}

