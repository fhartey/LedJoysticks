#include "ColorAnimation.h"
#include "ControlsDatabase.h"
#include "ColorValues.h"
#include "Arduino.h"
#include "Color.h"

long ColorAnimation::DiscoTimer = 0;
int ColorAnimation::PrevColorAni = 0;


float ColorAnimation::pwm_valR = 0;
float ColorAnimation::pwm_valB = 0;
float ColorAnimation::pwm_valG = 0;
void ColorAnimation::Fade(ColorValues& _colorvalues, long _speed) {
    analogWrite(_colorvalues.rPin, _colorvalues.rVal);
    analogWrite(_colorvalues.gPin, _colorvalues.gVal);
    analogWrite(_colorvalues.bPin, _colorvalues.bVal);
    delay(_speed);

    if (_colorvalues.rVal < 255 && _colorvalues.bVal == 255) {
        if (_colorvalues.gVal == 0) {
            _colorvalues.rVal++;
        }
        else {
            _colorvalues.rVal++;
            _colorvalues.gVal--;
        }
    }
    else  if (_colorvalues.gVal < 255 && _colorvalues.rVal == 255) {
        if (_colorvalues.bVal == 0) {
            _colorvalues.gVal++;
        }
        else {
            _colorvalues.gVal++;
            _colorvalues.bVal--;
        }
    }
    else  if (_colorvalues.bVal < 255 && _colorvalues.gVal == 255) {
        if (_colorvalues.rVal == 0) {
            _colorvalues.bVal++;
        }
        else {
            _colorvalues.rVal--;
            _colorvalues.bVal++;
        }
    }
}

void ColorAnimation::Disco(ColorValues& _colorvalues, long _speed) {

    if (DiscoTimer <= 0) {

        int randNumber1 = random(0, 11);
        if (PrevColorAni == randNumber1) {
            randNumber1 = randNumber1 + 1;
        }
        Color::SwitchColor(randNumber1, _colorvalues);
        PrevColorAni = randNumber1;
        DiscoTimer = _speed;
    }
    else {
        DiscoTimer--;
    }
}

void ColorAnimation::Breathe(ColorValues& _colorvalues, long _speed)
{
    // float smoothness_pts = _speed; //larger=slower change in brightness wass 1000
    float smoothness_pts = _speed; //larger=slower change in brightness wass 1000

    _colorvalues.BreatheVal = _colorvalues.BreatheVal + _colorvalues.BreatheSwitcher;

    if (_colorvalues.BreatheVal < smoothness_pts) {
        _colorvalues.BreatheSwitcher = 1;
    }
    else {
        _colorvalues.BreatheVal = 0;
    }
    SetBreatheColor(_colorvalues, smoothness_pts);
}

void ColorAnimation::RandomBreathe(ColorValues& _colorvalues, long _speed)
{
    float smoothness_pts = _speed;//larger=slower change in brightness wass 1000

    _colorvalues.BreatheVal = _colorvalues.BreatheVal + _colorvalues.BreatheSwitcher;

    if (_colorvalues.BreatheVal < smoothness_pts) {
        _colorvalues.BreatheSwitcher = 1;
    }
    else {
        _colorvalues.BreatheVal = 0;
        int randNumber = random(0, 11);

        if (PrevColorAni == randNumber) {
            randNumber = randNumber + 1;

        }
        Color::SwitchColor(randNumber, _colorvalues);
        PrevColorAni = randNumber;
    }
    SetBreatheColor(_colorvalues, smoothness_pts);
}


void ColorAnimation::NoAnimation(ColorValues& _colorvalues, long _speed)
{
    // blank method for no ani
}
void ColorAnimation::SetBreatheColor(ColorValues& _colorvalues, float smoothness_pts) {


    if (_colorvalues.rVal == 0) {
        ColorAnimation::pwm_valR = 255 * (1.0 - abs((2.0 * (_colorvalues.BreatheVal / smoothness_pts)) - 1.0));
    }
    else  if (_colorvalues.rVal == 255) {
        ColorAnimation::pwm_valR = 255;
    }
    else  if (_colorvalues.rVal == 125) {
        ColorAnimation::pwm_valR = (125 * (1.0 - abs((2.0 * (_colorvalues.BreatheVal / smoothness_pts)) - 1.0))) + 130;
    }

    //125
    if (_colorvalues.bVal == 0) {
        ColorAnimation::pwm_valB = 255 * (1.0 - abs((2.0 * (_colorvalues.BreatheVal / smoothness_pts)) - 1.0));
    }
    else  if (_colorvalues.bVal == 255) {
        ColorAnimation::pwm_valB = 255;
    }
    else  if (_colorvalues.bVal == 125) {
        ColorAnimation::pwm_valB = (125 * (1.0 - abs((2.0 * (_colorvalues.BreatheVal / smoothness_pts)) - 1.0))) + 130;
    }

    if (_colorvalues.gVal == 0) {
        ColorAnimation::pwm_valG = 255 * (1.0 - abs((2.0 * (_colorvalues.BreatheVal / smoothness_pts)) - 1.0));
    }
    else  if (_colorvalues.gVal == 255) {
        ColorAnimation::pwm_valG = 255;
    }
    else  if (_colorvalues.gVal == 125) {
        ColorAnimation::pwm_valG = (125 * (1.0 - abs((2.0 * (_colorvalues.BreatheVal / smoothness_pts)) - 1.0))) + 130;
    }
    analogWrite(_colorvalues.rPin, int(ColorAnimation::pwm_valR));
    analogWrite(_colorvalues.bPin, int(ColorAnimation::pwm_valB));
    analogWrite(_colorvalues.gPin, int(ColorAnimation::pwm_valG));
    delay(5);
}
