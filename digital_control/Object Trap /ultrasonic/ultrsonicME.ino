// Mahmoud Eidarous

int trigPin=12; // the Trigger of the Sensor is connected to any of the Digital Pins
int echoPin=13; // Same for the Echo

long duration, v;
int distance,oldDistance=0; // variables for calculating duration, distance and velocity

void setup(){
  
  Serial.begin (9600); // Starts the Serial Communication for showing the results on the Serial Monitor
  pinMode(trigPin,OUTPUT); // Define Trigger Pin as an Output that sends the unltra sonic wave
  pinMode(echoPin,INPUT); // Defines Echo Pin as an Input that receives the reflected ultra sonic wave

}

void loop (){
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

  v = distance - oldDistance;
  oldDistance = distance;
  
  Serial.print("Time: "); // Print the Duration the sound wave took to come back and hit the echo pin on the Serial Monitor
  Serial.print(duration); 
  
  if(distance < 30){
        
  Serial.print("Red Distance: ");
  Serial.print(distance);
  Serial.print("\n");
  
  }
  if(distance > 30 && distance <40 ){
  Serial.print("Yellow Distance: ");
  Serial.print(distance);
  Serial.print("\n");  
  }
  else{
  Serial.print("Out of range!  ");
  Serial.print("Velocity: ");
  Serial.print(v);
  Serial.print("\n\n");
  delay(700);
  }
}
