 #ifndef VisionSensor_h
#define VisionSensor_h 

#include <inttypes.h>
#include <Arduino.h>

class VisionSensor
{
  public:
   VisionSensor(HardwareSerial &uart, uint32_t baud = 115200);
   void begin(void);
   bool valid(void);
   void search(void);
   int getX(void);
   int getY(void);
   int getWidth(void);
   int getHeight(void);
   int detectScore(void);
   bool detected(void);
	
  private:
   HardwareSerial *m_puart;
   int dataDetected,ScoreH,ScoreL;
   int dataX,dataY,dataWidth,dataHeight;
   int comdata[50], data_p = 0; 
   uint32_t _baud;
   bool _valid;
};

#endif