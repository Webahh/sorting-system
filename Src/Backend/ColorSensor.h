#ifndef COLORSENSOR_H
#define COLORSENSOR_H

#include "EmbSysLib.h"
#include "AnalogPart.h"
#include <string>

namespace so {

    struct Color{
        int red;
        int white;
        int blue;
        std::string descr;

    };

    class ColorSensor : public AnalogPart{

        public:
            ColorSensor(EmbSysLib::Hw::Adc_Mcu& adc, int port)
            : AnalogPart(adc, port){
            }

            Color getColor();

        protected:

        private:
    };

}
#endif // COLORSENSOR_H
