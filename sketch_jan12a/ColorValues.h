#ifndef __ColorValues_h__
#define __ColorValues_h__

class ColorValues
{
public:

  int rVal = 0;
  int gVal = 0;
  int bVal = 0;
  int BreatheVal = 0;

  int rDir = -1;
  int gDir = 1;
  int bDir = -1;
  int BreatheSwitcher = 0;

  // constants to name the pins
  const int rPin = 11;
  const int gPin = 10;
  const int bPin = 9;
private:

};



#endif
