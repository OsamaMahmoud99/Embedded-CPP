/*
 * PowerLed.c
 *
 *  Created on: May 22, 2023
 *      Author: Osama
 */


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Led.h"
#include "PowerLed.h"

void PowerLed_ctor(PowerLed_Type *const me,
		LedColor_Type _color,
		LedState_Type _state,
		LedDiamter_Type _diameter,
		LedCurrent_Type _current,
		LedVoltage_Type _voltage)
{
	static const struct LedVtable vtable={

			(void(*)(Led_Type const * const me))&PowerLed_runDiagnostics,
			(u32(*)(Led_Type const * const me))&PowerLed_computeEfficiency,
	};

	Led_ctor(&me->super , _color , _state);

	me->super.vptr = &vtable;

	me->diameter = _diameter;
	me->voltage = _voltage;
	me->current = _current;

}

void PowerLed_setCurrent(PowerLed_Type *const me , LedCurrent_Type _current){

	me->current = _current;
}
void PowerLed_setDiameter(PowerLed_Type *const me , LedDiamter_Type _diameter){

	me->diameter = _diameter;
}
void PowerLed_setVoltage(PowerLed_Type *const me , LedVoltage_Type _voltage){

	me->voltage  = _voltage;
}
led_elec_type PowerLed_computePower(PowerLed_Type *const me){

	return (me->current * me->voltage);
}
led_elec_type PowerLed_getCurrent(PowerLed_Type *const me){

	return me->current;
}
led_elec_type PowerLed_getDiameter(PowerLed_Type *const me){

	return me->diameter;
}
led_elec_type PowerLed_getVoltage(PowerLed_Type *const me){

	return me->voltage;
}

u32  PowerLed_computeEfficiency(PowerLed_Type const * const me)
{

	/* Dummy efficiency computation */
	const u8 input = 120;
	const u8 output = 86;

	u8 eff = ((input/output)*100)-((u8)(me->current)/2);


	/* for test */
	DIO_voidSetDirection(GPIOA , 5 , OUTPUT_PP_10MHZ);

	DIO_voidSetValue(GPIOA , 5 , GPIO_HIGH);

	return eff;
}

void PowerLed_runDiagnostics(PowerLed_Type const * const me)
{
	for(int i=0; i<(me->current); ++i){
		/* Do something */
	}

	/* for test */
	DIO_voidSetDirection(GPIOA , 6 , OUTPUT_PP_10MHZ);

	DIO_voidSetValue(GPIOA , 6 , GPIO_HIGH);
}
