#pragma once

#include "Menu.h"

namespace so {

	class ManualSortMenu : public Menu
	{
	public:
		ManualSortMenu();

	protected:
		virtual void setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries) override;

		void onScrollUpEvent();
		void onScrollDownEvent();
		void onMenuBtnClickEvent();
		void onMenuBtnActionEvent();


	private:
		bool m_bManualMovement;

	};
}
