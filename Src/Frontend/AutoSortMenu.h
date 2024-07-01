#pragma once

#include "Menu.h"

namespace so {

	class MenuButton;

	class AutoSortMenu : public Menu
	{
	public:
		AutoSortMenu()
			: m_bStarted(false)
		{

		}

	protected:
		virtual void setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries) override;

		void startAutoSort();
		void stopAutoSort();

	private:
		std::shared_ptr<MenuButton> m_toggleStartButton;
		bool m_bStarted;
	};
}
