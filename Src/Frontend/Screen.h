#pragma once

#include <Frontend/EventReceiver.h>

#include "EmbSysLib.h"
#include <memory>
#include <list>

namespace so {

	class Display;

	class Screen : public EventReceiver
	{
		public:
			Screen(u_int32_t displaySize)
			  : m_displaySize(displaySize)
			{
			}

			virtual void update();
			virtual void render();
			virtual bool forwardEvent(const EventType& eventType) override;


			virtual void showDisplay(const std::shared_ptr<Display>& display);
			virtual void closeDisplay(const std::shared_ptr<Display>& display);
			virtual void closeDisplay();
			virtual void closeAllDisplays();

			template<typename T>
			std::shared_ptr<T> showDisplay(){
				std::shared_ptr<T> display = std::make_shared<T>();
				showDisplay(display);
				return display;
			}

			virtual std::shared_ptr<Display> getActiveDisplay() const;


			u_int32_t getSize() const;
			void setSize(u_int32_t size);

		protected:
			std::shared_ptr<Display> showDisplayImpl();

		private:
			u_int32_t m_displaySize;
			std::list<std::shared_ptr<Display>> m_displayStack;
	};
}
