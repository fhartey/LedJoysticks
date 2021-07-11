#include "Controls.h"
#include "Arduino.h"
#include "Color.h"
#include "ColorValues.h"
#include "ColorAnimation.h"
#include "ControlsDatabase.h"
#include "EprommSettings.h"

void Controls::JoyStickMovement(ColorValues& _colorvalue)
{

    ColorPickerControl(_colorvalue);
}

void Controls::JoyStickMovement(ColorValues& _colorvalue, SelectEnum _selectenum, int ButtonPin, int& ButtonHigh, int& ButtonLow)
{
    int ReadIn = digitalRead(ButtonPin);
    if (ReadIn != ButtonLow) {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (ReadIn != ButtonHigh) {
            ButtonHigh = ReadIn;
            if (JoyStickLock == true) {
                JoyStickLock = false;
                Color::SwitchColor(static_cast<int>(ControlsDatabase::getJoystickColor()), _colorvalue); // switch color back to where it is
            }
            else if (JoyStickLock == false) {
                JoyStickLock = true;
                EnumSelected(_selectenum, _colorvalue);
            }
        }
    }
    ButtonLow = ReadIn;
}




void Controls::EnumSelected(SelectEnum _selectenum, ColorValues& _colorvalue) {
    if (_selectenum == SelectEnum::ANIMATION_EFFECT) {
        int CurrentEnum = static_cast<int>(ControlsDatabase::getAnimationEffect());
        CurrentEnum++;

        if (CurrentEnum == static_cast<int>(AnimationEffect::LAST)) {
            ControlsDatabase::setAnimationEffect(static_cast<AnimationEffect>(0));
            Color::SwitchColor(ControlsDatabase::AnimatioMapColorCode[0], _colorvalue); // set color code
            EprommSettings::setEpromSettings(EpromAddress::AnimationColorEprom, static_cast<AnimationEffect>(0));
        }
        else {

            ControlsDatabase::setAnimationEffect(static_cast<AnimationEffect>(CurrentEnum));
            Color::SwitchColor(ControlsDatabase::AnimatioMapColorCode[CurrentEnum], _colorvalue); // set color code
            EprommSettings::setEpromSettings(EpromAddress::AnimationColorEprom, static_cast<AnimationEffect>(CurrentEnum));
        }
    }
    else if (_selectenum == SelectEnum::JOYSTICK_COLOR) {
        int CurrentEnum = static_cast<int>(ControlsDatabase::getJoystickColor());
        CurrentEnum++;
        if (CurrentEnum == static_cast<int>(JoystickColor::LAST)) {
            ControlsDatabase::setJoystickColor(static_cast<JoystickColor>(0));
            Color::SwitchColor(static_cast<int>(ControlsDatabase::getJoystickColor()), _colorvalue);
            EprommSettings::setEpromSettings(EpromAddress::JoystickColorEprom, static_cast<JoystickColor>(0));
        }
        else {
            ControlsDatabase::setJoystickColor(static_cast<JoystickColor>(CurrentEnum));
            Color::SwitchColor(static_cast<int>(ControlsDatabase::getJoystickColor()), _colorvalue);
            EprommSettings::setEpromSettings(EpromAddress::JoystickColorEprom, static_cast<JoystickColor>(CurrentEnum));
        }
    }
    else if (_selectenum == SelectEnum::TIMER_SELECTED)
    {
        int CurrentEnum = static_cast<int>(ControlsDatabase::getTimerSelected());
        CurrentEnum++;
        if (CurrentEnum == static_cast<int>(TimerSelected::LAST)) {
            ControlsDatabase::setAniTimer(static_cast<TimerSelected>(0));
            Color::SwitchColor(ControlsDatabase::arrTimerColorCode[0], _colorvalue);
            EprommSettings::setEpromSettings(EpromAddress::TimerSelectedEprom, static_cast<TimerSelected>(0));
        }
        else {
            ControlsDatabase::setAniTimer(static_cast<TimerSelected>(CurrentEnum));
            Color::SwitchColor(ControlsDatabase::arrTimerColorCode[CurrentEnum], _colorvalue); // set color code
            EprommSettings::setEpromSettings(EpromAddress::TimerSelectedEprom, static_cast<TimerSelected>(CurrentEnum));
        }

    }

}


void Controls::ColorPickerControl(ColorValues& _colorvalue) {
    if (ControlsDatabase::getJoystickColor() == JoystickColor::RANDOMCENTER
     || ControlsDatabase::getJoystickColor() == JoystickColor::RANDOMALL) {
            randNumber = random(0, 11);
            Color::SwitchColor(randNumber, _colorvalue);
     }
    else {
        Color::SwitchColor(static_cast<int>(ControlsDatabase::getJoystickColor()), _colorvalue);
    }
}



/* Not in use anymore but was pretty cool
void Controls::JoyStickMovement(ColorValues& _colorvalue, void(*_aniselect)(ColorValues& _colorvalue, long _anispeed), long _anispeed, int& ButtonPin, int& ButtonHigh, int& ButtonLow)
{
   // int ReadIn = digitalRead(ButtonPin);
    if (ButtonPin != ButtonLow) {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (ButtonPin != ButtonHigh) {
            ButtonHigh = ButtonPin;
            ColorPickerControl(_colorvalue);
        }
        if (((millis() - lastDebounceTime) > ControlsDatabase::getAniIdle()) && JoyStickLock != true) {
            _aniselect(_colorvalue, _anispeed);
            Serial.println("Anisleetc");
        }
    }
    ButtonLow = ButtonPin;
}*/
