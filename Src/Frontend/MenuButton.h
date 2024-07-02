#pragma once
#include "MenuEntry.h"
#include "MenuText.h"


#include <memory>
#include <vector>

namespace so {

	extern const EventType menuBtnClickEventType;

	class MenuButton : public MenuText {
	public:

		MenuButton()
		{
			setupMappings({
				BIND_EVENT(menuBtnClickEventType, &MenuButton::onClick)
			});
		}

		void setOnClick(const std::function<void()>& onUpdateFunc);

	protected:
		virtual void onClick();

	private:
		std::function<void()> m_onClickFunc;
	};

	template<>
		class MenuBuilder<MenuButton> : public  MenuBuilderBase<MenuButton>{
		public:
			MenuBuilder<MenuButton>& text(const std::string& text){
				get().setText(text);
				return *this;
			}

			MenuBuilder<MenuButton>& onUpdate(const std::function<void()>& onUpdateFunc){
				get().setOnUpdate(onUpdateFunc);
				return *this;
			}

			MenuBuilder<MenuButton>& onClick(const std::function<void()>& onClickFunc){
				get().setOnClick(onClickFunc);
				return *this;
			}

			MenuBuilder<MenuButton>& onEvent(const EventType& eventType, const std::function<void()>& onEventFunc){
				get().addMapping(eventType, onEventFunc);
				return *this;
			}
		};
}
