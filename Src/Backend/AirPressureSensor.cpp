#include "AirPressureSensor.h"

namespace so {
	float AirPressureSensor::getPressure(){
		// conversion to bar
		int raw = getValue();

		return raw;
	}

	bool AirPressureSensor::pressure(){
		return true;
	}

}
