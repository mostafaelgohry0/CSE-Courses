int motorPin = 3;
int dir1 = 2;
int dir2 = 7;
int poten =A0;
int sw =0;
int speed;
void setup() {
  // put your setup code here, to run once:
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(sw,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sw) == HIGH){
     digitalWrite(dir1,HIGH);
     digitalWrite(dir2,LOW);
  }else{
    digitalWrite(dir2,HIGH);
    digitalWrite(dir1,LOW);
  }
  speed = analogRead(poten) / 4.0;
  analogWrite(motorPin, speed);
  delay(20);
}


