#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Led.h"


void Led_ctor(Led_Type* const me, LedColor_Type _color, LedState_Type _state){

	me->color = _color;
	me->state = _state;

	/*Hardware Init*/
	RCC_voidEnableClock(RCC_APB2 , LED_PORT_CLOCK);

	switch(_color){
	case RED:
		DIO_voidSetDirection(LED_PORT , LED_RED_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_LOW);
		}
		break;
	case GREEN:
		DIO_voidSetDirection(LED_PORT , LED_GREEN_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_LOW);
		}
		break;
	case YELLOW:
		DIO_voidSetDirection(LED_PORT , LED_YELLOW_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_LOW);
		}
		break;
	case BLUE:
		DIO_voidSetDirection(LED_PORT , LED_BLUE_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_LOW);
		}
		break;

	}

}
void Led_setState(Led_Type* const me , LedState_Type _state){

	me->state = _state;

	switch(me->color){
	case RED:
		DIO_voidSetDirection(LED_PORT , LED_RED_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_LOW);
		}
		break;
	case GREEN:
		DIO_voidSetDirection(LED_PORT , LED_GREEN_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_LOW);
		}
		break;
	case YELLOW:
		DIO_voidSetDirection(LED_PORT , LED_YELLOW_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_LOW);
		}
		break;
	case BLUE:
		DIO_voidSetDirection(LED_PORT , LED_BLUE_PIN , OUTPUT_PP_2MHZ);
		if(me->state == ON){
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_LOW);
		}
		break;

	}


}
