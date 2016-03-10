//ARDUINO NANO V3.0

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created
 
int pos = 0;    // variable to store the servo position

int analogPin = A0;
int val; 
 
void setup()
{
  Serial.begin(9600);
  
  pinMode(analogPin,INPUT);
  pinMode(12,OUTPUT);
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
  
  myservo.write(pos);
  
}
 
void loop()
{
  val = analogRead(analogPin);    // read the input pin
  
  Serial.println(val);
  delay(1500);
   
   if (val > 0){
     for(pos = 0; pos < 75; pos += 1)  // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Serial.println(pos);
      //delay(50);
    }
    
        delay(1000);                       // waits 1s for the servo to reach the position
        
    for(pos = 75; pos >= 0; pos -=1)     // goes from 180 degrees to 0 degrees
    {                                
      myservo.write(pos);              // tell servo to go to position in variable 'pos'   
      Serial.println(pos); 
      //delay(50);      
    } 
   }
    
  
}
