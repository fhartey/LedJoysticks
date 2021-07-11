#pragma once
#ifndef __Color_h__
#define __Color_h__
#include "ColorValues.h"
class Color {
private:
    static void SetColorCode(int _red, int _green, int _blue, ColorValues& _colorvalues);
    //static void FiveVoltMode();
    //bool _fiveVoltMode = true;
    // when 5 volt 225 equals 0, and 0 = 255, if you use
    // ground switch back to 
    //int TwoFityFiveSwap = 255;
    //int ZeroSwap = 0;
 //   if 5V
    int TwoFityFiveSwap = 0;
    int ZeroSwap = 255;
public:
    static void SwitchColor(int num, ColorValues& rpin);

};
#endif
