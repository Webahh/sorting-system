#pragma once

#include <Frontend/EventReceiver.h>

#include "EmbSysLib.h"
#include <memory>
#include <vector>

namespace so {

	class MenuEntry;

	class Display : public EventReceiver
	{
		public:
			Display()
			  : m_displaySize()
			{
			}

			virtual void setup();
			virtual void update() = 0;
			virtual void render() = 0;

			DWORD getSize() const;
			void setSize(DWORD size);

		private:
			DWORD m_displaySize;
	};
}
