#ifndef LED_H
#define LED_H


#define LED_PORT          GPIOA
 
#define LED_PORT_CLOCK     2

#define LED_RED_PIN        0
#define LED_YELLOW_PIN     1
#define LED_GREEN_PIN      2
#define LED_BLUE_PIN       3



typedef enum{
	
	RED = 0,
	GREEN,
	YELLOW,
	BLUE
	
}LedColor_Type;

typedef enum{
	OFF = 0,
	ON = 1
}LedState_Type;


class Led{
private:
	LedColor_Type color; /* color of led */
	LedState_Type state; /* state of led */

public:
	Led(LedColor_Type _color, LedState_Type _state);
	void setState(LedState_Type _state);
	LedState_Type getState();
};




#endif
