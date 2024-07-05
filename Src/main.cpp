#include "ui/App.h"
#include "logic/Clock.h"
#include "logic/AutoStates.h"
#include "config.h"

using namespace so;
//***********t********************************************************
int main(void)
{

		App::get().init();
		app_taskManager.add(&App::get());
		app_taskManager.add(&SOClock::get());

		while(1){};

		App::get().terminate();
		return 0;
}


