/*
 * MedicalLed.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Osama
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "MedicalLed.h"

void MedicalLed_ctor(MedicalLed_Type* const me,
		LedWavelength_Type _wavelength,
		LedColor_Type _color,
		LedState_Type _state)
{
	static const struct LedVtable vtable={

			(void(*)(Led_Type const * const me))&MedicalLed_runDiagnostics,
			(u32(*)(Led_Type const * const me))&MedicalLed_computeEfficiency,
	};
	Led_ctor(&me->super , _color , _state);

	me->super.vptr = &vtable;

	me->wavelength = _wavelength;


}

LedWavelength_Type Medicalled_getWavelength(MedicalLed_Type *const me)
{
	return (me->wavelength);
}
void Medicalled_setWavelength(MedicalLed_Type *const me, LedWavelength_Type _wavelength)
{
	me->wavelength = _wavelength;
}

u32 MedicalLed_computeEfficiency(MedicalLed_Type const * const me)
{
	/* Dummy efficiency computation */
	const u8 input = 120;
	const u8 output = 86;
	const u8 k1 = 4;
	const u8 k2 = 6;

	u8 k;

	/* if wavelength == IR k=4 else k=6 */
	k = me->wavelength == INFRARED ?k1 : k2;

	u8 eff = ((input/output)*100) - k;

	/* for test */
	DIO_voidSetDirection(GPIOA , 7 , OUTPUT_PP_10MHZ);

	DIO_voidSetValue(GPIOA , 7 , GPIO_HIGH);

	return eff;
}
void MedicalLed_runDiagnostics(MedicalLed_Type const * const me)
{
	/* Dummy diagnostics sequence */

	for(int i=0; i<20; ++i){

		/* Do something */
	}

	/* for test */
	DIO_voidSetDirection(GPIOA , 8 , OUTPUT_PP_10MHZ);

	DIO_voidSetValue(GPIOA , 8 , GPIO_HIGH);
}
