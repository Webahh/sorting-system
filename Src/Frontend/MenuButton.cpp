#include "MenuButton.h"

void MenuButton::update(){

}

void MenuButton::draw(){
	
}

void MenuButton::select(){
	OnClick();
}

void MenuButton::focus(bool hasFocus){
	m_isFocused = hasFocus
}

void MenuButton::onClick(){
	if (onClick) onClick();
}

bool MenuButton::addChildMenu(std::shared_ptr<MenuEntry> ) {
        return false; 
    }

bool MenuButton::emoveChildMenu(std::shared_ptr<MenuEntry>) {
        return false; 
    }