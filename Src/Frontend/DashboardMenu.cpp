#include "DashboardMenu.h"
#include "MenuText.h"
#include "MenuButton.h"
#include "App.h"
#include "Backend/PressureController.h"

namespace so {

  void DashboardMenu::setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries){

	  menuEntries = {
			  MenuBuilder<MenuText>()
						  .text("-- Dashboard Menu --")
						  .build(),
		      MenuBuilder<MenuText>()
			  	  	  	  .onUpdate([this]()
						  {
				  	  	  	  m_cranePostionText->setText("Crane Position: ");
						  })
						  .assign(m_cranePostionText)
						  .build(),
			  MenuBuilder<MenuText>()
						  .onUpdate([this]()
						  {
				  	  	  	  m_airPressureText->setText("Air Pressure: " + std::to_string(App::get().getPressureController()->getPressure()));
						  })
						  .assign(m_airPressureText)
						  .build(),
			  MenuBuilder<MenuText>()
						  .onUpdate([this]()
						  {
						  	  m_detectedColorText->setText("Deteced Color: ");
						  })
						  .assign(m_detectedColorText)
						  .build(),
			  MenuBuilder<MenuText>()
						  .onUpdate([this]()
						  {
						  	  m_lightBarrierStateText->setText("Light Barrier State: ");
						  })
						  .assign(m_lightBarrierStateText)
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

}
