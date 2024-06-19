#include "ColorSensor.h"
#include "AnalogPart.h"
namespace so {

	Color ColorSensor::getColor(){
		// Something
		Color c;
		c.blue = c.red = c.white = 0;
		int raw = AnalogPart::getValue();
		if(raw < 33500){
			c.white = 1;
			c.descr = "white";
		}else if(33500 < raw && raw < 36000){
			c.red = 1;
			c.descr = "red";
		}else{ //Problem, Standardvalue ist == blau
			c.blue = 1;
			c.descr = "blue";
		}
		return c;
	}

}

