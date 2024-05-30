#include "ColorSensor.h"

int ColorSensor::getValue(){
	return adc.get(2); //Pin 2 = ColorSensor, gives raw value
}

Color ColorSensor::getColor(){
	// Something
	Color c;
	return c;
}


