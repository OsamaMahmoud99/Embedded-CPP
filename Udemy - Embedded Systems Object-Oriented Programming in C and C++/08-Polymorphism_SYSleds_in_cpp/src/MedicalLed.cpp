/*
 * MedicalLed.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Osama
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "MedicalLed.h"

MedicalLed::MedicalLed( LedWavelength_Type _wavelength,
											LedColor_Type   _color,
											LedState_Type _state)

:Led(_color,_state),
wavelength(_wavelength)
{

}


LedWavelength_Type MedicalLed:: MedicalLed_getWavelength(){

	return (this->wavelength);
}
 void  MedicalLed:: MedicalLed_setWavelength(LedWavelength_Type wavelength){

	  this->wavelength =  wavelength;

 }


u32 MedicalLed:: compute_efficiency() const {
	/* Dummy efficiency computation */
	const u8 input = 120;
	const u8 output = 86;
	const u8 k1 = 4;
	const u8 k2 = 6;

	u8 k;

	/* if wavelength == IR k=4 else k=6 */
	k = this->wavelength == INFRARED ?k1 : k2;

	u8 eff = ((input/output)*100) - k;

	/* for test */
	DIO_voidSetDirection(GPIOA , 7 , OUTPUT_PP_10MHZ);

	DIO_voidSetValue(GPIOA , 7 , GPIO_HIGH);

	return eff;
}

void MedicalLed::run_diagnostics() const {
	/* Dummy diagnostics sequence */

	for(int i=0; i<20; ++i){

		/* Do something */
	}

	/* for test */
	DIO_voidSetDirection(GPIOA , 8 , OUTPUT_PP_10MHZ);

	DIO_voidSetValue(GPIOA , 8 , GPIO_HIGH);
}
