#include "SplashDisplay.h"
#include "Menu.h"
#include "MenuButton.h"
#include "App.h"
#include "MainDisplay.h"

extern EmbSysLib::Dev::ScreenChar disp;

namespace so {

	SplashDisplay::SplashDisplay()
	{
		setupMappings({
			BIND_EVENT(menuBtnClickEventType, &SplashDisplay::onUserInput),
			BIND_EVENT(scrollUpEventType, &SplashDisplay::onUserInput),
			BIND_EVENT(scrollDownEventType, &SplashDisplay::onUserInput)
		});
	}

	void SplashDisplay::update(){
	}

	void SplashDisplay::render(){
		disp.printf(1, 2, "Sorting Machine");
		disp.printf(2, 2, "<Press any key>");
	}

	bool SplashDisplay::forwardEvent(const EventType& eventType){
		return false;
	}

	void SplashDisplay::onUserInput(){
		App::get().getScreen()->closeDisplay();
		App::get().getScreen()->showDisplay<MainDisplay>();
	}
}
