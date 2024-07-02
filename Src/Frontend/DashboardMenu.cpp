#include "DashboardMenu.h"
#include "MenuText.h"
#include "MenuButton.h"
#include "App.h"
#include "Backend/PressureController.h"
#include "Backend/Crane.h"

namespace so {

  void DashboardMenu::setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries){

	  menuEntries = {
			  MenuBuilder<MenuText>()
						  .text("-- Dashboard Menu --")
						  .build(),

					      MenuBuilder<MenuText>()
							  	  	  	  .onUpdate([this]()
										  {
								  	  	  	  m_cranePostionText->setText("Crane Position: "+ std::to_string(App::get().getCrane()->getPosition()));
										  })
										  .assign(m_cranePostionText)
										  .build(),
		      MenuBuilder<MenuText>()
			  	  	  	  .onUpdate([this]()
						  {
				  	  	  	  m_cranePostionText->setText("Crane Position: "+ std::to_string(App::get().getCrane()->getPosition()));
						  })
						  .assign(m_cranePostionText)
						  .build(),
			  MenuBuilder<MenuText>()
						  .onUpdate([this]()
						  {
				  	  	  	  m_airPressureText->setText("Air Pressure: "+ std::to_string(App::get().getPressureController()->getPressure()));
						  })
						  .assign(m_airPressureText)
						  .build(),
			  MenuBuilder<MenuText>()
						  .onUpdate([this]()
						  {
				  	  	  	  int colorRaw = App::get().getColorSensor()->getValue();
				  	  	  	  std::string s = "";
				  	  	  	  if (colorRaw < 40000){
				  	  	  		  s = "White";
				  	  	  	  }
				  	  	  	  if (colorRaw > 40000 && colorRaw < 50000){
				  	  	  		  s = "Red";
				  	  	  	  }

				  	  	  	  if (colorRaw > 50000){
				  	  	  		  s = "Blue";
				  	  	  	  }

						  	  m_detectedColorText->setText("Last Color: "+ s);
						  })
						  .assign(m_detectedColorText)
						  .build(),
			  MenuBuilder<MenuText>()
						  .onUpdate([this]()
						  {
						  	  m_lightBarrierStateText->setText("LB-State: "+ std::to_string(App::get().getLightBarrier()->getState()));
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
