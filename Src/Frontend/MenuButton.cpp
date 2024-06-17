#include "MenuButton.h"

void MenuButton::update(){

}

void MenuButton::draw(){
	
}

void MenuButton::select(){
	onClick();
}

void MenuButton::focus(bool hasFocus){
	m_isFocused = hasFocus;
}

void MenuButton::onClick(){
}

bool MenuButton::addChildMenu(std::shared_ptr<MenuEntry> ) {
        return false; 
    }

bool MenuButton::removeChildMenu(std::shared_ptr<MenuEntry>) {
        return false; 
    }
