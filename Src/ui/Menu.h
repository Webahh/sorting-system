#pragma once

#include "EmbSysLib.h"
#include <memory>
#include <vector>
#include <string>

namespace so {

	class Menu
	{
		public:
			Menu(WORD displaySize)
			: m_displaySize(displaySize)
			, m_displayPtr(0)
			, m_nextUpdateTime(0)
			{}

			virtual void update();
			virtual void render();

			// Events
			void onMoveDisplayUp();
			void onMoveDisplayDown();
			void onResetDisplayPosition();

		private:
			std::vector<std::string> m_menuEntries;
			WORD m_displaySize;
			DWORD m_displayPtr;
			LWORD m_nextUpdateTime;
	};
}
