#include "Menu.h"
#include "MenuEntry.h"

extern EmbSysLib::Dev::ScreenChar disp;

namespace so {
	Menu::Menu()
	 : m_displayPtr()
	 , m_cursorPtr()
	{
		setupMappings({
						BIND_EVENT(scrollUpEventType, &Menu::onMoveCursorUp),
						BIND_EVENT(scrollDownEventType, &Menu::onMoveCursorDown)
					});
	}

	void Menu::setup(){
		if(m_menuEntries.empty())
			setup(m_menuEntries);
	}

	void Menu::update(){
		for(std::shared_ptr<MenuEntry>& menuEntry : m_menuEntries) {
			menuEntry->update();
		}
	}

	void Menu::render(){

		std::vector<std::string> lines;

		for(std::shared_ptr<MenuEntry>& menuEntry : m_menuEntries) {
			lines.push_back(menuEntry->draw());
		}

		const DWORD start = m_displayPtr;
		const DWORD end = start + getSize();

		for(DWORD i = start; i < end; i++){
			std::string line;

			if(i == m_cursorPtr)
				line += ">";

			if(i < lines.size())
				line += lines[i];

			disp.printf(i - start, 0, "%-20s", line.c_str());
		}
	}



	bool Menu::forwardEvent(const EventType& eventType){
		if(std::shared_ptr<MenuEntry> menuEntry = getSelectedMenuEntry()){
			if(std::shared_ptr<EventReceiver> eventReceiver = std::static_pointer_cast<EventReceiver>(menuEntry)){
				return eventReceiver->dispatchEvent(eventType);
			}
		}

		return false;
	}

	std::shared_ptr<MenuEntry> Menu::getSelectedMenuEntry() const{
			if(m_cursorPtr < m_menuEntries.size()){
				return m_menuEntries[m_cursorPtr];
			}

			return nullptr;
		}

	void Menu::onMoveDisplayUp(){
		m_displayPtr--;
	}

	void Menu::onMoveDisplayDown(){
		m_displayPtr++;
	}

	void Menu::onResetDisplayPosition(){
		m_displayPtr = 0;
		m_cursorPtr = 0;
	}

	void Menu::onMoveCursorUp(){

		if(m_cursorPtr <= 0){
			m_cursorPtr = 0;
			return;
		}

		m_cursorPtr--;
		if(m_cursorPtr < m_displayPtr ){
			onMoveDisplayUp();
		}
	}

	void Menu::onMoveCursorDown(){
		if(m_cursorPtr >= m_menuEntries.size() - 1){
			m_cursorPtr = m_menuEntries.size() - 1;
			return;
		}

		m_cursorPtr++;
		if(m_cursorPtr >= m_displayPtr + getSize()){
			onMoveDisplayDown();
		}
	}

	void Menu::onResetCursorPosition(){
		m_cursorPtr = m_displayPtr;
	}
}
