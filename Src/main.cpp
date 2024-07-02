#include <Frontend/Clock.h>
#include "Frontend/App.h"
#include "Frontend/AutoStates.h"
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


