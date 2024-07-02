#include "MenuText.h"

namespace so {

	std::string MenuText::draw(){
		return m_text;
	}

	bool MenuText::forwardEvent(const EventType& eventType){
		return false;
	}

	void MenuText::setText(const std::string& text){
		m_text = text;
	}
}
