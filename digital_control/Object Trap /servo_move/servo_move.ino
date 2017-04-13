// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

int stoppin =8;
int state;
 
void setup() 
{ 
   Serial.begin (9600);
 
  pinMode(stoppin,INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
}

 
 
void loop() 
{ 
  //state=0;
 // delay(100);
  
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(60);  
    
    // state=digitalRead(stoppin);
   // if(state==HIGH){
      
     // Serial.print("  this pos ");
      //Serial.print(pos);
       //break;
    //}
    
    // waits 15ms for the servo to reach the position 
  } 
  
  for(pos =180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(60);   
    // waits 15ms for the servo to reach the position 
  } 
  
  
  
} 
