#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Led.h"


Led::Led(LedColor_Type _color, LedState_Type _state)
/* Option2 */
//:color(_color),
// state(_state)
{

	/* option1 */
	this->color = _color;
	this->state = _state;

	/*Hardware Init*/
	RCC_voidEnableClock(RCC_APB2 , LED_PORT_CLOCK);

	switch(_color){
	case RED:
		DIO_voidSetDirection(LED_PORT , LED_RED_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_LOW);
		}
		break;
	case GREEN:
		DIO_voidSetDirection(LED_PORT , LED_GREEN_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_LOW);
		}
		break;
	case YELLOW:
		DIO_voidSetDirection(LED_PORT , LED_YELLOW_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_LOW);
		}
		break;
	case BLUE:
		DIO_voidSetDirection(LED_PORT , LED_BLUE_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_LOW);
		}
		break;

	}

}
void Led::setState(LedState_Type _state){

	this->state = _state;

	switch(this->color){
	case RED:
		DIO_voidSetDirection(LED_PORT , LED_RED_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_RED_PIN, GPIO_LOW);
		}
		break;
	case GREEN:
		DIO_voidSetDirection(LED_PORT , LED_GREEN_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_GREEN_PIN, GPIO_LOW);
		}
		break;
	case YELLOW:
		DIO_voidSetDirection(LED_PORT , LED_YELLOW_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_YELLOW_PIN, GPIO_LOW);
		}
		break;
	case BLUE:
		DIO_voidSetDirection(LED_PORT , LED_BLUE_PIN , OUTPUT_PP_2MHZ);
		if(this->state == ON){
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_HIGH);
		}
		else{
			DIO_voidSetValue(LED_PORT, LED_BLUE_PIN, GPIO_LOW);
		}
		break;

	}


}

LedState_Type Led::getState(){

	return this->state;
}

void  Led::run_diagnostics()const{


}

u32 Led::compute_efficiency()const {

   return  0U;
}

void runSystemDiagnostics(Led const * led_modules[]){

	int i;
	for(i=0;led_modules[i] != (Led *)0;i++){

	   led_modules[i]->run_diagnostics();
	}

}
void computeEff(Led const * led_modules[]){

	int i;
	for(i=0;led_modules[i] !=(Led*)0;i++){

	   led_modules[i]->compute_efficiency();
	}


}

