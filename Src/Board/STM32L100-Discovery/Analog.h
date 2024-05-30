#ifndef ANALOG_H
#define ANALOG_H

#include "EmbSysLib.h"
#include "config.h"

class Analog{

	public:
	virtual int getValue() = 0;
	virtual ~Analog();



	protected:
	Adc_Mcu adc(timer);


	private:

};

#endif
