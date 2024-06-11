#pragma once

#include "EmbSysLib.h"

namespace so {
    class AirVent{
    public:
        AirVent(const EmbSysLib::Dev::Digital& portAirPressure)
            : m_portAirVent(portAirPressure)
        {} 

        void open();
	    void close();

        private:
            EmbSysLib::Dev::Digital m_portAirVent;
    };
}


