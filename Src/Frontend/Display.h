#include "EmbSysLib.h"

class Display{
	// Hier noch Singleton einbauen?!
	
	public:
		Display(const ScreenChar& sc)
		: m_sc(sc)
		{}
	
		void update();
		
		void render();
		
		bool addChildMenu(std::shared_ptr<MenuEntry> menuEntry);
		
		bool removeChildMenu(std::shared_ptr<MenuEntry> menuEntry);
	
	
	private:
		ScreenChar m_sc;
		std::vector<std::shared_ptr<MenuEntry>> m_menuEntries;
		int m_focusedIndex = 0;
	


};