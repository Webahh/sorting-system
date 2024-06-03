#include "ColorSensor.h"

int ColorSensor::getValue(){
	return adc.get(6); //Pin 6 = ColorSensor, gives raw value
}

Color ColorSensor::getColor(){
	// Something
	Color c;
	return c;
}


