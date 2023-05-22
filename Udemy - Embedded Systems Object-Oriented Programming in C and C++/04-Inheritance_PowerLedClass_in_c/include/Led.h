#ifndef LED_H
#define LED_H


#define LED_PORT          GPIOA
 
#define LED_PORT_CLOCK    (2)

#define LED_RED_PIN        0
#define LED_GREEN_PIN      1
#define LED_BLUE_PIN       2
#define LED_YELLOW_PIN     3


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


typedef struct{
	LedColor_Type color; /* color of led */
	LedState_Type state; /* state of led */
}Led_Type;

void Led_ctor(Led_Type* const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type* const me , LedState_Type _state);


#endif
