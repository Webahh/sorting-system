#pragma once

#include "EmbSysLib.h"

namespace so {
    class PressureController {
    public:
        PressureController(const EmbSysLib::Dev::Digital& portPressure)
            : m_portPressure(portPressure)
        {} 

        void enable();
	    void disable();

        private:
            EmbSysLib::Dev::Digital m_portPressure;
    };
}


