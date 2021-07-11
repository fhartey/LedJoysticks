#ifndef __CommonEnums_h__
#define __CommonEnums_h__



enum class JoystickColor
{
    RED = 0,
    ORANGE,
    YELLOW,
    SPRING_GREEN,
    GREEN,
    TURQOISE,
    CYAN,
    OCEAN,
    BLUE,
    VIOLET,
    MAGENTA,
    RASPBERY,
    RANDOMCENTER,
    RANDOMALL,
    LAST, // use to see the last var in the list of enums good for irreating though this
};

enum class  AnimationEffect
{
    FADE = 0,
    FAST_FADE,
    BREATHE,
    FAST_BREATHE,
    DISCO,
    FAST_DISCO,
    RANDOM_BREATHE,
    FAST_RANDOM_BREATHE,
    NO_ANIMATION,
    LAST,
};

enum class TimerSelected {

    THRITY_SEC = 0,
    ONE_MIN,
    TWO_MIN,
    FIVE_MIN,
    SEVEN_MIN,
    TEN_MIN,
    FIFTEEN_MIN,
    TWENTY_MIN,
    TWENTYFIVE_MIN,
    THIRTYMIN_MIN,
    LAST,

};
enum class SelectEnum {
    JOYSTICK_COLOR = 0,
    ANIMATION_EFFECT,
    TIMER_SELECTED,

};

enum class AnimationColorCode {
    ORANGE = 1,
    GREEN = 4,
    TURQOISE = 5,
    RED = 0,
    VIOLET = 9,
    BLUE = 8,
    RASPBERY = 11,
    CYAN = 6,
    SPRING_GREEN = 3,

};


enum class TimerColorCode {
   
    RED = 0,
    TURQOISE = 5,
    GREEN = 4,
    BLUE = 8,
    VIOLET = 9,
    ORANGE = 1,
    SPRING_GREEN = 3,
    CYAN = 6,
    RASPBERY = 11,
    YELLOW = 2,    

};

enum class EpromAddress {
    JoystickColorEprom = 0,
    AnimationColorEprom = 1,
    TimerSelectedEprom = 2,

};

#endif
