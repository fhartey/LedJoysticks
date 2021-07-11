#include "ColorAnimation.h"
#include "Color.h"
#include "ColorValues.h"
#include "Controls.h"
#include "CommonEnums.h"
#include "ControlsDatabase.h"
#include "EprommSettings.h"
#include <EEPROM.h>
ColorValues _colorvalue;
Controls _controls;

const int buttonPins[] = { 2,3,4,5 };

bool BootUp = true;
bool AnimationLock = false;
int lastButtonState = 1;
long unsigned int lastPress;
volatile int buttonFlag;
int debounceTime = 20;

int CurrentJoystickPosition = -1;
int LastJoystickPosition = -1;

int button8 = 8;
int Highbutton8 = HIGH;
int Lowbutton8 = LOW;

int button12 = 12;
int Highbutton12 = HIGH;
int Lowbutton12 = LOW;

int button13 = 13;
int Highbutton13 = HIGH;
int Lowbutton13 = LOW;

ISR(PCINT2_vect) {
    buttonFlag = 1;

    for (int i = 0; i < 4; i++) {
        if (digitalRead(buttonPins[i]) == 0) {
            CurrentJoystickPosition = i;

        }
    }
}

void setup() {

    pinMode(_colorvalue.rPin, OUTPUT);
    pinMode(_colorvalue.gPin, OUTPUT);
    pinMode(_colorvalue.bPin, OUTPUT);

    PORTD = 0b00000000;
    PCICR = 0b00000100; // port D open pins 0 - 7
    PCMSK2 = 0b11111100; // pins 7 - 2 on

    EprommSettings::SetDefaultState();
    Color::SwitchColor(static_cast<int>(ControlsDatabase::getJoystickColor()), _colorvalue);
    ControlsDatabase::setAniTimer(ControlsDatabase::getTimerSelected());
    ControlsDatabase::setAnimationLock(false);
    ControlsDatabase::setBootUp(true);
    Serial.begin(9600);
    sei(); // Turns on our interupts
}



void loop() {
    if ((((millis() - lastPress) > ControlsDatabase::getAniIdle() && ControlsDatabase::getAnimationLock() != true)) || ControlsDatabase::getBootUp() == true) {
        PickFade();
    }
    else if (CurrentJoystickPosition != LastJoystickPosition && ControlsDatabase::getAnimationLock() == true
        && ControlsDatabase::getJoyStickRandomColorSwitcher() == true
        && (ControlsDatabase::getJoystickColor() == JoystickColor::RANDOMCENTER
            || ControlsDatabase::getJoystickColor() == JoystickColor::RANDOMALL)) {
        _controls.JoyStickMovement(_colorvalue);
        LastJoystickPosition = CurrentJoystickPosition;
    }

    if ((millis() - lastPress) > debounceTime && buttonFlag)
    {
        ControlsDatabase::setBootUp(false);

        lastPress = millis();
        if (digitalRead(buttonPins[CurrentJoystickPosition]) == 0 && lastButtonState == 1)    //if button is pressed and was released last change
        {
            AnimationLock = true;
            ControlsDatabase::setAnimationLock(true);
            _controls.JoyStickMovement(_colorvalue);

            lastButtonState = 0;
        }
        else if (digitalRead(buttonPins[CurrentJoystickPosition]) == 1 && lastButtonState == 0)
        {
            ControlsDatabase::setAnimationLock(false);
            _controls.JoyStickMovement(_colorvalue);
            lastButtonState = 1;    //record the lastButtonState
        }


        buttonFlag = 0;
    }

    _controls.JoyStickMovement(_colorvalue, SelectEnum::JOYSTICK_COLOR, button8, Lowbutton8, Highbutton8);
    _controls.JoyStickMovement(_colorvalue, SelectEnum::ANIMATION_EFFECT, button12, Lowbutton12, Highbutton12);
    _controls.JoyStickMovement(_colorvalue, SelectEnum::TIMER_SELECTED, button13, Lowbutton13, Highbutton13);
}
void PickFade() {

    switch (ControlsDatabase::getAnimationEffect()) {
    case AnimationEffect::FADE:
        ColorAnimation::Fade(_colorvalue, 33);
        break;

    case AnimationEffect::FAST_FADE:
        ColorAnimation::Fade(_colorvalue, 16);
        break;

    case AnimationEffect::BREATHE:
        ColorAnimation::Breathe(_colorvalue, 1000);
        break;
    case AnimationEffect::FAST_BREATHE:
        ColorAnimation::Breathe(_colorvalue, 500);
        break;

    case AnimationEffect::DISCO:
        ColorAnimation::Disco(_colorvalue, 40000);
        break;

    case AnimationEffect::FAST_DISCO:
        ColorAnimation::Disco(_colorvalue, 20000);
        break;

    case AnimationEffect::RANDOM_BREATHE:
        ColorAnimation::RandomBreathe(_colorvalue, 1000);
        break;

    case AnimationEffect::FAST_RANDOM_BREATHE:
        ColorAnimation::RandomBreathe(_colorvalue, 500);
        break;

    case AnimationEffect::NO_ANIMATION:
        ColorAnimation::NoAnimation(_colorvalue, 0);
        break;
    default:
        // Serial.println("Defualted");
        break;
    }
}
