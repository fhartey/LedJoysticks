#ifndef __ColorAnimation_h__
#define __ColorAnimation_h__
#include "ColorValues.h"
#include "Color.h"
class ColorAnimation
{
public:

    static void Fade(ColorValues& _colorvalues, long _speed);
    static void Breathe(ColorValues& _colorvalues, long _speed);
    static void RandomBreathe(ColorValues& _colorvalues, long _speed);
    static void NoAnimation(ColorValues& _colorvalues, long _speed);
    static void Disco(ColorValues& _colorvalues, long _speed);
private:

    static long DiscoTimer;
    static int PrevColorAni;
    static void SetBreatheColor(ColorValues& _colorvalues, float smoothness_pts);
   static float pwm_valR;
  static  float pwm_valB;
  static  float pwm_valG;
};


#endif
