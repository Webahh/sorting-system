#pragma once

#include "Display.h"
#include "Clock.h"

namespace so {

	class SplashDisplay : public Display
	{
	public:
		SplashDisplay();

		virtual void update() override;
		virtual void render() override;
		virtual bool forwardEvent(const EventType& eventType) override;

	protected:
		void onUserInput();
	};
}
