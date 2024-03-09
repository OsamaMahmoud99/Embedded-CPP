#include "led.h"



Led::Led()
{
	this->diameter = 3;
	this->voltage = 3.3;
	this->current = 200.0;
}

Led::Led(int diameter, float voltage, float current)
{
	setDiameter(diameter);
	setCurrent(current);
	setVoltage(voltage);
}

int Led::getDiameter()
{
	return this->diameter;
}

float Led::getVoltage()
{
	return this->voltage;
}

float Led::getCurrent()
{
	return this->current;
}

void Led::setDiameter(int diameter)
{
	if(diameter>0)
		this->diameter = diameter;
	else
		this->diameter = 0;
}

void Led::setVoltage(float voltage)
{
	if(voltage>0)
		this->voltage = voltage;
	else
		this->voltage = 0;
}

void Led::setCurrent(float current)
{
	if(current>0)
		this->current = current;
	else
		this->current = 0;
}

