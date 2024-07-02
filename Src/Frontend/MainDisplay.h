#pragma once

#include "Menu.h"

namespace so {

	class MainDisplay : public Menu
	{
		virtual void setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries) override;
	};
}
