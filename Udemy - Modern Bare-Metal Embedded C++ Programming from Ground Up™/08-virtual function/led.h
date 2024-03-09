#ifndef __LED_H
#define __LED_H

#include <stdio.h>


class Led
{
	
	private:
		
		int diameter;
		float voltage;
		float current;
	
	
	public:
		
		Led();
		Led(int d, float v, float c);
		
		
		int getDiameter();
		virtual float getVoltage();
		float getCurrent();
		
		void setDiameter(int d);
		void setVoltage(float v);
		void setCurrent(float c);
	
		float power();
		
		int isOn();
		
		
		~Led();
		
};

class MedicalLed:public Led
{
	private:
		int wavelength;
	
	public:
		MedicalLed(float d,float v, float c, int w)
		{
			setCurrent(c);
			setDiameter(d);
			setVoltage(v);
			
			wavelength = w;
		}
		
		void setWavelength(int w)
		{
			wavelength = w;
		}
		
		int getWavelength()
		{
			return wavelength;
		}
		
		/*Facilitators*/
		float m_factor()
		{
			return (getCurrent()*getDiameter()*wavelength)/100;
		}
		
		float getVoltage()
		{
			printf("This LED has no voltage to show \n\r");
		}
	
	
};

#endif





