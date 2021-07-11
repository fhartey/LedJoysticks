#ifndef __Controls_h__
#define __Controls_h__
#include "Arduino.h"
#include "ColorValues.h"
#include "CommonEnums.h"
#include "ControlsDatabase.h"
#include "EprommSettings.h"
class Controls
{
public:
  //void JoyStickMovement(ColorValues& _colorvalue, void (*_aniselect)(ColorValues& _colorvalue, long _anispeed), long _anispeed, int &ButtonPin, int& ButtonHigh, int& ButtonLow);
  void JoyStickMovement(ColorValues& _colorvalue, SelectEnum _selectenum, int ButtonPin, int& ButtonHigh, int& ButtonLow);
  void JoyStickMovement(ColorValues& _colorvalue);
  void EnumSelected(SelectEnum _selectenum, ColorValues& _colorvalue);
private:
  void ColorPickerControl(ColorValues& _colorvalue);
  long randNumber;
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers;
  bool JoyStickLock = false; // remain this to holding down isnt true
};


#endif
