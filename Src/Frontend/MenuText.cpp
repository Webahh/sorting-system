#include "MenuText.h"

void MenuText::update(){
	
}

void MenuText::draw(){
	if (isFocused) {
        std::cout << "> " << m_text << std::endl;  // Hervorheben des Textes, wenn fokussiert
    } else {
        std::cout << "  " << m_text << std::endl; // Normale Darstellung
    }
 
}

void MenuText::select(){
	
}

void MenuEntry::focus(bool hasFocus){
	m_isFocused = hasFocus;
}
	

bool MenuText::addChildMenu(std::shared_ptr<MenuEntry>){
	return false // No Childs for Texts
}

bool MenuText::removeChildMenu(std::shared_ptr<MenuEntry>){
	return false; // No Childs for Texts
}