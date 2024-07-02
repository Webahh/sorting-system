#include "MenuButton.h"

namespace so {

		void MenuButton::setOnClick(const std::function<void()>& onClickFunc){
			m_onClickFunc = onClickFunc;
		}

		void MenuButton::onClick(){
			m_onClickFunc();
		}

}
