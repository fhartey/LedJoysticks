#include "CommonEnums.h"
#include "ControlsDatabase.h"
#include "EprommSettings.h"
#include "Arduino.h"

// Initi the enums
AnimationEffect ControlsDatabase::_animationeffect = AnimationEffect::BREATHE;
JoystickColor ControlsDatabase::_joystickcolor = JoystickColor::RED;
TimerSelected ControlsDatabase::_timerselected = TimerSelected::THRITY_SEC;
long ControlsDatabase::AniIdle = 0;
bool ControlsDatabase::_animationLock = false;
bool ControlsDatabase::_JoyStickRandomStick = false;
bool ControlsDatabase::_BootUp = false;
const int ControlsDatabase::TimerAddress = 3;
const int ControlsDatabase::JoystickAddress = 1;
const int ControlsDatabase::AnimationEffectAddress = 2;

int ControlsDatabase::AnimatioMapColorCode[9] = {
    static_cast<int>(AnimationColorCode::ORANGE), static_cast<int>(AnimationColorCode::GREEN), static_cast<int>(AnimationColorCode::TURQOISE),
    static_cast<int>(AnimationColorCode::RED), static_cast<int>(AnimationColorCode::VIOLET), static_cast<int>(AnimationColorCode::BLUE),
    static_cast<int>(AnimationColorCode::RASPBERY), static_cast<int>(AnimationColorCode::CYAN),  static_cast<int>(AnimationColorCode::SPRING_GREEN)
};

int ControlsDatabase::arrTimerColorCode[10] = {
     static_cast<int>(TimerColorCode::RED), static_cast<int>(TimerColorCode::TURQOISE), static_cast<int>(TimerColorCode::GREEN),
    static_cast<int>(TimerColorCode::BLUE), static_cast<int>(TimerColorCode::VIOLET), static_cast<int>(TimerColorCode::ORANGE),
    static_cast<int>(TimerColorCode::SPRING_GREEN), static_cast<int>(TimerColorCode::CYAN),  static_cast<int>(TimerColorCode::RASPBERY),
     static_cast<int>(TimerColorCode::YELLOW)
};

JoystickColor ControlsDatabase::getJoystickColor()
{
    return _joystickcolor;
}

AnimationEffect ControlsDatabase::getAnimationEffect()
{
    return _animationeffect;
}

TimerSelected ControlsDatabase::getTimerSelected()
{
    return _timerselected;
}

void ControlsDatabase::setAnimationEffect(AnimationEffect _color)
{
    setBootUp(true);
    _animationeffect = _color;
}

void ControlsDatabase::setJoystickColor(JoystickColor _color)
{
    _joystickcolor = _color;
}

void ControlsDatabase::setTimerSelected(TimerSelected _timer)
{
    _timerselected = _timer;
}

void ControlsDatabase::setJoyStickRandomColorSwitcher(bool _value)
{
    _JoyStickRandomStick = _value;
}

void ControlsDatabase::setAnimationLock(bool _value)
{
    _animationLock = _value;
}

void ControlsDatabase::setAniIdle(long _aniidle)
{
    AniIdle = _aniidle;
}

void ControlsDatabase::setBootUp(bool value)
{
    _BootUp = value;
}

long ControlsDatabase::getAniIdle()
{
    return AniIdle;
}

bool ControlsDatabase::getJoyStickRandomColorSwitcher()
{
    return _JoyStickRandomStick;
}

bool ControlsDatabase::getAnimationLock()
{
    return _animationLock;
}

bool ControlsDatabase::getBootUp()
{
    return _BootUp;
}


void ControlsDatabase::setAniTimer(TimerSelected _SelectedEnum)
{

    switch (_SelectedEnum) {
    case TimerSelected::THRITY_SEC:
        setAniIdle(30000);
        //setAniIdle(5000);
        setTimerSelected(TimerSelected::THRITY_SEC);
      //  Serial.println("30 secs");
        break;

    case TimerSelected::ONE_MIN:
        setAniIdle(60000);
        setTimerSelected(TimerSelected::ONE_MIN);
        //Serial.println("1min");
        break;

    case TimerSelected::TWO_MIN:
        setAniIdle(120000);
        setTimerSelected(TimerSelected::TWO_MIN);
        // Serial.println("two_min");
        break;
    case TimerSelected::FIVE_MIN:
        setAniIdle(300000);
        setTimerSelected(TimerSelected::FIVE_MIN);
        //Serial.println("five min");
        break;

    case TimerSelected::SEVEN_MIN:
        setAniIdle(420000);
        setTimerSelected(TimerSelected::SEVEN_MIN);
        //Serial.println("seven ,min");
        break;

    case TimerSelected::TEN_MIN:
        setAniIdle(600000);
        setTimerSelected(TimerSelected::TEN_MIN);
        //Serial.println("Ten min");
        break;

    case TimerSelected::FIFTEEN_MIN:
        setAniIdle(900000);
        setTimerSelected(TimerSelected::FIFTEEN_MIN);
        //Serial.println("fifteen mins");
        break;

    case TimerSelected::TWENTY_MIN:
        setAniIdle(1200000);
        setTimerSelected(TimerSelected::TWENTY_MIN);
        break;

    case TimerSelected::TWENTYFIVE_MIN:
        setAniIdle(1500000);
        setTimerSelected(TimerSelected::TWENTYFIVE_MIN);
        //Serial.println("twentyfiver mis");
        break;
    case TimerSelected::THIRTYMIN_MIN:
        setAniIdle(1800000);
        setTimerSelected(TimerSelected::THIRTYMIN_MIN);
        //Serial.println("Thirty mins");
        break;
    default:
        //Serial.println("Defulated");
        break;
    }
}
