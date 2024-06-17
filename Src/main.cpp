//*******************************************************************
#include "config.h"

//***********t********************************************************
int main(void)
{
	while(1){
		crane.updatePosition();

		switch(enc.getEvent()){
			case DigitalEncoder::LEFT:
				crane.turnLeft();
				break;
			case DigitalEncoder::RIGHT:
				crane.turnRight();
				break;
			case DigitalEncoder::CTRL_DWN:
				crane.halt();
				break;
			default:
				break;
		}
		disp.printf(0, 0, "endS State: %d", endswitchPort.get());
		disp.printf(1, 0, "Pos State: %d", positionSensorPort.get());
		disp.printf(2, 0, "lb State: %d", lbPort.get());
		disp.printf(3, 0, "Pos: %3d", crane.getPosition());

		disp.refresh();
	};

	return 0;}


