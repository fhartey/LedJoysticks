#include "EprommSettings.h"
#include "ControlsDatabase.h"
void EprommSettings::setEpromSettings(EpromAddress addressEnum, JoystickColor JoystickEnum)
{
    EEPROM.update(static_cast<int>(addressEnum), static_cast<byte>(JoystickEnum));
   // Serial.println(EEPROM.read(static_cast<byte>(addressEnum)));

}

void EprommSettings::setEpromSettings(EpromAddress addressEnum, AnimationEffect JoystickEnum)
{
    EEPROM.update(static_cast<int>(addressEnum), static_cast<byte>(JoystickEnum));
    //Serial.println(EEPROM.read(static_cast<byte>(addressEnum)));

}

void EprommSettings::setEpromSettings(EpromAddress addressEnum, TimerSelected JoystickEnum)
{
    EEPROM.update(static_cast<int>(addressEnum), static_cast<byte>(JoystickEnum));
    //Serial.println(EEPROM.read(static_cast<byte>(addressEnum)));

}

void EprommSettings::SetDefaultState() {
    if (EEPROM.read(static_cast<byte>(EpromAddress::TimerSelectedEprom)) < 0 || EEPROM.read(static_cast<byte>(EpromAddress::TimerSelectedEprom)) > 9) {
        EEPROM.update(static_cast<int>(EpromAddress::TimerSelectedEprom), static_cast<byte>(0));
    }
    else {
        ControlsDatabase::setTimerSelected(static_cast<TimerSelected>(EEPROM.read(static_cast<byte>(EpromAddress::TimerSelectedEprom))));
    }

    if (EEPROM.read(static_cast<byte>(EpromAddress::JoystickColorEprom)) < 0 || EEPROM.read(static_cast<byte>(EpromAddress::JoystickColorEprom)) > 13) {
        EEPROM.update(static_cast<int>(EpromAddress::JoystickColorEprom), static_cast<byte>(0));
    }
    else {
        ControlsDatabase::setJoystickColor(static_cast<JoystickColor>(EEPROM.read(static_cast<byte>(EpromAddress::JoystickColorEprom))));
    }

    if (EEPROM.read(static_cast<byte>(EpromAddress::AnimationColorEprom)) < 0 || EEPROM.read(static_cast<byte>(EpromAddress::AnimationColorEprom)) > 8) {
        EEPROM.update(static_cast<int>(EpromAddress::AnimationColorEprom), static_cast<byte>(0));
    }
    else {
        ControlsDatabase::setAnimationEffect(static_cast<AnimationEffect>(EEPROM.read(static_cast<byte>(EpromAddress::AnimationColorEprom))));
    }
}
