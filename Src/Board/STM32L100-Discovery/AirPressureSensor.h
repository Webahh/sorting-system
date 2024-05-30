#ifndef AIRPRESSURESENSOR_H
#define AIRPRESSURESENSOR_H
#include "EmbSysLib.h"
#include "AnalogPart.h"

class AirPressureSensor : public AnalogPart {

	public:
    AirPressureSensor(EmbSysLib::Hw::Adc_Mcu& adc): AnalogPart(adc){

    }
	
    int getValue() override;
    float getPressure();
    bool pressure();

	protected:
	

	private:
	

};

#endif
