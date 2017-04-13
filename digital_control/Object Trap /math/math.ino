
#include <math.h>

float x;
float x2;
int i;

void setup(){
  
  Serial.begin (9600);
  
}

void loop(){
  
  
  x2=(50*3.14)/180;
  x= sinf(x2);
  Serial.print("    this is x :  ");
  Serial.print(x);
  
    delay(2000);
  
  
  
  
}
