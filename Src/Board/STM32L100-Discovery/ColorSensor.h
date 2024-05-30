#ifndef COLORSENSOR_H
#define COLORSENSOR_H
#include "Analog.h"

struct Color{
	// Magic will happen here
};

class ColorSensor : public Analog{

    public:
        ColorSensor();
        virtual ~ColorSensor();

        int Analog::getValue(){
        	return 0;
        }

        int getColor(): Color(){
        	return Color
        }

    protected:

    private:
};

#endif // COLORSENSOR_H
