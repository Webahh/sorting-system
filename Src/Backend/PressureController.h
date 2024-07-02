#pragma once

#include "EmbSysLib.h"
#include "AnalogPart.h"

namespace so {

    class PressureController {
    public:
        PressureController(EmbSysLib::Dev::Digital& portPressure, const AnalogPart& pressureSensor) //Composition with PressureSensor
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
            AnalogPart m_pressureSensor;
            bool m_bEnable;
            int m_scale;
    };
}



