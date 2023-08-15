/*
 * PowerLed.cpp
 *
 *  Created on: May 22, 2023
 *      Author: Osama
 */


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Led.h"
#include "PowerLed.h"

PowerLed::PowerLed(LedColor_Type _color,
				   LedState_Type _state,
				   LedDiamter_Type _diameter,
				   LedCurrent_Type _current,
				   LedVoltage_Type _voltage)

	:Led(_color , _state),
	diameter(_diameter),
	current(_current),
	voltage( _voltage)
{
}

void PowerLed::PowerLed_setCurrent(LedCurrent_Type _current){

	this->current = _current;
}
void PowerLed::PowerLed_setDiameter(LedDiamter_Type _diameter){

	this->diameter = _diameter;
}
void PowerLed::PowerLed_setVoltage(LedVoltage_Type _voltage){

	this->voltage  = _voltage;
}
led_elec_type PowerLed::PowerLed_computePower(){

	return (this->current * this->voltage);
}
led_elec_type PowerLed::PowerLed_getCurrent(){

	return this->current;
}
led_elec_type PowerLed::PowerLed_getDiameter(){

	return this->diameter;
}
led_elec_type PowerLed::PowerLed_getVoltage(){

	return this->voltage;
}

u32 PowerLed::compute_efficiency() const{

   //Dummy efficeincy computation


	  const u8 input = 120;
	  const u8 output = 86;

	 u8 eff =  ((input/output)*100) -(u8)((this->current)/2);

		/* for test */
		DIO_voidSetDirection(GPIOB , 7 , OUTPUT_PP_10MHZ);

		DIO_voidSetValue(GPIOB , 7 , GPIO_HIGH);



	 return eff;
}

void PowerLed:: run_diagnostics() const {

	/* for test */
	DIO_voidSetDirection(GPIOB , 8 , OUTPUT_PP_10MHZ);

	DIO_voidSetValue(GPIOB , 8 , GPIO_HIGH);

}
