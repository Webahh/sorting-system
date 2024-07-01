#include "Display.h"

namespace so {

	void Display::setup(){}

	u_int32_t Display::getSize() const{
			return m_displaySize;
	}

	void Display::setSize(u_int32_t size){
		m_displaySize = size;
	}
}
