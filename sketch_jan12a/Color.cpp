#include "Arduino.h"
#include "Color.h"
#include "ColorValues.h"
#include "ControlsDatabase.h"

void Color::SwitchColor(int num, ColorValues& _colorvalues)
{
    int TwoFityFiveSwap = 0;
    int ZeroSwap = 255;
    switch (num) {
    case 0: // red
        SetColorCode(TwoFityFiveSwap, ZeroSwap, ZeroSwap, _colorvalues);
        //  Serial.println("red");
        break;

    case 1: // orange
  //  Serial.println("orange");
        SetColorCode(TwoFityFiveSwap, 125, ZeroSwap, _colorvalues);
        break;

    case 2: // yello
  //   Serial.println("yellow");
        SetColorCode(TwoFityFiveSwap, 255, ZeroSwap, _colorvalues);
        break;

    case 3: // spring green
   // Serial.println(" spring green");
        SetColorCode(125, TwoFityFiveSwap, ZeroSwap, _colorvalues);
        break;

    case 4: // green
   // Serial.println("green");
        SetColorCode(ZeroSwap, TwoFityFiveSwap, ZeroSwap, _colorvalues);
        break;

    case 5: // turqoise
   // Serial.println("turqoise");
        SetColorCode(ZeroSwap, TwoFityFiveSwap, 125, _colorvalues);
     // SetColorCode(ZeroSwap, TwoFityFiveSwap, ZeroSwap, _colorvalues);
        break;

    case 6: //cyan
   // Serial.println("cyan");
        SetColorCode(ZeroSwap, TwoFityFiveSwap, TwoFityFiveSwap, _colorvalues);
        break;

    case 7: // ocean
   // Serial.println("ocean");
        SetColorCode(ZeroSwap, 125, TwoFityFiveSwap, _colorvalues);
        break;

    case 8:// blue
   // Serial.println("blue");
        SetColorCode(ZeroSwap, ZeroSwap, TwoFityFiveSwap, _colorvalues);
        break;
    case 9: //violet 
  //  Serial.println("viol");
        SetColorCode(125, ZeroSwap, TwoFityFiveSwap, _colorvalues);
        break;

    case 10: // magenta
   // Serial.println("magenta");
        SetColorCode(TwoFityFiveSwap, ZeroSwap, TwoFityFiveSwap, _colorvalues);
        break;

    case 11: // raspbery
    //Serial.println("raspbd");
        SetColorCode(TwoFityFiveSwap, ZeroSwap, 125, _colorvalues);
        break;
    case 12: // Random just center
        for (int i = 0; i <= 11; i++) {
            SwitchColor(i, _colorvalues);
            delay(100);
        }
        ControlsDatabase::setJoyStickRandomColorSwitcher(false);
        break;
    case 13: // Random all
        for (int i = 0; i <= 11; i++) {
            SwitchColor(i, _colorvalues);
            delay(100);
        }
        ControlsDatabase::setJoyStickRandomColorSwitcher(true);
        break;
    default:
        break;
        // add defualt here as of now giving error
    }
    analogWrite(_colorvalues.rPin, _colorvalues.rVal);
    analogWrite(_colorvalues.gPin, _colorvalues.gVal);
    analogWrite(_colorvalues.bPin, _colorvalues.bVal);
}

void Color::SetColorCode(int _red, int _green, int _blue, ColorValues& _colorvalues) {
    _colorvalues.rVal = _red;
    _colorvalues.gVal = _green;
    _colorvalues.bVal = _blue;
}
