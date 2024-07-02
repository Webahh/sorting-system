#pragma once

#include "EmbSysLib.h"
#include "Backend/AirPressureSensor.h"

namespace so {
    class PressureController {
    public:
        PressureController(EmbSysLib::Dev::Digital& portPressure, const AirPressureSensor& pressureSensor)
            : m_portPressure(portPressure),
			  m_pressureSensor(pressureSensor),
			  m_bEnable(false)

        {} 

        void enable();
	    void disable();
	    void checkPressure();
	    void calibrate();
	    int getPressure() const;

        private:
            EmbSysLib::Dev::Digital& m_portPressure;
            AirPressureSensor m_pressureSensor;
            bool m_bEnable;
            int m_scale;
    };
}



