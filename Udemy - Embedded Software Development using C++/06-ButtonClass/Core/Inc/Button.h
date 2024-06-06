/*
 * Button.h
 *
 *  Created on: Jun 5, 2024
 *      Author: Osama
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "pinmap.h"

class Button
{
	private:
		pinStruct_t pinStruct;
		bool prevPressed;
		bool IsDebounced(void);
	public:
		Button(pinStruct_t& gpioPinStruct);
		bool IsPressed(void);
};



#endif /* INC_BUTTON_H_ */
