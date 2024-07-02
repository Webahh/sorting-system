#include "Display.h"

namespace so {

	void Display::setup(){}

	DWORD Display::getSize() const{
			return m_displaySize;
	}

	void Display::setSize(DWORD size){
		m_displaySize = size;
	}
}
