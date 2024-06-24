#include "ColorSensor.h"
#include "AnalogPart.h"
namespace so {

	Color ColorSensor::getColor(){
		// Something
		Color c;
		c.blue = c.red = c.white = 0;
		int raw = AnalogPart::getValue();
		if(raw < 30000){
			c.white = 1;
			c.descr = "white";
		}else if(40000 < raw && raw < 50000){
			c.red = 1;
			c.descr = "red";
		}else if(raw > 56000){
			c.blue = 1;
			c.descr = "blue";
		}
		return c;
	}

}

