#include "ui/Menu.h"
#include "ui/App.h"
#include "movement/Crane.h"
#include "movement/PressureController.h"
#include "sensoric/AnalogPart.h"
#include "sensoric/PositionSensor.h"
#include "logic/AutoStates.h"

extern EmbSysLib::Dev::ScreenChar disp;

namespace so {


	void Menu::update(){

		const int64_t currentTime = SOClock::get().getTime();
		if(currentTime - (int64_t)m_nextUpdateTime < 0){
			return;
		}

		m_nextUpdateTime = currentTime + 30;

		std::string sortMode = "<invalid>";

		switch(App::get().getSortMode()){
			case SortMode::OFF:
				sortMode = "OFF";
				break;
			case SortMode::AUTO:
				sortMode = "AUTO";

				if(App::get().getSOController()->isPaused()){
					sortMode += " (Paused)";
				}else if(AutoStates::getIsMoveToGarbage()){
					sortMode += " (Garbage)";
				}

				break;
			case SortMode::MANUAL:
				sortMode = "MANUAL";
				break;
			default:
				break;
		}

		m_menuEntries = {
			"Mode: " + sortMode,
			"Crane Position: " + std::to_string(App::get().getCrane()->getPosition()),
			"Pressure: " + std::string(App::get().getPressureController()->showPressure()),
			"Last Color: " + AutoStates::getLastDetectedColor(),
			"LB-State: " + std::string(App::get().getLightBarrier()->getState() ? "True" : "False"),
			"Item Count: " + std::to_string(AutoStates::getItemCount()),
		};
	}

	void Menu::render(){

		const int start = m_displayPtr;
		const int end = start + m_displaySize;

		for(int i = start; i < end; i++) {
			disp.printf(i-start, 0, "%-20s", m_menuEntries[i].c_str());
		}

		disp.refresh();
	}

	void Menu::onMoveDisplayUp(){
		if(m_displayPtr <= 0){
			m_displayPtr = 0;
		}else{
			m_displayPtr--;
		}
	}

	void Menu::onMoveDisplayDown(){
		if(m_displayPtr >= m_menuEntries.size() - m_displaySize){
			m_displayPtr = m_menuEntries.size() - m_displaySize;
		}else{
			m_displayPtr++;
		}
	}
}
