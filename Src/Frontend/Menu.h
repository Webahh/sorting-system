#pragma once

#include <Frontend/EventReceiver.h>

#include "EmbSysLib.h"
#include "Display.h"
#include <memory>
#include <vector>

namespace so {

	class MenuEntry;

	extern const EventType scrollUpEventType;
	extern const EventType scrollDownEventType;

	class Menu : public Display
	{
		public:
			Menu();

			virtual void setup() override;
			virtual void update() override;
			virtual void render() override;
			virtual bool forwardEvent(const EventType& eventType) override;

			std::shared_ptr<MenuEntry> getSelectedMenuEntry() const;

		protected:
			virtual void setup(std::vector<std::shared_ptr<MenuEntry>>& menuEntries) = 0;

			// Events
			void onMoveDisplayUp();
			void onMoveDisplayDown();
			void onResetDisplayPosition();

			void onMoveCursorUp();
			void onMoveCursorDown();
			void onResetCursorPosition();

		private:
			std::vector<std::shared_ptr<MenuEntry>> m_menuEntries;

			u_int32_t m_displayPtr;
			u_int32_t m_cursorPtr;
	};
}
