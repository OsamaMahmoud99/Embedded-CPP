#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Led.h"

static void Led_run_diagnostics(Led_Type const * const me);
static u32 Led_compute_efficiency(Led_Type const * const me);

void Led_ctor(Led_Type* const me, LedColor_Type _color, LedState_Type _state){

	/* initial virtual table */
	static const struct LedVtable vtable={
			&Led_run_diagnostics,
			&Led_compute_efficiency
	};

	me->vptr = &vtable;

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

static void Led_run_diagnostics(Led_Type const * const me)
{
	(void)me;
}

static u32 Led_compute_efficiency(Led_Type const * const me)
{
	(void)me;
	return 0U;
}

/* polymorphism at work */
void runSystemDiagnostics(Led_Type const *led_modules[])
{
	int i;

	for(i=0; led_modules[i] != (Led_Type*)0; ++i){
		Led_runDiagnostics_Vcall(led_modules[i]);
	}

}
void computeLedEffs(Led_Type const *led_modules[])
{
	int i;

	for(i=0; led_modules[i] != (Led_Type*)0; ++i){
		led_computeEffi_Vcall(led_modules[i]);
	}
}
