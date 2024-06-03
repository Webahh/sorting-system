#ifndef ANALOGPART_H
#define ANALOGPART_H

#include "EmbSysLib.h"

//will inherit from Class Part
class AnalogPart{

	public:

	//Con needs ref of Adc_Mcu Obj
	AnalogPart(EmbSysLib::Hw::Adc_Mcu& adc)
	: adc(adc){
	}

	virtual int getValue() = 0;

	protected:
	EmbSysLib::Hw::Adc_Mcu& adc;


	private:

};

#endif
