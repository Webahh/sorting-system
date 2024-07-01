#pragma once

#include "MenuEntry.h"
#include <string>

namespace so {
	class MenuText : public MenuEntry {
	public:

	MenuText()
		: m_text()
	{
	}

	//void update() override{}
	std::string draw() override;
	virtual bool forwardEvent(const EventType& eventType) override;

	void setText(const std::string& text);

	private:
		std::string m_text;
	};

	template<>
	class MenuBuilder<MenuText> : public  MenuBuilderBase<MenuText>{
	public:
		MenuBuilder<MenuText>& text(const std::string& text){
			get().setText(text);
			return *this;
		}

		MenuBuilder<MenuText>& onUpdate(const std::function<void()>& onUpdateFunc){
			get().setOnUpdate(onUpdateFunc);
			return *this;
		}

		MenuBuilder<MenuText>& onEvent(const EventType& eventType, const std::function<void()>& onUpdateFunc){
			get().addMapping(eventType, onUpdateFunc);
			return *this;
		}
	};
}
