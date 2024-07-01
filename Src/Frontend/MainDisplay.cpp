#include "MainDisplay.h"
#include "AutoSortMenu.h"
#include "ManuelSortMenu.h"
#include "DashboardMenu.h"
#include "MenuText.h"
#include "MenuButton.h"
#include "App.h"
#include "AutoStates.h"

namespace so {

	void MainDisplay::setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries){
		menuEntries = {
				/*std::make_shared<MenuText>("--- Main Menu ---"),
				std::make_shared<MenuButton>("Auto sort", []() -> void{
					 App::get().getSOController()->reset();
					 App::get().getSOController()->run(SOState(AutoStates::stateMoveToLoader));
					 App::get().showDisplay<AutoSortDisplay>();
				}),
				std::make_shared<MenuButton>("Manuel sort", []() -> void{

				}),
				std::make_shared<MenuButton>("Dashboard", []() -> void{
									 App::get().showDisplay<AutoSortDisplay>();
								}),
				std::make_shared<MenuButton>("Settings", []() -> void{

				}),*/
				MenuBuilder<MenuText>()
						  .text("--- Main Menu ---")
						  .build(),

			    MenuBuilder<MenuButton>()
						  .text("Auto Sort")
						  .onClick([](){
								App::get().getSOController()->reset();
								App::get().getScreen()->showDisplay<AutoSortMenu>();
						  })
						  .build(),

			    MenuBuilder<MenuButton>()
						  .text("Manuel sort")
						  .onClick([](){
								App::get().getSOController()->reset();
								App::get().getScreen()->showDisplay<ManuelSortMenu>();
						  })
						  .build(),

			    MenuBuilder<MenuButton>()
						  .text("Dashboard")
						  .onClick([](){
							  App::get().getScreen()->showDisplay<DashboardMenu>();
						  })
						  .build(),

				MenuBuilder<MenuButton>()
						  .text("Settings")
						  .onClick([]()
						  {
						  })
						  .build()

	  };
	}
}
