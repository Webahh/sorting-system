#include "AutoSortMenu.h"
#include "MenuText.h"
#include "MenuButton.h"
#include "App.h"
#include "AutoStates.h"
#include "DashboardMenu.h"
#include "Backend/Crane.h"
#include "Backend/PressureController.h"

namespace so {

  void AutoSortMenu::setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries){

	  menuEntries = {
			  MenuBuilder<MenuText>()
						  .text("-- Auto Sort Menu --")
						  .build(),

			  MenuBuilder<MenuButton>()
						  .text("Start")
						  .onClick([this](){
				  	  	  	  if(!m_bStarted){
				  	  	  		  startAutoSort();
				  	  	  	  }
				  	  	  	  else
				  	  	  	  {
				  	  	  		  stopAutoSort();
				  	  	  	  }

			  	  	  	  })
						  .assign(m_toggleStartButton)
						  .build(),

			  MenuBuilder<MenuButton>()
			  	  	  	  .text("Dashboard")
						  .onClick([](){
				  	  	  	  App::get().getScreen()->showDisplay<DashboardMenu>();
			  	  	  	  })
						  .build(),

			  MenuBuilder<MenuButton>()
						  .text("Back")
						  .onClick([this]()
						  {
								stopAutoSort();
			 				  	App::get().getScreen()->closeDisplay();
						  })
						  .build()
	  };
  }

  void AutoSortMenu::startAutoSort(){
	  m_bStarted = true;
	  App::get().getSOController()->reset();
	  App::get().getSOController()->run(SOState(AutoStates::stateMoveToLoader));
	  m_toggleStartButton->setText("Stop");
  }

  void AutoSortMenu::stopAutoSort(){
	  m_bStarted = false;
	  App::get().getSOController()->reset();
	  App::get().getCrane()->halt();
	  App::get().getCrane()->raiseArm();
	  App::get().getCrane()->disablePad();
	  App::get().getPressureController()->disable();
	  m_toggleStartButton->setText("Start");
  }

}
