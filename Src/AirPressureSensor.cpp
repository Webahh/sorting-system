#include "AirPressureSensor.h"


int AirPressureSensor::getValue(){
	return adc.get(6); //Pin 6 = AirPressureSensor, gives raw value

}

float getPressure(){
	// conversion to bar
	return 0.0;
}

bool pressue(){
	return true;
}


