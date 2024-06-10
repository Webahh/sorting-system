#ifndef AIRPRESSURESENSOR_H
#define AIRPRESSURESENSOR_H

#include "EmbSysLib.h"
#include "AnalogPart.h"

namespace so {
    class AirPressureSensor : public AnalogPart{

	public:
    AirPressureSensor(EmbSysLib::Hw::Adc_Mcu& adc, int port)
        : AnalogPart(adc, port)
    {}
	
    float getPressure();
    bool pressure();
    };
}


#endif
