#ifndef __EprommSettings_h__
#define __EprommSettings_h__
#include "Arduino.h"
#include "CommonEnums.h"
#include <EEPROM.h>

class EprommSettings
{
public:

  static void setEpromSettings(EpromAddress addressEnum, JoystickColor JoystickEnum);
  static void setEpromSettings(EpromAddress addressEnum, AnimationEffect JoystickEnum);
  static void setEpromSettings(EpromAddress addressEnum, TimerSelected JoystickEnum);
  static void SetDefaultState();

private:
};
#endif
