#include<Servo.h>

//variables
int distance  ;
long duration ;
int randomNumber ;

//distance sensor pins
const int echoPin = 11 ;
const int trigPin = 9  ;

//servo motor pins
const int servoPin1 = 7 ;
const int servoPin2 = 5 ;
const int servoPin3 = 3 ;

//Servo variables
Servo servoVariable1 ;
Servo servoVariable2 ;
Servo servoVariable3 ;

void setup() {
  Serial.begin(9600);

  //servo pin attachment
  servoVariable1.attach(servoPin1) ;
  servoVariable2.attach(servoPin2) ;
  servoVariable3.attach(servoPin3) ;

  //sensor pinn attachments
  pinMode(trigPin, OUTPUT) ; 
  pinMode(echoPin, INPUT)  ;
  
}

void loop() {

  int pos = 179 ;
  distance = returnDistance() ;
  Serial.println(distance) ;

  if(distance <= 20)
  {
    randomNumber = randomNumberGen(1,4) ;
    

    switch(randomNumber)
    {
      case 1 : servoVariable1.write(pos) ;
               delay(1000);

               pos = 90 ;
               
               servoVariable1.write(pos) ;
               delay(500);

               break;
               
      case 2 : servoVariable2.write(pos) ;
               delay(1000);

               pos = 90 ;
               
               servoVariable2.write(pos) ;
               delay(500);

               break;
               
      case 3 : servoVariable3.write(pos) ;
               delay(1000);

               pos = 90 ;
               
               servoVariable3.write(pos) ;
               delay(500);

               break;
    }
  }

}
int returnDistance()
{
  //clears trigger pin
  digitalWrite(trigPin, LOW) ;
  delayMicroseconds(2)       ;

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;

  return distance;
}

int randomNumberGen(int low,int high)
{
  int randNum ; 
  randNum = random(low,high);

  return randNum ;
}
