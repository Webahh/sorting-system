#include "Screen.h"
#include "Display.h"

namespace so {

	void Screen::update(){
		if(std::shared_ptr<Display> activeDisplay = getActiveDisplay()){
			activeDisplay->update();
		}
	}

	void Screen::render(){
		if(std::shared_ptr<Display> activeDisplay = getActiveDisplay()){
			activeDisplay->render();
		}
	}

	bool Screen::forwardEvent(const EventType& eventType) {
		for(const std::shared_ptr<Display>& display : m_displayStack){
			 if(display->dispatchEvent(eventType)){
				 return true;
			 }
		}

		return false;
	};

	void Screen::showDisplay(const std::shared_ptr<Display>& display){
		if(!display){
			return;
		}

		display->setSize(getSize());
		display->setup();
		m_displayStack.push_front(display);
	}

	void Screen::closeDisplay(const std::shared_ptr<Display>& display){
			if(!display){
				return;
			}

		m_displayStack.remove(display);
	}

	void Screen::closeDisplay(){
		closeDisplay(getActiveDisplay());
	}

	void Screen::closeAllDisplays(){
		m_displayStack.clear();
	}

	std::shared_ptr<Display> Screen::getActiveDisplay() const{
		if(m_displayStack.empty()){
			return nullptr;
		}

		return m_displayStack.front();
	}

	DWORD Screen::getSize() const{
		return m_displaySize;
	}

	void Screen::setSize(DWORD size){
		m_displaySize = size;
	}
}
