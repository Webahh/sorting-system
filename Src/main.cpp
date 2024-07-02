#include <Frontend/Clock.h>
#include "Frontend/App.h"
#include "Frontend/AutoStates.h"
#include "Frontend/Screen.h"
#include "Frontend/SplashDisplay.h"
#include "config.h"

using namespace so;
//***********t********************************************************
int main(void)
{

	App::get().init();
	App::get().getScreen()->showDisplay<SplashDisplay>();
	app_taskManager.add(&App::get());
	app_taskManager.add(&SOClock::get());

	while(1){};

	App::get().terminate();
	return 0;
}


