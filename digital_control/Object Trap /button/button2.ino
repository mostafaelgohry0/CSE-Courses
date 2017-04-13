
const byte ledPin = 13;
const byte interruptPin = 2;
 byte state ;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  
}

void loop() {
  digitalWrite(ledPin, HIGH);
  if (digitalRead(interruptPin)==HIGH);
   digitalWrite(ledPin, LOW);
   
  
}


