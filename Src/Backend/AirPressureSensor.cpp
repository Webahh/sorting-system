#include "AirPressureSensor.h"

namespace so {
	float getPressure(){
		// conversion to bar
		int raw = AnalogPart::getValue();

		return raw;
	}

	bool pressue(){
		return true;
	}

}