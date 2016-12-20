
#include<Servo.h>
#include<math.h>

///pins for ultrasonic

int trigPin=12;
int echoPin=13;

double duration, volcity ;
double distance,olddistance; 
 
//int objectNum=0;
long x,y;
double xRad,yRad;

// servo 

Servo myservo;    // object for the servo
int servoPosition=0;
int servoPin=9;


void setup(){


    Serial.begin(9600);

    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);

    myservo.attach(9); 

}




void loop(){
  
     delay(2000);

      // intial 
	
  for(servoPosition=0;servoPosition<90;servoPosition+=1){
	

        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
   
    
	duration = pulseIn (echoPin ,HIGH)  ;
  
	distance = duration/58;
    
   if (distance <= 30 && distance!=0){
	
	//objectNum++;
     
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

      /*
  	Serial.print(" the distance  of object from X: ");
   Serial.print(x);
        Serial.print("\n");
        
  	Serial.print(" the distance  of object from Y: ");
   Serial.print(y);
        Serial.print("\n");
        
       */

    }

  else if (distance>30|| distance==0)
	{
  Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print("NO objects ");

        Serial.print("\n");
}
        


////  servo motion 

	myservo.write(servoPosition);      
        delay(1000); 
    
    


	}

//delay(5000);
}


