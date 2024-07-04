#pragma once

#include "sensoric/AnalogPart.h"
#include "EmbSysLib.h"
#include <string>

namespace so {

    class PressureController {
    public:
        PressureController(EmbSysLib::Dev::Digital& portPressure, const AnalogPart& pressureSensor) //Composition with PressureSensor
            : m_portPressure(portPressure),
			  m_pressureSensor(pressureSensor),
			  m_bEnable(false),
        	  m_enoughPressure(true)

        {} 

        void enable();
	    void disable();
	    void checkPressure();
	    int getPressure() const;
	    std::string showPressure();

        private:
            EmbSysLib::Dev::Digital& m_portPressure;
            AnalogPart m_pressureSensor;
            bool m_bEnable;
            bool m_enoughPressure;
    };
}



