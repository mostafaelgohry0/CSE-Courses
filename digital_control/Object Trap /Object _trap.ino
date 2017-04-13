
#include<Servo.h>
#include<math.h>       

///pins for ultrasonic
long duration, velocity;
long distance,oldDistance=0;	//Calculate the velocity v=distance-oldDistance
long x,y;			//  calculate  Coordinates  (x,y )
double xRad,yRad;		// convert servo position from degree to  radain 

///leds
int redLed = 9;
int yellowLed = 10;
int greenLed = 11;
int buzzer = 8;                 //To make alarm 

// servo 
Servo myservo;           //create servo object to control a servo 
                        // a maximum of eight servo objects can be created
int servoPosition=0;        // variable to store the servo position 
int servoPin=7;

///// car motion      to control the direction   
int dir1 = 3;
int dir2 = 4;
int statePin = 5;      //   switch  to swap between two module  ( open loop , closed loop)


void setup(){
  Serial.begin (9600); // Starts the Serial Communication for showing the results on the Serial Monitor
  pinMode(trigPin,OUTPUT); // Define Trigger Pin as an Output that sends the unltra sonic wave
  pinMode(echoPin,INPUT); // Defines Echo Pin as an Input that receives the reflected ultra sonic wave

/// leds 
 
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(buzzer,OUTPUT);

/// car
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(statePin,INPUT);
 

  myservo.attach(servoPin);          // Attaches the servo on pin 9 to the servo object 

}


void loop(){
  
     delay(2000);    // wait 2 seconds before starting

  if(digitalRead(statePin)== LOW){
   
       observe_object();   /// open loop 

}
        
  else if (digitalRead(statePin)== HIGH) {
  
	keep_trap_object();   //closed loop 

}

}

//////////////////////////////////////  functions  ////////////////////////////////////

void observe_object (){

    //Start servo motion 
	
  for(servoPosition=0;servoPosition<180;servoPosition+=1){

         // Check that the Trigger Pin is clear for 2 micro seconds
  	digitalWrite(trigPin,LOW);
  	delayMicroseconds(2);
  
  	// Generate the Ultra Sound Wave for 10 micro seconds
  	digitalWrite(trigPin,HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPin,LOW);
   
  // Using pulseIn function, we'll read the travel time and put that value in variable duration
  duration =  pulseIn (echoPin ,HIGH)  ; // read the travel time.. 
  /* the pulseIn function will wait for the echoPin to go high
   * caused by the reflected ultra sound wave, and it will start timing
   * then it will wait for the echoPin to go low, when the sound wave will end
   * which will stop the timing
   * At the end, the function will return length of the pulse in micro seconds
   */
  
	distance = duration*0.034/2; // sound velocity = 340 m/s = 0.043 cm/us distance is divided by 2 as the sound wave travels and returns 

  ///  calculte ths  velocity 
    	velocity=(distance-oldDistance)/.2;     /// .2 is the time of the loop 
  	oldDistance=distance;
    

   if (distance <= 100 && distance!=0){       

        servoPosition--;            // to keep the servo track the object 
                
     ///  calculate the X and Y  of object 

      xRad=(servoPosition*3.14)/180;   // convert servo position from degree to  radain 
      yRad=(servoPosition*3.14)/180;

        x=distance*cos(xRad);
        y=distance*sin(yRad);      

      
  //// print 

        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print(" the servoPosition is : ");
        Serial.print(servoPosition);
        Serial.print("\n");
   
        Serial.print(" the velocity  is : ");
        Serial.print(velocity);
        Serial.print("\n");
        
  	Serial.print(" the distance in  X: ");
        Serial.print(x);
        Serial.print("\n");
        
  	Serial.print(" the distance  in Y: ");
        Serial.print(y);
        Serial.print("\n\n\n");
        
       

    }


//// the object  out of the range  of sensor 
  else if (distance>100 || distance==0)
	{
        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
          
       // Serial.print(" the    velocity  is : ");
        //Serial.print(velocity);
        //Serial.print("\n");
        
	Serial.print("NO objects ");
        Serial.print("\n");
}
        



	///	staysafe();    //  keep object in yellow region 




if (distance<=30 && distance!=0)
  	red();       // to switch on  the red LED 
 
else if (distance>30&& distance <=60)
   	yellow();    // to switch on  the yellow LED
   
else  if (distance>60 && distance >=100)
    	green();

else 
        ledsoff();
  
////  servo motion 

	myservo.write(servoPosition);      
        delay(200); 
  
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


    delay(2000);      // wait 2 seconds until servo  move  in onther direction  


 for(servoPosition=180;servoPosition>=0;servoPosition-=1){   ///   move 180 degre 


        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
   
    
	duration = pulseIn (echoPin ,HIGH)  ;
  
	distance = duration/58;
  
 ///  calculte ths  velocity 

    	velocity=(distance-oldDistance)/.2;     /// .2 is the time of the loop 
  	oldDistance=distance;
    
  

   if (distance <= 100 && distance!=0){
	
	
         servoPosition++;  
  
     ///  calculate the X and Y  of object 

      xRad=(servoPosition*3.14)/180;
      yRad=(servoPosition*3.14)/180;

        x=distance*cos(xRad);
        y=distance*sin(yRad);


/// print 
        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print(" the servoPosition is : ");
        Serial.print(servoPosition);
        Serial.print("\n");
   
        Serial.print(" the velocity  is : ");
        Serial.print(velocity);
        Serial.print("\n");
        
  	Serial.print(" the distance in  X: ");
        Serial.print(x);
        Serial.print("\n");
        
  	Serial.print(" the distance  in Y: ");
        Serial.print(y);
        Serial.print("\n");
        

    }








//// the object  out of the range  of sensor 

  else if (distance>100|| distance==0){
 	Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print("NO objects ");
        Serial.print("\n");
  }
        





if (distance<=30 && distance!=0)
  	red();
 
else if (distance>30&& distance <=60)
 	yellow();
   
else if (distance>60 && distance >=100)
    	green();

else 
        ledsoff();




  //staysafe();             //  keep object in yellow region 



////  servo motion 

	myservo.write(servoPosition);      
        delay(200); 
    

}

}

void keep_trap_object(){


    // start  servo  motion 

	
  for(servoPosition=0;servoPosition<180;servoPosition+=1){

 Serial.print(" aaaaaaaaaaaaaaaaaaaaaa: ");
	
  
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);                     //wait 10 microseconds  
        digitalWrite(trigPin,LOW);
   
       duration = pulseIn (echoPin ,HIGH)  ;    // the duration that  signal take  to  return again to the ultrasonic
  
	distance = duration/58;                  ///  to obtain the distance  


  ///  calculte ths  velocity 

    	velocity=(distance-oldDistance)/.2;     /// .2 is the time of the loop 
  	oldDistance=distance;
    



   if (distance <= 100 && distance!=0){       

        servoPosition--;            // to keep the servo track the object 
         
        
       
     ///  calculate the X and Y  of object 

      xRad=(servoPosition*3.14)/180;   // convert servo position from degree to  radain 
      yRad=(servoPosition*3.14)/180;

        x=distance*cos(xRad);
        y=distance*sin(yRad);      

      


  //// print 

        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print(" the servoPosition is : ");
        Serial.print(servoPosition);
        Serial.print("\n");
   
        Serial.print(" the    velocity  is : ");
        Serial.print(velocity);
        Serial.print("\n");
        
  	Serial.print(" the distance in  X: ");
        Serial.print(x);
        Serial.print("\n");
        
  	Serial.print(" the distance  in Y: ");
        Serial.print(y);
        Serial.print("\n\n\n");
        
       

    }


//// the object  out of the range  of sensor 
  else if (distance>100 || distance==0)
	{
        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
          
       // Serial.print(" the    velocity  is : ");
        //Serial.print(velocity);
        //Serial.print("\n");
        
	Serial.print("NO objects ");
        Serial.print("\n");
  }
        





if (distance<=30 && distance!=0)
  	red();       // to switch on  the red LED 
 
else if (distance>30&& distance <=60)
   	yellow();    // to switch on  the yellow LED
   
else  if (distance>60 && distance >=100)
    	green();

else 
        ledsoff();
  



		staysafe();    //  keep object in yellow region 




////  servo motion 

	myservo.write(servoPosition);      
        delay(200); 
  

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


    delay(2000);      // wait 2 seconds until servo  move  in onther direction  


 for(servoPosition=180;servoPosition>=0;servoPosition-=1){   ///   move 180 degre 


        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
   
    
	duration = pulseIn (echoPin ,HIGH)  ;
  
	distance = duration/58;
  
 ///  calculte ths  velocity 

    	velocity=(distance-oldDistance)/.2;     /// .2 is the time of the loop 
  	oldDistance=distance;
    
  

   if (distance <= 100 && distance!=0){
	
	
         servoPosition++;  
  
     ///  calculate the X and Y  of object 

      xRad=(servoPosition*3.14)/180;
      yRad=(servoPosition*3.14)/180;

        x=distance*cos(xRad);
        y=distance*sin(yRad);


/// print 
        Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print(" the servoPosition is : ");
        Serial.print(servoPosition);
        Serial.print("\n");
   
        Serial.print(" the    velocity  is : ");
        Serial.print(velocity);
        Serial.print("\n");
        
  	Serial.print(" the distance in  X: ");
        Serial.print(x);
        Serial.print("\n");
        
  	Serial.print(" the distance  in Y: ");
        Serial.print(y);
        Serial.print("\n");
        

    }







//// the object  out of the range  of sensor 

  else if (distance>100|| distance==0){
 	Serial.print(" the    distance   is : ");
        Serial.print(distance);
        Serial.print("\n");
        
	Serial.print("NO objects ");
        Serial.print("\n");
  }
       



if (distance<=30 && distance!=0)
  	red();
 
else if (distance>30&& distance <=60)
 	yellow();
   
else  if (distance>60 && distance >=100)
    	green();

else 
        ledsoff();


 

  staysafe();             //  keep object in yellow region 



////  servo motion 

	myservo.write(servoPosition);      
        delay(200); 
  


}





}








   // to switch on  the red LED 
 
void red(){
  
 	digitalWrite(redLed,HIGH);
  	digitalWrite(yellowLed,LOW);
   	digitalWrite(greenLed,LOW);
    	digitalWrite(buzzer,HIGH);
  
}

   // to switch on  the yellow LED 
 

void yellow(){
  
 	digitalWrite(redLed,LOW);
  	digitalWrite(yellowLed,HIGH);
        digitalWrite(greenLed,LOW);
        //digitalWrite(buzzer,HIGH);
        // delay(700);
        digitalWrite(buzzer,LOW);
  
}

   // to switch on  the green LED 
 
void green(){
  
 	digitalWrite(redLed,LOW);
  	digitalWrite(yellowLed,LOW);
   	digitalWrite(greenLed,HIGH);
    	digitalWrite(buzzer,LOW);
 
}



void ledsoff(){


	digitalWrite(redLed,LOW);
  	digitalWrite(yellowLed,LOW);
   	digitalWrite(greenLed,LOW);
    	digitalWrite(buzzer,LOW);



}



/// object  close to me   -ve velocity >>  move back         

/// object  move away from me     >>   +ve velocity  >> moveforward 

void staysafe(){

if(distance<30 && velocity < 0)    ///the object close  to the car 
	move_back();

else if (distance<30 && velocity > 0)     ///the object   far from  the car
        move_forward();


else if (distance>60 && distance<100 && velocity > 0)       ///the object   far from  the car
   	 move_forward();

else if (distance>60 && distance<100 && velocity < 0)        ///the object close  to the car
    	move_back();

//  the object  in safe  region 
else if (distance>=30 && distance<=60)
	stop_motion();

else if (distance==0 || distance> 100)
	stop_motion();

else 
	stop_motion();

}

///  to move the  car  in back direction
void move_back(){

	 digitalWrite(dir1,HIGH);
    	 digitalWrite(dir2,LOW);
}

///  to move the  car  in forward direction
void move_forward(){

	digitalWrite(dir2,HIGH);
    	digitalWrite(dir1,LOW);
}

//  stop  the car 
void stop_motion(){

	digitalWrite(dir2,LOW);
    	digitalWrite(dir1,LOW);

}


