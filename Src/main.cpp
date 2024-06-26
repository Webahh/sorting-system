#include <Frontend/Clock.h>
#include "Frontend/App.h"
#include "Frontend/AutoStates.h"
#include "config.h"

using namespace so;
//***********t********************************************************
int main(void)
{

	App::get().init();
	App::get().getSOController()->run(SOState(stateMoveToLoader));

	app_taskManager.add(&App::get());
	app_taskManager.add(&SOClock::get());

	while(1){
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
		}*/
		disp.printf(0, 0, "pos: %d", App::get().getCrane()->getPosition());

		disp.refresh();
		//
	};

	App::get().terminate();
	return 0;
}


