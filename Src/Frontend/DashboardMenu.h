#pragma once

#include "Menu.h"

namespace so {

	class MenuText;

	class DashboardMenu : public Menu
	{
		virtual void setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries) override;

	private:

		std::shared_ptr<MenuText> m_cranePostionText;
		std::shared_ptr<MenuText> m_airPressureText;
		std::shared_ptr<MenuText> m_detectedColorText;
		std::shared_ptr<MenuText> m_lightBarrierStateText;

	};
}
