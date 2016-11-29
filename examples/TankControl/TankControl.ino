
/*******************************************
Adapt to visionsensor command 1.1 
morpx .inc
*******************************************/

#include "VisionSensor.h"

Servo servoX;
int E1=5;    //PWM1 pin
int M1=4;    //motor1 pin
int E2=6;    //motor2 pin
int M2=7;    //PWM2 pin 
int Val=200;  //motor speed value

VisionSensor MU(Serial, 115200);   // define the object detection

void setup()
{
  MU.begin();   //initialize
  pinMode(M1, OUTPUT); 
  pinMode(M2, OUTPUT);
}

void loop()
{
  MU.routine();    

  if (MU.valid()>0)  
  { 
    if(MU.detected() == true)
    {
     if (MU.getX()<40){
        car_right();
        delay(100);
        }
     else if (MU.getX()>60){ 
        car_left();
        delay(100);
        }
     else 
        car_stop();
    }
    
    else
      Serial.println("No object detected");
      car_stop();
      
  }
  else
    Serial.println("No data or too many detected");
    car_stop();
  delay(50);
}

void car_foward()

{
      digitalWrite(M1,LOW);         
      analogWrite(E1, Val);   
      digitalWrite(M2,LOW);
      analogWrite(E2, Val);   
 }
 
 void car_back()
{
     digitalWrite(M1,HIGH);     
     analogWrite(E1, Val);   
     digitalWrite(M2,HIGH);
     analogWrite(E2, Val);   
}

void car_left()
{
     digitalWrite(M1,HIGH);     
     analogWrite(E1, Val); 
     digitalWrite(M2,LOW);
     analogWrite(E2, Val);  
}

void car_right()
{
     digitalWrite(M1,LOW);     
     analogWrite(E1, Val);    
     digitalWrite(M2,HIGH);
     analogWrite(E2, Val);  
  }

void car_stop()
{
     digitalWrite(M1,LOW);     
     analogWrite(E1, 0);    
     digitalWrite(M2,LOW);
     analogWrite(E2, 0);
}  
