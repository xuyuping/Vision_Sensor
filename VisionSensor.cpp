/* morpx.inc copyright */

#include <VisionSensor.h>


VisionSensor::VisionSensor(HardwareSerial &uart, uint32_t baud): m_puart(&uart)
{
	_baud = baud;
	_valid = false;
}

void VisionSensor::begin(void)
{
  m_puart->begin(_baud);
  while (m_puart->available() > 0)
  {
    m_puart->read();
  }
}

bool VisionSensor::valid(void)
{
  return _valid;
}

void VisionSensor::routine(void)
{
  while(m_puart->available() > 0)
  {
    int dataByte = m_puart->read();
	
    if (dataByte == 0xFE)
    { 
      comdata[data_p] = dataByte;
	  int temp_p = data_p;
	  data_p = 0;
	  
      if (comdata[temp_p-1] == 0xFF)
      {
		dataDetected = comdata[0];
		ScoreH = comdata[1];
		ScoreL = comdata[2];
        dataX = comdata[3];
        dataY = comdata[4];
        dataWidth = comdata[5];
		dataHeight = comdata[6];
        _valid = true;
      }
      else
      {
        _valid = false;
      }
    }
    else
    {
      comdata[data_p] = dataByte ;
      data_p++ ;
    }
  }
}

bool VisionSensor::detected(void)
{
	if(dataDetected == 1)
	{
		return true;
	}
	
	return false;
}

int VisionSensor::detectScore(void)
{
  return (int)((ScoreH<<8)|ScoreL);
} 

int VisionSensor::getX(void)
{
  return dataX;
}

int VisionSensor::getY(void)
{
  return dataY;
}

int VisionSensor::getWidth(void)
{
  return dataWidth;
}

int VisionSensor::getHeight(void)
{
  return dataHeight;
}

