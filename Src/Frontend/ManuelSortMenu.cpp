#include "ManuelSortMenu.h"
#include "MenuText.h"
#include "MenuButton.h"
#include "App.h"
#include "AutoStates.h"
#include "DashboardMenu.h"

namespace so {

	extern const EventType menuBtnActionEventType("menuBtnActionEventType");

	ManuelSortMenu::ManuelSortMenu()
			: m_bManuelMovement(false)
		{
			setupMappings({
								BIND_EVENT(scrollUpEventType, &ManuelSortMenu::onScrollUpEvent),
								BIND_EVENT(scrollDownEventType, &ManuelSortMenu::onScrollDownEvent),
								BIND_EVENT(menuBtnClickEventType, &ManuelSortMenu::onMenuBtnClickEvent),
								BIND_EVENT(menuBtnActionEventType, &ManuelSortMenu::onMenuBtnActionEvent)
							});
		}

	void ManuelSortMenu::setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries){

		  menuEntries = {
					  MenuBuilder<MenuText>()
								  .text("-- Manuel Sort Menu --")
								  .build(),

					  MenuBuilder<MenuButton>()
								  .text("Dashboard")
								  .onClick([](){
									  App::get().getScreen()->showDisplay<DashboardMenu>();
								  })
								  .build(),

					  MenuBuilder<MenuButton>()
								  .text("Back")
								  .onClick([]()
								  {
									  App::get().getScreen()->closeDisplay();
								  })
								  .build()
		  };
	}

	void ManuelSortMenu::onScrollUpEvent() {
		if(m_bManuelMovement){
			//TODO: call manuel state turn left
		}else{
			onMoveCursorUp();
		}
	}

	void ManuelSortMenu::onScrollDownEvent(){
		if(m_bManuelMovement){
			//TODO: call manuel state turn right
		}else{
			onMoveCursorDown();
		}
	}

	void ManuelSortMenu::onMenuBtnClickEvent(){
		if(m_bManuelMovement){
			//TODO: call manuel state raise lower/arm
		}else{
			forwardEvent(menuBtnClickEventType);
		}
	}

	void ManuelSortMenu::onMenuBtnActionEvent(){
		m_bManuelMovement = !m_bManuelMovement;
	}

}
