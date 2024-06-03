#pragma once

#include "EmbSysLib.h"
#include "Base/Part.h"

namespace ss {
    class PressureController : public Part {
    public:
        Motor(const EmbSysLib::Dev::Digital& portPressure)
            : m_portPressure(portPressure)
        {} 

        virtual void enable();
	    virtual void disable();

        private:
        DEmbSysLib::Dev::igital m_portPressure;
    };
}


