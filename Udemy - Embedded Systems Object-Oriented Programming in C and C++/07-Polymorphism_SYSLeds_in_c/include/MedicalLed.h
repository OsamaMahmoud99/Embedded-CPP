#ifndef MEDICALLED_H
#define MEDICALLED_H


#include "Led.h"

typedef enum
{
	INFRARED = 910,
	NEAR_INFRARED = 880
}LedWavelength_Type;


typedef struct
{
	Led_Type super;
	LedWavelength_Type wavelength;
}MedicalLed_Type;


void MedicalLed_ctor(MedicalLed_Type* const me,
		            LedWavelength_Type _wavelength,
					LedColor_Type _color,
					LedState_Type _state);

LedWavelength_Type Medicalled_getWavelength(MedicalLed_Type *const me);
void Medicalled_setWavelength(MedicalLed_Type *const me, LedWavelength_Type _wavelength);

u32 MedicalLed_computeEfficiency(MedicalLed_Type const * const me);
void MedicalLed_runDiagnostics(MedicalLed_Type const * const me);

#endif
