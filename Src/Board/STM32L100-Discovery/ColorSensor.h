#ifndef COLORSENSOR_H
#define COLORSENSOR_H
#include "EmbSysLib.h"
#include "AnalogPart.h"
#include <string>

struct Color{
	int red;
	int green;
	int blue;
	std::string descr;

};

class ColorSensor : public AnalogPart{

    public:
        ColorSensor(EmbSysLib::Hw::Adc_Mcu& adc): AnalogPart(adc){

        }

        int getValue() override;
        Color getColor();

    protected:

    private:
};

#endif // COLORSENSOR_H
