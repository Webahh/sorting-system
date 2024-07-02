#include <Frontend/ManualSortMenu.h>
#include "MenuText.h"
#include "MenuButton.h"
#include "App.h"
#include "ManualStates.h"
#include "DashboardMenu.h"

namespace so {

	extern const EventType menuBtnActionEventType("menuBtnActionEventType");

	ManualSortMenu::ManualSortMenu()
			: m_bManualMovement(false)
		{
			setupMappings({
								BIND_EVENT(scrollUpEventType, &ManualSortMenu::onScrollUpEvent),
								BIND_EVENT(scrollDownEventType, &ManualSortMenu::onScrollDownEvent),
								BIND_EVENT(menuBtnClickEventType, &ManualSortMenu::onMenuBtnClickEvent),
								BIND_EVENT(menuBtnActionEventType, &ManualSortMenu::onMenuBtnActionEvent)
							});
			App::get().getSOController()->reset();
		}

	void ManualSortMenu::setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries){

		  menuEntries = {
					  MenuBuilder<MenuText>()
								  .text("-- Manual Sort Menu --")
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

	void ManualSortMenu::onScrollUpEvent() {
		if(m_bManualMovement){
			App::get().getSOController()->run(turnLeft);
		}else{
			onMoveCursorUp();
		}
	}

	void ManualSortMenu::onScrollDownEvent(){
		if(m_bManualMovement){
			App::get().getSOController()->run(turnRight);
		}else{
			onMoveCursorDown();
		}
	}

	void ManualSortMenu::onMenuBtnClickEvent(){
		if(m_bManualMovement){
			App::get().getSOController()->run(toggleArm);
		}else{
			forwardEvent(menuBtnClickEventType);
		}
	}

	void ManualSortMenu::onMenuBtnActionEvent(){
		m_bManualMovement = !m_bManualMovement;
	}

}
