//*******************************************************************
#include "Frontend/App.h"
#include "Frontend/AutoStates.h"

using namespace so;
//***********t********************************************************
int main(void)
{

	App::get().init();
	App::get().getSOController()->run(SOState(stateMoveToLoader));

	while(1){
		App::get().update();
		/*crane.updatePosition();

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

		disp.refresh();*/
	};

	App::get().terminate();
	return 0;}


