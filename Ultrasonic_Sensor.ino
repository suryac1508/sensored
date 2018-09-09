const int trigPin =4;
const int echoPin =2;
const int led=13;                   
void setup() {  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.41; 
  if (distance >= 80 || distance <=0)
  {
    Serial.println("Out of range");
  }
  else
  {
   Serial.print(distance); 
   Serial.println(" cm");
  }
  delay(500);
  if(distance<=35){
    digitalWrite(led,HIGH);
    Serial.println("LED on");
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
