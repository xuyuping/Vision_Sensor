
/*******************************************
Adapt to visionsensor command 1.1 
morpx .inc
*******************************************/

#include "VisionSensor.h"

VisionSensor MU(Serial, 115200); 

void setup()
{
  MU.begin();
}

void loop()
{
  MU.routine();    

  if (MU.valid()>0)  
  { 
    if(MU.detected() == true)
    {
    Serial.print("detected score is:");
    Serial.println(MU.detectScore());
    Serial.print("Object detected at:");
    Serial.print(MU.getX());
    Serial.print(",");
    Serial.print(MU.getY());
    Serial.print(" with wdith of:");
    Serial.print(MU.getWidth()); 
    Serial.print(" and height of:");
    Serial.println(MU.getHeight());
    }
    else
    Serial.println("No object detected");
  }
  else
    Serial.println("No data or too many detected");

  delay(100);
}

