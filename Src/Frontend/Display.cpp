#include "Display.h"



void Display::update(){
	// checks encodermovement!!
	// Turn and press

}

void Display::render(){
	
	
}

bool Display::addChildMenu(std::shared_ptr<MenuEntry> menuEntry){
	m_menuEntries.push_back(menuEntry);
	return true;

}

bool Display::removeChildMenu(std::shared_ptr<MenuEntry> menuEntry){
	auto iter = std::find(m_menuEntries.begin(), m_menuEntries.end(), menuEntry);
    if (iter != m_menuEntries.end()) {
        m_menuEntries.erase(iter);
        return true;
    }
    return false;
	
}
