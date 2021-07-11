#ifndef __ControlsDatabase_h__
#define __ControlsDatabase_h__
#include "CommonEnums.h"

class ControlsDatabase
{
public:

  static JoystickColor getJoystickColor();
  static AnimationEffect getAnimationEffect();
  static TimerSelected getTimerSelected();
  static void setAnimationEffect(AnimationEffect _color);
  static void setJoystickColor(JoystickColor _color);
  static void setTimerSelected(TimerSelected _timer);
  static void setJoyStickRandomColorSwitcher(bool _value);
  static void setAnimationLock(bool _value);
  static void setAniIdle(long _aniidle);
  static void setBootUp(bool value);
  static int AnimatioMapColorCode[9];
  static int arrTimerColorCode[10];
  static long getAniIdle();
  static void setAniTimer(TimerSelected _selectedCase);
  static bool getJoyStickRandomColorSwitcher();
  static bool getAnimationLock();
  static bool getBootUp();
  static const int TimerAddress;
  static const int JoystickAddress;
  static const int AnimationEffectAddress;
private:
  static AnimationEffect _animationeffect;
  static JoystickColor _joystickcolor;
  static TimerSelected _timerselected;
  static long AniIdle;
  static bool _JoyStickRandomStick;
  static bool _animationLock;
  static bool _BootUp; // used for a couple boot things/ if someone clicks on the animation button for the user to see the animation real quick
};



#endif
