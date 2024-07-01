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

			u_int32_t getSize() const;
			void setSize(u_int32_t size);

		private:
			u_int32_t m_displaySize;
	};
}
