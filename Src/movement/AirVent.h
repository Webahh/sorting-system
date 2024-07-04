#pragma once

#include "EmbSysLib.h"

namespace so {
    class AirVent{
    public:
        AirVent(EmbSysLib::Dev::Digital& portAirPressure)
            : m_portAirVent(portAirPressure)
        {} 

        void open();
	    void close();

	    bool isOpen() const;

        private:
            EmbSysLib::Dev::Digital& m_portAirVent;
    };
}
